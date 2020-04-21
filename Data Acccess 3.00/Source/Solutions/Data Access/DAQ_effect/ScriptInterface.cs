using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Reflection;
using System.CodeDom.Compiler;
using System.Diagnostics;
using Microsoft.CSharp;
using System.Security.Cryptography;
using System.Threading;
using System.IO;


namespace ScriptingInterface
{
    public interface IScriptType1
    {
        string RunScript(int value);
    }

    public class Tools
    {
        public static object Run(string astrCode)
        {
            Assembly compiledScript = CompileCode(
                "namespace SimpleScripts" +
                "{" +
                "    public class MyScriptMul5 : ScriptingInterface.IScriptType1" +
                "    {" +
                "        public string RunScript(int value)" +
                "        {" +
                "            return this.ToString() + \" just ran! Result: \" + (value*5).ToString();" +
                "        }" +
                "    }" +
                "    public class MyScriptNegate : ScriptingInterface.IScriptType1" +
                "    {" +
                "        public string RunScript(int value)" +
                "        {" +
                "            return this.ToString() + \" just ran! Result: \" + (-value).ToString();" +
                "        }" +
                "    }" +
                "}");
            var loRet = new object();
            if (compiledScript != null)
            {
                loRet = RunScript(compiledScript);
            }

            return loRet;
        }

        public static Assembly CompileCode(string code)
        {
            // Create a code provider
            // This class implements the 'CodeDomProvider' class as its base. All of the current .Net languages (at least Microsoft ones)
            // come with thier own implemtation, thus you can allow the user to use the language of thier choice (though i recommend that
            // you don't allow the use of c++, which is too volatile for scripting use - memory leaks anyone?)
            Microsoft.CSharp.CSharpCodeProvider csProvider = new Microsoft.CSharp.CSharpCodeProvider();

            // Setup our options
            CompilerParameters options = new CompilerParameters();
            options.GenerateExecutable = false; // we want a Dll (or "Class Library" as its called in .Net)
            options.GenerateInMemory = true; // Saves us from deleting the Dll when we are done with it, though you could set this to false and save start-up time by next time by not having to re-compile
            // And set any others you want, there a quite a few, take some time to look through them all and decide which fit your application best!

            // Add any references you want the users to be able to access, be warned that giving them access to some classes can allow
            // harmful code to be written and executed. I recommend that you write your own Class library that is the only reference it allows
            // thus they can only do the things you want them to.
            // (though things like "System.Xml.dll" can be useful, just need to provide a way users can read a file to pass in to it)
            // Just to avoid bloatin this example to much, we will just add THIS program to its references, that way we don't need another
            // project to store the interfaces that both this class and the other uses. Just remember, this will expose ALL public classes to
            // the "script"
            options.ReferencedAssemblies.Add(Assembly.GetExecutingAssembly().Location);

            // Compile our code
            CompilerResults result;
            result = csProvider.CompileAssemblyFromSource(options, code);

            if (result.Errors.HasErrors)
            {
                // TODO: report back to the user that the script has errored
                return null;
            }

            if (result.Errors.HasWarnings)
            {
                // TODO: tell the user about the warnings, might want to prompt them if they want to continue
                // runnning the "script"
            }

            return result.CompiledAssembly;
        }

        public static object RunScript(Assembly script)
        {
            // Now that we have a compiled script, lets run them
            foreach (Type type in script.GetExportedTypes())
            {
                foreach (Type iface in type.GetInterfaces())
                {
                    if (iface == typeof(ScriptingInterface.IScriptType1))
                    {
                        // yay, we found a script interface, lets create it and run it!

                        // Get the constructor for the current type
                        // you can also specify what creation parameter types you want to pass to it,
                        // so you could possibly pass in data it might need, or a class that it can use to query the host application
                        ConstructorInfo constructor = type.GetConstructor(System.Type.EmptyTypes);
                        if (constructor != null && constructor.IsPublic)
                        {
                            // lets be friendly and only do things legitimitely by only using valid constructors

                            // we specified that we wanted a constructor that doesn't take parameters, so don't pass parameters
                            ScriptingInterface.IScriptType1 scriptObject = constructor.Invoke(null) as ScriptingInterface.IScriptType1;
                            if (scriptObject != null)
                            {
                                //Lets run our script and display its results
                                var loRet = scriptObject.RunScript(50);
                                return loRet;
                            }
                            else
                            {
                                // hmmm, for some reason it didn't create the object
                                // this shouldn't happen, as we have been doing checks all along, but we should
                                // inform the user something bad has happened, and possibly request them to send
                                // you the script so you can debug this problem
                            }
                        }
                        else
                        {
                            // and even more friendly and explain that there was no valid constructor
                            // found and thats why this script object wasn't run
                        }


                    }//if (iface == typeof(ScriptingInterface.IScriptType1))
                }// foreach (Type iface in type.GetInterfaces())
            }// foreach (Type type in script.GetExportedTypes())

            return null;
        }//public static object RunScript(Assembly script)
    }

    public class CompilerRunner : MarshalByRefObject
    {
        private Assembly assembly = null;

        public Assembly getAssembly()
        {
            return this.assembly;
        }

        public void PrintDomain()
        {
            Console.WriteLine("Object is executing in AppDomain \"{0}\"",
                AppDomain.CurrentDomain.FriendlyName);
        }

        public bool Compile(string code, 
                            int anPreLineCount, 
                            ref string astrError,
                            ref List<System.CodeDom.Compiler.CompilerError> aoErrors)
        {
            CSharpCodeProvider codeProvider = new CSharpCodeProvider();
            CompilerParameters parameters = new CompilerParameters();
            parameters.GenerateInMemory = true;
            parameters.GenerateExecutable = false;

            parameters.ReferencedAssemblies.Add("System.Data.dll");
            parameters.ReferencedAssemblies.Add("System.dll");
            parameters.ReferencedAssemblies.Add("System.Deployment.dll");

            CompilerResults results = codeProvider.CompileAssemblyFromSource(parameters, code);
            if (!results.Errors.HasErrors)
            {
                this.assembly = results.CompiledAssembly;
            }
            else
            {
               
                foreach (System.CodeDom.Compiler.CompilerError loError in results.Errors)
                {
                    astrError += loError.ErrorNumber + "|Line:"+(loError.Line-anPreLineCount)+":" + loError.ErrorText +  "\n";
                    Debug.WriteLine(loError.ErrorNumber + "|Line:" + (loError.Line - anPreLineCount) + ":" + loError.ErrorText);

                    if (null!=aoErrors)
                    {
                        loError.Line = loError.Line - anPreLineCount;
                        aoErrors.Add(loError);
                    }                    
                }
                this.assembly = null;
            }

            return this.assembly != null;
        }

        public object InternalRun(string typeName, string methodName, object[] args)
        {
            Type type = this.assembly.GetType(typeName);
            return type.InvokeMember(methodName, BindingFlags.InvokeMethod, null, assembly, args);
        }

        public static string getMd5Hash(string input)
        {
            // Create a new instance of the MD5CryptoServiceProvider object.
            MD5 md5Hasher = MD5.Create();

            // Convert the input string to a byte array and compute the hash.
            byte[] data = md5Hasher.ComputeHash(Encoding.Default.GetBytes(input));

            // Create a new Stringbuilder to collect the bytes
            // and create a string.
            StringBuilder sBuilder = new StringBuilder();

            // Loop through each byte of the hashed data 
            // and format each one as a hexadecimal string.
            for (int i = 0; i < data.Length; i++)
            {
                sBuilder.Append(data[i].ToString("x2"));
            }

            // Return the hexadecimal string.
            return sBuilder.ToString();
        }

        public static string GetFunctionKey(String astrFunctionScript, object[] args)
        {
            String lstrKey = "";
            lstrKey = lstrKey + astrFunctionScript;
            foreach (object loObj in args)
            {
                if (null == loObj)
                {
                    lstrKey = lstrKey + loObj.GetType().ToString();
                }
                else
                {
                    lstrKey = lstrKey + "null";
                }               
            }

             lstrKey = getMd5Hash(lstrKey);
             return lstrKey;
        }

   
        static Object m_oLock = new Object();

        static  AppDomain domain = null;

        static Dictionary<string, CompilerRunner> m_oAssemblies = new Dictionary<string, CompilerRunner>();

        public static void clearSource()
        {
            lock (CompilerRunner.m_oLock)
            {

                try
                {
                    CompilerRunner.m_oAssemblies.Clear();
                }
                catch (System.Exception ex)
                {
                    Debug.WriteLine(ex.Message);
                }

                try
                {
                    if (null!= CompilerRunner.domain)
                    {
                        AppDomain.Unload(CompilerRunner.domain);
                    }
                   
                }
                catch (System.Exception ex)
                {
                    Debug.WriteLine(ex.Message);

                }

                try
                {
                    CompilerRunner.domain = null;
                }
                catch (System.Exception ex)
                {
                    Debug.WriteLine(ex.Message);
               	
                }
            }

        }



        public static object Run(   String astrFunctionScript, 
                                    object[] args, 
                                    ref string astrErr,
                                    ref List<System.CodeDom.Compiler.CompilerError> aoErrors)
        {

            String lstrKey = GetFunctionKey(astrFunctionScript, args);

            lock (CompilerRunner.m_oLock)
            {
                try
                {
	                if (null == CompilerRunner.domain)
	                {
	                    CompilerRunner.domain = AppDomain.CreateDomain("ScriptSystem");
	                }
                    
                    if (!m_oAssemblies.ContainsKey(lstrKey))
                    {
                        bool lbCompiledResult = false;

                        CompilerRunner cr = null;
                        try
                        {

                            string lstrFullName = typeof(CompilerRunner).Assembly.FullName;
                            cr = (CompilerRunner)CompilerRunner.domain.CreateInstanceAndUnwrap(lstrFullName, "ScriptingInterface.CompilerRunner");

                        }
                        catch (System.Exception ex)
                        {
                            cr = (CompilerRunner)CompilerRunner.domain.CreateInstanceFromAndUnwrap("DAQ-OPC-EFFECT.exe", "ScriptingInterface.CompilerRunner");

                        }
                        try
                        {   //eg.
                            //cr.Compile("public class Function { public static string Exec(string astrArgs) { return \"hello\"+astrArgs; } }");

                           
                            string lscript = "     using System;"
                                              +"\r\nusing System.Collections.Generic;"
                                              +"\r\nusing System.ComponentModel;"
                                              +"\r\nusing System.Data;"
                                              +"\r\nusing System.Text;"
                                             
                                              +"\r\nusing System.Diagnostics;"
                                              + "\r\n using System.Threading;"
                                              +"\r\npublic class a" + lstrKey 
                                              + " \r\n{ "
                                              + " public static Dictionary<String, Object> m_oData = new Dictionary<String, Object>(); public static String m_strKey = (\"lock\"); public static int Push(string astrKey, Object aoData) { lock (m_strKey) { if (null == astrKey || null == aoData) { return -1; } if (m_oData.ContainsKey(astrKey)) { m_oData[astrKey] = aoData; } else { m_oData.Add(astrKey, aoData); } return m_oData.Count; } }        public static object Get(string astrKey) { lock (m_strKey) { if (null == astrKey) { return null; } if (m_oData.ContainsKey(astrKey)) { return m_oData[astrKey]; } else { return null; } } }        public static int Remove(string astrKey) { lock (m_strKey) { if (null == astrKey) { return -1; } if (m_oData.ContainsKey(astrKey)) { m_oData.Remove(astrKey); } else { return -1; } return m_oData.Count; } }        public static int Clear() { lock (m_strKey) { m_oData = new Dictionary<String, Object>(); return 0; } }        public static int GetSize() { lock (m_strKey) { int lnCount = m_oData.Count; return lnCount; } }"                                              
                                              + " public static double[] Load(string astrFileName)        {            double[] loData = new double[0];            if (null == astrFileName)            {                return loData;            }            System.IO.StreamReader loReader = null;            try            {                loReader = new System.IO.StreamReader(System.IO.File.Open(astrFileName, System.IO.FileMode.Open));            }            catch (System.Exception )            {                           }            if (null == loReader)            {                return loData;            }            string lstrData = loReader.ReadToEnd();            try            {                loReader.Close();            }            catch (System.Exception )            {                return loData;            }            try            {                string[] loBuffers = lstrData.Split('\t');                List<double> loTemp = new List<double>();                for (int i = 0; i < loBuffers.Length; i++)                {                    double ldblValue = 0.0;                    if (Double.TryParse(loBuffers[i], out ldblValue))                    {                        loTemp.Add(ldblValue);                    }                }                return loTemp.ToArray();            }            catch (System.Exception )            {                return loData;            }        }        public static int Save(string astrFileName, double[] aoData)        {            if (aoData == null || astrFileName == null)            {                return 0;            }            System.IO.StreamWriter loFile = null;            try            {                loFile = new System.IO.StreamWriter(System.IO.File.Open(astrFileName, System.IO.FileMode.Create));            }            catch (System.Exception )            {            }            if (null == loFile)            {                return 0;            }            try            {                for (int i = 0; i < aoData.Length; i++)                {                    loFile.Write(aoData[i].ToString());                    loFile.Write('\t');                }                loFile.Flush();            }            catch (System.Exception )            {                return 0;            }            try            {                loFile.Close();            }            catch (System.Exception )            {                return 0;            }            return aoData.Length;        }"                                             
                                              + "\r\n\t public static object Exec" 
                                              + astrFunctionScript
                                              + " \r\n}";

 
                            lbCompiledResult = cr.Compile(lscript, 10, ref astrErr,ref aoErrors);
                          
                            if (!lbCompiledResult) 
                            {
                                Debug.WriteLine(lscript);
                                EricZhao.UiThread.ThreadUiController.log(lscript, EricZhao.UiThread.ThreadUiController.LOG_LEVEL.FATAL);
                            }
                        }
                        catch (System.Exception ex)
                        {
                            Debug.WriteLine(ex.Message);
                            astrErr += ex.Message;
                        }


                        object result = null;

                        try
                        {
                            if (lbCompiledResult)
                            {
                                result = cr.InternalRun("a"+lstrKey, "Exec", args);
                            }

                        }
                        catch (System.Exception ex)
                        {
                            Debug.WriteLine(ex.Message);
                            Debug.WriteLine(astrFunctionScript);
                            astrErr += ex.Message;
                        }
                        if (lbCompiledResult)
                        {
                            m_oAssemblies.Add(lstrKey, cr);
                        }

                        return result;
                    }
                    else
                    {
                       object result = null;


                       try
                       {
                           CompilerRunner cr = CompilerRunner.m_oAssemblies[lstrKey];
                           result = cr.InternalRun("a" + lstrKey, "Exec", args);

                       }
                       catch (System.Exception ex)
                       {

                           Debug.WriteLine(ex.Message);
                           Debug.WriteLine(astrFunctionScript);
                           astrErr += ex.Message;
                       }

                       return result;
                    }
                }
                catch (System.Exception ex)
                {
                    Debug.WriteLine(ex.Message);
                    Debug.WriteLine(astrFunctionScript);
                    astrErr += ex.Message;
                }
            }

            return 0;

         //   AppDomain.Unload(domain);          
        }

    }
}

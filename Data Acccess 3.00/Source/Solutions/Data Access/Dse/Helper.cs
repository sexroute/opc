using System;
using System.Text;
using System.Diagnostics;
using System.Globalization;

namespace Aco
{
    using DseHelper;

    internal partial class SMessageHeader
    {
        public override string ToString()
        {
            return this.nServiceCode.ToString();
        }
    }

    internal partial class SFieldContent
    {
        public override string ToString()
        {
            string ret = string.Empty;

            switch (this.fType)
            {
                case EFieldType.FTFloat:
                    {
                        ret = this.fValue.ToString();
                    }
                    break;

                case EFieldType.FTInt:
                    {
                        ret = this.iValue.ToString();
                    }
                    break;

                case EFieldType.FTString:
                    {
                        if(this.strValue != null)
                        {
                            ret = this.strValue;
                        }
                        else
                        {
                            Debug.Assert(false);
                        }
                    }
                    break;

                case EFieldType.FTDateTime:
                    {
                        ret = this.strValue;
                    }
                    break;


                case EFieldType.FTBytes:
                    {
                        if(this.buf != null)
                        {
                            ret = this.buf.ToHexString();
                        }
                        else
                        {
                            Debug.Assert(false);
                        }
                    }
                    break;

                case EFieldType.FTBool:
                    {
                        bool val = (this.iValue == 1);
                        ret = val.ToString();
                    }
                    break;

                case EFieldType.FTChar:
                    {
                        if (null == this.buf)
                        {
                            Debug.Assert(false);

                            return ret;
                        }

                        if (this.buf.Length < 1)
                        {
                            Debug.Assert(false);

                            return ret;
                        }

                        ret = this.buf[0].ToString();
                    }
                    break;

                default:

                    Debug.Assert(false);

                    break;
            }

            return ret;
        }
    }

    internal partial class SDataPacket
    {
        public override string ToString()
        {
            var sb = new StringBuilder();

            if (this.msgHeader != null)
            {
                sb.AppendFormat("{0}", this.msgHeader.nServiceCode);
            }

            if (this.packet != null)
            {
                sb.AppendFormat(": {0}", this.packet.Length);
            }

            return sb.ToString();
        }

        public static SDataPacket Empty
        {
            get
            {
                SDataPacket dp = new SDataPacket();

                dp.msgHeader = new SMessageHeader();
                //dp.packet = new Dictionary<int, SFieldContent>[0];
                //dp.curWarnings = new string[0];

                return dp;
            }
        }
    }
}

namespace DseHelper
{
    using Aco;

    static class BytesHelper
    {
        public static string ToHexString(this byte[] bytes)
        {
            return ToHexString(bytes, 0, bytes.Length);
        }

        public static string ToHexString(this byte[] bytes, int start, int count)
        {
            char[] str = new char[count * 2];

            byte b;

            for (int bx = start, sx = 0; bx < count; ++bx, ++sx)
            {
                b = ((byte)(bytes[bx] >> 4));
                str[sx] = (char)(b > 9 ? b - 10 + 'A' : b + '0');

                b = ((byte)(bytes[bx] & 0x0F));
                str[++sx] = (char)(b > 9 ? b - 10 + 'A' : b + '0');
            }

            return new string(str);
        }
    }

    static class StringHelper
    {
        internal static bool IsNullOrEmptyOrWhiteSpace(this string value)
        {
            return IsNullOrEmptyOrWhiteSpace(value, 0);
        }

        internal static bool IsNullOrEmptyOrWhiteSpace(this string value, int offset)
        {
            // don't use Trim(), which will copy the string, which may be large, just to test for emptyness
            //return String.IsNullOrEmpty(value) || String.IsNullOrEmpty(value.Trim());
            if (null != value)
            {
                for (int i = offset; i < value.Length; ++i)
                {
                    if (!Char.IsWhiteSpace(value[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        internal static bool IsNullOrEmptyOrWhiteSpace(this string value, int offset, int length)
        {
            // don't use Trim(), which will copy the string, which may be large, just to test for emptyness
            //return String.IsNullOrEmpty(value) || String.IsNullOrEmpty(value.Trim());
            if (null != value)
            {
                length = Math.Min(value.Length, length);
                for (int i = offset; i < length; ++i)
                {
                    if (!Char.IsWhiteSpace(value[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    static class DateTimeHelper
    {
        internal const string DATETIME_FORMAT = "yyyy'-'MM'-'dd' 'HH':'mm':'ss";
        internal const string DATETIME_FORMAT_FULL = "yyyy'-'MM'-'dd' 'HH':'mm':'ss'.'fff";

        internal static readonly DateTime Default = new DateTime(2000, 1, 1, 1, 1, 1);

        internal static DateTime ToDateTime(this string sDateTime)
        {
            DateTime dt = DateTimeHelper.Default;

            if (StringHelper.IsNullOrEmptyOrWhiteSpace(sDateTime))
            {
                Debug.Assert(false);

                return dt;
            }

            int pos = sDateTime.LastIndexOf('.');

            if (pos > 0)
            {
                if (!DateTime.TryParseExact(
                    sDateTime,
                    DATETIME_FORMAT_FULL,
                    DateTimeFormatInfo.CurrentInfo,
                    DateTimeStyles.None,
                    out dt))
                {
                    Debug.Assert(false);

                    return dt;
                }
            }
            else
            {
                if (!DateTime.TryParseExact(
                    sDateTime,
                    DATETIME_FORMAT,
                    DateTimeFormatInfo.CurrentInfo,
                    DateTimeStyles.None,
                    out dt))
                {
                    Debug.Assert(false);

                    return dt;
                }
            }

            return dt;
        }
    }

    static class BHAcoHelper
    {
        public static object ToObject(this SFieldContent self)
        {
            switch (self.fType)
            {
                case EFieldType.FTFloat:
                    return self.fValue;

                case EFieldType.FTInt:
                    return self.iValue;

                case EFieldType.FTString:
                    return self.strValue;

                case EFieldType.FTDateTime:
                    return self.strValue.ToDateTime();

                case EFieldType.FTBytes:
                    return self.buf;

                case EFieldType.FTBool:
                    return (self.iValue == 1);

                case EFieldType.FTChar:
                    {
                        if (null == self.buf)
                        {
                            Debug.Assert(false);

                            return null;
                        }

                        if (self.buf.Length < 1)
                        {
                            Debug.Assert(false);

                            return null;
                        }

                        return self.buf[0];
                    }

                default:
                    Debug.Assert(false);
                    break;
            }

            return null;
        }

    }
}

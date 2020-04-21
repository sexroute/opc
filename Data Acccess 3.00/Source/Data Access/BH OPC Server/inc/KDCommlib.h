#pragma  once

#ifdef _KDCOMMLIB_MARBLE_H_
#define _KDCOMMLIB_API_  __declspec(dllexport)
#else
#define _KDCOMMLIB_API_  __declspec(dllimport)
#ifdef _DEBUG
#pragma comment(lib, "KDCommLibD.lib")
#else
#pragma comment(lib, "KDCommlib.lib")
#endif
#endif

#include <atlstr.h>
#include <vector>
using std::vector;

/// �õ����̵�ǰĿ¼
CString _KDCOMMLIB_API_  GetAppPath();

/// �õ����̵�ǰȫ·����
CString _KDCOMMLIB_API_  GetFilePathFromFullName();

extern "C"
{
	// !\name ��������
	//@{

	/// ι��
	/** ���¿��Ź��ļ�
	*	\param[in] strFile_ ���Ź��ļ���
	*	\return ι���ɹ���־
	*/
	bool _KDCOMMLIB_API_ Feed(const CString &strFile_);

	/// �����Զ���������
	/** ͬʱ����ִ�и��µ���Ϣ����������
	*	\return �Ƿ������ɹ�
	*/
	bool _KDCOMMLIB_API_ StartUpdater(int nTryCount = 10);

    /// �汾��
    struct _KDCOMMLIB_API_ S_VERSION_NO
    {
        WORD wMain;
        WORD wSub;
        WORD wBuild;
        WORD wCompile;

        S_VERSION_NO(void);
        inline CString ToString(void);
    };

    /// �汾��Ϣ��
    class _KDCOMMLIB_API_ CBHVersion
    {
    public:
        CBHVersion(LPCTSTR szPath_ = "");

    public:
        bool GetFileVersion(S_VERSION_NO &verNo_);
        bool GetProductVersion(S_VERSION_NO &verNo_);
        bool GetFileFlags(DWORD& rdwFlags);
        bool GetFileOS(DWORD& rdwOS);
        bool GetFileType(DWORD& rdwType);
        bool GetFileSubtype(DWORD& rdwType);	

        // string info
        bool GetCompanyName(CString &strCompanyName_);
        bool GetFileDescription(CString &strFileDesc_);
        bool GetProductName(CString &strProductName_);

    protected:
        inline bool Init();
        bool GetFixedInfo(void *pBlock_, VS_FIXEDFILEINFO& rFixedInfo_);
        bool GetStringInfo(LPVOID pBlock_, LPCTSTR lpszKey, CString &strValue_);

        bool _bInit;
        CString	_strPath;
        CString	_strCompanyName;
        CString	_strProductName;
        CString	_strFileDescription;
        VS_FIXEDFILEINFO _fixFileInfo;
    };

	/// ��������
	class _KDCOMMLIB_API_ CMutexRW
	{
	protected:
		HANDLE m_semReaders;
		HANDLE m_semWriters;
		long m_lnReaders;
	public:
		CMutexRW();
		virtual ~CMutexRW();

		void BeginRead();
		void EndRead();
		void BeginWrite();
		void EndWrite();
	};


	/// �ļ��������
	/** ����ļ��жԻ����û�ѡ��Ŀ¼ */
	class _KDCOMMLIB_API_ CBrowseForFolder
	{
	public:
		CBrowseForFolder(const HWND hParent = NULL, const LPITEMIDLIST pidl = NULL, const int nTitleID = 0);
		CBrowseForFolder(const HWND hParent, const LPITEMIDLIST pidl, const CString& strTitle);
		virtual ~CBrowseForFolder(void);

		/// �����ļ���ѡ��Ի����owner����
		void SetOwner(const HWND hwndOwner);
		/// ���ô������Ŀ¼���ĸ�Ŀ¼(NULL��ʾ��������Ϊ��Ŀ¼)
		void SetRoot(const LPITEMIDLIST pidl = NULL);
		/// ��ȡ�ļ���ѡ��Ի���ı���
		CString GetTitle(void) const;
		/// �����ļ���ѡ��Ի���ı���: ����1
		void SetTitle(const CString& strTitle);
		/// �����ļ���ѡ��Ի���ı���: ����2
		bool SetTitle(const int nTitle);
		/// ��ȡBROWSEINFO����ulFlags, �μ�MSDN�й���BROWSEINFO::ulFlags��˵��
		UINT GetFlags(void) const;
		/// ����BROWSEINFO��ulFlags����
		void SetFlags(const UINT ulFlags);
		// ��ȡ��ѡ�����ļ���·��
		CString GetSelectedFolder(void) const;
		/// ��ȡ��ѡ���ļ����������ͼƬ
		int GetImage(void) const;
		/// ����Ŀ¼ѡ��Ի���
		bool SelectFolder(void);

	protected:
		virtual void OnInit(void) const;
		virtual void OnSelChanged(const LPITEMIDLIST pidl) const;
		void EnableOK(const bool bEnable) const;
		void SetStatusText(const CString& strText) const;
        void SetSelection(const LPITEMIDLIST pidl) const;
        void SetSelection(const CString& strPath) const;
	private:
		static int __stdcall BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
		typedef std::auto_ptr<char> AUTO_STR;
		AUTO_STR m_pchTitle;
		BROWSEINFO m_bi;
		char m_szSelected[MAX_PATH];
		CString m_strPath;
		HWND m_hwnd;
	};

    /// ��־����
	enum E_LOG_LEVEL
	{
		MODE_TRACE = 0x0001,				//�Ƚ�ϸ�ڵ���Ϣ
		MODE_DEBUG = 0x0002,				//ϵͳ�����е�ϸ����Ϣ
		MODE_INFO  = 0x0004,				//����ʱ��������������¼�
		MODE_WARN  = 0x0010,				//����ʱ������Ҫ�Ͳ���Ԥ�ڵ�״̬����û�г�Ϊ������
		MODE_ERROR = 0x0020,				//���������ڵĴ������Ԥ�ڵ��¼�
		MODE_FATAL = 0x0040					//�ǳ����صĴ��󣬵���ϵͳ��ֹ
	};

    /// ��־��
    class _KDCOMMLIB_API_ CHZLog 
    {
    public:
        CHZLog(void);
	    virtual ~CHZLog(void);
    	
    public:

        static CHZLog * CreateLogTxt(const CString &strFileDir_, const CString &strFileName, int iLogLevel_ = MODE_ERROR | MODE_FATAL);
        static void ReleaseAllLog(void);
        static E_LOG_LEVEL GetLevelByString( const CString &strLevel );

	    virtual BOOL IsDebugEnabled() = 0;
	    virtual BOOL IsErrorEnabled() = 0;
	    virtual BOOL IsFatalEnabled() = 0;
	    virtual BOOL IsInfoEnabled() = 0;
	    virtual BOOL IsTraceEnabled() = 0;
	    virtual BOOL IsWarnEnabled() = 0;

	    virtual void Trace(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ) = 0;
	    virtual void Debug(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ) = 0;
	    virtual void Info(const CString &strMsg, const CString &strModule = "", const CString &strOperType = ""  ) = 0;
	    virtual void Warn(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ) = 0;
	    virtual void Error(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ) = 0;
	    virtual void Fatal(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ) = 0;

    protected:
        static std::vector<CHZLog*> s_vecLog;
	    int _iLogLevel;		// ��־����
    };


	/// ��־������
	class _KDCOMMLIB_API_ CHZLogManage 
	{
	public:
		CHZLogManage(void);
		~CHZLogManage(void);

	public:
		static BOOL IsDebugEnabled();
		static BOOL IsErrorEnabled(); 
		static BOOL IsFatalEnabled();
		static BOOL IsInfoEnabled();
		static BOOL IsTraceEnabled(); 
		static BOOL IsWarnEnabled();
		static void Trace(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" ); 
		static void Debug(const CString &strMsg, const CString &strModule = "", const CString &strOperType = ""  ); 
		static void Info(const CString &strMsg, const CString &strModule = "", const CString &strOperType = "" );
		static void Warn(const CString &strMsg, const CString &strModule = "", const CString &strOperType = ""  );
		static void Error(const CString &strMsg, const CString &strModule = "", const CString &strOperType = ""  );
		static void Fatal(const CString &strMsg, const CString &strModule = "", const CString &strOperType = ""  );

		static void StartLogTxt(CString strFileDir_,CString strFileName,int iLogLevel_ = 2);
		
		static UINT GetLogger(CString strFileDir_,CString strFileName,int iLogLevel_ = 2 );
		
		static void Log(	UINT anLoggHandle,
							const CString &strMsg, 
							const CString &strModule = "", 
							const CString &strOperType = "" ,
							int iLogLevel_= 2);
		
		static void ReleaseLogger(UINT anLoggHandle);

    protected:
		static void InitLog( CString strKey = "", CString strFile = "" );
		static void ValidLog();

	protected:
		static CHZLog *m_pLog;					//��־�ӿ�
	};


    /// �쳣����ʽ
    enum E_EXCEPTION_HANDLE_TYPE
    {
        EH_MSG_BOX = 0x0001,           ///< �Ի��򱨴�
        EH_WRITE_LOG = 0x0002,        ///< ��־����
        EH_WRITE_DUMP = 0x0004,     ///< дdump�ļ�
        EH_STATIC_EXIT = 0x0008         ///< ��Ĭ�˳�
    };

    /// ������Ϣ��׽��
    class _KDCOMMLIB_API_ CBHCrashCapture
    {
    public:
        /// �����쳣������
        static void Load(int iType_ = EH_WRITE_LOG | EH_WRITE_DUMP | EH_STATIC_EXIT);
        /// ж���쳣������
        static void Unload(void);

    protected:
        /// ���������Ϣ
        struct S_CRASH_INFO
        {
            DWORD64 dw64Addr;      ///< �쳣������ַ
            DWORD dwCode;             ///< �쳣��
            DWORD dwFlag;               ///< �쳣��־
            S_CRASH_INFO(void): dw64Addr(0), dwCode(0), dwFlag(0)
            {
            }
        };
        /// ���ö�ջ��Ϣ
        struct S_CALL_STACK_INFO
        {
            CString strModuleName;      ///< ģ����
            CString strMethodName;      ///< ������
            CString strFileName;             ///< �ļ���
            DWORD dwLineNo;              ///< �����к�
            S_CALL_STACK_INFO(void): dwLineNo(0)
            {
            }
        };
        static int s_iType;      ///< �쳣��������
        static LPTOP_LEVEL_EXCEPTION_FILTER s_lpPrevFilter;  ///< ֮ǰ���쳣������ָ��

        /// �쳣��������
        static long _stdcall AppCrashHandler(_EXCEPTION_POINTERS *pExceptionInfo_);
        /// ��ȡ���������Ϣ
        static bool GetCrashInfo(const EXCEPTION_RECORD *pRecord_, S_CRASH_INFO &crash_);
        /// ��ȡ���ö�ջ��Ϣ
        static bool GetCallStackInfo(const CONTEXT *pContext_, vector<S_CALL_STACK_INFO> &vecStack_);
        /// ����dump�ļ�
        static bool CreateDumpFile(_EXCEPTION_POINTERS *pExceptionInfo_, const char *szFilePath_);
    };


    /// ��ַ����
    enum E_BH_ADDRESS_TYPE
    {
        ADDR_MAC,
        ADDR_IPV4,
        ADDR_IPV6
    };
    /// ��ַ��
    class _KDCOMMLIB_API_ CBHAddress
    {
    public:
        /// ��ַ����
        enum
        {
            ADDR_MAC,
            ADDR_IPV4,
            ADDR_IPV6
        };

        CBHAddress(int iType_ = ADDR_MAC);
        CBHAddress(const CBHAddress &addr_);
        CBHAddress & operator=(const CBHAddress &addr_);

        /// ��ȡ����
        int GetType(void);
        /// ��ȡ��ַ
        bool GetAddress(CString &strAddr_);
        bool GetAddress(vector<BYTE> &vbyAddr_);
        /// ���õ�ַ
        bool SetAddress(const char *szAddr_);
        bool SetAddress(const vector<BYTE> &vbyAddr_);

    protected:
        BYTE _abyAddr[16];   ///< ��ַ��Ϣ
        int _iType;                 ///< ��ַ����
        int _nLen;                  ///< ��ַ����
        int _nGroups;            ///< ��ַ������
        char _chSep;             ///< ��ַ�ַ����ķָ���
        bool _bHex;              ///< �Ƿ�16���Ʊ�ʾ
        bool _bInit;               ///< ��ʼ���Ƿ�ɹ�

        /// �ַ���ת��16������
        static void Str2Hex(const char *szHexStr_, vector<BYTE> &vbyHex_);
    };

    /// ����������
    class _KDCOMMLIB_API_ CBHNetworkAdapters
    {
    public:
        CBHNetworkAdapters(void);
        ~CBHNetworkAdapters(void);

        /// ˢ��������Ϣ
        void Refresh(void);
        /// ��������
        unsigned int GetAdaptersCount(void);
        /// ��ȡ��������
        CString GetAdapterName(unsigned int iAdapter_);
        /// ��ȡ����������Ϣ
        CString GetAdapterDescription(unsigned int iAdapter_);
        /// ��ȡ���������ַ
        bool GetPhysicalAddress(unsigned int iAdapter_, CBHAddress &addrMac_);
        /// ��ȡIP��ַ��Ŀ
        unsigned int GetIPAddressesCount(unsigned int iAdapter_);
        /// ��ȡIP��ַ
        bool GetIPAddress(unsigned int iAdapter_, unsigned int iAddr_, CBHAddress &addrIP_);
        /// ��ȡ��������
        bool GetSubnetMask(unsigned int iAdapter_, unsigned int iAddr_, CBHAddress &addrSubnet_);
        /// ��ȡ������Ŀ
        unsigned int GetGatewaysCount(unsigned int iAdapter_);
        /// ��ȡ���ص�ַ
        bool GetGatewayAddress(unsigned int iAdapter_, unsigned int iGateway_, CBHAddress &addrGateway_);

    protected:
        /// ������Ϣ�ṹ��
        struct S_BHNetworkAdapter
        {
            CString _strName;                                     ///< ��������
            CString _strDescription;                             ///< ����������Ϣ
            CBHAddress _addrMac;                             ///< ���������ַ
            vector<CBHAddress> _vecIpAddr;             ///< IP��ַ�б�
            vector<CBHAddress> _vecSubnetMask;    ///< ���������б�
            vector<CBHAddress> _vecGateway;         ///< �����б�
        };

        vector<S_BHNetworkAdapter> _vecAdapters;   ///< ������Ϣ
    };

	//@}
}
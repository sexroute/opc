#ifndef __BKTRACELOG_H__
#define __BKTRACELOG_H__

#include <KD5000\BH5000Macro.h>
#include <BHLog.h>

#define BH5000_TRACE_ON                     (1)
#define BH5000_TRACE_OFF                    (0)

enum BH5000_TRACE_KIND{
	BTK_DEBUG = 0,
	BTK_WARNING,
	BTK_ERROR,
	BTK_MAX_NUM
};


/* 日志选项开关 */
#define BH5000_OPT_CLEAR_LAST_LOG_AT_START   (BH5000_TRACE_OFF)
#define BH5000_OPT_WRITE_LOG_TO_FILE         (BH5000_TRACE_OFF)

/* General Methods */
#define BH5000_TRACE_LOG_ON                  (BH5000_TRACE_OFF)

/* Information */
#define BH5000_TRACE_INFO_ON                 (BH5000_TRACE_OFF)
#define BH5000_TRACE_INFO_ID_ON              (BH5000_TRACE_OFF)
#define BH5000_TRACE_INFO_PO_ON              (BH5000_TRACE_OFF)
#define BH5000_TRACE_INFO_PO_SND_ON          (BH5000_TRACE_OFF)
#define BH5000_TRACE_INFO_PO_RCV_ON          (BH5000_TRACE_OFF)
#define BH5000_TRACE_INFO_PO_NTF_ON          (BH5000_TRACE_OFF)

/* Function */
#define BH5000_TRACE_FUNC_ON                 (BH5000_TRACE_OFF)
#define BH5000_TRACE_FUNC_PO_ON              (BH5000_TRACE_OFF)
#define BH5000_TRACE_FUNC_PO_SND_ON          (BH5000_TRACE_OFF)
#define BH5000_TRACE_FUNC_PO_RCV_ON          (BH5000_TRACE_OFF)
#define BH5000_TRACE_FUNC_PO_NTF_ON          (BH5000_TRACE_OFF)

/* Warning */
#define BH5000_TRACE_WARNING_ON              (BH5000_TRACE_OFF)
/* Error */
#define BH5000_TRACE_ERROR_ON                (BH5000_TRACE_ON)
/* File */
#define BH5000_LOG_ERROR_ON                  (BH5000_TRACE_ON)

/// <Trace Categories>
/* Information */
#define BH5000_TRACE_CAT_INFO             "(II)"
#define BH5000_TRACE_CAT_INFO_PO          "[PO]"
#define BH5000_TRACE_CAT_INFO_ID          "[ID]"
#define BH5000_TRACE_CAT_INFO_PO_SND      "[PO-MSG-SND]"
#define BH5000_TRACE_CAT_INFO_PO_RCV      "[PO-MSG-RCV]"
#define BH5000_TRACE_CAT_INFO_PO_NTF      "[PO-MSG-NTF]"
/* Function */
#define BH5000_TRACE_CAT_FUNC             "(FUNC)"
#define BH5000_TRACE_CAT_FUNC_PO          "[PO]"
#define BH5000_TRACE_CAT_FUNC_PO_SND      "[PO-MSG-SND]"
#define BH5000_TRACE_CAT_FUNC_PO_RCV      "[PO-MSG-RCV]"
#define BH5000_TRACE_CAT_FUNC_PO_NTF      "[PO-MSG-NTF]"
/* Warning */
#define BH5000_TRACE_CAT_WARNING          "(WW)"
/* Error */
#define BH5000_TRACE_CAT_ERROR            "(EE)"
/// </Trace Categories>

#include "KD5000/BH5000Macro.h"

class BH5000_EXT_CLASS CBH5000TraceLog
{
public:
	CBH5000TraceLog(const CString & strLog, const CString & strCat);
	~CBH5000TraceLog(void);
protected:
	CString m_strLog;
	CString m_strCat;
};

class BH5000_EXT_CLASS CBH5000TraceFuncLog : public CBH5000TraceLog
{
public:
	CBH5000TraceFuncLog(const CString & strLog,
	                    const CString & strCat = BH5000_TRACE_CAT_FUNC);

	~CBH5000TraceFuncLog(void);
private:
	void TraceFuncEntry();
	void TraceFuncExit();
private:
	int m_nNo;
};



void BH5000_EXT_FUNC _bh5000_send_log_to_tt(const int nKind, 
											const TCHAR * strTrace, const TCHAR * strLoc);

void BH5000_EXT_FUNC _bh5000_trace_func_entry(const CString & strLog,
                         const CString &strCategory = BH5000_TRACE_CAT_FUNC);

void BH5000_EXT_FUNC _bh5000_trace_func_exit(const CString & strLog,
                         const CString &strCategory = BH5000_TRACE_CAT_FUNC);

/* BH5000_TRACE_LOG
<in> Kind
- 0 Information
- 1 Warning
- 2 Error
BH5000_TRACE_LOG */

#if BH5000_TRACE_LOG_ON
	#define BH5000_TRACE_LOG(Kind, Trace, Comment)  \
	{ \
		CString strLoc; \
		strLoc.Format("%s@%d",  __FUNCTION__, __LINE__); \
		CString strMsg; \
		strMsg.Format("%s %s", Trace, Comment); \
		_bh5000_send_log_to_tt(Kind, strMsg, strLoc); \
	}
#else
	#define BH5000_TRACE_LOG(Kind, Trace, Comment)
#endif


/* BH5000_TRACE_DUMP
<in> Kind
- BTK_DEBUG Information
- BTK_WARNING Warning
- BTK_ERROR Error
BH5000_TRACE_DUMP */

#if BH5000_TRACE_INFO_ON
	#define BH5000_TRACE_INFO(info) BHLOG_DEBUG(info)
#else
	#define BH5000_TRACE_INFO(info)
#endif


#if BH5000_TRACE_INFO_PO_ON
#define BH5000_TRACE_INFO_PO(info) BHLOG_DEBUG(STR("[POMSG]", info))
#else
#define BH5000_TRACE_INFO_PO(info)
#endif

#if BH5000_TRACE_INFO_ID_ON
	#define BH5000_TRACE_INFO_ID(ID) \
		BHLOG_DEBUG(STR("%s %s(0x%04x/%d)", BH5000_TRACE_CAT_INFO_ID, #ID, ID, ID))
#else
	#define BH5000_TRACE_INFO_ID(ID)
#endif

#if BH5000_TRACE_INFO_PO_SND_ON
	#define BH5000_TRACE_INFO_PO_SND(PO_MSG_ID, FuncName) \
		BHLOG_DEBUG(STR("%s %s(0x%04x/%d)--%s", \
			BH5000_TRACE_CAT_INFO_PO_SND, \
			#PO_MSG_ID, PO_MSG_ID, PO_MSG_ID, #FuncName))
#else
	#define BH5000_TRACE_INFO_PO_SND(PO_MSG_ID, FuncName)
#endif

#if BH5000_TRACE_INFO_PO_RCV_ON
	#define BH5000_TRACE_INFO_PO_RCV(PO_MSG_ID, FuncName) \
		BHLOG_DEBUG(STR("%s %s(0x%04x/%d)--%s", \
			BH5000_TRACE_CAT_INFO_PO_RCV, \
			#PO_MSG_ID, PO_MSG_ID,PO_MSG_ID, #FuncName))
#else
	#define BH5000_TRACE_INFO_PO_RCV(PO_MSG_ID, FuncName)
#endif

#if BH5000_TRACE_INFO_PO_NTF_ON
	#define BH5000_TRACE_INFO_PO_NTF(PO_MSG_ID, FuncName) \
		BHLOG_DEBUG(STR("%s %s(0x%04x/%d)--%s", \
			BH5000_TRACE_CAT_INFO_PO_NTF, \
			#PO_MSG_ID, PO_MSG_ID, PO_MSG_ID, #FuncName))
#else
	#define BH5000_TRACE_INFO_PO_NTF(PO_MSG_ID, FuncName)
#endif

#if BH5000_TRACE_FUNC_ON
	#define BH5000_TRACE_FUNC_ENTRY(FuncName) \
	    _bh5000_trace_func_entry(FuncName)
	#define BH5000_TRACE_FUNC_EXIT(FuncName) \
		_bh5000_trace_func_exit(FuncName)
	#define BH5000_TRACE_FUNC_ENTRY_EXIT(FuncName) \
		CBH5000TraceFuncLog __bh5000_trace_func_log(FuncName)
#else
	#define BH5000_TRACE_FUNC_ENTRY(FuncName)
	#define BH5000_TRACE_FUNC_EXIT(FuncName)
	#define BH5000_TRACE_FUNC_ENTRY_EXIT(FuncName)
#endif

#define BH5000_TRACE_FUNC  BH5000_TRACE_FUNC_ENTRY_EXIT

#if BH5000_TRACE_FUNC_PO_ON
	#define BH5000_TRACE_FUNC_PO_ENTRY(FuncName) \
	    _bh5000_trace_func_entry(FuncName, BH5000_TRACE_CAT_FUNC_PO)
	#define BH5000_TRACE_FUNC_PO_EXIT(FuncName) \
		_bh5000_trace_func_exit(FuncName, BH5000_TRACE_CAT_FUNC_PO)
	#define BH5000_TRACE_FUNC_PO_ENTRY_EXIT(FuncName) \
		CBH5000TraceFuncLog __bh5000_trace_func_log(FuncName, BH5000_TRACE_CAT_FUNC_PO)
#else
	#define BH5000_TRACE_FUNC_PO_ENTRY(FuncName)
	#define BH5000_TRACE_FUNC_PO_EXIT(FuncName)
	#define BH5000_TRACE_FUNC_PO_ENTRY_EXIT(FuncName)
#endif

#define BH5000_TRACE_FUNC_PO BH5000_TRACE_FUNC_PO_ENTRY_EXIT

#if BH5000_TRACE_FUNC_PO_SND_ON
	#define BH5000_TRACE_FUNC_PO_SND_ENTRY(FuncName) \
	    _bh5000_trace_func_entry(FuncName, BH5000_TRACE_CAT_FUNC_PO_SND)
	#define BH5000_TRACE_FUNC_PO_SND_EXIT(FuncName) \
		_bh5000_trace_func_exit(FuncName, BH5000_TRACE_CAT_FUNC_PO_SND)
	#define BH5000_TRACE_FUNC_PO_SND_ENTRY_EXIT(FuncName) \
		CBH5000TraceFuncLog __bh5000_trace_func_log(FuncName, BH5000_TRACE_CAT_FUNC_PO_SND)
#else
	#define BH5000_TRACE_FUNC_PO_SND_ENTRY(FuncName)
	#define BH5000_TRACE_FUNC_PO_SND_EXIT(FuncName)
	#define BH5000_TRACE_FUNC_PO_SND_ENTRY_EXIT(FuncName)
#endif

#define BH5000_TRACE_FUNC_PO_SND BH5000_TRACE_FUNC_PO_SND_ENTRY_EXIT

#if BH5000_TRACE_FUNC_PO_RCV_ON
	#define BH5000_TRACE_FUNC_PO_RCV_ENTRY(FuncName) \
	    _bh5000_trace_func_entry(FuncName, BH5000_TRACE_CAT_FUNC_PO_RCV)
	#define BH5000_TRACE_FUNC_PO_RCV_EXIT(FuncName) \
		_bh5000_trace_func_exit(FuncName, BH5000_TRACE_CAT_FUNC_PO_RCV)
	#define BH5000_TRACE_FUNC_PO_RCV_ENTRY_EXIT(FuncName) \
		CBH5000TraceFuncLog __bh5000_trace_func_log(FuncName, BH5000_TRACE_CAT_FUNC_PO_RCV)
#else
	#define BH5000_TRACE_FUNC_PO_RCV_ENTRY(FuncName)
	#define BH5000_TRACE_FUNC_PO_RCV_EXIT(FuncName)
	#define BH5000_TRACE_FUNC_PO_RCV_ENTRY_EXIT(FuncName)
#endif

#define BH5000_TRACE_FUNC_PO_RCV BH5000_TRACE_FUNC_PO_RCV_ENTRY_EXIT

#if BH5000_TRACE_FUNC_PO_NTF_ON
	#define BH5000_TRACE_FUNC_PO_NTF_ENTRY(FuncName) \
	    _bh5000_trace_func_entry(FuncName, BH5000_TRACE_CAT_FUNC_PO_NTF)
	#define BH5000_TRACE_FUNC_PO_NTF_EXIT(FuncName) \
		_bh5000_trace_func_exit(FuncName, BH5000_TRACE_CAT_FUNC_PO_NTF)
	#define BH5000_TRACE_FUNC_PO_NTF_ENTRY_EXIT(FuncName) \
		CBH5000TraceFuncLog __bh5000_trace_func_log(FuncName, BH5000_TRACE_CAT_FUNC_PO_NTF)
#else
	#define BH5000_TRACE_FUNC_PO_NTF_ENTRY(FuncName)
	#define BH5000_TRACE_FUNC_PO_NTF_EXIT(FuncName)
	#define BH5000_TRACE_FUNC_PO_NTF_ENTRY_EXIT(FuncName)
#endif

#define BH5000_TRACE_FUNC_PO_NTF BH5000_TRACE_FUNC_PO_NTF_ENTRY_EXIT

#if BH5000_TRACE_WARNING_ON
	#define BH5000_TRACE_WARNING(Warning)  BHLOG_WARN( Warning)
#else
	#define BH5000_TRACE_WARNING(Warning)
#endif

#define BH5000_TRACE_ERROR(Error) BHLOG_ERROR(Error)

#define BH5000_TRACE_ARRAY(WaveName, WaveData, WaveNum) \
do {\
	CString sLog; \
	CString sTemp; \
	int   nWaveNum = WaveNum; \
	if(nWaveNum > 0) \
		sLog.Format("%f", (float)WaveData[0]); \
	for(int i = 1; i < nWaveNum; i++){ \
		sTemp.Format(",%f", (float)WaveData[i]); \
		sLog += sTemp; \
	} \
	BH5000_TRACE_LOG(BTK_DEBUG, WaveName, sLog); \
}while(0)



#define WRITE_FATAL(e) 	if (NULL!=e)\
						{\
						CString lstrErrorMessage;\
						e->GetErrorMessage(lstrErrorMessage.GetBufferSetLength(1024),255);\
						lstrErrorMessage.ReleaseBuffer();\
						BHLOG_FATAL(lstrErrorMessage);\
						e->Delete();\
						}\


#define BEGIN_ERROR_HANDLE		try{ \
										try{\

#define END_ERROR_HANDLE				    }\
											catch (CMemoryException* e)\
											{\
											WRITE_FATAL(e);\
											}\
											catch (CFileException* e)\
											{\
											WRITE_FATAL(e);\
											}\
											catch (CException* e)\
											{\
											WRITE_FATAL(e);\
											}\
									}catch(...){WRITE_FATAL_LOG;}

#define WRITE_FATAL_LOG 						{\
													ASSERT(FALSE);\
													CString lstrFatalLine ;\
													lstrFatalLine.Format(_T("****** Fatal Error ****** %s %d"),__FILE__,__LINE__);\
													BHLOG_FATAL(lstrFatalLine);\
												};

#endif
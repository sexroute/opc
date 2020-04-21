#ifndef  __BHLOG_H__
#define __BHLOG_H__

#include <KD5000\BH5000Macro.h>

enum BHLOG_MODE_ENUM {
	BHLOG_MODE_TRACE  = 0,
	BHLOG_MODE_DEBUG,
	BHLOG_MODE_INFO,
	BHLOG_MODE_WARN,
	BHLOG_MODE_ERROR,
	BHLOG_MODE_FATAL,
	BHLOG_MODE_FILE,
	BHLOG_MODE_NUM
};

BH5000_EXT_FUNC CString getStringFormattedAs(const TCHAR * format, ...);
BH5000_EXT_FUNC bool BHLog(BHLOG_MODE_ENUM level, CString msg, CString loc);

#define STR getStringFormattedAs


#define gc_cTimeFormat          "%Y-%m-%d %H:%M:%S"

#define BHLOG(level, info) \
	do {	CString sLine; \
	sLine.Format("%s@%d", __FUNCTION__, __LINE__); \
	BHLog(level, info, sLine); \
	}while(0)

#define _BHLOG_TRACE(info)
#define _BHLOG_DEBUG(info)
#define _BHLOG_INFO(info)
#define _BHLOG_WARN(info)
#define _BHLOG_ERROR(info)
#define _BHLOG_FATAL(info)
#define _BHLOG_FILE(info)

#define _BHLOG_ARRAY(ArrayName, ArrayData, ArrayNum)

#define BHLOG_TRACE(info) BHLOG(BHLOG_MODE_TRACE, info)
#define BHLOG_DEBUG(info) BHLOG(BHLOG_MODE_DEBUG, info)
#define BHLOG_INFO(info)  BHLOG(BHLOG_MODE_INFO,  info)
#define BHLOG_WARN(info)  BHLOG(BHLOG_MODE_WARN,  info)
#define BHLOG_ERROR(info) BHLOG(BHLOG_MODE_ERROR, info)
#define BHLOG_FATAL(info) BHLOG(BHLOG_MODE_FATAL, info)
#define BHLOG_FILE(info)  BHLOG(BHLOG_MODE_FILE, info)

#define BHLOG_ARRAY(ArrayName, ArrayData, ArrayNum) \
do {\
	if(ArrayNum > 0){ \
	string logStr = ArrayName; \
	logStr.append(STR("[%d]=%f", ArrayNum, (double)ArrayData[0])); \
	for(int i = 1; i < ArrayNum; i++){ \
	logStr.append(STR(",%f", (double)ArrayData[i])); \
	} \
	BHLOG_DEBUG(logStr); \
	} \
}while(0)

#define BHLOG_ID(id) BHLOG_DEBUG(STR("%s(%d)", # id, id))

#endif
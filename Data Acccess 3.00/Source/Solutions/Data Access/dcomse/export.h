#ifndef _CALLBACK_EXPORT_H_ 
#define _CALLBACK_EXPORT_H_

#if defined(CALLBACK_EXPORT)
#define CALLBACK_EXPORT_API  extern "C" __declspec(dllexport) 
#else 
#define CALLBACK_EXPORT_API  extern "C" __declspec(dllimport) 
#endif
CALLBACK_EXPORT_API bool __stdcall login(const char * username, const char * password, const char * domain);



#endif
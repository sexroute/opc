#ifndef BH5000_VERSION_H
#define BH5000_VERSION_H


/*
 * BHClient Version Infomation
 */
/* The numeric compile-time version constants. These constants are the
 * authoritative version numbers for BH5000. 
 */

/** major version 
 * Major API changes that could cause compatibility problems for older
 * programs such as structure size changes.  No binary compatibility is
 * possible across a change in the major version.
 */
#define BH5000_BHClient_MAJOR_VERSION       4

/** minor version
 * Minor API changes that do not cause binary compatibility problems.
 * Reset to 0 when upgrading BH5000_BHClient_MAJOR_VERSION
 */
#define BH5000_BHClient_MINOR_VERSION       1

/** patch level 
 * The MICRO Level never includes API changes, simply bug fixes.
 * Reset to 0 when upgrading BH5000_BHClient_MINOR_VERSION
 */
#define BH5000_BHClient_MICRO_VERSION       1

/** 
 * The symbol BH5000_BHClient_IS_DEV_VERSION is only defined for internal,
 * "development" copies of BH5000.  It is undefined for released versions
 * of BH5000.
 */
/* #undef BH5000_BHClient_IS_DEV_VERSION */



#ifndef BH5000_BHClient_STRINGIFY
/** Helper macro for BH5000_BHClient_STRINGIFY */
#define BH5000_BHClient_STRINGIFY_HELPER(n) #n

/** Properly quote a value as a string in the C preprocessor */
#define BH5000_BHClient_STRINGIFY(n) BH5000_BHClient_STRINGIFY_HELPER(n)
#endif

/** The formatted string of BH5000's version */
#define BH5000_BHClient_VERSION_STRING \
     BH5000_BHClient_STRINGIFY(BH5000_BHClient_MAJOR_VERSION) "." \
     BH5000_BHClient_STRINGIFY(BH5000_BHClient_MINOR_VERSION) "." \
     BH5000_BHClient_STRINGIFY(BH5000_BHClient_MICRO_VERSION)

/** An alternative formatted string of BH5000's version */
/* macro for Win32 .rc files using numeric csv representation */
#define BH5000_BHClient_VERSION_STRING_CSV BH5000_BHClient_MAJOR_VERSION ##, \
                             ##BH5000_BHClient_MINOR_VERSION ##, \
                             ##BH5000_BHClient_MICRO_VERSION
                             
/*
 * BH5000 Product Version Information
 */

/**
 * @file BH5000_version.h
 * @brief BH5000 Versioning Interface
 * 
 * BH5000's Version
 *
 */

/* The numeric compile-time version constants. These constants are the
 * authoritative version numbers for BH5000. 
 */

/** major version 
 * Major API changes that could cause compatibility problems for older
 * programs such as structure size changes.  No binary compatibility is
 * possible across a change in the major version.
 */
#define BH5000_MAJOR_VERSION       4

/** minor version
 * Minor API changes that do not cause binary compatibility problems.
 * Reset to 0 when upgrading BH5000_MAJOR_VERSION
 */
#define BH5000_MINOR_VERSION       1

/** patch level 
 * The MICRO Level never includes API changes, simply bug fixes.
 * Reset to 0 when upgrading BH5000_MINOR_VERSION
 */
#define BH5000_MICRO_VERSION       1

#define BH5000_PACKAGE_VERSION     3


/** 
 * The symbol BH5000_IS_DEV_VERSION is only defined for internal,
 * "development" copies of BH5000.  It is undefined for released versions
 * of BH5000.
 */
/* #undef BH5000_IS_DEV_VERSION */



#ifndef BH5000_STRINGIFY
/** Helper macro for BH5000_STRINGIFY */
#define BH5000_STRINGIFY_HELPER(n) #n

/** Properly quote a value as a string in the C preprocessor */
#define BH5000_STRINGIFY(n) BH5000_STRINGIFY_HELPER(n)
#endif

/** The formatted string of BH5000's version */
#define BH5000_VERSION_STRING \
     BH5000_STRINGIFY(BH5000_MAJOR_VERSION) "." \
     BH5000_STRINGIFY(BH5000_MINOR_VERSION) "." \
     BH5000_STRINGIFY(BH5000_MICRO_VERSION)

/** An alternative formatted string of BH5000's version */
/* macro for Win32 .rc files using numeric csv representation */
#define BH5000_VERSION_STRING_CSV BH5000_MAJOR_VERSION ##, \
                             ##BH5000_MINOR_VERSION ##, \
                             ##BH5000_MICRO_VERSION


#endif /* ndef BH5000_VERSION_H */

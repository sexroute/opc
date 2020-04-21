// DVSYSsymbols.h -- Offset definitions for extensible counters

// The names below MUST match with the names in DVSYSperf.ini
// and the numbers match with the order of the counter definitions
// found in DiOPCperfMon.cpp.  The index of a counter is the number
// here divided by 2.  The table in DiOPCperfMon.cpp sets the type
// and scale for each of the performance numbers

#define DVSYS_Server                   0
#define DVSYS_Sessions                 2
#define DVSYS_GroupCount               4
#define DVSYS_GroupRate                6
#define DVSYS_ItemCount                8
#define DVSYS_ItemRate                10
#define DVSYS_AsyncReadRate           12
#define DVSYS_SyncReadRate            14
#define DVSYS_ChgReadRate             16
#define DVSYS_DeltaVModuleCount       18
#define DVSYS_DeltaVItemCount         20
#define DVSYS_DeltaVItemRate          22
#define DVSYS_DeltaVOCNBoundCount     24
#define DVSYS_DeltaVOCNRate           26
#define DVSYS_DeltaVReadRate          28
#define DVSYS_DeltaVEhiEloRate        30
#define DVSYS_DeltaVSglItemReadRate   32
#define DVSYS_DeltaVItemWriteRate     34
#define DVSYS_DeltaVOtherObjectCount  36



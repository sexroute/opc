

//This file gives offsets to the counters.


//
//  DVDgCtrnm.h
//
//  Offset definition file for extensible counter objects and counters
//
//  These "relative" offsets must start at 0 and be multiples of 2 (i.e.
//  even numbers). In the Open Procedure, they will be added to the 
//  "First Counter" and "First Help" values for the device they belong to, 
//  in order to determine the absolute location of the counter and 
//  object names and corresponding Explain text in the registry.
//
//  This file is used by the extensible counter DLL code as well as the 
//  counter name and Explain text definition file (.INI) file that is used
//  by LODCTR to load the names into the registry.
//
#define DVDGOBJ 0
#define REDTIM 2
#define CONTIM 4
#define COMTIM 6
#define OTRTIM 8
#define IDLTIM 10


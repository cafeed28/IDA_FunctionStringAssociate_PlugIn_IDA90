
// ****************************************************************************
// File: Main.cpp
// Desc: Function String Associate plug-in
//
// ****************************************************************************
#include "stdafx.h"

// === Function Prototypes ===
plugmod_t* idaapi IDAP_init();
void idaapi IDAP_term();
bool idaapi IDAP_run(size_t arg);
extern void CORE_Init();
extern void CORE_Process(size_t iArg);
extern void CORE_Exit();


// === Data ===
const static char IDAP_name[] = "Function String Associate";

// Plug-in description block
extern "C" ALIGN(32) plugin_t PLUGIN =
{
	IDP_INTERFACE_VERSION,	// IDA version plug-in is written for
	PLUGIN_UNL,				// Plug-in flags
	IDAP_init,	            // Initialization function
	IDAP_term,	            // Clean-up function
	IDAP_run,	            // Main plug-in body
    IDAP_name,	            // Comment - unused
    IDAP_name,	            // As above - unused
	IDAP_name,	            // Plug-in name shown in Edit->Plugins menu
	NULL                    // Hot key to run the plug-in
};

// Init
plugmod_t* idaapi IDAP_init()
{
    CORE_Init();
    return(PLUGIN_OK);
}

// Un-init
void idaapi IDAP_term()
{
    CORE_Exit();
}

// Run
bool idaapi IDAP_run(size_t iArg)
{
    CORE_Process(iArg);
	return true;
}




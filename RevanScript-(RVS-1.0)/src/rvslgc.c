// C Standard Libraries
#include <stdlib.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsctl.h"
#include "../include/rvslgc.h"


// RevanScript Direct Data Logic (Create Function)
RVS_DIRECT_LOGIC* rvs_direct_logic_create(void){
	RVS_DIRECT_LOGIC* rvs_direct_logic = (RVS_DIRECT_LOGIC*) malloc(sizeof(RVS_DIRECT_LOGIC));
	if (!rvs_direct_logic) return NULL;
	rvs_direct_logic->string_literal_check = false;
	rvs_direct_logic->binary_start_operation_check = false;
	rvs_direct_logic->expression_check = false;
	rvs_direct_logic->expression_queue = RVS_UNDEFINED_QUEUE;
	return rvs_direct_logic;
}


// RevanScript Direct Data Logic (Delete Function)
void rvs_direct_logic_delete(RVS_DIRECT_LOGIC* rvs_direct_logic){
	free(rvs_direct_logic);
}


// RevanScript Variable Logic (Create Function)
RVSLGC* rvs_logic_create(void){
    RVSLGC* rvs_logic = (RVSLGC*) malloc(sizeof(RVSLGC));
    if (!rvs_logic) return NULL;
    rvs_logic->assignment_operation_check = false;
	rvs_logic->string_literal_check = false;
	rvs_logic->binary_start_operation_check = false;
	rvs_logic->expression_check = false;
	rvs_logic->expression_queue = RVS_UNDEFINED_QUEUE;
    return rvs_logic;
}


// RevanScript Variable Logic (Delete Function)
void rvs_logic_delete(RVSLGC* rvs_logic){
	free(rvs_logic);
}
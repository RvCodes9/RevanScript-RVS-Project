#ifndef RVSCTL_H
#define RVSCTL_H

#include <stdbool.h>

#include "rvsmem.h"


// RevanScript Variable Logic (Variable Created Logical Variables)
typedef struct{
    bool assignment_operation_check;
	bool string_literal_check;
} RVSLOGIC;


// Checking Functions
bool rvs_file_type_check(const char*);
bool rvs_variable_name_check(const RVSBUF*, const RVSMEM*, bool);
bool rvs_variable_data_check(const RVSBUF*, const RVSLOGIC*);


#endif
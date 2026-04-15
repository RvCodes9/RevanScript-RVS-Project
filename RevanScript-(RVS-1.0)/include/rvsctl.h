#ifndef RVSCTL_H
#define RVSCTL_H

#include <stdbool.h>

#include "rvsmem.h"


// RevanScript Variable Type Struct
typedef struct{
	bool string_type_check;
	bool integer_type_check;
	bool float_type_check;
	bool boolean_type_check;
	bool binary_type_check;
} RVSTYPE;


// RevanScript Variable Logic (Variable Created Logical Variables)
typedef struct{
    bool assignment_operation_check;
	bool string_literal_check;
} RVSLOGIC;


// Checking Functions
bool rvs_file_type_check(const char*);
bool rvs_variable_name_check(const RVSBUF*, const RVSMEM*, bool);
bool rvs_variable_data_check(const RVSBUF*, const RVSTYPE*, const RVSLOGIC*);


#endif
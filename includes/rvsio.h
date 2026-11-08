#ifndef RVSIO_H
#define RVSIO_H

// C Standard Librarys
#include <stdbool.h>
#include <stdint.h>

// RevanScript (RVS) Core / Engine Librarys
#include "rvstbl.h"

// RevanScript (RVS) Execution Mode
enum {RVS_FILE_MODE, RVS_REPL_MODE};

// RevanScript Input/Output Type
typedef union{
    char* output_buffer;
    char* input_buffer;
} RVSIO_Buffer;

// RevanScript (RVS) REPL Message
#define RVS_REPL_MESSAGE   "RevanScript (RVS) Programming Language \nRead Eval Print Loop (REPL)"

// RevanScript (RVS) Info Messages
#define RVS_VARIABLE_CONSTANT_INFO                        "%s[RVSVariableConstantInfo] : The variable you want to make constant is a constant.%s\n"

// RevanScript I/O Functions
void rvs_standard_output(const RVSIO_Buffer*, const int8_t*);
void rvs_standard_table_output(const RVSTBL*);
void rvs_standard_input(RVSIO_Buffer*, const int8_t*);
void rvs_standard_debug(bool, const char*);
void rvs_standard_info(const char*);
void rvs_standard_error(const char*, const char*);

#endif
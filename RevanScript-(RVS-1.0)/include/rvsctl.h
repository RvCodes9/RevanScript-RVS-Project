#ifndef RVSCTL_H
#define RVSCTL_H

#include <stdbool.h>

#include "rvsmem.h"

bool rvs_file_type_check(const char*);
bool rvs_variable_name_check(const RVSBUF*, const RVSMEM*, bool);

#endif
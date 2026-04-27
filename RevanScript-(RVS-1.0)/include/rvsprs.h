#ifndef RVSPRS_H
#define RVSPRS_H

#include "../include/rvsmem.h"
#include "../include/rvsbuf.h"

RVSBUF* rvs_variable_parser(const char*, RVSMEM*, bool);
RVSBUF* rvs_variable_name_parser(const char*);

#endif
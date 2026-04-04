#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


#include "rvsio.h"


bool rvs_file_type_check(const char* const file_type){
    if (strcmp(file_type, ".rvs") == 0){
        return true;
    }

    else{
        rvs_standard_error(RVS_FILE_TYPE_ERROR, NULL);
        return false;
    }
}


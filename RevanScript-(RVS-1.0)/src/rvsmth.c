// C Standard Libraries
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

// RevanScript (RVS) Core / Engine Libraries
#include "../include/rvsmth.h"


// RevanScript (RVS) Stabilize Number Length Function 
void _rvs_stabilize_number_length(char* num1, 
                                  char* num2, 
                                  const size_t* const num1_length, 
                                  const size_t* const num2_length)

{
    if (*num1_length > *num2_length){
        size_t length = *num1_length - *num2_length;
        memmove(num2 + length, num2, *num2_length + 1);
        for (size_t i = 0; i < length; i++) num2[i] = '0';
    }

    else if (*num2_length > *num1_length){
        size_t length = *num2_length - *num1_length;
        memmove(num1 + length, num1, *num1_length + 1);
        for (size_t i = 0; i < length; i++) num1[i] = '0';
    }
}


// RevanScript Reverse Number Process Function
bool _rvs_reverse_number_process(char* number, const size_t* const number_length){
    char* reverse_number = (char*) malloc(sizeof(char) * 2048);
    if (!reverse_number) return false;
    size_t reverse_number_counter = 0;
    for (int i = (int) *number_length - 1; i >= 0; i--){
        reverse_number[reverse_number_counter++] = number[i];
    }
    reverse_number[reverse_number_counter] = '\0';
    strcpy(number, reverse_number);
    free(reverse_number);
    return true;
}


// RevanScript Numbers Addition Function
RVSMTH* rvs_math_int_add(char* num1, char* num2){
    char* total = (char*) calloc(sizeof(char), 2048);
    if (!total) return NULL;

    const size_t num1_length = strlen(num1);
    const size_t num2_length = strlen(num2);
    size_t total_counter = 0;
    int carry = 0;

    _rvs_stabilize_number_length(num1, num2, &num1_length, &num2_length);

    for (int i = num1_length - 1; i >= 0; i--){
        int number1 = (int) num1[i] - '0';
        int number2 = (int) num2[i] - '0';
        int addition = number1 + number2 + carry;
        int result = addition % 10; 
        carry = addition / 10;
        total[total_counter++] = ((char) result) + '0';
    }

    if (carry > 0){
        total[total_counter++] = carry + '0';
    }

    total[total_counter] = '\0';
    if (_rvs_reverse_number_process(total, &total_counter) == false){
        free(total);
        return NULL;
    }
    return total;
}


// RevanScript Math Memory Delete
void rvs_math_memory_delete(RVSMTH* math_memory){
    free(math_memory);
}
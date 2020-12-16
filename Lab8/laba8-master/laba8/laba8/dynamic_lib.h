#pragma once
#include "record.h"

int ** dynamic_array(size_t height);
int *dynamic_array2(size_t height);
void dynamic_array_free1(int *b, size_t height);
void dynamic_array_free(int **a, size_t height);

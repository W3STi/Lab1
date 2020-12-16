#pragma once
#include "dynamic_lib.h"
#include <vector>

void BFSD(int start, int* dist, int** a, int n);
void DFSD(int start, int* dist, vector<vector<int>> a, vector<int> wes, int n, int fantom_n);

void zad1();
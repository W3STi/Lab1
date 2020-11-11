#pragma once
#include "dynamic_lib.h"

void BFSD(int start, int* dist, int** a, int n);
void BFSDList(int v, int *dist, List *a, int n);
void DFSD(int start, int* dist, int** a, int n);
void DFSDList(int v, int* dist, List* a, int n);
void BFSD_norec(int start, int* dist, int** a, int n);
void DFSD_norec(int start, int* dist, int** a, int n);

void zad1();
void zad2();
void zad3();
void zad4();
void zvezdochki();
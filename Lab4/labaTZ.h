#pragma once
#include "dynamic_lib.h"

void dfs(int v, int *vis, int **a, int n);
void dfslist(int v, int *vis, List *a, int n);
void dfs_norec(int start, int *vis, int **a, int n);
void dfs_norec_lib(int v, int *vis, int **a, int n);
void dfs_norec_no(int start, int *vis, int **a, int n);
void dfs_norec_no_lib(int v, int *vis, int **a, int n);
void zad1();
void zad2();
void zad3();
void zvezdochki();
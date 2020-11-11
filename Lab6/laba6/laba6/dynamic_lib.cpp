#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

#include "record.h"
#include "dynamic_lib.h"

//Выделение памяти
int ** dynamic_array(size_t height){
	int **a;
	a = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < height; i++) {
		a[i] = (int*)malloc(height * sizeof(int));
	}
	return a;
}

//Выделение памяти
int *dynamic_array2(size_t height){
	int *b;
	b = (int*)malloc(height * sizeof(int));
	return b;
}

//Освобождение памяти от динамического массива
void dynamic_array_free1(int *b, size_t height) {
	free(b);
}
//Освобождение памяти от динамического массива
void dynamic_array_free(int **a, size_t height) {
	for (int i = 0; i < height; i++) {
		free(a[i]);
	}
	free(a);
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <new> 
#include <stack>
#include <time.h>
#include <queue>

#include "dynamic_lib.h"
#include "labaTZ.h"
#include "record.h"

void BFSD(int start, int* dist, int** a, int n) {
	queue<int> Steck;
	Steck.push(start);
	dist[start] = 0;
	printf("\nResult:\n");
	printf("v%d : ", start + 1);

	int v;
	while (!Steck.empty()) {
		v = Steck.front();
		Steck.pop();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (dist[i] == -1)) {
				Steck.push(i);
				dist[i] = dist[v] + 1;
				printf("v%d(%d) ", i + 1 , dist[i]);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		printf("v%d = %d\n", i + 1, dist[i]);
	}
	*/
}

void BFSDList(int start, int *dist, List *a, int n) {
	queue<int> Steck;
	Steck.push(start);
	dist[start] = 0;
	printf("\nResult:\n");
	printf("v%d : ", start + 1);

	int v;
	while (!Steck.empty()) {
		v = Steck.front();
		Steck.pop();
		for (int i = 0; i < a[v].GetSize(); i++) {
			if (dist[a[v][i]] == -1) {
				Steck.push(a[v][i]);
				dist[a[v][i]] = dist[v] + 1;
				printf("v%d(%d) ", a[v][i] + 1 , dist[a[v][i]]);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		printf("v%d = %d\n", i + 1, dist[i]);
	}
	*/
}

void DFSD(int start, int* dist, int** a, int n) {
	stack<int> Steck;
	Steck.push(start);
	dist[start] = 0;
	printf("\nResult:\n");

	int v;
	while (!Steck.empty()) {
		v = Steck.top();
		Steck.pop();
		printf("v%d(%d) ", v + 1, dist[v]);
		for (int i = n - 1; i > -1; i--) {
			if (a[v][i] && (dist[i]) == -1) {
				Steck.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		printf("v%d = %d\n", i + 1, dist[i]);
	}
	*/
}

void DFSDList(int start, int* dist, List* a, int n) {
	stack<int> Steck;
	Steck.push(start);
	dist[start] = 0;
	printf("\nResult:\n");

	int v;
	while (!Steck.empty()) {
		v = Steck.top();
		Steck.pop();
		printf("v%d(%d) ", v + 1, dist[v]);
		for (int i = a[v].GetSize() - 1; i > -1; i--) {
			if (dist[a[v][i]] == -1) {
				Steck.push(a[v][i]);
				dist[a[v][i]] = dist[v] + 1;

			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		printf("v%d = %d\n", i + 1, dist[i]);
	}
	*/
}

void BFSD_norec(int start, int* dist, int** a, int n) {
	queue<int> Steck;
	Steck.push(start);
	dist[start] = 0;

	int v;
	while (!Steck.empty()) {
		v = Steck.front();
		Steck.pop();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (dist[i] == -1)) {
				Steck.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}

void DFSD_norec(int start, int* dist, int** a, int n) {
	stack<int> Steck;
	Steck.push(start);
	dist[start] = 0;

	int v;
	while (!Steck.empty()) {
		v = Steck.top();
		Steck.pop();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (dist[i]) == -1) {
				Steck.push(i);
				dist[i] = dist[v] + 1;
			}
		}
	}
}

void zad1(){
	setlocale(LC_ALL, "Rus");

	int n;
	
	printf("Реализация поиска растояний в матрице смежности queue\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	int **a = dynamic_array(n); //матрица смежности
	int *vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	//Ввод
	for(int i = 0; i < n; i++){
		for(int j = i; j < n ; j++){
			a[i][j] = rand()%2;
			a[j][i] = a[i][j];
		}
	}
	//Обнуление диагонали
	for(int i = 0; i < n; i++){
		a[i][i] = 0;
	}

	//Одномерные массивы
	for(int i = 0; i < n; i++){
		vis[i] = -1;
	}
	
	//Вывод
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[j] = -1;
		}
		BFSD(i, vis, a, n);
	}

	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}

void zad2() {
	setlocale(LC_ALL, "Rus");

	int n;

	printf("\n\nРеализация поиска растояний в списке смежности queue\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	List *relist = new List[n];

	int **a = dynamic_array(n); //матрица смежности
	int *vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	//Ввод
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//Обнуление диагонали
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
		vis[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				if (relist[i].GetSize() == 0) {
					relist[i].push_front(j);
					printf(" v%d", j + 1);
				}
				else {
					relist[i].push_back(j);
					printf(" v%d", j + 1);
				}
			}
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[j] = -1;
		}
		BFSDList(i, vis, relist, n);
	}

	delete[] relist;
	_getch();
}

void zad3() {
	setlocale(LC_ALL, "Rus");

	int n;
	clock_t start, end;

	printf("\n\nРеализация поиска растояний в матрице смежности stack\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	int **a = dynamic_array(n); //матрица смежности
	int *vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	//Ввод
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//Обнуление диагонали
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	//Одномерные массивы
	for (int i = 0; i < n; i++) {
		vis[i] = -1;
	}

	//Вывод
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[j] = -1;
		}
		DFSD(i, vis, a, n);
	}
	
	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}

void zad4() {
	setlocale(LC_ALL, "Rus");

	int n;

	printf("\n\nРеализация поиска растояний в списке смежности stack\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	List* relist = new List[n];

	int** a = dynamic_array(n); //матрица смежности
	int* vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	//Ввод
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//Обнуление диагонали
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
		vis[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		printf("V%d:", i + 1);
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				if (relist[i].GetSize() == 0) {
					relist[i].push_front(j);
					printf(" v%d", j + 1);
				}
				else {
					relist[i].push_back(j);
					printf(" v%d", j + 1);
				}
			}
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[j] = -1;
		}
		DFSDList(i, vis, relist, n);
	}

	delete[] relist;
	_getch();
}

void zvezdochki() {
	setlocale(LC_ALL, "Rus");

	int n;
	clock_t start, end;

	printf("\n\nСравнение времени поиска растояний в матрице смежности BFSD и DFSD\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	int **a = dynamic_array(n); //матрица смежности
	int *vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	//Ввод
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//Обнуление диагонали
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	//Одномерные массивы
	for (int i = 0; i < n; i++) {
		vis[i] = -1;
	}

	printf("\nResult BFSD: ");

	start = clock();

	BFSD_norec(0 , vis, a, n);

	end = clock();
	printf("\nUse %.2f msecond.\n", difftime(end, start));


	for (int i = 0; i < n; i++) {
		vis[i] = -1;
	}

	printf("\nResult DFSD: ");
	start = clock();

	DFSD_norec(0, vis, a, n);

	end = clock();
	printf("\nUse %.2f msecond.\n", difftime(end, start));

	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}
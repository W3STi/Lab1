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
#include <iostream>

#include "dynamic_lib.h"
#include "labaTZ.h"
#include "record.h"

using namespace std;

void BFSD(int start, int* dist, int** a, int n) {
	queue<int> Steck;
	Steck.push(start);
	dist[start] = 0;


	int v;
	while (!Steck.empty()) {
		v = Steck.front();
		Steck.pop();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (dist[i] > (dist[v] + a[v][i]))) {
				Steck.push(i);
				dist[i] = dist[v] + a[v][i];
			}
		}
	}
}

void DFSD(int start, int* dist,vector<vector<int>> a,vector<int> wes, int n, int fantom_n) {
	queue<int> Steck;
	Steck.push(start);
	dist[start] = 0;

	int v;
	while (!Steck.empty()) {
		v = Steck.front();
		Steck.pop();
		for (int i = 0; i < fantom_n; i++) {
			if (a[v][i]) {
				for (int j = 0; j < n; j++) {
					if (a[j][i] && (dist[j] > (dist[v] + wes[i]))) {
						Steck.push(j);
						dist[j] = dist[v] + wes[i];
					}
				}
			}
			/*
			if (a[v][i] && (dist[i] > (dist[v] + a[v][i]))) {
				Steck.push(i);
				dist[i] = dist[v] + a[v][i];
			}
			*/
		}
	}
}

void zad1() {
	setlocale(LC_ALL, "Rus");

	int n;

	printf("Реализация в матрице смежности\n");

	printf("Введите размер матрицы - ");
	scanf("%d", &n);

	int** a = dynamic_array(n); //матрица смежности
	int* vis = dynamic_array2(n); //проверка на прохождение

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (rand() % 2) {
				a[i][j] = 1 + rand() % 9;
				a[j][i] = a[i][j];
			}
			else {
				a[i][j] = 0;
				a[j][i] = a[i][j];
			}
		}
	}

	//Обнуление диагонали
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	//Одномерные массивы
	for (int i = 0; i < n; i++) {
		vis[i] = 10000;
	}

	//Вывод
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	cout << endl;
	int radius = 10000;
	int diametr = -1;
	vector<int> max;
	for (int i = 0; i < n; i++) {
		BFSD(i, vis, a, n);
		printf("v%d : ", i + 1);
		max.push_back(-1);
		for (int j = 0; j < n; j++) {
			if (vis[j] != 0 && vis[j] != 10000) {
				printf("v%d(%d) ", j + 1, vis[j]);
				if (max[i] < vis[j]) {
					max[i] = vis[j];
				}
			}
			vis[j] = 10000;
		}
		cout << endl;
	}


	vector<int> centr;
	vector<int> peref;
	for (int j = 0; j < n; j++) {
		if (radius > max[j]) {
			centr.clear();
			centr.push_back(j);
			radius = max[j];
		}
		else {
			if (radius == max[j]) {
				centr.push_back(j);
			}
		}
		if (diametr < max[j]) {
			peref.clear();
			peref.push_back(j);
			diametr = max[j];
		}
		else {
			if (diametr == max[j]) {
				peref.push_back(j);
			}
		} 
	}

	cout << endl;
	cout << "Радиус: " << radius << endl;
	cout << "Диаметр: " << diametr << endl;
	cout << endl;

	cout << "Переферийные вершины(diametr): ";
	for (int i = 0; i < peref.size(); i++) {
		cout << "v" << peref[i] + 1 << " ";
	}
	cout << endl;

	cout << "Центральные вершины(radius): ";
	for (int i = 0; i < centr.size(); i++) {
		cout << "v" << centr[i] + 1 << " ";
	}
	cout << endl;

	cout << endl;

	int counter;
	for (int i = 0; i < n; i++) {
		counter = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				counter++;
			}
		}
		if (counter == 0) {
			cout << "V" << i + 1 << " - изолированная" << endl;
		}
		else {
			if (counter == 1) {
				cout << "V" << i + 1 << " - концевая" << endl;
			}
			else {
				if (counter == (n - 1)) {
					cout << "V" << i + 1 << " - доминирующая" << endl;
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////

	cout << endl;
	cout << endl;
	cout << endl;

	printf("Реализация в матрице инцидентности\n");

	vector<vector<int>> incen;
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		incen.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j) {
						incen[k].push_back(1);
					}
					else {
						incen[k].push_back(0);
					}
				}
				temp.push_back(a[i][j]);
			}
		}
	}
	int fantom_n = incen[0].size();

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < fantom_n; j++) {
			cout << incen[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < fantom_n; i++) {
		cout << temp[i] << " ";
	}
	cout << endl;

	cout << endl;
	radius = 10000;
	diametr = -1;
	max.clear();
	for (int i = 0; i < n; i++) {
		DFSD(i, vis, incen, temp, n, fantom_n);
		printf("v%d : ", i + 1);
		max.push_back(-1);
		for (int j = 0; j < n; j++) {
			if (vis[j] != 0 && vis[j] != 10000) {
				printf("v%d(%d) ", j + 1, vis[j]);
				if (max[i] < vis[j]) {
					max[i] = vis[j];
				}
			}
			vis[j] = 10000;
		}
		cout << endl;
	}

	centr.clear();
	peref.clear();
	for (int j = 0; j < n; j++) {
		if (radius > max[j] && max[j] != -1) {
			centr.clear();
			centr.push_back(j);
			radius = max[j];
		}
		else {
			if (radius == max[j]) {
				centr.push_back(j);
			}
		}
		if (diametr < max[j]) {
			peref.clear();
			peref.push_back(j);
			diametr = max[j];
		}
		else {
			if (diametr == max[j]) {
				peref.push_back(j);
			}
		}
	}

	cout << endl;
	cout << "Переферийные вершины(diametr): ";
	for (int i = 0; i < peref.size(); i++) {
		cout << "v" << peref[i] + 1 << " ";
	}
	cout << endl;

	cout << "Центральные вершины(radius): ";
	for (int i = 0; i < centr.size(); i++) {
		cout << "v" << centr[i] + 1 << " ";
	}
	cout << endl;

	cout << endl;
	cout << "Радиус: " << radius << endl;
	cout << "Диаметр: " << diametr << endl;

	cout << endl;

	for (int i = 0; i < n; i++) {
		counter = 0;
		for (int j = 0; j < fantom_n; j++) {
			if (incen[i][j]) {
				counter++;
			}
		}
		if (counter == 0) {
			cout << "V" << i + 1 << " - изолированная" << endl;
		}
		else {
			if (counter == 2) {
				cout << "V" << i + 1 << " - концевая" << endl;
			}
			else {
				if (counter == (n - 1)*2) {
					cout << "V" << i + 1 << " - доминирующая" << endl;
				}
			}
		}
	}

	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}


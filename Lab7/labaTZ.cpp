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
#include "iostream"
#include "sstream"

#include "dynamic_lib.h"
#include "labaTZ.h"
#include "record.h"

using namespace std;

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
			if (a[v][i] && (dist[i] > (dist[v] + a[v][i]))) {
				Steck.push(i);
				dist[i] = dist[v] + a[v][i];
				printf("v%d(%d) ", i + 1 , dist[i]);
			}
		}
	}
}

void Spirit(int argc, char* argv[]){
	setlocale(LC_ALL, "Rus");

	bool orflag(false);
	bool susflag(false);

	int N = 6;
	if (argc > 1)
	{
		for (int i = 0; i < argc; ++i)
		{
			if (strcmp(argv[i], "-or") == 0) {
				orflag = true;
			}
			if (strcmp(argv[i], "-neor") == 0) {
				orflag = false;
			}
			if (strcmp(argv[i], "-sus") == 0) {
				susflag = true;
			}
			if (strcmp(argv[i], "-nesus") == 0) {
				susflag = false;
			}
			if (strcmp(argv[i], "-ver") == 0) {
				stringstream convert(argv[i + 1]); // ������� ���������� stringstream � ������ convert, ������������� � ��������� argv[1]

				int myint;
				if (!(convert >> myint)) // ��������� �����������
					myint = 6;
				N = myint;
			}
		}
	}
	else
	{
		cout << "��������� ����� �������������� �� ���������." << endl;
	}


	if (orflag) {
		cout << "��������������� ";
	}else{
		cout << "����������������� ";
	}

	if (susflag) {
		cout << "���������� ���� ";
	}else{
		cout << "�� ���������� ���� ";
	}

	cout << "(������: " <<  N << ")." << endl;

	zad(orflag, susflag, N);

	_getch();
}

void zad(bool orflag, bool susflag, int n){
	setlocale(LC_ALL, "Rus");

	int **a = dynamic_array(n); //������� ���������
	int *vis = dynamic_array2(n); //�������� �� �����������

	if (orflag) {       // ���������������
		if (susflag) {  // ����������
			srand(time(NULL));
			//����
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (rand() % 2) {
						a[i][j] = 1 + rand() % 9;
					}
					else {
						a[i][j] = 0;
					}
				}
			}
		}
		else {          // �� ����������
			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = rand() % 2;
				}
			}
		}
	}
	else {              // �����������������
		if (susflag) {  // ����������
			srand(time(NULL));
			//���������� �����������������
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
		}
		else {          // �� ����������
			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					a[i][j] = rand() % 2;
					a[j][i] = a[i][j];
				}
			}
		}
	}
	
	

	//��������� ���������
	for(int i = 0; i < n; i++){
		a[i][i] = 0;
	}

	//���������� �������
	for(int i = 0; i < n; i++){
		vis[i] = 100000;
	}
	
	//�����
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[j] = 100000;
		}
		BFSD(i, vis, a, n);
	}

	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}
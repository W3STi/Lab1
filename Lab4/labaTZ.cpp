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

#include "dynamic_lib.h"
#include "labaTZ.h"
#include "record.h"

void dfs(int v, int *vis, int **a, int n){
	vis[v] = 1;
	printf("%d ",v + 1);
	for(int i = 0; i < n; i++){
		if((a[v][i] == 1) && (vis[i] == 0)){
			dfs(i, vis, a, n);
		}
	}
}

void dfslist(int v, int *vis, List *a, int n) {
	vis[v] = 1;
	printf("%d ", v + 1);
	for (int i = 0; i < a[v].GetSize(); i++) {
		if (!vis[a[v][i]]) {
			dfslist(a[v][i], vis, a, n);
		}
	}
}

void dfs_norec(int start, int *vis, int **a, int n) {
	List Stack;
	vis[start] = 1;
	printf("%d ", start + 1);
	Stack.push_front(start);

	int v;
	while (Stack.GetSize()){
		v = Stack[0];
		Stack.pop_front();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (!vis[i])) {
				printf("%d ", i + 1);
				Stack.push_front(i);
				vis[i] = 1;
			}
		}
	}
}

void dfs_norec_no(int start, int *vis, int **a, int n) {
	List Stack;
	car temp;
	vis[start] = 1;
	Stack.push_front(start);

	int v;
	while (Stack.GetSize()) {
		v = Stack[0];
		Stack.pop_front();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (!vis[i])) {
				Stack.push_front(i);
				vis[i] = 1;
			}
		}
	}
}

void dfs_norec_no_lib(int start, int *vis, int **a, int n) {
	stack<int> Steck;
	car temp;
	vis[start] = 1;
	Steck.push(start);

	int v;
	while (!Steck.empty()) {
		v = Steck.top();
		Steck.pop();
		for (int i = 0; i < n; i++) {
			if (a[v][i] && (!vis[i])) {
				Steck.push(i);
				vis[i] = 1;
			}
		}
	}
}

void zad1(){
	setlocale(LC_ALL, "Rus");

	int n, v;
	
	printf("���������� ������ � �������� ���������\n");

	printf("������� ������ ������� - ");
	scanf("%d", &n);

	printf("������� ����� ������� ��� ����������� - ");
	scanf("%d", &v);

	int **a = dynamic_array(n); //������� ���������
	int *vis = dynamic_array2(n); //�������� �� �����������

	srand(time(NULL));
	//����
	for(int i = 0; i < n; i++){
		for(int j = i; j < n ; j++){
			a[i][j] = rand()%2;
			a[j][i] = a[i][j];
		}
	}
	//��������� ���������
	for(int i = 0; i < n; i++){
		a[i][i] = 0;
	}

	//���������� �������
	for(int i = 0; i < n; i++){
		vis[i] = 0;
	}
	
	//�����
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nResult: ");
	v--;
	dfs(v, vis, a, n);


	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}

void zad2() {
	setlocale(LC_ALL, "Rus");

	int n, v;

	printf("\n\n���������� ������ �� ������� ���������\n");

	printf("������� ������ ������� - ");
	scanf("%d", &n);

	printf("������� ����� ������� ��� ����������� - ");
	scanf("%d", &v);

	List *relist = new List[n];

	int **a = dynamic_array(n); //������� ���������
	int *vis = dynamic_array2(n); //�������� �� �����������

	srand(time(NULL));
	//����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//��������� ���������
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
		vis[i] = 0;
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

	printf("\nResult: ");
	v--;
	dfslist(v, vis, relist, n);

	delete[] relist;
	_getch();
}

void zad3() {
	setlocale(LC_ALL, "Rus");

	int n, v;
	clock_t start, end;

	printf("\n\n���������� ������ � �������� ��������� ��� ��������\n");

	printf("������� ������ ������� - ");
	scanf("%d", &n);

	printf("������� ����� ������� ��� ����������� - ");
	scanf("%d", &v);

	int **a = dynamic_array(n); //������� ���������
	int *vis = dynamic_array2(n); //�������� �� �����������

	srand(time(NULL));
	//����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//��������� ���������
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	//���������� �������
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		//ok[i] = 0;
	}

	//�����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\nResult: ");
	v--;
	dfs_norec(v, vis, a, n);
	
	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}

void zvezdochki() {
	setlocale(LC_ALL, "Rus");

	int n, v;
	clock_t start, end;

	printf("\n\n��������� ������� ������ ������� ��������� ��� ��������\n");

	printf("������� ������ ������� - ");
	scanf("%d", &n);

	printf("������� ����� ������� ��� ����������� - ");
	scanf("%d", &v);

	int **a = dynamic_array(n); //������� ���������
	int *vis = dynamic_array2(n); //�������� �� �����������

	srand(time(NULL));
	//����
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	//��������� ���������
	for (int i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	//���������� �������
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
		//ok[i] = 0;
	}

	printf("\nResult: ");
	v--;

	start = clock();
	dfs_norec_no(v, vis, a, n);
	end = clock();
	printf("\nUse %.2f msecond.\n", difftime(end, start));

	printf("\nResult_Lib: ");
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	start = clock();
	dfs_norec_no_lib(v, vis, a, n);
	end = clock();
	printf("\nUse %.2f msecond.\n", difftime(end, start));

	dynamic_array_free(a, n);
	dynamic_array_free1(vis, n);
	_getch();
}
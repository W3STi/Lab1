#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>

const int wall = 0, pass = 1, digger = 2, coin = 3;
void menu();

void rules();//������� ������
void graphicsofmenu();//������� ����
void dynamic_array_print(int** maze, int height, int width, bool stopwatch);//������� ������ ���� ������� ���������
void dynamic_array_bot(int** maze, int height, int width, bool stopwatch);
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<windows.h>
#include<iostream>

#define STRLEN_(x) #x
#define STRLEN(x) STRLEN_(x)
#define LEN 15
#define KEY_UP 72 //����������� ������� "�����"
#define KEY_DOWN 80 //����������� ������� "����"
#define KEY_LEFT 75 //����������� ������� "�����"
#define KEY_RIGHT 77 //����������� ������� "������"
#define KEY_SPACE 32 //����������� ������� "������"
#define KEY_ESC 27 //����������� ������� "escape"
#define KEY_ENTER 13 //����������� ������� "enter"
//���������������� ����
void menu();
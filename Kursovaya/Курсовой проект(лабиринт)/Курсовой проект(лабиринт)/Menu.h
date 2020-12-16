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
#define KEY_UP 72 //определение клавиши "вверх"
#define KEY_DOWN 80 //определение клавиши "вниз"
#define KEY_LEFT 75 //определение клавиши "влево"
#define KEY_RIGHT 77 //определение клавиши "вправо"
#define KEY_SPACE 32 //определение клавиши "пробел"
#define KEY_ESC 27 //определение клавиши "escape"
#define KEY_ENTER 13 //определение клавиши "enter"
//Пользовательское меню
void menu();
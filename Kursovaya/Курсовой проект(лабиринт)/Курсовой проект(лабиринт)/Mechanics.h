#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<iostream>
#include<memory.h>
#include<time.h>
#include<malloc.h>
#include<conio.h>
#include<vector>

using namespace std;

#define KEY_SPACE 32 //определение клавиши "пробел"

int ** dynamic_array(size_t height, size_t width);
void dynamic_array_free(int **maze, size_t height);
bool deadend(int x, int y, int** maze, int height, int width);
void go(int** maze, int height, int width, bool stopwatch, bool check_bot);
void go2(int** maze, int height, int width, double &difP);
void mazegame(int height, int width, bool stopwatch, bool check_bot, int lvl);
void Way_coord(int** maze, int *py, int *px, int *xc1, int *yc1, int *xc2, int *yc2, int lvl);
int Find_way(int** maze, int y, int x);
void runbot(int** maze, int height, int lvl, double &difB);
void mainmech(int** maze, int height, int lvl);
void grph_bot1(int *xc1, int *yc1, int *xc2, int *yc2);
void grph_bot2(int *xc1, int *yc1, int *xc2, int *yc2, int lvl);

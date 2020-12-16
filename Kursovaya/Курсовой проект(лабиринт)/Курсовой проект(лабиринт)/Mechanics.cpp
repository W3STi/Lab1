#include "Mechanics.h"
#include "Graphics.h"
#include "Menu.h"
#include <thread>

using namespace std;

//Выделение памяти под динамический массив
int ** dynamic_array(size_t height, size_t width) {
	int **maze;
	maze = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < width; ++i) {
		maze[i] = (int*)malloc(width * sizeof(int));
	}
	return maze;
}
//Освобождение памяти от динамического массива
void dynamic_array_free(int **maze, size_t height) {
	for (int i = 0; i < height; i++) {
		free(maze[i]);
	}
	free(maze);
	maze = NULL;
}
//Функция для тупика
bool deadend(int x, int y, int** maze, int height, int width) {
	int check = 0;
	if (x != 1) {
		if (maze[y][x - 2] == pass)
			check += 1;
	}
	else check += 1;
	if (y != 1) {
		if (maze[y - 2][x] == pass)
			check += 1;
	}
	else check += 1;
	if (x != width - 2) {
		if (maze[y][x + 2] == pass)
			check += 1;
	}
	else check += 1;
	if (y != height - 2) {
		if (maze[y + 2][x] == pass)
			check += 1;
	}
	else check += 1;
	if (check == 4)
		return 1;
	else
		return 0;
}
//Графика движения бота
void grph_bot1(int *xc1, int *yc1, int *xc2, int *yc2) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT r;
	r.left = *xc1;
	r.top = *yc1;
	r.right = *xc2;
	r.bottom = *yc2;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	ReleaseDC(hwnd, dc);
}
//Графика движения бота
void grph_bot2(int *xc1, int *yc1, int *xc2, int *yc2, int lvl) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	brush = CreateSolidBrush(RGB(5, 2, 189));
	SelectObject(dc, brush); //Выбираем кисть
	Rectangle(dc, *xc1, *yc1, *xc2, *yc2); //Нарисовали прямоугольник, закрашенный неким стилем
	DeleteObject(brush); //Очищаем память от созданной кисти
	ReleaseDC(hwnd, dc);
	if (lvl == 1) {
		Sleep(lvl * 250);
	}
	else if (lvl == 2) {
		Sleep(lvl * 110);
	}
	else if (lvl == 3) {
		Sleep(lvl * 60);
	}
}
//Создание копии динамического массива
int** copymaze(int** sourseMatrix, int rows, int cols)
{
	int** cmaze = new int*[rows];
	for (int i = 0; i < rows; i++)
		cmaze[i] = new int[cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cmaze[i][j] = sourseMatrix[i][j];
		}
	}
	return cmaze;
}
//Функция для просмотра количества путей
int Find_way(int** maze, int y, int x) {
	int counter = 0;
	if (maze[y + 1][x] == 1) counter++;//Вниз
	if (maze[y - 1][x] == 1) counter++;//Вверх
	if (maze[y][x + 1] == 1) counter++;//Вправо
	if (maze[y][x - 1] == 1) counter++;//Влево
	return counter;
}
//Фукнция для просмотра типа пути
void Way_coord(int** maze, int *py, int *px, int *xc1, int *yc1, int *xc2, int *yc2, int lvl) {
	if (maze[*(py) + 1][*px] == 1) {
		maze[*py][*px] = 4;
		maze[*(py) + 1][*px] = 4;
		maze[*(py) + 2][*px] = 4;
		grph_bot1(xc1, yc1, xc2, yc2);
		*(yc1) += 20;
		*(yc2) += 20;
		*(py)+= 2;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		grph_bot1(xc1, yc1, xc2, yc2);
		*(yc1) += 20;
		*(yc2) += 20;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		return;
	}
	if (maze[*py][*(px)+1] == 1) {
		maze[*py][*px] = 4;
		maze[*py][*(px)+1] = 4;
		maze[*py][*(px)+2] = 4;
		grph_bot1(xc1, yc1, xc2, yc2);
		*(xc1) += 20;
		*(xc2) += 20;
		*(px) += 2;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		grph_bot1(xc1, yc1, xc2, yc2);
		*(xc1) += 20;
		*(xc2) += 20;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		return;
	}
	if (maze[*(py) - 1][*px] == 1) {
		maze[*py][*px] = 4;
		maze[*(py) - 1][*px] = 4;
		maze[*(py) - 2][*px] = 4;
		grph_bot1(xc1, yc1, xc2, yc2);
		*(yc1) -= 20;
		*(yc2) -= 20;
		*(py) -= 2;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		grph_bot1(xc1, yc1, xc2, yc2);
		*(yc1) -= 20;
		*(yc2) -= 20;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		return;
	}
	if (maze[*py][*(px) - 1] == 1) {
		maze[*py][*px] = 4;
		maze[*py][*(px) - 1] = 4;
		maze[*py][*(px) - 2] = 4;
		grph_bot1(xc1, yc1, xc2, yc2);
		*(xc1) -= 20;
		*(xc2) -= 20;
		*(px) -= 2;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		grph_bot1(xc1, yc1, xc2, yc2);
		*(xc1) -= 20;
		*(xc2) -= 20;
		grph_bot2(xc1, yc1, xc2, yc2, lvl);
		return;
	}
}
//Логика бота
void runbot(int** maze, int height, int lvl, double &difB) {
	int y = 1, x = 1, ctr, yc1 = 50, xc1 = 900, yc2 = 70, xc2 = 920;
	int y1 = 50, y2 = 70, x1 = 380, x2 = 400;
	time_t t1b, t2b;
	vector<int> WayBot;
	maze[1][0] = 0;
	t1b = time(NULL);
	ctr = Find_way(maze, y, x);
	if (ctr > 1) {
		WayBot.push_back(y);
		WayBot.push_back(x);
	}
	while (TRUE) { 
		if (y == height - 2 && x == height - 2) break;
		//бот всегда будет возвращаться в точку отправки от вектора!!!
		//Вернуться назад, до точки разъединения
		ctr = Find_way(maze, y, x);
		while (ctr == 0) {
			while (TRUE) {
				if (y == WayBot[WayBot.size() - 2] && x == WayBot[WayBot.size() - 1]) {
					break;
				}
				//Вниз
				if (maze[y + 1][x] == 4) {
					maze[y][x] = 5;
					maze[y + 1][x] = 5;
					maze[y + 2][x] = 5;
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					yc1 += 20;
					yc2 += 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					yc1 += 20;
					yc2 += 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					y += 2;
				}
				//Вправо
				else if (maze[y][x + 1] == 4) {
					maze[y][x] = 5;
					maze[y][x + 1] = 5;
					maze[y][x + 2] = 5;
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					xc1 += 20;
					xc2 += 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					xc1 += 20;
					xc2 += 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					x += 2;
				}
				//Вверх
				else if (maze[y - 1][x] == 4) {
					maze[y][x] = 5;
					maze[y - 1][x] = 5;
					maze[y - 2][x] = 5;
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					yc1 -= 20;
					yc2 -= 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					yc1 -= 20;
					yc2 -= 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					y -= 2;
				}
				//Влево
				else if (maze[y][x - 1] == 4) {
					maze[y][x] = 5;
					maze[y][x - 1] = 5;
					maze[y][x - 2] = 5;
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					xc1 -= 20;
					xc2 -= 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					grph_bot1(&xc1, &yc1, &xc2, &yc2);
					xc1 -= 20;
					xc2 -= 20;
					grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
					x -= 2;
				}
			}
			ctr = Find_way(maze, y, x);
			if (ctr == 0) {
				WayBot.pop_back();
				WayBot.pop_back();
			}
		}
			if (ctr == 1) {
				Way_coord(maze, &y, &x, &xc1, &yc1, &xc2, &yc2, lvl);
			}
			else if (ctr > 1) {
				//Записать одно из направлений в вектор и пойти в него
				WayBot.push_back(y);
				WayBot.push_back(x);
				Way_coord(maze, &y, &x, &xc1, &yc1, &xc2, &yc2, lvl);
			}
		}
	grph_bot1(&xc1, &yc1, &xc2, &yc2);
	xc1 += 20;
	xc2 += 20;
	grph_bot2(&xc1, &yc1, &xc2, &yc2, lvl);
	t2b = time(NULL);
	difB = difftime(t2b, t1b);
		dynamic_array_free(maze, height);
	}
//функция для движения пользователя
void go2(int** maze, int height, int width, double &difP) {
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	time_t t1, t2;
	int xG = 0, yG = 1;
	int x1g = 380, x2g = 400, y1g = 50, y2g = 70;
	t1 = time(NULL);
	while (yG != width - 2) {
		while (xG != height - 1) {
			if (_kbhit()) //если нажата клавиша
			{
				switch (_getch()) {
				case 'a'://влево
					if (maze[yG][xG - 1] != 0 && maze[1][0] != digger) {
						maze[yG][xG] = pass;
						maze[yG][xG - 1] = digger;
						xG -= 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g -= 20; x2g -= 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 'd'://вправо
					if (maze[yG][xG + 1] != 0) {
						maze[yG][xG] = pass;
						maze[yG][xG + 1] = digger;
						xG += 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g += 20; x2g += 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 's'://вниз
					if (maze[yG + 1][xG] != 0) {
						maze[yG][xG] = pass;
						maze[yG + 1][xG] = digger;
						yG += 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g += 20; y2g += 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 'w'://вверх
					if (maze[yG - 1][xG] != 0) {
						maze[yG][xG] = pass;
						maze[yG - 1][xG] = digger;
						yG -= 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g -= 20; y2g -= 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				}
			}
		}
	}
	t2 = time(NULL);
	difP = difftime(t2, t1);
	dynamic_array_free(maze, height);
	ReleaseDC(hwnd, dc);
}
//Функция для движения объекта по лабиринту
void go(int** maze, int height, int width, bool stopwatch, bool check_bot) {
	int xG = 0, yG = 1, amount = 0;
	time_t t1, t2;
	double differ;
	FILE *file;
	int x1g = 430, x2g = 450, y1g = 50, y2g = 70;
	if (check_bot) {
		x1g = 380, x2g = 400;
	}
	int xcoin1 = 130, ycoin1 = 360, xcoin2 = 150, ycoin2 = 380;
	t1 = time(NULL);
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	while (yG != width - 2) {
		while (xG != height - 1) {
			if (_kbhit()) //если нажата клавиша
			{
				switch (_getch()) {
				case 'a'://влево
					if (maze[yG][xG - 1] != 0 && maze[1][0] != digger) {
						if (maze[yG][xG - 1] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
							SelectObject(dc, brush); //Выбираем кисть
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //Очищаем память от созданной кисти
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG][xG - 1] = digger;
						xG -= 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g -= 20; x2g -= 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 'd'://вправо
					if (maze[yG][xG + 1] != 0) {
						if (maze[yG][xG + 1] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
							SelectObject(dc, brush); //Выбираем кисть
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //Очищаем память от созданной кисти
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG][xG + 1] = digger;
						xG += 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g += 20; x2g += 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 's'://вниз
					if (maze[yG + 1][xG] != 0) {
						if (maze[yG + 1][xG] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
							SelectObject(dc, brush); //Выбираем кисть
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //Очищаем память от созданной кисти
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG + 1][xG] = digger;
						yG += 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g += 20; y2g += 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case 'w'://вверх
					if (maze[yG - 1][xG] != 0) {
						if (maze[yG - 1][xG] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // Выбранный элемент
							SelectObject(dc, brush); //Выбираем кисть
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //Очищаем память от созданной кисти
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG - 1][xG] = digger;
						yG -= 1;
						//Зарисовка поля
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g -= 20; y2g -= 20;
						//Объект
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //Выбираем кисть
						Rectangle(dc, x1g, y1g, x2g, y2g); //Нарисовали прямоугольник, закрашенный неким стилем
						DeleteObject(brush); //Очищаем память от созданной кисти
					}
					else break;
					break;
				case KEY_SPACE:
						file = fopen("Результаты.txt", "a");
						fprintf(file, "Лабиринт пройден не полностью\n");
						fprintf(file, "************************************\n");
						fclose(file);
						stopwatch = 0;
						dynamic_array_free(maze, height);
						system("cls");
						menu();
					break;
				}
			}
		}
	}
	static LOGFONT lf1;
	lf1.lfCharSet = DEFAULT_CHARSET;
	lf1.lfPitchAndFamily = DEFAULT_PITCH;
	lf1.lfHeight = 20;
	lf1.lfWidth = 10;
	lf1.lfItalic = 0;

	HFONT hFont1 = CreateFontIndirect(&lf1);
	SelectObject(dc, hFont1);
	SetTextColor(dc, RGB(0, 0, 0));
	SetBkColor(dc, RGB(59, 255, 251));
	TextOut(dc, 105, 90, L"Игра пройдена!", strlen("Игра пройдена!"));
	if (stopwatch == 1) {
		TextOut(dc, 80, 225, L"Таймер остановлен", strlen("Таймер остановлен"));
		t2 = time(NULL);
		differ = difftime(t2, t1);
		file = fopen("Результаты.txt", "a");
		fprintf(file, "Размеры лабиринта - %d x %d \n", height, width);
		fprintf(file, "Кол-во собранных монеток - %d\n", amount);
		fprintf(file, "Время прохождения - %.2f сек.\n", differ);
		fprintf(file, "************************************\n");
		fclose(file);
	}
	RECT r;
	r.left = 550;
	r.top = 300;
	r.right = 1065;
	r.bottom = 400;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(102, 102, 153)));
	TextOut(dc, 570, 340, L"Нажмите любую клавишу, чтобы вернуться", strlen("Нажмите любую клавишу, чтобы вернуться"));
	DeleteObject(hFont1); //выгрузим из памяти объект шрифта
	dynamic_array_free(maze, height);
	_getch();
	ReleaseDC(hwnd, dc);
	menu();
}
//Основная функция
void mazegame(int height, int width, bool stopwatch, bool check_bot, int lvl) {
	int x, y, random, count, coins = 0;
	int **maze = dynamic_array(width, height);
	for (int i = 0; i < height; i++) { // Массив заполняется землей-ноликами
		for (int j = 0; j < width; j++) {
			maze[i][j] = wall;
		}
	}
	x = 1; //Начальные координаты копателя
	y = 1;
	count = 0; //счетчик
	while (count < 1000) {
		maze[y][x] = pass; count++;
		while (pass) { // Бесконечный цикл, который прерывается только тупиком
			random = rand() % 4;
			switch (random) {
			case 0: if (y != 1) {
				if (maze[y - 2][x] == wall) { // Вверх
					maze[y - 1][x] = pass;
					maze[y - 2][x] = pass;
					y -= 2;
				}
			}
			case 1: if (y != height - 2) {
				if (maze[y + 2][x] == wall) { // Вниз
					maze[y + 1][x] = pass;
					maze[y + 2][x] = pass;
					y += 2;
				}
			}
			case 2: if (x != 1) {
				if (maze[y][x - 2] == wall) { // Влево
					maze[y][x - 1] = pass;
					maze[y][x - 2] = pass;
					x -= 2;
				}
			}
			case 3: if (x != width - 2) {
				if (maze[y][x + 2] == wall) { // Вправо
					maze[y][x + 1] = pass;
					maze[y][x + 2] = pass;
					x += 2;
				}
			}
			}
			if (deadend(x, y, maze, height, width)) //Проверка на тупик
				break;
		}
		if (deadend(x, y, maze, height, width)) { // Возвращаем копателя из тупика
			do {
				x = 2 * (rand() % ((width - 1) / 2)) + 1;
				y = 2 * (rand() % ((height - 1) / 2)) + 1;
			} while (maze[y][x] != pass);
		}
	}
	maze[1][0] = digger;
	maze[width - 2][height - 1] = pass;
	//Графика построенного лабиринта
	if (check_bot) {
		//Графика
		dynamic_array_bot(maze, height, width, stopwatch);
		//Потоки
		mainmech(maze, height, lvl);
		//Движение
		go(maze, height, width, stopwatch, 1);
	}
	else {
		while (coins != 3) {
			x = 2 * (rand() % ((width - 1) / 2)) + 1;
			y = 2 * (rand() % ((height - 1) / 2)) + 1;
			if (maze[y][x] == pass) {
				maze[y][x] = coin;
				coins++;
			}
		}
		dynamic_array_print(maze, height, width, stopwatch);
		//Движение
		go(maze, height, width, stopwatch, 0);
	}
}
//Функция для вызова потоков
void mainmech(int** maze, int height, int lvl) {
	double difP = 0, difB = 0;
	FILE *file;
	HWND hwnd = GetConsoleWindow(); //Берём ориентир на консольное окно (В нём будем рисовать)
	HDC dc = GetDC(hwnd); //Цепляемся к консольному окну
	RECT window = {}; //Переменная window будет использована для получения ширины и высоты окна
	HBRUSH brush; //Переменная brush - это кисть, она будет использоваться для закрашивания
	RECT r;
	r.left = 530;
	r.top = 300;
	r.right = 1065;
	r.bottom = 400;
	int **cmaze = copymaze(maze, height, height);
	std::thread th(go2, cmaze, height, height, std::ref(difP));
	std::thread th1(runbot, maze, height, lvl, std::ref(difB));
	th.join();
	th1.join();
	if (difB < difP) {
		FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(102, 102, 153)));
		TextOut(dc, 700, 340, L"Бот оказался сильнее...", strlen("Бот оказался сильнее..."));
	}
	else {
		FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(102, 102, 153)));
		TextOut(dc, 740, 340, L"Вы победили!", strlen("Вы победили!"));
	}
	file = fopen("Результаты.txt", "a");
	fprintf(file, "Размеры лабиринта - %d x %d \n", height, height);
	fprintf(file, "Время бота - %.2f сек.\n", difB);
	fprintf(file, "Время игрока - %.2f сек.\n", difP);
	fprintf(file, "************************************\n");
	fclose(file);
	ReleaseDC(hwnd, dc);
	_getch();
	menu();
}

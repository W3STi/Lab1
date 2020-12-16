#include "Mechanics.h"
#include "Graphics.h"
#include "Menu.h"
#include <thread>

using namespace std;

//��������� ������ ��� ������������ ������
int ** dynamic_array(size_t height, size_t width) {
	int **maze;
	maze = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < width; ++i) {
		maze[i] = (int*)malloc(width * sizeof(int));
	}
	return maze;
}
//������������ ������ �� ������������� �������
void dynamic_array_free(int **maze, size_t height) {
	for (int i = 0; i < height; i++) {
		free(maze[i]);
	}
	free(maze);
	maze = NULL;
}
//������� ��� ������
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
//������� �������� ����
void grph_bot1(int *xc1, int *yc1, int *xc2, int *yc2) {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT r;
	r.left = *xc1;
	r.top = *yc1;
	r.right = *xc2;
	r.bottom = *yc2;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
	ReleaseDC(hwnd, dc);
}
//������� �������� ����
void grph_bot2(int *xc1, int *yc1, int *xc2, int *yc2, int lvl) {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	brush = CreateSolidBrush(RGB(5, 2, 189));
	SelectObject(dc, brush); //�������� �����
	Rectangle(dc, *xc1, *yc1, *xc2, *yc2); //���������� �������������, ����������� ����� ������
	DeleteObject(brush); //������� ������ �� ��������� �����
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
//�������� ����� ������������� �������
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
//������� ��� ��������� ���������� �����
int Find_way(int** maze, int y, int x) {
	int counter = 0;
	if (maze[y + 1][x] == 1) counter++;//����
	if (maze[y - 1][x] == 1) counter++;//�����
	if (maze[y][x + 1] == 1) counter++;//������
	if (maze[y][x - 1] == 1) counter++;//�����
	return counter;
}
//������� ��� ��������� ���� ����
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
//������ ����
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
		//��� ������ ����� ������������ � ����� �������� �� �������!!!
		//��������� �����, �� ����� ������������
		ctr = Find_way(maze, y, x);
		while (ctr == 0) {
			while (TRUE) {
				if (y == WayBot[WayBot.size() - 2] && x == WayBot[WayBot.size() - 1]) {
					break;
				}
				//����
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
				//������
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
				//�����
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
				//�����
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
				//�������� ���� �� ����������� � ������ � ����� � ����
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
//������� ��� �������� ������������
void go2(int** maze, int height, int width, double &difP) {
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	time_t t1, t2;
	int xG = 0, yG = 1;
	int x1g = 380, x2g = 400, y1g = 50, y2g = 70;
	t1 = time(NULL);
	while (yG != width - 2) {
		while (xG != height - 1) {
			if (_kbhit()) //���� ������ �������
			{
				switch (_getch()) {
				case 'a'://�����
					if (maze[yG][xG - 1] != 0 && maze[1][0] != digger) {
						maze[yG][xG] = pass;
						maze[yG][xG - 1] = digger;
						xG -= 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g -= 20; x2g -= 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 'd'://������
					if (maze[yG][xG + 1] != 0) {
						maze[yG][xG] = pass;
						maze[yG][xG + 1] = digger;
						xG += 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g += 20; x2g += 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 's'://����
					if (maze[yG + 1][xG] != 0) {
						maze[yG][xG] = pass;
						maze[yG + 1][xG] = digger;
						yG += 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g += 20; y2g += 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 'w'://�����
					if (maze[yG - 1][xG] != 0) {
						maze[yG][xG] = pass;
						maze[yG - 1][xG] = digger;
						yG -= 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g -= 20; y2g -= 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
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
//������� ��� �������� ������� �� ���������
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
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	while (yG != width - 2) {
		while (xG != height - 1) {
			if (_kbhit()) //���� ������ �������
			{
				switch (_getch()) {
				case 'a'://�����
					if (maze[yG][xG - 1] != 0 && maze[1][0] != digger) {
						if (maze[yG][xG - 1] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
							SelectObject(dc, brush); //�������� �����
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //������� ������ �� ��������� �����
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG][xG - 1] = digger;
						xG -= 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g -= 20; x2g -= 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 'd'://������
					if (maze[yG][xG + 1] != 0) {
						if (maze[yG][xG + 1] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
							SelectObject(dc, brush); //�������� �����
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //������� ������ �� ��������� �����
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG][xG + 1] = digger;
						xG += 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						x1g += 20; x2g += 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 's'://����
					if (maze[yG + 1][xG] != 0) {
						if (maze[yG + 1][xG] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
							SelectObject(dc, brush); //�������� �����
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //������� ������ �� ��������� �����
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG + 1][xG] = digger;
						yG += 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g += 20; y2g += 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case 'w'://�����
					if (maze[yG - 1][xG] != 0) {
						if (maze[yG - 1][xG] == coin) {
							brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
							SelectObject(dc, brush); //�������� �����
							Ellipse(dc, xcoin1, ycoin1, xcoin2, ycoin2);
							DeleteObject(brush); //������� ������ �� ��������� �����
							xcoin1 += 40;
							xcoin2 += 40;
							amount++;
						}
						maze[yG][xG] = pass;
						maze[yG - 1][xG] = digger;
						yG -= 1;
						//��������� ����
						RECT r;
						r.left = x1g;
						r.top = y1g;
						r.right = x2g;
						r.bottom = y2g;
						FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(255, 189, 187)));
						y1g -= 20; y2g -= 20;
						//������
						brush = CreateSolidBrush(RGB(255, 0, 0));
						SelectObject(dc, brush); //�������� �����
						Rectangle(dc, x1g, y1g, x2g, y2g); //���������� �������������, ����������� ����� ������
						DeleteObject(brush); //������� ������ �� ��������� �����
					}
					else break;
					break;
				case KEY_SPACE:
						file = fopen("����������.txt", "a");
						fprintf(file, "�������� ������� �� ���������\n");
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
	TextOut(dc, 105, 90, L"���� ��������!", strlen("���� ��������!"));
	if (stopwatch == 1) {
		TextOut(dc, 80, 225, L"������ ����������", strlen("������ ����������"));
		t2 = time(NULL);
		differ = difftime(t2, t1);
		file = fopen("����������.txt", "a");
		fprintf(file, "������� ��������� - %d x %d \n", height, width);
		fprintf(file, "���-�� ��������� ������� - %d\n", amount);
		fprintf(file, "����� ����������� - %.2f ���.\n", differ);
		fprintf(file, "************************************\n");
		fclose(file);
	}
	RECT r;
	r.left = 550;
	r.top = 300;
	r.right = 1065;
	r.bottom = 400;
	FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(102, 102, 153)));
	TextOut(dc, 570, 340, L"������� ����� �������, ����� ���������", strlen("������� ����� �������, ����� ���������"));
	DeleteObject(hFont1); //�������� �� ������ ������ ������
	dynamic_array_free(maze, height);
	_getch();
	ReleaseDC(hwnd, dc);
	menu();
}
//�������� �������
void mazegame(int height, int width, bool stopwatch, bool check_bot, int lvl) {
	int x, y, random, count, coins = 0;
	int **maze = dynamic_array(width, height);
	for (int i = 0; i < height; i++) { // ������ ����������� ������-��������
		for (int j = 0; j < width; j++) {
			maze[i][j] = wall;
		}
	}
	x = 1; //��������� ���������� ��������
	y = 1;
	count = 0; //�������
	while (count < 1000) {
		maze[y][x] = pass; count++;
		while (pass) { // ����������� ����, ������� ����������� ������ �������
			random = rand() % 4;
			switch (random) {
			case 0: if (y != 1) {
				if (maze[y - 2][x] == wall) { // �����
					maze[y - 1][x] = pass;
					maze[y - 2][x] = pass;
					y -= 2;
				}
			}
			case 1: if (y != height - 2) {
				if (maze[y + 2][x] == wall) { // ����
					maze[y + 1][x] = pass;
					maze[y + 2][x] = pass;
					y += 2;
				}
			}
			case 2: if (x != 1) {
				if (maze[y][x - 2] == wall) { // �����
					maze[y][x - 1] = pass;
					maze[y][x - 2] = pass;
					x -= 2;
				}
			}
			case 3: if (x != width - 2) {
				if (maze[y][x + 2] == wall) { // ������
					maze[y][x + 1] = pass;
					maze[y][x + 2] = pass;
					x += 2;
				}
			}
			}
			if (deadend(x, y, maze, height, width)) //�������� �� �����
				break;
		}
		if (deadend(x, y, maze, height, width)) { // ���������� �������� �� ������
			do {
				x = 2 * (rand() % ((width - 1) / 2)) + 1;
				y = 2 * (rand() % ((height - 1) / 2)) + 1;
			} while (maze[y][x] != pass);
		}
	}
	maze[1][0] = digger;
	maze[width - 2][height - 1] = pass;
	//������� ������������ ���������
	if (check_bot) {
		//�������
		dynamic_array_bot(maze, height, width, stopwatch);
		//������
		mainmech(maze, height, lvl);
		//��������
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
		//��������
		go(maze, height, width, stopwatch, 0);
	}
}
//������� ��� ������ �������
void mainmech(int** maze, int height, int lvl) {
	double difP = 0, difB = 0;
	FILE *file;
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
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
		TextOut(dc, 700, 340, L"��� �������� �������...", strlen("��� �������� �������..."));
	}
	else {
		FillRect(dc, &r, (HBRUSH)CreateSolidBrush(RGB(102, 102, 153)));
		TextOut(dc, 740, 340, L"�� ��������!", strlen("�� ��������!"));
	}
	file = fopen("����������.txt", "a");
	fprintf(file, "������� ��������� - %d x %d \n", height, height);
	fprintf(file, "����� ���� - %.2f ���.\n", difB);
	fprintf(file, "����� ������ - %.2f ���.\n", difP);
	fprintf(file, "************************************\n");
	fclose(file);
	ReleaseDC(hwnd, dc);
	_getch();
	menu();
}

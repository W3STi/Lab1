#include "Mechanics.h"
#include "Graphics.h"
#include "Menu.h"

//������� ����������������� ����
void menu() {
	int p = 1, c = 0;
	int x11 = 760, x22 = 780, y11 = 215, y22 = 235;
	int height, width;
	char name[LEN];
	system("cls");
	FILE *file;
	bool stopwatch = 0;//�������� �� ��, ����� �� ���������� � ���� ��������
	graphicsofmenu();
	HWND hwnd = GetConsoleWindow(); //���� �������� �� ���������� ���� (� �� ����� ��������)
	HDC dc = GetDC(hwnd); //��������� � ����������� ����
	RECT window = {}; //���������� window ����� ������������ ��� ��������� ������ � ������ ����
	HBRUSH brush; //���������� brush - ��� �����, ��� ����� �������������� ��� ������������
	//������ �������
	brush = CreateSolidBrush(RGB(20, 10, 100)); // ������ ����� ������������ ����� � �����
	SelectObject(dc, brush); //�������� �����
	RECT WinCoord = {}; //������ ��������� ���� 
	GetWindowRect(hwnd, &WinCoord); //����� ����������
	while (TRUE) //��������� �� ����
	{
		int prov = 0;
		c = _getch();
		switch (c)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			p = c - '0';
		case KEY_ENTER:
			switch (p)
			{
			case 1:
				Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
				DeleteObject(brush); //������� ������ �� ��������� �����
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
					printf("������� ��� �������� ���������:                              \n");
					printf("1)����� ����� ������.                                        \n");
					printf("2)�����/������ - �������� �������� �� ������� �� 11 �� 33    \n");
					printf("������� ����� ��������� -                                    \n");
					scanf_s("%d", &height);
					printf("������� ������ ��������� -                                   \n");
					scanf_s("%d", &width);
					//�������� ��������
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 34;
						jge end1;
						cmp eax, 10;
						jle end1;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end1;
						cmp ecx, ebx;
						jne end1;

						cmp ebx, 34;
						jge end1;
						cmp ebx, 10;
						jle end1;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end1;
						jmp endgood;
					end1:
						mov prov, 0;
						jmp finaly;
					endgood:
						mov prov, 1;
						jmp finaly;
					finaly:;
					}
				}
				DeleteObject(brush); //������� ������ �� ��������� �����
				ReleaseDC(hwnd, dc);
				mazegame(height, width, stopwatch, 0, 0);
				break;
			case 2:
				Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
				DeleteObject(brush); //������� ������ �� ��������� �����
				char name[LEN];
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
					printf("������� ��� �������� ���������:                              \n");
					printf("1)����� ����� ������.                                        \n");
					printf("2)�����/������ - �������� �������� �� ������� �� 11 �� 33    \n");
					printf("������� ����� ��������� -                                    \n");
					scanf_s("%d", &height);
					printf("������� ������ ��������� -                                   \n");
					scanf_s("%d", &width);
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 34;
						jge end2;
						cmp eax, 10;
						jle end2;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end2;
						cmp ecx, ebx;
						jne end2;

						cmp ebx, 34;
						jge end2;
						cmp ebx, 10;
						jle end2;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end2;
						jmp endgood2;
					end2:
						mov prov, 0;
						jmp finaly2;
					endgood2:
						mov prov, 1;
						jmp finaly2;
					finaly2:;
					}
				}
				printf("������� ���� ��� (< 15 ��������)                             \n");
				scanf("%" STRLEN(LEN) "s", name);
				file = fopen("����������.txt", "a");
				fprintf(file, "************************************\n");
				setlocale(LC_ALL, "Rus");
				fprintf(file, "���/������� - %s \n", name);
				fclose(file);
				DeleteObject(brush); //������� ������ �� ��������� �����
				ReleaseDC(hwnd, dc);
				stopwatch = 1;
				mazegame(height, width, stopwatch, 0, 0);
				break;
			case 3:
				char name1[LEN];
				int lvl;
				while (prov == 0) {
					system("cls");
					Rectangle(dc, 0, 0, WinCoord.right, WinCoord.bottom); //���������� �������������, ����������� ����� ������
					printf("������� ��� �������� ���������:                              \n");
					printf("1)����� ����� ������.                                        \n");
					printf("2)�����/������ - �������� �������� �� ������� �� 11 �� 21    \n");
					printf("������� ����� ��������� -                                    \n");
					scanf_s("%d", &height);
					printf("������� ������ ��������� -                                   \n");
					scanf_s("%d", &width);
					printf("������� ��������� ��������� ��������� - '1'. '2' ��� '3'     \n");
					scanf_s("%d", &lvl);
					__asm {
						mov eax, height;
						mov ebx, width;
						mov edi, 2;
						cmp eax, 22;
						jge end22;
						cmp eax, 10;
						jle end22;
						mov ecx, eax;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end22;
						cmp ecx, ebx;
						jne end22;

						cmp ebx, 22;
						jge end22;
						cmp ebx, 10;
						jle end22;
						mov eax, ebx;
						cdq;
						idiv edi;
						cmp edx, 0;
						je end22;
						jmp egd2;
					end22:
						mov prov, 0;
						jmp fnl2;
					egd2:
						mov prov, 1;
						jmp fnl2;
					fnl2:;
					}
					if (lvl > 3 || lvl < 1) {
						prov = 0;
					}
				}
				printf("������� ���� ��� (< 15 ��������)                             \n");
				scanf("%" STRLEN(LEN) "s", name1);
				file = fopen("����������.txt", "a");
				fprintf(file, "************************************\n");
				setlocale(LC_ALL, "Rus");
				fprintf(file, "���/������� - %s \n", name1);
				fclose(file);
				DeleteObject(brush); //������� ������ �� ��������� �����
				ReleaseDC(hwnd, dc);
				stopwatch = 1;
				mazegame(height, width, stopwatch, 1, lvl);
				__asm {
					mov eax, y11;
					mov ebx, y22;
					cmp eax, 215;
					jle endwarning;
					sub eax, 140;
					cmp ebx, 235;
					jle endwarning;
					sub ebx, 140;
					mov y11, eax;
					mov y22, ebx;
				endwarning:;
				}
				break;
			case 4:
				system("cls");
				rules();
				_getch();
				if (_kbhit()) _getch();
				__asm {
					mov eax, y11;
					mov ebx, y22;
					cmp eax, 215;
					jle endw;
					sub eax, 210;
					cmp ebx, 235;
					jle endw;
					sub ebx, 210;
					mov y11, eax;
					mov y22, ebx;
				endw:;
				}
				break;
			case 5:
				system("cls");
				exit(0);
			}
			system("cls");
			graphicsofmenu();
			p = 1;
			break;
		case KEY_UP:
			if (p > 1) {
				brush = CreateSolidBrush(RGB(20, 100, 200)); // �� ��������� �������
				SelectObject(dc, brush); //�������� �����
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //������� ������ �� ��������� �����
				p--;
				y11 -= 70;
				y22 -= 70;
				brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
				SelectObject(dc, brush); //�������� �����
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //������� ������ �� ��������� �����
			}
			break;
		case KEY_DOWN:
			if (p < 5) {
				brush = CreateSolidBrush(RGB(20, 100, 200)); // �� ��������� �������
				SelectObject(dc, brush); //�������� �����
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //������� ������ �� ��������� �����
				p++;
				y11 += 70;
				y22 += 70;
				brush = CreateSolidBrush(RGB(255, 204, 102)); // ��������� �������
				SelectObject(dc, brush); //�������� �����
				Ellipse(dc, x11, y11, x22, y22);
				DeleteObject(brush); //������� ������ �� ��������� �����
			}
			break;
		}
	}
}
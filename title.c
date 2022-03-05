#include "title.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <mmsystem.h>
#define BLACK 0
#define MIDDLEYELLOW 14
#define YELLOW 6
#define DARKGRAY  8
#define WHITE 15 
#define RED 4 
#define LIGHTRED 12
#define GREEN 2 
#define BLUE 1
#define LIGHTGRAY 7

#pragma comment(lib, "winmm.lib")
#pragma warning (disable : 4996)
#define SOUND_FILE_NAME "title.wav"


int text_cbnu[19][66] = {
   2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
   2,0,0,0,1,1,1,1,1,1,1,3,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,3,0,0,0,1,1,1,1,1,3,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,1,1,1,1,1,3,0,0,0,0,0,0,0,1,3,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,0,1,1,1,3,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,1,3,1,3,0,0,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,1,1,1,1,1,3,0,0,0,0,1,3,0,0,0,0,0,0,1,3,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,1,1,1,1,1,1,1,1,1,3,0,0,1,1,1,1,1,1,1,1,1,3,0,0,1,1,1,1,1,1,1,1,1,3,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,1,3,0,0,0,0,0,1,1,1,1,3,0,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,1,1,1,3,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,0,1,1,1,3,0,0,0,0,0,0,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,1,3,0,1,3,0,2,
   2,0,0,0,1,3,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,1,1,1,1,3,0,1,3,0,1,3,0,2,
   2,0,0,0,0,1,3,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
   2,0,0,0,0,0,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
   2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
};


// 타이틀화면 출력하는 함수
void show_title() {
	system("mode con cols=137 lines=43");
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int i, j;
	int cbnu_x = 2, cbnu_y = 1;

	for (j = 0; j < 19; j++) {
		gotoxy(cbnu_x, cbnu_y);
		for (i = 0; i < 66; i++) {
			if (text_cbnu[j][i] == 0)
				printf("  ");
			else if (text_cbnu[j][i] == 1) {
				if (i / 13 == 0) {
					textcolor(RED, BLACK);
					printf("■");

				}
				else if (i / 13 == 1) {
					textcolor(LIGHTRED, BLACK);
					printf("■");
				}
				else if (i / 13 == 2) {
					textcolor(YELLOW, BLACK);
					printf("■");
				}
				else if (i / 13 == 3) {
					textcolor(GREEN, BLACK);
					printf("■");
				}
				else if (i / 13 == 4) {
					textcolor(BLUE, BLACK);
					printf("■");
				}

			}
			else if (text_cbnu[j][i] == 2) {
				textcolor(MIDDLEYELLOW, BLACK);
				printf("★");
			}
			else if (text_cbnu[j][i] == 3) {
				textcolor(DARKGRAY, BLACK);
				printf("■");
			}
		}
		cbnu_y++;
	}

	print_t();
	textcolor(WHITE,BLACK);
}


void t_start() {

	gotoxy(57, 28);
	printf("〓〓〓〓〓〓〓〓〓〓");
	gotoxy(57, 29);
	printf("     GAME START     ");
	gotoxy(57, 30);
	printf("〓〓〓〓〓〓〓〓〓〓");
}

void t_restart() {

	gotoxy(45, 18);
	printf("〓〓〓〓〓〓〓〓〓〓");
	gotoxy(45, 19);
	printf("      RESTART       ");
	gotoxy(45, 20);
	printf("〓〓〓〓〓〓〓〓〓〓");
}

void t_exit() {
	gotoxy(57, 34);
	printf("〓〓〓〓〓〓〓〓〓〓");
	gotoxy(57, 35);
	printf("        EXIT           ");
	gotoxy(57, 36);
	printf("〓〓〓〓〓〓〓〓〓〓");
}
void t_rexit() {
	gotoxy(45, 24);
	printf("〓〓〓〓〓〓〓〓〓〓");
	gotoxy(45, 25);
	printf("        EXIT           ");
	gotoxy(45, 26);
	printf("〓〓〓〓〓〓〓〓〓〓");
}


// start와 exit중에 고르는 함수
void print_t() {
	int X, Y;
	int* x = &X;
	int* y = &Y;
	char key;

	*x = 54;
	*y = 29;

	t_start();
	t_exit();
	gotoxy(*x, *y);
	printf("▶");


	while (1) {
		key = getch();
		if (key == 13) {
			title_execute(y);
			break;
		}
		title_move(key, x, y);
	}
}

// 게임 도중 죽었을때 다시 시작할 수 있게 해주는 함수
void print_t_restart() {
	int X, Y;
	int* x = &X;
	int* y = &Y;
	char key;

	*x = 42;
	*y = 19;

	t_restart();
	t_rexit();
	gotoxy(*x, *y);
	printf("▶");


	while (1) {
		key = getch();
		if (key == 13) {
			retitle_execute(y);
			break;
		}
		retitle_move(key, x, y);
	}
}

void title_move(char key, int* x, int* y) {
	//system("cls");

	t_start();
	t_exit();
	switch (key) {
	case 72:
		*x = 54;
		*y = 29;
		gotoxy(*x, *y);
		printf("▶");
		*y = 35;
		gotoxy(*x, *y);
		printf("  ");
		*y = 29;
		break;
	case 80:
		*x = 54;
		*y = 35;
		gotoxy(*x, *y);
		printf("▶");
		*y = 29;
		gotoxy(*x, *y);
		printf("  ");
		*y = 35;
		break;
	default:
		break;
	}
	printf("\n");
}

// start와 exit중에 고르는 함수
void retitle_move(char key, int* x, int* y) {
	//system("cls");

	t_restart();
	t_rexit();
	switch (key) {
	case 72:
		*x = 42;
		*y = 19;
		gotoxy(*x, *y);
		printf("▶");
		*y = 25;
		gotoxy(*x, *y);
		printf("  ");
		*y = 19;
		break;
	case 80:
		*x = 42;
		*y = 25;
		gotoxy(*x, *y);
		printf("▶");
		*y = 19;
		gotoxy(*x, *y);
		printf("  ");
		*y = 25;
		break;
	default:
		break;
	}
	printf("\n");
}



void title_execute(int* y) {
	if (*y == 29)
		system("cls");

	if (*y == 35) {
		exit(EXIT_SUCCESS);
	}
}
void retitle_execute(int* y) {
	int i=0;
	if (*y == 19) {
		system("cls");
		print_sulmung2();
		changeFsize();
		system("mode con cols=400 lines=200");
		for (double d = 0.6; d < 2.1; d += 0.3) {
			i++;
			ch1_start(d, i);
		}
	}
	if (*y == 25)
		exit(EXIT_SUCCESS);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 8;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void print_sulmung() {
	system("cls");
	gotoxy(28, 10);
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	gotoxy(28, 11);
	printf("▣                                                ▣\n");
	gotoxy(28, 12);
	printf("▣                                                ▣\n");
	gotoxy(28, 13);
	printf("▣                **  조작 방법  **               ▣\n");
	gotoxy(28, 14);
	printf("▣                                                ▣\n");
	gotoxy(28, 15);
	printf("▣                                                ▣\n");
	gotoxy(28, 16);
	printf("▣                      상 : ↑                   ▣\n");
	gotoxy(28, 17);
	printf("▣                                                ▣\n");
	gotoxy(28, 18);
	printf("▣                      하 : ↓                   ▣\n");
	gotoxy(28, 19);
	printf("▣                                                ▣\n");
	gotoxy(28, 20);
	printf("▣                      좌 : ←                   ▣\n");
	gotoxy(28, 21);
	printf("▣                                                ▣\n");
	gotoxy(28, 22);
	printf("▣                      우 : →                   ▣\n");
	gotoxy(28, 23);
	printf("▣                                                ▣\n");
	gotoxy(28, 24);
	printf("▣                    공격 : SPACE                ▣\n");
	gotoxy(28, 25);
	printf("▣                                                ▣\n");
	gotoxy(28, 26);
	printf("▣                                                ▣\n");
	gotoxy(28, 27);
	printf("▣                                                ▣\n");
	gotoxy(28, 28);
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	gotoxy(47, 31);
	printf("press any key ...");
	getch();
}

void print_sulmung2() {
	int key = 0;

	gotoxy(28, 7);
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
	gotoxy(28, 8);
	printf("▣                                                ▣\n");
	gotoxy(28, 9);
	printf("▣                                                ▣\n");
	gotoxy(28, 10);
	printf("▣                                                ▣\n");
	gotoxy(28, 11);
	printf("▣                **  게임 방법  **               ▣\n");
	gotoxy(28, 12);
	printf("▣                                                ▣\n");
	gotoxy(28, 13);
	printf("▣                                                ▣\n");
	gotoxy(28, 14);
	printf("▣                                                ▣\n");
	gotoxy(28, 15);
	printf("▣    1. 다가오는 몬스터를 공격하여 죽이시오!     ▣\n");
	gotoxy(28, 16);
	printf("▣                                                ▣\n");
	gotoxy(28, 17);
	printf("▣    2. 몬스터에 닿으면 즉시 GAME OVER!          ▣\n");
	gotoxy(28, 18);
	printf("▣                                                ▣\n");
	gotoxy(28, 19);
	printf("▣    3. 몬스터가 반대편 벽에 닿으면 GAME OVER!   ▣\n");
	gotoxy(28, 20);
	printf("▣                                                ▣\n");
	gotoxy(28, 21);
	printf("▣    4. 각 스테이지 별로 3마리의 몬스터를        ▣\n");
	gotoxy(28, 22);
	printf("▣       잡으면 다음 단계로 넘어갑니다.           ▣\n");
	gotoxy(28, 23);
	printf("▣                                                ▣\n");
	gotoxy(28, 24);
	printf("▣    5. STAGE는 총 6개이며 단계가                ▣\n");
	gotoxy(28, 25);
	printf("▣       높아질수록 몬스터의 속도가 빨라집니다!   ▣\n");
	gotoxy(28, 26);
	printf("▣                                                ▣\n");
	gotoxy(28, 27);
	printf("▣                                                ▣\n");
	gotoxy(28, 28);
	printf("▣                                                ▣\n");
	gotoxy(28, 29);
	printf("▣       ENTER키를 누르면 게임이 시작됩니다.      ▣\n");
	gotoxy(28, 30);
	printf("▣                                                ▣\n");
	gotoxy(28, 31);
	printf("▣                                                ▣\n");
	gotoxy(28, 32);
	printf("▣                                                ▣\n");
	gotoxy(28, 33);
	printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n"); 
	
	while (key != 13) {
		key = getch();
	}

}
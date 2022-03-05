#include "ch1.h"
#include "title.h"
#pragma warning (disable : 4996)
#define SOUND_FILE_NAME1 "main-bgm.wav"
#define SOUND_FILE_NAME2 "clap.wav"
#define SOUND_FILE_NAME3 "clear.wav"
kill_count = 0;

// 몬스터 도트 동적할당 및 초기화
void ch1_init() {
	FILE* fp = fopen("monster.txt", "r");
	monster.dot = (char**)malloc(sizeof(char*) * 9);
	for (int i = 0; i < 9; i++) {
		monster.dot[i] = (char*)malloc(sizeof(char) * 20);
		fgets(monster.dot[i], 20, fp);
	}
}

// 게임을 시작하는 함수, monster_speed를 매개변수로 받아 난이도 조절
void ch1_start(double monster_speed,int i) {
	kill_count = 0;
	PlaySound(TEXT(SOUND_FILE_NAME1), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HWND myconsole = GetConsoleWindow();
	HBITMAP hImage, hOldBitmap;
	HDC hdc = GetDC(myconsole);
	HDC hMemDC = CreateCompatibleDC(hdc);
	ch1_init();

	// 초기 위치 지정
	for (int count = 0; count < MON; count++)
	{
		mon[count].x = rand() % 100 + 330;
		mon[count].y = count*30+20;			   
	}
	
	character_init();
	printDot(1, Hero.x, Hero.y);
	char key;

	// 무한반복
	while (1) {

		// 키보드 입력을 받음, 스페이스바는 공격, 방향키는 이동
		if (kbhit()) {
			key = getch();
			if (key == 32)
				character_attack();
			else
				character_move(key);
		}
		
		// 몬스터 출력
		print_mon(monster_speed);

		// 몬스터 3마리를 잡았을 때
		if (kill_count == 3)

		{
			// 스테이지 5개를 클리어하면 게임 성공
			if (i == 5) {
				all_clear();
			}

			// 스테이지가 5번째 이하면 미션 성공
			else {

				// 배경 초기화 및 콘솔창 크기 조절
				system("cls");
				system("mode con cols=110 lines=40");
				getbackFsize();

				// 이미지 로드
				hImage = NULL;
				hImage = (HBITMAP)LoadImage(NULL, TEXT("6.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
				PlaySound(TEXT(SOUND_FILE_NAME2), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				BitBlt(hdc, 20, 20, 1200, 900, hMemDC, 0, 0, SRCCOPY);
				kill_count = 0;

				// 게임 클리어
				char num = getch();
				while (num != 13) {
					num = getch();
				}
			}
			changeFsize();
			system("mode con cols=400 lines=200");
			break;

		}
		Sleep(10);
	}
}

                                                            
// 몬스터의 이동을 출력하는 함수
void print_mon(double monster_speed)

{


	
	srand(time(0));

	int count = 0;



	// 몬스터를 이동
	for (count = 0; count < MON; count++)

	{

		// 땅에 떨어졌을 경우 게임 오버, 재시작 창 출력
		if (mon[count].x <= 2) {
			system("mode con cols=110 lines=40");
			getbackFsize();
			gotoxy(49, 10);
			printf("GAME OVER!\n");
			gotoxy(42, 11);
			printf("% d 단계까지 버텼습니다.\n", (int)((monster_speed) * 10.0 / 3.0 - 1 ));
			print_t_restart();


		}

		// 몬스터를 왼쪽으로 이동, 매개변수로 이동속도 조절
		mon[count].x -= monster_speed;

		if (mon[count].x < 350)

		{

			// 몬스터가 지나간 자리에 공백을 출력하여 흔적 제거
			for (int j = 0; j < 9; j++) {
				gotoxy(mon[count].x + 15, mon[count].y + j);

				printf("    ");
			}

			// 몬스터와 주인공의 출력 범위가 겹치면 게임 오버, 재시작 창 출력
			if (mon[count].x - Hero.x <= 18 && mon[count].x - Hero.x >= -20) {
				if (mon[count].y - Hero.y >= -10 && mon[count].y - Hero.y <= 14) {
					system("mode con cols=110 lines=40");
					getbackFsize();
					gotoxy(49, 10);
					printf("GAME OVER!\n");
					gotoxy(42, 11);
					printf("% d 단계까지 버텼습니다.\n", (int)(monster_speed * 10.0 / 3.0 - 1));
					print_t_restart();
				}
			}

			// 몬스터 출력할 때 마다 색깔이 바뀜
			textcolor(rand() % 15 + 1, 0);
			printDot(3, mon[count].x, mon[count].y );
			textcolor(15, 0);
		}

	}

}

// 스테이지 5개를 모두 클리어하면 출력되는 함수
void all_clear() {
	PlaySound(TEXT(SOUND_FILE_NAME3), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("mode con cols=110 lines=40");
	getbackFsize();
	gotoxy(49, 10);
	printf("축하합니다!!\n");
	gotoxy(42, 11);
	printf("당신은 충북대의 영웅이 되었습니다>_<\n");
	gotoxy(42, 13);
	printf("한번 더 도전해보세요!!\n");
	print_t_restart();

}
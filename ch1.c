#include "ch1.h"
#include "title.h"
#pragma warning (disable : 4996)
#define SOUND_FILE_NAME1 "main-bgm.wav"
#define SOUND_FILE_NAME2 "clap.wav"
#define SOUND_FILE_NAME3 "clear.wav"
kill_count = 0;

// ���� ��Ʈ �����Ҵ� �� �ʱ�ȭ
void ch1_init() {
	FILE* fp = fopen("monster.txt", "r");
	monster.dot = (char**)malloc(sizeof(char*) * 9);
	for (int i = 0; i < 9; i++) {
		monster.dot[i] = (char*)malloc(sizeof(char) * 20);
		fgets(monster.dot[i], 20, fp);
	}
}

// ������ �����ϴ� �Լ�, monster_speed�� �Ű������� �޾� ���̵� ����
void ch1_start(double monster_speed,int i) {
	kill_count = 0;
	PlaySound(TEXT(SOUND_FILE_NAME1), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	HINSTANCE hInstance = GetModuleHandle(NULL);
	HWND myconsole = GetConsoleWindow();
	HBITMAP hImage, hOldBitmap;
	HDC hdc = GetDC(myconsole);
	HDC hMemDC = CreateCompatibleDC(hdc);
	ch1_init();

	// �ʱ� ��ġ ����
	for (int count = 0; count < MON; count++)
	{
		mon[count].x = rand() % 100 + 330;
		mon[count].y = count*30+20;			   
	}
	
	character_init();
	printDot(1, Hero.x, Hero.y);
	char key;

	// ���ѹݺ�
	while (1) {

		// Ű���� �Է��� ����, �����̽��ٴ� ����, ����Ű�� �̵�
		if (kbhit()) {
			key = getch();
			if (key == 32)
				character_attack();
			else
				character_move(key);
		}
		
		// ���� ���
		print_mon(monster_speed);

		// ���� 3������ ����� ��
		if (kill_count == 3)

		{
			// �������� 5���� Ŭ�����ϸ� ���� ����
			if (i == 5) {
				all_clear();
			}

			// ���������� 5��° ���ϸ� �̼� ����
			else {

				// ��� �ʱ�ȭ �� �ܼ�â ũ�� ����
				system("cls");
				system("mode con cols=110 lines=40");
				getbackFsize();

				// �̹��� �ε�
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

				// ���� Ŭ����
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

                                                            
// ������ �̵��� ����ϴ� �Լ�
void print_mon(double monster_speed)

{


	
	srand(time(0));

	int count = 0;



	// ���͸� �̵�
	for (count = 0; count < MON; count++)

	{

		// ���� �������� ��� ���� ����, ����� â ���
		if (mon[count].x <= 2) {
			system("mode con cols=110 lines=40");
			getbackFsize();
			gotoxy(49, 10);
			printf("GAME OVER!\n");
			gotoxy(42, 11);
			printf("% d �ܰ���� ������ϴ�.\n", (int)((monster_speed) * 10.0 / 3.0 - 1 ));
			print_t_restart();


		}

		// ���͸� �������� �̵�, �Ű������� �̵��ӵ� ����
		mon[count].x -= monster_speed;

		if (mon[count].x < 350)

		{

			// ���Ͱ� ������ �ڸ��� ������ ����Ͽ� ���� ����
			for (int j = 0; j < 9; j++) {
				gotoxy(mon[count].x + 15, mon[count].y + j);

				printf("    ");
			}

			// ���Ϳ� ���ΰ��� ��� ������ ��ġ�� ���� ����, ����� â ���
			if (mon[count].x - Hero.x <= 18 && mon[count].x - Hero.x >= -20) {
				if (mon[count].y - Hero.y >= -10 && mon[count].y - Hero.y <= 14) {
					system("mode con cols=110 lines=40");
					getbackFsize();
					gotoxy(49, 10);
					printf("GAME OVER!\n");
					gotoxy(42, 11);
					printf("% d �ܰ���� ������ϴ�.\n", (int)(monster_speed * 10.0 / 3.0 - 1));
					print_t_restart();
				}
			}

			// ���� ����� �� ���� ������ �ٲ�
			textcolor(rand() % 15 + 1, 0);
			printDot(3, mon[count].x, mon[count].y );
			textcolor(15, 0);
		}

	}

}

// �������� 5���� ��� Ŭ�����ϸ� ��µǴ� �Լ�
void all_clear() {
	PlaySound(TEXT(SOUND_FILE_NAME3), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("mode con cols=110 lines=40");
	getbackFsize();
	gotoxy(49, 10);
	printf("�����մϴ�!!\n");
	gotoxy(42, 11);
	printf("����� ��ϴ��� ������ �Ǿ����ϴ�>_<\n");
	gotoxy(42, 13);
	printf("�ѹ� �� �����غ�����!!\n");
	print_t_restart();

}
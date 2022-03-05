#include "ch1.h"

//���ΰ� ��Ʈ���� �ʱ�ȭ ���ִ� �Լ�, ������ �������� �ʱ�ȭ�� �ȵȴ�.
void character_init() {
	Hero.x = 70;
	Hero.y = 40;
	FILE* fp = fopen("character.txt", "r");
	Hero.dot = (char**)malloc(sizeof(char*) * 14);
	for (int i = 0; i < 14; i++) {
		Hero.dot[i] = (char*)malloc(sizeof(char) * 22);
		fgets(Hero.dot[i], 22, fp);
	}
}
//���ΰ��� ������ �ִ� �Լ�
void character_move(char key) {
	printDot(2, Hero.x, Hero.y);
	switch (key) {
	case 75:		//���� ȭ��ǥ ������ �������� �̵�
		if (Hero.x < 3) break;
		Hero.x -= 10;
		printDot(1, Hero.x, Hero.y);
		break;
	case 77:		//������ ȭ��ǥ ������ ���������� �̵�
		if (Hero.x > 328) break;
		Hero.x += 10;
		printDot(1, Hero.x, Hero.y);
		break;
	case 72:		//���� ȭ��ǥ ������ ���� �̵�
		if (Hero.y < 3) break;
		Hero.y -= 5;
		printDot(1, Hero.x, Hero.y);
		break;
	case 80:		//������ ȭ��ǥ ������ �Ʒ��� �̵�
		if (Hero.y > 177) break;
		Hero.y += 5;
		printDot(1, Hero.x, Hero.y);
		break;
	}
}

//���ΰ��� ���͸� �����ϴ� �Լ�, Į�� �Բ� ���
void character_attack() {

	printDot(1, Hero.x, Hero.y);
	gotoxy(Hero.x + 20, Hero.y + 9);
	printf("  ��");
	gotoxy(Hero.x + 20, Hero.y + 10);
	printf("����������ᢺ");
	gotoxy(Hero.x + 20, Hero.y + 11);
	printf("  ��");
	
	//Į�� ������ ������ ��ġ�� ���͸� ȭ�鿡�� ���ְ� kill_count�� 1�� ����
	for (int count = 0; count < 12; count++) {
		if (mon[count].x - Hero.x <= 41 && mon[count].x - Hero.x >= 19) {
			if (mon[count].y - Hero.y >= 3 && mon[count].y - Hero.y <= 11) {
				for (int i = 0; i < 9; i++) {
					gotoxy(mon[count].x, mon[count].y + i);
					printf("                  ");
				}
				mon[count].x = 900;
				/*mon[count].y = rand() % 150 + 3;*/
				kill_count++;

			}
		}
	}
	Sleep(100);
	gotoxy(Hero.x + 20, Hero.y + 9);
	printf("    ");
	gotoxy(Hero.x + 20, Hero.y + 10);
	printf("                      ");
	gotoxy(Hero.x + 20, Hero.y + 11);
	printf("    ");
}
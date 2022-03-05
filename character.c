#include "ch1.h"

//주인공 도트들을 초기화 해주는 함수, 파일은 전역으로 초기화가 안된다.
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
//주인공을 움직여 주는 함수
void character_move(char key) {
	printDot(2, Hero.x, Hero.y);
	switch (key) {
	case 75:		//왼쪽 화살표 누를때 왼쪽으로 이동
		if (Hero.x < 3) break;
		Hero.x -= 10;
		printDot(1, Hero.x, Hero.y);
		break;
	case 77:		//오른쪽 화살표 누를때 오른쪽으로 이동
		if (Hero.x > 328) break;
		Hero.x += 10;
		printDot(1, Hero.x, Hero.y);
		break;
	case 72:		//위쪽 화살표 누를때 위로 이동
		if (Hero.y < 3) break;
		Hero.y -= 5;
		printDot(1, Hero.x, Hero.y);
		break;
	case 80:		//오른쪽 화살표 누를떄 아래로 이동
		if (Hero.y > 177) break;
		Hero.y += 5;
		printDot(1, Hero.x, Hero.y);
		break;
	}
}

//주인공이 몬스터를 공격하는 함수, 칼도 함께 출력
void character_attack() {

	printDot(1, Hero.x, Hero.y);
	gotoxy(Hero.x + 20, Hero.y + 9);
	printf("  ■");
	gotoxy(Hero.x + 20, Hero.y + 10);
	printf("■■■■■■■■■■▶");
	gotoxy(Hero.x + 20, Hero.y + 11);
	printf("  ■");
	
	//칼과 몬스터의 범위가 겹치면 몬스터를 화면에서 없애고 kill_count에 1을 더함
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
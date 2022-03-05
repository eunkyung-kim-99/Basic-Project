#include <stdio.h>
#include "title.h"
#include "render.h"
#include "ch1.h"

int main(void) {
	int i=0;
	double d;
	cursor(0);
	show_title();
	images(20, 20, 0);
	print_sulmung();
	print_sulmung2();
	system("cls");
	changeFsize();
	system("mode con cols=400 lines=200");
	for (d = 0.6; d < 2.1; d += 0.3) {
		i++;
		ch1_start(d,i);
		
		
	}
	Sleep(3000);
	exit(1);
}
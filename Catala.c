#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <conio.h>

int main()
{

	int looper;
	int diceCounter = 1;
	int result;
	int result2;
	int sum = 0;
	char response;

	srand(time(NULL)); // to make the randomization independent of the computer's fixed seed

	for (looper = 1; looper <= 2; looper++) {

		printf("Dice #%d:\t%d\n", diceCounter, result = rand() % 6 + 1);
		sum += result;
		diceCounter++;

	}

	printf("Three dices were rolled.\nTheir sum is \t%d\n", sum);

	/*if sum = 9
	{
	//PL1 recebe wool, PL2 recebe grain.
	}*/

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	/* Draw Bar on screen */
	bar(150, 200, 400, 350);

	getch();
	closegraph();
	return 0;

}


int drawGrid(void)
{
	puts("+--------------+--------------+--------------+--------------+");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("|              |              |              |              |");
	puts("+--------------+--------------+--------------+--------------+");
	return 0;
}


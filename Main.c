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
	puts("|      # 0     |      # 1     |      # 2     |      # 3     |");
	puts("|              |              |              |              |");
	puts("|      N:D     |      N:D     |      N:D     |      N:D     |");
	puts("|     S:B(4)   |     S:I(6)   |     S:I(6)   |     S:B(4)   |");
	puts("|    E:L(11)   |    E:W(12)   |    E:W(12)   |    E:W(12)   |");
	puts("|      W:D     |    W:L(11)   |    W:L(11)   |    W:L(11)   |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|      # 4     |      # 5     |      # 6     |      # 7     |");
	puts("|              |              |              |              |");
	puts("|     N:B(4)   |     N:I(6)   |     N:B(5)   |    N:W(10)   |");
	puts("|     S:G(3)   |     S:L(3)   |    S:G(11)   |     S:L(4)   |");
	puts("|      E:D     |    E:W(10)   |      E:D     |      E:D     |");
	puts("|      W:D     |      W:D     |    W:W(10)   |      W:D     |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|      # 8     |      # 9     |      #10     |      #11     |");
	puts("|              |              |              |              |");
	puts("|     N:G(3)   |     N:L(3    |    N:G(11)   |     N:L(4)   |");
	puts("|     S:B(8)   |    S:W(10)   |    S:W(10)   |     S:I(3)   |");
	puts("|      E:D     |     E:W(9)   |      E:D     |      E:D     |");
	puts("|      W:D     |       W:D    |     W:D(9)   |      W:D     |");
	puts("+--------------+--------------+--------------+--------------+");
	puts("|      #12     |      #13     |      #14     |      #15     |");
	puts("|              |              |              |              |");
	puts("|     N:B(8)   |    N:W(10)   |    N:W(10)   |     N:I(3)   |");
	puts("|      S:D     |      S:D     |      S:D     |      S:D     |");
	puts("|     E:I(5)   |     E:G(2)   |     E:I(6)   |      E:D     |");
	puts("|      W:D     |     W:I(5)   |     W:G(2)   |     W:L(6)   |");
	puts("+--------------+--------------+--------------+--------------+");



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




int rollDice(void)
{
	return(rand() % 6) + 1);
}

int playGame(void)
{
	int dice_1 = 0;
	int dice_2 = 0;
	int sum = 0;
	int result;
	int point = 0;
	time_t t;
	bool playForPoint = false;

	srand(time(&t));
	printf(Roll dice with[ENTER]\n);
	fgetc(stdin);
	dice_1 = rollDice();
	dice_2 = rollDice();
	sum = dice_1 + dice_2;
	printf("D1: %2d - D2:%2d - Sum: %2d\n", dice_1, dice_2, sum);




}






void main()
{
	struct date
	{

		int day;
		int month;
		int year;
	};

	struct details
	{
		char name[20];
		int price;
		int code;
		int qty;
		struct date mfg;
	};

	struct details item[50];
	int n, i;

	clrscr();

	printf("Enter number of items:");
	scanf("%d", &n);
	fflush(stdin);

	for (i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Item name:");
		scanf("%[^\n]", item[i].name);

		printf("Quantity:");
		scanf("%d", &item[i].qty);
		fflush(stdin);
	}

	printf(" ***** INVENTORY *****\n");
	printf("------------------------------------------------------------------\n");
	printf("S.N.| NAME | CODE | QUANTITY | PRICE |MFG.DATE\n");
	printf("------------------------------------------------------------------\n");
	for (i = 0; i < n; i++)
		printf("%d %-15s %-5d \n", i + 1, item[i].name, item[i].qty;
	printf("------------------------------------------------------------------\n");

}





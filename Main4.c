#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

typedef struct {
	int Wool;
	int Brick;
	int Lumber;
	int Iron;
	int Grain;
	int StartPos;
	int Points;
}Player;

typedef struct {	
	char North[5], South[5], East[5], West[5];
	int AmountNorth, AmountSouth, AmountEast, AmountWest;
	/*array = array2 array2 array2 array2
	array2 = map map map map  */
	char Type[5]; //village, city or nothing type    == "A" (coppied)
	char Player[5]; //player1, player2 or none       == 10 (coopied)
} Map;

int playerStart(int i)
{
	int player_pos = 20;

	while ((player_pos > 15 || player_pos < 0) || player_pos == i) {
		scanf("%d", &player_pos);
		if (player_pos == i) {
			printf("Choose another cell on the board\n");
		}
	}
	return player_pos;
}

void drawGrid(Map Cells[4][4])
{
	int n = 0;
	for (int j = 0; j < 4; j = j + 1) {
		puts("+--------------+--------------+--------------+--------------+");
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (n < 10) {
				printf("      #%d      |", n);
			}
			else {
				printf("      #%d     |", n);
			}
			n = n++;
			if (i == 3) {
				printf("\n");
			}
		}
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (Cells[j][i].AmountNorth < 10) {
				printf("    N:%s(%d)    |", Cells[j][i].North, Cells[j][i].AmountNorth);
			}
			else {
				printf("    N:%s(%d)   |", Cells[j][i].North, Cells[j][i].AmountNorth);
			}
			if (i == 3) {
				printf("\n");
			}
		}
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (Cells[j][i].AmountSouth < 10) {
				printf("    S:%s(%d)    |", Cells[j][i].South, Cells[j][i].AmountSouth);
			}
			else {
				printf("    S:%s(%d)   |", Cells[j][i].South, Cells[j][i].AmountSouth);
			}
			if (i == 3) {
				printf("\n");
			}
		}
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (Cells[j][i].AmountEast < 10) {
				printf("    E:%s(%d)    |", Cells[j][i].East, Cells[j][i].AmountEast);
			}
			else {
				printf("    E:%s(%d)   |", Cells[j][i].East, Cells[j][i].AmountEast);
			}
			if (i == 3) {
				printf("\n");
			}
		}
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (Cells[j][i].AmountWest < 10) {
				printf("    W:%s(%d)    |", Cells[j][i].West, Cells[j][i].AmountWest);
			}
			else {
				printf("    W:%s(%d)   |", Cells[j][i].West, Cells[j][i].AmountWest);
			}
			if (i == 3) {
				printf("\n");
			}
		}
		for (int i = 0; i < 4; i = i++) {
			if (i == 0) {
				printf("|");
			}
			if (!strcmp(Cells[j][i].Player, "none")) {
				printf("              |");
			}
			else {
				printf("    %s (%s)   |", Cells[j][i].Player, Cells[j][i].Type);
			}
			if (i == 3) {
				printf("\n");
			}
		}
	}
	puts("+--------------+--------------+--------------+--------------+");
}

int rollDice(void)
{
	return((rand() % 6) + 1);
}

int playGame()
{
	int dice_1 = 0;
	int dice_2 = 0;
	int sum = 0;
	int point = 0;
	time_t t;


	srand(time(&t));
	dice_1 = rollDice();
	dice_2 = rollDice();
	sum = dice_1 + dice_2;
	printf("D1: %2d - D2:%2d - Sum: %2d\n", dice_1, dice_2, sum);
	return sum;
}

void putCharacter(Map *cmap, Player *cplayer, char player[10])
	{
	if (!strcmp(cmap->Player, "none")) {
		if (cplayer->Brick > 0 && cplayer->Grain > 0 && cplayer->Lumber > 0 && cplayer->Wool > 0) {
			cplayer->Brick--;
			cplayer->Grain--;
			cplayer->Lumber--;
			cplayer->Wool--;
			strcpy(cmap->Player, player); // Player == 10
			strcpy(cmap->Type, "A");
			cplayer->Points++;
		}
	}
	else {
		printf("You don't have enough res or there's a player there already.\n");
	}	
}

void upgrade(Map *cmap, Player *cplayer, char player[10])
{
	if (!strcmp(cmap->Player, player)) {
		if (!strcmp(cmap->Type, "A")) {
			if (cplayer->Grain >= 2 && cplayer->Iron >= 3) {
				cplayer->Grain = cplayer->Grain - 2;
				cplayer->Iron = cplayer->Iron - 3;
				strcpy(cmap->Type, "C");
				cplayer->Points += 2;
			}
			else {
				printf("You don't have enough resources!!\n");
			}
		}
		else {
			printf("This cell doesn't have village on it");
		}
	}
	else {
		printf("This is not your village\n");
	}
}

void convertToRes(int *valueFrom, int *valueTo)
{
	if (valueFrom != valueTo) {
		if (*valueFrom >= 4) {
			*valueFrom = *valueFrom - 4;
			*valueTo = *valueTo + 1;
		}
		else {
			printf("You don't have enough resources\n");
		}
	}
	else {
		printf("Same resources\n");
	}
}

void convertToPoints(int *valueFrom, int *valuePoints)
{
	if (*valueFrom >= 10) {
		*valueFrom = *valueFrom - 10;
		*valuePoints = *valuePoints + 1;
	}
	else {
		printf("You don't have enough resources\n");
	}
}


int main(Dice_1, Dice_2) {

	Map Cells[4][4] = {
		{{"D","B","L","D",1,4,11,1,"none","none"}, {"D","I","W","L",1,6,12,11,"none","none"}, {"D","B","G","W",1,5,9,12,"none","none"}, {"D","W","D","G",1,10,1,9,"none","none"}},
		{{"B","G","D","D",4,3,1,1,"none","none"}, {"I","L","W","D",6,3,10,1,"none","none"}, {"B","G","D","W",5,11,1,10,"none","none"}, {"W","L","D","D",10,4,1,1,"none","none"}},
		{{"G","B","D","D",3,8,1,1,"none","none"}, {"L","W","W","D",3,10,9,1,"none","none"}, {"G","W","D","W",10,11,1,9,"none","none"}, {"L","I","D","D",4,3,1,1,"none","none"}},
		{{"B","D","I","D",8,1,5,1,"none","none"}, {"W","D","G","I",10,1,2,5,"none","none"}, {"W","D","L","G",10,1,6,2,"none","none"}, {"I","D","D","L",3,1,1,6,"none","none"}}
	};

	int loop = 1;
	char input[128];
	int Turn = 1;
	int cellChoice;


	drawGrid(Cells);
	Player player1 = { 40,40,40,40,40,0,0 };
	Player player2 = player1;
	printf("Choose start position of player 1\n");
	player1.StartPos = playerStart(20);
	printf("Choose start position) of player 2\n");
	player2.StartPos = playerStart(player1.StartPos);

	player1.Points -= 1;
	player2.Points -= 1;

	int counter = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (counter == player1.StartPos) {
				putCharacter(Cells[j] + i, &player1, "PL1");  // <- player pos = 10 (copy)
			}
			if (counter == player2.StartPos) {
				putCharacter(Cells[j] + i, &player2, "PL2");
			}
			counter++;
		}
	}

	playGame();
	drawGrid(Cells);
	printf("\nC Colocar cidade\n");
	printf("E Colocar nova vila\n");
	printf("B Banco\n");
	printf("P passar\n");

	while (loop == 1) {


		if (player1.Points >= 1) {
			printf("\n\nCongrats PL1! You won!");
			printf("\n\nDo you want to try again?\nyes, noX2?\n\n");
			fgets(input, 128, stdin);

			if (input[0] == 'y') {
				main();

				return(0);
			}

			if (input[0] == 'n') {
				printf("you suck");
				exit(1);
				return(0);
			}
		}
		else if (player2.Points >= 1) {
			printf("\nCongrats PL2! You won!");
			printf("\n\nDo you want to try again?\nyes, noX2?");
			fgets(input, 128, stdin);

			if (input[0] == 'y') {
				main();

				return(0);
			}

			if (input[0] == 'n') {
				printf("you suck");
				exit(1);
				return(0);
			}
		}



		if (Turn == 1) {
			printf("\nTurn of Player 1\n");
			printf("Brick - %d\n", player1.Brick);
			printf("Grain - %d\n", player1.Grain);
			printf("Iron - %d\n", player1.Iron);
			printf("Lumber - %d\n", player1.Lumber);
			printf("Wool - %d\n", player1.Wool);
			printf("Points - %d\n", player1.Points);
		}
		else {
			printf("\nTurn of player 2\n");
			printf("Brick - %d\n", player2.Brick);
			printf("Grain - %d\n", player2.Grain);
			printf("Iron - %d\n", player2.Iron);
			printf("Lumber - %d\n", player2.Lumber);
			printf("Wool - %d\n", player2.Wool);
			printf("Points - %d\n", player2.Points);
		}
		char input2[128];
		scanf("\n");
		fgets(input2, 128, stdin);

		if (input2[0] == 'c') { // <- upgrading village into city
			drawGrid(Cells);
			printf("\nG + G + I + I + I\n"); // <- choosing to place a village
			printf("Choose cell with village to upgrade\n");
			scanf("%d", &cellChoice);


			counter = 0;
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 4; i++) {
					if (counter == cellChoice && Turn == 1) {
						upgrade(Cells[j] + i, &player1, "PL1"); //goes to upgrade and puts a city in the place of the village.
					}
					else if (counter == cellChoice && Turn == 2) {
						upgrade(Cells[j] + i, &player2, "PL2");
					}
					counter++;
				}
			}

			drawGrid(Cells);
		}
		else if (input2[0] == 'e') { // <- placing a new village
			drawGrid(Cells);
			printf("\nB + L + G + W\n");
			printf("Choose adjcent cell\n");
			scanf("%d", &cellChoice);

			counter = 0;
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 4; i++) {
					if (counter == cellChoice && Turn == 1) {
						if (!strcmp(Cells[j - 1][i].Player, "PL1") || !strcmp(Cells[j + 1][i].Player, "PL1") || !strcmp(Cells[j][i - 1].Player, "PL1") || !strcmp(Cells[j][i + 1].Player, "PL1")) {
							putCharacter(Cells[j] + i, &player1, "PL1"); //goes to upgrade and puts a city in the place of the village.
						}
						else {
							printf("Player 1 doesn't have village or city on adj cell\n");
						}
					}
					else if (counter == cellChoice && Turn == 2) {
						if (Cells[j - 1][i].Player == "PL2" || Cells[j + 1][i].Player == "PL2" || Cells[j][i - 1].Player == "PL2" || Cells[j][i + 1].Player == "PL2") {
							putCharacter(Cells[j] + i, &player2, "PL2");
						}
						else {
							printf("Player 2 doesn't have village or city on adj cell\n");
						}
					}
					counter++;
				}

			}
			drawGrid(Cells);
		}

		else if (input2[0] == 'b') {
			int valueFrom, valueTo;
			printf("Choose one\n");
			printf("A - exchange resources 4:1\nB - exchange points 10:1\n");
			fgets(input, 128, stdin);

			if (input[0] == 'a') {
				printf("Choose resource you want to change from\n");
				printf("B - Brick\nG - Grain\nI - Iron\nL - Lumber\nW - Wool\n");
				fgets(input, 128, stdin);
				if (input[0] == 'b') {
					valueFrom = (Turn == 1) ? &player1.Brick : &player2.Brick;
				}
				else if (input[0] == 'g') {
					valueFrom = (Turn == 1) ? &player1.Grain : &player2.Grain;   //if turn = 1 player1 else player 2
				}
				else if (input[0] == 'i') {
					valueFrom = (Turn == 1) ? &player1.Iron : &player2.Iron;
				}
				else if (input[0] == 'l') {
					valueFrom = (Turn == 1) ? &player1.Lumber : &player2.Lumber;
				}
				else if (input[0] == 'w') {
					valueFrom = (Turn == 1) ? &player1.Wool : &player2.Wool;
				}

				printf("Choose resource you want to change to\n");
				printf("B - Brick\nG - Grain\nI - Iron\nL - Lumber\nW - Wool\n");
				fgets(input, 128, stdin);

				if (input[0] == 'b') {
					valueTo = (Turn == 1) ? &player1.Brick : &player2.Brick;
				}
				else if (input[0] == 'g') {
					valueTo = (Turn == 1) ? &player1.Grain : &player2.Grain;   //if turn = 1 player1 else player 2
				}
				else if (input[0] == 'i') {
					valueTo = (Turn == 1) ? &player1.Iron : &player2.Iron;
				}
				else if (input[0] == 'l') {
					valueTo = (Turn == 1) ? &player1.Lumber : &player2.Lumber;
				}
				else if (input[0] == 'w') {
					valueTo = (Turn == 1) ? &player1.Wool : &player2.Wool;
				}
				convertToRes(valueFrom, valueTo);
			}
			else if (input[0] == 'b') {

				valueTo = (Turn == 1) ? &player1.Points : player2.Points;
				printf("Choose resource you want to change from\n");
				printf("B - Brick\nG - Grain\nI - Iron\nL - Lumber\nW - Wool\n");
				fgets(input, 128, stdin);

				if (input[0] == 'b') {
					valueFrom = (Turn == 1) ? &player1.Brick : &player2.Brick;
				}
				else if (input[0] == 'g') {
					valueFrom = (Turn == 1) ? &player1.Grain : &player2.Grain;   //if turn = 1 player1 else player 2
				}
				else if (input[0] == 'i') {
					valueFrom = (Turn == 1) ? &player1.Iron : &player2.Iron;
				}
				else if (input[0] == 'l') {
					valueFrom = (Turn == 1) ? &player1.Lumber : &player2.Lumber;
				}
				else if (input[0] == 'w') {
					valueFrom = (Turn == 1) ? &player1.Wool : &player2.Wool;
				}
				convertToPoints(valueFrom, valueTo);
			}
		}

		else if (input2[0] == 'p') {
			printf("You passed your turn\n");
			if (Turn == 1) {
				Turn = 2;
			}
			else {
				Turn = 1;
			}
		}
	}
	return 0;
}
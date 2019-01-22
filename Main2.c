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
	int player_pos = 0;

	while ((player_pos >= 15 || player_pos <= 0) || player_pos == i) {
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

void playGame()
{
	int dice_1 = 0;
	int dice_2 = 0;
	int sum = 0;
	int point = 0;
	time_t t;


	srand(time(&t));
	printf("Roll dice with[ENTER]\n");
	fgetc(stdin);
	dice_1 = rollDice();
	dice_2 = rollDice();
	sum = dice_1 + dice_2;
	printf("D1: %2d - D2:%2d - Sum: %2d\n", dice_1, dice_2, sum);
}

void putCharacter(Map *cmap, Player *cplayer, char player[10])
{
	if (cplayer->Brick > 0 && cplayer->Grain > 0 && cplayer->Lumber > 0 && cplayer->Wool > 0) {
		cplayer->Brick--;
		cplayer->Grain--;
		cplayer->Lumber--;
		cplayer->Wool--;
		strcpy(cmap->Player, player); // Player == 10
		strcpy(cmap->Type, "A");
	}
	else {
		printf("You don't have enough res\n");
	}
}

void upgrade(Map *cmap, char player[10])
{
	if (!strcmp(cmap->Player, player)) {
		if (!strcmp(cmap->Type, "A")) {
			strcpy(cmap->Type, "C");
		}
		else {
			printf("This cell doesn't have village on it");
		}
	}
	else {
		printf("This is not your village\n");
	}
}

int main(Dice_1, Dice_2) {

	Map Cells[4][4] = {
		{{"D","B","L","D",1,4,11,1,"none","none"}, {"D","I","W","L",1,6,12,11,"none","none"}, {"D","B","G","W",1,5,9,12,"none","none"}, {"D","W","D","G",1,10,1,9,"none","none"}},
		{{"B","G","D","D",4,3,1,1,"none","none"}, {"I","L","W","D",6,3,10,1,"none","none"}, {"B","G","D","W",5,11,1,10,"none","none"}, {"W","L","D","D",10,4,1,1,"none","none"}},
		{{"G","B","D","D",3,8,1,1,"none","none"}, {"L","W","W","D",3,10,9,1,"none","none"}, {"G","W","D","W",10,11,1,9,"none","none"}, {"L","I","D","D",4,3,1,1,"none","none"}},
		{{"B","D","I","D",8,1,5,1,"none","none"}, {"W","D","G","I",10,1,2,5,"none","none"}, {"W","D","L","G",10,1,6,2,"none","none"}, {"I","D","D","L",3,1,1,6,"none","none"}}
	};

	int PLone[] = { 50, 50, 50, 50, 50, 50 }; //  W  B  L  G  I  D  
	int multiplayer = 1;
	int loop = 1;
	char input[128] = "";
	int Turn = 1;

	drawGrid(Cells);
	Player player1 = { 1,1,1,0,1,0 };
	Player player2 = player1;
	printf("Choose start position of player 1\n");
	player1.StartPos = playerStart(20);
	printf("Choose start position) of player 2\n");
	player2.StartPos = playerStart(player1.StartPos);

	int counter = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (counter == player1.StartPos) {
				putCharacter(Cells[j] + i, &player1, "PL1");  // <- player pos = 10 (copy)
			}
			if (counter == player2.StartPos) {
				putCharacter(Cells[j] + i, &player2, "PL2");
				upgrade(Cells[j] + i, "PL1");
			}
			counter++;
		}
	}

	drawGrid(Cells);
	playGame();

	PLone[0] -= 1;
	printf("%d\n", PLone[0]); // <- here it prints 49

	printf("C Colocar cidade\n");
	printf("E Evoluir cidade\n");
	printf("B Banco\n");
	printf("P passar\n");

	while (input != 'c' || input != 'e' || input != 'b' || input != 'p') {
		printf("%d", Turn);
		fgets(input, 128, stdin);
		if (input[0] == 'c') {

			counter = 0;
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 4; i++) {
					if (counter == player1.StartPos) {
						printf("hello");
						upgrade(Cells[j] + i, &player2);
					}
					counter++;
				}
			}

			drawGrid(Cells);
			printf("B + L + G + W\n"); // <- choosing to place a village
			printf("%d\n", PLone[0]);
			printf("Quer continuar? y- Sim, N- Nao\n"); // do you want to continue?

			while (input != 'y' || input != 'n') {
				fgets(input, 128, stdin);
				if (input[0] == 'y' && &PLone[0] > 1 && &PLone[1] > 1 && &PLone[2] > 1 && &PLone[3] > 1) { //<- checks if player has resources.
					PLone[0] -= 1;
					PLone[1] -= 1;    //takes away the resources it costs!
					PLone[2] -= 1;
					PLone[3] -= 1;
					printf("%d\n", PLone[0]); // <- it prints 48
				}
				else if (input[0] == 'n') {
					printf("hello");
				}
				else {
					printf("the fuk yah doin?\n");
					break;
				}
			}
		}
		else if (input[0] == 'e') {
			multiplayer = 2;
			printf("you are now the mayor\n");
		}
		else if (input[0] == 'b') {
			printf("you know we are stealing from you?\n");
		}
		else if (input[0] == 'p') {
			printf("you skipped your turn\n");
			if (Turn == 1) {
				Turn = 2;
			}
			else if (Turn == 2) {
				Turn = 1;
			}
			Turn = 2;
		}
		else {
			printf("invalid number\n");
		}
	}

	while (loop == 1) {
		fgetc(stdin);
	}

	return 0;

}
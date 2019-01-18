#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Map()
{


}
void Players()
{
	int player1_pos = 0;
	int player2_pos = 0;

	while (player1_pos >= 17 || player1_pos <= 0) {
		scanf("%d", &player1_pos);
	}
	printf("player 1 in: %d\n", player1_pos);

	while (player2_pos >= 17 || player2_pos <= 0) {
		scanf("%d", &player2_pos);
	}
	printf("player 2 in: %d\n", player2_pos);

}

int main() {
	int PLone[] = {50, 50, 50, 50, 50, 50 }; //  W  B  L  G  I  D  
	int multiplayer = 1;
	int loop = 1;
	char input[128] ="";

	drawGrid();
	Players();
	playGame();

	PLone[0] -= 1;
	printf("%d\n", PLone[0]);

	printf("C Colocar cidade\n");
	printf("E Evoluir cidade\n");
	printf("B Banco\n");
	printf("P passar\n");

	while (input != 'c' || input != 'e' || input != 'b' || input != 'p') {
		fgets(input, 128, stdin);
		if (input[0] == 'c') {
			printf("B + L + G + W\n");
			printf("%d\n", PLone[0]);
			printf("Quer continuar? y- Sim, N- Nao\n");

			while (input != 'y' || input != 'n') {
				fgets(input, 128, stdin);
				if (input[0] == 'y' && PLone[0] > 1 && PLone[1] > 1 && PLone[2] > 1 && PLone[3] > 1) {
					PLone[0] -= 1;
					PLone[1] -= 1;
					PLone[2] -= 1;
					PLone[3] -= 1;
					printf("%d\n", PLone[0]);
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

int rollDice(void)
{
	return((rand() % 6) + 1);
}

int playGame(void)
{
	int dice_1 = 0;
	int dice_2 = 0;
	int sum = 0;
	time_t t;


	srand(time(&t));
	printf("Roll dice with[ENTER]\n");
	fgetc(stdin);
	dice_1 = rollDice();
	dice_2 = rollDice();
	sum = dice_1 + dice_2;
	printf("D1: %2d - D2:%2d - Sum: %2d\n", dice_1, dice_2, sum);
}


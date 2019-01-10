#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>

int main (){
	FILE *fp;
	fp = fopen("map2.ini","r");
	char grid_values[9][9];
	char save[9];

	int i;
	for (i = 0; (fscanf(fp, "%s", save) != EOF); i++)
	{
		int n;
		for (n = 0; n <=9; n++)
		{
			grid_values[i][n] = save[n];
			printf("%c\n", grid_values[i][n]);
		}
	}
	fclose(fp);
	return 0;
}

// Mateusz Pawlowski 2023. Program that generate correctly solved Sudoku boards.
#include <iostream>
#include <time.h>

int table[9][9] = { {0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0}
};

int x, y;
int r;

int l = 0;

int draw_board()
{
	int x, y;
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			printf("%d ", table[y][x]);
		}
		printf("\n");
	}
	return 0;
}

bool sprawdz_wiersz() 
{
	for (int a = 0; a < 9; a++) 
	{
		if (table[y][a] == r) { return true; }
	}
	return false;
}

bool sprawdz_kolumne()
{
	for (int a = 0; a < 9; a++)
	{
		if (table[a][x] == r) { return true; }
	}
	return false;
}

bool k1() 
{
	if (table[0][0] == r) { return true; }
	if (table[0][1] == r) { return true; }
	if (table[0][2] == r) { return true; }
	
	if (table[1][0] == r) { return true; }
	if (table[1][1] == r) { return true; }
	if (table[1][2] == r) { return true; }
	
	if (table[2][0] == r) { return true; }
	if (table[2][1] == r) { return true; }
	if (table[2][2] == r) { return true; }
	return false;
}

bool k2()
{
	if (table[0][3] == r) { return true; }
	if (table[0][4] == r) { return true; }
	if (table[0][5] == r) { return true; }

	if (table[1][3] == r) { return true; }
	if (table[1][4] == r) { return true; }
	if (table[1][5] == r) { return true; }

	if (table[2][3] == r) { return true; }
	if (table[2][4] == r) { return true; }
	if (table[2][5] == r) { return true; }
	return false;
}

bool k3()
{
	if (table[0][6] == r) { return true; }
	if (table[0][7] == r) { return true; }
	if (table[0][8] == r) { return true; }

	if (table[1][6] == r) { return true; }
	if (table[1][7] == r) { return true; }
	if (table[1][8] == r) { return true; }

	if (table[2][6] == r) { return true; }
	if (table[2][7] == r) { return true; }
	if (table[2][8] == r) { return true; }
	return false;
}

bool k4()
{
	if (table[3][0] == r) { return true; }
	if (table[3][1] == r) { return true; }
	if (table[3][2] == r) { return true; }

	if (table[4][0] == r) { return true; }
	if (table[4][1] == r) { return true; }
	if (table[4][2] == r) { return true; }

	if (table[5][0] == r) { return true; }
	if (table[5][1] == r) { return true; }
	if (table[5][2] == r) { return true; }
	return false;
}

bool k5()
{
	if (table[3][3] == r) { return true; }
	if (table[3][4] == r) { return true; }
	if (table[3][5] == r) { return true; }

	if (table[4][3] == r) { return true; }
	if (table[4][4] == r) { return true; }
	if (table[4][5] == r) { return true; }

	if (table[5][3] == r) { return true; }
	if (table[5][4] == r) { return true; }
	if (table[5][5] == r) { return true; }
	return false;
}

bool k6()
{
	if (table[3][6] == r) { return true; }
	if (table[3][7] == r) { return true; }
	if (table[3][8] == r) { return true; }

	if (table[4][6] == r) { return true; }
	if (table[4][7] == r) { return true; }
	if (table[4][8] == r) { return true; }

	if (table[5][6] == r) { return true; }
	if (table[5][7] == r) { return true; }
	if (table[5][8] == r) { return true; }
	return false;
}

bool k7()
{
	if (table[6][0] == r) { return true; }
	if (table[6][1] == r) { return true; }
	if (table[6][2] == r) { return true; }

	if (table[7][0] == r) { return true; }
	if (table[7][1] == r) { return true; }
	if (table[7][2] == r) { return true; }

	if (table[8][0] == r) { return true; }
	if (table[8][1] == r) { return true; }
	if (table[8][2] == r) { return true; }
	return false;
}

bool k8()
{
	if (table[6][3] == r) { return true; }
	if (table[6][4] == r) { return true; }
	if (table[6][5] == r) { return true; }

	if (table[7][3] == r) { return true; }
	if (table[7][4] == r) { return true; }
	if (table[7][5] == r) { return true; }

	if (table[8][3] == r) { return true; }
	if (table[8][4] == r) { return true; }
	if (table[8][5] == r) { return true; }
	return false;
}

bool k9()
{
	if (table[6][6] == r) { return true; }
	if (table[6][7] == r) { return true; }
	if (table[6][8] == r) { return true; }

	if (table[7][6] == r) { return true; }
	if (table[7][7] == r) { return true; }
	if (table[7][8] == r) { return true; }

	if (table[8][6] == r) { return true; }
	if (table[8][7] == r) { return true; }
	if (table[8][8] == r) { return true; }
	return false;
}

bool sprawdz_kwadrat() 
{
	bool sprawdz = false;

	if (x >= 0 && x < 3 && y>=0 && y < 3) { sprawdz = k1(); }
	if (x >= 3 && x < 6 && y >= 0 && y < 3) { sprawdz = k2(); }
	if (x >= 6 && x < 9 && y >= 0 && y < 3) { sprawdz = k3(); }
	
	if (x >= 0 && x < 3 && y >= 3 && y < 6) { sprawdz = k4(); }
	if (x >= 3 && x < 6 && y >= 3 && y < 6) { sprawdz = k5(); }
	if (x >= 6 && x < 9 && y >= 3 && y < 6) { sprawdz = k6(); }

	if (x >= 0 && x < 3 && y >= 6 && y < 9) { sprawdz = k7(); }
	if (x >= 3 && x < 6 && y >= 6 && y < 9) { sprawdz = k8(); }
	if (x >= 6 && x < 9 && y >= 6 && y < 9) { sprawdz = k9(); }

	return sprawdz;
}

int zeruj() 
{
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			table[y][x] = 0;
		}
	}
	x = 0; y = 0;
	return false;
}

int main()
{
	printf("Mateusz Pawlowski 2023. Program that generate correctly solved Sudoku boards.\n\n");
	srand(time(NULL));
	
	r = rand() % 8 + 1;
	
	for (y = 0; y < 9; y++)
	{

		for (x = 0; x < 9; x++)
		{
			r = rand() % 8 + 1;

			l = 0;

			while (sprawdz_wiersz() == true || sprawdz_kolumne() == true || sprawdz_kwadrat() == true)
			{
				l++;
				r = rand() % 9 + 1;
				if (l == 30000) { zeruj(); }
			}
				
				table[y][x] = r;
	
				bool t = true;
				if (x == 8 && y == 8) 
				{
					printf("\n");
					draw_board();
					printf("\n");
										
					printf("\n");
					zeruj();
				}
		}
	}
	return 0;
}
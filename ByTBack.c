int HayJugada(char board[N][N])
{
	int x, y;
	int i=0;
	int j=0;
	for (i = 0; i < N-1; ++i)
		{
			for (j = 0; j < N-1; ++j)
			{
				if (board[i][j] != ' ')
				{
				//Existe Movimiento Horizontal
					if (board[i][j] == board[i][j+1])
						return 1;
					else if (board[i][j+1] == ' ')
					{
						y = j+2;
						while (board[i][y] == ' '   &&   y < N-1)
							y++;
						if (board[i][j] == board[i][y])
							return 1;
					}

			//Existe Movimiento Vertical
					if (board[i][j] == board[i+1][j])
						return 2;
					else if (board[i+1][j] == ' ')
					{
						x = i+2;
						while (board[x][j] == ' '   &&   x < N-1)
							x++;
						if (board[i][j] == board[x][j])
							return 2;
					}

			//Existe Movimiento Diagonal
					if (board[i][j] == board[i+1][j+1])
						return 3;
					else if (board[i+1][j+1] == ' ')
					{
						x = i+2;
						y = j+2;
						while (board[x][y] == ' '   &&   x < N-1   &&   y < N-1)
							x++;
							y++;
						if (board[i][j] == board[x][y])
							return 3;
					}
				}
			}
		}
	return 0;
}


#include<iostream>
#include<stdio.h>
using namespace std;

void printBoard(int flag);
int checkWinner();
char board[9];

int main()
{

	int playerTurn = 1;
	int gameOver = 1;
	int moveCount = 0;

	printf("\n\nPlease use numbers in the spaces as inputs for X or O\n\n");
	printBoard(0);

	for(int i = 0; i < 9; i++){
		board[i] = ' ';
	}

	while(gameOver == 1)
	{
		cout << "\nPlayer " << playerTurn << " please execute turn.\n\nKey:\n";
		printBoard(0);	
		cout << "\n\n";
		printBoard(1);
		int move, skip = 0;
		cout << "Turn: ";
		cin >> move;
		if(cin.fail()){
			cin.clear();
			while(cin.get() != '\n');
			skip = 1;
		}else{
			skip = 1;
			for(int i = 0; i < 9; i++){
				if(move == i) { skip = 0; }        
			}                  
		}
		if(board[move] == ' ' && skip == 0){
			char gamePiece;
			if(playerTurn == 1){gamePiece = 'x';}else{ gamePiece = '0'; }
			board[move] = gamePiece;
			moveCount++;
			gameOver = checkWinner();
			if(gameOver == 1){
				if(playerTurn == 1){ playerTurn = 2; }else { playerTurn = 1; }
			}
		}else{
			cout << "ERROR: Bad user input. Please re-enter move.";
		}

		if(moveCount == 9 && gameOver == 1){
			cout << "\n\n";
			printBoard(1);
			cout << "\nBoard is full. Tie Game!\n\n";
			return 0;
		}	
	}

	cout << "\n\nPlayer " << playerTurn << " is the winner!!!!\n\n";
	printBoard(1);	

	return 0;
}
void printBoard(int flag)
{
	if(flag == 0)
	{
		printf ("|| 0 || 1 || 2 ||\n");
		printf ("-----------------\n");
		printf ("|| 3 || 4 || 5 ||\n");
		printf ("-----------------\n");
		printf ("|| 6 || 7 || 8 ||\n");	
	}else
	{
		printf ("|| %c || %c || %c ||\n", board[0],board[1],board[2]);
		printf ("-----------------\n");
		printf ("|| %c || %c || %c ||\n", board[3], board[4] ,board[5]);
		printf ("-----------------\n");
		printf ("|| %c || %c || %c ||\n\n", board[6], board[7] , board[8]);

	}

}
int checkWinner()
{
	//Check Horizontals
	int base = 0;
	for(int i = 0; i < 3; i++){
		if(board[base] == board[base + 1] && board[base] == board[base + 2] && board[base] != ' '){
			return 0;
		}

		base = base + 3;
	}
	//Check Verticals
	for(int i = 0; i  < 3; i++){
		base = i;
		if(board[base] == board[base + 3] && board[base] == board[base + 6] && board[base] != ' '){
			return 0;
		}
	}
	//Check Horizontals
	if(board[0] == board[4] && board[0] == board[8] && board[0] != ' '){
		return 0;
	}else if (board[2] == board[4] && board[2] == board[6] && board[2] != ' '){
		return 0;
	}else{
		return 1;
	}

}


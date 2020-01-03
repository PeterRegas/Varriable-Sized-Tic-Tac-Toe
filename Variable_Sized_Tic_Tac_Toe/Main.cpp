//Program: pg 47 exercise 4
//Date: 4 november 2015
//Written by: Peter Regas


#include <iostream.h>
#include "apstring.h"
#include <apmatrix.h>
#include <apvector.h>

//Fix the winchecking

//Prototypes
int CheckBoard(apstring strQuestion);
int CheckXY(int intBoardSize, apstring strQuestion);
int BoardSize(apmatrix<char> &chrBoard);
void BoardCreator(int intBoardSize, apmatrix<char> &chrBoard);
void PlayerTurn(int intBoard, apstring strPlayer, char chrCharacter, apmatrix<char> &chrBoard);
bool CheckWin(int intBoardSize, apmatrix<char> chrBoard, char chrWin);


int CheckBoard(apstring strQuestion)
{
	//declaring variable
	//intCin is a variable that holts the users entered integer
	int intCin; 
	
	//asking user the question and getting answer
	cout << strQuestion;
	cin >> intCin;
	cout << endl;
	
	//making sure the user enters a valid int
	while(cin.fail() || intCin < 3)
	{
		//as long as the integer is not valid it will delete what the user entered and 
		//ask for a new value
		cin.clear();
		cin.ignore(10000, '\n');
		cout << strQuestion;
		cin >> intCin;
		cout << endl;
	}
	
	return intCin;
} 

int CheckXY(int intBoardSize, apstring strQuestion)
{
	//declaring variable
	//intCin is a variable that holts the users entered integer
	int intCin; 
	
	//asking user the question and getting answer
	cout << strQuestion;
	cin >> intCin;
	cout << endl;
	
	//making sure the user enters a valid int
	while(cin.fail() || intCin > intBoardSize || intCin < 1)
	{
		//as long as the integer is not valid it will delete what the user entered and 
		//ask for a new value
		cin.clear();
		cin.ignore(10000, '\n');
		cout << strQuestion;
		cin >> intCin;
		cout << endl;
	}
	
	return intCin;
} 

int BoardSize(apmatrix<char> &chrBoard)
{
	//this is the size of the board
	int intBoardSize;
	
	//asking the user for the size of the board and getting the answer
	cout << "What Size of board would you like? \n";
	intBoardSize = CheckBoard("Enter board size(greater than 2): ");
	
	//resizing the matrix to the size of the board
	chrBoard.resize(intBoardSize, intBoardSize);
	return intBoardSize;
}

int WinCondition(int intBoardSize)
{
	//This is the win condition
	int intWinCondition;
	
	//I re-use checkboard function for the win condtition as they require the same
	//conditions for the imput to be valid
	intWinCondition = CheckXY(intBoardSize, "How many in a row are needed to win: ");
	return intWinCondition;
	
	
}


void BoardCreator(int intBoardSize, apmatrix<char> &chrBoard)
{
	//declaring variables matrixes and vectors
	//this is the main index for the board creator
	int intPrimaryIndex = 0;
	
	//this index is located inside the primary index and is used in
	//conjuction with the primary index to determine positions of X's and O's 
	//on the board when it is being created
	int intSecondaryIndex = 0;
	
	//this index is used with the primary index to create the structure of the board
	int intTertiaryIndex = 0;
	
	//this index is used for numbering the columns
	int intColumns = 1;
	
	//this index is used for numbering the rows.
	int intRows = 1;
	
	//this is here for formating
	cout << "    ";
	
	//This while statment is numbering the columns
	while (intColumns <= intBoardSize)
	{
		
		if (intColumns < 10)
		{
			cout << " " << intColumns << "  ";
		}
		else
		{
			cout << " " << intColumns << " ";
		}
		intColumns++;
	}
		//This is here for formating
		cout << endl << endl;
	
	//This is the main loop in this function and will create the board and insert the X's
	//O's or blanks
	while (intPrimaryIndex < intBoardSize)
	{
		int intSecondaryIndex = 0;
		
		//This wile statment numbers the rows
		while (intSecondaryIndex < intBoardSize)
		{
		
			if (intSecondaryIndex == 0)
			{
				if(intRows < 10)
				{
					cout << intRows << "   ";
				}
				else
				{
					cout << intRows << "  ";
				}
				
				intRows++;
			}
		
			//This set of if and else if statments checks the matrix to see if the current position on the board
			//has an X, O or nothing
			if (chrBoard[intPrimaryIndex][intSecondaryIndex] != 'X' && chrBoard[intPrimaryIndex][intSecondaryIndex] != 'O')
			{
				chrBoard[intPrimaryIndex][intSecondaryIndex] = ' ';
			}
			else if (chrBoard[intPrimaryIndex][intSecondaryIndex] == 'X')
			{
				chrBoard[intPrimaryIndex][intSecondaryIndex] = 'X';
			}
			else if (chrBoard[intPrimaryIndex][intSecondaryIndex] == 'O')
			{
				chrBoard[intPrimaryIndex][intSecondaryIndex] = 'O';
			}
			
			//this if statment puts the X's O's or nothing in the correct places on the board
			//it also places the verticle lines between the X's and O's
			//note: at this point only the board structure above the current set of X's O's or nothing
			//is presently there for each loop
			if (intSecondaryIndex == (intBoardSize - 1))
			{
			
				cout << " " << chrBoard[intPrimaryIndex][intSecondaryIndex] << " ";
			}
			else
			{
				cout << " " << chrBoard[intPrimaryIndex][intSecondaryIndex] << " |";
			}	
			
			intSecondaryIndex++;	
		}
		//This if is checking to see if the last line of X's and O's has been drawn 
		//becasue if it has the rest of this code does not need to run as there is no structure
		//below the final line
		if (intPrimaryIndex != (intBoardSize - 1))
		{
			intTertiaryIndex = 0;
			
			cout << endl << "    ";
			
			//This while loop builds one line of board structure each time it runs
			//it also takes into account the fencepost situation
			while (intTertiaryIndex < intBoardSize)
			{
				if(intTertiaryIndex != intBoardSize - 1)
				{
				
					cout << "---|";
				}	
				else
				{
					cout << "--- ";
				}
				intTertiaryIndex++;
			}
			
			cout << endl;	
		}
		
		intPrimaryIndex++;
	}
}

void PlayerTurn(int intBoard, apstring strPlayer, char chrCharacter, apmatrix<char> &chrBoard)
{
	//declaring varriables
	//this is the row postition the players X or O will be located at this turn
	int intRow;
	//this is the column postition the players X or O will be located at this turn
	int intColumn;
	//this bool is used to check if there is aready a move made in a position
	bool boolCheck = false;
	
	//this while statment will loop as long as the player has not made a valid move
	while (boolCheck == false)
	{
		cout << endl;
		
		//asking the user for a row and column position which are first sent to CheckXY to make
		//sure they are valid before the program checks to see if the position has been filled
		intColumn = CheckXY(intBoard, strPlayer + "Enter a Column position: ") - 1;
		cout << endl;
		
		intRow = CheckXY(intBoard, strPlayer + "Enter a row position: ") - 1;
		cout << endl;
		
		//this checks to make sure that the position on the board the user entered isn't taken
		//and if it is asks for a new position by restating the function
		if (chrBoard[intRow][intColumn] != 'X' && chrBoard[intRow][intColumn] != 'O')
		{
			chrBoard[intRow][intColumn] = chrCharacter;
			boolCheck = true;
		}
		else
		{
			cout << "This Position is already filled please choose another! \n";
		}
	
	}
	
}

bool CheckWin(int intBoardSize, apmatrix<char> chrBoard, char chrWin, int intWinLength)
{
	//The index for the main loop in this function
	int intPrimaryIndex = 0;
	//This index for the secondary loop inside the main loop
	int intSecondaryIndex = 0;
	//This is used to check if the player has won in the horizontal row
	int intHorWin = 0;
	//This is used to check if the player has won in the vertical row
	int intVerWin = 0;
	//This is used to check if the player has won in the diagonal row going from bottom left to top right
	int intDiaForwardWin = 0;
	//This is used to check if the player has won in the diagonal row from top right to bottom left
	int intDiaBackwardWin = 0;
	//This is used as the index for the diagonal index 
	int intDiagonalIndex = 0;
	
	//this while statment will loop unitl there is a winner or it has checked the whole board and there is not
	//a winner
	while (intPrimaryIndex < intBoardSize)
	{

		//this while loop will loop until intSecondaryIndex is equal to intBoardSize at which time it stops
		//this loop checks a row, column and the diagonals to see if they are equal to chrWin(which is an X orY)
		//if they are it adds one to that variable
		while (intSecondaryIndex < intBoardSize)
		{
			//checking Horizontal
			if (chrBoard[intPrimaryIndex][intSecondaryIndex] == chrWin)
			{
				intHorWin++;
			}
			else
			{
				intHorWin = 0;
			}
			
			//checking Vertical
			if (chrBoard[intSecondaryIndex][intPrimaryIndex] == chrWin)
			{
				intVerWin++;
			}
			else
			{
				intVerWin = 0;
			}
			
			while (intDiagonalIndex < intWinLength)
			{
			
					//Checking forward diagonal
				if (chrBoard[][] == chrWin)
				{
					intDiaForwardWin++;
				}
				else
				{
					intDiaForwardWin = 0;
				}
				
				//checking backwards diagonal
				if (chrBoard[][] == chrWin)
				{
					intDiaBackwardWin++;
				}
				else
				{
					intDiaBackwardWin = 0;
				}
				intDiagonalIndex++;
			}
				
			if (intDiaBackwardWin == intWinLength || intDiaForwardWin == intWinLength)
			{
				return true;
			}
			else
			{
				intDiaBackwardWin = 0;
				intDiaForwardWin = 0;
			}
			
			intSecondaryIndex++;
		}
		//This will check of one of the Win variables is equal to the board size if it is that in turn means that someone
		//has one the game so it returns true.
		if (intHorWin == intWinLength || intVerWin == intWinLength)
		{
			return true;
		}
		else
		{
			//after checking a row column and diagnal they are reset to check the next row and
			//column for a win the diagnals are set back to 0 becasue if they wen't if even one 
			//character was entered on a digonal someone would eventualy win from it 
			intHorWin = 0;
			intVerWin = 0;
		}
		intSecondaryIndex = 0;
		intPrimaryIndex++;
	}
	
	return false;
}

int main()
{
	//declaring variables matrixes and vectors
	//this is the size of the board
	int intBoardSize;
	//this is the matrix that stores the information for the game of tic tac toe it holds
	//the X and O positions on the board
	apmatrix<char> chrBoard(0,0);
	//A string that says "Player1; "
	apstring strPlayer1 = "Player1: ";
	//A string that says "Player2; "
	apstring strPlayer2 = "Player2: ";
	//A character that holds "X"
	char chrX = 'X';
	//A character that holds "X"
	char chrO = 'O';
	//this bool determins whos turn it is
	bool boolTurn = true;
	//this bool is made equal to true or false when the CheckWin function is called
	//if it is true then the game has been won if false the game continues
	bool boolWin;
	//After every turn 1 is added to this if it becomes equal to how many spaces are on the board
	//then a tie is announced
	int intTieDetector = 0;
	
	//Making intBoardSize equal to the function BoardSize which will ask the user for a board size
	intBoardSize = BoardSize(chrBoard);
	
	//This is asking the user for the win length
	int intWinLength = WinCondition(intBoardSize);
	
	//will create the initial board with nothing on it
	BoardCreator(intBoardSize, chrBoard);
	//this is a infnite loop that will only end if there is a winner or a tie
	while(true)
	{
		//this if else statment is used for turn selection
		if (boolTurn == true)
		{
			//calls the player turn function for player 1 who is X
			PlayerTurn(intBoardSize, strPlayer1, chrX, chrBoard);
			//the tie detector increases by one because a players turn has passed
			intTieDetector++;
			//the Program checks to see if there is a winner
			boolWin = CheckWin(intBoardSize, chrBoard, chrX, intWinLength);
			
			//if there is a winner the final board is created the player is notified and the game is stopped
			if (boolWin == true)
			{
				BoardCreator(intBoardSize, chrBoard);
				cout << "\n Player 1 is the Winner!";
				break;
			}
			//if the tie detector is equal to the number of spaces on the board
			//that means there is no more possible moves and the game had ended in a tie
			//so the final board is displayed and it is displayed that it is a tie
			else if(intTieDetector == (intBoardSize * intBoardSize))
			{
				BoardCreator(intBoardSize, chrBoard);
				cout << "\n The game has ended in a tie!";
				break;
			}
			
			//the board is displayed
			BoardCreator(intBoardSize, chrBoard);
			//the turn is ended
			boolTurn = false;	
		}
		else
		{
			//calls the player turn function for player 1 who is X
			PlayerTurn(intBoardSize, strPlayer2, chrO, chrBoard);
			//the tie detector increases by one because a players turn has passed
			intTieDetector++;
			//the Program checks to see if there is a winner
			boolWin = CheckWin(intBoardSize, chrBoard, chrO, intWinLength);
			cout << boolWin;
			
			//if there is a winner the final board is created the player is notified and the game is stopped
			if (boolWin == true)
			{
				BoardCreator(intBoardSize, chrBoard);
				cout << "\n Player 2 is the Winner!";
				break;
			}
			//if the tie detector is equal to the number of spaces on the board
			//that means there is no more possible moves and the game had ended in a tie
			//so the final board is displayed and it is displayed that it is a tie
			else if(intTieDetector == (intBoardSize * intBoardSize))
			{
				BoardCreator(intBoardSize, chrBoard);
				cout << "\n The game has ended in a tie!";
				break;
			}
			//the board is displayed
			BoardCreator(intBoardSize, chrBoard);
			//the turn is ended
			boolTurn = true;
		}
	}
}



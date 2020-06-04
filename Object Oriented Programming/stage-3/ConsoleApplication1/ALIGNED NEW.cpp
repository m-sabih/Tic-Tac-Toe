#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
using namespace std;
class TicTacToe
{
private:
	int **board;											// 2-d dynamic array for board
    int size;												// size of the array
    static int draw; 										// static variable to check for draw
    char Player;
	int mode;
	int place;
	 
public:
	int getSize()
	{
		return size;
	}
	int getMode()
	{
		return mode;
	}
	char getPlayer()
	{
		return Player;
	}
	void setSize(int s)
	{
		this->size=s;
	}
	void setMode(int m)
	{
		this->mode=m;
	}
	void setPlayer(char p)
	{
		this->Player=p;
	}
	void setPlace(char place)
	{
		this->place=place;
	}
	TicTacToe(int size)                       	 				// constructor to iniatialize board with values from 1 to square of size
	{
		draw=0;												// whenever a new object is created, static variable which is used to check draw, is set to 0
		board=new int*[size];
		this->size=size;						
		int p=1;							 				// variable taken to assign values to the board starting with 1;
		for (int i=0;i<size;i++)
		{
			board[i]=new int[size];
			for(int j=0;j<size;j++)
			{
				board[i][j]=0+p;
				p++;
			}
		}
	}
	~TicTacToe()											//destructor
	{
		delete []*board;
	}
	void PrintBoard()										// function to print board
	{
    	for ( int i = 0; i < size; i++ )
		{
         	for (int j = 0; j < size; j++ )
         	{ 
			    if (board[i][j]==88)
					cout <<'\t'<<"X";						// substitutes ascii of X with X
				else if (board[i][j]==79)
               		cout <<'\t'<<"O";						// substitutes ascii of O with O
				else 
            		cout <<'\t'<<board[i][j];
				if (j<size-1)								// used this condition so that a line is not put after the last number in a particular row
				{
					cout<<'\t'<<"|";
			    }
         	 }  
         	 if (i<size-1)									// used this condition so that a line is not put at the end of the table
        	 {
				cout<<endl;
				for (int k=0;k<size;k++)
				{
					cout<<"________________";
				}
				cout<<endl;
         	 }	
      	}
    } 
   void Turns()						// function to encode the players' turns on the board by setting the place mark X or O with ascii of X and O
   {
      draw++;												// draw is incremented whenerever a player takes a turn
	  bool filled = true; 									//If true, it means player has tried to mark on an aready filled place
      for( int i = 0; i < this->size; i++ )
      {
         for( int j = 0; j < this->size; j++ )
         { 									
            if(board[i][j] == place) 
            { 
               if (Player=='X')             
			   		board[i][j] = 88;						//ascii of X stored where player X has taken move
			   else if (Player=='O') 
			   		board[i][j] = 79;       				//ascii of O stored where player O has taken move
               filled = false;   							// place not filled
            }
         }
      }
      while(filled == true) 								// keeps asking for input till an empty place is not entered and repeats the above process of assigning ascii to the place selected.
	  { 
	  	cout << "The place is already filled!..Enter a number again.\n"; 
	  	cin>>place;
	  	for( int i = 0; i < this->size; i++ )
      	{
    		for( int j = 0; j < this->size; j++ )
         	{
            	if(board[i][j] == place) 
            	{ 
               		if (Player=='X')           
               			board[i][j] = 88;
			   		else if (Player=='O') 
			   			board[i][j] = 79;
               	filled = false;          
            	}
         	}
      	 }
	  }
   }
   	void computerturn() 							// marks places for computer's turns
	{
		draw++;
		int count = 0;
		count = 0;
		for (int i = 0; i < size; i++) {					//checks for opponent own marks in rows
			count = 0;
			for (int j = 0; j < size; j++) {
				if (board[i][j] == 79)
					count++;
			}
			if (count == size - 1) {
				for (int j = 0; j < size; j++) {
					if (board[i][j] != 88 && board[i][j] != 79) {
						board[i][j] = 79;
						return;
					}

				}
			}
		}
		count = 0;
		for (int j = 0; j < size; j++) {					// checks for own marks in columns
			count = 0;
			for (int i = 0; i < size; i++) {
				if (board[i][j] == 79)
					count++;
			}
			if (count == size - 1) {
				for (int i = 0; i < size; i++) {
					if (board[i][j] != 88 && board[i][j] != 79) {
						board[i][j] = 79;
						return;
					}
				}
			}
		}
		count = 0;
		for (int i = 0, j = 0; i < size, j < size; i++, j++) //checks for own marks in left diagonal
		{	if (board[i][j] == 79)
				count++;
		}
		if (count == size - 1) {
			for (int i = 0, j = 0; i < size, j < size; i++, j++) {
				if (board[i][j] != 88 && board[i][j] != 79) {
					board[i][j] = 79;
					return;
				}

			}
		}
		count = 0;
		for (int i = 0, j = size - 1; i < size, j > 0; i++, j--) {	//checks for ownn marks in right diagonal
			if (board[i][j] == 79)
				count++;
		}
		if (count == size - 1) {
			for (int i = 0, j = size - 1; i <size, j > 0; i++, j--) {
				if (board[i][j] != 88 && board[i][j] != 79) {
					board[i][j] = 79;
					return;
					
				}

			}
		}
		count = 0;
		for (int i = 0; i < size; i++) {						// check for opponents marks in rows
			count = 0;
			for (int j = 0; j < size; j++) {
				if (board[i][j] == 88)
					count++;
			}
			if (count == size - 1) {
				for (int j = 0; j < size; j++) {
					if (board[i][j] != 88 && board[i][j] != 79) {
						board[i][j] = 79;
						return;
					}

				}
			}
		}
		count = 0;
		for (int j = 0; j < size; j++) {						// check for opponents marks in columns
			count = 0;
			for (int i = 0; i < size; i++) {
				if (board[i][j] == 88)
					count++;
			}
			if (count == size - 1) {
				for (int i = 0; i < size; i++) {
					if (board[i][j] != 88 && board[i][j] != 79) {
						board[i][j] = 79;
						return;
					}
				}
			}
		}
		count = 0;
		for (int i = 0, j = 0; i < size, j < size; i++, j++) {	//check for opponents marks in left diagonal
			if (board[i][j] == 88)
				count++;
		}
		if (count == size - 1) {
			for (int i = 0, j = 0; i < size, j < size; i++, j++) {
				if (board[i][j] != 88 && board[i][j] != 79) {
					board[i][j] = 79;
					return;
				}

			}
		}
		count = 0;
		for (int i = 0, j = size - 1; i < size, j > 0; i++, j--) {	// checks for opponents marks in right diagonal
			if (board[i][j] == 88)
				count++;
		}
		if (count == size - 1) {
			for (int i = 0, j = size - 1; i <size, j > 0; i++, j--) {
				if (board[i][j] != 88 && board[i][j] != 79) {
					board[i][j] = 79;
					return;
			 }

			}
		}
		while (true) {										// to mark for open sets only{
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					int random;
					if (size == 3) {
						random = rand() % 9 + 1;
					}
					else if (size == 4) {
						random = rand() % 16 + 1;
					}
					else if (size == 5) {
						random = rand() % 25 + 1;
					}

					if (board[i][j] == random)
					{
						if (Player == 'X')
						{
							board[i][j] = 88;					// assigning 51 to X because array is int type
						}
						else if (Player == 'O')
						{
							board[i][j] = 79;					// assigning 52 to O because array is int type
						}
						return;
					}
				}
			}
		}
	}
   bool CheckResult(bool End_of_Game) 				// checks if any player has won or game is a draw
   {
      int c=0;
	  for(int i = 0; i < size; i++) 							// first it checks for consecutive marks in row
      {
         for (int j=0;j<size-1;j++)
		 {
		 	if(board[i][j] == board[i][j+1])
		 		c++;
	     }
		 if (c==size-1)											//if the condition is true, it means consecutive marks are found in a row, so game is over
		 {
			End_of_Game = true;
		 }
		 else 
			c=0;
      }
      if (c==0)													// then it checks for consecutive marks in row (if not found in cols)
      {
       	for(int j = 0; j < size; j++) 
      	{
        	for (int i=0;i<size-1;i++)
		  	{
		 		if(board[i][j] == board[i+1][j])
		 			c++; 
		  	}
		 	if (c==size-1)										//if the condition is true, it means consecutive marks are found in a col, so game is over
		 		End_of_Game = true;
		 	else 
		 		c=0;
      	}
  	  }
      if (c==0)													// then it checks for consecutive marks in left diagonal (if not found in cols or rows)
      {
      	for (int i=0,j=0;i<size-1,j<size-1;i++,j++)
      	 {
 		  	if (board[i][j] == board[i+1][j+1])
   				c++;
		 }
		if (c==size-1)											//if the condition is true, it means consecutive marks are found in left diagonal, so game is over
		 	End_of_Game = true;
		else 
	 		c=0;
      }
	  if (c==0)      											// then it checks for consecutive marks in right diagonal (if not found in cols or rows or eft diagonal)
	  {
	  	 for (int i=0,j=size-1;j>0,i<size-1;i++,j--)
      	 {
		  	if (board[i][j] == board[i+1][j-1])
      			c++;
		 }
		 if (c==size-1)											//if the condition is true, it means consecutive marks are found in right diagonal, so game is over
	 		End_of_Game = true;
  	 	 else 
			c=0;
      }
      if(End_of_Game == true) 									//if game is over, winning player is declared
      {
      	 PrintBoard();
         cout << "\n\n ----->CONGRATULATIONS Player " << Player << "! You Have Won the Game!<-----\n\n";
      }
      else														// if no one wins, it checks for draw and declares that game is drawn
      {
    		int d=this->draw; 
      		if( d==(size*size) ) 
      		{
      			PrintBoard();
         		cout << "\n\n----->Its a DRAW! Try Again!<-----\n\n"; 
         		End_of_Game = true;					
     		 }
      }
      return End_of_Game;
   }
   
	void shiftTurn()										// shifts turns from X to O and vice versa
	{
		if( Player == 'X' ) 					
        {
      		setPlayer('O');
       	}
       	else             
		{
           	setPlayer('X');
        }
	}
	int inputPlace()						//take input for the place to be marked
	{
		int p;
		cout << "\nPlayer \"" << this->Player << "\", it's your turn: ";
        cin >> p; 
       	while (p>(size*size) || p<=0 )		//if the numbr entered is out of range, it asks for another input till a valid place number is entered.
        {
			cout<<endl<<"Error:Its not a choice,enter a place number that's available!!"<<endl;
			cin>>p;
       	}
       	cout << "\n";
  	    setPlace(p);
	}
	void saveGame()
	{
		ofstream outf("Gamedata.txt", ios::app);
		if(!outf)
		{
			cout << "File creation failed" << endl;
		}
		outf << size << " " <<mode<<" "<<Player<<" ";
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				outf << board[i][j] << " " ;	
			}
		}
		outf<<endl;
		outf.close();	
	}

	void loadGame(int s)
	{
		ifstream inf("Gamedata.txt");
		if(!inf)
		{
			cout << "Failed to open a file" << endl;
		}
		int m,n;
		char p;
		inf >> m >> p;
		for (int i=0;i<s;i++)
		{
			for (int j=0;j<s;j++)
			{
				inf>>n;
				board[i][j]=n;
			}
		}
		setMode(m);
		setPlayer(p);	
		setSize(s);
		inf.close();	//closing the file
	}

friend int findSize();
friend int Boardtype();
friend int Start();	
};
int	findSize()
{	
	ifstream inf("Gamedata.txt");
	if(!inf)
	{
		cout << "Failed to open a file" << endl;
	}
	int s;
	inf>>s;
	return s;
}
	
int TicTacToe::draw;											// static variable defined outside class

	
int Start()														// function to print instructions and return the format of game to be played
{
	int mode;
	char modec;
	cout<<"Select the Mode: (Enter 1 or 2)"<<endl<<endl;
	cout<<"1)1-player (user vs computer)"<<endl;
	cout<<"2)2-player (user vs user)"<<endl;
	do {
		cin>>modec;
		if (!isdigit(modec)) 									//check to see only 1 or 2 is entered
			cout<<"Wrong option selected, Enter again!"<<endl;
		else if(isdigit(modec) && modec=='1')
			{
				mode=1;	
				break;
			}	
		else if (isdigit(modec) && modec=='2')
			{
				mode=2;
				break;
			}
		else if (mode!=1 &&  mode!=2)
			cout<<"Wrong option selected, Enter again!"<<endl;	
	}while(!isdigit(modec) || mode!=1 || mode!=2 );
	return mode;
}
int Boardtype()													//function to select the format of board to be played on
{
	int choice;
	char choicec;
	cout<<"Which size of board do you want to select?"<<endl;
	cout<<"1)3x3"<<endl;
	cout<<"2)4x4"<<endl;
	cout<<"3)5x5"<<endl;
	bool correct=false;											// variable to check if the input choice is correct or not
	cout<<"Enter 1,2 or 3:"<<endl; 
		do	
		{
			cin>>choicec;				
			if (!isdigit(choicec))							//if choice is not a digit
				cout<<"Wrong option selected, Enter again!"<<endl;
			else if(isdigit(choicec) && choicec=='1')
			{
				choice=1;									//if 1 then continue
				break;
			}	
			else if (isdigit(choicec) && choicec=='2')
			{
				choice=2;									//if 2 then continue
				break;
			}
			else if (isdigit(choicec) && choicec=='3')
			{
				choice=3;									//if 3 then continue
				break;
			}				
			else if (choice!=1 &&  choice!=2 && choice!=3)		//if not then try again
				cout<<"Wrong option selected, Enter again!"<<endl;	
		}while(!isdigit(choice) || choice!=1 || choice!=2 || choice!=3 );
		if (choice==1)
			choice=3;										// choice 1 means user wants to play 3*3 format so choice is set to 3
		else if(choice==2)
			choice=4;										// choice 2 means user wants to play 4*4 format so choice is set to 4
		else if(choice==3)
			choice=5;										// choice 3 means user wants to play 5*5 format so choice is set to 5l
			return choice;
}
int Choice()
{
	int c;
	cout <<"********************WELCOME TO Tic-Tac-Toe**********************"<<endl;
	cout<<"****************************************************************"<<endl<<endl;
	cout<<"1. Load a Saved Game"<<endl;
	cout<<"2. Delete a Saved Game"<<endl;
	cout<<"3. New Game"<<endl; 
	cin>>c;
	return c;
}

int main()
{	
	bool end = false;										// variable that tells if a game has completely ended or not
	do
    {
    	int choose=Choice();
    	bool End_of_Game= false;
		if (choose==1)
		{
			int s=findSize();
			TicTacToe newGame(s);
			newGame.loadGame(s);
			while(true)											//takes input and checks for result till we break out of the loop
			{
        		if (newGame.getMode()==2)
				{
					newGame.shiftTurn();
        			newGame.PrintBoard();						//prints 
        			newGame.inputPlace();
        			newGame.Turns();				// calling function turns
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        				break;
				}
				else if (newGame.getMode()==1)
				{
					newGame.shiftTurn();
        			newGame.PrintBoard();						//prints 
        			newGame.inputPlace();
        			newGame.Turns();				// calling function turns
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        				break;	
					newGame.shiftTurn();
        			newGame.computerturn();
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        			break;
				}
			 	if (End_of_Game==true)								//at the end of the game, it asks if the user wants to play again
        		{
        			newGame.saveGame();
					char c;
					cout<<"Do you wish to play again? (Press 'y' or 'n' for yes and no)"<<endl;
        			cin>>c;
            		if (c=='y' || c=='Y')
            			end=false;
            		else if (c=='n' || c=='N')
            			end=true;
            		else 
            		{
            			cout<<"You have entered a wrong choice."<<endl<<"Game ended"<<endl;		// if a user enters anything other than n or y, the main loop ends as end is assigned true
            			end=true;	
            		}
        		}
    		}	
		}
		else if (choose==2)
		{
			//delGame();
		}	
		else if (choose==3)
		{
			int mode=Start();
			int choice=Boardtype();								// start function called to return choice of user for the format
			TicTacToe newGame(choice);							// obj of class initialized with parameterized constructor
			newGame.setMode(mode);	
    		while(true)											//takes input and checks for result till we break out of the loop
			{
        		if (newGame.getMode()==2)
				{
					newGame.shiftTurn();
        			newGame.PrintBoard();						//prints 
        			newGame.inputPlace();
        			newGame.Turns();				// calling function turns
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        				break;
				}
				else if (newGame.getMode()==1)
				{
					newGame.shiftTurn();
        			newGame.PrintBoard();						//prints 
        			newGame.inputPlace();
        			newGame.Turns();				// calling function turns
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        				break;	
					newGame.shiftTurn();
        			newGame.computerturn();
        			End_of_Game = newGame.CheckResult(End_of_Game);		//CheckResukt function called which returns the status of game
        			if(End_of_Game==true)						// breaks out of loop if game ends
        				break;
				}
			 	if (End_of_Game==true)								//at the end of the game, it asks if the user wants to play again
        		{
        			newGame.saveGame();
					char c;
					cout<<"Do you wish to play again? (Press 'y' or 'n' for yes and no)"<<endl;
        			cin>>c;
            		if (c=='y' || c=='Y')
            			end=false;
            		else if (c=='n' || c=='N')
            			end=true;
            		else 
            		{
            			cout<<"You have entered a wrong choice."<<endl<<"Game ended"<<endl;		// if a user enters anything other than n or y, the main loop ends as end is assigned true
            			end=true;	
            		}
        		}
    		}	
		}				
    } while(!end);
    cout<<endl<<endl<<"Game aborted. Thanks for playing!"<<endl<<endl;
    return 0;
}

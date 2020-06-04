#include <iostream>
using namespace std;

class TicTacToe
{
private:
	int **ar;
	int size;

public:

	//*********************************************************//
	TicTacToe(int size)               //constructor
	{
		int n=1;
		this->size=size;
		this->ar=new int *[size];
		for (int i=0;i<size;i++)
		{
			ar[i]=new int [size];
			for (int j=0;j<size;j++)
			{
				ar[i][j]=n;
				n++;
			}
		}
	}

	//*********************************************************//
	~TicTacToe()					//destructor
	{
		delete []ar;
	}

	//********************************************************//
	void printtable()				//table print
	{
		system("pause");
		system("cls");
		for (int i=0;i<size;i++)
		{
			for (int j=0;j<size;j++)
			{
				if (ar[i][j]==51)
				{
				cout<<'\t'<<" X ";			   //assigning X  (check player turn function)
				}
				else if (ar[i][j]==52)
				{
					cout<<'\t'<<" O ";			//assigning O (check player turn function)
				}
				else 
					cout<<'\t'<<ar[i][j];
				if (j<size-1)
				{
					cout<<'\t'<<"|";
				}
			}
			if(i<size-1)
			{
				cout<<endl;
				for (int k=0;k<size;k++)
				{
					cout<<"________________";
				}
			}
	cout<<endl;
			}
		}

	//********************************************************//
	void playerturn(int choice,char player)				//turn of player X or O
	{
		bool wrong=true;
		for (int i=0;i<size;i++)
		{
			for (int j=0;j<size;j++)
			{
				if (ar[i][j]==choice)
				{
					if (player=='X')
					{
						ar[i][j]=51;					// assigning 51 to X because array is int type
					}
					else if (player=='O')
					{
						ar[i][j]=52;					// assigning 52 to O because array is int type
					}
					wrong=false;
				}
			}
		}
		while (wrong==true)						// to mark for open sets only
		{
			cout<<endl<<"you can only mark open sets please try again "<<endl;
			cin>>choice;
			for (int i=0;i<size;i++)
			{
				for (int j=0;j<size;j++)
				{
					if (ar[i][j]==choice)
					{
						if (player=='X')
						{
							ar[i][j]=51;					// assigning 51 to X because array is int type
						}
						else if (player=='O')
						{
							ar[i][j]=52;					// assigning 52 to O because array is int type
						}
						wrong=false;
					}
			}
		}
		}
	}

	//*********************************************************//
	 bool Checkwin3(char Player, bool GameOver)               //checking the winner in 3*3
	 {
		for(int i = 0; i < 3; i++) 
		{              
			 if(ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2])			//checking by row
				 GameOver = true;
			}
		for(int i = 0; i < 3; i++)
		{                
			if(ar[0][i] == ar[1][i] && ar[1][i] ==  ar[2][i])			//checking by column
				GameOver = true;
			}
		if(ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2])				//checking by diagonals
		{     
			GameOver = true;		
			}
		if(ar[0][2] == ar[1][1] && ar[1][1] == ar[2][0]){
         GameOver = true;
			}
		if(GameOver == true) 
		{
         printtable();
		 cout<<endl;
		 cout<<endl;
		 cout << "Player " << Player << " wins!\n\n";				//if winner is true then winner is returned
         cout << "-----------------------" << endl;
         cout << "|   CONGRATULATIONS " << Player << " |\n";
         cout << "-----------------------" << endl << endl;
		}
		return GameOver;
   } 

	 //*********************************************************//
	 bool Checkwin4(char Player, bool GameOver)					  //checking the winner in 4*4
	 {
		for(int i = 0; i < 4; i++) 
		{               
			 if(ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2] && ar[i][2]==ar[i][3])				//checking by row
				 GameOver = true;
		}
		for(int i = 0; i < 4; i++)
		{                
			if(ar[0][i] == ar[1][i] && ar[1][i] ==  ar[2][i] && ar[2][i]==ar[3][i])				//checking by column
				GameOver = true;
		}
		if(ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[2][2]==ar[3][3])					//checking by diagonals
		{     
			GameOver = true;
		}
		if(ar[0][3] == ar[1][2] && ar[1][2] == ar[2][1] && ar[2][1]==ar[3][0])
		{
			 GameOver = true;
		}
		if(GameOver == true)						//if gameOver is true then winner is returned
		{
         printtable();
		 cout<<endl;
		 cout<<endl;
		 cout << "Player " << Player << " wins!\n\n";
         cout << "-----------------------" << endl;
         cout << "|   CONGRATULATIONS " << Player << " |\n";
         cout << "-----------------------" << endl << endl;
		}
		return GameOver;
   } 

	 //*********************************************************//
	 bool Checkwin5(char Player, bool GameOver)
	 {
		for(int i = 0; i < 5; i++) 
		{               
			 if(ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2] && ar[i][2]==ar[i][3] && ar[i][3]==ar[i][4])				//checking by row
				 GameOver = true;
		}
		for(int i = 0; i < 5; i++)
		{                
			if(ar[0][i] == ar[1][i] && ar[1][i] ==  ar[2][i] && ar[2][i]==ar[3][i] && ar[3][i]==ar[4][i])				//checking by column
				GameOver = true;
		}
		if(ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[2][2]==ar[3][3] && ar[3][3]==ar[4][4])					//checking by diagonals
		{     
			GameOver = true;
		}
		if(ar[0][4] == ar[1][3] && ar[1][3] == ar[2][2] && ar[2][2]==ar[3][1] && ar[3][1]==ar[4][0])
		{
         GameOver = true;
		}
		if(GameOver == true)									//if winner is true then winner is returned
		{
         printtable();
		 cout<<endl;
		 cout<<endl;
		 cout << "Player " << Player << " wins!\n\n";
         cout << "-----------------------" << endl;
         cout << "|   CONGRATULATIONS " << Player << " |\n";
         cout << "-----------------------" << endl << endl;
      }
		return GameOver;
   } 

	 //*********************************************************//
	bool CheckDraw(bool gameover)					//check if the game is a draw
	{
      int n = 1;
      int counter = 0;
      for(int i = 0; i < size; i++ )
	  {
         for(int j = 0; j < size; j++ )
		 {
            if(ar[i][j] == n)						//if any index is still available then counter is incremented 
			{ 
               counter++; 
            }
            n++;
         }
      }
	  if( counter < 1 )								//if counter is not incremented means no more index available so draw
	  {
		 cout<<"****************"<<endl;
         cout <<"|  ITS A DRAW  |"<<endl;
		 cout<<"****************"<<endl;
		 cout<<"\n\n"<<endl;
		 gameover=true;
      }
	  return gameover;
   }
		
}; 
void gamestart()				//start of the game
	{
		//system("cls");
		cout<<'\t'<<'\t'<<" *************************************"<<endl;
		cout<<'\t'<<'\t'<<" |       welcome to Tic-Tac-Toe      |"<<endl;
		cout<<'\t'<<'\t'<<" *************************************"<<endl;
		cout<<endl;
		cout<<"please select the format of the game "<<endl;    //level selection
		cout<<"1) 3*3 "<<endl;
		cout<<"2) 4*4 "<<endl;
		cout<<"3) 5*5 "<<endl;
		cout<<endl;
	}	

														//****** class ended here ******//
											//*************************************************************//
																//****MAIN****//

int main()
{
	system("color f5");						
	bool done=false;						//it will continue the game till the user ask to quit
	do	
	{
		gamestart();							//first time game is started here
		int choice1,size;
		cout<<endl;

		cout<<"press 1,2 or 3 "<<endl;				//level selection option
		cin>>choice1;
		if (choice1==1)							//assigning value in size
			size=3;								//size3
		else if (choice1==2)
			size=4;								//size4
		else if (choice1==3)
			size=5;								//size5
		else									//if other then 1,2 or 3 then it will take input again
			{
				cout<<"Wrong Choice. Start Over"<<endl;
				return 0;
			}

		TicTacToe obj1(size);				//object created of the size given
		int choice;							//for input of the number selected by X or O
		char player='O';					//first turn by player X
		bool gamecheck=false;				//gamecheck will tell if game is finshed and done will continue the game until it is finished
		while(true)
		{
			if (player=='X')				//player turn X or O
			{
				player='O';
			}
			else
			{
				player='X';
			}

			obj1.printtable();				//printing table
			cout<<endl;
			cout<<endl;
			cout<<"player "<<player<<" its your turn: "<<endl;
			cin>>choice;					//player choice number input
			obj1.playerturn(choice,player);
			if (size==3)
				gamecheck=obj1.Checkwin3(player,gamecheck);		//check win for size 3
			else if (size==4)
				gamecheck=obj1.Checkwin4(player,gamecheck);		//check win for size 4
			else if (size==5)
				gamecheck=obj1.Checkwin5(player,gamecheck);		//check win for size 5
			gamecheck=obj1.CheckDraw(gamecheck);				//check for draw
			if (gamecheck==true)
			break;												//if game ended break the loop
		}	
			if (gamecheck==true)								//try again
			{
				char choice;					
				cout<<"do you want to try again (y/n)? "<<endl;		//if Y or y then game started again
				cin>>choice;
				if (choice=='y' || choice=='Y')
				{
					system("pause");
					system("cls");
					done=false;
				}
				else if (choice!='y' || choice!='Y')				//else game ended
				{
					done=true;
					cout<<"Game Ended.Thank you for playing :-)"<<endl;
				}
			}
		}
	while (!done);						//waiting for done to be true
	return 0;
}

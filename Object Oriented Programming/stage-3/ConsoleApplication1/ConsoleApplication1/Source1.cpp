//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stdio.h>
//#include <time.h>
//
//using namespace std;
//
//class TicTacToe
//{
//private:
//	int **ar;					//initializing 2d array as data member
//	int size;					//size as data member
//
//public:
//
//	//*********************************************************//
//	TicTacToe(int size)               //constructor
//	{
//		int n = 1;
//		this->size = size;				//assigning the size passes
//		this->ar = new int *[size];				//dynamic array initializing
//		for (int i = 0; i<size; i++)
//		{
//			ar[i] = new int[size];
//			for (int j = 0; j<size; j++)
//			{
//				ar[i][j] = n;
//				n++;
//			}
//		}
//	}
//
//	//*********************************************************//
//	~TicTacToe()					//destructor
//	{
//		delete[]ar;					//deleting array for controlling memory leakage
//	}
//
//	//********************************************************//
//	void printtable()				//table print
//	{
//		system("cls");					//clear previous screen
//		for (int i = 0; i<size; i++)
//		{
//			for (int j = 0; j<size; j++)
//			{
//				if (ar[i][j] == 51)
//				{
//					cout << '\t' << " X ";			   //assigning X  (check player turn function)
//				}
//				else if (ar[i][j] == 52)
//				{
//					cout << '\t' << " O ";			//assigning O (check player turn function)
//				}
//				else
//					cout << '\t' << ar[i][j];
//				if (j<size - 1)
//				{
//					cout << '\t' << "|";
//				}
//			}
//			if (i<size - 1)
//			{
//				cout << endl;
//				for (int k = 0; k<size; k++)
//				{
//					cout << "________________";
//				}
//			}
//			cout << endl;
//		}
//	}
//
//	//********************************************************//
//	void playerturn(int choice, char player)				//turn of player X or O
//	{
//		bool wrong = true;
//		for (int i = 0; i<size; i++)
//		{
//			for (int j = 0; j<size; j++)
//			{
//				if (ar[i][j] == choice)					//if number choice number entered by user is available 
//				{
//					if (player == 'X')
//					{
//						ar[i][j] = 51;					// assigning 51 to X because array is int type
//					}
//					else if (player == 'O')
//					{
//						ar[i][j] = 52;					// assigning 52 to O because array is int type
//					}
//					wrong = false;
//				}
//			}
//		}
//		while (wrong == true)						// to mark for open sets only
//		{
//			cout << endl << "you can only mark open sets please try again " << endl;
//			cin >> choice;
//			for (int i = 0; i<size; i++)
//			{
//				for (int j = 0; j<size; j++)
//				{
//					if (ar[i][j] == choice)				//again check if available
//					{
//						if (player == 'X')
//						{
//							ar[i][j] = 51;					// assigning 51 to X because array is int type
//						}
//						else if (player == 'O')
//						{
//							ar[i][j] = 52;					// assigning 52 to O because array is int type
//						}
//						wrong = false;
//					}
//				}
//			}
//		}
//	}
//
//	//********************************************************//
//	void computerturn(int size1, char player)			//computer turn function
//	{
//		//bool wrong = true;
//		int count = 0;
//		count = 0;
//		for (int i = 0; i < size; i++)					//checking for rows if computer winning
//		{			
//			count = 0;
//			for (int j = 0; j < size; j++) 
//			{
//				if (ar[i][j] == 52)
//					count++;
//			}
//			if (count == size - 1)					//if two inputs by computer then mark at third
//			{
//				for (int j = 0; j < size; j++) 
//				{
//					if (ar[i][j] != 51 && ar[i][j] != 52)		//checking positions
//					{
//						ar[i][j] = 52;					//assign computer value
//						return;
//					}
//				}
//			}
//		}
//							//end of row checking
//		count = 0;
//		for (int j = 0; j < size; j++)				//checking for columns if computer winning
//		{				
//			count = 0;
//			for (int i = 0; i < size; i++) 
//			{
//				if (ar[i][j] == 52)
//					count++;
//			}
//			if (count == size - 1)				//if two inputs by computer then mark at third
//			{
//				for (int i = 0; i < size; i++) 
//				{
//					if (ar[i][j] != 51 && ar[i][j] != 52)			//checking positions
//					{
//						ar[i][j] = 52;				//assign computer value
//						return;
//					}
//				}
//			}
//		}
//
//							//end of column check
//		count = 0;
//		for (int i = 0, j = 0; i < size, j < size; i++, j++)			//checking left diagonal
//		{
//			if (ar[i][j] == 52)
//				count++;
//		}
//		if (count == size - 1)						//if two inputs by computer then mark at third
//		{
//			for (int i = 0, j = 0; i < size, j < size; i++, j++) 
//			{
//				if (ar[i][j] != 51 && ar[i][j] != 52) 
//				{
//					ar[i][j] = 52;				//assign computer value
//					return;
//				}
//			}
//		}
//
//						//end of left diagonal check
//		count = 0;
//		for (int i = 0, j = size - 1; i < size, j > 0; i++, j--)		//checking right diagonal
//		{
//			if (ar[i][j] == 52)
//				count++;
//		}
//		if (count == size - 1)					//if two inputs by computer then mark at third
//		{
//			for (int i = 0, j = size - 1; i <size, j > 0; i++, j--) 
//			{
//				if (ar[i][j] != 51 && ar[i][j] != 52) 
//				{
//					ar[i][j] = 52;				//assign computer value
//					return;	
//				}
//			}
//		}
//
//						//end of right diagonal check
//						//checking to stop player from wining the game// 
//
//		count = 0;
//		for (int i = 0; i < size; i++)				//rows checking
//		{			
//			count = 0;
//			for (int j = 0; j < size; j++) 
//			{
//				if (ar[i][j] == 51)
//					count++;
//			}
//			if (count == size - 1)						//if player wining then mark at third
//			{
//				for (int j = 0; j < size; j++) 
//				{
//					if (ar[i][j] != 51 && ar[i][j] != 52) 
//					{
//						ar[i][j] = 52;				//assign computer value
//						return;
//					}
//				}
//			}
//		}
//				
//						//end of rows check
//		count = 0;
//		for (int j = 0; j < size; j++)					//columns checking
//		{					
//			count = 0;
//			for (int i = 0; i < size; i++) 
//			{
//				if (ar[i][j] == 51)
//					count++;
//			}
//			if (count == size - 1)						//if player wining then mark at third
//			{
//				for (int i = 0; i < size; i++) 
//				{
//					if (ar[i][j] != 51 && ar[i][j] != 52) 
//					{
//						ar[i][j] = 52;			//assign computer value
//						return;
//					}
//				}
//			}
//		}
//						//end of columns check
//	
//		count = 0;
//		for (int i = 0, j = 0; i < size, j < size; i++, j++)		//left diagonal checking
//		{						
//			if (ar[i][j] == 51)
//				count++;
//		}
//		if (count == size - 1)						//if player wining then mark at third
//		{
//			for (int i = 0, j = 0; i < size, j < size; i++, j++) 
//			{
//				if (ar[i][j] != 51 && ar[i][j] != 52) 
//				{
//					ar[i][j] = 52;				//assign computer value
//					return;
//				}
//			}
//		}
//					//end of left diagonal check
//
//		count = 0;
//		for (int i = 0, j = size - 1; i < size, j > 0; i++, j--)		//right diagonal checking
//		{						
//			if (ar[i][j] == 51)
//				count++;
//		}
//		if (count == size - 1)				//if player wining then mark at third
//		{
//			for (int i = 0, j = size - 1; i <size, j > 0; i++, j--) 
//			{
//				if (ar[i][j] != 51 && ar[i][j] != 52) 
//				{
//					ar[i][j] = 52;			//assign computer value
//					return;
//				}
//			}
//		}
//					//end of right diagonal check
//
//								//if no one is wining or losing mark at random place//
//
//		while (true)
//		{						// to mark at random place
//			for (int i = 0; i < size; i++) 
//			{
//				for (int j = 0; j < size; j++) 
//				{
//					int random;
//					if (size == 3)			//generating random number of size 9
//					{
//						random = rand() % 9 + 1;
//					}
//					else if (size == 4)			//generating random number of size 16
//					{
//						random = rand() % 16 + 1;
//					}
//					else if (size == 5)			//generating random number of size 25
//					{
//						random = rand() % 25 + 1;
//					}
//					if (ar[i][j] == random)
//					{
//						if (player == 'X')
//						{
//							ar[i][j] = 51;					// assigning 51 to X because array is int type
//						}
//						else if (player == 'O')
//						{
//							ar[i][j] = 52;						// assigning 52 to O because array is int type
//						}
//					return;
//					}
//				}
//			}
//		}
//	}
//
//	//*********************************************************//
//	bool Checkwin(char Player, bool GameOver)			//checking the win and draw state of game
//	{               
//		int check = 0, k = 0, m = 0;
//		for (int i = 0; i < size; i++)				//to check rows win
//		{
//			for (int j = 0; j<size - 1; j++)
//			{
//				if (ar[i][j] == ar[i][j + 1])		//if 3 positions marked
//					check++;
//			}
//			if (check == size - 1)					//comparing
//			{
//				GameOver = true;
//			}
//			else
//				check = 0;
//		}
//		if (check == 0)
//		{
//			for (int j = 0; j < size; j++)			//to check columns win
//			{
//				for (int i = 0; i<size - 1; i++)
//				{
//					if (ar[i][j] == ar[i + 1][j])		//if 3 positions marked
//						check++;
//				}
//				if (check == size - 1)			//comparing
//					GameOver = true;
//				else
//					check = 0;
//			}
//		}
//		if (check == 0)			//Checking the left Diagonal win
//		{
//			for (int i = 0, j = 0; i<size - 1, j<size - 1; i++, j++)
//			{
//				if (ar[i][j] == ar[i + 1][j + 1])		//if 3 positions marked
//					check++;
//			}
//			if (check == size - 1)			//comparing
//				GameOver = true;
//			else
//				check = 0;
//		}
//		if (check == 0)      //Checking the right diagonal win
//		{
//			for (int i = 0, j = size - 1; j>0, i<size - 1; i++, j--)
//			{
//				if (ar[i][j] == ar[i + 1][j - 1])		//if 3 positions marked
//					check++;
//			}
//			if (check == size - 1)			//comparing
//				GameOver = true;
//			else
//				check = 0;
//		}
//		if (GameOver == true)			//if any player wins
//		{
//			printtable();
//			cout << "\n\nPlayer " << Player << " wins!\n\n";
//			cout << "-----------------------" << endl;
//			cout << "|   CONGRATULATIONS " << Player << " |\n";
//			cout << "-----------------------" << endl << endl;
//		}
//			//if no one wins check for draw
//
//		else {
//			int n = 1;
//			int counter = 0;
//			for (int i = 0; i < size; i++)
//			{
//				for (int j = 0; j < size; j++)
//				{
//					if (ar[i][j] == n)						//if any index is still available then counter is incremented 
//					{
//						counter++;
//					}
//					n++;
//				}
//			}
//			if (counter < 1)								//if counter is not incremented means no more index available so draw
//			{
//				cout << "****************" << endl;
//				cout << "|  ITS A DRAW  |" << endl;
//				cout << "****************" << endl;
//				cout << "\n\n" << endl;
//				GameOver = true;
//			}
//		}
//		return GameOver;
//	}
//
//		string currentDateTime() 
//{
//    time_t now = time(0);
//    struct tm  tstruct;
//    char buf[80];
//    tstruct = *localtime(&now);
//	strftime(buf, sizeof(buf), "%d/%m/%Y--%I:%M:%S-%p", &tstruct);
//    return buf;
//}
//
//	void savegame(ofstream &outf){
//		if (!outf) {
//			cout << "File is not Opened." << endl;
//		}
//		else{
//			string time4;
//			time4=currentDateTime();
//			for (int i=0;i<size;i++){
//				outf.write(reinterpret_cast<char*>(ar[i]), sizeof(int)*size);
//			}
//			outf.write(reinterpret_cast<char*>(size),sizeof(int));
//			outf.write(reinterpret_cast<char*>(&time4), sizeof(string));
//			cout<<"student stored in file "<<endl;
//			}
//		}
//
//	void loadgame(ifstream &in){
//		if (!in) {
//			cout << "File is not Opened." << endl;
//		}
//		else{
//		int id=1;
//		int check=0;
//		string time1;
//		int size1;
//		TicTacToe temp(size);
//		for (int i=0;i<size;i++){
//		in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);}
//		in.read(reinterpret_cast<char*>(&size1),sizeof(int));
//		in.read(reinterpret_cast<char*>(&time1),sizeof(string));
//		while(!in.eof()){
//			cout<<id<<'\t'<<time1<<endl;
//			for (int i=0;i<size;i++){
//				in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);}
//				in.read(reinterpret_cast<char*>(&size1),sizeof(int));
//				in.read(reinterpret_cast<char*>(&time1),sizeof(string));
//			id++;
//			check=1;
//		}
//		if (check==0){
//			cout<<"no record found in file"<<endl;
//			}
//		}
//	}
//
//	void deletegame(ifstream &in, int delchoice){
//		if (!in) {
//			cout << "File is not Opened." << endl;
//		}
//		int id2=1;
//		int check=0;
//		string time2;
//		int size2;
//		TicTacToe temp(size);
//		fstream outf1("copy.dat", ios::binary | ios::out | ios::app);
//		for (int i=0;i<size;i++){
//			in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);}
//		in.read(reinterpret_cast<char*>(&size2),sizeof(int));
//		in.read(reinterpret_cast<char*>(&time2),sizeof(string));
//		while(!in.eof()){
//			if (delchoice!=id2){
//				for (int i=0;i<size;i++){
//					outf1.write(reinterpret_cast<char*>(ar[i]), sizeof(int)*size);}
//					outf1.write(reinterpret_cast<char*>(size),sizeof(int));
//					outf1.write(reinterpret_cast<char*>(&time2), sizeof(string));
//					}
//			else{
//				check=1;
//				for (int i=0;i<size;i++){
//					in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);}
//				in.read(reinterpret_cast<char*>(&size2),sizeof(int));
//				in.read(reinterpret_cast<char*>(&time2),sizeof(string));
//				id2++;
//				}
//		}
//		in.close();
//		outf1.close();
//
//		remove ("game.dat");
//		rename ("copy.dat","game.dat");
//		if (check==1){
//			cout<<"record deleted"<<endl;
//			}
//	}
//	
//	TicTacToe selectgame(ifstream &in, int levchoice){
//		if (!in) {
//			cout << "File is not Opened." << endl;
//		}
//		int id3=1;
//		int count=0;
//		string time3;
//		int size3;
//		TicTacToe temp(size);
//		for (int i=0;i<size;i++){
//			in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);
//		}
//		in.read(reinterpret_cast<char*>(&size3),sizeof(int));
//		in.read(reinterpret_cast<char*>(&time3),sizeof(string));
//		while(!in.eof()){
//			if (levchoice==id3){
//				return temp;
//				count=1;
//			}
//		for (int i=0;i<size;i++){
//			in.read(reinterpret_cast<char*>(&temp), sizeof(int)*size);}
//		in.read(reinterpret_cast<char*>(&size3),sizeof(int));
//		in.read(reinterpret_cast<char*>(&time3),sizeof(string));
//		id3++;
//			}
//			if(count==0){
//			cout<<"no record found"<<endl;
//			}
//		}
//
//};
//int gamestart()				//start of the game
//{
//	cout << '\t' << '\t' << " *************************************" << endl;
//	cout << '\t' << '\t' << " |       welcome to Tic-Tac-Toe      |" << endl;
//	cout << '\t' << '\t' << " *************************************" << endl;
//	cout << endl;
//	char choicec=0;			//to check char
//	int choice_=0;	//to input choice
//	cout << "1. single player (human vs computer) " << endl;
//	cout << "2. two player (human vs human) " << endl;
//		do
//		{
//			cin>>choicec;
//			if (!isdigit(choicec))		//check if input is digit only not a character
//				cout<<"Wrong option selected, Enter again!"<<endl;		//if not try again
//			else if(isdigit(choicec) && choicec=='1')
//			{
//					choice_=1;		//if choice 1 then continue
//					break;
//			}	
//			else if (isdigit(choicec) && choicec=='2')
//			{
//					choice_=2;		//if choice 2 then continue
//					break;
//			}
//			else if (choice_!=1 &&  choice_!=2)		//if choice out of range then try again
//				cout<<"Wrong option selected, Enter again!"<<endl;	
//		}while(!isdigit(choicec) || choice_!=1 || choice_!=2 );
//											//first time game is started from here
//	cout << "please select the format of the game " << endl;    //level selection
//	cout << "1) 3*3 " << endl;
//	cout << "2) 4*4 " << endl;
//	cout << "3) 5*5 " << endl;
//	cout << endl;
//	return choice_;
//}
//
////****** class ended here ******//
////*************************************************************//
////****MAIN****//
//
//int main()
//{
//	//system("color 1f");
//	bool done = false;						//it will continue the game till the user ask to quit
//	do 
//	{
//		int choices=0;
//		TicTacToe obj1(3),obj2(3),obj3(3);
//		cout<<"1. load a saved game "<<endl;
//		cout<<"2. delete a saved game "<<endl;
//		cout<<"3. new game "<<endl;
//		cout<<"enter choice: ";
//		cin>>choices;
//		if (choices==1){
//			ifstream inf("game.dat", ios::binary | ios::in | ios::app);
//			obj3.loadgame(inf);
//			inf.close();
//		}
//			else if (choices==2){
//			}
//			else if (choices==3){
//			int choice_=gamestart();							
//			int choice1=0, size;
//			char choice1c=0;
//			int choices=0;
//			cout << endl;
//			cout << "press 1,2 or 3 " << endl;				//level selection option
//			do 
//			{
//				cin>>choice1c;
//				if (!isdigit(choice1c))			//if choice is not a digit
//					cout<<"Wrong option selected, Enter again!"<<endl;
//				else if(isdigit(choice1c) && choice1c=='1')
//				{
//					choice1=1;		//if 1 then continue
//					size=3;	
//					break;
//				}	
//				else if (isdigit(choice1c) && choice1c=='2')
//				{
//					choice1=2;		//if 2 then continue
//					size=4;
//					break;
//				}
//				else if (isdigit(choice1c) && choice1c=='3')
//				{
//					choice1=3;		//if 3 then continue
//					size=5;
//					break;
//				}				
//				else if (choice1!=1 &&  choice1!=2 && choice1!=3)		//if not then try again
//					cout<<"Wrong option selected, Enter again!"<<endl;	
//			
//			}while(!isdigit(choice1) || choice1!=1 || choice1!=2 || choice1!=3 );
//			
//			TicTacToe obj1(size);				//object created of the size given
//			int choice;							//for input of the number selected by X or O
//			char player = 'O';					//first turn by player X
//			bool gamecheck = false;				//gamecheck will tell if game is finshed and done will continue the game until it is finished
//			while (true)
//			{
//				if (choice_==2)				//if gameplay vs player
//				{
//					if (player == 'X')				//player turn X or O
//					{
//						player = 'O';
//					}
//					else
//					{
//						player = 'X';
//					}
//
//				obj1.printtable();				//printing table
//				cout << endl;
//				cout << endl;
//				cout << "player " << player << " its your turn: " << endl;
//				cin >> choice;					//player choice number input
//				obj1.playerturn(choice, player);		//player turn
//				gamecheck = obj1.Checkwin(player, gamecheck);		//check win for size 
//				if (gamecheck == true)
//					break;												//if game ended break the loop
//				}
//
//				else if (choice_==1)		//if game play vs computer
//				{
//					if (player == 'X')				//player turn X or O
//					{
//					player = 'O';
//					}
//					else
//					{
//					player = 'X';
//					}
//
//					obj1.printtable();				//printing table
//					cout << endl;
//					cout << endl;
//					if (player == 'X') 
//					{
//						cout << "human: select a location: " << endl;
//						cin >> choice;					//player choice number input
//						obj1.playerturn(choice, player);
//					}
//					else if (player == 'O') 
//					{
//						obj1.computerturn(size, player);	//computers turn
//					}
//					gamecheck = obj1.Checkwin(player, gamecheck);		//check win for size 
//					if (gamecheck == true)
//						break;	
//					}
//				}															//if game ended break the loop
//			if (gamecheck == true)								//try again
//			{
//				char choice;
//				cout << "do you want to try again (y/n)? " << endl;		//if Y or y then game started again
//				cin >> choice;
//				if (choice == 'y' || choice == 'Y')
//				{		
//					system("cls");
//					done = false;
//				}
//				else if (choice != 'y' || choice != 'Y')				//else game ended
//				{
//					done = true;
//					cout << "Game Ended.Thank you for playing :-)" << endl;
//				}
//			}
//			}
//		} while (!done);						//waiting for done to be true
//	return 0;
//}
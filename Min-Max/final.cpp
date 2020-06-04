#include<iostream>
using namespace std;
int index1;
char board[9] = {};

void drawboard(){
	for (int i=0;i<9;i++){
		board[i]='*';
	}
}

void draw_board() //display tic-tac-toe board
{
    cout<<endl;
    cout<<'\t'<<board[0]<< '\t' << "|"<<'\t'<<board[1]<< '\t' << "|"<<'\t'<<board[2]<<endl;
    cout << "______________________________________________"<<endl;
    cout<<'\t'<<board[3]<< '\t' << "|"<<'\t'<<board[4]<< '\t' << "|"<<'\t'<<board[5]<<endl;
    cout << "______________________________________________"<<endl;
    cout<<'\t'<<board[6]<< '\t' << "|"<<'\t'<<board[7]<< '\t' << "|"<<'\t'<<board[8]<<endl;
}


int isFull()// Board is full
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X')
        {
            if(board[i]!='O')
               {
                 return 0;
               }
        }
    }
return 1;
}

int user_won()//Checks whether user has won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
    {
        return 1;
    }
    return 0;
}

int cpu_won()// Checks whether CPU has won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
    {
        return 1;
    }
    return 0;
}

int minimax(bool flag)// The minimax function
{

    int max_val=-1000,min_val=1000;
    int i,j,value = 1;
    if(cpu_won() == 1)
        {return 10;}
    else if(user_won() == 1)
        {return -10;}
    else if(isFull()== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};//if score[i]=1 then it is empty

        for(i=0;i<9;i++)
            {
                 if(board[i] == '*')
                {
                    if(min_val>max_val) // reverse of pruning condition.....
                  {
                      if(flag == true)
                   {
                     board[i] = 'X';
                     value = minimax(false);
                   }
                    else
                    {
                      board[i] = 'O';
                      value = minimax(true);
                    }
                  board[i] = '*';
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 max_val = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > max_val && score[j] != 1)
                    {
                        max_val = score[j];
                        index1 = j;
                    }
                }
                return max_val;
        }
        if(flag == false)
        {
                min_val = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < min_val && score[j] != 1)
                    {
                        min_val = score[j];
                        index1 = j;
                    }
                }
            return min_val;
        }
}

void gamestart()                //start of the game
{
    cout <<'\t'<< '\t' << '\t' << " *************************************" << endl;
    cout <<'\t'<< '\t' << '\t' << " |       welcome to Tic-Tac-Toe      |" << endl;
    cout <<'\t'<< '\t' << '\t' << " *************************************" << endl;
    cout << endl;
    cout << endl;
    cout<<"USER----->(O)"<<endl;
    cout<<"CPU------>(X)"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"SELECT: "<<endl;
    cout<<"1-> Player first  "<<endl;
    cout<<"2-> CPU first  ";
    cout<<endl;
}

int main() //The main function
{
    bool done=false;
    do{
    drawboard();
	gamestart();
   int move,choice;
   cin>>choice;
   if(choice == 1)
   {
        system("pause");
        system("cls");
       draw_board();
        up:cout<<endl<<"Your Move:  "<<endl;
         cin>>move;
         if(board[move-1]=='*')
         {
           board[move-1] = 'O';
            system("cls");
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move";
             goto up;
         }
   }
    while(true)
    {
        cout<<endl<<"CPU MOVE.... "<<endl;
        minimax(true);
        board[index1] = 'X';
        system("pause");
        system("cls");
        draw_board();
        if(cpu_won()==1)
        {
            cout << "\n\nYou " << " lose!\n\n";
            cout << "-------------------" << endl;
            cout << "|   Try Again!!! " << " |\n";
            cout << "-------------------" << endl << endl;
            break;
        }
        if(isFull()==1)
        {
            cout << "****************" << endl;
            cout << "|  ITS A DRAW  |" << endl;
            cout << "****************" << endl;
            break;
        }
again:  cout<<endl<<"Your Move:  "<<endl;
        cin>>move;
        if(board[move-1]=='*')
         {
           board[move-1] = 'O';
        system("cls");
           draw_board();
         }
         else
         {
             cout<<endl<<"Invalid Move......Try different move"<<endl;
             goto again;
         }
         if(user_won()==1)
         {
            cout << "\n\nYou " << " wins!\n\n";
            cout << "-----------------------" << endl;
            cout << "|   CONGRATULATIONS " << " |\n";
            cout << "-----------------------" << endl << endl;
             break;
         }
         if(isFull() == 1)
        {
            cout << "****************" << endl;
            cout << "|  ITS A DRAW  |" << endl;
            cout << "****************" << endl <<endl;
            break;
        }
    }
        char choicee;
        cout << "do you want to try again (y/n)? " << endl;     //if Y or y then game started again
        cin >> choicee;
        if (choicee == 'y' || choicee == 'Y')
        {       
            system("cls");
            done = false;
        }
        else if (choicee != 'n' || choicee != 'N')                //else game ended
        {
            done = true;
            cout << "Game Ended.Thank you for playing :-)" << endl;
        }            
        } while (done!=true);                        //waiting for done to be true

}

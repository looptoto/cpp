/*
lolaproject1.cc
author:lola
date 2012-12-5
base on ttt.cc


this program can play tic tac toe
player move first
then the peogram will generate next step automatically

lola will high-light the changed part, and use memo to mention next change part;
enjoy games! , although this program is not smart enough!

the first add locate at line 77
*/ 


/* ttt.cc -- Program to play tic tac toe

   Author: Larry Morell

   Modification History
   Date        Action
   11/07/12  -- Original version, translated from the stage3 algorithm


   Stage 1 algorithm

   o Set up the board
   o Print the directions
   o Print the initial board

   Stage 2: Define our basic operations on the playing board

   Stage 3: Implement the user interaction and the main algorithm
   convertRC2position(r,c) = position on the internal board
      Representation for the board
      The board has 9 squares.  Each square can hold an 'X', an 'O' or a ' ' (a space
      The easiest way of representing a collection of 9 values is to put them
      in a list of length 9.  So an empty board will be represented by:

      Let board name
    < 
      ' ', ' ', ' ',    # row 1
      ' ', ' ', ' ',    # row 2
      ' ', ' ', ' '     # row 3
    >


       Note that there are 9 values here in a row. we will have to figure out
       how to translate (row, col) coordinates to access the appropriate values.
       Basically, given (row, col) (each betweeen 1 and 3) we use the formula

        Let n name 3*(row-1) + col

       to get to the corresponding index `n' in `board'

       Thus for (2,3)  n = 3*(2-1) + 3 = 6.

       Given square `n' (1 <= `n' <= 9) the corresponding (row,col) is computed
       by:

        Let row name quotient of (n+3) divided by (3)
        Let col name remainder of (n-1) divided by (3) + 1

       Thus for n=6,  

        row = quotient of (6+3) divided by (3) = 2
        col = remainder of (6-1) divided by (3) + 1 = 2+1 = 3

*/
#include <fstream>      //for create score records  
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>  // this two title will be used to generate random number 
                // Add_2 line 382 and at line 194 
		// I changed a little part of direction

using namespace std;

const bool DEBUG = false;
/*
   Let convertRC2position(r,c) name
   Function {
      Let n name 3*(r-1) + c
      Return n
   }
*/

int convertRC2Position (int r, int c) {
     int n = 3*(r-1) + c;
     return n;
}
/*
   Let convertPosition2Row (n) name
   Function {
      Let ans name  integer((n-1)/3) + 1
      Return ans
   }
*/
   int convertPosition2Row (int n) {
      int ans =  ((n-1)/3) + 1;
      return ans;
   }
/*
   Let convertPosition2Col (n) name
   Function {
       Return (n-1) % 3 + 1

   }
*/
   int convertPosition2Col (int n) {
      return (n-1) %3 + 1;
   }

/*
   Let Set(alias board, r, c, mark) name 
   Procedure {
       Let n name convertRC2Position(r,c)
       Let board[n] name mark
   }
*/

   void set(string &board, int r, int c, char mark) {
      int n = convertRC2Position(r,c);
      board[n] = mark;
   }

/*
   # Set up a board of 9 squares
   Let CreateBoard (alias board) name 
   Procedure {
      Let board name 
       < 
         ' ', ' ', ' ',    # row 1
         ' ', ' ', ' ',    # row 2
         ' ', ' ', ' '     # row 3
       >
   }
*/
void createBoard (string &board) {
   board = "          ";  // 10 spaces
}

/*
   Let DisplayBoard (board) name
   Procedure {
       Echo " ", board[1], " | ", board[2], " | ", board[3], "\n"
       Echo "------------\n"
       Echo " ", board[4], " | ", board[5], " | ", board[6], "\n"
       Echo "------------\n"
       Echo " ", board[7], " | ", board[8], " | ", board[9], "\n"
   }
*/

void displayBoard (string board) {
       cout << " " << board[1] << " | " << board[2] << " | " << board[3] << "\n";
       cout << "------------\n";
       cout << " " << board[4] << " | " << board[5] << " | " << board[6] << "\n";
       cout << "------------\n";
       cout << " " << board[7] << " | " << board[8] << " | " << board[9] << "\n";
   
}
/*
   Let DisplayDirections () name 
   Procedure {
      Print "Directions for TicTacToe" 
      Print "
   This project implements a game of TicTacToe to be played by two people.

   The game is played on a 3 x 3 board, as in:
   =>
      |   |
   -----------
      |   |
   -----------
      |   |

   There are three rows (horizontal), three columns (vertical), and two diagonals
   (the forward diagonal: \ and the backward diagonal /).

   The grid is initially empty. Player 1 uses the X mark; player 2 uses the O mark. Players alternate turns.  During each turn
   a player places his or her mark on an empty square.   The game halts soon as either of the following conditions hold: 

   o A player has three marks in the same row, column or diagonal. That player is declared to be the winner.
   o All squares are filled and no player has three marks in the same row, column or diagonal.  That game is declared to be 'cat' and there is no winner.

   "

   }
*/ // CHANGe RULE
   void displayDirections () {cout<<endl<<endl<<endl;
   cout << "Directions for TicTacToe__Confident type"  << endl<<endl;
   cout << "This project implements a game of TicTacToe to be played just by\n YOUSELF." << endl<<endl;;

   cout << "  The game is played on a 3 x 3 board, as in:" << endl;
   cout << "   |   |" << endl;
   cout << "-----------" << endl;
   cout << "   |   |" << endl;
   cout << "-----------" << endl;
   cout << "   |   |" << endl;

   cout << " There are three rows (horizontal), \n  three columns (vertical),\n and two diagonals" << endl;
   cout << "  (the forward diagonal: \\ \n  and the backward diagonal /)." << endl;

   cout << "  The grid is initially empty. \n  Player  uses the X mark; Computer uses the O mark.\n  after player move the cp will generate next step. " << endl;
   cout << "  a player places his or her mark on an empty square.   The game halts soon as either of the following conditions hold: " << endl;

   cout << "o  if three marks in the same row, column or diagonal. the game will finished" << endl<<endl;
   cout << "o  All squares are filled and no player has three marks in the same row, column or diagonal.  \n   That game is declared to be 'cat' and there is no winner." << endl<<endl<<endl;
   cout<< "The reason why I call it confident type that computer will try it best to let u win the game.\n  how about chage a little bit of rule, that do you best to let computer win .\n  that sound good,\n   maybe we will have an rank for u.\n  it coming soon..."<<endl;

   }

/*
   Let getVal(board, r,c) name
   Function {
       Let n name convertRC2Position(r,c);
       Return board[n]
   }
*/

char getVal(string board, int r,int c) {
    int n = convertRC2Position(r,c);
    return board[n];
}
/*
   Let getRow(board,r) name
   Function {
      Generate each(c) from 1 to 3
      [+]
    @first: Let ans name ""
    @iter:  Let ans name ans + getVal(board,r,c)
      Return ans
   }
*/

string getRow(string board, int r) {
   string ans; int c;
   for (ans = "",c=1; c <=3; c++) 
       ans = ans + getVal(board,r,c);
   return ans;
}

/*
   Let getCol(board,c) name
   Function {
      Generate each(r) from 1 to 3
      [+]
         @first: Let ans name ""
         @iter:  Let ans name ans + getVal(board,r,c)
      Return ans
   }
*/

   string getCol (string board, int c) {
   string ans; int r;
   for (ans = "",r=1; r <=3; r++) 
       ans = ans + getVal(board,r,c);
   if (DEBUG) cout << "getCol: returns" << ans << endl;
   return ans;

   }
/*
 let getDia1(board) name
Function {
generate each (L) from 1 to 3
[+]
@f: let ans name ''
@i: let ans name ans+getVal(board,L,L)
return ans
} */

string getDia1(string board) {
string ans; int l;
 for ( ans = "" , l=1; l<=3; l++)
	 ans = ans+getVal(board,l,l);
 if (DEBUG) cout << "getDia1: returns" << ans << endl;
 return ans; }

/*
let getDia2(board) name function
{
generate each (L) from 1 to 3
[+]
@f: let ans name ''
@i: let ans name ans+getVal(board,L,4-L)
return ans

}

*/


string getDia2(string board) {
string ans; int l;
 for ( ans = "", l=1; l<=3; l++)
          ans = ans+getVal(board,l,4-l);
  if (DEBUG) cout << "getDia2: returns" << ans << endl;
	   return ans; }


/*
   Let threeInARow (line) name
   Function {
      Return line = "XXX" or line = "OOO"
   }
*/

bool threeInARow (string line) {
   return line == "XXX" or line == "OOO";
}

/*
   Let checkWin (board) name
   Function {
       Generate each(n) from 1 to 3
       [+]  When threeInARow(getRow(board,n)) 
       or threeInARow(getCol(board,n))
       @first: Let ans name false
       @iter: Let ans name true
       
   select # check win for two diagonals

   threeInARow(getDia1(board)) or  threeInARow(getDia2(board)) -> let ans name true
          Return ans

       }
*/

bool checkWin (string board) {
   int n; 
   bool ans;
   for (ans = false, n=1; n<=3; n++) {
      if ( threeInARow(getRow(board,n))
        || threeInARow(getCol(board,n)))  
        ans = true;}
  
      if(threeInARow(getDia1(board))|| threeInARow(getDia2(board))    )
   ans =true;
   return ans;
}
/*
   Let allFilled (board) name
   Function {
       Generate each(b) from board until b = ' '  # Linear search
       Select 
     on(b) -> Let ans name false
     otherwise -> Let ans name true
       Return ans
   }
*/

   bool allFilled (string board) {
      int b; 
      bool ans;
      for (b=1;b<=9 && board[b] != ' ';b++);
      if (b <= 9) 
         ans = false;
      else
         ans = true;
      return ans;
   }

/*
   Let checkCat (board) name
   Function {
      Return not checkWin(board) and allFilled(board)
   }

*/
   bool checkCat (string board) {
      return ! checkWin(board) && allFilled(board);
   }
// Add_2 
 /*
 add 1 make a list to lead computer move= cpmove
 *********************************************
 */


 /*let  makecpmove(alias cpmove) name
 procedure{
 let cpmove name <>
 generate each(n) from 1 to 9
 [+]
 append n onto cpmove
}
 */

 void makecpmove(int cpmove[], int cpsize)
    {
       int index;
        for (index=0;index<cpsize;index++)
               cpmove[index]=index+1;
}

/*
 * add 2 delete movementfrom cpmove
 * ********************************
 * */
/*let DltMoveFromCp(alias cpmove, r,c) name
  Procedure{
     let n name  convertRC2Position(r,c)
      generate each(cp) from cpmove
      [+] when (cp=n)
          delete cp
#     print 'rc_h' cpmove
                      }*/


void DltMoveFromCp(int a[],int &size,int r, int c)
{ int i;
	  int n=convertRC2Position(r,c);
    for (i=size-1;a[i]!=n;i--);// linear search int n without body
      while (i<size-1)
      {
        a[i]=a[i+1];
	  i++;    
      }
   size--;
}

//creat print array used for testing
void printArray(int list[], int size)
   {
     int index;
     for (index=0;index<size;index++)
     cout<<list[index]<<" ";
    }
      //from page 499

// in genesis there is a setp called count cpmove, in .cc we have size,
// I just use size instand of count 
// Notice: count = size; index=size-1;
/*
 #3.a count cpmove list**********************
       let cntcp(alias cpmove) name
          Function{
          generate each (cp) from cpmove
           [+]
             @f: let cnt name 0
             @i: let cnt name cnt+1
            return   cnt
  */ 

//3.b make computer move by random this number will be used as subscript*
/*
 let cpm(alias cpmove,t)name
   Function{
       let cpm  name random()%t+1
       return cpm
            }

*/
// there is no relationship with cpmove list
// just need a random number.

int random(int size)
{
srand(time(NULL));
int ans=rand()%size;
return ans;
}
/*
void setuprand() {
  struct timeval tv; struct timezone tz;
    gettimeofday(&tv, &tz);
      srand(tv.tv_usec);
      }
it is working at oringinal program , but it not work here
so i change to use 2104-lab12.cc
Notice:  the number create by random is between 0 to size-1
it can directlly use as index.

*/

//3.c Generate the real step for computer
/*
 let cpstep(alias cpmove,cpm) name
      Function{
          let cpstep name iterator(cpmove[cpm])
          return cpstep
           }
*/

 int cpstep ( int cpmove[],int cpm)
    {
      int ans;
      ans= cpmove[cpm];
      return ans;
    }
//3.d
//delete cpstep from cp list
/*
let Delcpm(alias cpmove,n) name
     Procedure{
      generate each(cp) from cpmove
      [+] when (cp=n)
          delete cp
          print cpmove
        }

*/

void Delcpm(int cpmove[],int &size,int n)
{ while (n<size-1)
    {
    cpmove[n]=cpmove[n+1];
    n++;
    }
  size--;
}

//here!!! n=cpm!!! there is a little different between genesis,
//since I already know the location, so it doesn't need do linear search

//4 make the computer steps, it contains random number, 
//delete computer number, 
//set the mark on the board;

/*let cpSet(alias board,alias cpmove, mark)name
    Procedure {
    let t name  cntcp(cpmove)
    let cpm name    cpm( cpmove,t)
    let n name cpstep(cpmove,cpm)
    let board[n] name mark
    Delcpm( cpmove,n)
*/
void cpSet(string &board,int cpmove[], int &size,char mark)
     {int t= random(size);
      int n= cpstep(cpmove,t);
          board[n]= mark;
      Delcpm(cpmove,size,t);
      }

// the added parts finished they are all from stic.cc (boole rpeng)

// adjust main function 
//add score record



/*
   # Main algorithms (stage 3 proper)
   Let moves name < 
       <[1 1] [2 2] [3 3 ] [3 1] [ 1 3] [2 3] [ 1 2] >
       < [1 1] [1 2] [1 3] [2 2] [3 1] [3 2] >
       < [1 1] [1 2] [1 3] [2 2] [3 2] [3 1] [2 1] [2 3] [3 3]>
   >
   CreateBoard(board)
   Generate each(moveList) from moves 
   [+] {
       Generate each(move) moveList
       until checkWin(board) or checkCat(board)
       [+]
     @first: {
        Let player name 'X'
        Print "Game started"
        CreateBoard(board)
     }
     @iter: {
         Set (board, move[1], move[2], player)
         Print "After" player "plays at (" move[1] "," move[2] "):"
         DisplayBoard(board)
         Select
       player = 'X' -> Let player name 'O'
       player = 'O' -> Let player name 'X'
     }
     Select
         player = 'X' -> Let player name 'O'
         player = 'O' -> Let player name 'X'

     Select 
        checkWin(board) -> {Print "Player" player " WON!"}
        checkCat(board) -> {Print "Game was a cat"}
        otherwise -> Print "Insufficient moves, no one has won or lost!"
   }
*/

int main () {
	 string board;
   char player;
   char ans;
   int  move1, move2;
   int  cpmove[9];//creat computer move array
   int const ruler=0;// ruler is using  for reset record list array
   int const lola=9;// it should be named as size lola is quite lazy so..
  //  ifstream infile ("records.dat");// open date file;
     /* Looks like
       34 Larry
       44 Fred
       12 Lola
     */
    
   displayDirections();
   do{
  //  int count[100];
  //  string name[100];
  //  int rsize=0 ;                                               //create 2 arraies one for count win, one for player's name
  //  while (infile >> count[rsize] >> name[rsize] ) rsize++;     // insert data into array
  //       infile.close();                                       //close date file.
  //   string playerName;
                                                                 //memo: rsize is the index, the real size of name and count is rsize+1
								 //      infile.close();                                             //close date file.
								 //      string playerName;
								               
      player = 'O';
      cout << "Game started" << endl;
      createBoard(board);
      int size =lola;                                           // when start game again make sure the size back to 9!! 
                                                                //it an important point!!
      makecpmove(cpmove,size);
      do {
	      if (player=='O')
            //cout<<"you got here"<<endl;                                 // use this to check  where have problem 
	       {       player='X';
	               cout << "Enter move for player " << player << ":"; 
                       cin >> move1 >> move2;
                       cout << "YOu entereed " << move1 << ' ' << move2 << endl;
			   if (move1<1||  move1>3) // the number of Row is illegal
				  {  
				  cout<<"please enter the number of Row between 1 and 3."<<endl;      
	 			   player = 'O';
				  }
     			   else if (move2<1 || move2>3) // the number of column is illegal
         			 {  
				  cout<<"please enter the number of Column  between 1 and 3."<<endl;  
	  			 player = 'O';
				 }
     			   else if (getVal(board,move1,move2)=='X')
         			 {  
		  		   cout <<"the square ("<< move1<<","<< move2 << ") is filled by 'X' Please enter again. "<<endl; 
	 			  player = 'O';}
		          else if (getVal(board,move1,move2)=='O')  
          			{  
		  		   cout <<"the square ("<< move1<<","<< move2 << ") is filled by 'O' Please enter again. "<<endl; 
	 			  player = 'O';}
                         /* else if (move1!= int or move2!=int)
			         {
				 cout<<"number please!";
				  player = 'O';
				 }
				 */
 		         else if (getVal(board,move1,move2)==' ')

	  	             {  
			  set (board, move1, move2, player);
          		  DltMoveFromCp(cpmove,size,move1,move2);
          	   	  cout <<"After " << player  <<" plays at (" 
                	  << move1 << ","  << move2 << "):" << endl;
                 		 displayBoard(board);
    	          		  if ( checkWin(board))                                 // just need check win and check cat before computer move
	 	     		  {cout << endl;}       //"Player " << player << " WON!" << endl;}
                  		  else if ( checkCat(board) )
	              		 {cout << endl;}       //"Game was a cat" << endl;   
                 		  else
	           	 	 {
		   		 player='O';
	        	         cpSet(board, cpmove, size,player);
		                 cout<<"Computer move:"<<endl;
		   		 displayBoard(board);
		                 } 
	                       }
      			 else 
           		cout<<"Do not do useless thing, please.";	// WERN!! this is not working for control input, Icannot figure out       
          } 
      } while ( !( checkWin(board) || checkCat(board)));
//         if ( player == 'X') 
//        player = 'O';
//         else   
//        player  = 'X';
  //   when program stop the winer is player
        if ( checkWin(board)) 
           {cout << "Player " << player << " WON!" << endl;}
        else if ( checkCat(board) ) 
           {cout << "Game was a cat" << endl;}
      
      
      char ansr;
       if(checkWin(board)and player=='O')//if player win the program will ask the follow question . 
		                                // Memo: we can make it interesting by changing 'X' to 'O', 
	      {	
		      do{				// when  player let computer win,we will ask question.
                 	cout<<"Do you want save record?(y/n)";
                 	cin>>ansr;
	       		cout<<endl;
              
		        }while(ansr !='y'and ansr!='n');// check answer
	              if (ansr=='n')
			  {
	//		   ofstream outfile ("records.dat");// output data
        //                  int cm;
        //                  for (cm=0; cm <=rsize; cm++)
        //                  { outfile << count[cm] << ' ' << name[cm] << endl; }
         //                  outfile.close();	 
	                  cout<<"next question ->"<<endl;
			  }  
		 
		     else if (ansr=='y')
	                 { 
			   int count[100];
		           string name[100];
	                   int rsize= ruler ;  
                      	   ifstream infile ("records.dat");// open date file;
		           while (infile >> count[rsize] >> name[rsize] ) rsize++;     // insert data into array
		           infile.close(); 
		      
		       cout << "Your name please [not more than 15 chars]:" ;
		        string playerName;
		        cin >> playerName;
		        int playerPos;
		      for (playerPos=0; playerPos <= rsize && name[playerPos] != playerName; playerPos++);//find player name in the name array, if not find ,
		     											  // pick up player's name and count
			                                                                                  //we will create new name in the name array
 		        int PLcount;
		   	if(playerPos<rsize)// rsize=index size of array =rsize +1
			  {
		 		count[playerPos] ++;
		     	 	PLcount=count[playerPos];
			   }
			
			else if (playerPos>=rsize)
			  { 
		          rsize++;
			  count[rsize] = 1;
                          name[rsize] = playerName;  
			  PLcount=1;
			  }
		     /*    ofstream outfile ("records.dat");// output data
	                 int cm;
	                 for (cm=0; cm <=rsize; cm++)
	                      { outfile << count[cm] << ' ' << name[cm] << endl; }
	                          outfile.close();
*/  // sort first then put records back to the dat file
		     // sorting 2 list
                   int sot;                            //generate each sot from rlist
		                                        //[+]
							//generate each ot from next(sot)
							//[+] when (sot<ot)
							//#switch
							//let t name sot
							//sot=ot
							//ot=t
		  for (sot=0;sot<rsize;sot++)
		  {
		   if (count[sot]<count[sot+1])
		    {
		    int tem;
		    string tems;
		    int h=sot;
		    int k=sot+1;
		    tem =count[h];
		    count[h]=count[k];
		    count[k]=tem;
		    tems=name[h];
		    name[h]=name[k];
		    name[k]=tems;    
		    }
		  }
                    
		  
		  //show the rank top 3 and player
		  fstream outfile ("records.dat");// output data
		  int cm;
		  for (cm=0; cm <=rsize; cm++)
		  { outfile << count[cm] << ' ' << name[cm] << endl; }
		  outfile.close();
		    int show;
		   cout<<"Top Three "<<endl;
		    for (show=0;show<3;show++)
		    {
		    cout<<setfill(' ')<<setw(15)<<name[show]<<setw(5)<<setfill('.')<<count[show]<<endl;
		    } 
		    cout<<"your are here~"<<endl;
		    cout<<setfill(' ')<<setw(15)<<playerName<<setw(5)<<setfill('.')<<PLcount<<endl;
	        }
	      } 
        do {  cout << "Do you want to play another game? (y/n) ";

           cin >> ans;
         } while (ans != 'y' && ans != 'n');// neither y nor n the question will ask again
	} while (ans == 'y');
cout<<endl<<"see you next time~!"<<endl;
return 0;
}
// Your receipt number is 31214-46022.

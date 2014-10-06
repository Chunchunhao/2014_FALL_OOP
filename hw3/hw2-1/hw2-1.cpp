#include <iostream>

using namespace std;

int main () 
{
  int* table = new int[9];
  char* player = new char[3];
  player[0] = ' ';
  player[1] = '0';
  player[2] = 'X';

  // Begining Intro
  cout << "請遵循以下數字鍵入區塊名稱" << endl;
  cout << "1|2|3" << endl << "-*-*-*" << endl;
  cout << "4|5|6" << endl << "-*-*-*" << endl;
  cout << "7|8|9" << endl;

  int winner = 0, turn = 2 , choice, run=0; // 2: X, 1: 0
  do { 
    // Loop Choice
    char c = (turn == 2 ? 'X' : '0') ;
    cout << "輪" << c << "方下..." << endl;
    cout << "請輸入區塊號碼(1~9):" ;
    cin >> choice;
    
    // Wrong input
    if( choice < 1 || choice > 9 ) {
      cout << "要輸入正確數字哦!!請重新選擇" << endl;
      cout << "1|2|3" << endl << "-*-*-" << endl;
      cout << "4|5|6" << endl << "-*-*-" << endl;
      cout << "7|8|9" << endl;
      continue;
    }
    
    // Can't choice
    if( table[choice-1] != 0 ){
      cout << "這一格不能下哦!!請重新選擇" << endl;
      cout << "1|2|3" << endl << "-*-*-" << endl;
      cout << "4|5|6" << endl << "-*-*-" << endl;
      cout << "7|8|9" << endl;
      continue;
    }

    // Make Choice
    table[choice-1] = turn;
    switch(choice-1){
      case 0:
        if( table[1] == turn && table[2] == turn )
          winner = turn;
        else if( table[3] == turn && table[6] == turn)
          winner = turn;
        else if( table[4] == turn && table[8] == turn)
          winner = turn;
        break;
      case 1:
        if( table[0] == turn && table[2] == turn )
          winner = turn;
        else if( table[4] == turn && table[7] == turn)
          winner = turn;
        break;
      case 2:
        if( table[1] == turn && table[0] == turn )
          winner = turn;
        else if( table[5] == turn && table[8] == turn)
          winner = turn;
        else if( table[4] == turn && table[6] == turn)
          winner = turn;
        break;
      case 3:
        if( table[4] == turn && table[5] == turn )
          winner = turn;
        else if( table[0] == turn && table[6] == turn)
          winner = turn;
        break;
      case 4:
        if( table[3] == turn && table[5] == turn )
          winner = turn;
        else if( table[1] == turn && table[7] == turn)
          winner = turn;
        else if( table[0] == turn && table[8] == turn)
          winner = turn;
        else if( table[2] == turn && table[6] == turn)
          winner = turn;
        break;
      case 5:
        if( table[2] == turn && table[8] == turn )
          winner = turn;
        else if( table[3] == turn && table[4] == turn)
          winner = turn;
        break;
      case 6:
        if( table[0] == turn && table[3] == turn )
          winner = turn;
        else if( table[7] == turn && table[8] == turn)
          winner = turn;
        else if( table[2] == turn && table[4] == turn)
          winner = turn;
        break;
      case 7:
        if( table[1] == turn && table[4] == turn )
          winner = turn;
        else if( table[6] == turn && table[8] == turn)
          winner = turn;
        break;
      case 8:
        if( table[2] == turn && table[5] == turn )
          winner = turn;
        else if( table[6] == turn && table[7] == turn)
          winner = turn;
        else if( table[0] == turn && table[4] == turn)
          winner = turn;
        break;
      default:
        cerr << "Program crash!!" << endl;
        return -1;
    }
    // tie
    run ++;
    
    // Print table
    cout << "<遊戲盤>" << "              請循序以下數字鍵輸入區塊名稱" << endl;
    for( int i=0; i<9; i=i+3) {
      cout << player[table[i]] << '|' 
           << player[table[i+1]] << '|' 
           << player[table[i+2]] 
           << "                  "
           << i+1 << "|"
           << i+2 << "|"
           << i+3 
           << endl;
      
      if( i!= 6 )
        cout << "-*-*-" << "                  -*-*-" << endl;
    }
    // Change
    turn = (turn == 1 ? 2 : 1); 
  } while( winner == 0 && run < 9);

  // Result
  if( winner == 0 )
    cout << "和局!" << endl;
  else
    cout << "由\"" << player[winner] << "方\"獲勝!!!" << endl;
  return 0;
}


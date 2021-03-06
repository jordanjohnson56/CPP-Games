//#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "board.h"
using namespace std;

Board::Board() {
  pieces = new int[9];
  size = 0;
  for(int i = 0; i < 9; i++) {
    this->pieces[i] = 0;
  }
  //this->draw();
}

void Board::draw() {
  stringstream ss;
  system("cls");
  string board[9][3];
  for(int i=0;i<9;i++) {
    if(pieces[i]==1) {
      board[i][0] = "\\ /";
      board[i][1] = " X ";
      board[i][2] = "/ \\";
    } else if(pieces[i]==2) {
      board[i][0] = "/ \\";
      board[i][1] = "| |";
      board[i][2] = "\\ /";
    } else {
      ss.clear();
      ss.str("");
      ss << " " << i+1 << " ";
      board[i][0] = "   ";
      board[i][1] = ss.str();
      board[i][2] = "   ";
    }
  }
  for(int i=0;i<3;i++) {
    for(int j=0;j<4;j++) {
      int mult = 3 * i;
      if(j<3) {
        cout
        << setw(1)
        << " "
        << setw(3)
        << board[mult][j]
        << " | "
        << board[mult+1][j]
        << " | "
        << board[mult+2][j]
        << endl;
      } else if(i<2) {
        cout << setw(17) << "-----------------" << endl;
      }
    }
  }
}

string Board::place(bool player_is_x, int position) {
  if(position < 0 || position > 8) {
    return "Position out of range.";
  } else if(this->pieces[position] != 0) {
    return "Position not empty.";
  } else {
    this->pieces[position] = player_is_x ? 1 : 2;
    size++;
    //draw();
    stringstream ss;
    ss.clear();
    ss.str("");
    ss << (player_is_x ? "X" : "O") << " placed a piece at position " << position << ".";
    return ss.str();
  }
  return "Error occurred.";
}

int Board::checkWin() {
  if(this->pieces[0] > 0) {
    if(this->pieces[0] == this->pieces[1] && this->pieces[1] == this->pieces[2]) {
      return this->pieces[0];
    } else if(this->pieces[0] == this->pieces[3] && this->pieces[3] == this->pieces[6]) {
      return this->pieces[0];
    } else if(this->pieces[0] == this->pieces[4] && this->pieces[4] == this->pieces[8]) {
      return this->pieces[0];
    }
  }
  if(this->pieces[1] > 0) {
    if(this->pieces[1] == this->pieces[4] && this->pieces[4] == this->pieces[7]) {
      return this->pieces[1];
    }
  }
  if(this->pieces[2] > 0) {
    if(this->pieces[2] == this->pieces[4] && this->pieces[4] == this->pieces[6]) {
      return this->pieces[2];
    } else if(this->pieces[2] == this->pieces[5] && this->pieces[5] == this->pieces[8]) {
      return this->pieces[2];
    }
  }
  if(this->pieces[3] > 0) {
    if(this->pieces[3] == this->pieces[4] && this->pieces[4] == this->pieces[5]) {
      return this->pieces[3];
    }
  }
  if(this->pieces[6] > 0) {
    if(this->pieces[6] == this->pieces[7] && this->pieces[7] == this->pieces[8]) {
      return this->pieces[6];
    }
  }
  return 0;
}

Board* Board::copyBoard() {
  Board* new_board = new Board();
  for(int i = 0; i < 9; i++) {
    if(this->pieces[i] > 0) {
      new_board->place((pieces[i] == 1 ? 1 : 0), i);
    }
  }
  return new_board;
}

int Board::getSize() {
  return size;
}

int Board::getPiece(int position) {
  return pieces[position];
}

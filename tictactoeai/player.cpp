#include <iostream>
#include "player.h"
using namespace std;

Player::Player(bool is_x) {
  piece = is_x;
}

bool Player::is_x() {
  return piece;
}

int Player::doTurn() {
  cout << "Player " << (this->piece ? "X" : "Y") << ", choose a position: ";
  int position;
  cin >> position;
  return position - 1;
}

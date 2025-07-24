#include "Player.h"
#include <cstring>

Player::Player() {
  // initialize variables
  ID = 0;
  firstName = "";
  lastName = "";
  numStat = 0;
}

int Player::setAll(int num, std::string fname, std::string lname, float *stats,
                   int statSize) {
  // copy names + ID
  ID = num;
  firstName = fname;
  lastName = lname;
  numStat = statSize;
  // copy the stats into member data
  for (int i = 0; i < statSize; i++) {
    memberData[i] = stats[i];
  }
  // if stat size is less than 20 then set to 0
  for (int i = statSize; i < 20; i++) {
    memberData[i] = 0.0f;
  }
  return 0;
}

int Player::setStats(float *stats, int statSize) {
  // copy stats
  numStat = statSize;
  for (int i = 0; i < statSize; i++) {
    memberData[i] = stats[i];
  }
  // set rest to 0
  for (int i = statSize; i < 20; i++) {
    memberData[i] = 0.0f;
  }
  return 0;
}

int Player::updateStats(float *newData, int statSize) {
  // add new stats to old stats
  for (int i = 0; i < numStat; i++) {
    memberData[i] += newData[i];
  }
  return 0;
}

void Player::printPlayer(std::ostream &out) {
  // print ID, and names
  out << ID << "\t" << firstName << "\t" << lastName;
  for (int i = 0; i < numStat; i++) {
    out << "\t" << memberData[i];
  }
  out << "\n";
}

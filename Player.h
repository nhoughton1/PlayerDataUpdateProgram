#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

// player: default constructor
// parameters:
// none
// returns:
// nothing
class Player {
private:
  int ID;
  std::string firstName;
  std::string lastName;
  float memberData[20];
  int numStat;

public:
  Player();
  int getID() const { return ID; }

  // setAll: sets all the players data
  // parameters:
  // num - ID for the player
  // fname - first name of the player
  // lname - last name of the player
  // stats - pointer to float array
  // statSize - how many stats
  // returns:
  // int - 0
  int setAll(int num, std::string fname, std::string lname, float *stats,
             int statSize);

  // setStats: sets the stats part
  // parameters:
  //  stats - pointer to float array
  // statsize - how many stats
  // returns:
  // int - 0
  int setStats(float *stats, int statSize);

  // updateStats: adds new data to the existing stats
  // parameters:
  // newData - pointer to float array
  // statSize - how many floats are in newData
  // returns:
  // int - 0
  int updateStats(float *newData, int statSize);

  // printPlayer: prints the players data in columns
  // parameters:
  // out - output stream
  // returns:
  // nothing
  void printPlayer(std::ostream &out);
};
#endif
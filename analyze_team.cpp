#include "Player.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// main: reads the team data from the text files and then applies the updates to
// the new data file, and writes out the results parameters: argc - number of
// command line arguments argv - array of command line argument strings returns:
// int - 0
int main(int argc, char *argv[]) {
  // checks for enough arguments
  if (argc < 6) {
    std::cout << "Missing command line arguments\n\n";
    std::cout << "./teamData oldData.txt newData.txt outName.txt numStats "
                 "numPlayers\n";
    return 0;
  }

  // sets the command line parameters to variable names
  std::string oldData = argv[1];
  std::string newData = argv[2];
  std::string outputData = argv[3];
  int numStats = std::atoi(argv[4]);
  int numPlayers = std::atoi(argv[5]);

  // make sure there aren't more than 20 stats
  if (numStats > 20) {
    std::cout << "Too many player stats for this program (max of 20).\n";
    return 0;
  }

  // allocate memory for the team
  Player *theTeam = new Player[numPlayers];
  // open the files and read header line
  std::ifstream oldFile(oldData);
  std::string headerLine;
  std::getline(oldFile, headerLine);

  // loop over all players
  for (int i = 0; i < numPlayers; i++) {
    // temporary variables
    int tempID;
    std::string tempFirst, tempLast;
    float tempStats[20] = {0.0f};
    // read ID, first name, and last name from oldFile
    oldFile >> tempID >> tempFirst >> tempLast;
    for (int j = 0; j < numStats; j++) {
      oldFile >> tempStats[j];
    }
    theTeam[i].setAll(tempID, tempFirst, tempLast, tempStats, numStats);
  }
  oldFile.close();

  // open the new file  & skip header
  std::ifstream newFile(newData);
  std::string newHeader;
  std::getline(newFile, newHeader);
  // read each line to update stats
  int tempID;
  std::string tempFirst, tempLast;
  // this will keep it reading until theres no more valid data
  while (newFile >> tempID >> tempFirst >> tempLast) {

    float tempStats[20] = {0.0f};
    for (int j = 0; j < numStats; j++) {
      newFile >> tempStats[j];
    }
    // find the matching player
    for (int k = 0; k < numPlayers; k++) {
      if (theTeam[k].getID() == tempID) {
        theTeam[k].updateStats(tempStats, numStats);
      }
    }
  }

  // close the file and write out the header
  newFile.close();
  std::ofstream outputFile(outputData);
  outputFile << headerLine << "\n";
  // print each players data
  for (int i = 0; i < numPlayers; i++) {
    theTeam[i].printPlayer(outputFile);
  }
  // free the memory
  delete[] theTeam;
  return 0;
}
# This makefile is used as follows to regenerate files for the teamData program:
#   make analyze_team.o       -- Regenerates analyze_team.o
#   make Player.o             -- Regenerates Player.o
#   make teamData             -- Regenerates the "teamData" executable
#   make                      -- Same as "make teamData"

teamData: analyze_team.o Player.o
	g++ -g -Wall analyze_team.o Player.o -o teamData

analyze_team.o: Player.h analyze_team.cpp
	g++ -g -Wall -c analyze_team.cpp

Player.o: Player.h Player.cpp
	g++ -g -Wall -c Player.cpp

clean:
	rm -f analyze_team.o Player.o teamData

all: teamData

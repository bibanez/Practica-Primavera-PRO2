OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Player.o Statistics.o Categories.o Tournament.o Ranking.o Tournaments.o
	g++ -o program.exe program.o Player.o Statistics.o Categories.o Tournament.o Ranking.o Tournaments.o $(OPTIONS)

program.o: program.cc
	g++ -c program.cc $(OPTIONS)

Player.o: Player.cc Player.hh
	g++ -c Player.cc $(OPTIONS)

Statistics.o: Statistics.cc Statistics.hh
	g++ -c Statistics.cc $(OPTIONS)

Categories.o: Categories.cc Categories.hh
	g++ -c Categories.cc $(OPTIONS)

Tournament.o: Tournament.cc Tournament.hh Statistics.o
	g++ -c Tournament.cc $(OPTIONS)

Ranking.o: Ranking.cc Ranking.hh Statistics.o Player.o
	g++ -c Ranking.cc $(OPTIONS)

Tournaments.o: Tournaments.cc Tournaments.hh Tournament.o Ranking.o Categories.o
	g++ -c Tournaments.cc $(OPTIONS)

tar: program.cc Player.cc Player.hh Statistics.cc Statistics.hh Categories.cc Categories.hh Tournament.cc Tournament.hh Ranking.cc Ranking.hh Tournaments.cc Tournaments.hh Makefile
	tar -cvf practica.tar program.cc Player.cc Player.hh Statistics.cc Statistics.hh Categories.cc Categories.hh Tournament.cc Tournament.hh Ranking.cc Ranking.hh Tournaments.cc Tournaments.hh Makefile

clean:
	rm *.exe
	rm *.o

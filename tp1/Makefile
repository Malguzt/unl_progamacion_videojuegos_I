IDIR =include
CFLAGS=-I$(IDIR)
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
HEADERS = Game.h Character.h
OPTIONS = -std=c++11

all: theGame clean

%.o: src/%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) $(OPTIONS)

%.o: include/%.h
	$(CXX) -c $< -o $@ ./

theGame: main.o Game.o Character.o
	g++ -o tp1 main.o Game.o Character.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f *.o
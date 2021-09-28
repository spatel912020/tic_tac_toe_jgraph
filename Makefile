CXX=		g++
CXXFLAGS=	-g -std=gnu++11
LDFLAGS=	
SHELL=		bash
PROGRAMS=	tic_tac_toe
SOURCES=	tic_tac_toe.cpp
OBJECTS=	$(SOURCES:.cpp=.o)

all:		$(PROGRAMS)

%.o:		%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

tic_tac_toe:	$(OBJECTS) 
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS)


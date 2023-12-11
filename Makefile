CXX = g++
CXXFLAGS = -std=c++11 -Wall -ansi -pedantic -DMAP
SRCS = Main.cpp Catalogue.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp Noeud.cpp Liste.cpp 
OBJS = $(SRCS:.cpp=.o)
TARGET = trajets

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

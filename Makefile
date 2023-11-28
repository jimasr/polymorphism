CXX = g++
CXXFLAGS = -std=c++11 -Wall -ansi -pedantic -DMAP
SRCS = Main.cpp Trajet.cpp TrajetSimple.cpp Noeud.cpp Liste.cpp 
OBJS = $(SRCS:..cpp=o)
TARGET = Prog

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

CXX = g++
CXXFLAGS = -g -Wall
driver: MazeSolver.o MazeSolver.cpp
	$(CXX) $(CXXFLAGS) MazeSolver.o driver.cpp -o driver
MazeSolver.o: MazeSolver.cpp MazeSolver.h
	$(CXX) $(CXXFLAGS) -c MazeSolver.cpp
remake:
	make driver
	make run

clean:
	rm *.o*
	rm *~ 

run:
	./driver

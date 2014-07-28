CXX=g++ -std=c++11

all: run clean

run: run.o
	@./run

run.o:
	@$(CXX) *.cpp *.h -o run 

clean: 
	@rm run
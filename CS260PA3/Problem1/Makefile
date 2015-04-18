CXX=g++
 
all: run clean
 
run: run.o
	@./run < /usr/share/dict/words
 
run.o:
	@$(CXX) *.cpp *.h -o run
	
clean:
	@rm run

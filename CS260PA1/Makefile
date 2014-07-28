CC=g++ -g -std=c++11
TARGETS=timing

all:build

build:main

main: $(TARGETS)

$(TARGETS): src/*.cpp
	$(CC) -o $@ $^
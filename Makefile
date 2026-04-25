# Copyright © 2023-2026 Alan Sampson

all: main

bindir=./bin

CXX = clang++
override CXXFLAGS += -g -Wall -Wpedantic -Werror=vla -fsanitize=address -std=gnu++23
#-Wl,--print-memory-usage

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

both: main main-debug

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(bindir)/$@

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o $(bindir)/$@

clean:
	rm -f main main-debug

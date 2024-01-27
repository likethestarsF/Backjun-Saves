all: main

CXX = clang++
override CXXFLAGS += -g -Wmost -Werror


## Chage 'main.cpp' to '*.cpp' when use multiple srcs.

SRCS = $(shell find . \( -name '.ccls-cache' -o -name 'History' \) -type d -prune -o -type f -name 'main.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug
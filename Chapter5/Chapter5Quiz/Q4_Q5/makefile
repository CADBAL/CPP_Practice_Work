CXX := g++
CXXFLAGS := -std=c++23 -O0 -g -ggdb \
-pedantic-errors \
-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion \
-Werror

# Output name (default 'app' if not supplied by the task)
MAIN ?= app

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean
all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	@echo "Cleaning objects and binaries..."
	rm -f $(OBJS) $(MAIN)

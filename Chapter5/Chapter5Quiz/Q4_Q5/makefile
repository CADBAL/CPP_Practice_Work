CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -g

TARGET := Q4
OBJS := Q4.o age_comparision.o input_age.o input_name.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) Q4.exe

.PHONY: all clean

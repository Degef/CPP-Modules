TARGET = bsp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp  Point.cpp bsp.cpp 

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)
	@printf "$(TARGET) Ready!"

clean:
	rm -f $(TARGET)
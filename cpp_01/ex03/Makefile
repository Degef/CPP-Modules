TARGET = Brain

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)
	@printf "$(TARGET) Ready!"

clean:
	rm -f $(TARGET)
TARGET = zombieHorde

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)
	@printf "$(TARGET) Ready!"

clean:
	rm -f $(TARGET)
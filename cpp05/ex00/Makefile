TARGET = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@printf "$(TARGET) Ready!\n"


clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(TARGET)
re: clean all

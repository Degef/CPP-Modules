#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        return 1;
    }

    std::istringstream iss(argv[1]);
    std::deque<std::string> tokens;
    std::string token;
    while (iss >> token)
        tokens.push_back(token);

    std::deque<int> stack;
	if (find_result(stack, tokens) == 1)
		return 1;
	std::cout << "Result: " << stack.front() << std::endl;
    return 0;
}

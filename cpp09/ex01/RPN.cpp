#include "includes/RPN.hpp"

int do_op(int first_num, int second_num, char op)
{
    if (op == '+')
        return first_num + second_num;
    else if (op == '-')
        return first_num - second_num;
    else if (op == '*')
        return first_num * second_num;
    else if (op == '/')
    {
        if (second_num == 0) {
            throw std::runtime_error("Error: Division by zero");
        }
        return first_num / second_num;
    }
    else {
        throw std::runtime_error("Error in do_op");
    }
}

int find_result(std::deque<int> &stack, std::deque<std::string> &tokens)
{
	for (std::deque<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); it++) {
        const std::string& token = *it;
        if (isdigit(token[0]) && token.size() == 1) {
            stack.push_front(atoi(token.c_str()));
        }
		else if (token.size() == 1 && 
				(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
            int second_num = stack.front();
            stack.pop_front();
            int first_num = stack.front();
            stack.pop_front();
			try {
            	stack.push_front(do_op(first_num, second_num, token[0]));
			}
			catch (std::runtime_error &e) {
				std::cout << e.what() << std::endl;
				return 1;
			}
        }
		else {
			std::cout << "Error: Invalid token: " << token << std::endl;
			return 1;
		}
    }
	if (stack.size() != 1) {
		std::cout << "Error: Invalid expression" << std::endl;
		return 1;
	}
	return 0;
}

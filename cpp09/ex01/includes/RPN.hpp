#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <cstring>


int do_op(int first_num, int second_num, char op);
void find_result(std::deque<int> &stack, std::deque<std::string> &tokens);

#endif
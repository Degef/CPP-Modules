# CPP09 Module

This module contains solutions for three exercises:

## Exercise 00

The goal of this exercise is to read from a database of `.csv` files containing bitcoin prices over time, and calculate the value of a given amount of bitcoin on a specific date. The solution uses an `std::map` container to store the bitcoin prices, and implements a binary search algorithm to find the closest date to the input date.

## Exercise 01

The goal of this exercise is to evaluate an expression written in reverse polish notation. The solution uses an `std::stack` container to store the operands and operators, and implements a simple algorithm to evaluate the expression.

## Exercise 02

The goal of this exercise is to sort an array of numbers using the merge-insertion sorting algorithm (Ford-Johnson algorithm), and compare the performance of two containers: `std::vector` and `std::list`. The solution implements the sorting algorithm using both containers, and measures the time it takes to sort an array of numbers.

References:

- [Choosing the Right Container: Sequential Containers](https://embeddedartistry.com/blog/2017/09/11/choosing-the-right-container-sequential-containers/#:~:text=Here's%20a%20quick%20summary%20of,access%20but%20costly%20insertions%2Fdeletions)
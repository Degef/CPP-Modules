#include <iostream>
using namespace std;

int main()
{
    int degree_fahrenheit;
    int degree_celsius;
    cout << "Enter temprature in Celsius: ";
    cin >> degree_celsius;
    cout << "Temprature in Fahrenheit is: ";
    degree_fahrenheit = (degree_celsius * 9/5) + 32;
    cout << degree_fahrenheit << endl;
    return 0;
}
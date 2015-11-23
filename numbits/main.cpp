#include <iostream>
#include "numbits.hpp"

using namespace std;
int main()
{
	cout << "Welcome to numbits. Enter a number to find out how many bits are set (i.e. 1) and how many bits are unset (i.e. 0) it has. Enter anything else to exit." <<endl;
	int num;
	while(cin >> num){
		cout << "The number " << num << " has " << num1bits(num) << " bits set and " << num0bits(num) << " unset." << endl;
	}
	cout << "Thanks for playing!" << endl;
	return 0;
}
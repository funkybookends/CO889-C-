#include <iostream>
#include "numbits.hpp"

using namespace std;
int main()
{
	cout << "Welcome2" <<endl;
	int num;
	while(cin >> num){
		cout << num << " : " << num1bits(num) << " , " << num0bits(num) << endl;
	}
	return 0;
}
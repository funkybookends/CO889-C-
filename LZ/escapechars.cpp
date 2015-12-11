#include <iostream>
#include <string>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. 
	//In most cases the returned string is simply the one 
	//character string containing ch, However escpaed chars 
	//are returned as the representation of them i.e. 
	//char('\t') returns string("\t").

	switch (ch){
		case 9:
			return string("\\t");
			break;
		case 10:
			return string("\\n");
			break;
		case 32:
			return string("\\s");
			break;
		case 13:
			return string("\\r");
			break;
		default:
			if (ch>=48 && ch<=57) {
				return string("\\") + string(1, ch);
			}
			return string(1,ch);
	}
}

int main()
{
	char in;
	while (cin >> noskipws >> in){
		cout << escapeChar(in);
	}
	return 0;
}
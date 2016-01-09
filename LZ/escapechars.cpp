#include <iostream>
#include <string>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. In most cases the returned 
	//string is simply the one character string containing ch, However escpaed 
	//chars are returned as the representation of them i.e. char('\t') returns string("\t").

	switch (ch){
		case 9: //tab
			return string("\\t");
		case 10: //new line
			return string("\\n");
		case 32: // space
			return string("\\s");
		case 13: // carriage return
			return string("\\r");
		case 92: // backslash "\"
			return string("\\\\");
		default: 
			if (ch>= '0' && ch<='9') { //digits
				return string("\\") + string(1, ch);
			}
			return string(1,ch); //just a regular char
	}
}

int main()
{
	char in;
	while (cin.get(in)){
		cout << escapeChar(in);
	}
	if (!cin.eof()){
		//there was an error reading in
		return 1;
	}
	return 0;
}
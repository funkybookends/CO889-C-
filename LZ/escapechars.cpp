#include <iostream>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. In most cases the returned string is simply the one character string containing ch, However escpaed chars are returned as the representation of them i.e. char('\t') returns string("\t").
	
	switch (ch){
		case '\t':
			return "\\t";
			break;
		case '\n':
			return "\\n";
			break;
		case ' ':
			return "\\s";
			break;
		case '\r':
			return "\\r";
			break;
		default:
			return string(1,ch);			
	}
}

int main()
{
	char in;
	while (cin >> in){
		cout << escapeChar(in) << flush;
	}
}
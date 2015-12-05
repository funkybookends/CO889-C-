#include <iostream>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. In most cases the returned string is simply the one character string containing ch, However escpaed chars are returned as the representation of them i.e. char('\t') returns string("\t").
	
	switch (ch){
		case 9:
			return string("\\")+string("t");
			break;
		case 10:
			return string("\\")+string("n");
			break;
		case 32:
			cout<<"case space";
			return string("\\")+string("s");
			break;
		case 13:
			return string("\\")+string("r");
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
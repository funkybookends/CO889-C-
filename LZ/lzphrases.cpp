#include <iostream>
#include <string>
#include <set>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. In most cases the returned string is simply the one character string containing ch, However escpaed chars are returned as the representation of them i.e. char('\t') returns string("\t").

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

string escapeString(const string& str){
	string out;
	for (string::const_iterator it = str.begin(); it!=str.end(); ++it){
		out += escapeChar(*it);
	}
	return out;
}

int main() {
	set<string> phrases;
	string phrase = "";
	phrases.insert(phrase); //to prevent the firs ont being an empty line
	char in;
	while (cin >> noskipws >> in){
		phrase += string(1, in);
		std::pair<std::set<string>::iterator,bool> ret;
		ret = phrases.insert(phrase);
		if (ret.second){ //it was inserted
			cout << escapeString(phrase) << endl;
			phrase = "";
		}
	}
	cout << escapeString(phrase) << endl;
	return 0;
}
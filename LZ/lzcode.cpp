#include <iostream>
#include <string>
#include <map>

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
	map<string, unsigned int> phrases;
	string phrase = "";
	unsigned int phrase_counter = 0;
	phrases[phrase] = phrase_counter++; //to prevent the first one being an empty line


	string in;
	while (getline(cin, in)){
		in += "\n"; //so that we get the \n at the end.
		string::const_iterator it = in.begin();
		while (it != in.end()){
			map<string, unsigned int>::iterator phrases_iterator;
			if (phrases.find(phrase) != phrases.end()){//it was found
				phrase = phrase + string(1, *it++); //grow the phrase by one char
			}
			else { //this is a new phrase
				phrases[phrase] = phrase_counter++;
				string prefix = phrase.substr(0, phrase.length()-1);
				unsigned int prefix_num = phrases[prefix];
				cout << prefix_num << escapeString(phrase.substr(phrase.length()-1, phrase.length())) << endl; //display it
				phrase = "";
			}
		}
		string prefix = phrase.substr(0, phrase.length()-1);
		unsigned int prefix_num = phrases[prefix];
		cout << prefix_num << escapeString(phrase.substr(phrase.length()-1, phrase.length())) << endl; //display it
				
	}
	return 0;
}
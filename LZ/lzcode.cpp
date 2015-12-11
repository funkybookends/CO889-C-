#include <iostream>
#include <string>
#include <map>

using namespace std;

string escapeChar(char ch){
	//takes in a charecter and returns a string. In most cases the returned string
	// is simply the one character string containing ch, However escpaed chars are
	//returned as the representation of them i.e. char('\t') returns string("\t").

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

	//initialize the 0 phrase
	string phrase = "";
	unsigned int phrase_counter = 0;
	phrases[phrase] = phrase_counter++; 

	char in;
	while (cin >> noskipws >> in){

		phrase += string(1, in); //append the char to the current phrase

		if (phrases.find(phrase) == phrases.end()){
			//phrase was not found
			//so its a new phrase
			cout << phrases[phrase.substr(0, phrase.length()-1)] 
			     << escapeChar(in) << endl;
			phrases[phrase] = phrase_counter++;
			phrase = ""; //reset the phrase
		} //else lets go through the loop again
	}
	if (cin.eof() && phrase!=""){
		cout << phrases[phrase.substr(0, phrase.length()-1)] 
		     << escapeChar(in) << endl;
	}
	return 0;
}
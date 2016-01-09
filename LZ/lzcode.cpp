#include <iostream>
#include <string>
#include <map>

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
	while (cin.get(in)){

		phrase += string(1, in); //append the char to the current phrase

		if (phrases.find(phrase) == phrases.end()){
			//phrase was not found
			//so its a new phrase
			cout << phrases[phrase.substr(0, phrase.length()-1)]
				 << escapeChar(in) << endl; //display it
			phrases[phrase] = phrase_counter++; //record it
			phrase = ""; //reset the phrase
		} //else lets go through the loop again
	}
	if (phrase!=""){
		//if the last phrase was not a new phrase
		//it still needs to be displayed.
		cout << phrases[phrase.substr(0, phrase.length()-1)] 
			 << escapeChar(in) << endl;
	}
	if (!cin.eof()){
		//there was an error reading in
		return 1;
	}
	return 0;
}
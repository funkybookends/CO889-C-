// $Id: lzdecode.cpp 983 2005-01-12 18:24:59Z arr $

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

namespace {
    // Report an error in the format of lzcoded text, and exit the
    // program with status 1.
    void formatError(string msg)
    {
	cerr << "Input format error (" << msg << ")\n";
	exit(1);
    }

    // Try to read a (possibly escaped) character from ism, and convert
    // it to raw (unescaped) form.  If successful, assign the resulting
    // character to c and return true; otherwise return false.  Raises a
    // format error if an incomplete or unrecognised escape sequence is
    // encountered.
    bool unescapeChar(istream& ism, char& c)
    {
		char ch;
		if (!ism.get(ch))
		    return false;
		if (ch != '\\') {
		    c = ch;
		    return true;
		}
		// If we get this far, it's an escape sequence.
		if (!ism.get(ch))
		    formatError("incomplete escape sequence");
		if (ch == '\\' || ('0' <= ch && ch <= '9')) {
		    c = ch;
		    return true;
		}
		switch (ch) {
		case 's':
		    c = ' ';
		    break;
		case 't':
		    c = '\t';
		    break;
		case 'r':
		    c = '\r';
		    break;
		case 'n':
		    c = '\n';
		    break;
		default:
		    formatError("unrecognised escape sequence ("+ string(1, ch) + ")");
		}
		return true;
    }
}

// Read lzcoded text from the standard input, and write the
// corresponding decoded text to the standard output.
int main() {
    vector<string> phrases;
    phrases.push_back("");  // phrases[0] is the empty string
    unsigned int prefix_num;
    while (cin >> prefix_num) {
		char ch;
		if (!unescapeChar(cin, ch))
		    formatError("incomplete phrase");
		if (prefix_num >= phrases.size())
		    formatError("prefix number out of range");
		string phrase = phrases[prefix_num];
		phrase += ch;
		cout << phrase;// << " -" << prefix_num << "- ";
		phrases.push_back(phrase);
    }
    // Here we ignore some pathological types of input error:
    if (!cin.eof())
	formatError("unexpected non-digit");
    return 0;
}

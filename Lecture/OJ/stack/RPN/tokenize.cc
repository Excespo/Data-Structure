#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iterator>


using namespace std;

vector<string> tokenize(string& input_line) {
    /**
     * @brief Tokenize input lines with white space delimitor
     * @param input_line A line of input. For example "2 3 +"
     * @return tokens Tokenized strings. For example: ["2", "3", "+"]
     */
    istringstream iss(input_line);
    vector<string> tokens((istream_iterator<string>(iss)), istream_iterator<string>());
    return tokens;
}

int main() {
    /** @brief Input line buffer*/
    string input_line;
    /** @brief Tokenized strings*/
    vector<string> tokens;
    while (true) {
        // Read line
        getline(cin, input_line);
        if (input_line.size() <= 0) break;

        // Tokenize
        tokens = tokenize(input_line);
		for (int i=0; i <tokens.size(); ++i){
			cout << tokens[i] << "_";
		}
		cout <<endl;
        // Clear input buffer
        input_line.clear();
    }
}
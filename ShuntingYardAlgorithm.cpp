#include "ShuntingYardAlgorithm.h"
#include <sstream>
#include <numeric>
using namespace std;

stack <string> stack1;
queue <string> outputList;
vector <string> operators;
vector <int> precedence;
vector <char> associativity;
vector <string> strVec;
string str;

ShuntingYardAlgorithm :: ShuntingYardAlgorithm () = default;

bool ShuntingYardAlgorithm :: hasOnlyDigits(const string s){
    return s.find_first_not_of( "0123456789" ) == string::npos;
}

int ShuntingYardAlgorithm :: getPrecedence(const string s) {
    for(int i = 0; i < operators.size(); i++) {
        if (s ==  operators[i])
            return precedence[i];
    }
}

char ShuntingYardAlgorithm :: getAssociativity(const string s) {
    for(int i = 0; i < operators.size(); i++) {
        if (s == operators[i])
            return associativity[i];
    }
}

vector<string> ShuntingYardAlgorithm :: parse(const string input) {
// Parses the string by white space
    istringstream ss(input);
    vector <string> tokenVector;

    // Fill vector with ss
    for (string input; ss >> input;) {
        tokenVector.push_back(input);
    }
    return tokenVector;
}

string ShuntingYardAlgorithm :: toRPN(const string s) {

    // Delimit string by white space and store in vector
    vector <string> tokens = parse(s);

    // Exit if input is not prefaced by "<"
    if(tokens[0] != "<") {
        cout << "Please begin prompt with '<'" << endl;
        exit(0);
    }


    //Change "rt" to "$" to be easily accessed
    for (int i = 0; i < tokens.size(); i ++) {
        if (tokens[i] == "rt")
            tokens[i] = "$";
    }

    // Stores operators and their precedence/associativity to vectors using same index
    operators.push_back("+"); precedence.push_back(2); associativity.push_back('L');
    operators.push_back("-"); precedence.push_back(2); associativity.push_back('L');
    operators.push_back("/"); precedence.push_back(3); associativity.push_back('L');
    operators.push_back("*"); precedence.push_back(3); associativity.push_back('L');
    operators.push_back("^"); precedence.push_back(4); associativity.push_back('R');
    operators.push_back("$"); precedence.push_back(4); associativity.push_back('R');


    // Shunting-Yard logic
    for (int i = 0; i < tokens.size(); i++) {
        if (hasOnlyDigits(tokens[i])) {
            outputList.push(tokens[i]);
        }
        vector<string>::iterator it = find(operators.begin(), operators.end(), tokens[i]);
        if (it != operators.end()) {
            if(!stack1.empty()) {
                bool stackPrecGreater = getPrecedence(stack1.top()) > getPrecedence(tokens[i]);
                bool precEqual = getPrecedence(stack1.top()) == getPrecedence(tokens[i]);
                bool assL = getAssociativity(tokens[i]) == 'L';
                while (!stack1.empty() && ((stackPrecGreater && stack1.top() != "(") || (precEqual && assL && stack1.top() != "("))) {
                    outputList.push(stack1.top());
                    stack1.pop();
                }
            }
            stack1.push(tokens[i]);
        }
        if (tokens[i] == "(") {
            stack1.push(tokens[i]);
        }
        if (tokens[i] == ")") {
            while (!stack1.empty() && stack1.top() != "(") {
                outputList.push(stack1.top());
                stack1.pop();
            }
            stack1.pop();
        }
        if (i == tokens.size()-1) {
            while(!stack1.empty()) {
                outputList.push(stack1.top());
                stack1.pop();
            }
        }
    }

    // Write string vector to string and swap "rt" back
    while(!outputList.empty()) {
        if(outputList.front() == "$") {
            strVec.push_back("rt");
            strVec.push_back(" ");
            outputList.pop();
        }
        else {
            strVec.push_back(outputList.front());
            strVec.push_back(" ");
            outputList.pop();
        }
    }
    str = accumulate(begin(strVec), end(strVec), str);
    return str;
}


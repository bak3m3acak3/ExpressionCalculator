#include <iostream>
#include "Integer.h"
#include "Addition.h"
#include "Division.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Exponentiation.h"
#include "ShuntingYardAlgorithm.h"
#include <vector>
#include <cmath>


bool hasOnlyDigits(const string s) {
    return s.find_first_not_of( "0123456789" ) == string::npos;
}

int main() {
    string s = "< ";
    string str;
    vector<string> delimiters;
    vector<string> tokens;
    vector<string> testVector;
    stack <Expression*> opStack;
    ShuntingYardAlgorithm obj1;
    ShuntingYardAlgorithm obj2;
    bool valid_input = true;

        // Set delimiters
        delimiters.push_back("+");
        delimiters.push_back("-");
        delimiters.push_back("*");
        delimiters.push_back("/");
        delimiters.push_back("^");
        delimiters.push_back("(");
        delimiters.push_back(")");

    do {
        cout << "Enter an expression:" << endl;
        getline(cin, str);
        s += str;

        // Test for invalid input
        testVector = obj2.parse(s);
        for (int i = 0; i < testVector.size(); i++) {
            if (!hasOnlyDigits(testVector[i])) {
                if (testVector[i] != "<" &&
                    find(delimiters.begin(), delimiters.end(), testVector[i]) == delimiters.end()) {
                    cout << "Error: Invalid entry. Only input numbers and operators separated by spaces!" << endl << endl;
                    valid_input = false;
                }
            }
        }
    }while (valid_input == false);

    tokens = obj2.parse(obj2.toRPN(s));
    for (int i = 0; i < tokens.size(); i++) {
        if (hasOnlyDigits(tokens[i])) {
            Integer *intObj = new Integer(tokens[i]);
            opStack.push(intObj);
        } else if (find(delimiters.begin(), delimiters.end(), tokens[i]) != delimiters.end()) {
            Expression *B = opStack.top();
            opStack.pop();
            Expression *A = opStack.top();
            opStack.pop();

            if (tokens[i] == "+") {
                Addition *addObj = new Addition(A, B);
                opStack.push(addObj);
            } else if (tokens[i] == "-") {
                Subtraction *subObj = new Subtraction(A, B);
                opStack.push(subObj);
            } else if (tokens[i] == "*") {
                Multiplication *multObj = new Multiplication(A, B);
                opStack.push(multObj);
            } else if (tokens[i] == "/") {
                Division *divObj = new Division(A, B);
                opStack.push(divObj);
            } else if (tokens[i] == "^") {
                Exponentiation *expObj = new Exponentiation(A, B);
                opStack.push(expObj);
            }
        } else {
            cout << "Error: Invalid entry. Only input numbers and operators separated by spaces!" << endl;
            exit(0);
        }
    }

    Expression *finalValue = opStack.top();
    cout << finalValue->simplify()->print();
    delete finalValue;

}
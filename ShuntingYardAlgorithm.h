#ifndef EXPRESSIONCALCULATOR_SHUNTING_YARD_ALGORITHM_H
#define EXPRESSIONCALCULATOR_SHUNTING_YARD_ALGORITHM_H
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class ShuntingYardAlgorithm {
public:
    stack <string> stack1;
    vector <string> tokens;
    queue <string> outputList;
    vector <string> operators;
    vector <int> precedence;
    vector <char> associativity;
    vector <string> strVec;
    string str;
    ShuntingYardAlgorithm ();
    bool hasOnlyDigits(const string s);
    int getPrecedence(const string s);
    char getAssociativity(const string s);
    vector<string> parse(const string input);
    string toRPN(const string);
};


#endif //EXPRESSIONCALCULATOR_SHUNTING_YARD_ALGORITHM_H

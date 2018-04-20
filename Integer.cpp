#include "Integer.h"
#include <string>
using namespace std;

// constructor
Integer :: Integer(string s) {
    string1 = s;
}

Integer ::~Integer() {};

string Integer :: getType() {
    return typeID = "Integer";
}

int Integer :: getValue() {
    int value = atoi(string1.c_str());
    return value;
}

Expression* Integer :: getLeftSide(){};

Expression* Integer :: getRightSide(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Integer :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Integer :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Integer :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Integer :: simplify(){};
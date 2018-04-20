#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
#include "Expression.h"


// Expression constructor
Expression :: Expression() {};

Expression ::~Expression() {};

/* Calculates the value of the expression.*/
int getValue();

/* Returns the requested operand for this expression component.*/
Expression* getLeftSide() {};

Expression* getRightSide() {};

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> getNumeratorFactors() {};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> getDenominatorFactors() {};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> getAdditiveTerms() {};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* simplify() {};



string Expression :: getType() {}

bool Expression :: isInt(Expression* a) {
    if(a->getValue() == int(a->getValue())){
        return true;
    } else return false;
}

//bool Expression :: stringIsDigits(const string s) {
//    return s.find_first_not_of( "0123456789" ) == string::npos;
//}
//
//bool Expression :: hasOnlyDigits(const string s) {
//    return s.find_first_not_of( "0123456789" ) == string::npos;
//}




#include "Multiplication.h"
#include "Expression.h"

using namespace std;

// Constructor
Multiplication :: Multiplication(Expression A, Expression B) {
    obj1 = &A;
    obj2 = &B;
}

Multiplication ::~Multiplication() {};

string Multiplication :: getType() {
    return typeID = "Multiplication";
}

int Multiplication :: getValue() {};

Expression* Multiplication :: getLeftSide() {
    return obj1;
}

Expression* Multiplication :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Multiplication :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Multiplication :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Multiplication :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Multiplication :: simplify(){};

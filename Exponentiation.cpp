#include "Exponentiation.h"
#include "Expression.h"


// Constructor
Exponentiation :: Exponentiation(Expression A, Expression B){
    obj1 = &A;
    obj2 = &B;
}

Exponentiation::~Exponentiation() {};

string Exponentiation :: getType() {
    return typeID = "Exponentiation";
}

int Exponentiation :: getValue() {};

Expression* Exponentiation :: getLeftSide() {
    return obj1;
}

Expression* Exponentiation :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Exponentiation :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Exponentiation :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Exponentiation :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Exponentiation :: simplify(){};
#include "Logarithm.h"
#include "Expression.h"


//constructor
Logarithm :: Logarithm(Expression A, Expression B) {
    obj1 = &A;
    obj2 = &B;
}

Logarithm ::~Logarithm() {};

string Logarithm :: getType() {
    return typeID = "Logarithm";
}

int Logarithm :: getValue() {};

Expression* Logarithm :: getLeftSide() {
    return obj1;
}

Expression* Logarithm :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Logarithm :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Logarithm :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Logarithm :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Logarithm :: simplify(){};

#include "NthRoot.h"
#include "Expression.h"


//constructor
NthRoot :: NthRoot(Expression* A, Expression* B) {
    obj1 = A;
    obj2 = B;
}

NthRoot ::~NthRoot() {};

string NthRoot :: getType() {
    return typeID = "NthRoot";
}

int NthRoot :: getValue() {};

Expression* NthRoot :: getLeftSide() {
    return obj1;
}

Expression* NthRoot :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> NthRoot :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> NthRoot :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> NthRoot :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* NthRoot :: simplify(){};
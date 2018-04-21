#include "Division.h"
#include "Expression.h"


// Constructor
Division :: Division(Expression* A, Expression* B) {
    obj1 = A;
    obj2 = B;
}

Division ::~Division() {};

string Division :: getType() {
    return typeID = "Division";
}

int Division :: getValue() {};

Expression* Division :: getLeftSide() {
    return obj1;
}

Expression* Division :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Division :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Division :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Division :: getAdditiveTerms(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Division :: simplify(){};

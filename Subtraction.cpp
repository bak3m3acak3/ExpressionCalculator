#include "Subtraction.h"
#include "Expression.h"



// Constructor
Subtraction :: Subtraction(Expression A, Expression B) {
    obj1 = &A;
    obj2 = &B;
}

Subtraction ::~Subtraction() {};

string Subtraction :: getType() {
    return typeID = "Subtraction";
}

int Subtraction :: getValue() {
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer")
        return obj1->getValue() - obj2->getValue();
    else return 0; // This needs to be changed, but idk what else to set as the else return
}

Expression* Subtraction :: getLeftSide() {
    return obj1;
}

Expression* Subtraction :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Subtraction :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Subtraction :: getDenominatorFactors(){};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Subtraction :: getAdditiveTerms() {
    vector <Expression*> terms;
    if((obj1->getType() == "Addition" || obj1->getType() == "Subtraction") && (obj2->getType() == "Addition" || obj2->getType() == "Subtraction")) {
        if(obj1->getLeftSide()->getType() == "Integer")
            terms.push_back(obj1->getLeftSide());
        if(obj1->getRightSide()->getType() == "Integer")
            terms.push_back(obj1->getRightSide());
        if(obj2->getLeftSide()->getType() == "Integer")
            terms.push_back(obj2->getLeftSide());
        if(obj2->getRightSide()->getType() == "Integer")
            terms.push_back(obj2->getRightSide());
    }
    return terms;
}
/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Subtraction :: simplify(){};
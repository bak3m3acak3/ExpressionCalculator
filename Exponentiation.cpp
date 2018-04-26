#include "Exponentiation.h"
#include "Expression.h"
#include "Integer.h"
#include "Division.h"
#include <cmath>


// Constructor
Exponentiation :: Exponentiation(Expression* A, Expression* B){
    obj1 = A;
    obj2 = B;
}

Exponentiation::~Exponentiation() {
    delete obj1;
    delete obj2;
};

string Exponentiation :: getType() {
    return typeID = "Exponentiation";
}

int Exponentiation :: getValue() {
    return static_cast<int>(pow(obj1->getValue(), obj2->getValue()));
};

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
Expression* Exponentiation :: simplify(){
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer") {
        string s = to_string(getValue());
        Integer* exactValue = new Integer(s);
        return exactValue;
    }
    if(obj1->getType() == "Division" && obj2->getType() == "Integer") {
        if(obj1->getLeftSide()->getType() == "Integer" && obj1->getRightSide()->getType() == "Integer") {
            Integer* intObj1 = new Integer(to_string(pow(obj1->getLeftSide()->getValue(), obj2->getValue())));
            Integer* intObj2 = new Integer(to_string(pow(obj1->getRightSide()->getValue(), obj2->getValue())));
            Division* divObj = new Division(intObj1, intObj2);
            return divObj;
        }
        else {
            Exponentiation* expObj = new Exponentiation(obj1, obj2);
            return expObj;
        }
    }

}

string Exponentiation :: print(){
    return getLeftSide()->print() + " ^ " + getRightSide()->print();
};
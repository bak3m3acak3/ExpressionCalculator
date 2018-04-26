#include "Multiplication.h"
#include "Expression.h"
#include "Integer.h"
#include "Division.h"
#include "Subtraction.h"
#include "Addition.h"
#include "Exponentiation.h"

using namespace std;

// Constructor
Multiplication :: Multiplication(Expression* A, Expression* B) {
    obj1 = A;
    obj2 = B;
}

Multiplication ::~Multiplication() {
    delete obj1;
    delete obj2;
};

string Multiplication :: getType() {
    return typeID = "Multiplication";
}

int Multiplication :: getValue() {
    return obj1->getValue() * obj2->getValue();
};

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
Expression* Multiplication :: simplify() {
    obj1 = obj1->simplify();
    obj2 = obj2->simplify();
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer") {
        string s = to_string(getValue());
        Integer* exactValue = new Integer(s);
        return exactValue;
    }
    else if(obj1->getType() == "Integer" && obj2->getType() == "Division") {
        int prod = obj1->getValue() * obj2->getLeftSide()->getValue();
        Integer* prodObj = new Integer(to_string(prod));
        Division* expObj = new Division(prodObj, obj2->getRightSide());
        return expObj;
    }
    else if(obj2->getType() == "Integer" && obj1->getType() == "Division") {
        int prod = obj2->getValue() * obj1->getLeftSide()->getValue();
        Integer* prodObj = new Integer(to_string(prod));
        Division* expObj = new Division(prodObj, obj1->getRightSide());
        return expObj;
    }
    else if(obj1->getType() == "Division" && obj2->getType() == "Division") {
        int prodOfNumerators = obj1->getLeftSide()->getValue() * obj2->getLeftSide()->getValue();
        Integer *prodOfNumeratorsObj = new Integer(to_string(prodOfNumerators));
        int prodOfDenominators = obj1->getRightSide()->getValue() * obj2->getRightSide()->getValue();
        Integer *prodOfDenominatorsObj = new Integer(to_string(prodOfDenominators));
        Division *prodOfDivisionTermsObj = new Division(prodOfNumeratorsObj, prodOfDenominatorsObj);
        return prodOfDivisionTermsObj;
    }
    else if(obj1->getType() == "Integer" && obj2->getType() == "Exponentiation") {
        int prod = obj1->getValue() * obj2->getLeftSide()->getValue();
        Integer* prodObj = new Integer(to_string(prod));
        Exponentiation* expObj = new Exponentiation(prodObj, obj2->getRightSide());
        return expObj;
    }
    else if(obj2->getType() == "Integer" && obj1->getType() == "Exponentiation") {
        int prod = obj2->getValue() * obj1->getLeftSide()->getValue();
        Integer* prodObj = new Integer(to_string(prod));
        Exponentiation* expObj = new Exponentiation(prodObj, obj1->getRightSide());
        return expObj;
    }
    else {
        Multiplication* multObj = new Multiplication(obj1, obj2);
        return multObj;
    }
};

string Multiplication :: print(){
    return getLeftSide()->print() + " * " + getRightSide()->print();
};

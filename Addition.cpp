#include "Addition.h"
#include "Expression.h"
#include "Integer.h"
#include <string>
#include <vector>


//constructor
Addition :: Addition(Expression* A, Expression* B) {
    obj1 = A;
    obj2 = B;
}

Addition ::~Addition() {
    delete obj1;
    delete obj2;
};

string Addition :: getType() {
    return typeID = "Addition";
}

int Addition :: getValue() {
    return obj1->getValue() + obj2->getValue();
}

Expression* Addition :: getLeftSide() {
    return obj1;
}

Expression* Addition :: getRightSide() {
    return obj2;
}

// Make similar method for Division objects that can be combined
vector <Expression*> Addition :: getAdditiveTerms() {
    vector <Expression*> terms;
    if((obj1->getType() == "Addition" || obj1->getType() == "Subtraction") && (obj2->getType() == "Addition" || obj2->getType() == "Subtraction")) {
        if(obj1->getLeftSide()->getType() == "Integer") {
            Expression* LL = obj1->getLeftSide();
            terms.push_back(LL);
        }
        if(obj1->getRightSide()->getType() == "Integer") {
            Expression* LR = obj1->getRightSide();
            terms.push_back(LR);
        }
        if(obj2->getLeftSide()->getType() == "Integer") {
            Expression* RL = obj2->getLeftSide();
            terms.push_back(RL);
        }
        if(obj2->getRightSide()->getType() == "Integer") {
            Expression* RR = obj2->getRightSide();
            terms.push_back(RR);
        }
    }
    return terms;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Addition :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Addition :: getDenominatorFactors(){};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Addition :: simplify(){
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer") {
        string s = to_string(getValue());
        Integer* exactValue = new Integer(s);
        return exactValue;
    }
    else if(!getAdditiveTerms().empty()) {
        int sumOfAdditiveTerms;
        for(int i = 0; i < getAdditiveTerms().size(); i++) {
            sumOfAdditiveTerms += getAdditiveTerms()[i]->getValue();
        }
        Integer* sumOfAdditiveTermsObj = new Integer(to_string(sumOfAdditiveTerms));
    }
    if(obj1->getType() == "Division" && obj2->getType() == "Division") {
        string s = to_string(getValue());
        Integer* exactValue = new Integer(s);
        return exactValue;
    }

};


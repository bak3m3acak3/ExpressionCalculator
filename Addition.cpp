#include "Addition.h"
#include "Expression.h"
#include "Integer.h"
#include "Division.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


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
    vector <Expression*> additiveInts;
    vector <Expression*> additiveDivs;
    vector <Expression*> divTerms;
    vector <Expression*> divTermsCopy;

    terms.push_back(obj1->getLeftSide());
    terms.push_back(obj1->getRightSide());
    terms.push_back(obj2->getLeftSide());
    terms.push_back(obj2->getRightSide());

    for(int i = 0; i < terms.size(); i++) {
        if(terms[i]->getType() == "Integer")
            additiveInts.push_back(terms[i]);
        if(terms[i]->getType() == "Division")
            divTerms.push_back(terms[i]);
    }
    terms.clear();
    if(additiveInts.size() > 1) {
        int sumOfAdditiveTerms = 0;
        for (int i = 0; i < additiveInts.size(); i++) {
            sumOfAdditiveTerms += additiveInts[i]->getValue();
        }
        Integer *sumOfAdditiveTermsObj = new Integer(to_string(sumOfAdditiveTerms));
        terms.push_back(sumOfAdditiveTermsObj);
    }
    // if terms[1] != "Integer", don't add
    else if(additiveInts.size() < 2) {
        Addition *falseObject = new Addition(obj1, obj2);
        terms.push_back(falseObject);
    }

    // copy additiveDivs vector
    for(int i = 0; i < divTerms.size(); i ++) {
        divTermsCopy.push_back(divTerms[i]);
    }

    // search for like denominators, push
    for(int i = 0; i < divTerms.size(); i++) {
        for(int j = 1; j < divTermsCopy.size(); j++) {
            if(divTerms[i]->getRightSide() == divTermsCopy[j]->getRightSide())
                additiveDivs.push_back(divTerms[i]);
        }
    }
    if(additiveDivs.size() > 1) {
        int sumOfNumerators = 0;
        for (int i = 0; i < additiveDivs.size(); i++) {
            sumOfNumerators += additiveDivs[i]->getLeftSide()->getValue();
        }
        Integer *sumOfNumeratorsObj = new Integer(to_string(sumOfNumerators));
        Division *sumOfDivisionTermsObj = new Division(sumOfNumeratorsObj, additiveDivs[1]->getRightSide());
        terms.push_back(sumOfDivisionTermsObj);
    }
    // if terms[1] != "Integer", don't add
    else if(additiveDivs.size() < 2) {
        Addition *falseObject2 = new Addition(obj1, obj2);
        terms.push_back(falseObject2);
    }
    return terms;
//    if((obj1->getType() == "Addition" || obj1->getType() == "Subtraction") && (obj2->getType() == "Addition" || obj2->getType() == "Subtraction")) {
//        if(obj1->getLeftSide()->getType() == "Integer") {
//            Expression* LL = obj1->getLeftSide();
//            additiveInts.push_back(LL);
//        }
//        if(obj1->getRightSide()->getType() == "Integer") {
//            Expression* LR = obj1->getRightSide();
//            additiveInts.push_back(LR);
//        }
//        if(obj2->getLeftSide()->getType() == "Integer") {
//            Expression* RL = obj2->getLeftSide();
//            additiveInts.push_back(RL);
//        }
//        if(obj2->getRightSide()->getType() == "Integer") {
//            Expression* RR = obj2->getRightSide();
//            additiveInts.push_back(RR);
//        }
//        if(obj1->getLeftSide()->getType() == "Division") {
//            Expression* LL = obj1->getLeftSide()->getLeftSide();
//            additiveDivs.push_back(LL);
//        }
//    }
//    return additiveInts;

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
    else if(!getAdditiveTerms().size() >1) {
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


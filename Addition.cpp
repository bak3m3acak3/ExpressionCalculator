#include "Addition.h"
#include "Expression.h"
#include "Integer.h"
#include "Division.h"
#include "Exponentiation.h"
#include "Subtraction.h"
#include "NthRoot.h"
#include "Logarithm.h"
#include "Multiplication.h"
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

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Addition :: getNumeratorFactors(){};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Addition :: getDenominatorFactors(){};


/* Searches 4 items (obj1(left and right) and obj2(left and right)
for Integers or fractions that can be combined */
vector <Expression*> Addition :: getAdditiveTerms() {
    vector<Expression *> terms;
    vector<Expression *> additiveInts;
    vector<Expression *> additiveDivs;
    vector<Expression *> divTerms;
    vector<Expression *> divTermsCopy;
    vector<Expression *> otherTerms;

    if(obj1->getType() == "Subtraction") {
        Subtraction* subObj = new Subtraction(obj1->getLeftSide(), obj1->getRightSide());
        Addition* addObj = subObj->subToAdd();
        obj1 = addObj;
    }
    if(obj2->getType() == "Subtraction") {
        Subtraction* subObj = new Subtraction(obj2->getLeftSide(), obj2->getRightSide());
        Addition* addObj = subObj->subToAdd();
        obj2 = addObj;
    }

    if((obj1->getType() == "Addition" || obj1->getType() == "Subtraction") && (obj2->getType() == "Addition" || obj2->getType() == "Subtraction")) {
        terms.push_back(obj1->getLeftSide());
        terms.push_back(obj1->getRightSide());
        terms.push_back(obj2->getLeftSide());
        terms.push_back(obj2->getRightSide());
    }

    else if((obj1->getType() == "Addition" || obj1->getType() == "Subtraction") && (obj2->getType() == "Integer" || obj2->getType() == "Division")) {
        terms.push_back(obj1->getLeftSide());
        terms.push_back(obj1->getRightSide());
        terms.push_back(obj2);
    }
    else if((obj1->getType() == "Integer" || obj1->getType() == "Division") && (obj2->getType() == "Addition" || obj2->getType() == "Subtraction")) {
        terms.push_back(obj1);
        terms.push_back(obj2->getLeftSide());
        terms.push_back(obj2->getRightSide());
    }
    else if((obj1->getType() == "Integer" || obj1->getType() == "Division") && (obj2->getType() == "Integer" || obj2->getType() == "Division")) {
        terms.push_back(obj1);
        terms.push_back(obj2);
    }

    for (int i = 0; i < terms.size(); i++) {
        if (terms[i]->getType() == "Integer") {
            additiveInts.push_back(terms[i]);
        }
        else if (terms[i]->getType() == "Division") {
            divTerms.push_back(terms[i]);
        }
        else
            otherTerms.push_back(terms[i]);
    }

    // If they only have 1 element, there's nothing to combine
    if(divTerms.size() == 1) {
        otherTerms.push_back(divTerms[0]);
        divTerms.clear();
    }
    if(additiveInts.size() == 1) {
        otherTerms.push_back(additiveInts[0]);
        additiveInts.clear();
    }

    terms.clear();
    if(otherTerms.size() == 1) {
        terms.push_back(otherTerms[0]);
    }
    else if(otherTerms.size() > 1) {
        if(otherTerms.size() == 2) {
            if(!additiveDivs.empty() || !additiveInts.empty()) {
                Addition *addObj = new Addition(otherTerms[0], otherTerms[1]);
                terms.push_back(addObj);
            }
            else {
                terms.push_back(otherTerms[0]);
                terms.push_back(otherTerms[1]);
            }
        }
        else if(otherTerms.size() == 4) {
            Addition* addObj1 = new Addition(otherTerms[0], otherTerms[1]);
            Addition* addObj2 = new Addition(otherTerms[2], otherTerms[3]);
            terms.push_back(addObj1);
            terms.push_back(addObj2);
        }
    }
    if (!additiveInts.empty()) {
        int sumOfAdditiveTerms = 0;
        for (int i = 0; i < additiveInts.size(); i++) {
            sumOfAdditiveTerms += additiveInts[i]->getValue();
        }
        Integer* sumOfAdditiveTermsObj = new Integer(to_string(sumOfAdditiveTerms));
        terms.push_back(sumOfAdditiveTermsObj);
    }

    // copy additiveDivs vector
    for (int i = 0; i < divTerms.size(); i++) {
        divTermsCopy.push_back(divTerms[i]);
    }

    // search for like denominators, push
    for (int i = 0; i < divTerms.size() - 1; i++) {
        for (int j = i + 1; j < divTermsCopy.size(); j++) {
            if (divTerms[i]->getRightSide()->getValue() == divTermsCopy[j]->getRightSide()->getValue()) {
                additiveDivs.push_back(divTerms[i]);
                additiveDivs.push_back(divTermsCopy[j]);
            }
        }
    }

    if (!additiveDivs.empty()) {
        int sumOfNumerators = 0;
        for (int i = 0; i < additiveDivs.size(); i++) {
            sumOfNumerators += additiveDivs[i]->getLeftSide()->getValue();
        }
        Integer *sumOfNumeratorsObj = new Integer(to_string(sumOfNumerators));
        Division *sumOfDivisionTermsObj = new Division(sumOfNumeratorsObj, additiveDivs[1]->getRightSide());
        terms.push_back(sumOfDivisionTermsObj);
    }
    return terms;
}

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Addition :: simplify() {
    obj1 = obj1->simplify();
    obj2 = obj2->simplify();
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer") {
        string s = to_string(getValue());
        Integer* exactValue = new Integer(s);
        return exactValue;
    }
    if((obj1->getType() == "Division" && obj2->getType() == "Division") && (obj1->getRightSide()->getValue() == obj2->getRightSide()->getValue())) {
        cout << "Got into div + div" << endl;
        int sumOfNumerators = obj1->getLeftSide()->getValue() + obj2->getLeftSide()->getValue();
        Integer *sumOfNumeratorsObj = new Integer(to_string(sumOfNumerators));
        Division *sumOfDivisionTermsObj = new Division(sumOfNumeratorsObj, obj2->getRightSide());
        return sumOfDivisionTermsObj;
    }
    else {
        vector <Expression*> simplifiedAdd = getAdditiveTerms();
        Addition* simplifiedAddObj = new Addition(simplifiedAdd[0], simplifiedAdd[1]);
        return simplifiedAddObj;
    }
};


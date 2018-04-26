#include "Division.h"
#include "Expression.h"
#include "Integer.h"
#include <iostream>


// Constructor
Division :: Division(Expression* A, Expression* B) {
    obj1 = A;
    obj2 = B;
}

Division :: ~Division() {
    delete obj1;
    delete obj2;
};

string Division :: getType() {
    return typeID = "Division";
}

int Division :: getValue() {
    return obj1->getValue()/obj2->getValue();
};

Expression* Division :: getLeftSide() {
    return obj1;
}

Expression* Division :: getRightSide() {
    return obj2;
}

/* Returns the individual multiplicative factors of the expression
 * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
vector <Expression*> Division :: getNumeratorFactors() {
    vector <Expression*> numFactors;
    if(obj1->getType() == "Integer") {
        int n = obj1->getValue();
        if(n < 0) {
            n = -1 * n;
        }
        int z = 2;
        while(z * z <= n) {
            if(n % z == 0) {
                string s = to_string(z);
                Integer *intObj = new Integer(s);
                numFactors.push_back(intObj);
                n /= z;
            }
            else z++;
        }
        if(n > 1) {
            string s = to_string(n);
            Integer *intObj = new Integer(s);
            numFactors.push_back(intObj);
        }
    }
    return numFactors;
};

/* Returns the individual multiplicative factors of the expression
 * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
vector <Expression*> Division :: getDenominatorFactors() {
    vector <Expression*> denFactors;
    if(obj2->getType() == "Integer") {
        int n = obj2->getValue();
        int z = 2;
        while(z * z <= n) {
            if(n % z == 0) {
                string s = to_string(z);
                Integer *intObj = new Integer(s);
                denFactors.push_back(intObj);
                n /= z;
            }
            else z++;
        }
        if(n > 1) {
            string s = to_string(n);
            Integer *intObj = new Integer(s);
            denFactors.push_back(intObj);
        }
    }
    return denFactors;
};

/* If the expression is the result of addition or subtraction, returns the individual terms.*/
vector <Expression*> Division :: getAdditiveTerms() {};

/* Signals the expression to produce a simplified version of itself put into lowest terms.*/
Expression* Division :: simplify() {
    obj1 = obj1->simplify();
    obj2 = obj2->simplify();
    if(obj1->getType() == "Integer" && obj2->getType() == "Integer") {
        if(obj1->getValue() < 0 && obj2->getValue() > 0) {
            obj1 = new Integer(to_string(-1 * obj1->getValue()));
            vector<Expression*> numList = getNumeratorFactors();
            vector<Expression*> denomList = getDenominatorFactors();
            int numerator = 1;
            int denominator = 1;

            for(int i = numList.size() - 1; i  >= 0; i--) {
                for(int j = 0; j < denomList.size(); j++) {
                    if(numList[i]->getValue() == denomList[j]->getValue()) {
                        numList.erase(numList.begin() + i);
                        denomList.erase(denomList.begin() + j);
                    }
                }
            }

            for(int i = 0; i < numList.size(); i++)
                numerator *= numList[i]->getValue();
            for(int i = 0; i < denomList.size(); i++)
                denominator *= denomList[i]->getValue();

            Integer* numObj = new Integer(to_string(-1 * numerator));
            Integer* denomObj = new Integer(to_string(denominator));
            Division* divObj = new Division(numObj, denomObj);
            return divObj;
        }
        else if(obj1->getValue() > 0 && obj2->getValue() < 0) {
            obj2 = new Integer(to_string(-1 * obj2->getValue()));
            vector<Expression*> numList = getNumeratorFactors();
            vector<Expression*> denomList = getDenominatorFactors();
            int numerator = 1;
            int denominator = 1;

            for(int i = numList.size() - 1; i  >= 0; i--) {
                for(int j = 0; j < denomList.size(); j++) {
                    if(numList[i]->getValue() == denomList[j]->getValue()) {
                        numList.erase(numList.begin() + i);
                        denomList.erase(denomList.begin() + j);
                    }
                }
            }

            for(int i = 0; i < numList.size(); i++)
                numerator *= numList[i]->getValue();
            for(int i = 0; i < denomList.size(); i++)
                denominator *= denomList[i]->getValue();

            Integer* numObj = new Integer(to_string(numerator));
            Integer* denomObj = new Integer(to_string(-1 * denominator));
            Division* divObj = new Division(numObj, denomObj);
            return divObj;
        }
        else if(obj1->getValue() < 0 && obj2->getValue() < 0) {
            obj1 = new Integer(to_string(-1 * obj1->getValue()));
            obj2 = new Integer(to_string(-1 * obj2->getValue()));
            vector<Expression *> numList = getNumeratorFactors();
            vector<Expression *> denomList = getDenominatorFactors();
            int numerator = 1;
            int denominator = 1;

            for (int i = numList.size() - 1; i >= 0; i--) {
                for (int j = 0; j < denomList.size(); j++) {
                    if (numList[i]->getValue() == denomList[j]->getValue()) {
                        numList.erase(numList.begin() + i);
                        denomList.erase(denomList.begin() + j);
                    }
                }
            }

            for (int i = 0; i < numList.size(); i++)
                numerator *= numList[i]->getValue();
            for (int i = 0; i < denomList.size(); i++)
                denominator *= denomList[i]->getValue();

            Integer *numObj = new Integer(to_string(numerator));
            Integer *denomObj = new Integer(to_string(denominator));
            Division *divObj = new Division(numObj, denomObj);
            return divObj;
        }
        else if(obj1->getValue() > 0 && obj2->getValue() > 0) {
            vector<Expression *> numList = getNumeratorFactors();
            vector<Expression *> denomList = getDenominatorFactors();
            int numerator = 1;
            int denominator = 1;

            for (int i = numList.size() - 1; i >= 0; i--) {
                for (int j = 0; j < denomList.size(); j++) {
                    if (numList[i]->getValue() == denomList[j]->getValue()) {
                        numList.erase(numList.begin() + i);
                        denomList.erase(denomList.begin() + j);
                    }
                }
            }

            for (int i = 0; i < numList.size(); i++)
                numerator *= numList[i]->getValue();
            for (int i = 0; i < denomList.size(); i++)
                denominator *= denomList[i]->getValue();

            Integer *numObj = new Integer(to_string(numerator));
            Integer *denomObj = new Integer(to_string(denominator));
            Division *divObj = new Division(numObj, denomObj);
            return divObj;
        }
        else if(obj1->getValue() == 0 && obj2->getValue() != 0) {
            Integer* intObj = new Integer(to_string(0));
            return intObj;
        }
        else if(obj2->getValue() == 0) {
            cout << "Error: Cannot divide by zero!";
            exit(0);
        }
        else {
            Division* divObj = new Division(obj1, obj2);
            return divObj;
        }
    }
    else {
        Division* divObj = new Division(obj1, obj2);
        return divObj;
    }
};

string Division :: print(){
    return getLeftSide()->print() + " / " + getRightSide()->print();
};

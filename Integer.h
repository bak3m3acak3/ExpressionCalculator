#ifndef EXPRESSIONCALCULATOR_INTEGER_H
#define EXPRESSIONCALCULATOR_INTEGER_H

#include "Expression.h"
#include <string>
using namespace std;

class Integer : public Expression {

private:

    string string1;
    string typeID;

public:

    Integer(string s);

    virtual ~Integer();

    virtual int getValue();

    virtual string getType();

    /* Returns the requested operand for this expression component.*/
    virtual Expression* getLeftSide();

    virtual Expression* getRightSide();

    /* Returns the individual multiplicative factors of the expression
     * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
    virtual vector <Expression*> getNumeratorFactors();

    /* Returns the individual multiplicative factors of the expression
     * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
    virtual vector <Expression*> getDenominatorFactors();

    /* If the expression is the result of addition or subtraction, returns the individual terms.*/
    virtual vector <Expression*> getAdditiveTerms();

    /* Signals the expression to produce a simplified version of itself put into lowest terms.*/
    virtual Expression* simplify();

    virtual string print();

};


#endif //EXPRESSIONCALCULATOR_INTEGER_H

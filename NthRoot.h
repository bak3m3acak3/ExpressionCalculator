#ifndef EXPRESSIONCALCULATOR_NTHROOT_H
#define EXPRESSIONCALCULATOR_NTHROOT_H

#include "Expression.h"
#include <string>

class NthRoot : public Expression {

private:
    Expression* obj1;
    Expression* obj2;
    string typeID;

public:
    NthRoot(Expression A, Expression B);

    virtual ~NthRoot();

    /* Calculates the value of the expression.*/
    virtual int getValue();

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

    virtual string getType();
};


#endif //EXPRESSIONCALCULATOR_NTHROOT_H
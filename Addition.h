#ifndef EXPRESSIONCALCULATOR_ADDITION_H
#define EXPRESSIONCALCULATOR_ADDITION_H

#include "Expression.h"
#include <string>

class Subtraction;

class Addition : public Expression {
// Represents the addition of two expressions, which can be an Integer or one of the other types
// implementing Expression, such as Addition

private:
    Expression* obj1;
    Expression* obj2;
    string typeID;

public:
    Addition(Expression* A, Expression* B);

    virtual ~Addition();

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


#endif //EXPRESSIONCALCULATOR_ADDITION_H

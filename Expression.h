#include <vector>
#include <stack>
using namespace std;
#ifndef EXPRESSIONCALCULATOR_EXPRESSION_H
#define EXPRESSIONCALCULATOR_EXPRESSION_H

// Models a component of a mathematical expression.
class Expression {

public:
    // constructor
    Expression();

    virtual ~Expression();

    /* Calculates the value of the expression.*/
    virtual int getValue() = 0;

    /* Returns the requested operand for this expression component.*/
    virtual Expression* getLeftSide() = 0;

    virtual Expression* getRightSide() = 0;

    /* Returns the individual multiplicative factors of the expression
     * –only those of a positive power. (Thus, belonging in the numerator if fractional.)*/
    virtual vector <Expression*> getNumeratorFactors() = 0;

    /* Returns the individual multiplicative factors of the expression
     * –only those of a negative power. (Thus,* belonging in the denominator if fractional.)*/
    virtual vector <Expression*> getDenominatorFactors() = 0;

    /* If the expression is the result of addition or subtraction, returns the individual terms.*/
    virtual vector <Expression*> getAdditiveTerms() = 0;

    /* Signals the expression to produce a simplified version of itself put into lowest terms.*/
    virtual Expression* simplify() = 0;

//    stack <Expression*> opStack;
//
//    vector <Expression*> parsedList;
//
    virtual string getType() = 0;

    virtual string print() = 0;

    static bool isInt(Expression* a);
};



#endif //EXPRESSIONCALCULATOR_EXPRESSION_H

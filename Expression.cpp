#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
#include "Expression.h"

class Expression {

public:
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

    virtual stack <Expression*> opStack;

    virtual vector <Expression*> parsedList;

    bool stringIsDigits(const string s) {
        return s.find_first_not_of( "0123456789" ) == string::npos;
    }

    bool hasOnlyDigits(const string s) {
        return s.find_first_not_of( "0123456789" ) == string::npos;
    }

   // getType() ??

};

class Integer : public Expression {
// Represents a simple integer.
// The value of an integer is the integer itself.

public:
    // Constructor
    Integer :: Integer(string s) {

        int value = atoi(s.c_str());

        int getValue() {
            return value;
        }
    }
};

class Addition : public Expression {
// Represents the addition of two expressions, which can be an Integer or one of the other types
// implementing Expression, such as Addition

public:
    //constructor
    Addition :: Addition(Expression* A, Expression* B) {

        Expression* getLeftSide() {
            return A;
        }

        Expression* getRightSide() {
            return B;
        }

        vector <Expression*> getAdditiveTerms() {
            if(A || B)
        }

        int getValue() {
            if(A && B)
            return A + B;
        }

        Expression* simplify() {

        }
    }
};

class Subtraction : public Expression {
// Like addition, but with a flipped sign on the second operand.

public:
    // Constructor
    Subtraction :: Subtraction(Expression* A, Expression* B) {

        Expression* getLeftSide() {
            return A;
        }
        Expression* getRightSide() {
            return B;
        }
    }


};

class Multiplication : public Expression {
// Models multiplying two expressions together.

public:
    // Constructor
    Multiplication :: Multiplication(Expression* A, Expression* B) {

        Expression* getLeftSide() {
            return A;
        }

        Expression* getightSide() {
            return B;
        }
    }

};

class Division : public Expression {
// Great for representing fractions.

public:
    // Constructor
    Division :: Division(Expression* A, Expression* B) {
        Expression* getLeftSide() {
            return A;
        }

        Expression* getightSide() {
            return B;
        }
    }

};

class Exponentiation : public Expression {

public:
    // Constructor
    Exponentiation :: Exponentiation(Expression* A, Expression* B) {

        Expression* getLeftSide() {
            return A;
        }

        Expression* getightSide() {
            return B;
        }
    }

};

class NthRoot : public Expression {

};

class Logarithm : public Expression {

};

int main() {

}

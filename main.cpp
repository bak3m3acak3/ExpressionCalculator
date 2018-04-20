#include <iostream>
#include "Integer.h"
#include "Addition.h"
#include <vector>

int main() {
    Integer* integer1 = new Integer("1");
    Integer* integer2 = new Integer("-2");
    Addition* add1 = new Addition(integer1, integer2);
    Integer* integer3 = new Integer("6");
    Integer* integer4 = new Integer("-9");
    Addition* add2 = new Addition(integer3, integer4);
    Addition* add3 = new Addition(add1, add2);

    vector <Expression*> addTerms = add3->getAdditiveTerms();

    for(int i = 0; i < addTerms.size(); i++)
        cout << addTerms[i]->getValue() << endl;

    delete add3;
}
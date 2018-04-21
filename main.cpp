#include <iostream>
#include "Integer.h"
#include "Addition.h"
#include "Division.h"
#include <vector>

int main() {
    Integer* integer1 = new Integer("1");
    Integer* integer5 = new Integer("3");
    Integer* integer2 = new Integer("-2");
    Division* division1 = new Division(integer1, integer5);
    Addition* add1 = new Addition(division1, integer2);
    Integer* integer3 = new Integer("2");
    Integer* integer6 = new Integer("3");
    Integer* integer4 = new Integer("-9");
    Division* division2 = new Division(integer3, integer6);
    Addition* add2 = new Addition(division2, integer4);
    Addition* add3 = new Addition(add1, add2);

    vector <Expression*> addTerms = add3->getAdditiveTerms();

    for(int i = 0; i < addTerms.size(); i++)
        cout << addTerms[i]->getType() << endl;

    delete add3;
}
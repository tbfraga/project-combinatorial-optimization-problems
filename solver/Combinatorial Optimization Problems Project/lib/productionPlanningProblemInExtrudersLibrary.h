#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include <iostream>
using namespace std;

namespace productionPlanningProblemInExtrudersLibrary
{
    class productionPlanningProblemInExtruders
    {
        int _NDays;
        int _NExtruders;

        public:

        productionPlanningProblemInExtruders(int, int);

        void printProblem();

    };
}


#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

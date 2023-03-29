#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;



namespace productionPlanningProblemInExtrudersLibrary
{
    class productionPlanningProblemInExtruders
    {
        int _NDays;
        int _NExtruders;
        vector<int> _productionRate;

        public:

        productionPlanningProblemInExtruders(int, int, vector<int>);

        void printProblem();
    };
}


#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

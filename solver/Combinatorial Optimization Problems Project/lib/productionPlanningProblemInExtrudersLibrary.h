#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;



namespace productionPlanningProblemInExtrudersLibrary
{
    class productionPlanningProblemInExtruders
    {
        unsigned int _NDays;
        unsigned int _NExtruders;
        vector<float> _productionRate;
        vector<float> _length;
        vector<int> _capacity;

        public:

        productionPlanningProblemInExtruders(unsigned int, unsigned int, vector<float>, vector<float>, vector<int>);
        ~productionPlanningProblemInExtruders();

        void printProblem();
    };
}


#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

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
        int _setupTime;
        float _setupCost;
        float _operationCost;

        unsigned int _NProducts;
        vector<float> _width;
        vector<float> _weightRatio;
        vector<float> _unitContribution;
        vector<int> _initialInventory;
        vector<int> _maximumInventory;
        int _totalMaximumInventory;
        float _inventoryUnitCost;

        vector<vector<int>> _demand;
        float _unmetDemandCost;

        vector<vector<bool>> _colorAndMaterialRatio;

        unsigned int _NOutlets;
        vector<int> _maximumTotalOutletInventory;

        vector<vector<int>> _maximumOutletInventoryPerProduct;

        public:

        productionPlanningProblemInExtruders(unsigned int, unsigned int, vector<float>, vector<float>, vector<int>, int, float, float, unsigned int, vector<float>, vector<float>,
        vector<float>, vector<int>, vector<int>, int, float, vector<vector<int>>, float, vector<vector<bool>>, unsigned int, vector<int>, vector<vector<int>>);
        ~productionPlanningProblemInExtruders();

        void printProblem();
    };
}


#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

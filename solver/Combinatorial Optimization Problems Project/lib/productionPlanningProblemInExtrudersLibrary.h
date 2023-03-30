#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

namespace productionPlanningProblemInExtrudersLibrary
{
    class productionPlanningProblemInExtruder
    {
        protected:

        unsigned int _NDays = 0;

        unsigned int _NExtruders = 0;
        vector<float> _productionRate = {0};
        vector<float> _length = {0};
        vector<int> _capacity = {0};
        int _setupTime = 0;
        float _setupCost = 0;
        float _operationCost = 0;

        unsigned int _NProducts = 0;
        vector<float> _width = {0};
        vector<float> _weightRatio = {0};
        vector<float> _unitContribution = {0};
        vector<int> _initialInventory = {0};
        vector<int> _maximumInventory = {0};
        int _totalMaximumInventory = 0;
        float _inventoryUnitCost = 0;

        vector<vector<int>> _demand = {{0}};
        float _unmetDemandCost = 0;

        vector<vector<bool>> _colorAndMaterialRatio = {{0}};

        unsigned int _NOutlets = 0;
        vector<int> _maximumTotalOutletInventory = {0};

        vector<vector<int>> _maximumOutletInventoryPerProduct = {{0}};

        public:
        productionPlanningProblemInExtruder() = default;
        productionPlanningProblemInExtruder(unsigned int, unsigned int, vector<float>, vector<float>, vector<int>, int, float, float, unsigned int, vector<float>, vector<float>,
        vector<float>, vector<int>, vector<int>, int, float, vector<vector<int>>, float, vector<vector<bool>>, unsigned int, vector<int>, vector<vector<int>>);

        ~productionPlanningProblemInExtruder();

        void printProblem();
    };

    class PPPIEInstance: public productionPlanningProblemInExtruder
    {
        public:

        void PPPIE001();
    };

}
#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

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

        // problem definition parameters

        unsigned int _NDays = 0;

        unsigned int _NExtruders = 0;
        vector<float> _productionRate = {0};
        vector<float> _length = {0};
        vector<vector<unsigned int>> _capacity = {{0}};
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

        vector<vector<unsigned int>> _demand = {{0}};
        float _unmetDemandCost = 0;

        vector<unsigned int> _color = {0};
        vector<vector<bool>> _colorAndMaterialRatio = {{0}};

        vector <vector <unsigned int>> _setupTime = {{0}};

        unsigned int _NOutlets = 0;
        vector<int> _maximumTotalOutletInventory = {0};

        vector<vector<int>> _maximumOutletInventoryPerProduct = {{0}};

        // solution variables

        vector<vector<unsigned int>> _balancing = {{0}};
        vector<vector<unsigned int>> _allocation = {{0}};
        vector<double> _processingTime = {0};

        // secondary variables

        vector<float> _batchWidth = {0};
        vector<float> _batchIdleness = {0};
        vector<vector<float>> _extruderProcTime = {{0}};
        vector<float> _extruderIdleness = {0};

        vector<vector<unsigned int>> _restricted = {{0}};
        // variable that informs the type of constraint not met and the index that informs the location of the error
        // restricted[1][b] indicates that the width of batch <b> is greater than the extruder can handle.

        vector<unsigned int> _production = {0};

        public:
        productionPlanningProblemInExtruder() = default;
        productionPlanningProblemInExtruder(unsigned int, unsigned int, vector<float>, vector<float>, vector<vector<unsigned int>>, float, float, unsigned int, vector<float>, vector<float>,
        vector<float>, vector<int>, vector<int>, int, float, vector<vector<unsigned int>>, float, vector<unsigned int>, vector<vector<bool>>,  vector <vector <unsigned int>>, unsigned int, vector<int>,
        vector<vector<int>>);

        ~productionPlanningProblemInExtruder();

        void clearAll();
        void clearSolution();
        void printProblem();
        void generateSolution();
        void evaluateSolution();
        void printSolution();
    };

    class PPPIEInstance: public productionPlanningProblemInExtruder
    {
        public:

        void PPPIE001();
    };

}
#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

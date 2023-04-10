#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include <iostream>
#include <vector>
//#include <random>
#include <ctime>
using namespace std;

namespace productionPlanningProblemInExtrudersLibrary
{
    class productionPlanningProblemInExtruder;
    class PPPIESolution;

    class productionPlanningProblemInExtruder
    {
        friend class PPPIESolution;
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
        vector<unsigned int> _productionLimit = {0};
        vector<unsigned int> _initialInventory = {0};
        vector<unsigned int> _maximumInventory = {0};
        unsigned int _totalMaximumInventory = 0;
        float _inventoryUnitCost = 0;

        vector<vector<unsigned int>> _demand = {{0}};
        float _unmetDemandCost = 0;

        vector<unsigned int> _color = {0};
        vector<vector<bool>> _colorAndMaterialRatio = {{0}};

        vector<vector<unsigned int>> _setupTime = {{0}};

        vector<vector<unsigned int>> _productionPerTime = {{0}};

        unsigned int _NOutlets = 0;
        vector<unsigned int> _totalMaximumOutletInventory = {0};

        vector<vector<unsigned int>> _maximumOutletInventory = {{0}};

        public:
        productionPlanningProblemInExtruder() = default;
        productionPlanningProblemInExtruder(unsigned int, unsigned int, vector<float>, vector<float>, vector<vector<unsigned int>>, float, float, unsigned int,
        vector<float>, vector<float>, vector<float>, vector<unsigned int>, vector<unsigned int>, unsigned int, float, vector<vector<unsigned int>>,
        float, vector<unsigned int>, vector<vector<bool>>,  vector <vector <unsigned int>>, unsigned int, vector<unsigned int>, vector<vector<unsigned int>>);

        ~productionPlanningProblemInExtruder();

        void clearProblem();
        void restartProblem();
        void printProblem();
    };

    class PPPIEInstance: public productionPlanningProblemInExtruder
    {
        public:

        void PPPIE001();
    };

    class PPPIESolution
    {
        friend class PPPIEInstance;
        protected:

        // solution variables

        vector<vector<unsigned int>> _balancing = {{0}};
        vector<vector<unsigned int>> _allocation = {{0}};
        vector<unsigned int> _processingTime = {0};

        // secondary variables

        vector<float> _batchWidth = {0};
        vector<float> _batchIdleness = {0};
        vector<vector<unsigned int>> _extruderProcTime = {{0}};
        vector<vector<unsigned int>> _extruderIdleness = {{0}};

        vector<vector<unsigned int>> _restricted = {{0}};
        // variable that informs the type of constraint not met and the index that informs the location of the error
        // restricted[1][b] indicates that the width of batch <b> is greater than the extruder can handle.

        vector<vector<unsigned int>> _production = {{0}};
        vector<vector<unsigned int>> _delivered = {{0}};
        vector<vector<unsigned int>> _unmetDemand = {{0}};
        vector<vector<vector<unsigned int>>> _deliveredToOutlet = {{{0}}};
        vector<unsigned int> _totalFreeOutletInventory = {0};
        vector<vector<unsigned int>> _freeOutletInventory = {{0}};
        vector<vector<unsigned int>> _inventory = {{0}};
        vector<unsigned int> _freeInventory = {0};
        vector<vector<unsigned int>> _freeInventoryPerProduct = {{0}};

        double _fitness = 0;
        double _productionTotalProfit = 0;
        double _unmetDemandTotalCost = 0;
        double _inventoryTotalCost = 0;

        public:

        void clearSolution();
        void restartSolution(PPPIEInstance problem);
        void generateSolution(PPPIEInstance);
        void evaluateSolution(PPPIEInstance);
        void swapTime(PPPIEInstance);
        void swapSolution(PPPIEInstance);
        void timeSimultedAnnealing(PPPIEInstance);
        void printSolution();
    };

}
#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

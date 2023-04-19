// Combinatorial Optimization Solver
//
// software created by Tatiana Balbi Fraga
//
// lib file
//
// PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H

#ifndef PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED
#define PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

#include<math.h>

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
        vector<unsigned int> _initialInventory = {0};
        vector<unsigned int> _maximumInventory = {0};
        unsigned int _totalMaximumInventory = 0;
        float _inventoryUnitCost = 0;

        vector<vector<unsigned int>> _demand = {{0}};
        float _unmetDemandCost = 0;

        unsigned int _NColors;
        vector<unsigned int> _color = {0};
        vector<vector<bool>> _colorAndMaterialRatio = {{0}};

        vector<vector<unsigned int>> _setupTime = {{0}};

        vector<vector<unsigned int>> _productionPerTime = {{0}};

        unsigned int _NOutlets = 0;
        vector<unsigned int> _totalMaximumOutletInventory = {0};

        vector<vector<unsigned int>> _maximumOutletInventory = {{0}};

        //auxiliary

        vector<vector<unsigned int>> _productColorGroup = {{0}};

        public:
        productionPlanningProblemInExtruder() = default;
        productionPlanningProblemInExtruder(unsigned int, unsigned int, vector<float>, vector<float>, vector<vector<unsigned int>>, float, float, unsigned int,
        vector<float>, vector<float>, vector<float>, vector<unsigned int>, vector<unsigned int>, unsigned int, float, vector<vector<unsigned int>>,
        float, vector<unsigned int>, vector<vector<bool>>,  vector <vector <unsigned int>>, unsigned int, vector<unsigned int>, vector<vector<unsigned int>>);

        ~productionPlanningProblemInExtruder();

        void clearProblem();
        void restartProblem();
        void print();
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

        // problem linked to the solution

        PPPIEInstance _problem;

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

        vector<vector<unsigned int>> _productionLimit = {{0}};
        vector<vector<unsigned int>> _production = {{0}};
        vector<vector<unsigned int>> _delivered = {{0}};
        vector<vector<unsigned int>> _unmetDemand = {{0}};
        vector<vector<vector<unsigned int>>> _deliveredToOutlet = {{{0}}};
        vector<unsigned int> _totalFreeOutletInventory = {0};
        vector<vector<unsigned int>> _freeOutletInventory = {{0}};
        vector<vector<unsigned int>> _inventory = {{0}};
        vector<unsigned int> _totalFreeInventory = {0};
        vector<vector<unsigned int>> _freeInventory = {{0}};

        double _fitness = 0;
        double _productionTotalProfit = 0;
        double _unmetDemandTotalCost = 0;
        double _inventoryTotalCost = 0;

        //auxiliary

        vector<vector<unsigned int>> _batchColorGroup = {{0}};

        public:

        void clear();
        void restartSolution(PPPIEInstance problem);
        void print();
        void generateSolution(PPPIEInstance);
        unsigned int productionLimit(PPPIEInstance problem, unsigned int product, unsigned int day);
        void include(PPPIEInstance problem, vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time);
        // create new batch and adjust linked variables
        void increase(unsigned int production, unsigned int product, unsigned int day);
        // increase production and adjust linked variables
        void timeSimultedAnnealing(PPPIEInstance, unsigned int NMaxIte);
        PPPIESolution autoCopy();
        void set(PPPIESolution solution);
        void swapTime(PPPIEInstance);
        void reduction(PPPIEInstance problem, unsigned int production, unsigned int product, unsigned int day);
        void swapProduct(PPPIEInstance);
        void include(PPPIEInstance problem, unsigned int product, unsigned int batch);
        // include product on batch and adjust linked variables
        void randomErase(PPPIEInstance problem, unsigned int batch);
        void erase(unsigned int location);
        void split(PPPIEInstance problem, unsigned int batch, unsigned int time);
        void processingTime(PPPIEInstance problem, unsigned int batch, unsigned int time);
        vector<unsigned int> productList(unsigned int batch);
        void insert(unsigned int product, unsigned int batch);
    };

}
#endif // PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H_INCLUDED

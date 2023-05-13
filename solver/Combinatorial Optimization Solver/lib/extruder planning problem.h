/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/project-combinatorial-optimization-problems/tree/main/solver/Combinatorial%20Optimization%20Solver.
******************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// Extruder Planning Problem Library
// developed by Tatiana Balbi Fraga
// start date: 2023/04/26
// last modification: 2023/05/13

#ifndef EXTRUDER_PLANNING_PROBLEM_H_INCLUDED
#define EXTRUDER_PLANNING_PROBLEM_H_INCLUDED

#include<math.h>

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

namespace extruderPlanningProblemLibrary
{
    class extruderPlanningProblem;
    class PPPIEInstance;
    class EPPSolution;

    class extruderPlanningProblem
    {
        friend class EPPSolution;

        protected:

        // these paramenters define an instance of an EPP (Exturder Planning Problem)

        // problem definition parameters

        unsigned int _NDays = 0; // number of planning days

        // *** parameters linked to extruders

        unsigned int _NExtruders = 0; // number of extruders
        vector<float> _productionRate = {0}; // production rate of extruder (m/min)
        vector<float> _length = {0}; // extruder length (m)
        vector<vector<unsigned int>> _capacity = {{0}}; // extruder capacity (min)
        float _setupCost = 0; // setup cost per minute ($/min)
        float _operationCost = 0; // operation cost per minute ($/min)

        // *** parameters linked to products

        unsigned int _NProducts = 0; // number of products
        vector<float> _width = {0}; // product width (m)
        vector<float> _weightRatio = {0}; // product weight ratio (g/m^2)
        vector<float> _unitContribution = {0}; // unit contribution ($/g)
        vector<unsigned int> _initialInventory = {0}; // product initial inventory at factory (g)
        vector<unsigned int> _maximumInventory = {0}; // product maximum inventory at factory (g)
        unsigned int _totalMaximumInventory = 0; // total maximum inventory at factory (g)
        float _inventoryUnitCost = 0; // inventory unit cost ($/g)

        vector<vector<unsigned int>> _demand = {{0}}; // product demand (g)
        float _unmetDemandCost = 0; // unmet demand cost ($/g)

        unsigned int _NColors; // number of different product colors
        vector<unsigned int> _color = {0}; // product color
        vector<vector<bool>> _colorAndMaterialRatio = {{0}}; // relation of products of same color and material

        vector<vector<unsigned int>> _setupTime = {{0}}; // setup time related with some pair of colors (min)

        vector<vector<unsigned int>> _productionPerTime = {{0}}; // production of each product per minute on each extruder (g/min)

        // *** paramenters linked to outlets

        unsigned int _NOutlets = 0; // number of outlets
        vector<unsigned int> _totalMaximumOutletInventory = {0}; // maximum outlet inventory (g)

        vector<vector<unsigned int>> _maximumOutletInventory = {{0}}; // maximum outlet inventory per product (g)

        //auxiliary

        vector<vector<unsigned int>> _productColorGroup = {{0}}; // variable defined to classify products by color and material
                                                                 // products of same color and material can be processed on a same batch
        public:

        bool print();
        bool print(ofstream &file);

        void clear();
        void restart();
    };

    // class for creating instances of EPP (Extruder Planning Problem)

    class EPPInstance: public extruderPlanningProblem
    {
        public:

        void EPP001();
    };

    // class for solving an EPP

    class EPPSolution
    {
        //friend class EPPInstance;

        protected:

        // solution variables

        // problem linked to the solution

        EPPInstance _problem; // EPP

        // solution variables

        vector<vector<unsigned int>> _balancing = {{0}}; // for assigning product to batch
        vector<vector<unsigned int>> _allocation = {{0}}; // for assingning batch to extruder and day
        vector<unsigned int> _processingTime = {0}; // batch processing time

        // secondary variables - calculated

        vector<float> _batchWidth = {0}; // batch width
        vector<float> _batchIdleness = {0}; // batch idleness
        vector<unsigned int> _batchColor = {0}; // batch color - replacing _allocation[batch][4]
        //vector<unsigned int> _batchColor = {0}; // batch color
        vector<vector<unsigned int>> _extruderProcTime = {{0}}; // extruder processing time
        vector<vector<unsigned int>> _extruderIdleness = {{0}}; // extruder idleness

        // vector<vector<unsigned int>> _restricted = {{0}}; // I won't use it for now
        // variable that informs the type of constraint not met and the index that informs the location of the error
        // restricted[1][b] indicates that the width of batch <b> is greater than the extruder can handle.

        vector<vector<unsigned int>> _production = {{0}}; // production
        vector<vector<unsigned int>> _delivered = {{0}}; // delivered
        vector<vector<unsigned int>> _unmetDemand = {{0}}; // unmet demand
        vector<vector<vector<unsigned int>>> _deliveredToOutlet = {{{0}}}; // delivered to outlet
        vector<unsigned int> _totalFreeOutletInventory = {0}; // free outlet inventory
        vector<vector<unsigned int>> _freeOutletInventory = {{0}}; // free outlet inventory by product
        vector<vector<unsigned int>> _inventory = {{0}}; // inventory at factory
        vector<unsigned int> _totalFreeInventory = {0}; // free inventory at factory
        vector<vector<unsigned int>> _freeInventory = {{0}}; // free inventory at factory by product

        double _fitness = 0; // fitness: profit = production profit - unmet demand cost - inventory cost
        double _productionTotalProfit = 0; // production profit
        double _unmetDemandTotalCost = 0; // unmet demand cost
        double _inventoryTotalCost = 0; // inventory cost

        //auxiliary

        vector<vector<unsigned int>> _batchColorGroup = {{0}}; // batch grouped by color

        int _i_print = 0;
        // _i_print = 0 - print only no restricted
        // _i_print = 1 - print only functions head
        // _i_print = 2 - print only PC informations
        // _i_print = 3 - print pertubation operator informations

        bool _SA_print = 0;
        bool _PCP_print = 0;
        bool _PCRE_print = 0;
        bool _PCR_print = 0;

        bool _fprint = 1;

        // functions

        public:

        void clear();
        bool print();
        bool print(unsigned int type);

        bool print(ofstream &file);
        bool print(unsigned int type, ofstream &file);

        void restart(EPPInstance problem);
        void generate();

        unsigned int productionLimit(unsigned int product, unsigned int day);
        bool insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time);
        bool increase(unsigned int production, unsigned int product, unsigned int day);
        bool deliver(unsigned int product);
        void forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution);
        void forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution, unsigned int &unmet);


        void simultedAnnealing(unsigned int NMaxIte);
        EPPSolution autoCopy();
        void set(EPPSolution solution);
        bool swapTime();
        void reduce(unsigned int production, unsigned int product, unsigned int day);

        void particleCollision(unsigned int NMaxIte, unsigned int NMaxIteSA);
        void swapProduct();
        bool insert(unsigned int product);
        bool include(unsigned int product, unsigned int batch);
        bool split(unsigned int batch, unsigned int time);
        vector<unsigned int> productList(unsigned int batch);
        void processingTime(unsigned int batch, unsigned int time);
        void randomErase(unsigned int batch);
        bool erase(unsigned int location);
        bool insert(unsigned int product, unsigned int batch);
        bool clean(unsigned int cleanType);
        unsigned int find(vector<unsigned int> UIVector, unsigned int value);

        bool verify();
    };
}

#endif // EXTRUDER_PLANNING_PROBLEM_H_INCLUDED

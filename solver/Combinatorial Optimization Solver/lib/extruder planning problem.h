/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.
****************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// Extruder Planning Problem Library
// developed by Tatiana Balbi Fraga
// start date: 2023/04/26
// last modification: 2023/04/26

#ifndef EXTRUDER_PLANNING_PROBLEM_H_INCLUDED
#define EXTRUDER_PLANNING_PROBLEM_H_INCLUDED

#include<iostream>
#include<vector>
using namespace std;

namespace extruderPlanningProblemLibrary
{
    class extruderPlanningProblem;
    class PPPIEInstance;

    class extruderPlanningProblem
    {
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

        vector<vector<unsigned int>> _productionPerTime = {{0}}; // production of each product per minute on each extruder

        // *** paramenters linked to outlets

        unsigned int _NOutlets = 0; // number of outlets
        vector<unsigned int> _totalMaximumOutletInventory = {0}; // maximum outlet inventory (g)

        vector<vector<unsigned int>> _maximumOutletInventory = {{0}}; // maximum outlet inventory per product (g)

        //auxiliary

        vector<vector<unsigned int>> _productColorGroup = {{0}}; // variable defined to classify products by color and material
                                                                 // products of same color and material can be processed on a same batch
        public:

        bool print();
        void clear();
        void restart();
    };

    class EPPInstance: public extruderPlanningProblem
    {
        public:

        void EPP001();
    };
}

#endif // EXTRUDER_PLANNING_PROBLEM_H_INCLUDED

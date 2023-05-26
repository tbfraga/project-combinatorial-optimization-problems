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
// last modification: 2023/05/26

#ifndef EXTRUDER_PLANNING_PROBLEM_H
#define EXTRUDER_PLANNING_PROBLEM_H

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

namespace epp
{
    class extruderPlanningProblem
    {
        protected:

        // these paramenters define an instance of an Exturder Planning Problem

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

        // *** functions

        public:

        void clear();

        bool restart(); // this function can be also used for verifying if informed data is ok - correct correspondence of dimensions of linked paramenters

        bool print();
        bool print(ofstream &file);
    };

    // class for creating instances of Extruder Planning Problem

    class EPP: public extruderPlanningProblem
    {
        public:

        void EPP001();
    };
}


#endif // EXTRUDER_PLANNING_PROBLEM_H

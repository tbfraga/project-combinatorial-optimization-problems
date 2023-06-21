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
// last modification: 2023/05/29

#ifndef EXTRUDER_PLANNING_PROBLEM_H
#define EXTRUDER_PLANNING_PROBLEM_H

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#include<math.h>

#include "multiproduct batch processing time maximization problem.h"

namespace epp
{
    class extruderPlanningProblem
    {
        friend class solution;

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

        void clear(); // this function clear memory allocated to vector type parameters and dependent variables used to represent an EPP

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

    // class for solving an extruder planning problem

    class solution
    {
        protected:

        EPP _problem; // EPP linked to the solution
        mpbptmp::MPBPTMP _subProblem; //
        mpbptmp::solution _subSolution;

        // primary variables

        vector<vector<unsigned int>> _balancing = {{0}}; // for assigning product to batch
        vector<vector<unsigned int>> _allocation = {{0}}; // for assingning batch to extruder and day
        vector<unsigned int> _processingTime = {0}; // batch processing time

        // secondary variables - calculated

        vector<float> _batchWidth = {0}; // batch width (m)
        vector<float> _batchIdleness = {0}; // batch idleness (m)
        vector<unsigned int> _batchColor = {0}; // batch color
        vector<vector<unsigned int>> _extruderProcTime = {{0}}; // extruder processing time (min)
        vector<vector<unsigned int>> _extruderIdleness = {{0}}; // extruder idleness (min)

        // vector<vector<unsigned int>> _restricted = {{0}}; // I won't use it for now
        // variable that informs the type of constraint not met and the index that informs the location of the error
        // restricted[1][b] indicates that the width of batch <b> is greater than the extruder can handle.

        vector<vector<unsigned int>> _production = {{0}}; // production
        vector<vector<unsigned int>> _delivered = {{0}}; // delivered to demand
        vector<vector<unsigned int>> _unmetDemand = {{0}}; // unmet demand
        vector<vector<vector<unsigned int>>> _deliveredToOutlet = {{{0}}}; // delivered to outlet
        vector<unsigned int> _totalFreeOutletInventory = {0}; // free outlet inventory
        vector<vector<unsigned int>> _freeOutletInventory = {{0}}; // free outlet inventory by product
        vector<vector<unsigned int>> _inventory = {{0}}; // inventory at factory
        vector<unsigned int> _totalFreeInventory = {0}; // free inventory at factory
        vector<vector<unsigned int>> _freeInventory = {{0}}; // free inventory at factory by product
        vector<vector<unsigned int>> _productionLimit = {{0}}; // maximum production allowed for products by day

        double _fitness = 0; // fitness: profit = production profit - unmet demand cost - inventory cost
        double _productionTotalProfit = 0; // production profit
        double _unmetDemandTotalCost = 0; // unmet demand cost
        double _inventoryTotalCost = 0; // inventory cost

        //auxiliary

        vector<vector<unsigned int>> _batchColorGroup = {{0}}; // batch grouped by color

        // print parameters

        bool _hprint = 0; // if _hprint == 1 solver will print all functions head on screen - usualy used to find bugs
        bool _fprint = 0; // if _fprint == 1 solver will print everything on differente files

        // I'll also use some print parameter inside functions, so I can see solver results on screen

        public:

        // functions

        void clear(); // this function clears vector type solution variables

        void print(); // this function prints a complete soltuion
        void print(unsigned int type); // this function prints some part of the solution as specified by parameter <type>

        void print(ofstream &file); // this function prints a complete soltuion on file
        void print(unsigned int type, ofstream &file); // this function prints some part of the solution on file as specified by parameter <type>

        bool verify(); // this function verifies if solution is feaseble
        void set(solution solution); // this function sets the values of current solution
        solution copy(); // this function creates a copy of the current solution by delivering this value to a variable of type solution

        void restart(EPP problem); // this function initializes solution variables
        unsigned int productionLimit(unsigned int product, unsigned int day); // this function calculates the maximum production allowed for products
        unsigned int timeLimit(unsigned int batch); // this function calculates the maximum processing time allowed for a set of products

        bool deliver(unsigned int product, ofstream &file); // this function distributes production of <product> to demand, outlets and inventory
        void backwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution);
        void forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution);

        bool processingTime(unsigned int batch, unsigned int time, ofstream &file); // this function changes the processing time of a batch and changes linked variables accordly
        bool reduce(unsigned int amount, unsigned int product, unsigned int day, ofstream &file); // this function reduces the production of some product at corresponding day
                                                                                                  // while changing processing time of one of its batches
        bool increase(unsigned int production, unsigned int product, unsigned int day, ofstream &file); // this function increases the production of some product at corresponding day
                                                                                                        // while changing processing time of one of its batches
        bool erase(unsigned int location, ofstream &file); // this function excludes the product of _balancing <location> from its batch
        bool insert(unsigned int product, unsigned int batch, ofstream &file); // this function includes <product> on <batch>

        bool insert(unsigned int product, ofstream &file); // this functions creates a ramdom batch with only one <product>
        bool include(unsigned int product, unsigned int batch, ofstream &file); // this function includes <product> on <batch> and adjust linked variables

        bool randomErase(unsigned int batch, ofstream &file); // this function ramdomly choose a product and erase it from the <batch>
        bool eraseAll(unsigned int batch, ofstream &file); // this function erases all products on batch

        bool clean(ofstream &file); // this function erases from solution batches with empty processing times
        unsigned int find(vector<unsigned int> UIVector, unsigned int value); // auxiliar function

        void generate(ofstream &file); // this function generates a feasible initial solution
        bool insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time, ofstream &file); // this function creates a new batch

        void simultedAnnealing(unsigned int NMaxIte, ofstream &file); // this function applies a Simulated Annealing method for improving batches processing times
        bool swapTime(ofstream &file); // this function ramdomly changes a batch processing time

        void particleCollision(unsigned int NMaxIte, unsigned int NMaxIteSA); // this function applies a Particle Collision method for improving solution
        void swapProduct(ofstream &file); // this function allocates some product randonly choosed on batch
                                          // if _batchIdleness is not enought for allocating product on batch, other products will be excluded from batch
                                          // if product color is not the same of batch color, all products on batch will be excluded before new product allocation
                                          // and the color of batch will change to the color of product
    };
}


#endif // EXTRUDER_PLANNING_PROBLEM_H

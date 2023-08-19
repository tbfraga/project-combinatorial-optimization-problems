/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

Obs: You can alter this file only for personal purpose. You cannot distribute altered version.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/COPSolver.
******************************************************************************************************************************************************************************/

// COPSolver (Combinatorial Optimization Problems Solver)
// version: V02_2023_07_31
// developed by Tatiana Balbi Fraga
// start date: 2023/07/31
// last modification: 2023/08/04

#ifndef MULTIPERIOD_MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED
#define MULTIPERIOD_MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED

#include "multiproduct-batch-processing-time-maximization-problem.h"

namespace mmbptm
{
    class multiperiodMultiproductBatchProcessingTimeMaximizationProblem
    {
        friend class solution;

        protected:

        unsigned int _NProducts = 0; // number of products
        unsigned int _NDays = 0; // number of days
        unsigned int _NOutlets = 0; // number of outlets

        vector<float> _productionRate = {0}; // weight ratio per product (g/m^2)

        vector<vector<unsigned int>> _demand = {{0}}; // demand per product per day (g)

        vector<vector<unsigned int>> _planned = {{0}}; // planned production per product per day (g)

        vector<vector<unsigned int>> _maximumOutletInventory = {{0}}; // maximum outlet inventory per product per outlet (g)
        vector<unsigned int> _totalMaximumOutletInventory = {0}; // total maximum outlet inventory per outlet (g)

        vector<unsigned int> _maximumInventory = {0}; // maximum inventory at factory per product (g)
        unsigned int _totalMaximumInventory = 0; // total maximum inventory at factory (g)

        unsigned int _maxBatchProcessingTime = 0; // maximum batch processing time (min)

        public:

        void clear();
        bool print();
        bool generateLingoData();

        bool get();
        void set(unsigned int NProducts, vector<float> productionRate, vector<unsigned int> demand, vector<unsigned int> maximumInventory, unsigned int totalMaximumInventory,
                vector<unsigned int> maximumOutletInventory, unsigned int totalMaximumOutletInventory, unsigned int maxBatchProcessingTime);
    };

    // class for creating instances of max multiproduct batch time problem

    class problem: public multiperiodMultiproductBatchProcessingTimeMaximizationProblem
    {
        public:

        void MMBPTM_02();
        void random(unsigned int problemSize);
        bool choose();
    };

    // class for solving a max multiproduct batch time problem

    class solution
    {
        protected:

        problem _problem; // MMPBPTM problem linked to the solution
        mbptm::problem _mbptmp; // MBPTM problem linked to the solution
        mbptm::solution _mbptms; // MBPTM solution linked to the solution
        vector<vector<unsigned int>> _freeInventory; // free inventory per product per day (g)
        vector<unsigned int> _totalFreeInventory; // total free inventory per day (g)
        vector<unsigned int> _freeOutletInventory; // free outlet inventory per product (g)
        unsigned int _totalFreeOutletInventory; // total free outlets inventory (g)
        vector<vector<unsigned int>> _unmetDemand; // unmet demand per product per day (g)

        vector<vector<unsigned int>> _solution;

        unsigned int _batchProcessingTime = 0; // batch processing time (min)

        public:

        void start(problem _problem); // this function initializes solution variables
        vector<vector<unsigned int>> analyticalMethod(); // this function solves the reported problem through the analytical method proposed by T. B. Fraga (2023)
        void clear();
    };
}

#endif // MULTIPERIOD_MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED

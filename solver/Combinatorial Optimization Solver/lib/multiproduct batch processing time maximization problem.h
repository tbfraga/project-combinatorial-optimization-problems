/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/project-combinatorial-optimization-problems/tree/main/solver/Combinatorial%20Optimization%20Solver.
******************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// Multiproduct Batch Processing Time Maximization Problem Library
// developed by Tatiana Balbi Fraga
// start date: 2023/06/16
// last modification: 2023/06/17

#ifndef MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED
#define MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED

#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

#include<math.h>

namespace mpbptmp
{
    class multiproductBatchProcessingTimeMaximizationProblem
    {
        friend class solution;

        protected:

        unsigned int _NProducts = 0; // number of products
        vector<float> _productionRate = {0}; // product weight ratio (g/m^2)

        vector<unsigned int> _demand = {0}; // demand per product (g)

        vector<unsigned int> _maximumInventory = {0}; // maximum inventory at factory per product (g)
        unsigned int _totalMaximumInventory = 0; // total maximum inventory at factory (g)

        vector<unsigned int> _maximumOutletInventory = {0}; // maximum outlet inventory per product (g)
        unsigned int _totalMaximumOutletInventory = 0; // total maximum outlet inventory (g)

        unsigned int _maxBatchProcessingTime = 0; // maximum batch processing time (min)

        unsigned int _batchProcessingTime = 0; // batch processing time (min)

        public:

        void clear();
        void print();

        void set(unsigned int NProducts, vector<float> productionRate, vector<unsigned int> demand, vector<unsigned int> maximumInventory, unsigned int totalMaximumInventory,
                 vector<unsigned int> maximumOutletInventory, unsigned int totalMaximumOutletInventory, unsigned int maxBatchProcessingTime);
    };

    // class for creating instances of max multiproduct batch time problem

    class MPBPTMP: public multiproductBatchProcessingTimeMaximizationProblem
    {
        public:

        void MPBPTMP001();
        void MPBPTMP002();
        void MPBPTMP003();
        void randomMPBPTMP(unsigned int problemSize);
    };

    // class for solving a max multiproduct batch time problem

    class solution
    {
        protected:

        MPBPTMP _problem; // MMBTP linked to the solution

        public:

        void start(MPBPTMP mmbtp_problem); // this function initializes solution variables
        unsigned int analyticalMethod(); // this function solves the reported problem through the analytical method proposed by T. B. Fraga (2023)
    };
}

#endif // MULTIPRODUCT_BATCH_PROCESSING_TIME_MAXIMIZATION_PROBLEM_H_INCLUDED

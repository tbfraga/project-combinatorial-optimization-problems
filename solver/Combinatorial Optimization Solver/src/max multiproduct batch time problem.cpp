/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/project-combinatorial-optimization-problems/tree/main/solver/Combinatorial%20Optimization%20Solver.
******************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// Max Multiproduct Batch Time Problem Library
// developed by Tatiana Balbi Fraga
// start date: 2023/06/16
// last modification: 2023/06/16

#include "../lib/max multiproduct batch time problem.h"

namespace mmbtp
{
    void maxMultiproductBatchTimeProblem::clear()
    {
        _productionRate.clear();
        _demand.clear();
        _maximumInventory.clear();
        _maximumOutletInventory.clear();
    };

    void maxMultiproductBatchTimeProblem::print()
    {
         cout << endl << "products: " << _NProducts << endl;

         cout << endl << "production rate:";

         for(unsigned int p=0; p<_productionRate.size(); p++)
         {
            cout << endl << _productionRate[p];
         }
         cout << endl;

         cout << endl << "demand:";

         for(unsigned int p=0; p<_demand.size(); p++)
         {
            cout << endl << _demand[p];
         }
         cout << endl;

         cout << endl << "fatctory maximum inventory:";

         for(unsigned int p=0; p<_maximumInventory.size(); p++)
         {
            cout << endl << _maximumInventory[p];
         }
         cout << endl;

         cout << endl << "total fatctory maximum inventory: " << _totalMaximumInventory << endl;

         cout << endl << "outlets maximum inventory:";

         for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
         {
            cout << endl << _maximumOutletInventory[p];
         }
         cout << endl;

         cout << endl << "total outlets maximum inventory: " << _totalMaximumOutletInventory << endl;

    };

    void MMBTP::MMBTP001()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
        clear();

        _NProducts = 2;
        _productionRate = {60,40};
        _demand = {1000,500};
        _maximumInventory = {3000,2000};
        _totalMaximumInventory = 3000;
        _maximumOutletInventory = {600,600};
        _totalMaximumOutletInventory = 1000;
    };

    void solution::analyticalMethod()
    {
        unsigned int aux, sum, T1, T2;

        T1 = floor(_problem._demand[0]/_problem._productionRate[0]);

        for(unsigned int p=1; p<_problem._NProducts; p++)
        {
            aux = floor(_problem._demand[p]/_problem._productionRate[p]);

            if(aux < T1) T1 = aux;
        }

        vector<unsigned int> S;
        S.resize(_problem._NProducts,0);

        for(unsigned int p=1; p<_problem._NProducts; p++)
        {
            S[p] = _problem._demand[p] - T1*_problem._productionRate[p];
        }

        T2 = floor((_problem._maximumInventory[0] + _problem._maximumOutletInventory[0] + S[0])/_problem._productionRate[0]);

        for(unsigned int p=1; p<_problem._NProducts; p++)
        {
            aux = floor((_problem._maximumInventory[p] + _problem._maximumOutletInventory[p] + S[p])/_problem._productionRate[p]);

            if(aux < T2) T2 = aux;
        }

        aux = 0;
        sum = 0;

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
            aux += S[p];
            sum += _problem._productionRate[p];
        }

        aux += _problem._totalMaximumInventory + _problem._totalMaximumOutletInventory;

        aux = floor(aux/sum);

        if(aux < T2) T2 = aux;

        _problem._batchProcessingTime = T1 + T2;

        cout << endl << "T': " << T1 << "\t T'': " << T2 << "\t batch processing time: " << _problem._batchProcessingTime << endl;

        S.clear();
    };

    void solution::start(MMBTP mmbtp_problem)
    {
        //clear();

        _problem.clear();
        _problem = mmbtp_problem; // linking solution to the problem

    };
}

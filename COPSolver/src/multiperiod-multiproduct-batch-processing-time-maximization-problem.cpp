/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

Obs: You can alter this file only for personal purpose. You cannot distribute altered version.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/COPSolver.
******************************************************************************************************************************************************************************/

// COPSolver (Combinatorial Optimization Problems Solver)
// version: V02_2023_08_04
// developed by Tatiana Balbi Fraga
// start date: 2023/07/31
// last modification: 2023/08/04

#include "../lib/multiperiod-multiproduct-batch-processing-time-maximization-problem.h"

namespace mmbptmp
{
    void multiperiodMultiproductBatchProcessingTimeMaximizationProblem::clear()
    {
        _productionRate.clear();

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            _demand[p].clear();
        }
        _demand.clear();

        _maximumInventory.clear();

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            _maximumOutletInventory[p].clear();
        }
        _maximumOutletInventory.clear();

        _totalMaximumOutletInventory.clear();
    };

    bool multiperiodMultiproductBatchProcessingTimeMaximizationProblem::print()
    {
        cout << endl << "head: printing problem..." << endl;

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/Documents/COPSolver/problem.txt";

        ofstream file;

        file.open(site);

        file << "Multi-period and multi-product batch processing time maximization problem " << endl;

        file << endl << "products: " << _NProducts << endl;

        file << endl << "production rate:" << endl << endl;

        for(unsigned int p=0; p<_productionRate.size(); p++)
        {
            file << setw(3) << _productionRate[p];
            if(p<_productionRate.size()-1) file << "\t ";
        }
        file << endl;

        file << endl << "maximum factory inventory:" << endl << endl;

        for(unsigned int p=0; p<_maximumInventory.size(); p++)
        {
            file << setw(3) << _maximumInventory[p];
            if(p<_maximumInventory.size()-1) file << "\t ";
        }
        file << endl;

        file << endl << "total maximum factory inventory: " << _totalMaximumInventory << endl;

        file << endl << "days: " << _NDays << endl;

        file << endl << "demand:" << endl;

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            file << "\n";
            for(unsigned int d=0; d<_demand[p].size(); d++)
            {
                file << setw(4) <<  _demand[p][d];
                if(d<_demand[p].size()-1) file << "\t ";
            }
        }

        file << endl << endl << "outlets: " << _NOutlets << endl;

        file << endl << "maximum outlets inventory" << endl;

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            file << "\n";
            for(unsigned int o=0; o<_maximumOutletInventory[p].size(); o++)
            {
                file << setw(4) <<  _maximumOutletInventory[p][o];
                if(o<_maximumOutletInventory[p].size()-1) file << "\t ";
            }
        }

        file << endl << endl << "total maximum outlets inventory:" << endl << endl;

        for(unsigned int o=0; o<_totalMaximumOutletInventory.size(); o++)
        {
            file << setw(3) << _totalMaximumOutletInventory[o];
            if(o<_totalMaximumOutletInventory.size()-1) file << "\t ";
        }

        file << endl << endl << "maximum batch processing time: " << _maxBatchProcessingTime << endl;

        cout << endl << "info: problem is available on file " << site << endl;

        file.close();

        return 0;
    };

    bool multiperiodMultiproductBatchProcessingTimeMaximizationProblem::generateLingoData()
    {/*
        cout << endl << "head: generating LINGO data..." << endl;
        ofstream file;

        file.open("Documents/COPSolver/LINGOSolver/MPBPTMP/data.ldt");

        file << "! products;" << endl << endl;

        for(unsigned int p=0; p<_productionRate.size(); p++)
        {
            file << "P" << p+1;
            if((p+1) == _productionRate.size())
            {
                file << " ~" << endl;
            } else if((p+1) >= 20 && (p+1)%20 == 0)
            {
                file << endl;
            }else
            {
                file << " ";
            }
        }

        file << endl << "! production rate;" << endl << endl;

        for(unsigned int p=0; p<_productionRate.size(); p++)
        {
            file << _productionRate[p];
            if((p+1) == _productionRate.size())
            {
                file << " ~" << endl;
            } else if((p+1) >= 20 && (p+1)%20 == 0)
            {
                file << endl;
            } else
            {
                file << " ";
            }
        }

        file << endl << "! demand;" << endl << endl;

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            file << _demand[p];
            if((p+1) == _demand.size())
            {
                file << " ~" << endl;
            } else if((p+1) >= 20 && (p+1)%20 == 0)
            {
                file << endl;
            } else
            {
                file << " ";
            }
        }

        file << endl << "! total outlets free inventory;" << endl << endl;

        file << _totalMaximumOutletInventory << " ~" << endl;

        file << endl << "! outlets free inventory;" << endl << endl;

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            file << _maximumOutletInventory[p];
            if((p+1) == _maximumOutletInventory.size())
            {
                file << " ~" << endl;
            } else if((p+1) >= 20 && (p+1)%20 == 0)
            {
                file << endl;
            }else
            {
                file << " ";
            }
        }

        file << endl << "! total factory free inventory;" << endl << endl;

        file << _totalMaximumInventory << " ~" << endl;

        file << endl << "! factory free inventory;" << endl << endl;

        for(unsigned int p=0; p<_maximumInventory.size(); p++)
        {
            file << _maximumInventory[p];
            if((p+1) == _maximumInventory.size())
            {
                file << " ~" << endl;
            } else if((p+1) >= 20 && (p+1)%20 == 0)
            {
                file << endl;
            }else
            {
                file << " ";
            }
        }

        file << endl << "! processing time limite;" << endl << endl;

        file << _maxBatchProcessingTime << " ~";

        cout << endl << "info: data.ldt (input for LINGO application) is available on Documents/COPSolver/LINGOSolver/MPBPTMP/data.ldt" << endl;

        file.close();*/
    };

    bool multiperiodMultiproductBatchProcessingTimeMaximizationProblem::get()
    {
        clear();

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/COPSolver/data.txt";

        cout << endl << "Data file dir: " << site << endl;

        fstream file;

        file.open(site);

        file >> _NProducts;

        _productionRate.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _productionRate[p];
        }

        _maximumInventory.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _maximumInventory[p];
        }

        file >> _totalMaximumInventory;

        file >> _NDays;

        _demand.resize(_NProducts);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            _demand[p].resize(_NDays,0);

            for(unsigned int d=0; d<_NDays; d++)
            {
                file >> _demand[p][d];
            }
        }

        file >> _NOutlets;

        _maximumOutletInventory.resize(_NProducts);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            _maximumOutletInventory[p].resize(_NOutlets,0);

            for(unsigned int o=0; o<_NOutlets; o++)
            {
                file >> _maximumOutletInventory[p][o];
            }
        }

        _totalMaximumOutletInventory.resize(_NOutlets,0);

        for(unsigned int o=0; o<_NOutlets; o++)
        {
            file >> _totalMaximumOutletInventory[o];
        }

        file >> _maxBatchProcessingTime;

        file.close();

        return 0;
    };

    bool multiperiodMultiproductBatchProcessingTimeMaximizationProblem::choose()
    {
        return 0;
    };

    void multiperiodMultiproductBatchProcessingTimeMaximizationProblem::set(unsigned int NProducts, vector<float> productionRate, vector<unsigned int> demand, vector<unsigned int> maximumInventory,
                                                                 unsigned int totalMaximumInventory, vector<unsigned int> maximumOutletInventory, unsigned int totalMaximumOutletInventory,
                                                                 unsigned int maxBatchProcessingTime)
    {/*
        clear();

        _NProducts = NProducts;
        _productionRate = productionRate;
        _demand = demand;
        _maximumInventory = maximumInventory;
        _totalMaximumInventory = totalMaximumInventory;
        _maximumOutletInventory = maximumOutletInventory;
        _totalMaximumOutletInventory = totalMaximumOutletInventory;
        _maxBatchProcessingTime = maxBatchProcessingTime;*/
    };

    /*void MPBPTMP::MPBPTMP001()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
         /*clear();

        _NProducts = 2;
        _productionRate = {60,40};
        _demand = {1000,500};
        _maximumOutletInventory = {600,600};
        _totalMaximumOutletInventory = 1000;
        _maximumInventory = {3000,2000};
        _totalMaximumInventory = 3000;
        _maxBatchProcessingTime = 100;
    };

    void MPBPTMP::MPBPTMP002()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
         /*clear();

        _NProducts = 3;
        _productionRate = {60,40,50};
        _demand = {1000,500,800};
         _maximumOutletInventory = {600,600,600};
        _totalMaximumOutletInventory = 1500;
        _maximumInventory = {3000,2000,1000};
        _totalMaximumInventory = 3500;
        _maxBatchProcessingTime = 100;
    };

    void MPBPTMP::MPBPTMP003()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
        /*clear();

        _NProducts = 10;
        _productionRate = {60,40,50,40,30,50,60,10,20,40};
        _demand = {1000,500,800,500,400,500,2000,300,500,1000};
         _maximumOutletInventory = {600,600,600,1500,300,200,500,800,0,200};
        _totalMaximumOutletInventory = 3000;
        _maximumInventory = {3000,2000,1000,800,3000,1000,400,300,200,0};
        _totalMaximumInventory = 5000;
        _maxBatchProcessingTime = 100;
    };*/

    void problem::random(unsigned int problemSize)
    {/*
        clear();

        _NProducts = problemSize;

        _productionRate.resize(_NProducts,0);
        _demand.resize(_NProducts,0);
        _maximumInventory.resize(_NProducts,0);
        _maximumOutletInventory.resize(_NProducts,0);

        unsigned int seed1 = rand()%3000 + 500;
        unsigned int seed2 = rand()%5000 + 1000;

        _totalMaximumOutletInventory = (_NProducts/2)*seed1;
        _totalMaximumInventory = (_NProducts/2)*seed2;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            _productionRate[p] = rand()%30 + 10;
            _demand[p] = rand()%3000 + 800;
            _maximumOutletInventory[p] = rand()%(seed1-500) + 500;
            _maximumInventory[p] = rand()%(seed2 - 1000) + 1000;
        }

        _maxBatchProcessingTime = 100;*/
    };

    vector<vector<unsigned int>> solution::analyticalMethod(unsigned int T1)
    {
        mbptmp::problem _mbptmp;
        mbptmp::solution _mbptms;

        vector<unsigned int> demand = {};
        vector<unsigned int> maximumInventory = {};
        unsigned int totalMaximumInventory = 0;
        vector<unsigned int> maximumOutletInventory = {};
        unsigned int totalMaximumOutletInventory = 0;
        unsigned int maxBatchProcessingTime = 0;

        // calculate _mbptmp problem

        _mbptmp.set(_problem._NProducts, _problem._productionRate, demand, maximumInventory, totalMaximumInventory, maximumOutletInventory, totalMaximumOutletInventory, maxBatchProcessingTime);

        _mbptms.start(_mbptmp);
        _solution = _mbptms.analyticalMethod(0);
        return _solution;
    };

    void solution::start(problem _mmbptmp)
    {
        _problem.clear();
        _problem = _mmbptmp; // linking solution to the problem
    };

    void solution::clear()
    {
        _problem.clear();

        for(unsigned int p=0; p<_freeInventory.size(); p++)
        {
            _freeInventory[p].clear();
        }
         _freeInventory.clear();

        _totalFreeInventory.clear();
        _freeOutletInventory.clear();

        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].clear();
        }
        _unmetDemand.clear();
    };
}

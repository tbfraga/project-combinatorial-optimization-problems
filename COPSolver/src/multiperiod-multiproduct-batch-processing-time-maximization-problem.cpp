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

namespace mmbptm
{
    void multiperiodMultiproductBatchProcessingTimeMaximizationProblem::clear()
    {
        _productionRate.clear();

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            _demand[p].clear();
        }
        _demand.clear();

        for(unsigned int p=0; p<_planned.size(); p++)
        {
            _planned[p].clear();
        }
        _planned.clear();

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            _maximumOutletInventory[p].clear();
        }
        _maximumOutletInventory.clear();

        _totalMaximumOutletInventory.clear();

        _maximumInventory.clear();
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

        return 0;
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

    void problem::MMBPTM_02()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
         clear();

        _NProducts = 2;
        _NDays = 2;
        _NOutlets = 1;
        _productionRate = {60,40};
        _demand = {{1000,500},{500,300}};
        _planned = {{1000,0},{0,1500}};
        _maximumOutletInventory = {{600,600}};
        _totalMaximumOutletInventory = {1000};
        _maximumInventory = {3000,2000};
        _totalMaximumInventory = 3000;
        _maxBatchProcessingTime = 100;
    };

    bool problem::choose()
    {
        unsigned int preDefProblem;

        do
        {
            cout << endl << "Please select the predefined problem." << endl;
            cout << endl << "choose:" << endl << endl;
            cout << "1 for taking the MMBPTM_02;" << endl;
            cout << "0 if you want to stop the solver." << endl;

            cout << endl << "digite option and then tecle enter: ";
            cin >> preDefProblem;

            if(preDefProblem > 1)
            {
                cout << endl << endl << "atention: please digite 0 or 1 !!!" << endl;
            }

        }while(preDefProblem > 1);

        if(preDefProblem == 1)
        {
            MMBPTM_02();
        } else if(preDefProblem == 0)
        {
            cout << endl << "Thanks for using COPSolver !!!";
            cout << endl << "See you..." << endl;

            cout << endl << "Press enter for closing this window." << endl;
            getchar();
            return 1;
        }
        return 0;
    };


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
        mbptm::problem mbptmp;
        mbptm::solution mbptms;

        unsigned int totalMaximumOutletInventory;
        vector<int> totalMaximumInventory = {};

        vector<unsigned int> demand = {};
        vector<vector<unsigned int>> delivered = {{}};
        vector<vector<unsigned int>> maximumInventory = {{}};
        vector<vector<unsigned int>> deliverToOutlet = {{}};

        vector<unsigned int> maximumOutletInventory = {};

        unsigned int maxBatchProcessingTime = 0;

        // algorithm 1 - distributing planned production

        totalMaximumInventory.resize(_problem._NDays,0);
        totalMaximumInventory[0] = _problem._totalMaximumInventory;

        totalMaximumOutletInventory = 0;

        for(unsigned int o=0; o<_problem._NOutlets; o++)
        {
            totalMaximumOutletInventory += _problem._totalMaximumOutletInventory[o];
        }

        demand.resize(_problem._NProducts, 0);
        delivered.resize(_problem._NProducts);
        maximumInventory.resize(_problem._NProducts);
        deliverToOutlet.resize(_problem._NProducts);

        maximumOutletInventory.resize(_problem._NProducts,0);

        unsigned int available, unmet, aux;

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(d==0)
            {
                totalMaximumInventory[d] = _problem._totalMaximumInventory;
            } else
            {
                totalMaximumInventory[d] = totalMaximumInventory[d-1];
            }

            for(unsigned int p=0; p<_problem._NProducts; p++)
            {
                available =  _problem._planned[p][d];

                for(unsigned int k=0; k<d; k++)
                {
                    available += _problem._planned[p][k] - delivered[p][k] - deliverToOutlet[p][k];
                }

                unmet = _problem._demand[p][d];

                for(unsigned int k=1; k<d; k++)
                {
                    unmet += _problem._demand[p][d] - delivered[p][k];
                }

                if(d==0)
                {
                    delivered[p].resize(_problem._NDays);
                    maximumInventory[p].resize(_problem._NDays);
                    deliverToOutlet[p].resize(_problem._NDays,0);

                    maximumOutletInventory[p] = 0;
                    for(unsigned int o=0; o<_problem._NOutlets; o++)
                    {
                        maximumOutletInventory[p] += _problem._maximumOutletInventory[p][o];
                    }
                }

                delivered[p][d] = min(available,unmet);

                if(d==0)
                {
                    maximumInventory[p][d] = _problem._maximumInventory[p];
                } else
                {
                    maximumInventory[p][d] = maximumInventory[p][d-1];
                }

                maximumInventory[p][d] += delivered[p][d] - _problem._planned[p][d];
                totalMaximumInventory[d] += delivered[p][d] - _problem._planned[p][d];

                if(maximumInventory[p][d] < 0)
                {
                    aux = - maximumInventory[p][d];
                    deliverToOutlet[p][d] = min(min(aux, maximumOutletInventory[p]), totalMaximumOutletInventory);
                    maximumOutletInventory[p] -= deliverToOutlet[p][d];
                    totalMaximumOutletInventory -= deliverToOutlet[p][d];
                    totalMaximumInventory[d] += deliverToOutlet[p][d];
                    maximumInventory[p][d] = 0;
                }

                if(d == 0)
                {
                    demand[p] = _problem._demand[p][d] - delivered[p][d];
                }

                if(maximumInventory[p][d] < 0)
                {
                    available -= delivered[p][d];
                    unmet -= delivered[p][d] + demand[p];

                    aux = min(available, unmet);

                    delivered[p][d] += aux;
                    totalMaximumInventory[d] += aux;
                    maximumInventory[p][d] += aux;

                    demand[p] -= aux;
                }

                if(maximumInventory[p][d] < 0)
                {
                    cout << endl << "error: planned production is not feasible !!!" << endl;
                    getchar();
                    return {{}};
                }
            }
        }

        // algorithm 2 - adjusting planned production distribution for atteining feasiability

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(totalMaximumInventory[d] < 0)
            {
                for(unsigned int p=0; p<_problem._NProducts; p++)
                {
                    unmet = abs(totalMaximumInventory[d]);
                    deliverToOutlet[p][d] += min(maximumOutletInventory[p], unmet);
                    maximumOutletInventory[p] -= min(maximumOutletInventory[p], unmet);
                    totalMaximumOutletInventory -= min(maximumOutletInventory[p], unmet);

                    for(unsigned int k=d; k<_problem._NDays; k++)
                    {
                        maximumInventory[p][d] += min(maximumOutletInventory[p], unmet);
                        totalMaximumInventory[d] += min(maximumOutletInventory[p], unmet);
                    }

                    if(totalMaximumInventory[d] == 0) break;
                }
            }
        }

        // algorithm 3 - creating a MBPTM problem

        _mbptmp.NProducts(_problem._NProducts);
        _mbptmp.productionRate(_problem._productionRate);
        _mbptmp.demand(demand);

        _mbptmp.maximumInventory_resize(_problem._NProducts);

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
           // _mbptmp.maximumInventory();
        }

        // solve mbptm problem

        mbptms.start(mbptmp);
        _solution = mbptms.analyticalMethod(0);

        totalMaximumInventory.clear();

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
            delivered[p].clear();
            maximumInventory[p].clear();
        }
        delivered.clear();
        maximumInventory.clear();

        maximumOutletInventory.clear();

        return _solution;
    };

    void solution::start(problem mmbptmp)
    {
        _problem.clear();
        _problem = mmbptmp; // linking solution to the problem
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

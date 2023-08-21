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
// last modification: 2023/08/21

#include "../lib/multiperiod-multiproduct-batch-processing-time-maximization-problem.h"

namespace mmbptm
{
    void problem::clear()
    {
        input.productionRate.clear();

        for(unsigned int p=0; p<input.demand.size(); p++)
        {
            input.demand[p].clear();
        }
        input.demand.clear();

        for(unsigned int p=0; p<input.planned.size(); p++)
        {
            input.planned[p].clear();
        }
        input.planned.clear();

        for(unsigned int p=0; p<input.maximumOutletInventory.size(); p++)
        {
            input.maximumOutletInventory[p].clear();
        }
        input.maximumOutletInventory.clear();

        input.totalMaximumOutletInventory.clear();

        input.maximumInventory.clear();

        for(unsigned int p=0; p<output.deliver.size(); p++)
        {
            output.deliver[p].clear();
        }
        output.deliver.clear();

        for(unsigned int p=0; p<output.deliverToOutlets.size(); p++)
        {
            output.deliverToOutlets[p].clear();
        }
        output.deliverToOutlets.clear();

        for(unsigned int p=0; p<output.stock.size(); p++)
        {
            output.stock[p].clear();
        }
        output.stock.clear();
    };

    bool problem::print()
    {
        cout << endl << "head: printing problem..." << endl;

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/COPSolver/problem.txt";

        ofstream file;

        file.open(site);

        file << "Multi-period and multi-product batch processing time maximization problem " << endl;

        file << endl << "products: " << input.NProducts << endl;

        file << endl << "production rate:" << endl << endl;

        for(unsigned int p=0; p<input.productionRate.size(); p++)
        {
            file << setw(3) << input.productionRate[p];
            if(p<input.productionRate.size()-1) file << "\t ";
        }
        file << endl;

        file << endl << "maximum factory inventory:" << endl << endl;

        for(unsigned int p=0; p<input.maximumInventory.size(); p++)
        {
            file << setw(3) << input.maximumInventory[p];
            if(p<input.maximumInventory.size()-1) file << "\t ";
        }
        file << endl;

        file << endl << "total maximum factory inventory: " << input.totalMaximumInventory << endl;

        file << endl << "days: " << input.NDays << endl;

        file << endl << "demand:" << endl;

        for(unsigned int p=0; p<input.demand.size(); p++)
        {
            file << "\n";
            for(unsigned int d=0; d<input.demand[p].size(); d++)
            {
                file << setw(4) <<  input.demand[p][d];
                if(d<input.demand[p].size()-1) file << "\t ";
            }
        }

        file << endl << endl << "outlets: " << input.NOutlets << endl;

        file << endl << "maximum outlets inventory" << endl;

        for(unsigned int p=0; p<input.maximumOutletInventory.size(); p++)
        {
            file << "\n";
            for(unsigned int o=0; o<input.maximumOutletInventory[p].size(); o++)
            {
                file << setw(4) <<  input.maximumOutletInventory[p][o];
                if(o<input.maximumOutletInventory[p].size()-1) file << "\t ";
            }
        }

        file << endl << endl << "total maximum outlets inventory:" << endl << endl;

        for(unsigned int o=0; o<input.totalMaximumOutletInventory.size(); o++)
        {
            file << setw(3) << input.totalMaximumOutletInventory[o];
            if(o<input.totalMaximumOutletInventory.size()-1) file << "\t ";
        }

        file << endl << endl << "maximum batch processing time: " << input.maxBatchProcessingTime << endl;

        cout << endl << "info: problem is available on file " << site << endl;

        file.close();

        return 0;
    };

    bool problem::generateLingoData()
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

    bool problem::get()
    {
        /*clear();

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/COPSolver/problem.txt";

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

        file.close();*/

        return 0;
    };

    void problem::set(unsigned int NProducts, vector<float> productionRate, vector<unsigned int> demand, vector<unsigned int> maximumInventory,
                      unsigned int totalMaximumInventory, vector<unsigned int> maximumOutletInventory, unsigned int totalMaximumOutletInventory, unsigned int maxBatchProcessingTime)
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

        cout << endl << "creating problem... " << endl;

        input.NProducts = 2;
        input.NDays = 2;
        input.NOutlets = 1;
        input.productionRate = {60,40};
        input.demand = {{1000,500},{500,300}};
        input.planned = {{1000,0},{0,1500}};
        input.maximumOutletInventory = {{600},{600}};
        input.totalMaximumOutletInventory = {1000};
        input.maximumInventory = {3000,2000};
        input.totalMaximumInventory = 3000;
        input.maxBatchProcessingTime = 100;
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

    void problem::start()
    {
        output.deliver.resize(input.NProducts);

        for(unsigned int p=0; p<input.NProducts; p++)
        {
            output.deliver[p].resize(input.NDays,0);
        }

        output.deliverToOutlets.resize(input.NProducts);

        for(unsigned int p=0; p<output.deliverToOutlets.size(); p++)
        {
            output.deliverToOutlets[p].resize(input.NDays,0);
        }

        output.stock.resize(input.NProducts);

        for(unsigned int p=0; p<output.stock.size(); p++)
        {
            output.stock[p].resize(input.NDays,0);
        }

    };

    solution problem::exactMethod()
    {
        unsigned int totalMaximumOutletInventory;
        vector<int> totalMaximumInventory = {};

        vector<unsigned int> demand = {};
        vector<vector<int>> maximumInventory = {{}};
        vector<vector<unsigned int>> deliverToOutlet = {{}};

        vector<unsigned int> maximumOutletInventory = {};

        start();

        // algorithm 1 - distributing planned production

        totalMaximumInventory.resize(input.NDays,0);
        totalMaximumInventory[0] = input.totalMaximumInventory;

        totalMaximumOutletInventory = 0;

        for(unsigned int o=0; o<input.NOutlets; o++)
        {
            totalMaximumOutletInventory += input.totalMaximumOutletInventory[o];
        }

        demand.resize(input.NProducts, 0);
        maximumInventory.resize(input.NProducts);

        maximumOutletInventory.resize(input.NProducts,0);

        unsigned int available, unmet;
        unsigned int aux, aux2;

        for(unsigned int d=0; d<input.NDays; d++)
        {
            if(d==0)
            {
                totalMaximumInventory[d] = input.totalMaximumInventory;
            } else
            {
                totalMaximumInventory[d] = totalMaximumInventory[d-1];
            }

            for(unsigned int p=0; p<input.NProducts; p++)
            {
                available =  input.planned[p][d];

                for(unsigned int k=0; k<d; k++)
                {
                    available += input.planned[p][k] - output.deliver[p][k] - output.deliverToOutlets[p][k];
                }

                unmet = input.demand[p][d];

                for(unsigned int k=1; k<d; k++)
                {
                    unmet += input.demand[p][d] - output.deliver[p][k];
                }

                if(d==0)
                {
                    maximumInventory[p].resize(input.NDays);

                    maximumOutletInventory[p] = 0;
                    for(unsigned int o=0; o<input.NOutlets; o++)
                    {
                        maximumOutletInventory[p] += input.maximumOutletInventory[p][o];
                    }
                }

                output.deliver[p][d] = min(available,unmet);

                if(d==0)
                {
                    maximumInventory[p][d] = input.maximumInventory[p];
                } else
                {
                    maximumInventory[p][d] = maximumInventory[p][d-1];
                }

                maximumInventory[p][d] += output.deliver[p][d] - input.planned[p][d];
                totalMaximumInventory[d] += output.deliver[p][d] - input.planned[p][d];

                if(maximumInventory[p][d] < 0)
                {
                    aux = - maximumInventory[p][d];
                    deliverToOutlet[p][d] = min(min(aux, maximumOutletInventory[p]), totalMaximumOutletInventory);
                    maximumOutletInventory[p] -= output.deliverToOutlets[p][d];
                    totalMaximumOutletInventory -= output.deliverToOutlets[p][d];
                    totalMaximumInventory[d] += output.deliverToOutlets[p][d];
                    maximumInventory[p][d] = 0;
                }

                if(d == 0)
                {
                    demand[p] = input.demand[p][d] - output.deliver[p][d];
                }

                if(maximumInventory[p][d] < 0)
                {
                    available -= output.deliver[p][d];
                    unmet -= output.deliver[p][d] + demand[p];

                    aux = min(available, unmet);

                    output.deliver[p][d] += aux;
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

        for(unsigned int d=0; d<input.NDays; d++)
        {
            if(totalMaximumInventory[d] < 0)
            {
                for(unsigned int p=0; p<input.NProducts; p++)
                {
                    unmet = abs(totalMaximumInventory[d]);
                    output.deliverToOutlets[p][d] += min(maximumOutletInventory[p], unmet);
                    maximumOutletInventory[p] -= min(maximumOutletInventory[p], unmet);
                    totalMaximumOutletInventory -= min(maximumOutletInventory[p], unmet);

                    for(unsigned int k=d; k<input.NDays; k++)
                    {
                        maximumInventory[p][d] += min(maximumOutletInventory[p], unmet);
                        totalMaximumInventory[d] += min(maximumOutletInventory[p], unmet);
                    }

                    if(totalMaximumInventory[d] == 0) break;
                }
            }
        }

        // algorithm 3 - creating a MBPTM problem

        _mbptmp.NProducts(input.NProducts);
        _mbptmp.productionRate(input.productionRate);
        _mbptmp.demand(demand);

        _mbptmp.maximumInventory_resize(input.NProducts);

        for(unsigned int p=0; p<input.NProducts; p++)
        {
           aux = maximumInventory[p][0];
           for(unsigned int d=1; d<input.NDays; d++)
           {
                aux2 = maximumInventory[p][d];
                aux = min(aux, aux2);
           }

           _mbptmp.maximumInventory(aux,p);
        }

        aux = totalMaximumInventory[0];
        for(unsigned int d=1; d<input.NDays; d++)
        {
            aux2 = totalMaximumInventory[d];
            aux = min(aux, aux2);
        }

        _mbptmp.totalMaximumInventory(aux);

        _mbptmp.maximumOutletInventory(maximumOutletInventory);
        _mbptmp.totalMaximumOutletInventory(totalMaximumOutletInventory);
        _mbptmp.maxBatchProcessingTime(input.maxBatchProcessingTime);

        // solving mbptm problem

        _mbptms.start(_mbptmp);
        _mbptms.analyticalMethod(0);

        // calculating final distribution

        for(unsigned int p=0; p<input.NProducts; p++)
        {
            output.deliver[p][0] += _mbptms.delivered(p);
            output.deliverToOutlets[p][0] += _mbptms.deliveredToOutlets(p);
        }

        // clearing vectors

        for(unsigned int p=0; p<input.NProducts; p++)
        {
            maximumInventory[p].clear();
        }
        demand.clear();
        maximumOutletInventory.clear();
        maximumInventory.clear();
        totalMaximumInventory.clear();

        solution out;

        return out;
    };
}

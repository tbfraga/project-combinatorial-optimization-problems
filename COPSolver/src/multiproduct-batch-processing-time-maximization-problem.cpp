/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

Obs: You can alter this file only for personal purpose. You cannot distribute altered version.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/COPSolver.
******************************************************************************************************************************************************************************/

// COPSolver (Combinatorial Optimization Problems Solver)
// version: V01_20230731
// developed by Tatiana Balbi Fraga
// start date: 2023/04/26
// last modification: 2023/08/04

#include "../lib/multiproduct-batch-processing-time-maximization-problem.h"

namespace mbptmp
{
    void multiproductBatchProcessingTimeMaximizationProblem::clear()
    {
        _productionRate.clear();
        _demand.clear();
        _maximumInventory.clear();
        _maximumOutletInventory.clear();
    };

    bool multiproductBatchProcessingTimeMaximizationProblem::print()
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
        site += "/Documents/COPSolver/problem.txt";

        ofstream file;

        file.open(site);

        file << "Multi-product batch processing time maximization problem " << endl;

        file << endl << "products: " << _NProducts << endl;

        file << endl << "production rate:" << endl << endl;

        for(unsigned int p=0; p<_productionRate.size(); p++)
        {
            file << setw(3) << _productionRate[p] << "\t ";
        }
        file << endl;

        file << endl << "demand:" << endl << endl;

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            file << setw(4) <<  _demand[p] << "\t ";
        }

        file << endl << endl << "total outlets maximum inventory: " << _totalMaximumOutletInventory << endl;

        file << endl << "outlets maximum inventory:" << endl << endl;

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            file << setw(4) << _maximumOutletInventory[p] << "\t ";
        }

        file << endl << endl << "total fatctory maximum inventory: " << _totalMaximumInventory << endl;

        file << endl << "fatctory maximum inventory:" << endl << endl;

        for(unsigned int p=0; p<_maximumInventory.size(); p++)
        {
            file << setw(4) << _maximumInventory[p] << "\t ";
        }

        file << endl << endl << "maximum batch processing time: " << _maxBatchProcessingTime << endl;

        cout << endl << "info: problem is available on file " << site << endl;

        file.close();

        return 0;
    };

    bool multiproductBatchProcessingTimeMaximizationProblem::generateLingoData()
    {
        cout << endl << "head: generating LINGO data..." << endl;

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/Documents/COPSolver/LINGOSolver/MPBPTMP/data.ldt";

        ofstream file;

        file.open(site);

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

        cout << endl << "info: data.ldt (input for LINGO application) is available on " << site << endl;

        file.close();

        return 0;
    };

    bool multiproductBatchProcessingTimeMaximizationProblem::get()
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
        site += "/Documents/COPSolver/data.txt";

        cout << endl << "Data file dir: " << site << endl;

        fstream file;

        file.open(site);

        unsigned int type;

        file >> type;

        if(type != 1)
        {
            cout << endl << "file do not correspond to a multiproduct batch processing time maximization problem" << endl;
            return 1;
        }else
        {
            cout << endl << "*** multi-ṕroduct batch processing time maximization problem ***" << endl;
        }

        file >> _NProducts;

        _productionRate.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _productionRate[p];
        }

        _demand.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _demand[p];
        }

        file >> _totalMaximumOutletInventory;

        _maximumOutletInventory.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _maximumOutletInventory[p];
        }

        file >> _totalMaximumInventory;

        _maximumInventory.resize(_NProducts,0);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file >> _maximumInventory[p];
        }

        file >> _maxBatchProcessingTime;

        file.close();

        return 0;
    };

    void multiproductBatchProcessingTimeMaximizationProblem::set(unsigned int NProducts, vector<float> productionRate, vector<unsigned int> demand, vector<unsigned int> maximumInventory,
                                                                 unsigned int totalMaximumInventory, vector<unsigned int> maximumOutletInventory, unsigned int totalMaximumOutletInventory,
                                                                 unsigned int maxBatchProcessingTime)
    {
        clear();

        _NProducts = NProducts;
        _productionRate = productionRate;
        _demand = demand;
        _maximumInventory = maximumInventory;
        _totalMaximumInventory = totalMaximumInventory;
        _maximumOutletInventory = maximumOutletInventory;
        _totalMaximumOutletInventory = totalMaximumOutletInventory;
        _maxBatchProcessingTime = maxBatchProcessingTime;
    };

    void problem::MPBPTMP001()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
        clear();

        _NProducts = 2;
        _productionRate = {60,40};
        _demand = {1000,500};
        _maximumOutletInventory = {600,600};
        _totalMaximumOutletInventory = 1000;
        _maximumInventory = {3000,2000};
        _totalMaximumInventory = 3000;
        _maxBatchProcessingTime = 100;
    };

    void problem::MPBPTMP002()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
        clear();

        _NProducts = 3;
        _productionRate = {60,40,50};
        _demand = {1000,500,800};
         _maximumOutletInventory = {600,600,600};
        _totalMaximumOutletInventory = 1500;
        _maximumInventory = {3000,2000,1000};
        _totalMaximumInventory = 3500;
        _maxBatchProcessingTime = 100;
    };

    void problem::MPBPTMP003()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver.
        **************************************************************************************************************************/
        clear();

        _NProducts = 10;
        _productionRate = {60,40,50,40,30,50,60,10,20,40};
        _demand = {1000,500,800,500,400,500,2000,300,500,1000};
         _maximumOutletInventory = {600,600,600,1500,300,200,500,800,0,200};
        _totalMaximumOutletInventory = 3000;
        _maximumInventory = {3000,2000,1000,800,3000,1000,400,300,200,0};
        _totalMaximumInventory = 5000;
        _maxBatchProcessingTime = 100;
    };

    bool problem::choose()
    {
        unsigned int preDefProblem = 1;

        do
        {
            cout << endl << "Please select the predefined problem." << endl;
            cout << endl << "choose:" << endl << endl;
            cout << "1 for taking the MPBPTMP001;" << endl;
            cout << "2 for taking the MPBPTMP002;" << endl;
            cout << "3 for taking the MPBPTMP003; " << endl;
            cout << "0 if you want to stop the solver." << endl;

            cout << endl << "digite option and then tecle enter: ";
            cin >> preDefProblem;

            if(preDefProblem > 3)
            {
                cout << endl << endl << "atention: please digite 0, 1, 2 or 3 !!!" << endl;
            }

        }while(preDefProblem > 3);

        if(preDefProblem == 1)
        {
            MPBPTMP001();
        } else if(preDefProblem == 2)
        {
            MPBPTMP002();
        } else if(preDefProblem == 3)
        {
            MPBPTMP003();
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
    {
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

        _maxBatchProcessingTime = 100;
    };

    unsigned int solution::analyticalMethod()
    {
        cout << endl << "head: applying Fraga's exact method for solving MPBPTMP..." << endl;

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // printf("\nCurrent working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            return 1;
        }

        string site = cwd;
        site += "/Documents/COPSolver/output.txt";

        ofstream file;

        file.open(site);

        cout << endl << endl << "Analytical solution:" << endl;
        file << "Analytical solution:" << endl << endl;

        unsigned int aux, sum, T1, T2;

        T1 = floor(_problem._demand[0]/_problem._productionRate[0]);

        for(unsigned int p=1; p<_problem._NProducts; p++)
        {
            aux = floor(_problem._demand[p]/_problem._productionRate[p]);
            if(aux < T1) T1 = aux;
        }

        vector<unsigned int> S;
        S.resize(_problem._NProducts,0);

        for(unsigned int p=0; p<_problem._NProducts; p++)
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

        if(_problem._batchProcessingTime > _problem._maxBatchProcessingTime) _problem._batchProcessingTime = _problem._maxBatchProcessingTime;

        file << "T': " << T1 << "\t T'': " << T2 << "\t max batch processing time: " << _problem._maxBatchProcessingTime << endl;
        file << endl << "batch processing time: " << _problem._batchProcessingTime << endl;

        cout << endl << "T': " << T1 << "\t T'': " << T2 << "\t max batch processing time: " << _problem._maxBatchProcessingTime << endl;
        cout << endl << "batch processing time: " << _problem._batchProcessingTime << endl << endl;

        S.clear();
        file.close();

        cout << endl << "info: output of analytical method is available on file " << site << endl;

        return _problem._batchProcessingTime;
    };

    void solution::start(problem mpbptmp_problem)
    {
        //clear();

        _problem.clear();
        _problem = mpbptmp_problem; // linking solution to the problem

    };

    void solution::clear()
    {
        _problem.clear();
    };
}

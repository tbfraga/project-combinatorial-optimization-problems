/*********************************************************************** LICENSE **********************************************************************************************
Important: Copies and distributions of this solver must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

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

#include "lib/multiperiod-multiproduct-batch-processing-time-maximization-problem.h"

#include <unistd.h>
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

template<class P, class S>
bool proc(P problem, S solution);

int main()
{
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

    unsigned int problemType = 1;

    file.open(site);
    file >> problemType;
    file.close();

    switch(problemType)
    {
        case 1:
        {
            mbptmp::problem problem;
            mbptmp::solution solution;
            proc(problem,solution);
        }
        break;
        case 2:
        {
            mmbptmp::problem problem;
            mmbptmp::solution solution;
            proc(problem,solution);
        }
        break;
        default:
            cout << endl;
    };
}

template<class P, class S>
bool proc(P problem, S solution)
{
    cout << "Thaks for using COPSolver :)))" << endl << endl;
    cout << "COPSolver was (and is being) developed by Fraga, T.B. with purpose of solving many differente combinatorial optimizations problems." << endl << endl;
    cout << "This first version, V01_20230804, only solves the Multi-product batch processing time maximization problem." << endl << endl;
    cout << "COPSolver is licenced by Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0)" << endl << endl;
    cout << "Under this licence you can:" << endl << endl;
    cout << "1) Free dowload and/or use this solver;" << endl;
    cout << "2) Share this solver (if don't modified anyway) only if you inform a link for the original repository and for the license;" << endl;
    cout << "3) Modify the solver for personal use, but not share modified version of solver." << endl << endl;
    cout << "You cannot use COPSolver or any modified version for comercial purpose." << endl;
    cout << "If you need or want to use COPSolver for any comercial purpose, please contact tatiana.balbi@ufpe.br." << endl << endl;
    cout << "If you use this solver for work or science, please don't forget to correctly cite it on presentations and the published material." << endl << endl;
    cout << "repository: github.com/tbfraga/COPSolver" << endl;

    cout << endl << "Please, resize the window (if needed) and press enter." << endl;
    getchar();

    cout << endl << "creating directories if needed..." << endl;

    // Creating a directory
    if (mkdir("Documents", 0777) == -1){}
    else
        cout << endl << "Documents directory created" << endl;

    if (mkdir("Documents/COPSolver", 0777) == -1){}
       // cerr << "Error :  " << strerror(errno) << endl;
    else
        cout << endl << "Documents/COPSolver directory created" << endl;

    if (mkdir("Documents/COPSolver/LINGOSolver", 0777) == -1){}
       // cerr << "Error :  " << strerror(errno) << endl;
    else
        cout << endl << "Documents/COPSolver/LINGOSolver directory created" << endl;

    if (mkdir("Documents/COPSolver/LINGOSolver/MPBPTMP", 0777) == -1){}
       // cerr << "Error :  " << strerror(errno) << endl;
    else
        cout << endl << "Documents/COPSolver/LINGOSolver/MPBPTMP directory created" << endl;

    unsigned int problemDefinitionMethod = 1;

    do
    {
        cout << endl << "Please select the problem definition method." << endl;
        cout << endl << "choose:" << endl << endl;
        cout << "1 for taking the problem from data.txt file;" << endl;
        cout << "2 for using a predefined problem;" << endl;
        cout << "3 for generating a random problem; " << endl;
        cout << "0 if you want to stop the solver." << endl;

        cout << endl << "digite option and then press enter: ";
        cin >> problemDefinitionMethod;

        if(problemDefinitionMethod > 3)
        {
            cout << endl << endl << "atention: please digite 0, 1, 2 or 3 !!!" << endl;
        }
    }while(problemDefinitionMethod > 3);

    if(problemDefinitionMethod == 0)
    {
        cout << endl << "Thanks for using COPSolver !!!";
        cout << endl << "See you..." << endl;

        cout << endl << "Press enter for closing this window." << endl;
        getchar();
        return 0;
    } else if(problemDefinitionMethod == 1)
    {
        problem.get();
    } else if(problemDefinitionMethod == 2)
    {
        if (problem.choose() == 1) return 1;
    } else if(problemDefinitionMethod == 3)
    {
        time_t source = 0;
        unsigned int NProducts = 10;

        cout << endl << "Please informe the source for random generation (interger value)." << endl;
        cout << endl << "digite option and then press enter: ";
        cin >> source;

        cout << endl << "Please informe number of products for random generation (interger value)." << endl;
        cout << endl << "digite option and then press enter: ";
        cin >> NProducts;

        srand((unsigned) source);
        problem.random(NProducts);
    }

    problem.print();

    problem.generateLingoData();

    solution.start(problem);
    solution.analyticalMethod();

    problem.clear();
    solution.clear();

    cout << endl << "Thanks for using COPSolver !!!";
    cout << endl << "See you..." << endl;

    cout << endl << "Press enter for closing this window." << endl << endl;

    return 0;
}

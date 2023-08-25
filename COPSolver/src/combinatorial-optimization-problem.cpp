/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

Obs: You can alter this file only for personal purpose. You cannot distribute altered version.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/COPSolver.
******************************************************************************************************************************************************************************/

// COPSolver (Combinatorial Optimization Problems Solver)
// version: V02_2023_08_16
// developed by Tatiana Balbi Fraga
// start date: 2023/08/16
// last modification: 2023/08/16

#include "../lib/combinatorial-optimization-problem.h"

namespace cop
{
    bool solver()
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
        cout << endl << "You can stop solver anytime pressing 0." << endl;
        getchar();

        unsigned int _problemDefinitionMethod;

        do{
            do
            {
                cout << endl << "Please select the problem definition method." << endl;
                cout << endl << "choose:" << endl << endl;
                cout << "1 for taking the problem from data.txt file;" << endl;
                cout << "2 for using a predefined problem;" << endl;
                cout << "3 for generating a random problem; " << endl;
                cout << "0 if you want to stop the solver." << endl;

                cout << endl << "digite option and then press enter: ";
                cin >> _problemDefinitionMethod;

                if(_problemDefinitionMethod > 3)
                {
                    cout << endl << endl << "atention: please digite 0, 1, 2 or 3 !!!" << endl;
                }
            }while(_problemDefinitionMethod > 3);

            unsigned int _problemType;

            if(_problemDefinitionMethod == 0)
            {
                cout << endl << "Thanks for using COPSolver !!!";
                cout << endl << "See you..." << endl;

                cout << endl << "Press enter for closing this window." << endl;
                getchar();
                return 0;
            } else if(_problemDefinitionMethod == 1)
            {
                char cwd[PATH_MAX];
                if (getcwd(cwd, sizeof(cwd)) != NULL)
                {
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
                file >> _problemType;
                file.close();
            } else if(_problemDefinitionMethod == 2 || _problemDefinitionMethod == 3)
            {
                do
                {
                    cout << endl << "Please select the problem type" << endl;
                    cout << endl << "choose:" << endl << endl;
                    cout << "1 for Multi-product batch processing time maximization;" << endl;
                    cout << "2 for Multi-period and multi-product batch processing time maximization;" << endl;
                    cout << "0 if you want to stop the solver." << endl;

                    cout << endl << "digite option and then press enter: ";
                    cin >> _problemType;

                    if(_problemType > 2)
                    {
                        cout << endl << endl << "atention: please digite 0, 1 or 2 !!!" << endl;
                    }
                }while(_problemType > 2);
            }

            switch(_problemType)
            {
                case 1:
                {
                    problem<mbptm::problem> _problem;
                    _problem.set_PDM(_problemDefinitionMethod);
                    _problem.get();
                    _problem.print();
                    _problem.generateLingoData();

                    solution<mbptm::problem, mbptm::solution> _solution;

                    _solution.start(_problem);
                    _solution.analyticalMethod();

                    _problem.clear();
                    _solution.clear();
                }
                break;
                case 2:
                {
                    problem<mmbptm::cop> _problem;
                    _problem.set_PDM(_problemDefinitionMethod);

                    _problem.get();
                    _problem.print();
                    _problem.generateLingoData();

                    _problem.start();
                    _problem.exactMethod();

                    _problem.clear();
                }
                break;
                default:
                    cout << endl;
                    return 1;
            };

        }while(_problemDefinitionMethod != 0);

        cout << endl << "Thanks for using COPSolver !!!";
        cout << endl << "See you..." << endl;

        cout << endl << "Press enter for closing this window." << endl << endl;

        return 0;
    }
}

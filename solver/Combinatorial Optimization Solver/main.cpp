/*********************************************************************** LICENSE **********************************************************************************************
Important: Copies and distributions of this solver must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/project-combinatorial-optimization-problems/tree/main/solver/Combinatorial%20Optimization%20Solver.
******************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// developed by Tatiana Balbi Fraga
// start date: 2023/04/26
// last modification: 2023/05/27

#include "lib/extruder planning problem.h"
using namespace epp;

int main()
{
    cout << "*** creating library extruder planning problem ****" << endl;
    cout << endl << "- creating a class for solving the problem and manipulating solution" << endl;
    cout << endl << "\t" << "-- defining solution primary and dependent variables" << endl;
    cout << endl << "\t" << "-- creating a function for clearing vector type variables" << endl;
    cout << endl << "\t" << "-- creating a function for printing solution parts" << endl;
    cout << endl << "\t" << "-- creating a function for printing solution" << endl;
    cout << endl << "\t" << "-- creating a function for printing solution parts on file" << endl;
    cout << endl << "\t" << "-- creating a function for printing solution on file" << endl;
    cout << endl << "\t" << "-- creating a function for inicializing solution variables" << endl;

    // continue - next time - stoping for today :)

    cout << endl << "\t" << "-- creating a fuction for generating some initial solution" << endl;

    ofstream file;

    EPP problem;

    problem.EPP001();
    problem.print();

    file.open("rst/EPP.txt");
    problem.print(file);
    file.close();
    getchar();

    solution epp_solution;
    epp_solution.print();

    epp_solution.restart(problem);

    file.open("rst/solution.txt");
    epp_solution.print(file);
    file.close();

    epp_solution.print();

    epp_solution.clear();
    problem.clear();

    return 0;
}

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
// last modification: 2023/05/26

#include "lib/extruder planning problem.h"
using namespace epp;

int main()
{
    cout << "*** creating library extruder planning problem ****" << endl;
    cout << endl << "- creating a class for the problem" << endl;
    cout << endl << "\t" << "-- defining the paramaters of the problem" << endl;
    cout << endl << "\t" << "-- creating a function for printing the EPP" << endl;
    cout << endl << "\t" << "-- creating a function for printing the EPP on file" << endl;
    cout << endl << "\t" << "-- search how to format output using cout -- later" << endl;
    cout << endl << "\t" << "-- in print function - verify dimensions of paramenters -- later" << endl;
    cout << endl << "\t" << "-- create a function for calculate value of dependent variables" << endl;
    cout << endl << "\t" << "-- creating a function for delete problem parameters and dependent variables of type vector" << endl;
    cout << endl << "- creating a class for problem instances" << endl;
    cout << endl << "\t" << "-- creating a function for creating a small and simple instance of the EPP (Extruder Planning Problem)" << endl;
    cout << endl << "to be continued ..." << endl;

    ofstream file;

    EPP problem;

    problem.EPP001();
    problem.print();

    file.open("rst/EPP.txt");
    problem.print(file);
    file.close();

    problem.clear();

    return 0;
}

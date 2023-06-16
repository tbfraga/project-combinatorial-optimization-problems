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
// last modification: 2023/05/31

#include "lib/max multiproduct batch time problem.h"

//#include "lib/extruder planning problem.h"
//using namespace epp;

int main()
{
    mmbtp::MMBTP mmbtp_problem;

    mmbtp_problem.MMBTP001();
    mmbtp_problem.print();

    mmbtp::solution mmbtp_solution;

    mmbtp_solution.start(mmbtp_problem);
    mmbtp_solution.analyticalMethod();

    mmbtp_problem.clear();

    /*cout << "*** creating library extruder planning problem ****" << endl;
    cout << endl << "to be continued - debugging..." << endl;

    ofstream file;

    EPP problem;

    problem.EPP001();
    problem.print();

    file.open("rst/EPP.txt");
    problem.print(file);
    file.close();
    getchar();

    file.open("rst/debug.txt");

    solution epp_solution;
    epp_solution.restart(problem);
    epp_solution.generate(file);

    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - generated" << endl;
    getchar();

    file.open("rst/solution.txt");
    epp_solution.print(file);
    file.close();

    epp_solution.verify();

    epp_solution.particleCollision(100, 100);

    epp_solution.print();
    cout << endl << "epp_solution - after particle collision" << endl;
    getchar();

    epp_solution.clear();
    problem.clear();*/

    return 0;
}

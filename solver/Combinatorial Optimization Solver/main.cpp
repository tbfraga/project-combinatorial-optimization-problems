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
// last modification: 2023/05/29

#include "lib/extruder planning problem.h"
using namespace epp;

int main()
{
    cout << "*** creating library extruder planning problem ****" << endl;
    cout << endl << "- creating a class for solving the problem and manipulating solution" << endl;
    cout << endl << "-- creating functions for applying Simulated Annealing for improve batches processing time" << endl;
    cout << endl << "--- creat a function for ramdomly chang a batch processing time" << endl;
    cout << endl << "--- creat a function for applying Simulated Annealing" << endl;

    cout << endl << "when production is reduced, free space in outlets, if exists, are not filled with other products in inventory " << endl;
    cout << endl << "need to improuve it" << endl;

    cout << endl << "working perfectly - next step: create a function for applying Particle Collision for improving solution" << endl;

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
    cout << endl << "epp_solution - just created" << endl;

    solution other_solution;

    epp_solution.restart(problem);

    epp_solution.print();
    cout << endl << "epp_solution - restarted" << endl;

    other_solution = epp_solution.copy();
    other_solution.print();
    cout << endl << "other_solution <-- epp_solution (=)" << endl;

    file.open("rst/debug.txt");
    epp_solution.generate(file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - generated" << endl;
    getchar();

    file.open("rst/solution.txt");
    epp_solution.print(file);
    file.close();

    other_solution.set(epp_solution);
    other_solution.print();
    cout << endl << "other_solution <-- epp_solution (set)" << endl;

    epp_solution.verify();

    file.open("rst/processingTime.txt");
    epp_solution.processingTime(0, 200, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - after reducing processing time" << endl;
    //getchar();

    file.open("rst/processingTime.txt");
    epp_solution.processingTime(0, 250, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - after increasing processing time" << endl;
    //getchar();

    file.open("rst/processingTime.txt", ios_base::app);
    epp_solution.processingTime(0, 450, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - after increasing processing time - unfeaseble" << endl;
    //getchar();

    file.open("rst/processingTime.txt", ios_base::app);
    epp_solution.processingTime(2, 150, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - after increasing processing time - unfeaseble" << endl;
    //getchar();

    file.open("rst/processingTime.txt", ios_base::app);
    epp_solution.processingTime(1, 300, file);
    epp_solution.processingTime(2, 40, file);
    epp_solution.processingTime(3, 40, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - before Simulated Annealing" << endl;
    getchar();

    file.open("rst/simulatedAnnealing.txt");
    epp_solution.simultedAnnealing(100, file);
    file.close();

    epp_solution.print();
    cout << endl << "epp_solution - after simulated annealing" << endl;
    getchar();

    epp_solution.clear();
    problem.clear();

    return 0;
}

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
// last modification: 2023/05/12

// goal: develop a solver for extruders planning optimization

// next step: start developing a library !!!

#include "lib/extruder planning problem.h"

using namespace extruderPlanningProblemLibrary;

int main()
{
    EPPInstance problem;

    problem.EPP001();

    problem.print();
    cout << endl << "problem" << endl;
    getchar();

    EPPSolution solution;

    solution.restart(problem);
    solution.print();
    cout << endl << "empty solution" << endl;
    // getchar();

    solution.generate();
    solution.print();
    cout << endl << "initial solution" << endl;
    // getchar();

    solution.particleCollision(100,1000);
    solution.print();
    cout << endl << "solution after Particle Collision" << endl;
    //getchar();


    cout << endl << endl << "step 12: creating EPPSolution class - changing pertubation fuction - swapProduct - stop spliting batches." << endl;
    // I will change batch selection - product can replace other of different collor changing batch collor
    // so code will improuve better batches sequence triyng to reduce total setup time - ok
    // now I will change order of procedures, I'll ask for erasing first of reducing batch processing time - for improve silver performance
}

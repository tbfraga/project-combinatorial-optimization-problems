// Combinatorial Optimization Solver
//
// software created by Tatiana Balbi Fraga
//
// project started on 2023/03/29
// last modified on 2023/03/29
//
// status: under construction
//
/****************** what will be done next ?
    This first version will be built only for the solution of an allocation and balancing problem named production planning problem in extruders.
    However, this first version will already be built with a focus on the development of a solver for general combinatorial optimization problems.
    In a first moment, solutions will be developed for different classes of problems.
    In a second moment, I will be developing an algorithm, most likely based on neural networks, to identify the nature of the problem and choose the appropriate solution method.
******************/
//
/****************** what I am doing now ?
    building a library containing a class to represent the problem in question.

    this class will have:

    the problem itself as an object;
    -at least one function for creating an instance of the problem;
    -at least one function to test compatibility of problem data
    -at least one function for printing problem data;
    -at least one function for creating an initial solution;
    -at least one function for changing this solution;
    -at least one function for printing the solution.
******************/
//
// Important: Copies and distributions of the files made available in this directory must comply with the
// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

#include "lib/productionPlanningProblemInExtrudersLibrary.h"
using namespace productionPlanningProblemInExtrudersLibrary;

int main()
{
    int NDays = 1;
    int NExtruders = 2;
    vector<int> productionRate = {40,60};

    productionPlanningProblemInExtruders problem(NDays,NExtruders,productionRate);

    problem.printProblem();
}

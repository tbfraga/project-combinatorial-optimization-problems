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
// last modification: 2023/05/10

// goal: develop a solver for extruders planning optimization

// next step: start developing a library !!!

#include "lib/extruder planning problem.h"

using namespace extruderPlanningProblemLibrary;

int main()
{
    ofstream file;
    file.open ("problem.txt");

    EPPInstance problem;

    problem.EPP001();

    problem.print(file);
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

    solution.particleCollision(30,30);
    solution.print();
    cout << endl << "solution after Particle Collision" << endl;
    getchar();

    // lets stop for today

    // g/min
    // 0 240 360
    // 1 120 180
    // 2 240 360
    // 3  80 120

    // only producing 1 and 3 in _ballancing
    // some error when deleting _ballnacing ???

    cout << endl << endl << "step 13: creating class EPPSolution - looking closer - clean function." << endl;
    cout << endl << endl << "next step: printing on file." << endl;

    // we have an error in SA function
    // when we have an empty processing time batch
    // function is increasing production without changing solution
    // weird

    // sinse I have a nonsense problem, I need to look all code again

    // nest step print in a file
    // lets print all in a file ***


    // also I will be remodeling solver

    // function split is creating many batches. I need to restrict spliting in some way.
    // mabe is better if we don't split

    // nest step I'll try to change tow things: 1) one product can replace order of diffente collor an 2) do not split solutions.

    // In this way Particle Collision will work as follow:

    /*
        Pertube current solution
        if better (local exploration)
        if worse(randomly choose if it will be acepted and explored localy or not)

        also, as I remember, PCA can move to a new solution randomly generated - need to remember how it works

        pertubation of current solution will be done as follows:

        ramdomly choose a product

        if production limit is bigger than some value
        choose a batch or to create a new one

        if not (must be a way of reducing rpoduct production or just do no accept this product)

        if a batch is choosed, just insert this product on the batch
        if the color is diffent, must erase all other products, it will be the only product on batch
        if the color is the same we need to make sure the product can be inserted, mabe erasing another products on the batch

        when creating a new batch, we must have a way of ordering batches to minimize setup time, or have a function for swapping batches positions
        the first way is better since we force solution to be better

        we will not use split (since new batches can be ramdonly created)

        the probability of creating a new batch will be small 1/(number of existing batches + 1)
        we can create a variable that can control this probability but it will make solver dependent of the adjusting of this parameter (what is not realy good)
    */


    // there is bugs in code need to verify

    // next step: create a collapsing function

    // talvez a função split não seja adequada. Irei repensar o procedimento de pertubação.

    // even if we don't considere different collors we have a problem with allocation - need a function to solve it and make program converge faster
    // as we can see we have many separated batches with the same group of products and on the same extruder (next step)
    // there is a erro in code when including new batches (need to adjust correctly setup time)
    // function clean is no mere necessary after SA

    file.close();
}

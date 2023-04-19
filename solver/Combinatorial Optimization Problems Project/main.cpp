// Combinatorial Optimization Solver
//
// software created by Tatiana Balbi Fraga
//
// project started on 2023/03/29
// last modified on 2023/04/16
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
    *** functions for creating an instance of the problem and test compatibility of problem data,
        * in classe PPPIEInstance:
        - PPPIE001();
    *** at least one function for printing problem data;
    *** at least one function for creating an initial solution;
    *** at least one function for evaluating the solution;
    - at least one function for changing the solution;
    *** at least one function for printing the solution (processing time of extruders);
    - one function for applying Simulated Annealing for ajusting extruders processing time.
******************/
//
// Important: Copies and distributions of the files made available in this directory must comply with the
// Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

#include "lib/productionPlanningProblemInExtrudersLibrary.h"
using namespace productionPlanningProblemInExtrudersLibrary;

int main()
{
    PPPIEInstance problem;

    problem.PPPIE001();
    problem.print();

    PPPIESolution solution(problem);
    solution.generate();
    solution.print();
    getchar();

    PPPIESolution SASolution = solution;
    SASolution.timeSimultedAnnealing(problem, 10);

    SASolution.swapProduct(problem);

    // if you want to inform the data, use the commands that are commented below **** with erros, need to correct.

    /*unsigned int NDays = 1;

    unsigned int NExtruders = 2;
    vector<float> productionRate = {40,60};
    vector<float> length = {1.0,0.8};
    vector<vector<int>> capacity = {{420,420}};
    int setupTime = 10;
    float setupCost = 20;
    float operationCost = 0.5;

    unsigned int NProducts = 4;
    vector<float> width = {0.6,0.3,0.6,0.2};
    vector<float> weightRatio = {10,10,10,10};
    vector<float> unitContribution = {1.1,1.3,1.2,1.1};
    vector<int> initialInventory = {1000,0,2000,0};
    vector<int> maximumInventory = {10000,50000,20000,10000};
    int totalMaximumInventory = 100000;
    float inventoryUnitCost = 0.01;

    vector<vector<int>> demand = {{99400,73800,149600,35800}};
    float unmetDemandCost = 0.5;

    vector<unsigned int> color = {0,0,0,0};
    vector<vector<bool>> colorAndMaterialRatio= {{1,1,1},{1,1},{1}};

    unsigned int NOutlets = 2;
    vector<int> maximumTotalOutletInventory = {30000,20000};

    vector<vector<int>> maximumOutletInventoryPerProduct = {{1000,1000},{5000,10000},{10000,5000},{5000,500}};

    productionPlanningProblemInExtruders problem{NDays,NExtruders,productionRate,length,capacity,setupTime,setupCost,operationCost,NProducts,width,weightRatio,unitContribution,initialInventory,
    maximumInventory,totalMaximumInventory,inventoryUnitCost,demand,unmetDemandCost,color,colorAndMaterialRatio,NOutlets,maximumTotalOutletInventory,maximumOutletInventoryPerProduct};*/
}

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

#ifndef COMBINATORIAL_OPTIMIZATION_PROBLEM_H_INCLUDED
#define COMBINATORIAL_OPTIMIZATION_PROBLEM_H_INCLUDED

#include "multiperiod-multiproduct-batch-processing-time-maximization-problem.h"

//template <typename>
//class Problem;

namespace cop
{
    bool solver();
   /* template <typename problem>
    struct GetElementFunctor
    {
        using problemType = typename problem::problemType;

        GetElementFunctor(problem const& c) : c_(c) {}

        problemType const& getNthElement(std::size_t n) const
        {
            return reinterpret_cast<std::vector<problemType> const*>(&c_)->operator[](n);
        }

        problem const& c_;
    };*/

    template <class problem>
    class combinatorial_optimization_problem
    {
        //mbptmp::problem problem; // MPBPTMP linked to the solution

        template <class P, class S> friend class solution;

        private:

        problem _problem;


        unsigned int _problemType, _problemDefinitionMethod;
        // 1 - Multi-product batch processing time maximization problem
        // 2 - Multi-period and multi-product batch processing time maximization problem


        public:

        bool start();

        bool get()
        {
            return _problem.get();
        };

        bool print()
        {
            return _problem.print();
        };

        bool generateLingoData()
        {
            return _problem.generateLingoData();
        };

        void clear()
        {
            _problem.clear();
        }
    };

    template <class P>
    class problem : public combinatorial_optimization_problem<P>
    {
    };

    template <class P, class S>
    class solution
    {
        problem<P> _problem;

        S _solution;

        public:

        void start(problem<P> _problem)
        {
            _solution.start(_problem._problem);
        }

        void analyticalMethod()
        {
            _solution.analyticalMethod(0);
        }

        void clear()
        {
            _solution.clear();
        }
    };
}

/*bool func()
{
    return 0;
};*/

/*namespace cop
{
    class combinatorialOptimizationProblem
    {
        mbptmp::problem problem; // MPBPTMP linked to the solution
    };
}*/

#endif // COMBINATORIAL_OPTIMIZATION_PROBLEM_H_INCLUDED

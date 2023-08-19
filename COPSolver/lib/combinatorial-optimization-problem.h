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

namespace cop
{
    bool solver();

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

        void set_PDM(unsigned int problemDefinitionMethod)
        {
            _problemDefinitionMethod = problemDefinitionMethod;
        };

        bool get()
        {
            switch(_problemDefinitionMethod)
            {
                case 1:
                {
                    return _problem.get();
                }
                break;
                case 2:
                {
                    if (_problem.choose() == 1) return 1;
                    return 0;
                }
                break;
                case 3:
                {
                    time_t source = 0;
                    unsigned int NProducts = 10;

                    cout << endl << "Please informe the source for random generation (interger value)." << endl;
                    cout << endl << "digite option and then press enter: ";
                    cin >> source;

                    cout << endl << "Please informe number of products for random generation (interger value)." << endl;
                    cout << endl << "digite option and then press enter: ";
                    cin >> NProducts;

                    srand((unsigned) source);
                    _problem.random(NProducts);
                    return 0;
                }
                break;
                default:
                    cout << endl;
                    return 1;
            };
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
        };
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
            _solution.analyticalMethod();
        }

        void clear()
        {
            _solution.clear();
        }
    };
}

#endif // COMBINATORIAL_OPTIMIZATION_PROBLEM_H_INCLUDED

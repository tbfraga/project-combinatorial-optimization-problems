/*********************************************************************** LICENSE **********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.

This project with its files can be consulted at https://github.com/tbfraga/project-combinatorial-optimization-problems/tree/main/solver/Combinatorial%20Optimization%20Solver.
******************************************************************************************************************************************************************************/

// Combinatorial Optimization Solver
// Extruder Planning Problem Library
// developed by Tatiana Balbi Fraga
// start date: 2023/04/26
// last modification: 2023/04/26

#include "../lib/extruder planning problem.h"

namespace extruderPlanningProblemLibrary
{

    bool extruderPlanningProblem::print()
    {
        bool error = 0; // false

        cout << endl << "EXTRUDER PLANNING PROBLEM" << endl;

        cout << endl << "Days: " << _NDays << endl;

        cout << endl << "Extruders: "  << _NExtruders << endl;

        cout << endl << "setup cost: " << _setupCost << "  -  operation cost: " << _operationCost << endl;

        cout << endl << "[extruder]  production rate (m/min) / length (m)" << endl;

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            cout << endl << e << "\t" << _productionRate[e] << "\t" << _length[e];
        }

        cout << endl << endl << "[extruder, day]  capacity(min)" << endl << endl;

        for(unsigned int d=0; d<_NDays; d++)
        {
            cout << "\t" << d;
        }

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            cout << endl << e;

            for(unsigned int d=0; d<_NDays; d++)
            {
                cout << "\t" << _capacity[e][d];
            }
        }

        cout << endl << endl << "Products: " << _NProducts << endl;

        cout << endl << "[product]  width (m) / weight ratio (g/m²) / unit contribution ($/g)" << endl << "/ initial inventory (g) / maximum inventory (g) / color" << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            cout << endl << p << "\t" << _width[p] << "\t" << _weightRatio[p] << "\t" << _unitContribution[p] << "\t" << _initialInventory[p] << "\t" << _maximumInventory[p]
            << "\t" << _color[p];
        }

        cout << endl << endl << "Factory: " << endl;

        cout << endl << "maximum inventory (g): " << _totalMaximumInventory << "  -  inventory unit cost ($/g): " << _inventoryUnitCost << endl;

        cout << endl << "[product, day]  demand (g)" << endl << endl;

        for(unsigned int d=0; d<_NDays; d++)
        {
            cout << "\t" << d;
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            cout << endl << p;

            for(unsigned int d=0; d<_NDays; d++)
            {
                cout << "\t" << _demand[p][d];
            }
        }

        cout << endl << endl << "Factory: " << endl;

        cout << endl << "unmet demand cost ($/g): " << _unmetDemandCost << endl;

        cout << endl << "[product, product]  relation of products of same color and material" << endl << endl;

        for(unsigned p=0; p<_NProducts; p++)
        {
            cout << "\t" << p;
        }
        cout << endl;

        for(unsigned p=0; p<_NProducts; p++)
        {
            cout << p;

            for(unsigned k=0; k<_NProducts; k++)
            {
                cout << "\t" << _colorAndMaterialRatio[p][k];
            }
            cout << endl;
        }

        cout << endl << "Colors: " << _NColors << endl;

        cout << endl << "[color]  color group" << endl << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            cout << c;
            for(unsigned int s=0; s<_productColorGroup[c].size(); s++)
            {
                cout << "\t" << _productColorGroup[c][s];
            }
            cout << endl;
        }

        cout << endl << "[color, color]  setup time (min)" << endl << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            cout << "\t" << c;
        }
        cout << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            cout << c;
            for(unsigned int k=0; k<_NColors; k++)
            {
                cout << "\t" << _setupTime[c][k];
            }
            cout << endl;
        }

        cout << endl << "[product, extruder]  production rate (g/min)" << endl << endl;


        for(unsigned int e=0; e<_NExtruders; e++)
        {
            cout << "\t" << e;
        }
        cout << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            cout << p;
            for(unsigned int e=0; e<_NExtruders; e++)
            {
                cout << "\t" << _productionPerTime[p][e];
            }
            cout << endl;
        }

        cout << endl << "Outlets: " << _NOutlets << endl;

        cout << endl << "[outlet]  maximum outlet inventory (g)" << endl << endl;

        for(unsigned int o=0; o<_NOutlets; o++)
        {
            cout << o << "\t" << _totalMaximumOutletInventory[o] << endl;
        }

        cout << endl << "[product, outlet]  maximum inventory (g)" << endl << endl;

        for(unsigned int o=0; o<_NOutlets; o++)
        {
            cout << "\t" << o;
        }
        cout << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            cout << p;
            for(unsigned int o=0; o<_NOutlets; o++)
            {
                cout << "\t" << _maximumOutletInventory[p][o];
            }
            cout << endl;
        }

        return error;
    };

    // clearing vectors
    void extruderPlanningProblem::clear()
    {
        _productionRate.clear();
        _length.clear();

        for(unsigned int s=0; s<_capacity.size(); s++)
        {
            _capacity[s].clear();
        }
        _capacity.clear();

        _width.clear();
        _weightRatio.clear();
        _unitContribution.clear();
        _initialInventory.clear();
        _maximumInventory.clear();

        for(unsigned int s=0; s<_demand.size(); s++)
        {
            _demand[s].clear();
        }
        _demand.clear();

        _color.clear();

        for(unsigned int s=0; s<_colorAndMaterialRatio.size(); s++)
        {
            _colorAndMaterialRatio[s].clear();
        }
        _colorAndMaterialRatio.clear();

        for(unsigned int s=0; s<_setupTime.size(); s++)
        {
            _setupTime[s].clear();
        }
        _setupTime.clear();

        for(unsigned int s=0; s<_productionPerTime.size(); s++)
        {
            _productionPerTime[s].clear();
        }
        _productionPerTime.clear();

        _totalMaximumOutletInventory.clear();

        for(unsigned int s=0; s<_maximumOutletInventory.size(); s++)
        {
            _maximumOutletInventory[s].clear();
        }
        _maximumOutletInventory.clear();

        for(unsigned int s=0; s<_productColorGroup.size(); s++)
        {
            _productColorGroup[s].clear();
        }
        _productColorGroup.clear();
    };

    // calculation of parameters values

    void extruderPlanningProblem::restart()
    {
        // resizing

        _productionPerTime.resize(_NProducts);

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            _productionPerTime[p].resize(_NExtruders,0);
        }

        // calculating values

        for(unsigned int p=0; p<_NProducts; p++)
        {
            for(unsigned int e=0; e<_NExtruders; e++)
            {
                _productionPerTime[p][e] = _width[p]*_weightRatio[p]*_productionRate[e]; // (m)*(g/m²)*(m/min) = (g/min)
            }
        }

        unsigned int color;

        // grouping products by color

        _productColorGroup.resize(_NColors);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            color = _color[p];
            _productColorGroup[color].push_back(p);
        }
    }

    // class for creating instances of EPP (Extruder Planning Problem)

    void EPPInstance::EPP001()
    {
        /*****************************
        Small problem developed to test the solver operation.
        It is expected that the allocation will be done correctly according to the measurements of the products and the extruders.
        *****************************/

         clear();

        _NDays = 2;

        _NExtruders = 2;
        _productionRate = {40,60};
        _length = {1.0,0.8};
        _capacity = {{420,420},{420,420}};
        _setupCost = 20;
        _operationCost = 0.5;

        _NProducts = 4;
        _width = {0.6,0.3,0.6,0.2};
        _weightRatio = {10,10,10,10};
        _unitContribution = {1.1,1.3,1.2,1.1};
        _initialInventory = {1000,0,3000,0};
        _totalMaximumInventory = 50000;
        _maximumInventory = {10000,50000,20000,10000};
        _inventoryUnitCost = 0.01;

        _demand = {{99400,73800},{149600,35800},{2000,4000},{3000,0}};
        _unmetDemandCost = 0.5;

        _NColors = 1;
        _color = {0,0,0,0};
        _colorAndMaterialRatio = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

        _setupTime = {{10}};

        _NOutlets = 2;
        _totalMaximumOutletInventory = {10000,5000};

        _maximumOutletInventory = {{1000,1000},{5000,10000},{10000,5000},{5000,500}};

        restart();
    };

    // class for solving EPP

    void EPPSolution::clear()
    {
        _problem.clear();

        for(unsigned int s=0; s<_balancing.size(); s++)
        {
            _balancing[s].clear();
        }
        _balancing.clear();

        for(unsigned int s=0; s<_allocation.size(); s++)
        {
            _allocation[s].clear();
        }
        _allocation.clear();

        _processingTime.clear();

        _batchWidth.clear();
        _batchIdleness.clear();
        _batchColor.clear();

        for(unsigned int s=0; s<_extruderProcTime.size(); s++)
        {
            _extruderProcTime[s].clear();
        }
        _extruderProcTime.clear();

        for(unsigned int s=0; s<_extruderIdleness.size(); s++)
        {
            _extruderIdleness[s].clear();
        }
        _extruderIdleness.clear();

        for(unsigned int s=0; s<_production.size(); s++)
        {
            _production[s].clear();
        }
        _production.clear();

        for(unsigned int s=0; s<_delivered.size(); s++)
        {
            _delivered[s].clear();
        }
        _delivered.clear();

        for(unsigned int s=0; s<_unmetDemand.size(); s++)
        {
            _unmetDemand[s].clear();
        }
        _unmetDemand.clear();

        for(unsigned int s=0; s<_deliveredToOutlet.size(); s++)
        {
            for(unsigned int i=0; i<_deliveredToOutlet[s].size(); i++)
            {
                _deliveredToOutlet[s][i].clear();
            }
            _deliveredToOutlet[s].clear();
        }
        _deliveredToOutlet.clear();

        _totalFreeOutletInventory.clear();

        for(unsigned int s=0; s<_freeOutletInventory.size(); s++)
        {
            _freeOutletInventory[s].clear();
        }
        _freeOutletInventory.clear();

        for(unsigned int s=0; s<_inventory.size(); s++)
        {
            _inventory[s].clear();
        }
        _inventory.clear();

        _totalFreeInventory.clear();

        for(unsigned int s=0; s<_freeInventory.size(); s++)
        {
            _freeInventory[s].clear();
        }
        _freeInventory.clear();

        for(unsigned int s=0; s<_batchColorGroup.size(); s++)
        {
            _batchColorGroup[s].clear();
        }
        _batchColorGroup.clear();

    };

    bool EPPSolution::print()
    {
        bool error = 0;

        print(0);
        print(1);
        print(2);
        print(3);
        print(4);
        print(5);
        print(6);

        return error;
    };

    // print function used for debugging
    bool EPPSolution::print(unsigned int type)
    {
        bool error = 0;
        unsigned int batch, position = 0;

        if(type == 0) // fitness
        {
            cout << endl << endl << "SOLUTION" << endl;

            cout << endl << "fitness: " << _fitness << endl;
            cout << endl << "production total profit: " << _productionTotalProfit << endl;
            cout << endl << "unmet demand total cost: " << _unmetDemandTotalCost  << endl;
            cout << endl << "inventory total cost: " << _inventoryTotalCost<< endl;

        }else if(type == 1) // _balancing primary variables and variables linked to batch
        {
            cout << endl << "balancing [batch, product] / processing time (min) / width (m) / idleness (m)" << endl;

            cout << endl << "\t";
            for(unsigned int p=0; p<_problem._NProducts; p++)
            {
                cout << p << "\t";
            }

            cout << "time \twidth \tidleness" << endl;

            for(unsigned int b=0; b<_balancing.size(); b++)
            {
                if(b==0)
                {
                    batch = _balancing[b][0];
                    cout << batch << "\t";
                }else if(_balancing[b][0] != _balancing[b-1][0])
                {
                    for(unsigned int p=position; p<_problem._NProducts; p++)
                    {
                        cout << "\t";
                    }

                    cout << _processingTime[batch];
                    cout << "\t" << _batchWidth[batch];
                    cout << "\t" << _batchIdleness[batch];
                    //cout << "\t" << _batchColor[batch];
                    cout << endl;
                    position = 0;
                    batch = _balancing[b][0];
                    cout << batch << "\t";
                }

                for(unsigned int p=position; p<_problem._NProducts; p++)
                {
                    if(_balancing[b][1]==p)
                    {
                            cout << p << "X" << "\t";
                            position = p+1;
                            break;
                    }else
                    {
                        cout << "\t";
                    }
                }

                if(b == (_balancing.size()-1))
                {
                    for(unsigned int p=position; p<_problem._NProducts; p++)
                    {
                        cout << "\t";
                    }
                    cout << _processingTime[batch];
                    cout << "\t" << _batchWidth[batch];
                    cout << "\t" << _batchIdleness[batch];
                    cout << "\t" << _batchColor[batch];
                }
            }

            cout << endl;

        }else if(type == 2)
        {
            cout << endl << "allocation [batch, extruder, day, iterator ref, iterator ref, color]: ";
            cout << endl << endl;
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                cout << b << "\t";
                for(unsigned int i=0; i<_allocation[b].size(); i++)
                {
                    cout << _allocation[b][i] << "\t";
                }
                cout << endl;
            }
            cout << endl;

             cout << endl << "batch color group [batch vector]: " << endl << endl;

            for(unsigned int c=0; c<_batchColorGroup.size(); c++)
            {
                for(unsigned int s=0; s<_batchColorGroup[c].size(); s++)
                {
                    cout << _batchColorGroup[c][s] << "\t";
                }
                cout << endl;
            }
            cout << endl;

        }else if(type == 3)
        {
            cout << endl << "[extruder, day]" << endl;
            cout << endl << "   processing time (min)  /  idleness (min)" << endl << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                cout << "\t" << d;
            }
            cout << "\t";
            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << endl;

            for(unsigned int e=0; e<_extruderProcTime.size(); e++)
            {
                cout << endl << e;
                for(unsigned int d=0; d<_extruderProcTime[e].size(); d++)
                {
                    cout << "\t" << _extruderProcTime[e][d];
                }

                cout << "\t";
                for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
                {
                    cout << "\t" << _extruderIdleness[e][d];
                }
                cout << endl;
            }
            cout << endl;

        }else if(type == 4)
        {
            cout << endl << "production / demand (g) [product, day]:" << endl;
            cout << endl << "\t" << "production" << "\t\t" << "delivered" << "\t\t" << "unmet" << "\t\t\t" << "demand";
            cout << endl << endl;

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << endl << endl;

            for(unsigned int p=0; p<_production.size(); p++)
            {
                cout << p;
                for(unsigned int d=0; d<_production[p].size(); d++)
                {
                    cout << "\t" << _production[p][d];
                }

                cout << "\t";

                for(unsigned int d=0; d<_delivered[p].size(); d++)
                {
                    cout << "\t" << _delivered[p][d];
                }

                cout << "\t";

                for(unsigned int d=0; d<_unmetDemand[p].size(); d++)
                {
                    cout << "\t" << _unmetDemand[p][d];
                }

                cout << "\t";

                for(unsigned int d=0; d<_problem._demand[p].size(); d++)
                {
                    cout << "\t" << _problem._demand[p][d];
                }

                cout << endl;
            }
            cout << endl;

            if(error == 1) cout << endl << "error: demand variables not correctly calculated." << endl;

        }else if (type == 5)
        {
            cout << endl  << endl;

            cout << "delivered to outlet (g) [product, outlet, day]" << endl << endl;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                cout << "\t" << "outlet: " << o;

                for(unsigned int d=2; d<_problem._NDays; d++)
                {
                    cout << "\t";
                }
            }

            cout << "\t" << "free";

            cout << endl << endl;

            for (unsigned int d=0; d<=_problem._NDays; d++)
            {
                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    cout << "\t" << o;
                }
            }

            cout << endl << endl;

            for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
            {
                cout << p;
                for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
                {
                    for(unsigned int d=0; d<_deliveredToOutlet[p][o].size(); d++)
                    {
                        cout << "\t" << _deliveredToOutlet[p][o][d];
                    }
                }

                for(unsigned int o=0; o<_freeOutletInventory[p].size(); o++)
                {
                    cout << "\t" << _freeOutletInventory[p][o];
                }

                cout << endl;
            }

            cout << endl;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                for(unsigned int d=0; d<_problem._NDays; d++)
                {
                    cout << "\t";
                }
            }

            cout << "total:";

            for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
            {
                cout << "\t"<< _totalFreeOutletInventory[o] ;
            }
            cout << endl;

        }else if(type == 6)  // inventory
        {
            cout << endl << "inventory (g) [product, day]" << endl << endl;
            cout << "\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "maximum";
            cout << endl << endl;

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                cout << "\t" << d;
            }

            cout << endl << endl;

            for(unsigned int p=0; p<_inventory.size(); p++)
            {
                cout << p;
                for(unsigned int d=0; d<_inventory[p].size(); d++)
                {
                    cout << "\t" << _inventory[p][d];
                }

                cout << "\t";

                for(unsigned int d=0; d<_freeInventory[p].size(); d++)
                {
                    cout << "\t"<< _freeInventory[p][d];
                    if(_freeInventory[p][d] > _problem._maximumInventory[p]) error = 1;
                }

                cout << "\t";

                cout << "\t"<< _problem._maximumInventory[p];

                cout << endl;
            }

            cout << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                cout << "\t";
            }

            cout << "\t" << "total:";
            for(unsigned int d=0; d< _totalFreeInventory.size(); d++)
            {
                cout << "\t" << _totalFreeInventory[d] ;
                if(_totalFreeInventory[d] > _problem._totalMaximumInventory) error = 1;
            }
            cout << "\t" << "total:" << "\t" << _problem._totalMaximumInventory;

            cout << endl << endl;

            if(error == 1) cout << "error: inventory variables not correctly calculated." << endl;

        }else
        {
            cout << endl << "info: please, choose a type betwing 0 and 6." << endl;
            /*
            cout << endl;
            cout << "restricted: "<< endl;
            cout << endl;
            for(unsigned int i=0; i<_restricted.size(); i++)
            {
                for(unsigned int j=0; j<_restricted[i].size(); j++)
                {
                    cout << _restricted[i][j] << "\t";
                }
                cout << endl;
            }
            */
        }

        if(error == 1) getchar();
        return error;
    };

    // create an empty initial solution for the problem
    void EPPSolution::restart(EPPInstance problem)
    {
        clear();

        // linking solution to the problem
        _problem = problem;

        cout << endl << "function: generate an empty initial solution for the <problem>." << endl;

        _fitness = 0;
        _productionTotalProfit = 0;
        _unmetDemandTotalCost = 0;
        _inventoryTotalCost = 0;

        _extruderProcTime.resize(problem._NExtruders);
        _extruderIdleness.resize(problem._NExtruders);
        for(unsigned int e=0; e<problem._NExtruders; e++)
        {
            _extruderProcTime[e].resize(problem._NDays,0);
            _extruderIdleness[e].resize(problem._NDays,0);

            for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
            {
                _extruderIdleness[e][d] = problem._capacity[e][d];
            }
        }

        _batchColorGroup.resize(problem._NColors);

        _production.resize(problem._NProducts);
        for(unsigned int p=0; p<_production.size(); p++)
        {
            _production[p].resize(problem._NDays,0);
        }

        _totalFreeInventory.resize(problem._NDays,0);

        for(unsigned int d=0; d<_totalFreeInventory.size(); d++)
        {
            _totalFreeInventory[d] = problem._totalMaximumInventory;
        }

        _inventory.resize(problem._NProducts);
        _freeInventory.resize(problem._NProducts);

        for(unsigned int p=0; p<problem._NProducts; p++)
        {
            _inventory[p].resize(problem._NDays,0);
            _freeInventory[p].resize(problem._NDays,0);
            for(unsigned int d=0; d<problem._NDays; d++)
            {
                _inventory[p][d] = problem._initialInventory[p];
                _freeInventory[p][d] = problem._maximumInventory[p] - problem._initialInventory[p];
                _totalFreeInventory[d] -= _inventory[p][d];
                _inventoryTotalCost += _inventory[p][d]*problem._inventoryUnitCost;
            }
        }

        _delivered.resize(problem._NProducts);
        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            _delivered[p].resize(problem._NDays,0);

            for(unsigned int d=0; d<_delivered[p].size(); d++)
            {
                if(problem._demand[p][d] >= _inventory[p][d])
                {
                    _delivered[p][d] = _inventory[p][d];
                }else
                {
                    _delivered[p][d] = problem._demand[p][d];
                }

                for(unsigned int i=d; i<problem._NDays; i++)
                {
                    _inventory[p][i] -= _delivered[p][d];
                    _freeInventory[p][i] += _delivered[p][d];
                    _totalFreeInventory[i] += _delivered[p][d];
                    _inventoryTotalCost -= _delivered[p][d]*problem._inventoryUnitCost;
                }
            }
        }

        _unmetDemand.resize(problem._NProducts);
        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].resize(problem._NDays,0);

            _unmetDemand[p][0] = problem._demand[p][0]-_delivered[p][0];
            _unmetDemandTotalCost += _unmetDemand[p][0]*problem._unmetDemandCost;

            for(unsigned int d=1; d<_unmetDemand[p].size(); d++)
            {
                _unmetDemand[p][d] = _unmetDemand[p][d-1] + problem._demand[p][d] - _delivered[p][d];
                _unmetDemandTotalCost += _unmetDemand[p][d]*problem._unmetDemandCost;
            }
        }

        _fitness -= _unmetDemandTotalCost;

        _totalFreeOutletInventory.resize(problem._NOutlets,0);
        for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
        {
            _totalFreeOutletInventory[o] = problem._totalMaximumOutletInventory[o];
        }

        _freeOutletInventory.resize(problem._NProducts);
        for(unsigned int p=0; p<_freeOutletInventory.size(); p++)
        {
            _freeOutletInventory[p].resize(problem._NOutlets,0);

            for(unsigned int o=0; o<_freeOutletInventory[p].size(); o++)
            {
                if(_freeOutletInventory[p][o] <= _totalFreeOutletInventory[o])
                {
                    _freeOutletInventory[p][o] = problem._maximumOutletInventory[p][o];
                }else
                {
                    _freeOutletInventory[p][o] = _totalFreeOutletInventory[o];
                }
            }
        }

        unsigned int aux, day;

        _deliveredToOutlet.resize(problem._NProducts);
        for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
        {
            _deliveredToOutlet[p].resize(problem._NOutlets);
            for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
            {
                _deliveredToOutlet[p][o].resize(problem._NDays,0);

                for(unsigned int d=0; d<_deliveredToOutlet[p][o].size(); d++)
                {
                    aux = _inventory[p][d];
                    day = d;

                    for(unsigned int i=d+1; i<problem._NDays; i++)
                    {
                        if(_inventory[p][i]<aux)
                        {
                            aux = _inventory[p][i];
                            day = i;
                        }
                    }

                    if(_inventory[p][day] != 0)
                    {
                        if(_inventory[p][d] <= _freeOutletInventory[p][o] || _inventory[p][day] <= _freeOutletInventory[p][o])
                        {
                            if(_inventory[p][d] <= _inventory[p][day])
                            {
                                _deliveredToOutlet[p][o][d] = _inventory[p][d];
                            }else
                            {
                                _deliveredToOutlet[p][o][d] = _inventory[p][day];
                            }
                        }else
                        {
                            _deliveredToOutlet[p][o][d] = _freeOutletInventory[p][o];
                        }

                        _freeOutletInventory[p][o] -= _deliveredToOutlet[p][o][d];
                        _totalFreeOutletInventory[o] -= _deliveredToOutlet[p][o][d];

                        for(unsigned int i=d; i<problem._NDays; i++)
                        {
                            _inventory[p][i] -= _deliveredToOutlet[p][o][d];
                            _totalFreeInventory[i] += _deliveredToOutlet[p][o][d];
                            _freeInventory[p][i] += _deliveredToOutlet[p][o][d];
                            _inventoryTotalCost -= _deliveredToOutlet[p][o][d]*problem._inventoryUnitCost;
                        }
                    }
                }
            }
        }

        _fitness -= _inventoryTotalCost;
    };

    // generate an inicial (not empty) solution

    void EPPSolution::generate()
    {
        cout << endl << "function: generating a new solution... " << endl;

        // taking the biggest setup time

        unsigned int setup = _problem._setupTime[0][0];

        for(unsigned int i=0; i<_problem._setupTime.size(); i++)
        {
            for(unsigned int j=0; j<_problem._setupTime[i].size(); j++)
            {
                if(_problem._setupTime[i][j] > setup)
                {
                    setup = _problem._setupTime[i][j];
                }
            }
        }

        // calculating a mean batch time

        unsigned int totalCapacity = 0;

        for(unsigned int e=0; e<_problem._NExtruders; e++)
        {
            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                totalCapacity = totalCapacity + _problem._capacity[e][d];
            }
        }

        unsigned int batchTime = rint(totalCapacity / _problem._NProducts) - setup;

        cout << endl << "batch time: " << batchTime << endl;

        // creating a batch for each product

        bool stop;
        unsigned int day = 0;
        unsigned int extruder = 0;
        unsigned int production = 0, prodLimit = 0;
        unsigned int time = 0;
        vector<unsigned int> newVector, productList;

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
            cout << endl << "product: " << p << endl;

            extruder = _problem._NExtruders;
            day = 0;
            time = 0;
            stop = 0;

            for(unsigned int e=0; e<_problem._NExtruders; e++)
            {
                if(_problem._width[p] <= _problem._length[e])
                {
                    cout << endl << "width ok";
                    extruder = e;

                    for(unsigned int d=0; d<_problem._NDays; d++)
                    {
                        production = batchTime*_problem._productionPerTime[p][e];

                        prodLimit = productionLimit(p,d);

                        if(production <= prodLimit)
                        {
                            time = batchTime;
                        }else
                        {
                            cout << endl << "inventory problem !!!";
                            cout << endl << "production reduced...";
                            production = prodLimit;
                            time = rint(floor(production / _problem._productionPerTime[p][e]));
                        }
                        cout << endl << "production: " << production << endl;
                        cout << endl << "time: " << time << endl;

                        if(time <= _extruderIdleness[e][d])
                        {
                            cout << endl << "found solution";
                            day = d;
                            stop = 1;
                            break;
                        }else
                        {
                            production = 0;
                            time = 0;
                            cout << endl << "time not ok";
                        }
                    }

                    if(stop == 1)
                    {
                        break;
                    }
                }
            }

            // creating a new batch

            cout << endl << "Solution found: " << endl;

            cout << endl << "extruder: " << extruder;
            cout << endl << "day: " << day;
            cout << endl << "time: " << time;
            cout << endl << "production: " << production << endl;

            if (extruder < _problem._NExtruders)
            {
                insert({p}, extruder, day, time);
            }else
            {
                cout << endl << "Product " << p << " cannot be allocated cause its width is very large for extruders !!!" << endl;
            }
        }

        newVector.clear();
        productList.clear();
    };

    // calculate largest possible production for <product> on <day>

    unsigned int EPPSolution::productionLimit(unsigned int product, unsigned int day)
    {
        cout << endl << "function: production limit calculation." << endl;

        unsigned int prodLimit;

        unsigned int totalFreeInventory = _totalFreeInventory[day];
        unsigned int freeInventory = _freeInventory[product][day];

        for(unsigned int d=day+1; d<_problem._NDays; d++)
        {
            if(totalFreeInventory > _totalFreeInventory[d])
            {
                totalFreeInventory = _totalFreeInventory[d];
            }

            if(freeInventory > _freeInventory[product][d])
            {
                freeInventory = _freeInventory[product][d];
            }
        }

        if(totalFreeInventory >= freeInventory)
        {
            prodLimit = freeInventory;
        }else
        {
            prodLimit = totalFreeInventory;
        }

        cout << endl << "Limit inventory: " << prodLimit << endl;

        prodLimit += _unmetDemand[product][day];

        cout << endl << "Limit inventory + unmet demand: " << prodLimit << endl;

        for(unsigned int o=0; o<_problem._NOutlets; o++)
        {
            if(_totalFreeOutletInventory[o] < _freeOutletInventory[product][o])
            {
                prodLimit += _totalFreeOutletInventory[o];
            }else
            {
                prodLimit += _freeOutletInventory[product][o];
            }
        }

        cout << endl << "Limit inventory + unmet demand + outlet: " << prodLimit << endl;

        return prodLimit;
    };

    // create new batch and adjust linked variables

    bool EPPSolution::insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time)
    {
        cout << endl << "function: creating a new batch: ";

        unsigned int batch = _allocation.size();
        cout << batch << endl;

        if(productList.size() > 1)
        {
            cout << endl << "info: verifying products similarity." << endl;

            for(unsigned int s=1; s<productList.size(); s++)
            {
                if(_problem._colorAndMaterialRatio[productList[0]][productList[s]] == 0)
                {
                    cout << endl << "error: products on batch must have same color and material !" << endl;
                    cout << endl << "info: batch will not be created." << endl;
                    getchar();
                    return 1;
                }
            }
        }

        unsigned int positionFirst = _balancing.size();
        unsigned int positionLast = positionFirst;

        unsigned int color, product;

        if(productList.size() == 0)
        {
            cout << endl << "info: creating an empty batch." << endl;
            color = 0;
        }else
        {
            positionLast += productList.size() - 1;

            product = productList[0];
            color = _problem._color[product];
        }

        vector <unsigned int> newVector;

        // finding setup time

        unsigned int prevColor;

        if(_balancing.size() > 0)
        {
            newVector = _balancing.back();
            product = newVector[1];
            prevColor = _problem._color[product];
        }else
        {
            prevColor = color;
        }

        float width = 0;

        if(_extruderIdleness[extruder][day] < time + _problem._setupTime[prevColor][color])
        {
            cout << endl << "error: extruder idleness must be grater than or equal to the <time> of batch + setup time !" << endl;
            cout << endl << "info: batch will not be created." << endl;
            getchar();
            return 1;
        }

        cout << endl << "info: creating new batch and adjusting linked variables." << endl;

        for(unsigned int i=0; i<productList.size(); i++)
        {
            product = productList[i];
            newVector.clear();
            newVector = {batch,product};
            _balancing.push_back(newVector);
            width += _problem._width[product];

            cout << endl << "product inserted: "<< product << " width: " << _problem._width[product] << endl;
        }

        _batchColorGroup[color].push_back(batch);

        _batchWidth.push_back(width);
        _batchIdleness.push_back(_problem._length[extruder] - width);

        // adjusting _allocation

        newVector.clear();
        newVector = {extruder,day,positionFirst,positionLast,color};
        _allocation.push_back(newVector);

        _processingTime.push_back(time);
        _extruderProcTime[extruder][day] += time + _problem._setupTime[prevColor][color];
        _extruderIdleness[extruder][day] -= time + _problem._setupTime[prevColor][color];

        if(time > 0)
        {
            unsigned int production;

            for(unsigned int i=0; i<productList.size(); i++)
            {
                product = productList[i];
                production = time*_problem._productionPerTime[product][extruder];

                cout << endl << "product: " << product << "  production: " << production << endl;

                increase(production, product, day);
            }
        }

        newVector.clear();
        return 0;
    };

    // increase production and adjust linked variables

    void EPPSolution::increase(unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: increase production." << endl;

        _production[product][day] += production;
        _productionTotalProfit += production*_problem._unitContribution[product];

        print(0);
        print(4);
        print(5);
        print(6);

        deliver(product);

         cout << endl << "info: after encreasing." << endl;

        print(0);
        print(4);
        print(5);
        print(6);

        getchar();
    };

    // distribute production between demand, outlets and inventory

    void EPPSolution::deliver(unsigned int product)
    {
        cout << endl << "function: deliver production between demand, outlets and inventory." << endl;

        // clearing distribution of <product>

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            _unmetDemandTotalCost -= _unmetDemand[product][d]*_problem._unmetDemandCost;
            _unmetDemand[product][d] = 0;

            if (d == 0)
            {
                _unmetDemand[product][d] = _problem._demand[product][d];
            }else
            {
                _unmetDemand[product][d] = _unmetDemand[product][d-1] + _problem._demand[product][d];
            }
            _unmetDemandTotalCost += _unmetDemand[product][d]*_problem._unmetDemandCost;

            _delivered[product][d] = 0;

            _totalFreeInventory[d] += _inventory[product][d];
            _freeInventory[product][d] += _inventory[product][d];
            _inventoryTotalCost -= _inventory[product][d]*_problem._inventoryUnitCost;

            _inventory[product][d] = 0;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                _totalFreeOutletInventory[o] += _deliveredToOutlet[product][o][d];
                _freeOutletInventory[product][o] += _deliveredToOutlet[product][o][d];
                _deliveredToOutlet[product][o][d] = 0;
            }

        }

        print(0);
        print(4);
        print(5);
        print(6);

        // distributing again

        unsigned int delivered;
        vector<unsigned int> distribution;

        distribution.clear();
        distribution.resize(_problem._NDays,0);

        if(_problem._NDays >= 1) distribution[0] += _problem._initialInventory[product];

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            distribution[d] += _production[product][d];
        }

        // distributing to demand

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            cout << endl << "distribution " << d << ": " << distribution[d] << endl;

            for(unsigned int l=d; l<_problem._NDays; l++)
            {
                if(distribution[d] <= _unmetDemand[product][l])
                {
                    delivered = distribution[d];

                }else
                {
                    delivered = _unmetDemand[product][l];
                }

                cout << endl << "delivered: " << delivered << endl;

                if(delivered > 0)
                {
                    _delivered[product][l] += delivered;

                    for(unsigned int k=l; k<_problem._NDays; k++)
                    {
                        _unmetDemand[product][k] -= delivered;
                        _unmetDemandTotalCost -= delivered*_problem._unmetDemandCost;
                    }

                    for(unsigned int k=d; k<l; k++)
                    {
                        _inventory[product][k] += delivered;
                        _totalFreeInventory[k] -= delivered;
                        _freeInventory[product][k] -= delivered;
                        _inventoryTotalCost += delivered*_problem._inventoryUnitCost;
                    }

                    distribution[d] -= delivered;
                }

                if(distribution[d] == 0) break;
            }
        }

        print(4);
        print(5);
        print(6);

        // distributing to outlets

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(distribution[d] > 0)
            {
                // distributing to outlets
                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    cout << endl << "free " << _freeOutletInventory[product][o] << " total free " << _totalFreeOutletInventory[o] << endl;

                    if(_totalFreeOutletInventory[o] < _freeOutletInventory[product][o])
                    {
                        delivered = _totalFreeOutletInventory[o];
                    }else
                    {
                        delivered = _freeOutletInventory[product][o];
                    }

                    if(distribution[d] < delivered)
                    {
                        delivered = distribution[d];
                    }

                    cout << endl << "delivered to outlet " << o << ": " << delivered << endl;

                    _deliveredToOutlet[product][o][d] += delivered;
                    _freeOutletInventory[product][o] -= delivered;
                    _totalFreeOutletInventory[o] -= delivered;

                    distribution[d] -= delivered;


                    if(distribution[d] == 0) break;
                }

                // distributing to inventory

                if(distribution[d] > 0)
                {
                    for(unsigned int l=d; l<_problem._NDays; l++)
                    {
                        _inventory[product][l] += distribution[d];
                        _totalFreeInventory[l] -= distribution[d];
                        _freeInventory[product][l] -= distribution[d];
                        _inventoryTotalCost += distribution[d]*_problem._inventoryUnitCost;
                    }
                }
            }
        }

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

        print(0);
        print(4);
        print(5);
        print(6);

        distribution.clear();
    };
}

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
        // _batchColor.clear();

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
            cout << endl << "[batch, product]" << endl;
            cout << endl << "balancing / processing time (min) / width (m) / idleness (m)" << endl;

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
                }else if(_balancing[b][0] != _balancing[b-1][0]) // if not the same batch
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
                    //cout << "\t" << _batchColor[batch];
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

        bool i_print = 0;

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

        if(i_print == 1) cout << endl << "batch time: " << batchTime << endl;

        // creating a batch for each product

        bool stop;
        unsigned int day = 0;
        unsigned int extruder = 0;
        unsigned int production = 0, prodLimit = 0;
        unsigned int time = 0;
        vector<unsigned int> newVector, productList;

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
             if(i_print == 1) cout << endl << "product: " << p << endl;

            extruder = _problem._NExtruders;
            day = 0;
            time = 0;
            stop = 0;

            for(unsigned int e=0; e<_problem._NExtruders; e++)
            {
                if(_problem._width[p] <= _problem._length[e])
                {
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
                             if(i_print == 1) cout << endl << "inventory problem !!!";
                             if(i_print == 1) cout << endl << "production reduced...";
                            production = prodLimit;
                            time = rint(floor(production / _problem._productionPerTime[p][e]));
                        }
                        cout << endl << "production: " << production << endl;
                        cout << endl << "time: " << time << endl;

                        if(time <= _extruderIdleness[e][d])
                        {
                             if(i_print == 1) cout << endl << "found solution";
                            day = d;
                            stop = 1;
                            break;
                        }else
                        {
                            production = 0;
                            time = 0;
                             if(i_print == 1) cout << endl << "time not ok";
                        }
                    }

                    if(stop == 1)
                    {
                        break;
                    }
                }
            }

            // creating a new batch

            if(i_print == 1) cout << endl << "Solution found: " << endl;

            if(i_print == 1) cout << endl << "extruder: " << extruder;
            if(i_print == 1) cout << endl << "day: " << day;
            if(i_print == 1) cout << endl << "time: " << time;
            if(i_print == 1) cout << endl << "production: " << production << endl;

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

        bool i_print =0;

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

        if(i_print == 1)  cout << endl << "Limit inventory: " << prodLimit << endl;

        unsigned int demandLimit;

        demandLimit = _unmetDemand[product][day];

        for(unsigned int d=day; d<_problem._NDays; d++)
        {
            if(demandLimit > _unmetDemand[product][d])
            {
                demandLimit = _unmetDemand[product][d];
            }
        }

        prodLimit += demandLimit;

        if(i_print == 1) cout << endl << "Limit inventory + unmet demand: " << prodLimit << endl;

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

        if(i_print == 1)cout << endl << "Limit inventory + unmet demand + outlet: " << prodLimit << endl;

        return prodLimit;
    };

    // create a new batch and adjust linked variables

    bool EPPSolution::insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time)
    {
        cout << endl << "function: creating a new batch.";

        bool i_print = 1;

        unsigned int batch = _allocation.size(); // selecting the new position
        if(i_print == 1) cout << endl << "new position: " << batch << endl;

        if(productList.size() > 1) // verify if products are of same color and material
        {
            if(i_print == 1) cout << endl << "info: verifying products similarity" << endl;

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

        // identifying _balancing indexes and batch color

        unsigned int positionFirst = _balancing.size(); // _balancing indexes
        unsigned int positionLast = positionFirst;

        unsigned int color=0, product;

        if(productList.size() == 0)
        {
            if(i_print == 1) cout << endl << "info: creating an empty batch." << endl;
            color = 0;
        }else
        {
            positionLast += productList.size() - 1;

            product = productList[0];
            color = _problem._color[product]; // selecting batch color
        }

        vector <unsigned int> newVector;

        // finding setup time

        unsigned int prevColor;

        if(_balancing.size() > 0)
        {
            newVector = _balancing.back();
            prevColor = _problem._color[newVector[1]];
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

        if(i_print == 1) cout << endl << "info: creating new batch and adjusting linked variables." << endl;

        for(unsigned int i=0; i<productList.size(); i++)
        {
            product = productList[i];
            newVector.clear();
            newVector = {batch,product};
            _balancing.push_back(newVector);
            width += _problem._width[product];

            if(i_print == 1) cout << endl << "product inserted: "<< product << " width: " << _problem._width[product] << endl;
        }

        cout << endl << "color: " << color << endl;

        _batchColorGroup[color].push_back(batch);

        _batchWidth.push_back(width);
        _batchIdleness.push_back(_problem._length[extruder] - width);
        _batchColor.push_back(color);

        // adjusting _allocation

        newVector.clear();

        newVector = {extruder,day,positionFirst,positionLast,color};
        _allocation.push_back(newVector);

        _processingTime.push_back(time);
        _extruderProcTime[extruder][day] += time + _problem._setupTime[prevColor][color];
        _extruderIdleness[extruder][day] -= time + _problem._setupTime[prevColor][color];

        if(i_print == 1) cout << endl << "extruder processing time: " << _extruderProcTime[extruder][day]  << "  extruder idleness: " << _extruderIdleness[extruder][day] << endl;

        if(time > 0)
        {
            unsigned int production; // increasing production and adjusting linked variables

            for(unsigned int i=0; i<productList.size(); i++)
            {
                product = productList[i];
                production = time*_problem._productionPerTime[product][extruder];

                if(i_print == 1) cout << endl << "product: " << product << "  production: " << production << endl;

                i_print = increase(production, product, day);
            }
        }

        newVector.clear();
        return i_print;
    };

    // increase production and adjust linked variables

    bool EPPSolution::increase(unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: increase production." << endl;

        bool i_print = 1;

        _production[product][day] += production;
        _productionTotalProfit += production*_problem._unitContribution[product];

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        i_print = deliver(product);

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        if(i_print == 1) cout << endl << "info: after encreasing." << endl;
        if(i_print == 1) getchar();

        return i_print;
    };

    // distribute production between demand, outlets and inventory

    bool EPPSolution::deliver(unsigned int product)
    {
        cout << endl << "function: delivering production between demand, outlets and inventory." << endl;

        bool i_print = 1;

        // clearing distribution of <product>

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            _unmetDemandTotalCost -= _unmetDemand[product][d]*_problem._unmetDemandCost;

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
            _freeInventory[product][d] = _problem._maximumInventory[product];
            _inventoryTotalCost -= _inventory[product][d]*_problem._inventoryUnitCost;

            _inventory[product][d] = 0;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                _totalFreeOutletInventory[o] += _deliveredToOutlet[product][o][d];
                _freeOutletInventory[product][o] = _problem._maximumOutletInventory[product][o];
                _deliveredToOutlet[product][o][d] = 0;
            }

        }

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        cout << endl << "info: deliver cleared." << endl;

        // distributing again

        unsigned int delivered;
        vector<unsigned int> distribution;

        distribution.clear();
        distribution.resize(_problem._NDays,0);

        // calculating daily distribution

        if(_problem._NDays >= 1) distribution[0] += _problem._initialInventory[product];

        if(i_print == 1) cout << endl << "distribution: ";
        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            distribution[d] += _production[product][d];
            if(i_print == 1) cout << "\t" << distribution[d];
        }
        if(i_print == 1) cout << endl;

        // distributing to demand

        unsigned int day;

        unsigned unmet = 0; // variable used to store the aggregated value of the unmet demand, counting from the last date to the date under analysis.

        // backward distribution

        /* it is needed to do the backward distribution first so that the distribution values are updated correctly
           and the products are shipped to the outlets on the correct dates.*/

        if(i_print ==1) cout << endl << "backward distribution" << endl;

        for(unsigned int d=_problem._NDays; d>0; d--)
        {
            day = d-1;

            cout << endl << "day: " << day << endl;

            unmet +=  _problem._demand[product][day];

            if(i_print == 1) cout << endl << "distribution (demand): " << distribution[day] << "  unmet: " << unmet << endl;

            if(distribution[day] > 0 && unmet > 0) forwardDelivery(product, day, distribution[day], unmet);

            if(i_print == 1) cout << endl << "after forward delivery function distribution: " << distribution[day] << "  unmet: " << unmet << endl;
        }

        // forward distribution

        if(i_print == 1) cout << endl << " after backward distribution: " << distribution[day] << "  unmet: " << unmet << endl;

        //forwardDelivery(product, 0, distribution[day]);
        // it is necessary ?

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);
        getchar();

        // distributing to outlets

        // problem here ???

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            cout << endl << "day: " << d << "  distribution (outlet): " << distribution[d] << endl;
            if(distribution[d] > 0)
            {
                // distributing to outlets
                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    cout << endl << "outlet: " << o << " free: " << _freeOutletInventory[product][o] << " total free: " << _totalFreeOutletInventory[o] << endl;

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

                    if(i_print == 1) cout << endl << "delivered to outlet " << o << ": " << delivered << endl;

                    _deliveredToOutlet[product][o][d] += delivered;
                    _freeOutletInventory[product][o] -= delivered;
                    _totalFreeOutletInventory[o] -= delivered;

                    distribution[d] -= delivered;

                    if(distribution[d] == 0) break;
                }

                // distributing to inventory

                cout << endl << "day: " << d << "  distribution (inventory): " << distribution[d] << endl;

                if(distribution[d] > 0)
                {
                    for(unsigned int l=d; l<_problem._NDays; l++)
                    {
                        _inventory[product][l] += distribution[d];
                        _totalFreeInventory[l] -= distribution[d];
                        _freeInventory[product][l] -= distribution[d];
                        _inventoryTotalCost += distribution[d]*_problem._inventoryUnitCost;

                        if(_inventory[product][l] > _problem._maximumInventory[product])
                        {
                            print(4);

                            cout << endl << "error: inventory of product " << product << " exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }

                        if(_totalFreeInventory[l] > _problem._totalMaximumInventory)
                        {
                            print(4);

                            cout << endl << "error: free inventory exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }

                        if(_freeInventory[product][l] > _problem._maximumInventory[product])
                        {
                            print(4);

                            cout << endl << "error: free inventory of product " << product << " exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }
                    }
                }
            }
        }

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        distribution.clear();

        return 0;
    };

    void EPPSolution::forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution)
    {
        bool i_print = 1;

        unsigned int day, delivered;

        for(unsigned int d=start; d<_problem._NDays; d++)
        {
            day = d;

            if(i_print == 1) cout << endl << "forward distribution " << day << ": " << distribution << endl;

            for(unsigned int l=day; l<_problem._NDays; l++)
            {
                if(distribution <= _unmetDemand[product][l])
                {
                    delivered = distribution;

                }else
                {
                    delivered = _unmetDemand[product][l];
                }

                if(i_print == 1) cout << endl << "delivered: " << delivered << endl;

                if(delivered > 0)
                {
                    _delivered[product][l] += delivered;

                    for(unsigned int k=l; k<_problem._NDays; k++)
                    {
                        _unmetDemand[product][k] -= delivered;
                        _unmetDemandTotalCost -= delivered*_problem._unmetDemandCost;
                    }

                    for(unsigned int k=day; k<l; k++) // between the day it was produced and the day before
                    {
                        _inventory[product][k] += delivered;
                        _totalFreeInventory[k] -= delivered;
                        _freeInventory[product][k] -= delivered;
                        _inventoryTotalCost += delivered*_problem._inventoryUnitCost;
                    }

                    distribution -= delivered;
                }

                if(distribution == 0) break;
            }
        }
    };

    void EPPSolution::forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution, unsigned int &unmet)
    {
        bool i_print = 1;

        unsigned int day, delivered, diff;

        for(unsigned int d=start; d<_problem._NDays; d++)
        {
            day = d;

            if(i_print == 1) cout << endl << "forward distribution " << day << ": " << distribution << endl;

            for(unsigned int l=day; l<_problem._NDays; l++)
            {
                if(distribution < _unmetDemand[product][l])
                {
                    delivered = distribution;

                }else
                {
                    delivered = _unmetDemand[product][l];
                }

                // on backward delivering diff will always be +

                diff = _problem._demand[product][day] - _delivered[product][day];

                cout << endl << "diff: " << diff << endl;

                if(delivered > diff)
                {
                    delivered = diff;
                }

                if(i_print == 1) cout << endl << "delivered: " << delivered << endl;

                if(delivered > 0)
                {
                    _delivered[product][l] += delivered;

                    for(unsigned int k=l; k<_problem._NDays; k++)
                    {
                        _unmetDemand[product][k] -= delivered;
                        _unmetDemandTotalCost -= delivered*_problem._unmetDemandCost;
                    }

                    for(unsigned int k=day; k<l; k++) // between the day it was produced and the day before
                    {
                        _inventory[product][k] += delivered;
                        _totalFreeInventory[k] -= delivered;
                        _freeInventory[product][k] -= delivered;
                        _inventoryTotalCost += delivered*_problem._inventoryUnitCost;
                    }

                    distribution -= delivered;
                    unmet -= delivered;
                }

                if(distribution == 0 || unmet == 0) break;
            }
        }
    };

    // apply a simulated annealing method for improving batches processing times

    void EPPSolution::simultedAnnealing(unsigned int NMaxIte)
    {
        cout << endl << "function: Simulated Annealing." << endl;

        bool i_print = 0;

        float probality = 0, aux = 0;

        EPPSolution solution;
        EPPSolution bestSolution = autoCopy();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            if(i_print == 1) cout << endl << "iteration: " << ite << endl;

            solution = autoCopy();
            solution.swapTime();

            if(i_print == 1) cout << endl << "best fitness: " << _fitness << "  solution fitness: " << solution._fitness << endl;

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    if(i_print == 1) cout << endl << "info: found a better solution." << endl;
                    bestSolution.set(solution);
                    ite = 0;
                }

                if(i_print == 1) cout << endl << "solution improved..." << endl;
                set(solution);
                //print();
                //cout << endl << "info: solution improved by SA." << endl;
                //getchar();
            }else
            {
                probality = solution._fitness / bestSolution._fitness;
                if(i_print == 1) cout << endl << "probality: " << probality << endl;
                aux = rand();
                aux = aux;
                if(i_print == 1) cout << endl << "random: " << aux << endl;

                if(aux <= probality)
                {
                    if(i_print == 1) cout << endl << "solution acepted..." << endl;
                    set(solution);
                    //print();
                    //cout << endl << "info: solution accepted by SA." << endl;
                    //getchar();
                }
            }
            cout << endl << "SA iteration: " << ite << endl;
        }

        set(bestSolution);

        solution.clear();
        bestSolution.clear();
    };

    // create a copy of the current solution by delivering this value to a variable of type EPPSolution

    EPPSolution EPPSolution::autoCopy()
    {
        EPPSolution solution;

        solution._problem = _problem;
        solution._balancing = _balancing;
        solution._allocation = _allocation;
        solution._processingTime = _processingTime;
        solution._batchWidth = _batchWidth;
        solution._batchIdleness = _batchIdleness;
        solution._extruderProcTime = _extruderProcTime;
        solution._extruderIdleness = _extruderIdleness;
        solution._production = _production;
        solution._delivered = _delivered;
        solution._unmetDemand = _unmetDemand;
        solution._deliveredToOutlet = _deliveredToOutlet;
        solution._totalFreeOutletInventory = _totalFreeOutletInventory;
        solution._freeOutletInventory = _freeOutletInventory;
        solution._inventory = _inventory;
        solution._totalFreeInventory = _totalFreeInventory;
        solution._freeInventory = _freeInventory;
        solution._fitness = _fitness;
        solution._productionTotalProfit = _productionTotalProfit;
        solution._unmetDemandTotalCost = _unmetDemandTotalCost;
        solution._inventoryTotalCost = _inventoryTotalCost;
        solution._batchColorGroup = _batchColorGroup;

        return solution;
    };

    // set the values of current solution

    void EPPSolution::set(EPPSolution solution)
    {
        _problem = solution._problem;
        _balancing = solution._balancing;
        _allocation = solution._allocation;
        _processingTime = solution._processingTime;
        _batchWidth = solution._batchWidth;
        _batchIdleness = solution._batchIdleness;
        _extruderProcTime = solution._extruderProcTime ;
        _extruderIdleness = solution._extruderIdleness;
        _production = solution._production;
        _delivered = solution._delivered;
        _unmetDemand = solution._unmetDemand;
        _deliveredToOutlet = solution._deliveredToOutlet;
        _totalFreeOutletInventory = solution._totalFreeOutletInventory;
        _freeOutletInventory = solution._freeOutletInventory;
        _inventory = solution._inventory;
        _totalFreeInventory = solution._totalFreeInventory;
        _freeInventory = solution._freeInventory;
        _fitness = solution._fitness;
        _productionTotalProfit = solution._productionTotalProfit;
        _unmetDemandTotalCost = solution._unmetDemandTotalCost;
        _inventoryTotalCost = solution._inventoryTotalCost;
        _batchColorGroup = solution._batchColorGroup;
    };

    // modify the processing time of a randomly chosen batch, decreasing or increasing by one unit of time (minute).

    bool EPPSolution::swapTime()
    {
        cout << endl << "function: swaping time.  " << endl << endl;

        bool i_print = 0;

        unsigned int batch = rand()%_allocation.size();
        if(i_print == 1) cout << endl << "batch:  " << batch << endl;

        unsigned int extruder = _allocation[batch][0];
        if(i_print == 1) cout << endl << "extruder:  " << extruder << endl;

        unsigned int day = _allocation[batch][1];
        if(i_print == 1) cout << endl << "day:  " << day << endl;

        unsigned int prodLimit;

        int step;

        if(_extruderIdleness[extruder][day] < 1)
        {
            step = -1;
            if(_processingTime[batch] < 1)
            {
                if(i_print == 1) cout << endl << "error: time cannot be reduced !" << endl;
                if(i_print == 1) cout << endl << "production not changed." << endl;
                if(i_print == 1) getchar();
                return 1;
            }
        } else if(_processingTime[batch] < 1)
        {
            step = 1;
        } else
        {
            step = rand()%2;
            if(step == 0)
            {
                step = -1;
            }
        }
        if(i_print == 1) cout << endl << "step:  " << step << endl;

        unsigned int product;
        unsigned int productionVariation;

        for(unsigned int b=_allocation[batch][2]; b<=_allocation[batch][3]; b++)
        {
            product = _balancing[b][1];
            if(i_print == 1) cout << endl << "product: " << product << endl;

            productionVariation = _problem._productionPerTime[product][extruder];
            if(i_print == 1) cout << endl << "production variation: " << productionVariation << endl;

            prodLimit = productionLimit(product, day);

            if(step == 1)
            {
                if(productionVariation > prodLimit)
                {
                    if(i_print == 1) cout << endl << "error: can not increase production !" << endl;
                    if(i_print == 1) cout << endl << "production not changed." << endl;
                    if(i_print == 1) getchar();
                    return 1;
                }else
                {
                    increase(productionVariation, product, day);
                }
            }else
            {
                reduce(productionVariation, product, day);
            }
        }

         _processingTime[batch] += step;
        _extruderProcTime[extruder][day] += step;
        _extruderIdleness[extruder][day] -= step;

        return 0;
    };

    // reduce production and adjust linked variables

    void EPPSolution::reduce(unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: reducing <production> and adjusting linked variables..." << endl;

        bool i_print = 0;

        _production[product][day] -= production;
        _productionTotalProfit -= production*_problem._unitContribution[product];

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        deliver(product);

        cout << endl << "info: after reduction." << endl;

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);
    };

    // apply a simulated annealing method for improving solution

    void EPPSolution::particleCollision(unsigned int NMaxIte, unsigned int NMaxIteSA)
    {
        cout << endl << "function: particle collision." << endl;

        srand((unsigned) time(NULL));

        EPPSolution solution;
        EPPSolution bestSolution = autoCopy();

        float probality = 0, aux = 0;

        _problem.print();
        print();
        cout << endl << "problem and initial solution in PCA." << endl;
        getchar();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            solution = autoCopy();

            solution.swapProduct();
            solution.print();

            cout << endl << "best fitness: " << _fitness << "  solution fitness: " << solution._fitness << endl;
            getchar();

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    cout << endl << "info: found a better solution." << endl;
                    bestSolution.set(solution);
                    ite = 0;
                }

                cout << endl << "info: solution improved." << endl;

                set(solution);

                print();
                cout << endl << "info: solution improved by PCA." << endl;
                getchar();

                clean(2);
                print();
                cout << endl << "info: solution cleared." << endl;
                getchar();

                simultedAnnealing(1);

                print();
                cout << endl << "info: solution after SA." << endl;
                getchar();
            }else
            {
                probality = solution._fitness / bestSolution._fitness;
                cout << endl << "probality: " << probality << endl;
                aux = rand()%100000;
                aux = aux / 100000;
                cout << endl << "random: " << aux << endl;

                cout << endl << "info: solution not improved" << endl;
                if(aux <= probality)
                {
                    cout << " but acepted..." << endl;
                    set(solution);

                    print();
                    cout << endl << "info: solution accepted by PCA." << endl;
                    getchar();

                    clean(2);
                    print();
                    cout << endl << "info: solution cleared." << endl;
                    getchar();

                    simultedAnnealing(NMaxIteSA);

                    print();
                    cout << endl << "info: solution after SA." << endl;
                    getchar();

                    aux = rand()%10;
                    aux = aux / 10;
                    cout << endl << "random clear: " << aux << endl;

                    if(aux < 0.2)
                    {
                        clean(1);
                        print();
                        cout << endl << "info: empty processed time batches cleared." << endl;
                        getchar();
                    }
                }
            }

            cout << endl << "PC iteration: " << ite << endl;
            getchar();
        }

        set(bestSolution);
        print();
        cout << endl << "info: final PCA solution." << endl;
        getchar();

        solution.clear();
        bestSolution.clear();
    };

    // ramdomly changes a batch or create a new one
    /* this function randomly chooses a product and eigther: creates a new lot with this product or allocates this product in a lot of the same color chosen randomly.
    When a batch is chosen, if there is no space in the extruder for the product to be inserted in the set, other products are removed.
    Additionally, the production limit for the new product is checked and then, if the batch processing time is too high, the batch is divided into two batches.
    The first batch with the limit processing time and the second with the remaining batch time value, subtracted from the setup value. */

    void EPPSolution::swapProduct()
    {
        cout << endl << "function: adding a new product on batch. " << endl << endl;

        bool i_print = 1;

        unsigned int aux, batch;

        unsigned int product = rand()%_problem._NProducts; // randomly select a product
        if(i_print == 1) cout << endl << "product randonly selected:  " << product << endl;

        unsigned int color = _problem._color[product]; // identify the product color
        if(i_print == 1) cout << endl << "product color:  " << color << endl;

        if(_batchColorGroup[color].size() > 0) // if there are other batches of the same color
        {
            // randomly choose a batch of the same color or to create a new batch
            aux = rand()%(_batchColorGroup[color].size()+1);

            if(aux == _batchColorGroup[color].size()) // create another batch
            {
                if(i_print == 1) cout << endl << "info: creating a new batch." << endl;

                insert(product);
            }else // insert the new product in the chosen batch
            {
                batch = _batchColorGroup[color][aux];

                if(i_print == 1) cout << endl << "batch:  " << batch << endl;
                include(product, batch);
            }
        }else // if there are any batch of the same color, create a new one
        {
            if(i_print == 1) cout << endl << "info: there is no batch of this color." << endl;
            if(i_print == 1) cout << endl << "info: creating a new batch." << endl;

            insert(product);
        }
    };

    // create a new random batch with one <product>

    bool EPPSolution::insert(unsigned int product)
    {
        cout << endl << "function: randomly creating a new batch." << endl;

        bool i_print = 1;

        // randomly choose an extruder and a day
        unsigned int extruder = rand()%_problem._NExtruders;

        // there is a problem here if no extruder can process the product because of its width (an infinite loop will be generated)
        while(_problem._length[extruder] < _problem._width[product])
        {
            extruder = rand()%_problem._NExtruders;
        }

        unsigned int day = rand()%_problem._NDays;

        // calculating setup time and

        unsigned int color = 0;

        unsigned int time, production, prodLimit;


        if(_extruderIdleness[extruder][day] <= _problem._setupTime[color][color]) // if extruder idleness is not enough do not create a new batch
        {
            time = 0;
            production = 0;

            if(i_print == 1) cout << endl << "info: small extruder ideleness - cannot include another batch on this extruder and day." << endl;
            if(i_print == 1) cout << endl << "info: new batch won't be created." << endl;
            return 1;
        }else
        {
            // calculating maximum production allowed
            production = (_extruderIdleness[extruder][day]-_problem._setupTime[color][color])*_problem._productionPerTime[product][extruder];
            prodLimit = productionLimit(product,day);

            if(i_print == 1) cout << endl << "production: " << production << " production limit: " << prodLimit << endl;

            // creating a new batch
            if(production > prodLimit)
            {
                time = rint(floor(prodLimit / _problem._productionPerTime[product][extruder]));
            }else
            {
                time = _extruderIdleness[extruder][day];
            }

            if(i_print == 1) cout << endl << "time: " << time << endl;

            insert({product},extruder,day,time);
        }
        return 0;
    };

    // include product on batch and adjust linked variables

    bool EPPSolution::include(unsigned int product, unsigned int batch)
    {
        cout << endl << "function: including product on batch..." << endl;

        bool i_print = 0;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        if(i_print == 1) cout << endl << "extruder: " << extruder << "  day: " << day  << endl;

        if(_problem._length[extruder] < _problem._width[product])
        {
            if(i_print == 1) cout << endl << "error: product cannot be allocated on this extruder !" << endl;
            if(i_print == 1) getchar();
            return 1;
        }else
        {
            unsigned int time, diff;
            unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];
            unsigned int prodLimit = productionLimit(product,day);

            if(i_print == 1) cout << endl << "production: " << production << "  limit: " << prodLimit << endl;

            if(production > prodLimit)
            {
                production = prodLimit;
                time = rint(floor(production / _problem._productionPerTime[product][extruder]));
                diff = _processingTime[batch] - time;

                if(i_print == 1) cout << endl << "production: " << production << "  time: " << time << "  diff: " << diff << endl;

                if(split(batch, time) == 1) processingTime(batch, time);
            }

            while(_batchIdleness[batch] < _problem._width[product])
            {
                if(i_print == 1) cout << endl << "idleness: "<< _batchIdleness[batch] << "  width: " << _problem._width[product] << endl;
                randomErase(batch);
            }

            return insert(product, batch);
        }
    };

    // split a batch into two batches

    bool EPPSolution::split(unsigned int batch, unsigned int time)
    {
        cout << endl << "function: spliting batch... " << endl;

        bool i_print = 0;

        if(i_print == 1) cout << endl << "info: calculating setup time." << endl;

        vector<unsigned int> pList;
        pList.clear();
        pList = productList(batch);

        if(i_print == 1) cout << endl << "pList: ";

        if(i_print == 1) for(unsigned int s=0; s<pList.size(); s++)
        {
            cout << pList[s] << "  ";
        }

        cout << endl;

        unsigned int product, color, prevColor;

        color = _allocation[batch][4];

        if(i_print == 1) cout << endl << "color: " << color << endl;

        if(_balancing.size() >= 1)
        {
            product = _balancing.back()[1];
            if(i_print == 1) cout << endl << "last product: " << product << endl;

            prevColor = _problem._color[product];
        }else
        {
            prevColor = color;
        }

        if(i_print == 1) cout << endl << "previous color: " << prevColor << endl;

        if(_processingTime[batch] <= time + _problem._setupTime[prevColor][color])
        {
            if(i_print == 1) cout << endl << "error: batch processing time cannot be splitted !" << endl;
            if(i_print == 1) cout << endl << "info: batch will not be splited." << endl;
            if(i_print == 1) getchar();
            return 1;
        }

        unsigned int timeNewBatch = _processingTime[batch] - time - _problem._setupTime[prevColor][color];

        if(i_print == 1) cout << endl << "info: reducing processing time of batch to: " << time << endl;
        processingTime(batch, time);

        // generating another batch

        if(i_print == 1) cout << endl << "info: generating another batch." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        if(i_print == 1) cout << endl << "extruder: " << extruder << "  day: " << day << endl;

        if(i_print == 1) cout << endl << "creating a new batch with the remaining time: " << timeNewBatch << endl;

        insert(pList, extruder, day, timeNewBatch);

        //print();

        return 0;
    };

    // create a list with batch products

    vector<unsigned int> EPPSolution::productList(unsigned int batch)
    {
        cout << endl << "function: creating a list of products." << endl;

        bool i_print = 0;

        unsigned int product;
        vector<unsigned int> productList;
        productList.clear();

        unsigned int start = _allocation[batch][2];
        unsigned int finish = _allocation[batch][3];

        if(i_print == 1) cout << endl << "start: " << start << "  finish: " << finish << endl;

        if( start >= _balancing.size() || _balancing[start][0] != batch)
        {
            if(i_print == 1) cout << endl << "this batch is empty !" << endl;
        }else
        {
            for(unsigned int s=start; s<=finish; s++)
            {
                product = _balancing[s][1];
                productList.push_back(product);
            }
        }

        if(i_print == 1) cout << endl << "product list: ";
        if(i_print == 1) for(unsigned int s=0; s<productList.size();s++)
        {
            cout << productList[s] << "\t";
        }

        return productList;
    };

    //changing processing time of <batch> to <time>

    void EPPSolution::processingTime(unsigned int batch, unsigned int time)
    {
        cout << endl << "function: changing batch processing time and linked variables." << endl;

        bool i_print = 0;

        if(time == _processingTime[batch])
        {
            if(i_print == 1) cout << endl << "info: no change in bach time." << endl;
        }else
        {
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(_allocation[batch].size()<=3)
            {
                if(i_print == 1) cout << endl << "info: bach is empty." << endl;
            }else
            {
                unsigned int product, production, prodLimit;

                for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                {
                    product = _balancing[s][1];

                    if(i_print == 1) cout << endl << "product: " << product << endl;

                    if(time < _processingTime[batch])
                    {
                        production = (_processingTime[batch]-time)*_problem._productionPerTime[product][extruder];

                        if(i_print == 1) cout << endl << "production reduction: " << production << endl;
                        reduce(production, product, day);
                    }else
                    {
                        production = (time-_processingTime[batch])*_problem._productionPerTime[product][extruder];

                        prodLimit = productionLimit(product,day);
                        if(production > prodLimit)
                        {
                            time = rint(floor(prodLimit / _problem._productionPerTime[product][extruder]));
                            production = time*_problem._productionPerTime[product][extruder];
                        }

                        if(i_print == 1) cout << endl << "production encrease: " << production << endl;
                        increase(production, product, day);
                    }
                }
            }

            if(i_print == 1) cout << endl << "time: " << time << "  extruder: " << extruder << "  day: " << day << endl;

            _extruderProcTime[extruder][day] -= _processingTime[batch] - time;
            _extruderIdleness[extruder][day] += _processingTime[batch] - time;
            _processingTime[batch] = time;

            if(i_print == 1) cout << endl << "time: " << time << " extruder time: " << _extruderProcTime[extruder][day] << " and idleness: "
                << _extruderIdleness[extruder][day] << "." << endl;
        }
    };

    // random erease a product on <batch>

    void EPPSolution::randomErase(unsigned int batch)
    {
        cout << endl << "function: random exclusion... " << endl;

        bool i_print = 0;

        if(_allocation[batch].size() <= 3)
        {
            if(i_print == 1) cout << endl << "info: no product on this batch. " << endl;
        }else
        {
            // choosing a product in the batch

            unsigned int start = _allocation[batch][2];
            unsigned int finish = _allocation[batch][3];

            cout << endl << "start: " << start << "  end: " << finish << endl;

            unsigned int location;

            if(start == finish)
            {
                if(i_print == 1) cout << endl << "info: only one product on this batch. " << endl;
                location = start;
            }else
            {
                if(i_print == 1) cout << endl << "number of products on this batch: " << finish - start + 1 << endl;
                location = start + rand()%(finish - start + 1);
            }

            erase(location);
        }
    };

    void EPPSolution::erase(unsigned int location)
    {
        cout << endl << "function: erasing product on batch. " << endl;

        bool i_print = 0;

        unsigned int batch = _balancing[location][0];

        if(i_print == 1) cout << endl << "location: "<< location << "   batch: " << batch << endl;

        if(location >= _balancing.size())
        {
            if(i_print == 1) cout << endl << "error: _ballancing[" << batch << "] do not have element " << location << " !" << endl;
        }else
        {
            if(_allocation[batch][2] < _allocation[batch][3])
            {
                _allocation[batch][3] -= 1;
                if(i_print == 1) cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
            }

            if(i_print == 1) cout << endl << "info: reorganizing other batches first and last indexes." << endl;

            for(unsigned int b=batch+1; b<_allocation.size(); b++)
            {
                if(i_print == 1) cout << endl << "batch: " << b;
                _allocation[b][2] -= 1;
                if(i_print == 1) cout << "  new first batch index: " << _allocation[b][2];

                _allocation[b][3] -= 1;
                if(i_print == 1) cout << "  new last batch index: " << _allocation[b][3] << endl;
            }

            unsigned int product = _balancing[location][1];

            if(i_print == 1) cout << endl << "product being excluded: " << product << endl;

            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(i_print == 1) cout << endl << "batch extruder: " << extruder << "   batch day: " << day << endl;

            // adjusting _balancing

            _balancing.erase(_balancing.begin()+location);

            _batchWidth[batch] -= _problem._width[product];

            if(i_print == 1) cout << endl << "batch width reduced to: " << _batchWidth[batch] << endl;

            _batchIdleness[batch] += _problem._width[product];

            if(i_print == 1) cout << endl << "batch idleness augmented to: " << _batchIdleness[batch] << endl;

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];

                if(i_print == 1) cout << endl << "production being reduced: " << production << "." << endl;

                if(production > 0)
                {
                    reduce(production, product, day);
                }
            }
        }
    };

    bool EPPSolution::insert(unsigned int product, unsigned int batch)
    {
        cout << endl << "function: inserting a new product on batch... " << endl;

        print(2);

        if(batch >= _allocation.size())
        {
            cout << endl << "error: batch do not exist !" << endl;
            cout << endl << "info: product will not be included." << endl;
            getchar();
            return 1;
        }

        cout << endl << "batch: " << batch << "  idleness: " << _batchIdleness[batch] << "  product: " << product << "  width: " << _problem._width[product] << "." << endl;

        if(_batchIdleness[batch] < _problem._width[product])
        {
            cout << endl << "error: batch idleness must be greater than product width !" << endl;
            cout << endl << "info: product will not be included." << endl;
            getchar();
            return 1;
        }

        unsigned int location = _allocation[batch][3];

        cout << endl << "location: " << location << endl;

        if(_balancing[location][0] > batch)
        {
            cout << endl << "location: " << location << endl;
            cout << "new last batch index: " << _allocation[batch][3] << endl;
        }else
        {
            cout << endl << "info: adjusting location index." << endl;

            location = _allocation[batch][3]+1;
            for(unsigned int l=_allocation[batch][3]; l>=_allocation[batch][2]; l--)
            {
                cout << endl << "product on location: " << _balancing[l][1] << endl;

                if(_balancing[l][1] > product)
                {
                    location = l;
                    cout << endl << "location: " << location << endl;
                }else
                {
                    break;
                }
            }

            cout << endl << "choosed location: " << location << endl;

            _allocation[batch][3] += 1;

            cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
        }

        cout << endl << "location: " << location << endl;

        cout << endl << "info: reorganizing balancing location indexes. " << endl;

        for(unsigned int b=batch+1; b<_allocation.size(); b++)
        {
            cout << endl << "batch: " << b << "\t";
            _allocation[b][2] += 1;
            cout << "new first batch index: " << _allocation[b][2];

            _allocation[b][3] += 1;
            cout << "  new last batch index: " << _allocation[b][3] << endl;
        }

        cout << endl << "info: inserting new product on batch." << endl;

        _balancing.insert(_balancing.begin()+location,{batch,product});

        _batchWidth[batch] += _problem._width[product];

        cout << endl << "batch width augmented to: " << _batchWidth[batch] << "." << endl;

        _batchIdleness[batch] -= _problem._width[product];

        cout << endl << "batch idleness reduced to: " << _batchIdleness[batch] << "." << endl;

        if(_processingTime[batch] > 0)
        {
            // adjusting production

            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];

            cout << endl << "production being encreased: " << production << "." << endl;

            if(production > 0)
            {
                increase(production, product, day);
            }
        }

        return 0;
    };

    //

    bool EPPSolution::clean(unsigned int cleanType)
    {
        cout << endl << "function: cleaning." << endl;

        bool i_print = 1;

        unsigned int color,prevColor,setup,location,extruder,day,aux;

        if(cleanType == 1) // batches with empty processing time
        {
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                if(_processingTime[b] == 0)
                {
                    // clearing processing time and linked variables

                    extruder = _allocation[b][0];
                    day = _allocation[b][1];
                    color = _allocation[b][4];

                    if(_allocation[b][2] > 0)
                    {
                        location = _allocation[b][2]-1;
                        prevColor = _problem._color[_balancing[location][1]];
                    }else
                    {
                        prevColor = color;
                    }

                    setup = _problem._setupTime[prevColor][color];

                    _extruderProcTime[extruder][day] -= setup;
                    _extruderIdleness[extruder][day] += setup;

                    // claring batch and linked variables

                    for(unsigned int i=_allocation[b][3]+1; i<_balancing.size(); i++)
                    {
                        _balancing[i][0] -= 1;
                    }

                    if(i_print == 1) cout << endl << "balancing: " << endl;
                    if(i_print == 1) for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    if(i_print == 1) cout << endl;

                    for(unsigned int p=_allocation[b][3]; p>=_allocation[b][2]; p--)
                    {
                        if(i_print == 1) cout << endl << p << endl;

                        if(p == 0)
                        {
                            if(i_print == 1) cout << endl << "p = 0" << endl;
                            _balancing.erase(_balancing.begin());
                        }else
                        {
                            _balancing.erase(_balancing.begin()+p);
                        }
                    }

                    if(i_print == 1) cout << endl;
                    if(i_print == 1) for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << i << endl;
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    if(i_print == 1) cout << endl;

                    aux = _allocation[b][3] - _allocation[b][2] + 1;

                    for(unsigned int i=b+1; i<_allocation.size(); i++)
                    {
                        if(i_print == 1) cout << endl << i << "first: " << _allocation[i][2] << "  last: " << _allocation[i][3] << endl;
                        _allocation[i][2] -= aux;
                        _allocation[i][3] -= aux;
                        if(i_print == 1) cout << endl << i << "new first: " << _allocation[i][2] << "  new last: " << _allocation[i][3] << endl;
                    }

                    location = find(_batchColorGroup[color],b);

                    if(location >= _batchColorGroup[color].size())
                    {
                        if(i_print == 1) cout << endl << "error: location of " << b << " not found." << endl;
                        if(i_print == 1) cout << endl << "info: there is an error in code, please verify." << endl;
                        if(i_print == 1) getchar();
                        return 1;
                    }else
                    {
                        _batchColorGroup[color].erase(_batchColorGroup[color].begin()+location);
                    }

                    for(unsigned int i=0; i<_batchColorGroup[color].size(); i++)
                    {
                        if(_batchColorGroup[color][i] > b)
                        {
                            _batchColorGroup[color][i] -= 1;
                        }
                    }

                    _allocation.erase(_allocation.begin()+b);
                    _batchWidth.erase(_batchWidth.begin()+b);
                    _batchIdleness.erase(_batchIdleness.begin()+b);
                    _processingTime.erase(_processingTime.begin()+b);

                    b--;
                }
            }
        }else if(cleanType == 2) // empty batches
        {
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                if(_batchWidth[b] == 0)
                {
                    color = _allocation[b][4];
                    location = find(_batchColorGroup[color],b);

                    if(location >= _batchColorGroup[color].size())
                    {
                        cout << endl << "error: location of " << b << " not found." << endl;
                        cout << endl << "info: there is an error in code, please verify." << endl;
                        getchar();
                        return 1;
                    }else
                    {
                        _batchColorGroup[color].erase(_batchColorGroup[color].begin()+location);
                    }

                    for(unsigned int i=0; i<_batchColorGroup[color].size(); i++)
                    {
                        if(_batchColorGroup[color][i] > b)
                        {
                            _batchColorGroup[color][i] -= 1;
                        }
                    }

                    extruder = _allocation[b][0];
                    day = _allocation[b][1];
                    color = _allocation[b][4];

                    if(_allocation[b][2] > 0)
                    {
                        location = _allocation[b][2]-1;
                        prevColor = _problem._color[_balancing[location][1]];
                    }else
                    {
                        prevColor = color;
                    }

                    setup = _problem._setupTime[prevColor][color];

                    _extruderProcTime[extruder][day] -= _processingTime[b] + setup;
                    _extruderIdleness[extruder][day] += _processingTime[b] + setup;

                    _processingTime.erase(_processingTime.begin()+b);

                    _allocation.erase(_allocation.begin()+b);
                    _batchWidth.erase(_batchWidth.begin()+b);
                    _batchIdleness.erase(_batchIdleness.begin()+b);
                }
            }
        }else
        {
            cout << endl << "error: type not know !" << endl;

            cout << endl << "types: " << endl;

            cout << endl << "2: clear empty batches." << endl;
        }

        return 0;
    };

    unsigned int EPPSolution::find(vector<unsigned int> UIVector, unsigned int value)
    {
        unsigned int position = UIVector.size();

        for(unsigned int i=0; i<UIVector.size(); i++)
        {
            if(UIVector[i] == value)
            {
                position = i;
            }
        }

        return position;
    };
}

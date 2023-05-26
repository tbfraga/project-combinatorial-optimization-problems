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
// last modification: 2023/05/24

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


    bool extruderPlanningProblem::print(ofstream &file)
    {
        bool error = 0; // false

        file << endl << "EXTRUDER PLANNING PROBLEM" << endl;

        file << endl << "Days: " << _NDays << endl;

        file << endl << "Extruders: "  << _NExtruders << endl;

        file << endl << "setup cost: " << _setupCost << "  -  operation cost: " << _operationCost << endl;

        file << endl << "[extruder]  production rate (m/min) / length (m)" << endl;

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            file << endl << e << "\t" << _productionRate[e] << "\t" << _length[e];
        }

        file << endl << endl << "[extruder, day]  capacity(min)" << endl << endl;

        for(unsigned int d=0; d<_NDays; d++)
        {
            file << "\t" << d;
        }

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            file << endl << e;

            for(unsigned int d=0; d<_NDays; d++)
            {
                file << "\t" << _capacity[e][d];
            }
        }

        file << endl << endl << "Products: " << _NProducts << endl;

        file << endl << "[product]  width (m) / weight ratio (g/m²) / unit contribution ($/g) / initial inventory (g) / maximum inventory (g) / color" << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file << endl << p << "\t" << _width[p] << "\t" << _weightRatio[p] << "\t" << _unitContribution[p] << "\t" << _initialInventory[p] << "\t" << _maximumInventory[p]
            << "\t" << _color[p];
        } // how format output ??? see later

        file << endl << endl << "Factory: " << endl;

        file << endl << "maximum inventory (g): " << _totalMaximumInventory << "  -  inventory unit cost ($/g): " << _inventoryUnitCost << endl;

        file << endl << "[product, day]  demand (g)" << endl << endl;

        for(unsigned int d=0; d<_NDays; d++)
        {
            file << "\t" << d;
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file << endl << p;

            for(unsigned int d=0; d<_NDays; d++)
            {
                file << "\t" << _demand[p][d];
            }
        }

        file << endl << endl << "Factory: " << endl;

        file << endl << "unmet demand cost ($/g): " << _unmetDemandCost << endl;

        file << endl << "[product, product]  relation of products of same color and material" << endl << endl;

        for(unsigned p=0; p<_NProducts; p++)
        {
            file << "\t" << p;
        }
        file << endl;

        for(unsigned p=0; p<_NProducts; p++)
        {
            file << p;

            for(unsigned k=0; k<_NProducts; k++)
            {
                file << "\t" << _colorAndMaterialRatio[p][k];
            }
            file << endl;
        }

        file << endl << "Colors: " << _NColors << endl;

        file << endl << "[color]  color group" << endl << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            file << c;
            for(unsigned int s=0; s<_productColorGroup[c].size(); s++)
            {
                file << "\t" << _productColorGroup[c][s];
            }
            file << endl;
        }

        file << endl << "[color, color]  setup time (min)" << endl << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            file << "\t" << c;
        }
        file << endl;

        for(unsigned int c=0; c<_NColors; c++)
        {
            file << c;
            for(unsigned int k=0; k<_NColors; k++)
            {
                file << "\t" << _setupTime[c][k];
            }
            file << endl;
        }

        file << endl << "[product, extruder]  production rate (g/min)" << endl << endl;


        for(unsigned int e=0; e<_NExtruders; e++)
        {
            file << "\t" << e;
        }
        file << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file << p;
            for(unsigned int e=0; e<_NExtruders; e++)
            {
                file << "\t" << _productionPerTime[p][e];
            }
            file << endl;
        }

        file << endl << "Outlets: " << _NOutlets << endl;

        file << endl << "[outlet]  maximum outlet inventory (g)" << endl << endl;

        for(unsigned int o=0; o<_NOutlets; o++)
        {
            file << o << "\t" << _totalMaximumOutletInventory[o] << endl;
        }

        file << endl << "[product, outlet]  maximum inventory (g)" << endl << endl;

        for(unsigned int o=0; o<_NOutlets; o++)
        {
            file << "\t" << o;
        }
        file << endl;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            file << p;
            for(unsigned int o=0; o<_NOutlets; o++)
            {
                file << "\t" << _maximumOutletInventory[p][o];
            }
            file << endl;
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
        if(_hprint == 1) cout << endl << "head: printing solution on screan..." << endl;
        bool error = 0;
        unsigned int batch;

        if(type == 0) // fitness
        {
            cout << endl << endl << "SOLUTION" << endl;

            cout << endl << "fitness: " << _fitness << endl;
            cout << endl << "production total profit: " << _productionTotalProfit << endl;
            cout << endl << "unmet demand total cost: " << _unmetDemandTotalCost  << endl;
            cout << endl << "inventory total cost: " << _inventoryTotalCost<< endl;

        }else if(type == 1) // _balancing
        {
            cout << endl << "[batch, product] - balancing" << endl;

            for(unsigned int b=0; b<_balancing.size(); b++)
            {
                if(b==0)
                {
                    batch = _balancing[b][0];
                    cout << endl << batch;
                }else if(_balancing[b][0] != _balancing[b-1][0]) // if not the same batch
                {
                    batch = _balancing[b][0];
                    cout << endl << batch;
                }

                cout << "\t" << _balancing[b][1];
            }

            cout << endl << endl << "processing time (min) / width (m) / idleness (m) / color" << endl << endl;

            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                cout << endl << b;
                cout << "\t" << _processingTime[b];
                cout << "\t" << _batchWidth[b];
                cout << "\t" << _batchIdleness[b];
                cout << "\t" << _batchColor[b];
            }

            cout << endl;

        }else if(type == 2)
        {
            cout << endl << "allocation [batch, extruder, day, index for _balancing - first product, index for _balancing - last product]: ";
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
        }

        if(error == 1) getchar();
        return error;
    };

    // print complete solution on <file>

    bool EPPSolution::print(ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: starting printing..." << endl;

        bool error = 0;

        error = print(0, file);
        error = print(1, file);
        error = print(2, file);
        error = print(3, file);
        error = print(4, file);
        error = print(5, file);
        error = print(6, file);

        return error;
    };

    // print on file as defined by <type>
    bool EPPSolution::print(unsigned int type, ofstream &file)
    {
        bool error = 0;
        unsigned int batch;

        if(type == 0) // fitness
        {
            file << endl << endl << "SOLUTION" << endl;

            file << endl << "fitness: " << _fitness << endl;
            file << endl << "production total profit: " << _productionTotalProfit;
            file << endl << "unmet demand total cost: " << _unmetDemandTotalCost;
            file << endl << "inventory total cost: " << _inventoryTotalCost;

            if(_fitness != (_productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost))
            {
                 error = 1;
                 file << endl << "error print: costs not correctly calculated !";
            }

        }else if(type == 1) // _balancing
        {
            file << endl << endl << "[batch, product] - balancing" << endl;

            for(unsigned int b=0; b<_balancing.size(); b++)
            {
                if(b==0)
                {
                    batch = _balancing[b][0];
                    file << endl << batch;
                }else if(_balancing[b][0] != _balancing[b-1][0]) // if not the same batch
                {
                    batch = _balancing[b][0];
                    file << endl << batch;
                }

                file << "\t" << _balancing[b][1];
            }

            file << endl << endl << "processing time (min) / width (m) / idleness (m) / color" << endl;

            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                file << endl << b;
                file << "\t" << _processingTime[b];
                file << "\t" << _batchWidth[b];
                file << "\t" << _batchIdleness[b];
                file << "\t" << _batchColor[b];
            }

            file << endl;

        }else if(type == 2)
        {
            file << endl << "allocation [batch, extruder, day, index for _balancing - first product, index for _balancing - last product]: " << endl << endl;
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                file << b << "\t";
                for(unsigned int i=0; i<_allocation[b].size(); i++)
                {
                    file << _allocation[b][i] << "\t";
                }
                file << endl;
            }

            file << endl << "batch color group [batch vector]: " << endl << endl;

            for(unsigned int c=0; c<_batchColorGroup.size(); c++)
            {
                for(unsigned int s=0; s<_batchColorGroup[c].size(); s++)
                {
                    file << _batchColorGroup[c][s] << "\t";
                }
                file << endl;
            }

        }else if(type == 3)
        {
            file << endl << "[extruder, day] -  processing time (min)  /  idleness (min)" << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                file << "\t" << d;
            }
            file << "\t";
            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << endl;

            for(unsigned int e=0; e<_extruderProcTime.size(); e++)
            {
                file << endl << e;
                for(unsigned int d=0; d<_extruderProcTime[e].size(); d++)
                {
                    file << "\t" << _extruderProcTime[e][d];
                }

                file << "\t";
                for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
                {
                    file << "\t" << _extruderIdleness[e][d];
                }
                file << endl;
            }

        }else if(type == 4)
        {
            file << endl << "[product, day] - production / demand (g):" << endl;
            file << endl << "\t" << "production" << "\t\t" << "delivered" << "\t\t" << "unmet" << "\t\t\t" << "demand";
            file << endl << endl;

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << endl << endl;

            unsigned int sum;
            for(unsigned int p=0; p<_production.size(); p++)
            {
                file << p;
                for(unsigned int d=0; d<_production[p].size(); d++)
                {
                    file << "\t" << _production[p][d];
                }

                file << "\t";

                for(unsigned int d=0; d<_delivered[p].size(); d++)
                {
                    file << "\t" << _delivered[p][d];
                }

                file << "\t";

                for(unsigned int d=0; d<_unmetDemand[p].size(); d++)
                {
                    file << "\t" << _unmetDemand[p][d];
                }

                file << "\t";

                for(unsigned int d=0; d<_problem._demand[p].size(); d++)
                {
                    file << "\t" << _problem._demand[p][d];
                }

                file << endl;

                if(_unmetDemand[p][0] != (_problem._demand[p][0] - _delivered[p][0])) error = 1;
                if(_unmetDemand[p][0] > _problem._demand[p][0]) error = 1;

                sum = _problem._demand[p][0];
                for(unsigned int d=1; d<_problem._demand[p].size(); d++)
                {
                    if(_unmetDemand[p][d] != (_unmetDemand[p][d-1] + _problem._demand[p][d] - _delivered[p][d])) error = 1;

                    sum += _problem._demand[p][d];
                    if(_unmetDemand[p][d] > sum) error = 1;
                }
            }

            if(error == 1) file << endl << "error: demand variables not correctly calculated !" << endl;

        }else if (type == 5)
        {
            file << endl << "delivered to outlet (g) [product, outlet, day]" << endl << endl;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                file << "\t" << "outlet: " << o;

                for(unsigned int d=2; d<_problem._NDays; d++)
                {
                    file << "\t";
                }
            }

            file << "\t" << "free";

            file << endl << endl;

            for (unsigned int d=0; d<=_problem._NDays; d++)
            {
                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    file << "\t" << o;
                }
            }

            file << endl << endl;

            for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
            {
                file << p;
                for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
                {
                    for(unsigned int d=0; d<_deliveredToOutlet[p][o].size(); d++)
                    {
                        file << "\t" << _deliveredToOutlet[p][o][d];
                    }
                }

                for(unsigned int o=0; o<_freeOutletInventory[p].size(); o++)
                {
                    file << "\t" << _freeOutletInventory[p][o];
                }

                file << endl;
            }

            file << endl;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                for(unsigned int d=0; d<_problem._NDays; d++)
                {
                    file << "\t";
                }
            }

            file << "total:";

            for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
            {
                file << "\t"<< _totalFreeOutletInventory[o];
                if(_totalFreeOutletInventory[o] > _problem._totalMaximumOutletInventory[o]) error = 1;
            }
            file << endl;

            if(error == 1) file << "error: outlet inventory variables not correctly calculated." << endl;

        }else if(type == 6)  // inventory
        {
            file << endl << "inventory (g) [product, day]" << endl << endl;
            file << "\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "maximum";
            file << endl << endl;

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << "\t";

            for(unsigned int d=0; d< _problem._NDays; d++)
            {
                file << "\t" << d;
            }

            file << endl << endl;

            for(unsigned int p=0; p<_inventory.size(); p++)
            {
                file << p;
                for(unsigned int d=0; d<_inventory[p].size(); d++)
                {
                    file << "\t" << _inventory[p][d];
                }

                file << "\t";

                for(unsigned int d=0; d<_freeInventory[p].size(); d++)
                {
                    file << "\t"<< _freeInventory[p][d];
                    if(_freeInventory[p][d] > _problem._maximumInventory[p]) error = 1;
                }

                file << "\t";

                file << "\t"<< _problem._maximumInventory[p];

                file << endl;
            }

            file << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                file << "\t";
            }

            file << "\t" << "total:";
            for(unsigned int d=0; d< _totalFreeInventory.size(); d++)
            {
                file << "\t" << _totalFreeInventory[d] ;
                if(_totalFreeInventory[d] > _problem._totalMaximumInventory) error = 1;
            }
            file << "\t" << "total:" << "\t" << _problem._totalMaximumInventory;

            file << endl;

            if(error == 1) file << endl << "error: inventory variables not correctly calculated." << endl;

        }else
        {
            file << endl << "info: please, choose a type betwing 0 and 6." << endl;
        }

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

    void EPPSolution::generate(ofstream &file)
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
                insert({p}, extruder, day, time, file);
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
        bool i_print = 0;

        if(i_print == 1) cout << endl << "function: production limit calculation." << endl;

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

        for(unsigned int d=day+1; d<_problem._NDays; d++)
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

        if(i_print == 1)cout << endl << "Limit inventory + unmet demand + outlet: " << prodLimit << endl; // seens to be ok

        return prodLimit;
    };

    // create a new batch and adjust linked variables

    bool EPPSolution::insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time, ofstream &file)
    {
        bool i_print = 0;

        if(i_print == 1) cout << endl << "function: creating a new batch.";

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

        if(i_print == 1) cout << endl << "extruder: " << extruder << "  day: " << day << endl;
        if(i_print == 1) cout << endl << "idleness: " << _extruderIdleness[extruder][day] << "  time: " << time << "  setup: " << _problem._setupTime[prevColor][color] << endl;

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

        if(i_print == 1) cout << endl << "color: " << color << endl;

        _batchColorGroup[color].push_back(batch);

        _batchWidth.push_back(width);
        _batchIdleness.push_back(_problem._length[extruder] - width);
        _batchColor.push_back(color);

        // adjusting _allocation

        newVector.clear();

        newVector = {extruder,day,positionFirst,positionLast};
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

                i_print = increase(production, product, day, file);
            }
        }

        newVector.clear();
        return i_print;
    };

    // increase production and adjust linked variables

    bool EPPSolution::increase(unsigned int production, unsigned int product, unsigned int day, ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1) cout << endl << "head: increasing <production> and adjusting linked variables..." << endl;

        if(_fprint == 1) file << endl << "function: increasing production." << endl;

        //cout << endl << "product: " << product << " production: " << _production[product][day] << endl;

        _production[product][day] += production;
        _productionTotalProfit += production*_problem._unitContribution[product];

        // verification here can result in a false bug since this function increase production of only one product per time

        //cout << endl << "new production: " << _production[product][day] << endl;

        i_print = deliver(product, file);

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info increase: BUG after increasing production (print)" << endl;
                file << endl << "BUG HERE - after increasing production (print)" << endl;
                getchar();
            }
            file << endl << "info: solution after increasing production." << endl;
        }

        // verification here can result in a false bug since this function increase production of only one product per time

        if(i_print == 1) cout << endl << "error after increase function !" << endl;

        return i_print;
    };

    // distribute production between demand, outlets and inventory

    // now I have a problem in deliver function - I have alread solved this bug but I deleted modifications since I had problems with solving bugs
    bool EPPSolution::deliver(unsigned int product, ofstream &file)
    {
        // any verification here can result in a false bug since this function is used by other ones

        bool i_print = 0;

        if(i_print == 1) cout << endl << "function: delivering production" << endl;
        if(_hprint == 1) cout << endl << "head: delivering production..." << endl;
        if(_fprint == 1) file << endl << "function: delivering production" << endl;

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info deliver: BUG HERE - start delivering (print)" << endl;
                file << endl << "BUG HERE" << endl;
            }
            file << endl << "info deliver: solution before start delivering." << endl;
        }

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

        if(i_print == 1) cout << endl << "info: deliver cleared." << endl;

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info deliver: BUG HERE - after clearing distribution (print)" << endl;
                file << endl << "BUG HERE" << endl;
            }
            file << endl << "info deliver: solution after clearing distribution." << endl;
        }

        // distributing again

        unsigned int delivered;
        vector<unsigned int> distribution;

        distribution.clear();
        distribution.resize(_problem._NDays,0);

        // calculating daily distribution

        if(_problem._NDays >= 1) distribution[0] += _problem._initialInventory[product];

        if(_i_print == 3) cout << endl << "distribution: ";
        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            distribution[d] += _production[product][d]; // acumulated production of <product> on day d
            if(_i_print == 3) cout << "\t" << distribution[d];
        }
        if(_i_print == 3) cout << endl;

        cout << endl << "delivering to demand" << endl;

        // distributing to demand

        unsigned int day;

        unsigned unmet = 0; // variable used to store the aggregated value of the unmet demand, counting from the last date to the date under analysis.

        // backward distribution

        /* it is needed to do the backward distribution first so that the distribution values are updated correctly
           and the products are shipped to the outlets on the correct dates.*/

        if(_i_print == 3) cout << endl << "backward distribution" << endl;

        for(unsigned int d=_problem._NDays; d>0; d--)
        {
            day = d-1;

            if(i_print == 1) cout << endl << "day: " << day << endl;

            unmet +=  _problem._demand[product][day]; // acumulated unmet demand in decreasing order

            if(i_print == 1) cout << endl << "distribution (demand): " << distribution[day] << "  unmet: " << unmet << endl;

            if(distribution[day] > 0 && unmet > 0) forwardDelivery(product, day, distribution[day], unmet);

            if(i_print == 1) cout << endl << "after forward delivery function distribution: " << distribution[day] << "  unmet: " << unmet << endl;
        }

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG HERE - after backward distribution" << endl;
                file << endl << "BUG HERE" << endl;
            }
            file << endl << "info deliver: solution after backward distribution." << endl;
        }

        // forward distribution

        if(i_print == 1) cout << endl << " forward distribution" << endl; // it is necessary cause backward distribution does not see previus demand

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(i_print == 1) cout << endl << "day: " << d << endl;

            if(i_print == 1) cout << endl << "distribution (demand): " << distribution[d] << endl;

            forwardDelivery(product, d, distribution[d]);
        }

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG HERE - after forward distribution" << endl;
                file << endl << "BUG HERE" << endl;
            }
            file << endl << "info deliver: solution after forward distribution." << endl;
        }

        cout << endl << "delivering to outlet and inventory" << endl;

        // updating inventory

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        cout << endl << "here 01";

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(i_print == 1) cout << endl << "day: " << d << "  distribution (outlet): " << distribution[d] << endl;
            if(distribution[d] > 0)
            {
                // distributing to outlets

                 cout << endl << "here 02";

                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    if(_i_print == 3) cout << endl << "outlet: " << o << " free: " << _freeOutletInventory[product][o] << " total free: " << _totalFreeOutletInventory[o] << endl;

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

                    if(_i_print == 3) cout << endl << "delivered to outlet " << o << ": " << delivered << endl;

                    _deliveredToOutlet[product][o][d] += delivered;
                    _freeOutletInventory[product][o] -= delivered;
                    _totalFreeOutletInventory[o] -= delivered;

                    distribution[d] -= delivered;

                    if(distribution[d] == 0) break;
                }

                 cout << endl << "here 03";

                // distributing to inventory

                if(_i_print == 3) cout << endl << "day: " << d << "  distribution (inventory): " << distribution[d] << endl;

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
                            print(5);
                            print(6);

                            cout << endl << "error in deliver function: inventory of product " << product << " exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }

                        if(_totalFreeInventory[l] > _problem._totalMaximumInventory)
                        {
                            print(4);
                            print(5);
                            print(6);

                            cout << endl << "error in deliver function: free inventory exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }

                        if(_freeInventory[product][l] > _problem._maximumInventory[product])
                        {
                            print(4);
                            print(5);
                            print(6);

                            cout << endl << "error in deliver function: free inventory of product " << product << " exceeds the maximum !" << endl;
                            getchar();
                            return 1;
                        }
                    }

                    cout << endl << "here 04";
                }

                cout << endl << "here 05";
            }
        }

        cout << endl << "here 06";

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

        distribution.clear();

        /*if(_fprint == 1)
        {
            if(print(file) == 1) file << endl << "BUG HERE" << endl;
            file << endl << "info deliver: solution after delivering." << endl;
        }*/

        return 0;
    };

    void EPPSolution::forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution)
    {
        if(_hprint == 1) cout << endl << "head: forward delivering production..." << endl;

        bool i_print = 0;

        unsigned int delivered;

        for(unsigned int d=start; d<_problem._NDays; d++)
        {
            if(i_print == 1) cout << endl << "forward distribution " << d << ": " << distribution << endl;

            for(unsigned int l=d; l<_problem._NDays; l++)
            {
                delivered = distribution;

                if(delivered > _unmetDemand[product][l])
                {
                    delivered = _unmetDemand[product][l];
                }

                for(unsigned int k=start; k<l; k++) // between the day it was produced and the day before
                {
                    if(delivered > _freeInventory[product][k])
                    {
                        delivered = _freeInventory[product][k];
                    }

                    if(delivered > _totalFreeInventory[k])
                    {
                        delivered = _totalFreeInventory[k];
                    }
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

                    for(unsigned int k=d; k<l; k++) // between the day it was produced and the day before
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


    // problem was here - normaly it will solve the bug - lets see
    void EPPSolution::forwardDelivery(unsigned int product, unsigned int start, unsigned int &distribution, unsigned int &unmet)
    {
        if(_hprint == 1) cout << endl << "head: backward delivering production..." << endl;

        bool i_print = 0; // I'm not seeing inventory capacity whe distributing to demand

        // As I remember, I just need to distribute production

        if(unmet > 0 && _production[product][start] > 0)
        {
            unsigned int delivered, diff;

            unsigned int amount = _production[product][start];

            for(unsigned int d=start; d<_problem._NDays; d++) // distributes production
            {
                if(i_print == 1) cout << endl << "forward distribution " << d << ": " << distribution << endl;

                diff = _problem._demand[product][d] - _delivered[product][d];

                if(amount > diff)
                {
                    delivered = diff;
                }else
                {
                    delivered = amount;
                }

                for(unsigned int k=start; k<d; k++) // between the day it was produced and the day before
                {
                    if(delivered > _freeInventory[product][k])
                    {
                        delivered = _freeInventory[product][k];
                    }

                    if(delivered > _totalFreeInventory[k])
                    {
                        delivered = _totalFreeInventory[k];
                    }
                }

                // adjusting delivered and unmetDemand variables

                if(delivered > 0)
                {
                    _delivered[product][d] += delivered;

                    for(unsigned int l=d; l<_problem._NDays; l++)
                    {
                        _unmetDemand[product][l] -= delivered;
                        _unmetDemandTotalCost -= delivered*_problem._unmetDemandCost;
                    }

                    amount -= delivered;
                    distribution -= delivered;
                    unmet -= delivered;
                }

                // adjusting inventory variables

                for(unsigned int k=start; k<d; k++) // between the day it was produced and the day before
                {
                    _inventory[product][k] += delivered;
                    _totalFreeInventory[k] -= delivered;
                    _freeInventory[product][k] -= delivered;
                    _inventoryTotalCost += delivered*_problem._inventoryUnitCost;
                }

                if(amount == 0) break;
            }

        }
    };

    // apply a simulated annealing method for improving batches processing times

    void EPPSolution::simultedAnnealing(unsigned int NMaxIte, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: Simulated Annealing." << endl;

        bool i_print = 1;
        bool i_print_all = 0;

        ofstream SA_file;
        SA_file.open("rst/simulatedAnnealing.txt", ios_base::app);

        if(_fprint == 1)
        {
            SA_file << endl << "*** Starting Simulated Annealing ***" << endl;
            if(print(SA_file) == 1)
            {
                cout << endl << "info SA: BUG HERE - starting SA (print)" << endl;
                SA_file << endl << "BUG HERE (print)" << endl;
                getchar();
            }
            SA_file << endl << "info SA: initial solution." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "info SA: BUG HERE - starting SA (verify)" << endl;
            SA_file << endl << "BUG HERE (verify)" << endl;
            getchar();
        }


        float probality = 0, aux = 0;

        EPPSolution solution;
        EPPSolution bestSolution = autoCopy();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            if(i_print == 1) cout << endl << "SA iteration: " << ite << endl;
            if(_fprint == 1) SA_file << endl << "SA iteration: " << ite << endl;

            solution = autoCopy();
            solution.swapTime(SA_file);

            if(_fprint == 1)
            {
                if(solution.print(SA_file) == 1)
                {
                    cout << endl << "info SA: BUG HERE - after swaping time - virtual solution" << endl;
                    SA_file << endl << "BUG HERE (print - virtual solution)" << endl;
                    getchar();
                }
                SA_file << endl << "info SA: virtual solution after swaping time." << endl;
            }

            if(solution.verify() == 1)
            {
                cout << endl << "info SA: BUG HERE - after swaping time - virtual solution (verify)" << endl;
                SA_file << endl << "BUG HERE (verify - virtual solution)" << endl;
                getchar();
            }

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    if(i_print_all == 1) cout << endl << "info: found a better solution." << endl;
                    bestSolution.set(solution);
                    ite = 0;
                }

                if(i_print_all == 1) cout << endl << "solution improved..." << endl;
                set(solution);
                //print();
                //cout << endl << "info: solution improved by SA." << endl;
                //getchar();
            }else
            {
                probality = solution._fitness / bestSolution._fitness;
                if(i_print_all == 1) cout << endl << "probality: " << probality << endl;
                aux = rand();
                aux = aux;
                if(i_print_all == 1) cout << endl << "random: " << aux << endl;

                if(aux <= probality)
                {
                    if(i_print_all == 1) cout << endl << "solution acepted..." << endl;
                    set(solution);
                    //print();
                    //cout << endl << "info: solution accepted by SA." << endl;
                    //getchar();
                }
            }
            if(i_print == 1) cout << endl << "SA iteration: " << ite << endl;
        }

        set(bestSolution);

        solution.clear();
        bestSolution.clear();

         if(_fprint == 1)
        {
            print(file);
            file << endl << "info SA: final solution." << endl;
        }

        SA_file.close();
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
        solution._batchColor = _batchColor;
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
        _batchColor = solution._batchColor;
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

    bool EPPSolution::swapTime(ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1 || i_print == 1) cout << endl << "head: swaping time..." << endl;

        unsigned int batch = rand()%_allocation.size();
        if(i_print == 1) cout << endl << "batch:  " << batch << endl;

        unsigned int extruder = _allocation[batch][0];
        if(i_print == 1) cout << endl << "extruder:  " << extruder << endl;

        unsigned int day = _allocation[batch][1];
        if(i_print == 1) cout << endl << "day:  " << day << endl;

        int step;

        if(_extruderIdleness[extruder][day] < 1)
        {
            if(_processingTime[batch] < 1)
            {
                if(i_print == 1) cout << endl << "info swapTime: time of batch (randomly selected) cannot be reduced or increased." << endl;
                if(i_print == 1) cout << endl << "no change in batch time." << endl;
                if(i_print == 1) getchar();
                return 1;
            }else
            {
                step = -1;
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

        if(i_print == 1) cout << endl << "step: " << step << endl;

        // evaluating if is possible to encrease production of all products on the batch

        vector<int> products;

        products.clear();
        products.resize(_problem._NProducts,0);

        unsigned int product, productionVariation, prodLimit;

        if(_batchWidth[batch] > 0 && step == 1)
        {
            for(unsigned int b=_allocation[batch][2]; b<=_allocation[batch][3]; b++)
            {
                product = _balancing[b][1];
                products[product] += 1;
            }

            for(unsigned int p=0; p<_problem._NProducts; p++)
            {
                if(products[p] > 0)
                {
                    productionVariation = _problem._productionPerTime[p][extruder];
                    prodLimit = productionLimit(p, day);

                    if(productionVariation > (prodLimit/products[p]))
                    {
                        if(i_print == 1) cout << endl << "info swapTime: can not increase production of product " << p << endl;
                        if(i_print == 1) cout << endl << "no change in batch time" << endl;
                        if(i_print == 1) getchar();
                        return 1;
                    }
                }
            }
        }

        // if everything ok, solver will change batch processing time
        processingTime(batch, _processingTime[batch]+step, file);

        // than print on file and verify if solution is ok
        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info swapTime: BUG after swap time (print)" << endl;
                file << endl << "BUG HERE - after swap time" << endl;
                getchar();
            }
            file << endl << "info: solution after swap time." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "info swapTime: BUG after swap time (verify)" << endl;
            if(_fprint == 1) file << endl << "BUG HERE - after swap time" << endl;
            getchar();
        }

        return 0;
    };

    //changing processing time of <batch> to <time>

    bool EPPSolution::processingTime(unsigned int batch, unsigned int time, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: changing batch processing time and linked variables." << endl;

        if(_i_print == 3) print();
        if(_i_print == 3) cout << endl << "info - function processing time: solution before reducing processing time." << endl;

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info processingTime: BUG before adjusting processing time (print)" << endl;
                file << endl << "BUG HERE - before adjusting processing time (print)" << endl;
                getchar();
            }
            file << endl << "info: solution before adjusting processing time." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "info processingTime: BUG before adjusting processing time (verify)" << endl;
            if(_fprint == 1) file << endl << "BUG HERE - before adjusting processing time (verify)" << endl;
            getchar();
        }

        unsigned int procTime = _processingTime[batch];

        if(time == procTime)
        {
            if(_hprint == 1) cout << endl << "info: no change in bach time." << endl;
        }else
        {
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(_batchWidth[batch] == 0)
            {
                if(_hprint == 1) cout << endl << "info - function processing time: bach is empty." << endl;
            }else
            {
                unsigned int product, production, prodLimit;

                // here we reduce or increase production of one product per time
                for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                {
                    product = _balancing[s][1];

                    cout << endl << "product: " << product << endl;

                    if(time < procTime) // reduce
                    {
                        production = (procTime-time)*_problem._productionPerTime[product][extruder];

                        //if(_i_print == 3) print();
                        //if(_i_print == 3) cout << endl << "info: solution just before reducing processing time." << endl;

                        //if(_i_print == 3) cout << endl << "production reduction: " << production << endl;
                        reduce(production, product, day, file);
                    }else // increase
                    {
                        production = (time-procTime)*_problem._productionPerTime[product][extruder];

                        prodLimit = productionLimit(product,day);
                        if(production > prodLimit)
                        {
                            cout << endl << "error processingTime: production > production limit !" << endl;
                            if(_fprint == 1) file << endl << "BUG before increasing" << endl;
                            getchar();
                            return 1;
                        }

                        if(_i_print == 3) cout << endl << "production encrease: " << production << endl;

                        increase(production, product, day, file);
                    }
                }
            }

            _extruderProcTime[extruder][day] -= _processingTime[batch] - time;
            _extruderIdleness[extruder][day] += _processingTime[batch] - time;
            _processingTime[batch] = time; // here we reduce the time of batch

            // verification can be done here

            if(_i_print == 3) cout << endl << "time: " << time << "  extruder: " << extruder << "  day: " << day << endl;

            if(_i_print == 3) cout << endl << "time: " << time << " extruder time: " << _extruderProcTime[extruder][day] << " and idleness: "
                << _extruderIdleness[extruder][day] << "." << endl;
        }

        // verification can be done here, not inside function reduce, increase or deliver

        return 0;
    };

    // reduce production and adjust linked variables

    void EPPSolution::reduce(unsigned int production, unsigned int product, unsigned int day, ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1) cout << endl << "head: reducing <production> and adjusting linked variables..." << endl;

        _production[product][day] -= production;
        _productionTotalProfit -= production*_problem._unitContribution[product];

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info reduce: BUG before reducing production (print)" << endl;
                file << endl << "BUG HERE - befor reducing production" << endl;
                getchar();
            }
            file << endl << "info: solution before reducing production." << endl;
        }

        // verification here can result in a false bug cause this function reduce production of only one product per time

        i_print = deliver(product, file);

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG after reducing production" << endl;
                file << endl << "BUG HERE - after reducing production" << endl;
                getchar();
            }
            file << endl << "info: solution after reducing production." << endl;
        }

    };

    // apply a simulated annealing method for improving solution

    void EPPSolution::particleCollision(unsigned int NMaxIte, unsigned int NMaxIteSA)
    {
        bool i_print = 1;
        bool i_print_all = 0;

        if(_hprint == 1 || i_print == 1 || i_print_all == 1) cout << endl << "head: particle collision" << endl;

        ofstream file, SA_file;

        file.open("rst/particleCollision.txt");

        srand((unsigned) time(NULL));

        EPPSolution solution;
        EPPSolution bestSolution = autoCopy();

        float probality = 0, aux = 0;

        if(_fprint == 1)
        {
            SA_file.open("rst/simulatedAnnealing.txt", ios_base::app);
            SA_file << endl << "*** In Particle Collision ***" << endl;
            SA_file.close();

            file << endl << "*** Particle Collision ***" << endl;

            _problem.print(file);
            if(print(file) == 1) file << endl << "BUG HERE" << endl;
            file << endl << "info PC: initial solution." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "BUG HERE" << endl;
            if(_fprint == 1) file << endl << "BUG HERE" << endl;
            getchar();
        }

        if(i_print_all == 1) _problem.print();
        if(i_print_all == 1) print();
        if(i_print_all == 1) cout << endl << "problem and initial solution in PCA." << endl;
        if(i_print_all == 1) getchar();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            if(i_print == 1 || i_print_all == 1) cout << endl << "*** PC - iteration " << ite << " ***" << endl;

            if(_fprint == 1) file << endl << "*** PC - iteration " << ite << " ***" << endl;

            solution = autoCopy();

            solution.swapProduct(file);
            if(_i_print == 2) solution.print();

            if(_fprint == 1)
            {
                SA_file.open("rst/simulatedAnnealing.txt", ios_base::app);
                SA_file << endl << "*** PC - iteration " << ite << " ***" << endl;
                SA_file.close();


                if(solution.print(file) == 1) file << endl << "BUG HERE" << endl;
                file << endl << "info PC: virtual solution after PC pertubation." << endl;
            }

            if(solution.verify() == 1)
            {
                cout << endl << "BUG HERE" << endl;
                if(_fprint == 1) file << endl << "BUG HERE" << endl;
                getchar();
            }

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    if(i_print_all == 1) cout << endl << "info: found a better solution." << endl;
                    bestSolution.set(solution);
                    ite = 0;

                    if(_fprint == 1)
                    {
                        file << endl << "info PC: *** found a best solution ***" << endl;
                        bestSolution.print(file);
                        file << endl << "info PC: best solution updated." << endl;
                    }

                    if(bestSolution.verify() == 1)
                    {
                        cout << endl << "BUG HERE" << endl;
                        if(_fprint == 1) file << endl << "BUG HERE" << endl;
                        getchar();
                    }
                }

                if(i_print_all == 1) cout << endl << "info: solution improved." << endl;

                set(solution);

                if(_fprint == 1)
                {
                    if(print(file) == 1) file << endl << "BUG HERE" << endl;
                    file << endl << "info PC: solution updated." << endl;
                }

                if(verify() == 1)
                {
                    cout << endl << "BUG HERE" << endl;
                    if(_fprint == 1) file << endl << "BUG HERE" << endl;
                    getchar();
                }

                if(i_print_all == 1) print();
                if(i_print_all == 1) cout << endl << "info: solution improved by PCA." << endl;

                simultedAnnealing(NMaxIteSA, SA_file);

                if(_fprint == 1)
                {
                    if(print(file) == 1) file << endl << "BUG HERE" << endl;
                    file << endl << "info PC: solution after SA." << endl;
                }

                if(verify() == 1)
                {
                    cout << endl << "BUG HERE" << endl;
                    if(_fprint == 1) file << endl << "BUG HERE" << endl;
                    getchar();
                }

                if(i_print_all == 1) print();
                if(i_print_all == 1) cout << endl << "info: solution after SA." << endl;
                //getchar();

                clean(1, file);
                if(i_print_all == 1) print();
                if(i_print_all == 1) cout << endl << "info: empty processed time batches cleared." << endl;

                if(_fprint == 1)
                {
                    if(print(file) == 1) file << endl << "BUG HERE" << endl;
                    file << endl << "info PC: solution after cleanning." << endl;
                }

                if(verify() == 1)
                {
                    cout << endl << "BUG HERE" << endl;
                    if(_fprint == 1) file << endl << "BUG HERE" << endl;
                    getchar();
                }
                //getchar();
            }else
            {
                probality = solution._fitness / bestSolution._fitness;
                if(i_print_all == 1) cout << endl << "probality: " << probality << endl;
                aux = rand()%10;
                aux = aux/10;
                if(i_print_all == 1) cout << endl << "random: " << aux << endl;

                if(i_print_all == 1) cout << endl << "info: solution not improved" << endl;
                if(aux <= probality)
                {
                    if(i_print_all == 1) cout << " but acepted..." << endl;
                    set(solution);

                    if(_fprint == 1)
                    {
                        if(print(file) == 1) file << endl << "BUG HERE" << endl;
                        file << endl << "info PC: solution updated - Metropolis criterium acceptation." << endl;
                    }

                    if(verify() == 1)
                    {
                        cout << endl << "BUG HERE" << endl;
                        if(_fprint == 1) file << endl << "BUG HERE" << endl;
                        getchar();
                    }

                    if(i_print_all == 1) print();
                    if(i_print_all == 1) cout << endl << "info: solution accepted by PCA." << endl;
                    //getchar();

                    simultedAnnealing(NMaxIteSA, SA_file);

                    if(_fprint == 1)
                    {
                        if(print(file) == 1) file << endl << "BUG HERE" << endl;
                        file << endl << "info PC: solution after SA." << endl;
                    }

                    if(verify() == 1)
                    {
                        cout << endl << "BUG HERE" << endl;
                        if(_fprint == 1) file << endl << "BUG HERE" << endl;
                        getchar();
                    }

                    if(i_print_all == 1) print();
                    if(i_print_all == 1) cout << endl << "info: solution after SA." << endl;
                    //getchar();

                    //aux = rand()%10;
                    //aux = aux / 10;
                    //cout << endl << "random clear: " << aux << endl;

                    //if(aux < 0.2)
                    //{
                    clean(1, file);
                    if(i_print_all == 1) print();
                    if(i_print_all == 1) cout << endl << "info: empty processed time batches cleared." << endl;

                    if(_fprint == 1)
                    {
                        if(print(file) == 1) file << endl << "BUG HERE" << endl;
                        file << endl << "info PC: solution after cleanning." << endl;
                    }

                    if(verify() == 1)
                    {
                        cout << endl << "BUG HERE" << endl;
                        if(_fprint == 1) file << endl << "BUG HERE" << endl;
                        getchar();
                    }
                }
            }
        }

        set(bestSolution);
        if(i_print_all == 1) print();
        if(i_print_all == 1) cout << endl << "info: final PCA solution." << endl;
        if(i_print_all == 1) getchar();

        if(_fprint == 1)
        {
            if(print(file) == 1) file << endl << "BUG HERE" << endl;
            file << endl << "info: PC - final solution." << endl;
        }

        solution.clear();
        bestSolution.clear();
        file.close();
    };

    // ramdomly changes a batch or create a new one
    /* this function randomly chooses a product and eigther: creates a new lot with this product or allocates this product in a lot of the same color chosen randomly.
    When a batch is chosen, if there is no space in the extruder for the product to be inserted in the set, other products are removed.
    Additionally, the production limit for the new product is checked and then, if the batch processing time is too high, the batch is divided into two batches.
    The first batch with the limit processing time and the second with the remaining batch time value, subtracted from the setup value. */

    void EPPSolution::swapProduct(ofstream &file) // PC pertubation operator
    {
        if(_hprint == 1) cout << endl << "head: swapping products." << endl;

        if(_PCP_print == 1) print();
        if(_PCP_print == 1) cout << endl << "solution before swap product" << endl;


        unsigned int aux, batch;

        unsigned int product = rand()%_problem._NProducts; // randomly select a product
        if(_PCP_print == 1) cout << endl << "product randonly selected:  " << product << endl;

        unsigned int color = _problem._color[product]; // identify the product color
        if(_PCP_print == 1) cout << endl << "product color:  " << color << endl;

        if(_batchColorGroup[color].size() > 0) // if there are other batches of the same color
        {
            // randomly choose a batch of the same color or to create a new batch
            aux = rand()%(_batchColorGroup[color].size()+1);

            if(aux == _batchColorGroup[color].size()) // create another batch
            {
                if(_i_print == 3) cout << endl << "info: creating a new batch." << endl;

                insert(product, file);
            }else // insert the new product in the chosen batch
            {
                batch = _batchColorGroup[color][aux];

                if(_PCP_print == 1) cout << endl << "batch:  " << batch << endl;
                include(product, batch, file);

                if(verify() == 1)
                {
                    cout << endl << "BUG HERE - after include" << endl;
                    if(_fprint == 1) file << endl << "BUG HERE" << endl;
                    getchar();
                }
            }
        }else // if there are any batch of the same color, create a new one
        {
            if(_i_print == 3) cout << endl << "info: there is no batch of this color." << endl;
            if(_i_print == 3) cout << endl << "info: creating a new batch." << endl;

            insert(product, file);
        }

        if(_i_print == 3) print();
        if(_i_print == 3) cout << endl << "info: solution after swap product" << endl;
    };

    // create a new random batch with one <product>

    bool EPPSolution::insert(unsigned int product, ofstream &file)
    {
        bool i_print = 0;

        if(_i_print == 1 || _i_print == 3) cout << endl << "function: randomly creating a new batch." << endl;

        // choosing extruder and day randomly - more chance whe idleness is bigger

        unsigned int extruder, day, sum = 0, random;

        for(unsigned int e=0; e<_extruderIdleness.size(); e++)
        {
            for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
            {
                sum += _extruderIdleness[e][d];
            }
        }

        if(i_print == 1) cout << endl << "sum: " << sum << endl;

        // solving this insue !!!

        // need to calculate correctly the setup time (prevColor)

        // randomly choose an extruder and a day

        // there is a problem here if no extruder can process the product because of its width (an infinite loop will be generated)
        do
        {
            random = rand()%(sum+1);

            if(i_print == 1) cout << endl << "random: " << random << endl;

            sum = 0;

            for(unsigned int e=0; e<_extruderIdleness.size(); e++)
            {
                for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
                {
                    sum += _extruderIdleness[e][d];
                    if(random <= sum)
                    {
                        extruder = e;
                        day = d;
                        break;
                    }
                }
            }
        } while(_problem._length[extruder] < _problem._width[product]);

        if(i_print == 1) cout << endl << "product: " << product << "  extruder: " << extruder << "  day: " << day << endl;
        if(i_print == 1) getchar();

        // calculating setup time and

        unsigned int color = 0;

        unsigned int time, production, prodLimit;

        if(i_print == 1) cout << endl << "idleness: " << _extruderIdleness[extruder][day] << "  setup: " << _problem._setupTime[color][color] << endl;

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
                time = _extruderIdleness[extruder][day] - _problem._setupTime[color][color];
            }

            if(i_print == 1) cout << endl << "time: " << time << endl;

            insert({product},extruder,day,time,file);
        }
        return 0;
    };

    // include product on batch and adjust linked variables

    bool EPPSolution::include(unsigned int product, unsigned int batch, ofstream &file)
    {
        bool error = 0;
        bool i_print = 0;

        if(_hprint == 1) cout << endl << "head: including product on batch." << endl;
        if(_fprint == 1) file << endl << endl << "function: including product on batch." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        if(_i_print == 3) cout << endl << "extruder: " << extruder << "  day: " << day  << endl;

        if(_problem._length[extruder] < _problem._width[product])
        {
            if(_i_print == 3) cout << endl << "error: product cannot be allocated on this extruder !" << endl;
            if(_i_print == 3) getchar();
            return 1;
        }else
        {
            if(verify() == 1)
            {
                print();
                cout << endl << "info include: solution before erasing" << endl;
                getchar();
            }

            while(_batchIdleness[batch] < _problem._width[product]) // taking free space on extruder (force viable solution)
            {
                randomErase(batch, file);
            }

            if(_fprint == 1)
            {
                if(print(file) == 1)
                {
                    file << endl << "BUG HERE" << endl;
                    cout << endl << "BUG on including product on batch - after random erasing" << endl;
                    getchar();
                }
                file << endl << "info include: solution after randon erasing." << endl;
            }

            if(verify() == 1)
            {
                cout << endl << "BUG HERE - solution after random erasing" << endl;
                if(_fprint == 1) file << endl << "BUG HERE" << endl;
                getchar();
            }

            // updating delivering to outlets

            unsigned int deliver;

            for(unsigned int o=0; o<_problem._NOutlets; o++)
            {
                if(_totalFreeOutletInventory[o]>0)
                {
                    // find inventory avalable
                    for(unsigned int p=0; p<_problem._NProducts; p++)
                    {
                        for(unsigned int d=0; d<_problem._NDays; d++)
                        {
                            if(_freeOutletInventory[p][o] == 0) break;

                            deliver = _inventory[p][d];
                            for(unsigned int l=d+1; l<_problem._NDays; l++)
                            {
                                if(deliver > _inventory[p][l])
                                {
                                    deliver = _inventory[p][l];
                                }
                            }

                            if(deliver > 0)
                            {
                                if(deliver > _totalFreeOutletInventory[o])
                                {
                                    deliver = _totalFreeOutletInventory[o];
                                }

                                if(deliver > _freeOutletInventory[p][o])
                                {
                                    deliver = _freeOutletInventory[p][o];
                                }

                                _deliveredToOutlet[p][o][d] += deliver;
                                _freeOutletInventory[p][o] -= deliver;
                                _totalFreeOutletInventory[o] -= deliver;

                                for(unsigned int l=d; l<_problem._NDays; l++)
                                {
                                    _inventory[p][l] -= deliver;
                                    _freeInventory[p][l] += deliver;
                                    _totalFreeInventory[l] += deliver;
                                    _inventoryTotalCost -= deliver*_problem._inventoryUnitCost;
                                }
                            }

                            if(_totalFreeOutletInventory[o] == 0) break;
                        }

                        if(_totalFreeOutletInventory[o] == 0) break;
                    }
                }
            }

            if(_fprint == 1)
            {
                if(print(file) == 1)
                {
                    file << endl << "BUG HERE" << endl;
                    cout << endl << "BUG on including product on batch - after updating delivering to outlets" << endl;
                    getchar();
                }
                file << endl << "info include: solution after updating delivering to outles." << endl;
            }

            if(verify())
            {
                print();
                cout << endl << "error: solution after erasing." << endl;
                file << endl << "BUG HERE" << endl;
                getchar();
            }

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

                processingTime(batch, time, file); // not spliting
            }

            if(_fprint == 1)
            {
                if(print(file) == 1)
                {
                    file << endl << "BUG HERE" << endl;
                    cout << endl << "BUG on including product on batch - after changing processing time" << endl;
                    getchar();
                }
                file << endl << "info include: solution after changing processing time" << endl;
            }

            if(verify())
            {
                print();
                cout << endl << "error: solution after changing processing time." << endl;
                file << endl << "BUG HERE" << endl;
                getchar();
            }

            error = insert(product, batch, file); // than insert product on batch

            if(_fprint == 1)
            {
                if(print(file) == 1) file << endl << "BUG HERE" << endl;
                file << endl << "info include: solution after inserting." << endl;
            }

            if(verify())
            {
                if(_fprint == 1) file << endl << "BUG HERE" << endl;
                print();
                cout << endl << "error: solution after inserting." << endl;
                getchar();
            }
        }

        return error;
    };

    // split a batch into two batches *** will be nomore used

    bool EPPSolution::split(unsigned int batch, unsigned int time, ofstream &file)
    {
        if(_i_print == 1) cout << endl << "function: spliting batch... " << endl;

        if(_i_print == 3) cout << endl << "info: calculating setup time." << endl;

        vector<unsigned int> pList;
        pList.clear();
        pList = productList(batch);

        if(_i_print == 3) cout << endl << "pList: ";

        if(_i_print == 3) for(unsigned int s=0; s<pList.size(); s++)
        {
            cout << pList[s] << "  ";
        }

        if(_i_print == 3) cout << endl;

        unsigned int product, color, prevColor;

        if(_i_print == 3) cout << endl << "batchColor: ";

        if(_i_print == 3) for(unsigned int s=0; s<_batchColor.size(); s++)
        {
            cout << _batchColor[s] << "  ";
        }

        color = _batchColor[batch];

        if(_i_print == 3) cout << endl << "color: " << color << endl;

        if(_balancing.size() >= 1)
        {
            product = _balancing.back()[1];
            if(_i_print == 3) cout << endl << "last product: " << product << endl;

            prevColor = _problem._color[product];
        }else
        {
            prevColor = color;
        }

        if(_i_print == 3) cout << endl << "previous color: " << prevColor << endl;

        if(_processingTime[batch] <= time + _problem._setupTime[prevColor][color])
        {
            if(_i_print == 3) cout << endl << "error: batch processing time cannot be splitted !" << endl;
            if(_i_print == 3) cout << endl << "info: batch will not be splited." << endl;
            if(_i_print == 3) getchar();
            return 1;
        }

        unsigned int timeNewBatch = _processingTime[batch] - time - _problem._setupTime[prevColor][color];

        if(_i_print == 3) cout << endl << "info: reducing processing time of batch to: " << time << endl;
        processingTime(batch, time, file);

        // generating another batch

        if(_i_print == 3) cout << endl << "info: generating another batch." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        if(_i_print == 3) cout << endl << "extruder: " << extruder << "  day: " << day << endl;

        if(_i_print == 3) cout << endl << "creating a new batch with the remaining time: " << timeNewBatch << endl;

        insert(pList, extruder, day, timeNewBatch, file);

        //print();

        return 0;
    };

    // create a list with batch products

    vector<unsigned int> EPPSolution::productList(unsigned int batch)
    {
        bool i_print = 0;

        if(i_print == 1) cout << endl << "function: creating a list of products." << endl;

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

    // random erease a product on <batch>

    bool EPPSolution::randomErase(unsigned int batch, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "function: random exclusion. " << endl;

        if(_PCRE_print == 1) print();
        if(_PCRE_print == 1) cout << endl << "solution befor random exclusion" << endl;

        if(batch == (_allocation.size()-1) && _allocation[batch][3] > _balancing.size()) // if it is the last batch and there is no corresponding element in _balancing
        {
            print();
            cout << endl << "error random erase: no product on this batch. " << endl;
            cout << endl << "batch: " << batch << " last batch: " << _allocation.size()-1 << " index last product" << _allocation[batch][3] << " _balancing size" << _balancing.size() << endl;
            getchar();
            return 1;
        // if it is not the last batch and first index of next batch is the same of the last index of this batch
        } else if(batch < (_allocation.size()-1) && (_allocation[batch][3] == _allocation[batch+1][2]))
        {
            print();
            cout << endl << "error random erase: no product on this batch. " << endl;
            cout << endl << "batch: " << batch << " last batch: " << _allocation.size()-1 << " index last product" << _allocation[batch][3] << " index first product " << _allocation[batch+1][2] << endl;
            getchar();
            return 1;
        } else
        {
            // choosing a product in the batch

            unsigned int start = _allocation[batch][2];
            unsigned int finish = _allocation[batch][3];

            if(_PCRE_print == 1) cout << endl << "start: " << start << "  end: " << finish << endl;

            unsigned int location;

            if(start == finish)
            {
                if(_PCRE_print == 1) cout << endl << "info: only one product on this batch. " << endl;
                location = start;
            }else
            {
                if(_PCRE_print == 1) cout << endl << "number of products on this batch: " << finish - start + 1 << endl;
                location = start + rand()%(finish - start + 1);
            }

            erase(location, file);
        }

        if(_PCRE_print == 1) print();
        if(_PCRE_print == 1) cout << endl << "solution after random exclusion" << endl;

        return 0;
    };

    bool EPPSolution::erase(unsigned int location, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: erasing product on batch. " << endl;

        if(_i_print == 3) print(1);
        if(_i_print == 3) cout << endl << "initial solution" << endl;

        unsigned int batch = _balancing[location][0];

        if(_i_print == 1) cout << endl << "location: "<< location << "   batch: " << batch << endl;

        if(location >= _balancing.size())
        {
            cout << endl << "error: _ballancing[" << batch << "] do not have element " << location << " !" << endl;
            return 1;
        }else
        {
            // adjusting allocation indexes

            if(_allocation[batch][2] < _allocation[batch][3])
            {
                _allocation[batch][3] -= 1;
                if(_i_print == 3) cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
            }

            if(_i_print == 3) cout << endl << "info: reorganizing other batches first and last indexes." << endl;

            for(unsigned int b=batch+1; b<_allocation.size(); b++)
            {
                if(_i_print == 3) cout << endl << "batch: " << b;
                _allocation[b][2] -= 1;
                if(_i_print == 3) cout << "  new first batch index: " << _allocation[b][2];

                _allocation[b][3] -= 1;
                if(_i_print == 3) cout << "  new last batch index: " << _allocation[b][3] << endl;
            }

            // excluding batches on _balancing

            unsigned int product = _balancing[location][1];
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(_i_print == 3) cout << endl << "batch being excluded - product: " << product << " extruder: " << extruder << " day: " << day << endl;

            // adjusting _balancing

             if(_i_print == 1) print(1);
             if(_i_print == 1) cout << endl << "location: " << location << endl;

            _balancing[location].clear();
            _balancing.erase(_balancing.begin()+location); // vector lib function

             if(_i_print == 1) print(1);

            _batchWidth[batch] -= _problem._width[product]; // adjusting batch width

            if(_i_print == 1) cout << endl << "batch width reduced to: " << _batchWidth[batch] << endl;

            _batchIdleness[batch] += _problem._width[product]; // adjusting batch idleness

            if(_i_print == 1) cout << endl << "batch idleness augmented to: " << _batchIdleness[batch] << endl;

            if(_i_print == 1) print(0);
            if(_i_print == 1) print(1);
            if(_i_print == 1) print(2);
            if(_i_print == 1) print(3);
            if(_i_print == 1) print(4);
            if(_i_print == 1) print(5);

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder]; // problem here

                if(_i_print == 3) cout << endl << "production being reduced: " << production << "." << endl;

                if(production > 0)
                {
                    reduce(production, product, day, file);
                }
            }

            if(_i_print == 3) print(0);
            if(_i_print == 3) print(1);
            if(_i_print == 3) print(2);
            if(_i_print == 3) print(3);
            if(_i_print == 3) print(4);
            if(_i_print == 3) print(5);
        }

        return 0;
    };

    bool EPPSolution::insert(unsigned int product, unsigned int batch, ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1) cout << endl << "head: inserting a new product on batch. " << endl;

        if(i_print == 1) print();
        if(i_print == 1) cout << endl << "solution before inserting product on batch" << endl;

        if(batch >= _allocation.size())
        {
            cout << endl << "error: batch do not exist !" << endl;
            cout << endl << "info: product will not be included." << endl;
            getchar();
            return 1;
        } // I have a batch but not the position in _balancing

        if(_i_print == 3) cout << endl << "batch: " << batch << "  idleness: " << _batchIdleness[batch] << "  product: " << product << "  width: " << _problem._width[product] << "." << endl;

        if(_batchIdleness[batch] < _problem._width[product])
        {
            cout << endl << "error: batch idleness must be greater than product width !" << endl;
            cout << endl << "info: product will not be included." << endl;
            getchar();
            return 1;
        }

        unsigned int location = _allocation[batch][3]; // last batch product

        if(_i_print == 3) cout << endl << "location: " << location << endl;

        if(location >= _balancing.size()) // if bach is empty (no products) - location is _allocation[batch][3]
        {
            if(_i_print == 3) cout << endl << "location: " << location << endl;
            if(_i_print == 3) cout << "batch index not changed: " << _allocation[batch][3] << endl;
        }else if(_balancing[location][0] > batch) // if bach is empty (no products) - location is _allocation[batch][3]
        {
            if(_i_print == 3) cout << endl << "location: " << location << endl;
            if(_i_print == 3) cout << "batch index not changed: " << _allocation[batch][3] << endl;
        }else // choose better location (ordering products on batch)
        {
            if(_i_print == 3) cout << endl << "info: adjusting other location index." << endl;

            location = _allocation[batch][3]+1;
            for(unsigned int l=_allocation[batch][3]+1; l>_allocation[batch][2]; l--)
            {
                if(_i_print == 3) cout << endl << "product on location: " << _balancing[l-1][1] << endl;

                if(_balancing[l-1][1] > product)
                {
                    location = l-1;
                    if(_i_print == 3) cout << endl << "location: " << location << endl;
                }else
                {
                    break;
                }
            }

            if(_i_print == 3) cout << endl << "choosed location: " << location << endl;

            _allocation[batch][3] += 1;

            if(_i_print == 3) cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
        }

        if(_i_print == 3) cout << endl << "here 03" << endl;

        if(_i_print == 3) cout << endl << "location: " << location << endl;

        if(_i_print == 3) cout << endl << "info: reorganizing balancing location indexes. " << endl;

        for(unsigned int b=batch+1; b<_allocation.size(); b++)
        {
            if(_i_print == 3) cout << endl << "batch: " << b << "\t";
            _allocation[b][2] += 1;
            if(_i_print == 3) cout << "new first batch index: " << _allocation[b][2];

            _allocation[b][3] += 1;
            if(_i_print == 3) cout << "  new last batch index: " << _allocation[b][3] << endl;
        }

        if(_i_print == 3) cout << endl << "info: inserting new product on batch." << endl;

        _balancing.insert(_balancing.begin()+location,{batch,product});

        _batchWidth[batch] += _problem._width[product];

        if(_i_print == 3) cout << endl << "batch width augmented to: " << _batchWidth[batch] << "." << endl;

        _batchIdleness[batch] -= _problem._width[product];

        if(_i_print == 3) cout << endl << "batch idleness reduced to: " << _batchIdleness[batch] << "." << endl;

        if(_processingTime[batch] > 0)
        {
            // adjusting production

            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];

            if(_i_print == 3) cout << endl << "production being encreased: " << production << "." << endl;

            if(production > 0)
            {
                increase(production, product, day, file);
            }
        }

        return 0;
    };

    //

    bool EPPSolution::clean(unsigned int cleanType, ofstream &file)
    {
        bool i_print = 0;

        if(i_print == 1) cout << endl << "function: cleaning." << endl;

        unsigned int color,prevColor,setup,location,extruder,day,first,last,position;

        if(cleanType == 1) // batches with empty processing time
        {
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                if(i_print == 1) cout << endl << "batch: " << b << endl;
                if(_processingTime[b] == 0)
                {
                    // clearing batch and linked variables

                    if(i_print == 1) cout << endl << "batch being cleaned: " << b << endl;

                    extruder = _allocation[b][0];
                    day = _allocation[b][1];
                    color = _batchColor[b];

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

                    // *** clearing batch and linked variables

                    // printing _balancing before cleaning

                    if(i_print == 1) cout << endl << "balancing: " << endl;
                    if(i_print == 1) for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    if(i_print == 1) cout << endl;

                    // erasing batch <b>

                    first = _allocation[b][2];
                    last = _allocation[b][3];

                    if(i_print == 1) cout << endl << "last: " << last << "  first: " << first << endl;

                    for(unsigned int p=last+1; p>first; p--)
                    {
                        position = p-1;
                        if(i_print == 1) cout << endl << "info: excluding position " << position << endl;

                        erase(position, file);

                        if(i_print == 1) cout << endl << "info: after excluding." << endl;
                    }

                    // printing _balancing after erasing

                    if(i_print == 1) cout << endl;
                    if(i_print == 1) for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << i << endl;
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    if(i_print == 1) cout << endl;

                    // adjusting batches indexes in _balancing

                    if(_allocation.size() > b+1) // if batch <b> is not the last one
                    {
                        for(unsigned int i=_allocation[b+1][2]; i<_balancing.size(); i++)
                        {
                            _balancing[i][0] -= 1;
                        }
                    }

                    // printing _balancing after adjusting _balancing indexes

                    if(i_print == 1) cout << endl << "balancing: " << endl;
                    if(i_print == 1) for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    if(i_print == 1) cout << endl;

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
                    //_batchColor.erase(_batchColor.begin()+b);

                    b--;

                    if(i_print == 1) cout << endl << "batch back: " << b << endl;
                }
            }
        }else if(cleanType == 2) // empty batches
        {
            for(unsigned int b=0; b<_allocation.size(); b++)
            {
                if(_batchWidth[b] == 0)
                {
                    color = _batchColor[b];
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
                    color = _batchColor[b];

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

    bool EPPSolution::verify()
    {
        if(_hprint == 1) cout << endl << "head: starting verifying..." << endl;

        vector<vector<unsigned int>> production = {{0}}; // production
        production.resize(_problem._NProducts);
        for(unsigned int s=0; s<production.size(); s++)
        {
            production[s].resize(_problem._NDays,0);
        }

        unsigned int batch, product, extruder, day;

        for(unsigned int s=0; s<_balancing.size(); s++)
        {
            batch = _balancing[s][0];
            product = _balancing[s][1];
            extruder = _allocation[batch][0];
            day = _allocation[batch][1];

            production[product][day] += _processingTime[batch]*_problem._productionPerTime[product][extruder];
        }

        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                if(production[p][d] != _production[p][d])
                {
                    cout << endl << "erro: problem with production calculation of product " << p << " and day " << d << " !!!" << endl;
                    cout << endl << "production: " << production[p][d] << " - _production: " << _production[p][d] << endl;
                    getchar();

                    return 1;
                }
            }
        }

        for(unsigned int s=0; s<production.size(); s++)
        {
            production[s].clear();
        }
        production.clear();

        return 0;
    }
}
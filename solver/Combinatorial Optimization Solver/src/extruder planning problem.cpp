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
// last modification: 2023/05/29

#include "../lib/extruder planning problem.h"

namespace epp
{
    // clear problem parameters and dependent variables of type vector

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

    // calculate values of dependent problem variables

    bool extruderPlanningProblem::restart()
    {
        bool error = 0; // false

        // verifying if dimensions are correct

        if(_productionRate.size() != _NExtruders)
        {
            cout << endl << "error in problem definition - extruder production rate must have <number of extruders> elements" << endl;
            error = 1;
        }

        if(_length.size() != _NExtruders)
        {
            cout << endl << "error in problem definition - extruder length must have <number of extruders> elements" << endl;
            error = 1;
        }

        if(_capacity.size() != _NExtruders)
        {
            cout << endl << "error in problem definition - extruder capacity must have <number of extruders> vectors of <number of days> elements" << endl;
            error = 1;
        }

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            if(_capacity[e].size() != _NDays)
            {
                cout << endl << "error in problem definition - extruder capacity must have <number of extruders> vectors of <number of days> elements" << endl;
                error = 1;
            }
        }

        if(_width.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products width must have <number of products> elements" << endl;
            error = 1;
        }

        if(_weightRatio.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products weight ratio must have <number of products> elements" << endl;
            error = 1;
        }

        if(_unitContribution.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products unit contribution must have <number of products> elements" << endl;
            error = 1;
        }

        if(_initialInventory.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products initial inventory must have <number of products> elements" << endl;
            error = 1;
        }

        if(_maximumInventory.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products maximum inventory must have <number of products> elements" << endl;
            error = 1;
        }

        if(_demand.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products demand by day must have <number of products> vectors of <number of days> elements" << endl;
            error = 1;
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            if(_demand[p].size() != _NDays)
            {
                cout << endl << "error in problem definition - products demand by day must have <number of products> vectors of <number of days> elements" << endl;
                error = 1;
            }
        }

        if(_color.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products color must have <number of products> elements" << endl;
            error = 1;
        }

        if(_colorAndMaterialRatio.size() != _NProducts)
        {
            cout << endl << "error in problem definition - products color and material rate must have <number of products> vectors of <number of products> elements" << endl;
            error = 1;
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            if(_colorAndMaterialRatio[p].size() != _NProducts)
            {
                cout << endl << "error in problem definition - products color and material rate must have <number of products> vectors of <number of products> elements" << endl;
                error = 1;
            }
        }

        if(_setupTime.size() != _NColors)
        {
            cout << endl << "error in problem definition - setup time must have <number of colors> vectors of <number of colors> elements" << endl;
            error = 1;
        }

        for(unsigned int c=0; c<_NColors; c++)
        {
            if(_setupTime[c].size() != _NColors)
            {
                cout << endl << "error in problem definition - setup time must have <number of colors> vectors of <number of colors> elements" << endl;
                error = 1;
            }
        }

        if(_totalMaximumOutletInventory.size() != _NOutlets)
        {
            cout << endl << "error in problem definition - total maximum outlets inventory must have <number of outlets> elements" << endl;
            error = 1;
        }

        if(_maximumOutletInventory.size() != _NProducts)
        {
            cout << endl << "error in problem definition - maximum outlets inventory must have <number of products> vectors of <number of outlets> elements" << endl;
            error = 1;
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            if(_maximumOutletInventory[p].size() != _NOutlets)
            {
                cout << endl << "error in problem definition - maximum outlets inventory must have <number of products> vectors of <number of outlets> elements" << endl;
                error = 1;
            }
        }

        // calculating production rate of products by extruder

        _productionPerTime.resize(_NProducts);

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            _productionPerTime[p].resize(_NExtruders,0);
        }

        for(unsigned int p=0; p<_NProducts; p++)
        {
            for(unsigned int e=0; e<_NExtruders; e++)
            {
                _productionPerTime[p][e] = _width[p]*_weightRatio[p]*_productionRate[e]; // (m)*(g/m²)*(m/min) = (g/min)
            }
        }

        // grouping products by color

        _productColorGroup.resize(_NColors);

        for(unsigned int p=0; p<_NProducts; p++)
        {
            _productColorGroup[_color[p]].push_back(p);
        }

        return error;
    };

    // print the extruder palnning problem

    bool extruderPlanningProblem::print()
    {
        bool error = 0; // false - this variable is used to verify if definition of the parameters (i.e. dimensions) is ok

        cout << endl << "EXTRUDER PLANNING PROBLEM" << endl;

        cout << endl << "Days: " << _NDays << endl;

        cout << endl << "Extruders: "  << _NExtruders << endl;

        cout << endl << "setup cost: " << _setupCost << "  -  operation cost: " << _operationCost << endl;

        cout << endl << "[extruder]  production rate (m/min) / length (m)" << endl;

        for(unsigned int e=0; e<_NExtruders; e++)
        {
            cout << endl << e << "\t" << _productionRate[e] << "\t" << _length[e];
        }

        cout << endl << endl << "[extruder, day]  capacity (min)" << endl << endl;

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

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            cout << p;
            for(unsigned int e=0; e<_productionPerTime[p].size(); e++)
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

    // print the extruder palnning problem on file

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

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            file << p;
            for(unsigned int e=0; e<_productionPerTime[p].size(); e++)
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

    void EPP::EPP001()
    {
        /**************************************************************************************************************************
        Small problem developed to test the solver operation.
        It is expected that the allocation will be done correctly according to the measurements of the products and the extruders.
        **************************************************************************************************************************/

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

    // clear solution primary and secondary variables of type vector

    void solution::clear()
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

        for(unsigned int p=0; p<_productionLimit.size(); p++)
        {
            _productionLimit[p].clear();
        }
        _productionLimit.clear();

        for(unsigned int s=0; s<_batchColorGroup.size(); s++)
        {
            _batchColorGroup[s].clear();
        }
        _batchColorGroup.clear();
    };

    // print on screen some part of the solution as specified by parameter <type>

    bool solution::print(unsigned int type)
    {
        bool error = 0;

        unsigned int batch;

        if(type == 0) // print fitness
        {
            cout << endl << endl << "SOLUTION" << endl;

            cout << endl << "fitness: " << _fitness << endl;
            cout << endl << "production total profit: " << _productionTotalProfit;
            cout << endl << "unmet demand total cost: " << _unmetDemandTotalCost;
            cout << endl << "inventory total cost: " << _inventoryTotalCost<< endl;

            if(_fitness != (_productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost))
            {
                 error = 1;
                 cout << endl << "error print: costs not correctly calculated !";
            }

        }else if(type == 1) // print _balancing and linked variables
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

        }else if(type == 2) // print _allocation and linked variables
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

        }else if(type == 3) // print extruder variables
        {
            cout << endl << "[extruder, day] - processing time (min) / idleness (min) / capacity (min)" << endl << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                cout << "\t" << d;
            }
            cout << "\t";
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

                cout << "\t";
                for(unsigned int d=0; d<_problem._capacity[e].size(); d++)
                {
                    cout << "\t" << _problem._capacity[e][d];
                }
                cout << endl;
            }
            cout << endl;

        }else if(type == 4) // print product variables
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

            unsigned int sum;

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

            cout << endl;

            if(error == 1) cout << endl << "error: demand variables not correctly calculated." << endl;

        }else if (type == 5) // print outlets variables
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

            for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
            {
                cout << "\t"<< _totalFreeOutletInventory[o];
                if(_totalFreeOutletInventory[o] > _problem._totalMaximumOutletInventory[o]) error = 1;
            }
            cout << endl;

            if(error == 1) cout << "error: outlet inventory variables not correctly calculated." << endl;

        }else if(type == 6)  // print inventory variables
        {
            cout << endl << "inventory (g) [product, day]" << endl << endl;
            cout << "\t\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "limit" << "\t\t\t" << "maximum";
            cout << endl << endl;

            cout << "\t" << "i";
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

            for(unsigned int p=0; p<_inventory.size(); p++)
            {
                cout << p << "\t" << _problem._initialInventory[p];
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

                for(unsigned int d=0; d<_productionLimit[p].size(); d++)
                {
                    cout << "\t"<< _productionLimit[p][d];
                }

                cout << "\t\t"<< _problem._maximumInventory[p];

                cout << endl;
            }

            cout << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                cout << "\t";
            }

            cout << "\t\t" << "total:";
            for(unsigned int d=0; d< _totalFreeInventory.size(); d++)
            {
                cout << "\t" << _totalFreeInventory[d] ;
                if(_totalFreeInventory[d] > _problem._totalMaximumInventory) error = 1;
            }
            cout << "\t\t\t\t" << "total:" << "\t" << _problem._totalMaximumInventory;

            cout << endl << endl;

            if(error == 1) cout << "error: inventory variables not correctly calculated." << endl;

        }else
        {
            cout << endl << "info: please, choose a type betwing 0 and 6." << endl;
        }

        if(error == 1) getchar();
        return error;
    };

    // print on screen a complete solution

    bool solution::print()
    {
        bool error = 0;

        error = print(0);
        print(1);
        print(2);
        print(3);
        error = print(4);
        print(5);
        error = print(6);

        return error;
    };

    // print on <file> some part of the solution as specified by parameter <type>

    bool solution::print(unsigned int type, ofstream &file)
    {
        bool error = 0;

        unsigned int batch;

        if(type == 0) // print fitness
        {
            file << endl << endl << "SOLUTION" << endl;

            file << endl << "fitness: " << _fitness << endl;
            file << endl << "production total profit: " << _productionTotalProfit;
            file << endl << "unmet demand total cost: " << _unmetDemandTotalCost;
            file << endl << "inventory total cost: " << _inventoryTotalCost << endl;

            if(_fitness != (_productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost))
            {
                 error = 1;
                 file << endl << "error print: costs not correctly calculated !";
            }

        }else if(type == 1) // print _balancing and linked variables
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

        }else if(type == 2) // print _allocation and linked variables
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

        }else if(type == 3) // print extruder variables
        {
            file << endl << "[extruder, day] -  processing time (min) / idleness (min) / capacity (min)" << endl;

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

                file << "\t";
                for(unsigned int d=0; d<_problem._capacity[e].size(); d++)
                {
                    file << "\t" << _problem._capacity[e][d];
                }
                file << endl;
            }

        }else if(type == 4) // print product variables
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

        }else if (type == 5) // print outlets variables
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

        }else if(type == 6)  // print inventory variables
        {
            file << endl << "inventory (g) [product, day]" << endl << endl;
            file << "\t\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "limit" << "\t\t\t" << "maximum";
            file << endl << endl;

            file << "\t" << "i";

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

            for(unsigned int p=0; p<_inventory.size(); p++)
            {
                file << p << "\t" << _problem._initialInventory[p];
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

                for(unsigned int d=0; d<_productionLimit[p].size(); d++)
                {
                    file << "\t"<< _productionLimit[p][d];
                }

                file << "\t\t"<< _problem._maximumInventory[p];

                file << endl;
            }

            file << endl;

            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                file << "\t";
            }

            file << "\t\t" << "total:";
            for(unsigned int d=0; d< _totalFreeInventory.size(); d++)
            {
                file << "\t" << _totalFreeInventory[d] ;
                if(_totalFreeInventory[d] > _problem._totalMaximumInventory) error = 1;
            }
            file << "\t\t\t\t" << "total:" << "\t" << _problem._totalMaximumInventory;

            file << endl;

            if(error == 1) file << endl << "error: inventory variables not correctly calculated." << endl;

        }else
        {
            file << endl << "info: please, choose a type betwing 0 and 6." << endl;
        }

        return error;
    };

    // print on <file> a complete solution

    bool solution::print(ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: starting printing on file..." << endl;

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

    // verify if the values of variable _production are correct

    bool solution::verify()
    {
        /**************************************************************************************************************************
        It calculates production and verifies if variable _production is correct.
        **************************************************************************************************************************/

        if(_hprint == 1) cout << endl << "head: verifying _production..." << endl;

        bool error = 0;

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

                    error = 1;
                }
            }
        }

        for(unsigned int s=0; s<production.size(); s++)
        {
            production[s].clear();
        }
        production.clear();

        return error;
    };

    // set the values of current solution

    void solution::set(solution solution)
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
        _productionLimit = solution._productionLimit;
        _productionTotalProfit = solution._productionTotalProfit;
        _unmetDemandTotalCost = solution._unmetDemandTotalCost;
        _inventoryTotalCost = solution._inventoryTotalCost;
        _batchColorGroup = solution._batchColorGroup;
    };

    // create a copy of the current solution by delivering this value to a variable of type solution

    solution solution::copy()
    {
        solution _solution;

        _solution._problem = _problem;
        _solution._balancing = _balancing;
        _solution._allocation = _allocation;
        _solution._processingTime = _processingTime;
        _solution._batchWidth = _batchWidth;
        _solution._batchIdleness = _batchIdleness;
        _solution._batchColor = _batchColor;
        _solution._extruderProcTime = _extruderProcTime;
        _solution._extruderIdleness = _extruderIdleness;
        _solution._production = _production;
        _solution._delivered = _delivered;
        _solution._unmetDemand = _unmetDemand;
        _solution._deliveredToOutlet = _deliveredToOutlet;
        _solution._totalFreeOutletInventory = _totalFreeOutletInventory;
        _solution._freeOutletInventory = _freeOutletInventory;
        _solution._inventory = _inventory;
        _solution._totalFreeInventory = _totalFreeInventory;
        _solution._freeInventory = _freeInventory;
        _solution._productionLimit = _productionLimit;
        _solution._fitness = _fitness;
        _solution._productionTotalProfit = _productionTotalProfit;
        _solution._unmetDemandTotalCost = _unmetDemandTotalCost;
        _solution._inventoryTotalCost = _inventoryTotalCost;
        _solution._batchColorGroup = _batchColorGroup;

        return _solution;
    };

    // create an empty initial solution for the problem

    void solution::restart(EPP problem)
    {
        clear();

        _problem.clear();
        _problem = problem; // linking solution to the problem

        if(_hprint == 1) cout << endl << "head: generating an empty initial solution for the <problem>..." << endl;

        _fitness = 0;
        _productionTotalProfit = 0;
        _unmetDemandTotalCost = 0;
        _inventoryTotalCost = 0;

        _extruderProcTime.resize(_problem._NExtruders);
        _extruderIdleness.resize(_problem._NExtruders);
        for(unsigned int e=0; e<_problem._NExtruders; e++)
        {
            _extruderProcTime[e].resize(_problem._NDays,0);
            _extruderIdleness[e].resize(_problem._NDays,0);

            for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
            {
                _extruderIdleness[e][d] = _problem._capacity[e][d];
            }
        }

        _batchColorGroup.resize(_problem._NColors);

        _production.resize(_problem._NProducts);
        for(unsigned int p=0; p<_production.size(); p++)
        {
            _production[p].resize(_problem._NDays,0);
        }

        _totalFreeInventory.resize(_problem._NDays,0);
        for(unsigned int d=0; d<_totalFreeInventory.size(); d++)
        {
            _totalFreeInventory[d] = _problem._totalMaximumInventory;
        }

        _inventory.resize(_problem._NProducts);
        _freeInventory.resize(_problem._NProducts);
        for(unsigned int p=0; p<_problem._NProducts; p++)
        {
            _inventory[p].resize(_problem._NDays,0);
            _freeInventory[p].resize(_problem._NDays,0);
            for(unsigned int d=0; d<_problem._NDays; d++)
            {
                _inventory[p][d] = _problem._initialInventory[p];
                _freeInventory[p][d] = _problem._maximumInventory[p] - _inventory[p][d];
                _totalFreeInventory[d] -= _inventory[p][d];
                _inventoryTotalCost += _inventory[p][d]*_problem._inventoryUnitCost;
            }
        }

        _delivered.resize(_problem._NProducts);
        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            _delivered[p].resize(_problem._NDays,0);

            for(unsigned int d=0; d<_delivered[p].size(); d++)
            {
                if(_problem._demand[p][d] >= _inventory[p][d])
                {
                    _delivered[p][d] = _inventory[p][d];
                }else
                {
                    _delivered[p][d] = _problem._demand[p][d];
                }

                for(unsigned int i=d; i<_problem._NDays; i++)
                {
                    _inventory[p][i] -= _delivered[p][d];
                    _freeInventory[p][i] += _delivered[p][d];
                    _totalFreeInventory[i] += _delivered[p][d];
                    _inventoryTotalCost -= _delivered[p][d]*_problem._inventoryUnitCost;
                }
            }
        }

        _unmetDemand.resize(_problem._NProducts);
        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].resize(_problem._NDays,0);

            _unmetDemand[p][0] = _problem._demand[p][0]-_delivered[p][0];
            _unmetDemandTotalCost += _unmetDemand[p][0]*_problem._unmetDemandCost;

            for(unsigned int d=1; d<_unmetDemand[p].size(); d++)
            {
                _unmetDemand[p][d] = _unmetDemand[p][d-1] + _problem._demand[p][d] - _delivered[p][d];
                _unmetDemandTotalCost += _unmetDemand[p][d]*_problem._unmetDemandCost;
            }
        }

        _fitness -= _unmetDemandTotalCost;

        _totalFreeOutletInventory.resize(_problem._NOutlets,0);
        for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
        {
            _totalFreeOutletInventory[o] = _problem._totalMaximumOutletInventory[o];
        }

        _freeOutletInventory.resize(_problem._NProducts);
        for(unsigned int p=0; p<_freeOutletInventory.size(); p++)
        {
            _freeOutletInventory[p].resize(_problem._NOutlets,0);

            for(unsigned int o=0; o<_freeOutletInventory[p].size(); o++)
            {
                if(_freeOutletInventory[p][o] <= _totalFreeOutletInventory[o])
                {
                    _freeOutletInventory[p][o] = _problem._maximumOutletInventory[p][o];
                }else
                {
                    _freeOutletInventory[p][o] = _totalFreeOutletInventory[o];
                }
            }
        }

        unsigned int aux, day;

        _deliveredToOutlet.resize(_problem._NProducts);
        for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
        {
            _deliveredToOutlet[p].resize(_problem._NOutlets);
            for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
            {
                _deliveredToOutlet[p][o].resize(_problem._NDays,0);

                for(unsigned int d=0; d<_deliveredToOutlet[p][o].size(); d++)
                {
                    aux = _inventory[p][d];
                    day = d;

                    for(unsigned int i=d+1; i<_problem._NDays; i++)
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

                        for(unsigned int i=d; i<_problem._NDays; i++)
                        {
                            _inventory[p][i] -= _deliveredToOutlet[p][o][d];
                            _totalFreeInventory[i] += _deliveredToOutlet[p][o][d];
                            _freeInventory[p][i] += _deliveredToOutlet[p][o][d];
                            _inventoryTotalCost -= _deliveredToOutlet[p][o][d]*_problem._inventoryUnitCost;
                        }
                    }
                }
            }
        }

        _fitness -= _inventoryTotalCost;

        _productionLimit.resize(_problem._NProducts);
        for(unsigned int p=0; p<_productionLimit.size(); p++)
        {
            _productionLimit[p].resize(_problem._NDays,0);

            for(unsigned int d=0; d<_productionLimit[p].size();d++)
            {
                _productionLimit[p][d] = productionLimit(p,d);
            }
        }
    };

    // calculate largest possible production for <product> on <day>

    unsigned int solution::productionLimit(unsigned int product, unsigned int day)
    {
        /**************************************************************************************************************************
        This function calculates maximum production allowed for products.
        It is calculated based on the procuction that can be send to inventory, unmet demand and outlets.
        **************************************************************************************************************************/

        if(_hprint == 1) cout << endl << "head: calculating production limit..." << endl;

        bool i_print = 0;

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

        if(totalFreeInventory > freeInventory)
        {
            prodLimit = freeInventory;
        }else
        {
            prodLimit = totalFreeInventory;
        }

        if(i_print == 1)  cout << endl << "Limit by inventory: " << prodLimit << endl;

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

        if(i_print == 1) cout << endl << "Limit by inventory and unmet demand: " << prodLimit << endl;

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

        if(i_print == 1) cout << endl << "Limit by inventory, unmet demand and outlet: " << prodLimit << endl;

        return prodLimit;
    };

    // distribute production of <product> between demand, outlets and inventory

    bool solution::deliver(unsigned int product, ofstream &file)
    {
        // any verification here can result in a false bug since this function is used by other ones

        if(_hprint == 1) cout << endl << "head: delivering production..." << endl;
        if(_fprint == 1) file << endl << "head: delivering production..." << endl;

        bool i_print = 0, error = 0;

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info deliver: BUG HERE - start delivering (print)" << endl;
                file << endl << "BUG HERE" << endl;
                error = 1;
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
                error = 1;
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

        if(i_print == 1) cout << endl << "distribution: ";

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            distribution[d] += _production[product][d]; // acumulated production of <product> on day d
            if(i_print == 1) cout << "\t" << distribution[d];
        }
        if(i_print == 1) cout << endl;

        if(i_print == 1) cout << endl << "delivering to demand" << endl;

        // distributing to demand

        unsigned int day;

        // backward distribution

        /* it is needed to do the backward distribution first so that the distribution values are updated correctly
           and the products are shipped to the outlets on the correct dates.*/

        if(i_print == 1) cout << endl << "backward distribution" << endl;

        for(unsigned int d=_problem._NDays; d>0; d--)
        {
            day = d-1;

            if(i_print == 1) cout << endl << "day: " << day << endl;

            if(i_print == 1) cout << endl << "distribution (demand): " << distribution[day] << endl;

            if(distribution[day] > 0) backwardDelivery(product, day, distribution[day]);

            if(i_print == 1) cout << endl << "after forward delivery function distribution: " << distribution[day] << endl;
        }

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG HERE - after backward distribution" << endl;
                file << endl << "BUG HERE" << endl;
                error = 1;
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
                error = 1;
            }
            file << endl << "info deliver: solution after forward distribution." << endl;
        }

        if(i_print == 1) cout << endl << "delivering to outlet and inventory" << endl;

        // updating outlets and factory inventories

        if(i_print == 1) print(0);
        if(i_print == 1) print(4);
        if(i_print == 1) print(5);
        if(i_print == 1) print(6);

        for(unsigned int d=0; d<_problem._NDays; d++)
        {
            if(i_print == 1) cout << endl << "day: " << d << "  distribution (outlet): " << distribution[d] << endl;

            if(distribution[d] > 0)
            {
                // distributing to outlets

                for(unsigned int o=0; o<_problem._NOutlets; o++)
                {
                    if(i_print == 1) cout << endl << "outlet: " << o << " free: " << _freeOutletInventory[product][o] << " total free: " << _totalFreeOutletInventory[o] << endl;

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

                if(i_print == 1) cout << endl << "day: " << d << "  distribution (inventory): " << distribution[d] << endl;

                if(distribution[d] > 0)
                {
                    // here I supose that remaining distribution can be send to inventory - if there is some error in solver solution can be infeasible
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
                }
            }
        }

        unsigned int amount;

        for(unsigned int o=0; o<_problem._NOutlets; o++)
        {
            if(_totalFreeOutletInventory[o] > 0)
            {
                for(unsigned int p=0; p<_problem._NProducts; p++)
                {
                    if(_freeOutletInventory[p][o] > 0)
                    {
                        for(unsigned int d=0; d<_problem._NDays; d++)
                        {
                            amount = _inventory[p][d];

                            if(amount == 0) break;

                            for(unsigned int k=d+1; k<_problem._NDays; k++)
                            {
                                if(_inventory[p][k] < amount)
                                {
                                    amount = _inventory[p][k];

                                    if(amount == 0)
                                    {
                                        d = k;
                                        break;
                                    }
                                }
                            }

                            if(amount > 0)
                            {
                                if(amount > _freeOutletInventory[p][o])
                                {
                                    amount = _freeOutletInventory[p][o];
                                }

                                if(amount > _totalFreeOutletInventory[o])
                                {
                                    amount = _totalFreeOutletInventory[o];
                                }

                                _deliveredToOutlet[p][o][d] += amount;
                                _freeOutletInventory[p][o] -= amount;
                                _totalFreeOutletInventory[o] -= amount;

                                if(i_print == 1) cout << endl << "totalFreeOutletInventory[o]: " << _totalFreeOutletInventory[o] << " amount: " << amount << endl;

                                for(unsigned int k=d; k<_problem._NDays; k++)
                                {
                                    _inventory[p][k] -= amount;
                                    _freeInventory[p][k] += amount;
                                    _totalFreeInventory[k] += amount;

                                    _inventoryTotalCost -= _problem._inventoryUnitCost*amount;
                                }

                                if(_freeOutletInventory[p][o] == 0) break;
                                if(_totalFreeOutletInventory[o] == 0) break;
                            }
                        }

                        if(_totalFreeOutletInventory[o] == 0) break;
                    }
                }
            }
        }

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

        distribution.clear();

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG HERE - after forward distribution" << endl;
                file << endl << "BUG HERE" << endl;
                error = 1;
            }
            file << endl << "info deliver: solution after delivering." << endl;
        }

        return error;
    };

     void solution::backwardDelivery(unsigned int product, unsigned int day, unsigned int &distribution)
    {
        if(_hprint == 1) cout << endl << "head: backward delivering production..." << endl;

        bool i_print = 0;

        if(_production[product][day] > 0)
        {
            unsigned int delivered, diff;

            unsigned int amount = _production[product][day];

            for(unsigned int d=day; d<_problem._NDays; d++) // distributes production
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

                for(unsigned int k=day; k<d; k++) // between the day it was produced and the day before
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
                }

                // adjusting inventory variables

                for(unsigned int k=day; k<d; k++) // between the day it was produced and the day before
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

    void solution::forwardDelivery(unsigned int product, unsigned int day, unsigned int &distribution)
    {
        if(_hprint == 1) cout << endl << "head: forward delivering production..." << endl;

        bool i_print = 0;

        unsigned int delivered;

        for(unsigned int d=day; d<_problem._NDays; d++)
        {
            if(i_print == 1) cout << endl << "forward distribution " << d << ": " << distribution << endl;

            for(unsigned int l=d; l<_problem._NDays; l++)
            {
                delivered = distribution;

                // verifying unmet demand limits
                for(unsigned int k=l; k<_problem._NDays; k++)
                {
                    if(delivered > _unmetDemand[product][k])
                    {
                        delivered = _unmetDemand[product][k];
                    }
                }

                // verifying inventory limits
                for(unsigned int k=day; k<l; k++) // between the day it was produced and the day before
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

    // change processing time of <batch> to <time> and linked variables accordly

    bool solution::processingTime(unsigned int batch, unsigned int time, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: changing batch processing time and linked variables..." << endl;

        bool i_print = 0; // set value to 1 if you wanna debbug this function

        bool error = 0;

        if(i_print == 1) print();
        if(i_print == 1) cout << endl << "info processingTime: solution before changing processing time." << endl;

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info processingTime: BUG before adjusting processing time (print)" << endl;
                file << endl << "BUG HERE - before adjusting processing time (print)" << endl;
                getchar();
                error = 1;
            }
            file << endl << "info processingTime: solution before adjusting processing time." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "info processingTime: BUG before adjusting processing time (verify)" << endl;
            if(_fprint == 1) file << endl << "BUG HERE - before adjusting processing time (verify)" << endl;
            getchar();
            error = 1;
        }

        unsigned int procTime = _processingTime[batch];

        if(time == procTime)
        {
            if(_hprint == 1) cout << endl << "info processingTime: no change in bach time." << endl;
        }else
        {
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(_batchWidth[batch] == 0)
            {
                if(_hprint == 1) cout << endl << "info processingTime: bach is empty." << endl;
            }else
            {
                unsigned int product, amount, prodLimit;

                vector<int> nProducts;

                nProducts.clear();
                nProducts.resize(_problem._NProducts,0);

                // verifying if there is some bug in solver

                if(time < procTime) // reduce
                {
                    for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                    {
                        product = _balancing[s][1];
                        nProducts[product] += 1;

                        if(i_print == 1) cout << endl << "product: " << product << " repetitions: " << nProducts[product] << endl;

                        amount = nProducts[product]*((procTime-time)*_problem._productionPerTime[product][extruder]);

                        if(amount > _production[product][day])
                        {
                            print();
                            cout << endl << "error processingTime: amount to be reduced: " << amount << " > _production: " << _production[product][day] << " !" << endl;
                            cout << endl << "processing time wont be changed." << endl;

                            if(_fprint == 1) file << endl << "BUG before reducing - amount to be increased >> _production" << endl;

                            getchar();
                            return 1;
                        }
                    }
                } else // increase
                {
                    if((time-procTime) > _extruderIdleness[extruder][day])
                    {
                        cout << endl << "error processingTime: not possible to increase ptocessing time - time to be increased >> extruder idleness" << endl;
                        cout << endl << "processing time wont be changed." << endl;

                        if(_fprint == 1) file << endl << "BUG before increasing - time increased >> extruder idleness" << endl;

                        getchar();
                        return 1;
                    }

                    for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                    {
                        product = _balancing[s][1];
                        nProducts[product] += 1;

                        if(i_print == 1) cout << endl << "product: " << product << " repetitions: " << nProducts[product] << endl;

                        amount = nProducts[product]*((time-procTime)*_problem._productionPerTime[product][extruder]);
                        prodLimit = productionLimit(product,day);

                        if(amount > prodLimit)
                        {
                            if(i_print == 1) cout << endl << "info processingTime: amount to be increased: " << amount << " > production limit: " << prodLimit << " !" << endl;
                            if(i_print == 1) cout << endl << "processing time wont be changed." << endl;
                            return 1;
                        }
                    }
                }

                // reducing or increasing production of one product per time

                for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                {
                    product = _balancing[s][1];

                    if(i_print == 1) cout << endl << "product: " << product << endl;

                    if(time < procTime) // reduce
                    {
                        amount = (procTime-time)*_problem._productionPerTime[product][extruder];

                        if(i_print == 1) cout << endl << "info processingTime: production reduction: " << amount << endl;

                        reduce(amount, product, day, file);
                    }else // increase
                    {
                        amount = (time-procTime)*_problem._productionPerTime[product][extruder];

                        if(i_print == 1) cout << endl << "info processingTime: production increasing: " << amount << endl;

                        increase(amount, product, day, file);
                    }
                }
            }

            _extruderProcTime[extruder][day] -= _processingTime[batch] - time;
            _extruderIdleness[extruder][day] += _processingTime[batch] - time;
            _processingTime[batch] = time; // here we reduce the time of batch

            // verification can be done here

            if(i_print == 1) cout << endl << "time: " << time << "  extruder: " << extruder << "  day: " << day << endl;

            if(i_print == 1) cout << endl << "time: " << _processingTime[batch] << " extruder time: " << _extruderProcTime[extruder][day] << " and idleness: "
                << _extruderIdleness[extruder][day] << "." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "error processingTime: production not correctly changed" << endl;
            error = 1;
        }

        return error;
    };

    // reduce production and adjust linked variables

    bool solution::reduce(unsigned int amount, unsigned int product, unsigned int day, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: reducing <production> and adjusting linked variables..." << endl;

        bool error = 0;

        _production[product][day] -= amount;
        _productionTotalProfit -= amount*_problem._unitContribution[product];

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info reduce: BUG before reducing production (print)" << endl;
                file << endl << "BUG HERE - befor reducing production" << endl;
                getchar();
                error = 1;
            }
            file << endl << "info: solution before reducing production." << endl;
        }

        // verification here can result in a false bug cause this function reduce production of only one product per time

        if(deliver(product, file) == 1)
        {
            error = 1;
            print();
            cout << endl << "error reduce: error after deliver function" << endl;
            getchar();
        }

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "BUG after reducing production" << endl;
                file << endl << "BUG HERE - after reducing production" << endl;
                getchar();
                error = 1;
            }
            file << endl << "info: solution after reducing production." << endl;
        }

        return error;

    };

    // increase production and adjust linked variables

    bool solution::increase(unsigned int amount, unsigned int product, unsigned int day, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: increasing <production> and adjusting linked variables..." << endl;
        if(_fprint == 1) file << endl << "head: increasing <production> and adjusting linked variables..." << endl;

        bool i_print = 0, error = 0;

        if(i_print == 1) cout << endl << "product: " << product << " production: " << _production[product][day] << endl;

        _production[product][day] += amount;
        _productionTotalProfit += amount*_problem._unitContribution[product];

        // verification here can result in a false bug since this function increase production of only one product per time

        if(i_print == 1) cout << endl << "new production: " << _production[product][day] << endl;

        if(deliver(product, file) == 1)
        {
            error = 1;
            print();
            cout << endl << "error reduce: error after deliver function" << endl;
            getchar();
        }

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info increase: BUG after increasing production (print)" << endl;
                file << endl << "BUG HERE - after increasing production (print)" << endl;
                getchar();
                error = 1;
            }
            file << endl << "info: solution after increasing production." << endl;
        }

        // verification here can result in a false bug since this function increase production of only one product per time

        if(error == 1) cout << endl << "error after increase function !" << endl;

        return error;
    };

    // exclude product on _balancing <location> from its batch

    bool solution::erase(unsigned int location, ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1 || i_print == 1) cout << endl << "head: erasing product on batch..." << endl;

        if(i_print == 1) print(1);
        if(i_print == 1) cout << endl << "info erase: initial solution" << endl;

        if(i_print == 1) cout << endl << "location: "<< location << "  _balancing size: " << _balancing.size() << endl;

        if(location >= _balancing.size())
        {
            cout << endl << "error erase: " << location << " bigger than _balancing size - element do not exist !" << endl;
            cout << endl << "no product will be erased from batch" << endl;
            getchar();
            return 1;
        }else
        {
            unsigned int batch = _balancing[location][0];

            // adjusting allocation indexes

            if(_allocation[batch][2] < _allocation[batch][3])
            {
                _allocation[batch][3] -= 1;
                if(i_print == 1) cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
            }

            if(i_print == 1) cout << endl << "info erase: reorganizing other batches first and last indexes." << endl;

            for(unsigned int b=batch+1; b<_allocation.size(); b++)
            {
                if(i_print == 1) cout << endl << "batch: " << b;
                _allocation[b][2] -= 1;
                if(i_print == 1) cout << "  new first batch index: " << _allocation[b][2];

                _allocation[b][3] -= 1;
                if(i_print == 1) cout << "  new last batch index: " << _allocation[b][3] << endl;
            }

            // excluding product from batch on _balancing

            unsigned int product = _balancing[location][1];
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(i_print == 1) cout << endl << "product being excluded from batch: " << product << " extruder: " << extruder << " day: " << day << endl;

            // adjusting _balancing

             if(i_print == 1) print(1); // printing _balancing
             if(i_print == 1) cout << endl << "location: " << location << endl;

            _balancing[location].clear();
            _balancing.erase(_balancing.begin()+location); // vector lib function

             if(i_print == 1) print(1); // printing _balancing

            _batchWidth[batch] -= _problem._width[product]; // adjusting batch width

            if(i_print == 1) cout << endl << "batch width reduced to: " << _batchWidth[batch] << endl;

            _batchIdleness[batch] += _problem._width[product]; // adjusting batch idleness

            if(i_print == 1) cout << endl << "batch idleness augmented to: " << _batchIdleness[batch] << endl;

            if(i_print == 1) print();

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int amount = _processingTime[batch]*_problem._productionPerTime[product][extruder];

                if(i_print == 1) cout << endl << "production being reduced: " << amount << endl;

                if(amount > 0)
                {
                    reduce(amount, product, day, file);
                }
            }

            if(i_print == 1) print();
        }

        return 0;
    };



    // generate an inicial not empty and feaseble solution

    void solution::generate(ofstream &file)
    {
        /**************************************************************************************************************************
        This function creates a non empty and feasible initial solution.
        It calculates a mean batch processing time and creates a batch for each product wich (cujo) processing time is the mean
        calculated or the maximum value allowed.
        **************************************************************************************************************************/

        if(_hprint == 1) cout << endl << "head: generating a new solution... " << endl;

        bool i_print = 0;

        // taking the biggest setup time to define a mean batch processing time

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

        // calculating a mean batch processing time

        unsigned int totalCapacity = 0;

        for(unsigned int e=0; e<_problem._capacity.size(); e++)
        {
            for(unsigned int d=0; d<_problem._capacity[e].size(); d++)
            {
                totalCapacity = totalCapacity + _problem._capacity[e][d];
            }
        }

        unsigned int batchTime = rint(floor(totalCapacity / _problem._NProducts)) - setup;

        if(i_print == 1) cout << endl << "mean batch processing time: " << batchTime << endl;

        // creating a batch for each product

        bool stop;
        unsigned int day = 0;
        unsigned int extruder = 0;
        unsigned int production = 0, prodLimit = 0;
        unsigned int time = 0;
        vector<unsigned int> newVector;

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
                             if(i_print == 1) cout << endl << "inventory problem - reducing production...";
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
                            if(i_print == 1) cout << endl << "info generate: extruder idleness is not enought to allocate another batch.";
                        }
                    }

                    if(stop == 1)
                    {
                        break;
                    }
                }
            }

            // creating a new batch

            if (extruder < _problem._NExtruders)
            {
                if(i_print == 1) cout << endl << "Solution found: " << endl;

                if(i_print == 1) cout << endl << "extruder: " << extruder;
                if(i_print == 1) cout << endl << "day: " << day;
                if(i_print == 1) cout << endl << "time: " << time;
                if(i_print == 1) cout << endl << "production: " << production << endl;

                insert({p}, extruder, day, time, file);
            }else
            {
                cout << endl << "Product " << p << " cannot be allocated cause its width is very large for extruders !!!" << endl;
            }
        }

        newVector.clear();
    };

    // create a new batch and adjust linked variables

    bool solution::insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time, ofstream &file)
    {
        if(_hprint == 1) cout << endl << "head: creating a new batch..." << endl;

        bool i_print = 0, error = 0;

        unsigned int batch = _allocation.size(); // selecting the new position (last position)
        // after I'll try to order by color but not now

        if(i_print == 1) cout << endl << "new position: " << batch << endl;

        if(productList.size() > 1) // verify if products of the informed list are of same color and material
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

                error = increase(production, product, day, file);
            }
        }

        newVector.clear();
        return error;
    };

    // apply a simulated annealing method for improving batches processing times

    void solution::simultedAnnealing(unsigned int NMaxIte, ofstream &file)
    {
        bool i_print = 0;

        if(_hprint == 1 || i_print == 1) cout << endl << "head: applying simulated annealing for improuve batches processing time..." << endl;

        if(_fprint == 1)
        {
            file << endl << "*** Starting Simulated Annealing ***" << endl;
            if(print(file) == 1)
            {
                print();
                cout << endl << "info SA: BUG HERE - starting SA (print)" << endl;
                file << endl << "BUG HERE (print)" << endl;
                getchar();
            }
            file << endl << "info SA: initial solution." << endl;
        }

        if(verify() == 1)
        {
            print();
            cout << endl << "info SA: BUG HERE - starting SA (verify)" << endl;
            file << endl << "BUG HERE (verify)" << endl;
            getchar();
        }

        float probality = 0, aux = 0;

        solution _solution;
        solution bestSolution = copy();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            if(i_print == 1) cout << endl << "SA iteration: " << ite << endl;
            if(_fprint == 1) file << endl << "SA iteration: " << ite << endl;

            _solution = copy();
            _solution.swapTime(file);

            if(_fprint == 1)
            {
                if(_solution.print(file) == 1)
                {
                    _solution.print();
                    cout << endl << "info SA: BUG HERE - after swaping time - virtual solution" << endl;
                    file << endl << "BUG HERE (print - virtual solution)" << endl;
                    getchar();
                }
                file << endl << "info SA: virtual solution after swaping time." << endl;
            }

            if(_solution.verify() == 1)
            {
                print();
                cout << endl << "info SA: BUG HERE - after swaping time - virtual solution (verify)" << endl;
                file << endl << "BUG HERE (verify - virtual solution)" << endl;
                getchar();
            }

            if(_solution._fitness > _fitness)
            {
                if(_solution._fitness > bestSolution._fitness)
                {
                    if(i_print == 1) cout << endl << "info: found a better solution." << endl;
                    bestSolution.set(_solution);
                    ite = 0;
                }

                if(i_print == 1) cout << endl << "solution improved..." << endl;
                set(_solution);

                if(i_print == 1)
                {
                    print();
                    cout << endl << "info SA: solution improved by SA." << endl;
                    getchar();
                }
            }else
            {
                probality = _solution._fitness / bestSolution._fitness;
                if(i_print == 1) cout << endl << "probality: " << probality << endl;
                aux = rand();
                aux = aux;
                if(i_print == 1) cout << endl << "random: " << aux << endl;

                if(aux <= probality)
                {
                    if(i_print == 1) cout << endl << "info SA: solution acepted..." << endl;
                    set(_solution);

                    if(i_print == 1)
                    {
                        print();
                        cout << endl << "info SA: solution improved by SA." << endl;
                        getchar();
                    }
                }
            }

            if(i_print == 1) cout << endl << "SA iteration: " << ite << endl;
        }

        set(bestSolution);

        _solution.clear();
        bestSolution.clear();

        if(_fprint == 1)
        {
            file << endl << "*** Starting Simulated Annealing ***" << endl;
            if(print(file) == 1)
            {
                print();
                cout << endl << "info SA: BUG HERE - starting SA (print)" << endl;
                file << endl << "BUG HERE (print)" << endl;
                getchar();
            }
            file << endl << "info SA: final solution." << endl;
        }

        if(verify() == 1)
        {
            print();
            cout << endl << "info SA: BUG HERE - starting SA (verify)" << endl;
            file << endl << "BUG HERE (verify)" << endl;
            getchar();
        }
    };

    // modify the processing time of a randomly chosen batch, decreasing or increasing by one unit of time (minute).

    bool solution::swapTime(ofstream &file)
    {
        bool i_print = 0; // set i_print = 0 if you wanna to debbug this function;

        if(_hprint == 1 || i_print == 1) cout << endl << "head: swaping time..." << endl;

        bool error = 0;

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
                if(i_print == 1) cout << endl << "info swapTime: time of batch cannot be reduced or increased." << endl;
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

        processingTime(batch, _processingTime[batch]+step, file);

        // printing on file and verify if solution is ok

        if(_fprint == 1)
        {
            if(print(file) == 1)
            {
                cout << endl << "info swapTime: BUG after swap time (print)" << endl;
                file << endl << "BUG HERE - after swap time" << endl;
                error = 1;
                getchar();
            }
            file << endl << "info: solution after swap time." << endl;
        }

        if(verify() == 1)
        {
            cout << endl << "info swapTime: BUG after swap time (verify)" << endl;
            if(_fprint == 1) file << endl << "BUG HERE - after swap time" << endl;
            error = 1;
            getchar();
        }

        return error;
    };
}

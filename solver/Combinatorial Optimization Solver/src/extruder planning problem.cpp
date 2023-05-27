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
// last modification: 2023/05/27

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
            cout << "\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "maximum";
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

                cout << "\t"<< _problem._maximumInventory[p];

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
            file << "\t" << "inventory" << "\t\t" << "free" << "\t\t\t" << "maximum";
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

                file << "\t"<< _problem._maximumInventory[p];

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
            file << "\t" << "total:" << "\t" << _problem._totalMaximumInventory;

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
    };
}

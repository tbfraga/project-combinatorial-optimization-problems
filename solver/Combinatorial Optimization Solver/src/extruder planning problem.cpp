/*********************************************************************** LICENSE ********************************************************************************************
Important: Copies and distributions of this file must comply with the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License (CC BY-NC-ND 4.0).

Under this license, it is allowed to download and share the code as long as they give credit to the original authors, and without being able to alter them in any way or use
them for commercial purposes.

The full license can be found in the LICENSE.md document available in this directory, or through the website: https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode.
****************************************************************************************************************************************************************************/

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

        // need to becalculated yet
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

        cout << endl << "[product, extruder]  production rate (g/m)" << endl << endl;


        for(unsigned int p=0; p<_NProducts; p++)
        {
            cout << "\t" << p;
        }
        cout << endl;

        // not dimensioned yet
        /*for(unsigned int e=0; e<_NExtruders; e++)
        {
            cout << e;
            for(unsigned int p=0; p<_NProducts; p++)
            {
                cout << "\t" << _productionPerTime[p][e];
            }
            cout << endl;
        } need to becalculated yet*/

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


    // class for creating instances of EPP (Extruder Planning Problem)

    void EPPInstance::EPP001()
    {
        /*****************************
        Small problem developed to test the solver operation.
        It is expected that the allocation will be done correctly according to the measurements of the products and the extruders.
        *****************************/

        // clearProblem();

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

        //restartProblem();
    }
}

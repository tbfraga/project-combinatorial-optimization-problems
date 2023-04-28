// Combinatorial Optimization Solver
//
// software created by Tatiana Balbi Fraga
//
// cpp file
//
// PRODUCTIONPLANNINGPROBLEMINEXTRUDERS_H

#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruder::productionPlanningProblemInExtruder(unsigned int NDays, unsigned int NExtruders, vector<float> productionRate, vector<float> length,
    vector<vector<unsigned int>> capacity, float setupCost, float operationCost, unsigned int NProducts, vector<float> width, vector<float> weightRatio,
    vector<float> unitContribution, vector<unsigned int> initialInventory, vector<unsigned int> maximumInventory, unsigned int totalMaximumInventory,
    float inventoryUnitCost, vector<vector<unsigned int>> demand, float unmetDemandCost, vector<unsigned int> color, vector<vector<bool>> colorAndMaterialRatio,
    vector <vector <unsigned int>> setupTime, unsigned int NOutlets, vector<unsigned int> totalMaximumOutletInventory, vector<vector<unsigned int>> maximumOutletInventory)
    {
        cout << endl << "constructing problem ..." << endl;
        clearProblem();
        restartProblem();

        _NDays = NDays;
        _NExtruders = NExtruders;

         _productionRate = productionRate;

        if(_productionRate.size() != _NExtruders)
        {
            cout << " production rate vector needs to have " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _productionRate.resize(_NExtruders,0);
        }

        _length = length;

        if(_length.size() != _NExtruders)
        {
            cout << " length vector needs to have " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _length.resize(_NExtruders,0);
        }

        _capacity = capacity;

        if(_capacity.size() != _NExtruders)
        {
            cout << " capacity matriz needs to have " << _NExtruders << " sets of " <<  _NDays << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _capacity.resize(_NExtruders);
        }

        for(unsigned int e=0; e<_capacity.size(); e++)
        {
            if(_capacity[e].size() != _NDays)
            {
                cout << " capacity of extruder " << e + 1 << " vector needs to have " << _NDays << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _capacity[e].resize(_NDays,0);
            }
        }

        _setupCost = setupCost;
        _operationCost = operationCost;

        _NProducts = NProducts;

        _width = width;

        if(_width.size() != _NProducts)
        {
            cout << " width vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _width.resize(_NProducts,0);
        }

        _weightRatio = weightRatio;

        if(_weightRatio.size() != _NProducts)
        {
            cout << " weight ratio vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _weightRatio.resize(_NProducts,0);
        }

        _unitContribution = unitContribution;

        if(_unitContribution.size() != _NProducts)
        {
            cout << " unit contribution vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _unitContribution.resize(_NProducts,0);
        }

        _initialInventory = initialInventory;

        if(_initialInventory.size() != _NProducts)
        {
            cout << " initial inventory vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _initialInventory.resize(_NProducts,0);
        }

        _totalMaximumInventory = totalMaximumInventory;

        if(_maximumInventory.size() != _NProducts)
        {
            cout << " maximum inventory vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumInventory.resize(_NProducts,0);
        }

        _inventoryUnitCost = inventoryUnitCost;

        _demand = demand;

        if(_demand.size() != _NDays)
        {
            cout << " demand matriz needs to have " << _NDays << " sets of " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _demand.resize(_NDays);
        }

        for(unsigned int d=0; d<_demand.size(); d++)
        {
            if(_demand[d].size() != _NProducts)
            {
                cout << " demand of day " << d + 1 << " vector needs to have " << _NProducts << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _demand[d].resize(_NProducts,0);
            }
        }

        _unmetDemandCost = unmetDemandCost;

        _color = color;

        if(_color.size() != _NProducts)
        {
            cout << " color vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _color.resize(_NProducts,0);
        }

        _colorAndMaterialRatio = colorAndMaterialRatio;

        if(_colorAndMaterialRatio.size() != _NProducts - 1)
        {
            cout << " color and material matriz needs to have " << _NProducts - 1 << " sets with a maximum of " << _NProducts - 1 << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _colorAndMaterialRatio.resize(_NProducts - 1);
        }

        _setupTime = setupTime;

        for(unsigned int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            if(_colorAndMaterialRatio[i].size() != _NProducts - i - 1)
            {
                cout << " color and materialRatio relation for product " << i + 1 << " vector needs to have " << _NProducts - i - 1 << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _colorAndMaterialRatio[i].resize(_NProducts - i - 1,0);
            }
        }

        _NOutlets = NOutlets;

        _totalMaximumOutletInventory = totalMaximumOutletInventory;

        if(_totalMaximumOutletInventory.size() != _NOutlets)
        {
            cout << " total outlet inventory vector needs to have " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _totalMaximumOutletInventory.resize(_NOutlets,0);
        }

        _maximumOutletInventory = maximumOutletInventory;

        if(_maximumOutletInventory.size() != _NProducts)
        {
            cout << " maximum outlet inventory matriz needs to have " << _NProducts << " sets of " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumOutletInventory.resize(_NProducts);
        }

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            if(_maximumOutletInventory[p].size() != _NOutlets)
            {
                cout << " maximum outlet of product " << p << " vector needs to have " << _NOutlets << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _maximumOutletInventory[p].resize(_NOutlets,0);
            }
        }
    };

    productionPlanningProblemInExtruder::~productionPlanningProblemInExtruder()
    {
        clearProblem();
    };

    void productionPlanningProblemInExtruder::clearProblem()
    {
        _productionRate.clear();
        _length.clear();

        for(unsigned int i=0; i<_capacity.size(); i++)
        {
            _capacity[i].clear();
        }
        _capacity.clear();

        _width.clear();
        _weightRatio.clear();
        _unitContribution.clear();
        _initialInventory.clear();
        _maximumInventory.clear();

        for(unsigned int i=0; i<_demand.size(); i++)
        {
            _demand[i].clear();
        }
        _demand.clear();

        _color.clear();

        for(unsigned int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            _colorAndMaterialRatio[i].clear();
        }
        _colorAndMaterialRatio.clear();

        for(unsigned int i=0; i<_setupTime.size(); i++)
        {
            _setupTime[i].clear();
        }
        _setupTime .clear();

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            _productionPerTime[p].clear();
        }
        _productionPerTime.clear();

        _totalMaximumOutletInventory.clear();

        for(unsigned int p=0; p<_maximumOutletInventory.size(); p++)
        {
            _maximumOutletInventory[p].clear();
        }
        _maximumOutletInventory.clear();

        for(unsigned int i=0; i<_productColorGroup.size(); i++)
        {
            _productColorGroup[i].clear();
        }
        _productColorGroup.clear();
    };

    void productionPlanningProblemInExtruder::restartProblem()
    {
        _productionPerTime.resize(_NProducts);
        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            _productionPerTime[p].resize(_NExtruders,0);
        }

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            for(unsigned int e=0; e<_productionPerTime.size(); e++)
            {
                _productionPerTime[p][e] = _width[p]*_weightRatio[p]*_productionRate[e];
            }
        }


        _productColorGroup.resize(_NColors);

        for(unsigned int p=0; p<_color.size(); p++)
        {

            _productColorGroup[_color[p]].push_back(p);
        }
    };

    void productionPlanningProblemInExtruder::print()
    {
        cout << endl << "PRODUCTION PLANNING PROBLEM IN EXTRUDERS" << endl << endl;

        cout << "number of days: " << _NDays << endl << endl;
        cout << "number of extruders: " << _NExtruders << endl << endl;
        cout << "production rate (m/min) [extruder]: " << endl << endl;

        for(vector<float>::iterator it = _productionRate.begin(); it != _productionRate.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "length (m) [extruder]: " << endl << endl;

        for(vector<float>::iterator it = _length.begin(); it != _length.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "capacity (min) [extruder, day]: ";
        cout << endl << endl;
        for(unsigned int e=0; e<_capacity.size(); e++)
        {
            for(unsigned int d=0; d<_capacity[e].size(); d++)
            {
                cout << _capacity[e][d] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "setup cost ($/min): " << _setupCost << endl << endl;
        cout << "operation cost ($/min): " << _operationCost << endl << endl;

        cout << "number of products: " << _NProducts << endl << endl;

        cout << "product width (m) [product]: " << endl << endl;

        for(vector<float>::iterator it = _width.begin(); it != _width.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "weight ratio (g/m^2) [product]: " << endl << endl;

        for(vector<float>::iterator it = _weightRatio.begin(); it != _weightRatio.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "unit contribution ($) [product]: " << endl << endl;

        for(vector<float>::iterator it = _unitContribution.begin(); it != _unitContribution.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "initial inventory (g) [product]: " << endl << endl;

        for(vector<unsigned int>::iterator it = _initialInventory.begin(); it != _initialInventory.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "maximum inventory (g) [product]: " << endl << endl;

        for(vector<unsigned int>::iterator it = _maximumInventory.begin(); it != _maximumInventory.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "total maximum inventory (g): " << _totalMaximumInventory << endl << endl;

        cout << "inventory unit cost ($): " << _inventoryUnitCost << endl << endl;

        cout << "demand (g) [product, day]: " << endl << endl;

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            for(unsigned int d=0; d<_demand[p].size(); d++)
            {
                cout << _demand[p][d] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        cout << "unmet demand cost ($): " << _unmetDemandCost << endl << endl;

        cout << "color [product]: " << endl << endl;

        for(vector<unsigned int>::iterator it = _color.begin(); it != _color.end(); ++it)
        {
            cout << *it << endl;
        }
        cout << endl;

        cout << "product color group [product vector]: " << endl << endl;

        for(unsigned int p=0; p<_productColorGroup.size(); p++)
        {
            for(unsigned int s=0; s<_productColorGroup[p].size(); s++)
            {
                cout << _productColorGroup[p][s] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        cout << "colour and material rate [product, product]: ";
        cout << endl << endl;

        for(unsigned int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            for(unsigned int j=0; j<_colorAndMaterialRatio[i].size(); j++)
            {
                cout << _colorAndMaterialRatio[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "setup time (min) [color, color]: " << endl << endl;

        for(unsigned int i=0; i<_setupTime.size(); i++)
        {
            for(unsigned int j=0; j<_setupTime[i].size(); j++)
            {
                cout << _setupTime[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "production rate (g/min) [product, extruder]: " << endl << endl;

        for(unsigned int p=0; p<_productionPerTime.size(); p++)
        {
            for(unsigned int e=0; e<_productionPerTime[p].size(); e++)
            {
               cout << _productionPerTime[p][e]  << "\t";
            }
            cout << endl;
        }
        cout << endl;

        cout << "number of outlets: " << _NOutlets << endl << endl;

        cout << "total maximum outlet inventory (g) [outlet]: " << endl << endl;
        for(vector<unsigned int>::iterator it = _totalMaximumOutletInventory.begin(); it != _totalMaximumOutletInventory.end(); ++it)
        {
            cout << *it << "\t";
        }
        cout << endl << endl;

        cout << "maximum outlet inventory (g) [product, outlet]: ";
        cout << endl << endl;
        for(unsigned int i=0; i<_maximumOutletInventory.size(); i++)
        {
            for(unsigned int j=0; j<_maximumOutletInventory[i].size(); j++)
            {
                cout << _maximumOutletInventory[i][j] << "\t";
            }
            cout << endl;
        }

        getchar();
    };

    void PPPIEInstance::PPPIE001()
    {
        /*****************************
        Small problem developed to test the solver operation.
        It is expected that the allocation will be done correctly according to the measurements of the products and the extruders.
        *****************************/

        clearProblem();

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

        restartProblem();
    }

    void PPPIESolution::initiate(PPPIEInstance problem)
    {
        clear();

        // linking solution to d=the problem
        _problem = problem;

        cout << endl << "restarting solution..." << endl;

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

    void PPPIESolution::clear()
    {
        for(unsigned int i=0; i<_balancing.size(); i++)
        {
            _balancing[i].clear();
        }
        _balancing.clear();

        for(unsigned int i=0; i<_allocation.size(); i++)
        {
            _allocation[i].clear();
        }
        _allocation.clear();

        _processingTime.clear();

        _batchWidth.clear();

        for(unsigned int i=0; i<_restricted.size(); i++)
        {
            _restricted[i].clear();
        }
        _restricted.clear();

        _batchIdleness.clear();

        for(unsigned int i=0; i<_extruderProcTime.size(); i++)
        {
            _extruderProcTime[i].clear();
        }
        _extruderProcTime.clear();

        for(unsigned int i=0; i<_extruderIdleness.size(); i++)
        {
            _extruderIdleness[i].clear();
        }
        _extruderIdleness.clear();

        for(unsigned int c=0; c<_batchColorGroup.size(); c++)
        {
            _batchColorGroup[c].clear();
        }
        _batchColorGroup.clear();

        for(unsigned int p=0; p<_production.size(); p++)
        {
            _production[p].clear();
        }
        _production.clear();

        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            _delivered[p].clear();
        }
        _delivered.clear();

        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].clear();
        }
        _unmetDemand.clear();

        for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
        {
            for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
            {
                _deliveredToOutlet[p][o].clear();
            }
             _deliveredToOutlet[p].clear();
        }
        _deliveredToOutlet.clear();

        _totalFreeOutletInventory.clear();

        for(unsigned int p=0; p<_freeOutletInventory.size(); p++)
        {
            _freeOutletInventory[p].clear();
        }
        _freeOutletInventory.clear();

        for(unsigned int p=0; p<_inventory.size(); p++)
        {
            _inventory[p].clear();
            _freeInventory[p].clear();
        }
        _inventory.clear();
        _freeInventory.clear();

        _totalFreeInventory.clear();
    };

    bool PPPIESolution::print()
    {
        bool error = 0;

        error = print(0);
        if(error==0){error=print(1);}else print(1);
        print(2);
        print(3);
        print(4);
        print(5);
        if(error==0){error=print(6);}else print(6);

        if(error == 1) getchar();
        return error;
    };

    bool PPPIESolution::print(unsigned int type)
    {
        bool error = 0;
        unsigned int batch, position = 0;

        if(type == 0)
        {
            cout << endl << endl << "SOLUTION" << endl;

            cout << endl << "fitness: " << _fitness << endl;
            cout << endl << "production total profit: " << _productionTotalProfit << endl;
            cout << endl << "unmet demand total cost: " << _unmetDemandTotalCost  << endl;
            cout << endl << "inventory total cost: " << _inventoryTotalCost<< endl;

        }else if(type == 1)
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
        }

        if(error == 1) getchar();
        return error;
    };

    void PPPIESolution::generate()
    {
        cout << endl << "function: generating a new solution... " << endl;

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

        cout << endl << totalCapacity << "  " << batchTime;
        newVector.clear();
    };

    unsigned int PPPIESolution::productionLimit(unsigned int product, unsigned int day)
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

    bool PPPIESolution::insert(vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time)
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

    void PPPIESolution::increase(unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: encrease production." << endl;

        _production[product][day] += production;
        _productionTotalProfit += production*_problem._unitContribution[product];

        print(0);
        print(4);
        print(5);
        print(6);

        delivering(product);

         cout << endl << "info: after encreasing." << endl;

        print(0);
        print(4);
        print(5);
        print(6);

        getchar();

         //print();
    };

    void PPPIESolution::timeSimultedAnnealing(unsigned int NMaxIte)
    {
        cout << endl << " Simulated Annealing... " << endl;

        srand((unsigned) time(NULL));

        float probality = 0, aux = 0;

        PPPIESolution solution;
        PPPIESolution bestSolution = autoCopy();

        cout << endl << " solution: " << endl;
        //solution.print();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            cout << endl << "iteration: " << ite << endl;

            solution = autoCopy();
            solution.swapTime();

            cout << endl << "best fitness: " << _fitness << "  solution fitness: " << solution._fitness << endl;

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    cout << endl << "found a better solution..." << endl;
                    bestSolution.set(solution);
                    ite = 0;
                }

                cout << endl << "solution improved..." << endl;
                set(solution);
                //print();
                //cout << endl << "info: solution improved by SA." << endl;
                //getchar();
            }else
            {
                probality = solution._fitness / bestSolution._fitness;
                cout << endl << "probality: " << probality << endl;
                aux = rand()%100000;
                aux = aux / 100000;
                cout << endl << "random: " << aux << endl;

                if(aux <= probality)
                {
                    cout << endl << "solution acepted..." << endl;
                    set(solution);
                    //print();
                    //cout << endl << "info: solution accepted by SA." << endl;
                    //getchar();
                }
            }
        }

        set(bestSolution);

        solution.clear();
        bestSolution.clear();
    };

    PPPIESolution PPPIESolution::autoCopy()
    {
        PPPIESolution solution;

        solution._problem = _problem;
        solution._balancing = _balancing;
        solution._allocation = _allocation;
        solution._processingTime = _processingTime;
        solution._batchWidth = _batchWidth;
        solution._batchIdleness = _batchIdleness;
        solution._extruderProcTime = _extruderProcTime;
        solution._extruderIdleness = _extruderIdleness;
        solution._restricted = _restricted;
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

    void PPPIESolution::set(PPPIESolution solution)
    {
        _problem = solution._problem;
        _balancing = solution._balancing;
        _allocation = solution._allocation;
        _processingTime = solution._processingTime;
        _batchWidth = solution._batchWidth;
        _batchIdleness = solution._batchIdleness;
        _extruderProcTime = solution._extruderProcTime ;
        _extruderIdleness = solution._extruderIdleness;
        _restricted = solution._restricted ;
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

    bool PPPIESolution::swapTime()
    {
        cout << endl << "function: swaping time...  " << endl << endl;

        unsigned int batch = rand()%_allocation.size();
        cout << endl << "batch:  " << batch << endl;

        unsigned int extruder = _allocation[batch][0];
        cout << endl << "extruder:  " << extruder << endl;

        unsigned int day = _allocation[batch][1];
        cout << endl << "day:  " << day << endl;

        unsigned int prodLimit;

        int step;

        if(_extruderIdleness[extruder][day] < 1)
        {
            step = -1;
            if(_processingTime[batch] < 1)
            {
                cout << endl << "error: time cannot be reduced !" << endl;
                cout << endl << "production not changed." << endl;
                getchar();
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
        cout << endl << "step:  " << step << endl;

        unsigned int product;
        unsigned int productionVariation;

        for(unsigned int b=_allocation[batch][2]; b<=_allocation[batch][3]; b++)
        {
            product = _balancing[b][1];
            cout << endl << "product: " << product << endl;

            productionVariation = _problem._productionPerTime[product][extruder];
            cout << endl << "production variation: " << productionVariation << endl;

            prodLimit = productionLimit(product, day);

            if(step == 1)
            {
                if(productionVariation > prodLimit)
                {
                    cout << endl << "error: can not increase production !" << endl;
                    cout << endl << "production not changed." << endl;
                    getchar();
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

    void PPPIESolution::reduce(unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: reducing <production> and adjusting linked variables..." << endl;

        _production[product][day] -= production;
        _productionTotalProfit -= production*_problem._unitContribution[product];

        print(0);
        print(4);
        print(5);
        print(6);

        delivering(product);

        cout << endl << "info: after reduction." << endl;

        print(0);
        print(4);
        print(5);
        print(6);

         //print();
    };

    void PPPIESolution::delivering(unsigned int product)
    {
        cout << endl << "function: delivering." << endl;


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

        unsigned int delivered, day;
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
            day = d;

            cout << endl << "distribution " << d << ": " << distribution[day] << endl;

            for(unsigned int l=day; l<_problem._NDays; l++)
            {
                if(distribution[day] <= _unmetDemand[product][l])
                {
                    delivered = distribution[day];

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

                    distribution[day] -= delivered;
                }

                if(distribution[day] == 0) break;
            }
        }

        print(4);
        print(5);
        print(6);

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

        print(5);
        print(6);

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

        distribution.clear();
    };

    void PPPIESolution::swapProduct()
    {
        cout << endl << "function: adding a new product on batch... " << endl << endl;

        unsigned int aux, batch, extruder = 0, day = 0, time = 0, production, prodLimit;
        vector <unsigned int> newVector;

        unsigned int product = rand()%_problem._NProducts;
        //unsigned int product = 3;
        cout << endl << "product:  " << product << endl;

        unsigned int color = _problem._color[product];

        cout << endl << "color:  " << color << endl;

        if(_problem._productColorGroup[color].size() == 1)
        {
            cout << endl << "there is only one product of this color..." << endl;
        }

        if(_batchColorGroup[color].size() > 0)
        {
            aux = rand()%(_batchColorGroup[color].size()+1);
            //aux = 2;
            if(aux == _batchColorGroup[color].size())
            {
                extruder = rand()%_problem._NExtruders;
                while(_problem._length[extruder] < _problem._width[product])
                {
                    extruder = rand()%_problem._NExtruders;
                }
                day = rand()%_problem._NDays;

                cout << endl << "extruder: " << extruder << "  day: " << day << endl;

                if(_extruderIdleness[extruder][day] <= _problem._setupTime[color][color])
                {
                    time = 0;
                    production = 0;

                    cout << endl << "error: cannot include another batch on this estruder and day ! " << endl;
                }else
                {
                    production = (_extruderIdleness[extruder][day]-_problem._setupTime[color][color])*_problem._productionPerTime[product][extruder];
                    prodLimit = productionLimit(product,day);

                    cout << endl << "production: " << production << "  limit: " << prodLimit << endl;

                    if(production > prodLimit)
                    {
                        production = prodLimit;
                        time = rint(floor(production / _problem._productionPerTime[product][extruder]));
                    }else
                    {
                        time = _extruderIdleness[extruder][day];
                    }

                    cout << endl << "time: " << time << endl;

                    insert({product},extruder,day,time);
                }
            }else
            {
                batch = _batchColorGroup[color][aux];

                cout << endl << "batch:  " << batch << endl;
                include(product, batch);
            }
        }else
        {
            cout << endl << "there is no batch of this color..." << endl;
            cout << endl << "creating a new batch..." << endl;

            extruder = rand()%_problem._NExtruders;
            while(_problem._length[extruder] < _problem._width[product])
            {
                extruder = rand()%_problem._NExtruders;
            }
            day = rand()%_problem._NDays;

            if(_extruderIdleness[extruder][day] <= _problem._setupTime[color][color])
            {
                time = 0;
                production = 0;

                cout << endl << "small ideleness time - cannot include another batch on this estruder !!!" << endl;
            }else
            {
                production = (_extruderIdleness[extruder][day]-_problem._setupTime[color][color])*_problem._productionPerTime[product][extruder];

                prodLimit = productionLimit(product,day);

                if(production < prodLimit)
                {
                    production = prodLimit;
                    time = rint(floor(production / _problem._productionPerTime[product][extruder]));
                }else
                {
                    time = _extruderIdleness[extruder][day];
                }

                insert({product},extruder,day,time);
            }
        }

        newVector.clear();

        //print();
    };

    bool PPPIESolution::include(unsigned int product, unsigned int batch)
    {
        cout << endl << "function: including product on batch..." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        cout << endl << "extruder: " << extruder << "  day: " << day  << endl;

        if(_problem._length[extruder] < _problem._width[product])
        {
            cout << endl << "error: product cannot be allocated on this extruder !" << endl;
            getchar();
            return 1;
        }else
        {
            unsigned int time, diff;
            unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];
            unsigned int prodLimit = productionLimit(product,day);

            cout << endl << "production: " << production << "  limit: " << prodLimit << endl;

            if(production > prodLimit)
            {
                production = prodLimit;
                time = rint(floor(production / _problem._productionPerTime[product][extruder]));
                diff = _processingTime[batch] - time;

                cout << endl << "production: " << production << "  time: " << time << "  diff: " << diff << endl;

                if(split(batch, time) == 1) processingTime(batch, time);
            }

            while(_batchIdleness[batch] < _problem._width[product])
            {
                cout << endl << "idleness: "<< _batchIdleness[batch] << "  width: " << _problem._width[product] << endl;
                randomErase(batch);
            }

            return insert(product, batch);
        }
    };

    void PPPIESolution::randomErase(unsigned int batch)
    {
        cout << endl << "function: random exclusion... " << endl;

        if(_allocation[batch].size() <= 3)
        {
            cout << endl << "info: no product on this batch. " << endl;
        }else
        {
            // choosing a product in the batch

            unsigned int start = _allocation[batch][2];
            unsigned int finish = _allocation[batch][3];

            cout << endl << "start: " << start << "  end: " << finish << endl;

            unsigned int location;

            if(start == finish)
            {
                cout << endl << "info: only one product on this batch. " << endl;
                location = start;
            }else
            {
                cout << endl << "number of products on this batch: " << finish - start + 1 << endl;
                location = start + rand()%(finish - start + 1);
            }

            erase(location);
        }
    };

    void PPPIESolution::erase(unsigned int location)
    {
        cout << endl << "function: erasing product on batch... " << endl;

        unsigned int batch = _balancing[location][0];

        cout << endl << "location: "<< location << "   batch: " << batch << endl;

        if(location >= _balancing.size())
        {
            cout << endl << "error: _ballancing[" << batch << "] do not have element " << location << " !" << endl;
        }else
        {
            if(_allocation[batch][2] < _allocation[batch][3])
            {
                _allocation[batch][3] -= 1;
                cout << endl << "new last batch index: " << _allocation[batch][3] << endl;
            }

            cout << endl << "info: reorganizing other batches first and last indexes." << endl;

            for(unsigned int b=batch+1; b<_allocation.size(); b++)
            {
                cout << endl << "batch: " << b;
                _allocation[b][2] -= 1;
                cout << "  new first batch index: " << _allocation[b][2];

                _allocation[b][3] -= 1;
                cout << "  new last batch index: " << _allocation[b][3] << endl;
            }

            unsigned int product = _balancing[location][1];

            cout << endl << "product being excluded: " << product << endl;

            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            cout << endl << "batch extruder: " << extruder << "   batch day: " << day << endl;

            // adjusting _balancing

            _balancing.erase(_balancing.begin()+location);

            _batchWidth[batch] -= _problem._width[product];

            cout << endl << "batch width reduced to: " << _batchWidth[batch] << endl;

            _batchIdleness[batch] += _problem._width[product];

            cout << endl << "batch idleness augmented to: " << _batchIdleness[batch] << endl;

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int production = _processingTime[batch]*_problem._productionPerTime[product][extruder];

                cout << endl << "production being reduced: " << production << "." << endl;

                if(production > 0)
                {
                    reduce(production, product, day);
                }
            }
        }
    };

    bool PPPIESolution::split(unsigned int batch, unsigned int time)
    {
        cout << endl << "function: spliting batch... " << endl;

        cout << endl << "info: calculating setup time." << endl;

        vector<unsigned int> pList;
        pList.clear();
        pList = productList(batch);

        cout << endl << "pList: ";

        for(unsigned int s=0; s<pList.size(); s++)
        {
            cout << pList[s] << "  ";
        }

        cout << endl;

        unsigned int product, color, prevColor;

        color = _allocation[batch][4];

        cout << endl << "color: " << color << endl;

        if(_balancing.size() >= 1)
        {
            product = _balancing.back()[1];
            cout << endl << "last product: " << product << endl;

            prevColor = _problem._color[product];
        }else
        {
            prevColor = color;
        }

        cout << endl << "previous color: " << prevColor << endl;

        if(_processingTime[batch] <= time + _problem._setupTime[prevColor][color])
        {
            cout << endl << "error: batch processing time cannot be splitted !" << endl;
            cout << endl << "info: batch will not be splited." << endl;
            getchar();
            return 1;
        }

        unsigned int timeNewBatch = _processingTime[batch] - time - _problem._setupTime[prevColor][color];

        cout << endl << "info: reducing processing time of batch to: " << time << endl;
        processingTime(batch, time);
        //print();

        // generating another batch

        cout << endl << "info: generating another batch." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        cout << endl << "extruder: " << extruder << "  day: " << day << endl;

        cout << endl << "creating a new batch with the remaining time: " << timeNewBatch << endl;

        insert(pList, extruder, day, timeNewBatch);

        //print();

        return 0;
    };

    void PPPIESolution::processingTime(unsigned int batch, unsigned int time)
    {
        cout << endl << "function: changing batch processing time and linked variables... " << endl;

        if(time == _processingTime[batch])
        {
            cout << endl << "info: no change in bach time." << endl;
        }else
        {
            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            if(_allocation[batch].size()<=3)
            {
                cout << endl << "info: bach is empty." << endl;
            }else
            {
                unsigned int product, production, prodLimit;

                for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
                {
                    product = _balancing[s][1];

                    cout << endl << "product: " << product << endl;

                    if(time < _processingTime[batch])
                    {
                        production = (_processingTime[batch]-time)*_problem._productionPerTime[product][extruder];

                        cout << endl << "production reduction: " << production << endl;
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

                        cout << endl << "production encrease: " << production << endl;
                        increase(production, product, day);
                    }
                }
            }

            cout << endl << "time: " << time << "  extruder: " << extruder << "  day: " << day << endl;

            _extruderProcTime[extruder][day] -= _processingTime[batch] - time;
            _extruderIdleness[extruder][day] += _processingTime[batch] - time;
            _processingTime[batch] = time;

            cout << endl << "time: " << time << " extruder time: " << _extruderProcTime[extruder][day] << " and idleness: "
                << _extruderIdleness[extruder][day] << "." << endl;
        }
    };

    vector<unsigned int> PPPIESolution::productList(unsigned int batch)
    {
        unsigned int product;
        vector<unsigned int> productList;
        productList.clear();

        unsigned int start = _allocation[batch][2];
        unsigned int finish = _allocation[batch][3];

        cout << endl << "start: " << start << "  finish: " << finish << endl;

        if( start >= _balancing.size() || _balancing[start][0] != batch)
        {
            cout << endl << "this batch is empty !" << endl;
        }else
        {
            for(unsigned int s=start; s<=finish; s++)
            {
                product = _balancing[s][1];
                productList.push_back(product);
            }
        }

        cout << endl << "product list: ";
        for(unsigned int s=0; s<productList.size();s++)
        {
            cout << productList[s] << "\t";
        }

        return productList;
    };

    bool PPPIESolution::insert(unsigned int product, unsigned int batch)
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

    void PPPIESolution::particleCollision(unsigned int NMaxIte, unsigned int NMaxIteSA)
    {
        cout << endl << "function: particle collision" << endl;

        PPPIESolution solution;
        PPPIESolution bestSolution = autoCopy();

        float probality = 0, aux = 0;

        _problem.print();
        print();
        cout << endl << "problem and initial solution in PCA." << endl;
        getchar();

        for(unsigned int ite=0; ite<NMaxIte; ite++)
        {
            cout << endl << "iteration: " << ite << endl;

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

                timeSimultedAnnealing(1);

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

                    timeSimultedAnnealing(NMaxIteSA);

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
        }

        set(bestSolution);
        cout << endl << "info: final PCA solution." << endl;
        print();
        getchar();

        solution.clear();
        bestSolution.clear();
    };

    bool PPPIESolution::clean(unsigned int cleanType)
    {
        cout << endl << "function: cleaning." << endl;

        unsigned int color,prevColor,setup,location,extruder,day;

        if(cleanType == 1)
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

                    _processingTime.erase(_processingTime.begin()+b);

                    // claring batch and linked variables

                    for(unsigned int i=_allocation[b][3]+1; i<_balancing.size(); i++)
                    {
                        _balancing[i][0] -= 1;
                    }

                    cout << endl << "balancing: " << endl;
                    for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    cout << endl;

                    for(unsigned int p=_allocation[b][3]; p>=_allocation[b][2]; p--)
                    {
                        cout << endl << p << endl;

                        if(p == 0)
                        {
                            cout << endl << "p = 0" << endl;
                            _balancing.erase(_balancing.begin());
                        }else
                        {
                            _balancing.erase(_balancing.begin()+p);
                        }
                    }

                    cout << endl;
                    for(unsigned int i=0; i<_balancing.size(); i++)
                    {
                        cout << endl << i << endl;
                        cout << endl << _balancing[i][0] << "  " << _balancing[i][1];
                    }
                    cout << endl;

                    for(unsigned int i=b+1; i<_allocation.size(); i++)
                    {
                        cout << endl << i << "first: " << _allocation[i][2] << "  last: " << _allocation[i][3] << endl;
                        _allocation[i][2] -= _allocation[b][3] - _allocation[b][2] + 1;
                        _allocation[i][3] -= _allocation[b][3] - _allocation[b][2] + 1;
                        cout << endl << i << "new first: " << _allocation[i][2] << "  new last: " << _allocation[i][3] << endl;
                    }

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

                    _allocation.erase(_allocation.begin()+b);
                    _batchWidth.erase(_batchWidth.begin()+b);
                    _batchIdleness.erase(_batchIdleness.begin()+b);
                    b--;
                }
            }
        }else if(cleanType == 2)
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

    unsigned int PPPIESolution::find(vector<unsigned int> UIVector, unsigned int value)
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
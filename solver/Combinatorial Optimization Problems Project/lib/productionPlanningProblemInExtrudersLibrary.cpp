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

    void PPPIESolution::clearSolution()
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
            _productionLimit[p].clear();
        }
        _inventory.clear();
        _freeInventory.clear();
        _productionLimit.clear();

        _totalFreeInventory.clear();
    };

    void PPPIESolution::restartSolution(PPPIEInstance problem)
    {
        clearSolution();

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

        _productionLimit.resize(problem._NProducts);
        for(unsigned int p=0; p<_productionLimit.size(); p++)
        {
           _productionLimit[p].resize(problem._NDays,0);
        }

        for(unsigned int p=0; p<problem._NProducts; p++)
        {
            for(unsigned int d=0; d<problem._NDays; d++)
            {
                _productionLimit[p][d] += _freeInventory[p][d] + _unmetDemand[p][d];

                for(unsigned int o=0; o<problem._NOutlets; o++)
                {
                    _productionLimit[p][d] += _freeOutletInventory[p][o];
                }
            }
        }

        print();
    };

    void PPPIESolution::print()
    {
        cout << endl << endl << "SOLUTION" << endl;

        cout << endl << "fitness: " << _fitness << endl;
        cout << endl << "production total profit: " << _productionTotalProfit << endl;
        cout << endl << "unmet demand total cost: " << _unmetDemandTotalCost  << endl;
        cout << endl << "inventory total cost: " << _inventoryTotalCost<< endl;

        cout << endl << "balancing [batch, product]: ";
        cout << endl << endl;
        for(unsigned int i=0; i<_balancing.size(); i++)
        {
            for(unsigned int j=0; j<_balancing[i].size(); j++)
            {
                cout << _balancing[i][j] << "\t";
            }
            cout << endl;
        }

        cout << endl << "allocation [batch, extruder, day, iterator ref, iterator ref]: ";
        cout << endl << endl;
        for(unsigned int b=0; b<_allocation.size(); b++)
        {
            for(unsigned int i=0; i<_allocation[b].size(); i++)
            {
                cout << _allocation[b][i] << "\t";
            }
            cout << endl;
        }

        cout << endl << "processing time [batch]: "<< endl << endl;

        for(unsigned int b=0; b<_processingTime.size() ; b++)
        {
            cout << _processingTime[b] << endl;
        }
        cout << endl;

        cout << "batch width (m) [batch]: "<< endl << endl;

        for(unsigned int b=0; b<_batchWidth.size() ; b++)
        {
            cout << _batchWidth[b] << endl;
        }
        cout << endl;

        cout << "batch idleness (m) [batch]: "<< endl << endl;
        for(unsigned int b=0; b<_batchIdleness.size(); b++)
        {
            cout << _batchIdleness[b] << endl;
        }
        cout << endl;

        cout << "extruder processing time (min) [extruder, day]: " << endl;
        cout << endl;
        for(unsigned int e=0; e<_extruderProcTime.size(); e++)
        {
            for(unsigned int d=0; d<_extruderProcTime[e].size(); d++)
            {
                cout << _extruderProcTime[e][d] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "extruder idleness (min) [extruder, day]: "<< endl;
        cout << endl;
        for(unsigned int e=0; e<_extruderIdleness.size(); e++)
        {
            for(unsigned int d=0; d<_extruderIdleness[e].size(); d++)
            {
                cout << _extruderIdleness[e][d] << "\t";
            }
            cout << endl;
        }

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

        cout << endl;
        cout << "production (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_production.size(); p++)
        {
            for(unsigned int d=0; d<_production[p].size(); d++)
            {
                cout << _production[p][d] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "delivered (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            for(unsigned int d=0; d<_delivered[p].size(); d++)
            {
                cout << _delivered[p][d] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "unmet demand (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            for(unsigned int d=0; d<_unmetDemand[p].size(); d++)
            {
                cout << _unmetDemand[p][d] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "delivered to outlet (g) [product, outlet, day]: "<< endl << endl;
        for(unsigned int p=0; p<_deliveredToOutlet.size(); p++)
        {
            for(unsigned int o=0; o<_deliveredToOutlet[p].size(); o++)
            {
                for(unsigned int d=0; d<_deliveredToOutlet[p][o].size(); d++)
                {
                    cout << _deliveredToOutlet[p][o][d] << "\t";
                }
                cout << "\t\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "free outlet inventory (g) [outlet]: "<< endl;
        cout << endl;
        for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
        {
            cout << _totalFreeOutletInventory[o] << "\t";
        }
        cout << endl;

        cout << endl;
        cout << "free outlet inventory per product (g) [product, outlet]: "<< endl;
        cout << endl;
        for(unsigned int p=0; p<_freeOutletInventory.size(); p++)
        {
            for(unsigned int o=0; o<_freeOutletInventory[p].size(); o++)
            {
                cout << _freeOutletInventory[p][o] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "inventory (g) [product, day]: "<< endl;
        cout << endl;
        for(unsigned int p=0; p<_inventory.size(); p++)
        {
            for(unsigned int d=0; d<_inventory[p].size(); d++)
            {
                cout << _inventory[p][d] << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "total free inventory (g) [day]: "<< endl;
        cout << endl;
        for(unsigned int d=0; d< _totalFreeInventory.size(); d++)
        {
            cout <<  _totalFreeInventory[d] << "\t";
        }
        cout << endl << endl;

        cout << "free inventory (g) [product, day]: "<< endl;
        cout << endl;
        for(unsigned int p=0; p<_freeInventory.size(); p++)
        {
            for(unsigned int d=0; d<_freeInventory[p].size(); d++)
            {
                cout << _freeInventory[p][d] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        cout << "production limit (g) [product]: " << endl <<  endl;

        for(unsigned int p=0; p<_productionLimit.size(); p++)
        {
            for(unsigned int d=0; d<_productionLimit[p].size(); d++)
            {
                cout << _productionLimit[p][d]  << "\t";
            }
            cout << endl;
        }
        cout << endl;

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

    //getchar();

    };

    void PPPIESolution::generateSolution(PPPIEInstance problem)
    {
        restartSolution(problem);

        cout << endl << "generating a new solution... " << endl;

        unsigned int setup = problem._setupTime[0][0];

        for(unsigned int i=0; i<problem._setupTime.size(); i++)
        {
            for(unsigned int j=0; j<problem._setupTime[i].size(); j++)
            {
                if(problem._setupTime[i][j] > setup)
                {
                    setup = problem._setupTime[i][j];
                }
            }
        }

        unsigned int totalCapacity = 0;

        for(unsigned int e=0; e<problem._NExtruders; e++)
        {
            for(unsigned int d=0; d<problem._NDays; d++)
            {
                totalCapacity = totalCapacity + problem._capacity[e][d];
            }
        }

        unsigned int batchTime = rint(totalCapacity / problem._NProducts) - setup;

        cout << endl << "batch time: " << batchTime << endl;

        bool stop;
        unsigned int day = 0;
        unsigned int extruder = 0;
        unsigned int production = 0, prodLimit = 0;
        unsigned int time = 0;
        vector<unsigned int> newVector, productList;

        for(unsigned int p=0; p<problem._NProducts; p++)
        {
            cout << endl << "product: " << p << endl;

            extruder = problem._NExtruders;
            day = 0;
            time = 0;
            stop = 0;

            for(unsigned int e=0; e<problem._NExtruders; e++)
            {
                if(problem._width[p] <= problem._length[e])
                {
                    cout << endl << "width ok";
                    extruder = e;

                    for(unsigned int d=0; d<problem._NDays; d++)
                    {
                        production = batchTime*problem._productionPerTime[p][e];

                        prodLimit = productionLimit(problem,p,d);

                        if(production <= prodLimit)
                        {
                            time = batchTime;
                        }else
                        {
                            cout << endl << "inventory problem !!!";
                            cout << endl << "production reduced...";
                            production = prodLimit;
                            time = rint(floor(production / problem._productionPerTime[p][e]));
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

            if (extruder < problem._NExtruders)
            {
                productList.clear();
                productList.push_back(p);

                include(problem, productList, extruder, day, time);
            }else
            {
                cout << endl << "Product " << p << " cannot be allocated cause its width is very large for extruders !!!" << endl;
            }
        }

        cout << endl << totalCapacity << "  " << batchTime;
        newVector.clear();
        print();
        getchar();
    };

    unsigned int PPPIESolution::productionLimit(PPPIEInstance problem, unsigned int product, unsigned int day)
    {
        unsigned int prodLimit;

        if(_totalFreeInventory[day] >= _freeInventory[product][day])
        {
            prodLimit = _productionLimit[product][day];
        }else
        {
            cout << endl << "info: total inventory problem - production limit reduced..." << endl;
            prodLimit =  _productionLimit[product][day] + _totalFreeInventory[day] - _freeInventory[product][day];
        }

        for(unsigned int o=0; o<problem._NOutlets; o++)
        {
            if(_totalFreeOutletInventory[o] < _freeOutletInventory[product][o])
            {
                prodLimit += _totalFreeOutletInventory[o] - _freeOutletInventory[product][o];
            }
        }

        return prodLimit;
    };

    void PPPIESolution::include(PPPIEInstance problem, vector<unsigned int> productList, unsigned int extruder, unsigned int day, unsigned int time)
    {
        unsigned int batch = _allocation.size();
        float width = 0;
        unsigned int product, color1, color2;

        cout << endl << "including new batch: " << batch << endl;

        vector <unsigned int> newVector;

        if(_balancing.size() >= 1)
        {
            newVector = _balancing.back();
            product = newVector[1];
            color1 = problem._color[product];
            product = productList[0];
            color2 = problem._color[product];
        }else
        {
            product = productList[0];
            color2 = problem._color[product];
            color1 = color2;
        }

        if(_extruderIdleness[extruder][day] < time + problem._setupTime[color1][color2])
        {
            cout << endl << "cannot create this batch on this extruder - idleness time must be grater than or equal to the time of batch + setup time !" << endl;
        }else
        {
            // adjusting variables

            for(unsigned int i=0; i<productList.size(); i++)
            {
                product = productList[i];
                newVector.clear();
                _batchColorGroup[problem._color[product]].push_back(batch);
                newVector = {batch,product};
                _balancing.push_back(newVector);
                width += problem._width[product];

                cout << endl << "product: "<< product << " width: " << problem._width[product] << endl;
            }

            _batchWidth.push_back(width);
            _batchIdleness.push_back(problem._length[extruder] - width);

            newVector.clear();
            newVector = {extruder,day,batch,batch};
            _allocation.push_back(newVector);

            _processingTime.push_back(time);
            _extruderProcTime[extruder][day] += time + problem._setupTime[color1][color2];
            _extruderIdleness[extruder][day] -= time + problem._setupTime[color1][color2];

            if(time > 0)
            {
                unsigned int production;

                for(unsigned int i=0; i<productList.size(); i++)
                {
                    product = productList[i];

                    production = time*problem._productionPerTime[product][extruder];

                    cout << endl << "product: " << product << "  production: " << production << endl;

                    include(problem, production, product, day);
                }
            }
        }

        newVector.clear();
    };

    void PPPIESolution::include(PPPIEInstance problem, unsigned int production, unsigned int product, unsigned int day)
    {
        unsigned int diff, reduction, aux;

        diff = production;
        for(unsigned int d=day; d<problem._NDays; d++)
        {
            cout << endl << "_unmetDemand[" << product << "][" << d << "]: " << _unmetDemand[product][d] << endl;

            reduction = 0;
            if(_unmetDemand[product][d] > 0)
            {
                if(diff <= _unmetDemand[product][d])
                {
                    reduction = diff;
                }else
                {
                    reduction = _unmetDemand[product][d];
                }

                _delivered[product][d] += reduction;
                _unmetDemand[product][d] -= reduction;

                _unmetDemandTotalCost -=reduction*problem._unmetDemandCost;

                cout << endl << "production going to demand: " << reduction << endl;

                for(unsigned int k=d+1; k<problem._NDays; k++)
                {
                    if(_unmetDemand[product][k] >= reduction)
                    {
                        _unmetDemand[product][k] -= reduction;
                        _unmetDemandTotalCost -=reduction*problem._unmetDemandCost;
                        aux = 0;
                    }else
                    {
                        cout << endl << "redistributing exceded delivered: " << aux << endl;
                        _unmetDemand[product][k] = 0;
                        _unmetDemandTotalCost -=_unmetDemand[product][k]*problem._unmetDemandCost;
                        aux = reduction - _unmetDemand[product][k];
                        _delivered[product][k] -= aux;

                        for(unsigned int l=k+1; l<problem._NDays; l++)
                        {
                            _unmetDemand[product][l] += aux;
                            _unmetDemandTotalCost +=aux*problem._unmetDemandCost;
                        }

                        for(unsigned int o=0; o<problem._NOutlets; o++)
                        {
                            cout << endl << "going to outlet: " << o << endl;
                            if(aux <= _freeOutletInventory[product][o] && aux <= _totalFreeOutletInventory[o])
                            {
                                _deliveredToOutlet[product][o][k] += aux;
                                _freeOutletInventory[product][o] -= aux;
                                _totalFreeOutletInventory[o] -= aux;
                                aux = 0;
                                break;
                            }else
                            {
                                if(_freeOutletInventory[product][o] <= _totalFreeOutletInventory[o])
                                {
                                    _deliveredToOutlet[product][o][k] += _freeOutletInventory[product][o];
                                    _freeOutletInventory[product][o] -=  _freeOutletInventory[product][o];
                                    _totalFreeOutletInventory[o] -= _freeOutletInventory[product][o];
                                    aux -= _freeOutletInventory[product][o];
                                }else
                                {
                                    _deliveredToOutlet[product][o][k] += _totalFreeOutletInventory[o];
                                    _freeOutletInventory[product][o] -= _totalFreeOutletInventory[o];
                                    _totalFreeOutletInventory[o] -= _totalFreeOutletInventory[o];
                                    aux -= _totalFreeOutletInventory[o];
                                }
                            }
                        }

                        if(aux > 0)
                        {
                            cout << endl << "going toinventory: " << aux << endl;
                            for(unsigned int l=k; l<problem._NDays; l++)
                            {
                                if(aux > _totalFreeInventory[l])
                                {
                                    cout << endl << "maximum inventory on day " << d << " broken !!! " << endl;
                                }

                                if(aux > _freeInventory[product][l])
                                {
                                    cout << endl << "maximum inventory of product " << product << " on day " << d << " broken !!! " << endl;
                                }

                                    _inventory[product][l] += aux;
                                    _totalFreeInventory[l] -= aux;
                                    _freeInventory[product][l] -= aux;
                                    _inventoryTotalCost += aux*problem._inventoryUnitCost;
                                }
                            }
                        }
                    }
                }

                diff -= reduction;

                if(diff > 0)
                {
                    cout << endl << "adjusting inventory: " << _inventory[product][d] << endl;
                    _inventory[product][d] += diff;
                    _totalFreeInventory[d] -= diff;
                    _freeInventory[product][d] -= diff;
                    _inventoryTotalCost += diff*problem._inventoryUnitCost;
                    cout << endl << "inventory: " << _inventory[product][d] << endl;
                }

                if(diff == 0)
                {
                    break;
                }
            }

            if(diff > 0)
            {
                for(unsigned int o=0; o<problem._NOutlets; o++)
                {
                    if(diff <= _totalFreeOutletInventory[o] && diff <= _freeOutletInventory[product][o])
                    {
                        aux = diff;
                    }else
                    {
                        if(_totalFreeOutletInventory[o] <= _freeOutletInventory[product][o])
                        {
                            aux = _totalFreeOutletInventory[o];
                        }else
                        {
                            aux = _freeOutletInventory[product][o];
                        }
                    }

                cout << endl << "production going to outlet: " << aux << endl;

                _deliveredToOutlet[product][o][day] += aux;
                _totalFreeOutletInventory[o] -= aux;
                _freeOutletInventory[product][o] -= aux;

                for(unsigned int d=day; d<problem._NDays; d++)
                {
                    cout << endl << "adjusting inventory: " << _inventory[product][d] << endl;
                    _inventory[product][d] -= aux;
                    _totalFreeInventory[d] += aux;
                    _freeInventory[product][d] += aux;
                    _inventoryTotalCost -= aux*problem._inventoryUnitCost;
                    cout << endl << "inventory: " << _inventory[product][d] << endl;
                }

                diff -= aux;

                if(diff == 0)
                {
                    break;
                }
            }
        }

        _production[product][day] += production;
        _productionTotalProfit += production*problem._unitContribution[product];

        for(unsigned int d=day; d<problem._NDays; d++)
        {
            _productionLimit[product][d] -= production;
        }

        for(unsigned int d=day; d>0; d--)
        {
            if(_productionLimit[product][d-1] > _productionLimit[product][d])
            {
                _productionLimit[product][d-1] = _productionLimit[product][d];
            }
        }

         _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

         print();
    };

    void PPPIESolution::timeSimultedAnnealing(PPPIEInstance problem, unsigned int NMaxIte)
    {
        cout << endl << " Simulated Annealing... " << endl;
        srand((unsigned) time(NULL));

        unsigned int itCount = 0;
        float probality = 0, aux = 0;

        PPPIESolution solution = autoCopy();
        PPPIESolution bestSolution = autoCopy();

        cout << endl << " solution: " << endl;
        solution.print();

        while (itCount < NMaxIte)
        {
            cout << endl << "iteration: " << itCount << endl;
            itCount ++;
            solution.swapTime(problem);
            cout << endl << "best fitness: " << _fitness << "  solution fitness: " << solution._fitness << endl;

            if(solution._fitness > _fitness)
            {
                if(solution._fitness > bestSolution._fitness)
                {
                    cout << endl << "found a better solution..." << endl;
                    bestSolution.set(solution);
                }

                cout << endl << "solution improved..." << endl;
                set(solution);
                print();
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
                    print();
                }
            }
        }

        set(bestSolution);
        print();
        getchar();
    };

    PPPIESolution PPPIESolution::autoCopy()
    {
        PPPIESolution solution;

        solution._balancing = _balancing;
        solution._allocation = _allocation;
        solution._processingTime = _processingTime;
        solution._batchWidth = _batchWidth;
        solution._batchIdleness = _batchIdleness;
        solution._extruderProcTime = _extruderProcTime;
        solution._extruderIdleness = _extruderIdleness;
        solution._restricted = _restricted;
        solution._productionLimit = _productionLimit;
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

        return solution;
    };

    void PPPIESolution::set(PPPIESolution solution)
    {
        _balancing = solution._balancing;
        _allocation = solution._allocation;
        _processingTime = solution._processingTime;
        _batchWidth = solution._batchWidth;
        _batchIdleness = solution._batchIdleness;
        _extruderProcTime = solution._extruderProcTime ;
        _extruderIdleness = solution._extruderIdleness;
        _restricted = solution._restricted ;
        _productionLimit = solution._productionLimit;
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
    };

    void PPPIESolution::swapTime(PPPIEInstance problem)
    {
        cout << endl << "function: swaping time...  " << endl << endl;

        unsigned int batch = rand()%_allocation.size();
        cout << endl << "batch:  " << batch << endl;

        unsigned int extruder = _allocation[batch][0];
        cout << endl << "extruder:  " << extruder << endl;

        unsigned int day = _allocation[batch][1];
        cout << endl << "day:  " << day << endl;

        unsigned int productionLimit;

        int step;
        bool restricted = 0;

        if(_extruderIdleness[extruder][day] < 1)
        {
            step = -1;
            if(_processingTime[batch] < 1)
            {
                restricted = 1;
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

        if(restricted == 0)
        {
            _processingTime[batch] += step;
            _extruderProcTime[extruder][day] += step;
            _extruderIdleness[extruder][day] -= step;

            unsigned int product;
            unsigned int productionVariation;

            for(unsigned int b=0; b<_balancing.size(); b++)
            {
                if(_balancing[b][0] == batch)
                {
                    product = _balancing[b][1];
                    cout << endl << "product: " << product << endl;

                    productionVariation = problem._productionPerTime[product][extruder];

                    cout << endl << "production variation: " << productionVariation << endl;


                    if(_totalFreeInventory[day] >= _freeInventory[product][day])
                    {
                        productionLimit = _productionLimit[product][day];
                    }else
                    {
                        cout << endl << "total inventory problem !!!";
                        cout << endl << "production limit reduced...";
                        productionLimit =  _productionLimit[product][day] + _totalFreeInventory[day] - _freeInventory[product][day];
                    }

                    for(unsigned int o=0; o<problem._NOutlets; o++)
                    {
                        if(_totalFreeOutletInventory[o] < _freeOutletInventory[product][o])
                        {
                            productionLimit += _totalFreeOutletInventory[o] - _freeOutletInventory[product][o];
                            cout << endl << "outlet inventory problem !!!";
                            cout << endl << "production limit reduced...";
                        }
                    }

                    if(step == 1)
                    {
                        if(productionVariation > productionLimit)
                        {
                            restricted = 0;
                            cout << endl << "restricted" << endl;
                        }else
                        {
                            include(problem, productionVariation, product, day);
                        }
                    }else
                    {
                        reduction(problem, productionVariation, product, day);
                    }
                }
            }
        }else
        {
            cout << endl << "restricted" << endl;
        }
    };

    void PPPIESolution::reduction(PPPIEInstance problem, unsigned int production, unsigned int product, unsigned int day)
    {
        cout << endl << "function: reducing production and adjusting linked variables..." << endl;

        unsigned int reduction = production, r, aux;

        if(_inventory[product][day] >= reduction)
        {
            r = reduction;
        }else
        {
            r = _inventory[product][day];
        }

        for(unsigned int d=day+1; d<problem._NDays; d++)
        {
            if(_inventory[product][d] < r)
            {
                r = _inventory[product][d];
            }
        }

        if(r > 0)
        {
            for(unsigned int d=day; d<problem._NDays; d++)
            {
                _inventory[product][d] -= r;
                _freeInventory[product][d] += r;
                _totalFreeInventory[d] += r;
                _inventoryTotalCost -= r*problem._inventoryUnitCost;
            }

            reduction -= r;
        }

        if(reduction > 0)
        {
            for(unsigned int o=0; o<problem._NOutlets; o++)
            {
                if(_deliveredToOutlet[product][o][day] > 0)
                {
                    if(_deliveredToOutlet[product][o][day] >= reduction)
                    {
                        r = reduction;
                    }else
                    {
                        r = _deliveredToOutlet[product][o][day];
                    }

                    _deliveredToOutlet[product][o][day] -= r;
                    _freeOutletInventory[product][o] += r;
                    _totalFreeOutletInventory[o] += r;

                    reduction -= r;
                }

                if(reduction == 0) break;
            }
        }

        aux = problem._initialInventory[product];
        cout << endl << "initial inventory: " << aux << endl;

        for(unsigned int d=day; d<problem._NDays; d++)
        {
            cout << endl << "reduction: " << reduction << endl;
            cout << endl << "inventory: " << aux << endl;
            if(reduction > 0)
            {
                if(_delivered[product][d] >= reduction)
                {
                    r = reduction;
                }else
                {
                    r = _delivered[product][d];
                }

                cout << endl << "reduction: " << r << endl;

                if(d!=(problem._NDays-1))
                {
                    if(aux <= problem._demand[product][d])
                    {
                        if(aux <= r)
                        {
                            r -= aux;
                            aux = 0;
                        }else
                        {
                            r = 0;
                            aux -= r;
                        }

                    }else
                    {
                        if(problem._demand[product][d] <= r)
                        {
                            r -= problem._demand[product][d];
                            aux -= problem._demand[product][d];
                        }else
                        {
                            r = 0;
                            aux -= r;
                        }
                    }
                }

                cout << endl << "reduction: " << r << endl;

                _delivered[product][d] -= r;

                for(unsigned int d=day; d<problem._NDays;d++)
                {
                    _unmetDemand[product][d] += r;
                    _unmetDemandTotalCost += r*problem._unmetDemandCost;
                }

                for(unsigned int l=day; l<d; l++)
                {
                    cout << endl << "inventory: " << _inventory[product][l] << endl;
                    _inventory[product][l] -= r;
                    _freeInventory[product][l] += r;
                    _totalFreeInventory[l] += r;
                    _inventoryTotalCost -= r*problem._inventoryUnitCost;
                }

                reduction -= r;
                cout << endl << "reduction: " << reduction << endl;
            }

            if(reduction == 0) break;
        }

        _production[product][day] -= production;
        _productionTotalProfit -= production*problem._unitContribution[product];

        for(unsigned int d=day; d<problem._NDays; d++)
        {
            _productionLimit[product][d] += production;
        }

        for(unsigned int d=0; d<day; d++)
        {
            _productionLimit[product][d] = _freeInventory[product][d] + _unmetDemand[product][day];

            for(unsigned int o=0; o<problem._NOutlets; o++)
            {
                _productionLimit[product][d] += _freeOutletInventory[product][o];
            }
        }

        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost;

         print();
    };

    void PPPIESolution::swapProduct(PPPIEInstance problem)
    {
        cout << endl << "function: adding a new product on batch... " << endl << endl;

        unsigned int aux, batch, extruder = 0, day = 0, time = 0, production, prodLimit;
        vector <unsigned int> newVector;

        //unsigned int product = rand()%problem._NProducts;
        unsigned int product = 3;
        cout << endl << "product:  " << product << endl;

        unsigned int color = problem._color[product];

        cout << endl << "color:  " << color << endl;

        if(problem._productColorGroup[color].size() == 1)
        {
            cout << endl << "there is only one product of this color..." << endl;
        }

        if(_batchColorGroup[color].size() > 0)
        {
            //aux = rand()%(_batchColorGroup[color].size()+1);
            aux = 2;
            if(aux == _batchColorGroup[color].size())
            {
                extruder = rand()%problem._NExtruders;
                while(problem._length[extruder] < problem._width[product])
                {
                    extruder = rand()%problem._NExtruders;
                }
                day = rand()%problem._NDays;

                cout << endl << "extruder: " << extruder << "  day: " << day << endl;

                if(_extruderIdleness[extruder][day] <= problem._setupTime[color][color])
                {
                    time = 0;
                    production = 0;

                    cout << endl << "error: cannot include another batch on this estruder and day ! " << endl;
                }else
                {
                    production = (_extruderIdleness[extruder][day]-problem._setupTime[color][color])*problem._productionPerTime[product][extruder];
                    prodLimit = productionLimit(problem,product,day);

                    cout << endl << "production: " << production << "  limit: " << prodLimit << endl;

                    if(production > prodLimit)
                    {
                        production = prodLimit;
                        time = rint(floor(production / problem._productionPerTime[product][extruder]));
                    }else
                    {
                        time = _extruderIdleness[extruder][day];
                    }

                    cout << endl << "time: " << time << endl;

                    include(problem,{product},extruder,day,time);
                }
            }else
            {
                batch = _batchColorGroup[color][aux];

                cout << endl << "batch:  " << batch << endl;
                include(problem, product, batch);
            }
        }else
        {
            cout << endl << "there is no batch of this color..." << endl;
            cout << endl << "creating a new batch..." << endl;

            extruder = rand()%problem._NExtruders;
            while(problem._length[extruder] < problem._width[product])
            {
                extruder = rand()%problem._NExtruders;
            }
            day = rand()%problem._NDays;

            if(_extruderIdleness[extruder][day] <= problem._setupTime[color][color])
            {
                time = 0;
                production = 0;

                cout << endl << "small ideleness time - cannot include another batch on this estruder !!!" << endl;
            }else
            {
                production = (_extruderIdleness[extruder][day]-problem._setupTime[color][color])*problem._productionPerTime[product][extruder];

                prodLimit = productionLimit(problem,product,day);

                if(production < prodLimit)
                {
                    production = prodLimit;
                    time = rint(floor(production / problem._productionPerTime[product][extruder]));
                }else
                {
                    time = _extruderIdleness[extruder][day];
                }

                include(problem,{product},extruder,day,time);
            }
        }

        newVector.clear();

        print();
    };

    void PPPIESolution::include(PPPIEInstance problem, unsigned int product, unsigned int batch)
    {
        cout << endl << "function: including product on batch..." << endl;

        unsigned int extruder = _allocation[batch][0];
        unsigned int day = _allocation[batch][1];

        cout << endl << "extruder: " << extruder << "  day: " << day  << endl;

        if(problem._length[extruder] < problem._width[product])
        {
            cout << endl << "problem cannot be allocated on this extruder..." << endl;
        }else
        {
            unsigned int time, diff;
            unsigned int production = _processingTime[batch]*problem._productionPerTime[product][extruder];
            unsigned int prodLimit = productionLimit(problem,product,day);

            cout << endl << "production: " << production << "  limit: " << prodLimit << endl;

            if(production > prodLimit)
            {
                production = prodLimit;
                time = rint(floor(production / problem._productionPerTime[product][extruder]));
                diff = _processingTime[batch] - time;

                cout << endl << "production: " << production << "  time: " << time << "  diff: " << diff << endl;

                split(problem, batch, time);
            }

            while(_batchIdleness[batch] < (problem._width[product] + 0.0005))
            {
                cout << endl << "idleness: "<< _batchIdleness[batch] << "  width: " << problem._width[product] << endl;
                randomErase(problem, batch);
            }

            insert(problem, product, batch);
        }
    };

    void PPPIESolution::randomErase(PPPIEInstance problem, unsigned int batch)
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
                cout << endl << "number of products on this batch: " << finish - start << endl;
                location = start + rand()%(finish - start);
            }

            erase(problem, location);
        }
    };

    void PPPIESolution::erase(PPPIEInstance problem, unsigned int location)
    {
        cout << endl << "function: erasing product on batch... " << endl;

        unsigned int batch = _balancing[location][0];

        cout << endl << "location: "<< location << "   batch: " << batch << endl;

        if(location >= _balancing.size())
        {
            cout << endl << "error: _ballancing[" << batch << "] do not have element " << location << " !" << endl;
        }else
        {
            if(_allocation[batch][2] == _allocation[batch][3])
            {
                _allocation[batch].erase(_allocation[batch].begin()+3);
                cout << endl << "info: last batch index cleared. " << endl;
            }else
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

                if(_allocation[b].size() >= 4)
                {
                    _allocation[b][3] -= 1;
                    cout << "  new last batch index: " << _allocation[b][3] << endl;
                }
            }

            unsigned int product = _balancing[location][1];

            cout << endl << "product being excluded: " << product << endl;

            unsigned int extruder = _allocation[batch][0];
            unsigned int day = _allocation[batch][1];

            cout << endl << "batch extruder: " << extruder << "   batch day: " << day << endl;

            // adjusting _balancing

            _balancing.erase(_balancing.begin()+location);

            _batchWidth[batch] -= problem._width[product];

            cout << endl << "batch width reduced to: " << _batchWidth[batch] << endl;

            _batchIdleness[batch] += problem._width[product];

            cout << endl << "batch idleness augmented to: " << _batchIdleness[batch] << endl;

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int production = _processingTime[batch]*problem._productionPerTime[product][extruder];

                cout << endl << "production being reduced: " << production << "." << endl;

                if(production > 0)
                {
                    reduction(problem, production, product, day);
                }
            }
        }
    };

    void PPPIESolution::split(PPPIEInstance problem, unsigned int batch, unsigned int time)
    {
        cout << endl << "function: spliting batch... " << endl;
        unsigned int extruder, day, product, color1, color2;
        unsigned int timeNewBatch = _processingTime[batch];
        vector<unsigned int> pList;

        processingTime(problem, batch, time);

        print();
        getchar();

        // generating another batch

        pList.clear();
        pList = productList(batch);

        if(_balancing.size() >= 1)
        {
            product = _balancing.back()[1];
            color1 = problem._color[product];
            if(pList.size()>=1)
            {
                product = pList[0];
            }
            color2 = problem._color[product];
        }else if(pList.size() >= 1)
        {
            if(pList.size()>=1)
            {
                product = pList[0];
                color2 = problem._color[product];
            }else
            {
                color2 = 0;
            }
            color1 = color2;
        }

        extruder = _allocation[batch][0];
        day = _allocation[batch][1];

        include(problem, pList, extruder, day, 0);

        if(_processingTime[batch] > problem._setupTime[color1][color2])
        {
            timeNewBatch -= _processingTime[batch] + problem._setupTime[color1][color2];
            processingTime(problem, batch, timeNewBatch);
        }
    };

    void PPPIESolution::processingTime(PPPIEInstance problem, unsigned int batch, unsigned int time)
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
                        production = (_processingTime[batch]-time)*problem._productionPerTime[product][extruder];

                        cout << endl << "production reduction: " << production << endl;
                        reduction(problem, production, product, day);
                    }else
                    {
                        production = (time-_processingTime[batch])*problem._productionPerTime[product][extruder];

                        prodLimit = productionLimit(problem,product,day);
                        if(production > prodLimit)
                        {
                            time = rint(floor(prodLimit / problem._productionPerTime[product][extruder]));
                            production = time*problem._productionPerTime[product][extruder];
                        }

                        cout << endl << "production encrease: " << production << endl;
                        include(problem, production, product, day);
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

        if(_allocation[batch].size()<=3)
        {
            cout << endl << "this batch is empty !" << endl;
        }else
        {
            for(unsigned int s=_allocation[batch][2]; s<=_allocation[batch][3]; s++)
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

    void PPPIESolution::insert(PPPIEInstance problem, unsigned int product, unsigned int batch)
    {
        cout << endl << "function: inserting a new product on batch... " << endl;

        cout << endl << "batch: " << batch << "  idleness: " << _batchIdleness[batch] << "  product: " << product << "  width: " << problem._width[product] << "." << endl;

        if(_batchIdleness[batch] < problem._width[product])
        {
            cout << endl << "error: batch idleness not enought to insert this product on this batch !" << endl;
        }else
        {
            unsigned int location;

            if(_allocation[batch].size() < 3)
            {
                location = _allocation[batch][2];
                cout << endl << "location: " << location << "." << endl;
            }else
            {
                location = _allocation[batch][3]+1;

                for(unsigned int l=_allocation[batch][3]; l>=_allocation[batch][2]; l--)
                {
                    if(_balancing[l][1] > product)
                    {
                        location = l;
                    }else
                    {
                        break;
                    }
                    cout << endl << "location: " << location << "." << endl;
                }
            }

            cout << endl << "location: " << location << "." << endl;

            _balancing.insert(_balancing.begin()+location,{batch,product});

            _batchWidth[batch] += problem._width[product];

            cout << endl << "batch width augmented to: " << _batchWidth[batch] << "." << endl;

            _batchIdleness[batch] -= problem._width[product];

            cout << endl << "batch idleness reduced to: " << _batchIdleness[batch] << "." << endl;

            cout << endl << "info: reorganizing balancing location indexes. " << endl;

            if(_allocation[batch].size() <= 3)
            {
                _allocation[batch].push_back(_allocation[batch][2] + 1);
            }else
            {
                _allocation[batch][3] += 1;
            }

            cout << "new last batch index: " << _allocation[batch][3] << "." << endl;

            for(unsigned int b=batch+1; b<_allocation.size(); b++)
            {
                cout << endl << "batch: " << b << "\t";
                _allocation[b][2] += 1;

                cout << "new first batch index: " << _allocation[b][2] << "\t";

                if(_allocation[b].size() >= 4)
                {
                    _allocation[b][3] += 1;
                    cout << "new last batch index: " << _allocation[b][3] << "." << endl;
                }
            }

            if(_processingTime[batch] > 0)
            {
                // adjusting production

                unsigned int extruder = _allocation[batch][0];
                unsigned int day = _allocation[batch][1];

                unsigned int production = _processingTime[batch]*problem._productionPerTime[product][extruder];

                cout << endl << "production being encreased: " << production << "." << endl;

                if(production > 0)
                {
                    include(problem, production, product, day);
                }
            }
        }
    };
}

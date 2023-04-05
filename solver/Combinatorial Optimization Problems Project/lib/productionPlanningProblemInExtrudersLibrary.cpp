#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruder::productionPlanningProblemInExtruder(unsigned int NDays, unsigned int NExtruders, vector<float> productionRate, vector<float> length,
    vector<vector<unsigned int>> capacity, float setupCost, float operationCost, unsigned int NProducts, vector<float> width, vector<float> weightRatio,
    vector<float> unitContribution, vector<int> initialInventory, vector<int> maximumInventory, int totalMaximumInventory, float inventoryUnitCost, vector<vector<unsigned int>> demand,
    float unmetDemandCost, vector<unsigned int> color, vector<vector<bool>> colorAndMaterialRatio, vector <vector <unsigned int>> setupTime, unsigned int NOutlets,
    vector<unsigned int> maximumTotalOutletInventory, vector<vector<unsigned int>> maximumOutletInventoryPerProduct)
    {
        clearProblem();

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

        _maximumInventory = maximumInventory;

        if(_maximumInventory.size() != _NProducts)
        {
            cout << " maximum inventory vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumInventory.resize(_NProducts,0);
        }

        _totalMaximumInventory = totalMaximumInventory;
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

        _maximumTotalOutletInventory = maximumTotalOutletInventory;

        if(_maximumTotalOutletInventory.size() != _NOutlets)
        {
            cout << " maximum outlet inventory vector needs to have " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumTotalOutletInventory.resize(_NOutlets,0);
        }

        _maximumOutletInventoryPerProduct = maximumOutletInventoryPerProduct;

        if(_maximumOutletInventoryPerProduct.size() != _NProducts)
        {
            cout << " maximum outlet inventory per product matriz needs to have " << _NProducts << " sets of " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _demand.resize(_NProducts);
        }

        for(unsigned int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            if(_maximumOutletInventoryPerProduct[i].size() != _NOutlets)
            {
                cout << " product " << i + 1 << " vector needs to have " << _NOutlets << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _maximumOutletInventoryPerProduct[i].resize(_NOutlets,0);
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

        _maximumTotalOutletInventory.clear();

        for(unsigned int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            _maximumOutletInventoryPerProduct[i].clear();
        }
        _maximumOutletInventoryPerProduct.clear();
    };

    void productionPlanningProblemInExtruder::printProblem()
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
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "weight ratio (g/m^2) [product]: " << endl << endl;

        for(vector<float>::iterator it = _weightRatio.begin(); it != _weightRatio.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "unit contribution ($) [product]: " << endl << endl;

        for(vector<float>::iterator it = _unitContribution.begin(); it != _unitContribution.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "initial inventory (g) [product]: " << endl << endl;

        for(vector<int>::iterator it = _initialInventory.begin(); it != _initialInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "maximum inventory (g) [product]: " << endl << endl;

        for(vector<int>::iterator it = _maximumInventory.begin(); it != _maximumInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "total maximum inventory (g): " << _totalMaximumInventory << endl << endl;

        cout << "inventory unit cost ($): " << _inventoryUnitCost << endl << endl;

        cout << "demand (g) [product, day]: " << endl << endl;

        for(unsigned int p=0; p<_demand.size(); p++)
        {
            for(unsigned int d=0; d<_demand[p].size(); d++)
            {
                cout << _demand[p][d] << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "unmet demand cost ($): " << _unmetDemandCost << endl << endl;

        cout << "color [product]: " << endl << endl;

        for(vector<unsigned int>::iterator it = _color.begin(); it != _color.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "colour and material rate [product, product]: ";
        cout << endl << endl;

        for(unsigned int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            for(unsigned int s=i; s>0; s--)
            {
                cout << "  ";
            }

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

        cout << "number of outlets: " << _NOutlets << endl << endl;

        cout << "maximum total outlet inventory (g) [outlet]: " << endl << endl;
        for(vector<unsigned int>::iterator it = _maximumTotalOutletInventory.begin(); it != _maximumTotalOutletInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl << endl;

        cout << "maximum outlet inventory per product (g) [product, outlet]: ";
        cout << endl << endl;
        for(unsigned int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            for(unsigned int j=0; j<_maximumOutletInventoryPerProduct[i].size(); j++)
            {
                cout << _maximumOutletInventoryPerProduct[i][j] << " ";
            }
            cout << endl;
        }
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
        _initialInventory = {1000,0,2000,0};
        _maximumInventory = {10000,50000,20000,10000};
        _totalMaximumInventory = 100000;
        _inventoryUnitCost = 0.01;

        _demand = {{99400,73800},{149600,35800},{2000,4000},{3000,0}};
        _unmetDemandCost = 0.5;

        _color = {0,0,0,0};
        _colorAndMaterialRatio= {{1,1,1},{1,1},{1}};

        _setupTime = {{10}};

        _NOutlets = 2;
        _maximumTotalOutletInventory = {30000,20000};

        _maximumOutletInventoryPerProduct = {{1000,1000},{5000,10000},{10000,5000},{5000,500}};
    }

    void PPPIESolution::clearSolution(PPPIEInstance problem)
    {
        _fitness = 0;
        _productionTotalProfit = 0;
        _unmetDemandTotalCost = 0;

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

        _extruderProcTime.resize(problem._NExtruders);
        for(unsigned int i=0; i<_extruderProcTime.size(); i++)
        {
            _extruderProcTime[i].resize(problem._NDays,0);
        }

        for(unsigned int i=0; i<_extruderIdleness.size(); i++)
        {
            _extruderIdleness[i].clear();
        }
        _extruderIdleness.clear();

        _extruderIdleness.resize(problem._NExtruders);
        for(unsigned int i=0; i<_extruderIdleness.size(); i++)
        {
            _extruderIdleness[i].resize(problem._NDays,0);
        }

        for(unsigned int p=0; p<_production.size(); p++)
        {
            _production[p].clear();
        }
        _production.clear();

        _production.resize(problem._NProducts);
        for(unsigned int p=0; p<_production.size(); p++)
        {
            _production[p].resize(problem._NDays,0);
        }

        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            _delivered[p].clear();
        }
        _delivered.clear();

        _delivered.resize(problem._NProducts);
        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            _delivered[p].resize(problem._NDays,0);
        }

        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].clear();
        }
        _unmetDemand.clear();

        _unmetDemand.resize(problem._NProducts);
        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            _unmetDemand[p].resize(problem._NDays,0);
        }

        for(unsigned int i=0; i<_deliveredToOutlet.size(); i++)
        {
            _deliveredToOutlet[i].clear();
        }
        _deliveredToOutlet.clear();

        _totalFreeOutletInventory.clear();

        for(unsigned int p=0; p<_freeOutletInventoryPerProduct.size(); p++)
        {
            _freeOutletInventoryPerProduct[p].clear();
        }
        _freeOutletInventoryPerProduct.clear();

        _freeOutletInventoryPerProduct.resize(problem._NProducts);
        for(unsigned int p=0; p<_freeOutletInventoryPerProduct.size(); p++)
        {
            _freeOutletInventoryPerProduct[p].resize(problem._NOutlets,0);
        }

        for(unsigned int p=0; p<_inventory.size(); p++)
        {
            _inventory[p].clear();
        }
        _inventory.clear();

        _inventory.resize(problem._NProducts);
        for(unsigned int p=0; p<_inventory.size(); p++)
        {
            _inventory[p].resize(problem._NDays,0);
        }

    };

    void PPPIESolution::generateSolution(PPPIEInstance problem)
    {
        clearSolution(problem);

        double totalCapacity = 0;

        for(unsigned int e=0; e<problem._NExtruders; e++)
        {
            for(unsigned int d=0; d<problem._NDays; d++)
            {
                totalCapacity = totalCapacity + problem._capacity[e][d];
            }
        }

        double batchTime = totalCapacity / problem._NProducts;

        unsigned int batch = 0;
        unsigned int day = 0;
        unsigned int extruder = 0;
        double sum = 0;
        vector<unsigned int> newVector;

        unsigned int color1 = problem._color[0];
        unsigned int color2 = color1;

        for(unsigned int p=0; p<problem._NProducts; p++)
        {
            newVector.clear();
            newVector = {p,batch};
            _balancing.push_back(newVector);
            _batchWidth.push_back(problem._width[p]);
            color1 = color2;
            color2 = problem._color[p];

            newVector.clear();
            newVector = {batch,extruder,day};
            _allocation.push_back(newVector);
            _processingTime.push_back(batchTime - problem._setupTime[color1][color2]);


            batch++;

            sum = sum + batchTime;

            if (sum >= problem._capacity[extruder][day])
            {
                _extruderProcTime[extruder][day] = sum;
                if (extruder == problem._NExtruders-1)
                {
                    extruder = 0;
                    day++;
                }else
                {
                    extruder++;
                }
                sum = 0;
            }
        }

        evaluateSolution(problem);

        cout << endl << totalCapacity << "  " << batchTime;
        newVector.clear();
    }

    void PPPIESolution::evaluateSolution(PPPIEInstance problem)
    {
        unsigned int product;
        unsigned int extruder;
        unsigned int day;
        vector<unsigned int> vec;

        // checks if the batch width is ok

        for(unsigned int i=0; i<_allocation.size(); i++)
        {
            _batchIdleness.push_back(problem._length[_allocation[i][1]] - _batchWidth[_allocation[i][0]]);

            if(_batchIdleness.back() < 0)
            {
                vec.clear();
                vec = {1,_allocation[i][0]};
                _restricted.push_back(vec);
            }
        }

        // checks if the extruder time is ok

        for(unsigned int e=0; e<problem._capacity.size(); e++)
        {
            for(unsigned int d=0; d<problem._capacity[e].size(); d++)
            {
                _extruderIdleness[e][d] = problem._capacity[e][d] - _extruderProcTime[e][d];

                if(_extruderIdleness[e][d] < 0)
                {
                    vec.clear();
                    vec = {2,e,d};
                    _restricted.push_back(vec);
                }
            }
        }

        for(unsigned int b=0; b<_balancing.size(); b++)
        {
            product = _balancing[b][1];
            extruder = _allocation[b][1];
            day = _allocation[b][2];
            _production[product][day] += _processingTime[b]*problem._weightRatio[product]*problem._width[product]*problem._productionRate[extruder];
            _productionTotalProfit += _production[product][day]*problem._unitContribution[product];
        }

        _totalFreeOutletInventory = problem._maximumTotalOutletInventory;
        _freeOutletInventoryPerProduct = problem._maximumOutletInventoryPerProduct;

        for(unsigned int p=0; p<problem._NProducts; p++)
        {
            _unmetDemand[p][0] = problem._demand[p][0];
            _inventory[p][0] = problem._initialInventory[p] + _production[p][0];

            if (_inventory[p][0] >= _unmetDemand[p][0])
            {
                _delivered[p][0] = _unmetDemand[p][0];
            }else
            {
                _delivered[p][0] = _inventory[p][0];
            }

            _inventory[p][0] -= _delivered[p][0];
            _unmetDemand[p][0] -= _delivered[p][0];

            _inventoryTotalCost += _inventory[p][0]*problem._inventoryUnitCost;
            _unmetDemandTotalCost += _unmetDemand[p][0]*problem._unmetDemandCost;

            for(unsigned int d=1; d<problem._NDays; d++)
            {
                _unmetDemand[p][d] = _unmetDemand[p][d-1] + problem._demand[p][d];

                _inventory[p][d] = _inventory[p][d-1] + _production[p][d] - _delivered[p][d];

                if (_inventory[p][d] >= _unmetDemand[p][d])
                {
                    _delivered[p][d] = _unmetDemand[p][d];
                }else
                {
                    _delivered[p][d] = _inventory[p][d];
                }

                _inventory[p][d] -= _delivered[p][d];
                _unmetDemand[p][d] -= _delivered[p][d];

                _inventoryTotalCost += _inventory[p][d]*problem._inventoryUnitCost;
                _unmetDemandTotalCost += _unmetDemand[p][d]*problem._unmetDemandCost;
            }

            for(unsigned int d=0; d<problem._NDays; d++)
            {
                if(_inventory[p][d] > 0)
                {
                    for(unsigned int o=0; o<problem._NOutlets; o++)
                    {
                        if ((_totalFreeOutletInventory[o] > 0) & (_freeOutletInventoryPerProduct[p][o] > 0))
                        {
                            if(_freeOutletInventoryPerProduct[p][o]  < _totalFreeOutletInventory[o])
                            {
                                if(_freeOutletInventoryPerProduct[p][o] < _inventory[p][d])
                                {
                                    vec = {p,o,d,_freeOutletInventoryPerProduct[p][o]};
                                }else
                                {
                                    vec = {p,o,d,_inventory[p][d]};
                                }
                            }else
                            {
                                if(_totalFreeOutletInventory[o] < _inventory[p][d])
                                {
                                    vec = {p,o,d,_totalFreeOutletInventory[o]};
                                }else
                                {
                                    vec = {p,o,d,_inventory[p][d]};
                                }
                            }
                            _deliveredToOutlet.push_back(vec);
                            _inventory[p][d] -= vec[3];
                            _freeOutletInventoryPerProduct[p][o] -= vec[3];
                            _totalFreeOutletInventory[o] -= vec[3];
                        }
                    }
                }
            }
        }



        _fitness = _productionTotalProfit - _unmetDemandTotalCost - _inventoryTotalCost ;

        vec.clear();
    };

    void PPPIESolution::printSolution()
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
                cout << _balancing[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "allocation [batch, extruder, day]: ";
        cout << endl << endl;
        for(unsigned int b=0; b<_allocation.size(); b++)
        {
            for(unsigned int i=0; i<_allocation[b].size(); i++)
            {
                cout << _allocation[b][i] << " ";
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
                cout << _extruderProcTime[e][d] << " ";
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
                cout << _extruderIdleness[e][d] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "production (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_production.size(); p++)
        {
            for(unsigned int d=0; d<_production[p].size(); d++)
            {
                cout << _production[p][d] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "delivered (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_delivered.size(); p++)
        {
            for(unsigned int d=0; d<_delivered[p].size(); d++)
            {
                cout << _delivered[p][d] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "unmet demand (g) [product, day]: "<< endl << endl;
        for(unsigned int p=0; p<_unmetDemand.size(); p++)
        {
            for(unsigned int d=0; d<_unmetDemand[p].size(); d++)
            {
                cout << _unmetDemand[p][d] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "delivered to outlet (g) [product, outlet, day, g]: "<< endl << endl;
        for(unsigned int i=0; i<_deliveredToOutlet.size(); i++)
        {
            for(unsigned int j=0; j<_deliveredToOutlet[i].size(); j++)
            {
                cout << _deliveredToOutlet[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "free outlet inventory (g) [outlet]: "<< endl;
        cout << endl;
        for(unsigned int o=0; o<_totalFreeOutletInventory.size(); o++)
        {
            cout << _totalFreeOutletInventory[o] << " ";
        }
        cout << endl;

        cout << endl;
        cout << "free outlet inventory per product (g) [product, outlet]: "<< endl;
        cout << endl;
        for(unsigned int p=0; p<_freeOutletInventoryPerProduct.size(); p++)
        {
            for(unsigned int o=0; o<_freeOutletInventoryPerProduct[p].size(); o++)
            {
                cout << _freeOutletInventoryPerProduct[p][o] << " ";
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
                cout << _inventory[p][d] << " ";
            }
            cout << endl;
        }

    }
}

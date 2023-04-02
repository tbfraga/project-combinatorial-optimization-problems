#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruder::productionPlanningProblemInExtruder(unsigned int NDays, unsigned int NExtruders, vector<float> productionRate, vector<float> length,
    vector<vector<unsigned int>> capacity, float setupCost, float operationCost, unsigned int NProducts, vector<float> width, vector<float> weightRatio,
    vector<float> unitContribution, vector<int> initialInventory, vector<int> maximumInventory, int totalMaximumInventory, float inventoryUnitCost, vector<vector<unsigned int>> demand,
    float unmetDemandCost, vector<unsigned int> color, vector<vector<bool>> colorAndMaterialRatio, vector <vector <unsigned int>> setupTime, unsigned int NOutlets,
    vector<int> maximumTotalOutletInventory,vector<vector<int>> maximumOutletInventoryPerProduct)
    {
        clearAll();

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

        if(_capacity.size() != _NDays)
        {
            cout << " capacity matriz needs to have " << _NDays << " sets of " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _capacity.resize(_NDays);
        }

        for(unsigned int d=0; d<_capacity.size(); d++)
        {
            if(_capacity[d].size() != _NExtruders)
            {
                cout << " capacity of day " << d + 1 << " vector needs to have " << _NExtruders << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _capacity[d].resize(_NExtruders,0);
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
        clearAll();
    };

    void productionPlanningProblemInExtruder::clearAll()
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

        clearSolution();
    };

    void productionPlanningProblemInExtruder::clearSolution()
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
        _extruderProcTime.reserve(_NExtruders);

        _extruderIdleness.clear();
    };

    void productionPlanningProblemInExtruder::printProblem()
    {
        cout << endl << "PRODUCTION PLANNING PROBLEM IN EXTRUDERS" << endl << endl;

        cout << "number of days: " << _NDays << endl;
        cout << "number of extruders: " << _NExtruders << endl;
        cout << "production rate (m/min): ";

        for(vector<float>::iterator it = _productionRate.begin(); it != _productionRate.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "length (m): ";

        for(vector<float>::iterator it = _length.begin(); it != _length.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "capacity (min): ";

        cout << endl;
        for(unsigned int i=0; i<_capacity .size(); i++)
        {
            for(unsigned int j=0; j<_capacity[i].size(); j++)
            {
                cout << _capacity[i][j] << " ";
            }
            cout << endl;
        }

        cout << "setup cost ($/min): " << _setupCost << endl;
        cout << "operation cost ($/min): " << _operationCost << endl;

        cout << "number of products: " << _NProducts << endl;

        cout << "product width (m): ";

        for(vector<float>::iterator it = _width.begin(); it != _width.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "weight ratio (g/m^2): ";

        for(vector<float>::iterator it = _weightRatio.begin(); it != _weightRatio.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "unit contribution ($): ";

        for(vector<float>::iterator it = _unitContribution.begin(); it != _unitContribution.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "initial inventory (g): ";

        for(vector<int>::iterator it = _initialInventory.begin(); it != _initialInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "maximum inventory (g): ";

        for(vector<int>::iterator it = _maximumInventory.begin(); it != _maximumInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "total maximum inventory (g): " << _totalMaximumInventory << endl;
        cout << "inventory unit cost ($): " << _inventoryUnitCost << endl;

        cout << "demand (g): ";
        cout << endl;
        for(unsigned int i=0; i<_demand.size(); i++)
        {
            for(unsigned int j=0; j<_demand[i].size(); j++)
            {
                cout << _demand[i][j] << " ";
            }
            cout << endl;
        }

        cout << "unmet demand cost ($): " << _unmetDemandCost << endl;

        cout << "color: ";

        for(vector<unsigned int>::iterator it = _color.begin(); it != _color.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "colour and material rate: ";
        cout << endl;

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

        cout << "setup time (min): " << endl;

        for(unsigned int i=0; i<_setupTime.size(); i++)
        {
            for(unsigned int j=0; j<_setupTime[i].size(); j++)
            {
                cout << _setupTime[i][j] << " ";
            }
            cout << endl;
        }

        cout << "number of outlets: " << _NOutlets << endl;

        cout << "maximum total outlet inventory (g): ";
        for(vector<int>::iterator it = _maximumTotalOutletInventory.begin(); it != _maximumTotalOutletInventory.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "maximum outlet inventory per product (g): ";
        cout << endl;
        for(unsigned int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            for(unsigned int j=0; j<_maximumOutletInventoryPerProduct[i].size(); j++)
            {
                cout << _maximumOutletInventoryPerProduct[i][j] << " ";
            }
            cout << endl;
        }
    };

    void productionPlanningProblemInExtruder::generateSolution()
    {
        clearSolution();

        double totalCapacity = 0;

        for(unsigned int d=0; d<_NDays; d++)
        {
            for(unsigned int e=0; e<_NExtruders; e++)
            {
                totalCapacity = totalCapacity + _capacity[d][e];
            }
        }

        double batchTime = totalCapacity / _NProducts;

        unsigned int batch = 0;
        unsigned int day = 0;
        unsigned int extruder = 0;
        double sum = 0;
        vector<unsigned int> newVector;

        unsigned int color1 = _color[0];
        unsigned int color2 = color1;

        float procTime = 0;

        for(unsigned int p=0; p<_NProducts; p++)
        {
            newVector.clear();
            newVector = {p,batch};
            _balancing.push_back(newVector);
            _batchWidth.push_back(_width[p]);
            color1 = color2;
            color2 = _color[p];

            newVector.clear();
            newVector = {batch,extruder,0};
            _allocation.push_back(newVector);
            _processingTime.push_back(batchTime - _setupTime[color1][color2]);

            batch++;

            sum = sum + batchTime;
            _extruderProcTime[extruder].push_back(sum);

            if (sum >= _capacity[day][extruder])
            {
                if (extruder == _NExtruders-1)
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

        evaluateSolution();

        cout << endl << totalCapacity << "  " << batchTime;
        newVector.clear();
    }

    void productionPlanningProblemInExtruder::evaluateSolution()
    {
        vector<unsigned int> vec;

        // checks if the batch width is ok

        for(unsigned int i=0; i<_allocation.size(); i++)
        {
            _batchIdleness.push_back(_length[_allocation[i][1]] - _batchWidth[_allocation[i][0]]);

            if(_batchIdleness.back() < 0)
            {
                vec.clear();
                vec = {1,_allocation[i][0]};
                _restricted.push_back(vec);
            }
        }

        // checks if the extruder time is ok

        vec.clear();
    };

    void productionPlanningProblemInExtruder::printSolution()
    {
        cout << endl << endl << "SOLUTION" << endl;
        cout << endl << "balancing: ";
        cout << endl;
        for(unsigned int i=0; i<_balancing.size(); i++)
        {
            for(unsigned int j=0; j<_balancing[i].size(); j++)
            {
                cout << _balancing[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "allocation: ";
        cout << endl;
        for(unsigned int i=0; i<_allocation.size(); i++)
        {
            for(unsigned int j=0; j<_allocation[i].size(); j++)
            {
                cout << _allocation[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl << "processing time"<< endl;

        for(unsigned int i=0; i<_processingTime.size() ;i++)
        {
            cout << _processingTime[i] << endl;
        }
        cout << endl;

        cout << "batch width"<< endl;

        for(unsigned int i=0; i<_batchWidth.size() ;i++)
        {
            cout << _batchWidth[i] << endl;
        }
        cout << endl;

        cout << "batch idleness"<< endl;
        for(unsigned int i=0; i<_batchIdleness.size(); i++)
        {
            cout << _batchIdleness[i] << endl;
        }
        cout << endl;

        cout << "extruder idleness"<< endl;
        cout << endl;

        //_extruderIdleness

        cout << endl << "extruder processing time: ";
        cout << endl;
        for(unsigned int i=0; i<_extruderProcTime.size(); i++)
        {
            for(unsigned int j=0; j<_extruderProcTime[i].size(); j++)
            {
                cout << _extruderProcTime[i][j] << " ";
            }
            cout << endl;
        }
    }

    void PPPIEInstance::PPPIE001()
    {
        /*****************************
        Small problem developed to test the solver operation.
        It is expected that the allocation will be done correctly according to the measurements of the products and the extruders.
        *****************************/

        clearAll();

        _NDays = 1;

        _NExtruders = 2;
        _productionRate = {40,60};
        _length = {1.0,0.8};
        _capacity = {{420,420}};
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

        _demand = {{99400,73800,149600,35800}};
        _unmetDemandCost = 0.5;

        _color = {0,0,0,0};
        _colorAndMaterialRatio= {{1,1,1},{1,1},{1}};

        _setupTime = {{10}};

        _NOutlets = 2;
        _maximumTotalOutletInventory = {30000,20000};

        _maximumOutletInventoryPerProduct = {{1000,1000},{5000,10000},{10000,5000},{5000,500}};
    }
}

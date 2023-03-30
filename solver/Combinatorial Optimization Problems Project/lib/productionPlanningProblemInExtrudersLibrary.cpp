#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruders::productionPlanningProblemInExtruders(unsigned int NDays, unsigned int NExtruders, vector<float> productionRate, vector<float> length, vector<int> capacity,
    int setupTime, float setupCost, float operationCost, unsigned int NProducts, vector<float> width, vector<float> weightRatio,  vector<float> unitContribution, vector<int> initialInventory,
    vector<int> maximumInventory, int totalMaximumInventory, float inventoryUnitCost, vector<vector<int>> demand, float unmetDemandCost, vector<vector<bool>> colorAndMaterialRatio,
    unsigned int NOutlets, vector<int> maximumTotalOutletInventory,vector<vector<int>> maximumOutletInventoryPerProduct)
    {
        _NDays = NDays;
        _NExtruders = NExtruders;

        _productionRate.clear();
         _productionRate = productionRate;
        if(_productionRate.size() != _NExtruders)
        {
            cout << " production rate vector needs to have " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _productionRate.resize(_NExtruders,0);
        }

        _length.clear();
        _length = length;

        if(_length.size() != _NExtruders)
        {
            cout << " length vector needs to have " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _length.resize(_NExtruders,0);
        }

        _capacity.clear();
        _capacity = capacity;

        if(_capacity.size() != _NExtruders)
        {
            cout << " capacity vector needs to have " << _NExtruders << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _capacity.resize(_NExtruders,0);
        }

        _setupTime = setupTime;
        _setupCost = setupCost;
        _operationCost = operationCost;

        _NProducts = NProducts;

        _width.clear();
        _width = width;

        if(_width.size() != _NProducts)
        {
            cout << " width vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _width.resize(_NProducts,0);
        }

        _weightRatio.clear();
        _weightRatio = weightRatio;

        if(_weightRatio.size() != _NProducts)
        {
            cout << " weight ratio vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _weightRatio.resize(_NProducts,0);
        }

        _unitContribution.clear();
        _unitContribution = unitContribution;

        if(_unitContribution.size() != _NProducts)
        {
            cout << " unit contribution vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _unitContribution.resize(_NProducts,0);
        }

        _initialInventory.clear();
        _initialInventory = initialInventory;

        if(_initialInventory.size() != _NProducts)
        {
            cout << " initial inventory vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _initialInventory.resize(_NProducts,0);
        }

        _maximumInventory.clear();
        _maximumInventory = maximumInventory;

        if(_maximumInventory.size() != _NProducts)
        {
            cout << " maximum inventory vector needs to have " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumInventory.resize(_NProducts,0);
        }

        _totalMaximumInventory = totalMaximumInventory;
        _inventoryUnitCost = inventoryUnitCost;

        for(int i=0; i<_demand.size(); i++)
        {
            _demand[i].clear();
        }
        _demand.clear();

        _demand = demand;

        if(_demand.size() != _NDays)
        {
            cout << " demand matriz needs to have " << _NDays << " sets of " << _NProducts << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _demand.resize(_NDays);
        }

        for(int d=0; d<_demand.size(); d++)
        {
            if(_demand[d].size() != _NProducts)
            {
                cout << " demand of day " << d + 1 << " vector needs to have " << _NProducts << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _demand[d].resize(_NProducts,0);
            }
        }

        _unmetDemandCost = unmetDemandCost;

        for(int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            _colorAndMaterialRatio[i].clear();
        }
        _colorAndMaterialRatio.clear();

        _colorAndMaterialRatio = colorAndMaterialRatio;

        if(_colorAndMaterialRatio.size() != _NProducts - 1)
        {
            cout << " color and material matriz needs to have " << _NProducts - 1 << " sets with a maximum of " << _NProducts - 1 << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _colorAndMaterialRatio.resize(_NProducts - 1);
        }

        for(int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            if(_colorAndMaterialRatio[i].size() != _NProducts - i - 1)
            {
                cout << " color and materialRatio relation for product " << i + 1 << " vector needs to have " << _NProducts - i - 1 << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _colorAndMaterialRatio[i].resize(_NProducts - i - 1,0);
            }
        }

        _NOutlets = NOutlets;

        _maximumTotalOutletInventory.clear();

        _maximumTotalOutletInventory = maximumTotalOutletInventory;

        if(_maximumTotalOutletInventory.size() != _NOutlets)
        {
            cout << " maximum outlet inventory vector needs to have " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _maximumTotalOutletInventory.resize(_NOutlets,0);
        }

        for(int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            _maximumOutletInventoryPerProduct[i].clear();
        }
        _maximumOutletInventoryPerProduct.clear();

        _maximumOutletInventoryPerProduct = maximumOutletInventoryPerProduct;

        if(_maximumOutletInventoryPerProduct.size() != _NProducts)
        {
            cout << " maximum outlet inventory per product matriz needs to have " << _NProducts << " sets of " << _NOutlets << " elements."<< endl;
            cout << " resizing ... " <<  endl <<  endl;

            _demand.resize(_NProducts);
        }

        for(int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            if(_maximumOutletInventoryPerProduct[i].size() != _NOutlets)
            {
                cout << " product " << i + 1 << " vector needs to have " << _NOutlets << " elements."<< endl;
                cout << " resizing ... " <<  endl <<  endl;

                _maximumOutletInventoryPerProduct[i].resize(_NOutlets,0);
            }
        }
    };

    productionPlanningProblemInExtruders::~productionPlanningProblemInExtruders()
    {
        _productionRate.clear();
        _length.clear();
        _capacity.clear();
        _width.clear();
        _weightRatio.clear();
        _unitContribution.clear();
        _initialInventory.clear();
        _maximumInventory.clear();

        for(int i=0; i<_demand.size(); i++)
        {
            _demand[i].clear();
        }
        _demand.clear();

        for(int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            _colorAndMaterialRatio[i].clear();
        }
        _colorAndMaterialRatio.clear();

        _maximumTotalOutletInventory.clear();

        for(int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            _maximumOutletInventoryPerProduct[i].clear();
        }
        _maximumOutletInventoryPerProduct.clear();
    };

    void productionPlanningProblemInExtruders::printProblem()
    {
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

        for(vector<int>::iterator it = _capacity.begin(); it != _capacity.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "setup time (min): " << _setupTime << endl;
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
        for(int i=0; i<_demand.size(); i++)
        {
            for(int j=0; j<_demand[i].size(); j++)
            {
                cout << _demand[i][j] << " ";
            }
            cout << endl;
        }

        cout << "unmet demand cost ($): " << _unmetDemandCost << endl;

        cout << "colour and material rate: ";
        cout << endl;

        for(int i=0; i<_colorAndMaterialRatio.size(); i++)
        {
            for(int s=i; s>0; s--)
            {
                cout << "  ";
            }

            for(int j=0; j<_colorAndMaterialRatio[i].size(); j++)
            {
                cout << _colorAndMaterialRatio[i][j] << " ";
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
        for(int i=0; i<_maximumOutletInventoryPerProduct.size(); i++)
        {
            for(int j=0; j<_maximumOutletInventoryPerProduct[i].size(); j++)
            {
                cout << _maximumOutletInventoryPerProduct[i][j] << " ";
            }
            cout << endl;
        }
    };
}

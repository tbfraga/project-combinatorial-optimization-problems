#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruders::productionPlanningProblemInExtruders(unsigned int NDays, unsigned int NExtruders, vector<float> productionRate, vector<float> length, vector<int> capacity)
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
    };

    productionPlanningProblemInExtruders::~productionPlanningProblemInExtruders()
    {
        _productionRate.clear();
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
    };
}

#include "productionPlanningProblemInExtrudersLibrary.h"

namespace productionPlanningProblemInExtrudersLibrary
{
    productionPlanningProblemInExtruders::productionPlanningProblemInExtruders(int NDays, int NExtruders, vector<int> productionRate)
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
    };

    void productionPlanningProblemInExtruders::printProblem()
    {
        cout << "number of days: " << _NDays << endl;
        cout << "number of extruders: " << _NExtruders << endl;
        cout << "production rate: ";

        for(vector<int>::iterator it = _productionRate.begin(); it != _productionRate.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    };
}

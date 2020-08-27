#ifndef COMPANYEMPWAGE_H
#define COMPANYEMPWAGE_H

#include <iostream>
#include <vector>

using namespace std;

class CompanyEmpWage
{
    public:
        string companyName;
        int NUM_OF_WORKING_DAYS;
        int MAX_HRS_IN_MONTH;
        int EMP_RATE_PER_HOUR;
        int monthlyEmployeeWage;
        vector<int> dailyWages;

        CompanyEmpWage()
        {
            cout << "\nEnter Company Name. \n";
            cin >> companyName;
            cout << "\nEnter total number of working days per month. \n";
            cin >> NUM_OF_WORKING_DAYS;
            cout << "\nEnter maximum working hours per month. \n";
            cin >> MAX_HRS_IN_MONTH;
            cout << "\nEnter employee rate per hour. \n";
            cin >> EMP_RATE_PER_HOUR;
        }
};

#endif
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct CompanyDetails
{
    string companyName;
    int NUM_OF_WORKING_DAYS;
    int MAX_HRS_IN_MONTH;
    int EMP_RATE_PER_HOUR;

    CompanyDetails()
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

class EmployeeWageComputation
{
    string companyName;
    int NUM_OF_WORKING_DAYS;
    int MAX_HRS_IN_MONTH;
    int EMP_RATE_PER_HOUR;

    public:
        EmployeeWageComputation(CompanyDetails company)
        {
            this->companyName = company.companyName;
            this->NUM_OF_WORKING_DAYS = company.NUM_OF_WORKING_DAYS;
            this->MAX_HRS_IN_MONTH = company.MAX_HRS_IN_MONTH;
            this->EMP_RATE_PER_HOUR = company.EMP_RATE_PER_HOUR;
        }
        int getWorkingHours();
        int getEmployeeWage();
};

int EmployeeWageComputation :: getWorkingHours()
{
    const int PART_TIME = 1;
    const int FULL_TIME = 2;
    int totalEmpHrs = 0;
    int totalWorkingDays = 0;
    srand(time(0));
    while(totalEmpHrs < MAX_HRS_IN_MONTH && totalWorkingDays < NUM_OF_WORKING_DAYS)
    {
        totalWorkingDays++;
        int empCheck = rand() % 3;
        switch(empCheck)
        {
            case PART_TIME:
                totalEmpHrs += 4;
                break;
            case FULL_TIME:
                totalEmpHrs += 8;
                break;
            default:
                totalEmpHrs += 0;
        }
    }
    return totalEmpHrs;
}

int EmployeeWageComputation :: getEmployeeWage()
{
    return getWorkingHours() * EMP_RATE_PER_HOUR;
}

void selectChoice()
{
        struct CompanyDetails company;
    EmployeeWageComputation* empWage = new EmployeeWageComputation(company);
    while (true)
    {
        int select;
        cout << "\n Select your choice. \n1: Calculate Employee wage for your company. \n2: Exit\n";
        cin >> select;

        switch(select)
        {
            case 1:
                empWage->getEmployeeWage();  
                break;
            case 2:
                exit(0);
        }
    } 
}

int main()
{
    selectChoice();
}
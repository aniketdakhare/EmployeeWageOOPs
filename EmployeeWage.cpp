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
    public:
        int getWorkingHours(CompanyDetails);
        void getEmployeeWage();
};

int EmployeeWageComputation :: getWorkingHours(CompanyDetails company)
{
    const int PART_TIME = 1;
    const int FULL_TIME = 2;
    const int NUM_OF_WORKING_DAYS = company.NUM_OF_WORKING_DAYS;    
    const int MAX_HRS_IN_MONTH = company.MAX_HRS_IN_MONTH;
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

void EmployeeWageComputation :: getEmployeeWage()
{
    struct CompanyDetails company;
    int empWage = getWorkingHours(company) * company.EMP_RATE_PER_HOUR;
    cout << "\nEmployee Wage Per Month = " << empWage << endl;
}

void selectChoice()
{
    EmployeeWageComputation* empWage = new EmployeeWageComputation;
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
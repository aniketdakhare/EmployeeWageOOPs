#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

class CompanyEmpWage
{
    public:
        string companyName;
        int NUM_OF_WORKING_DAYS;
        int MAX_HRS_IN_MONTH;
        int EMP_RATE_PER_HOUR;
        int monthlyEmployeeWage;

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

class IEmployeeWageComputation
{
    public:
        virtual int getMonthlyEmployeeWage(CompanyEmpWage companyDetails) = 0;
};

class EmployeeWageComputation : public IEmployeeWageComputation
{
    public:
        int getMonthlyEmployeeWage(CompanyEmpWage companyDetails)
        {
            const int PART_TIME = 1;
            const int FULL_TIME = 2;
            int totalEmpHrs = 0;
            int totalWorkingDays = 0;
            srand(time(0));
            while(totalEmpHrs < companyDetails.MAX_HRS_IN_MONTH && totalWorkingDays < companyDetails.NUM_OF_WORKING_DAYS)
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
            return totalEmpHrs * companyDetails.EMP_RATE_PER_HOUR;
        }
};

struct EmployeeWageBuilder
{
    void computeCompanyEmployeeWage(list<CompanyEmpWage>* companyDetails)
    {
        CompanyEmpWage company;
        company.monthlyEmployeeWage = (new EmployeeWageComputation())->getMonthlyEmployeeWage(company);
        companyDetails->push_back(company);
    }
};

void display(list<CompanyEmpWage> companyDetails)
{
    for (list<CompanyEmpWage> :: iterator company = companyDetails.begin(); company != companyDetails.end(); company++)
    {
        cout << "\nMonthly Employee wage of "<< company->companyName << " is Rs. " << company->monthlyEmployeeWage << endl;
    }
}

void selectChoice()
{
    list<CompanyEmpWage> companyDetails;
    struct EmployeeWageBuilder employeeWageBuilder;
    bool flag = true;
    while (flag)
    {
        int select;
        cout << "\n Select your choice. \n1: Calculate Employee wage for your company. \n2: Display Details. \n3: Exit\n";
        cin >> select;

        switch(select)
        {
            case 1:
                employeeWageBuilder.computeCompanyEmployeeWage(&companyDetails);  
                break;
            case 2:
                display(companyDetails);
                break;
            case 3:
                flag = false;
        }
    } 
}

int main()
{
    selectChoice();
}
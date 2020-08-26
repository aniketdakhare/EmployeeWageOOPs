#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EmployeeWageComputation
{
    const int EMP_RATE_PER_HOUR = 20;

    public:
        int getWorkingHours();
        void getEmployeeWage();
};

int EmployeeWageComputation :: getWorkingHours()
{
    const int PART_TIME = 1;
    const int FULL_TIME = 2;   
    int empHrs = 0;
    srand(time(0));
    int empCheck = rand() % 3;
    switch(empCheck)
    {
        case PART_TIME:
            empHrs = 4;
            break;
        case FULL_TIME:
            empHrs = 8;
            break;
        default:
            empHrs = 0;
    }
    return empHrs;
}

void EmployeeWageComputation :: getEmployeeWage()
{
    int empWage = getWorkingHours() * EMP_RATE_PER_HOUR;
    cout << "Employee Wage Per Day = " << empWage << endl;    
}

int main()
{
    EmployeeWageComputation* empWage = new EmployeeWageComputation;
    empWage->getEmployeeWage();  
}
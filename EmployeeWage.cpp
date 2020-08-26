#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EmployeeWage
{
    int present = 1;
    const int EMP_RATE_PER_HOUR = 20;

    public:
        void getAttendance()
        {
            int empHrs = 0;
            int empWage = 0;
            srand(time(0));
            int empCheck = rand() % 2;
            if (empCheck == present)
                empHrs = 8;
            else
                empHrs = 0;
            empWage = empHrs * EMP_RATE_PER_HOUR;
            cout << "Employee Wage Per Day = " << empWage << endl;  
        }
};

int main()
{
    EmployeeWage* empWage = new EmployeeWage;
    empWage->getAttendance();  
}
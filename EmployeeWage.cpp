#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EmployeeWage
{
    int present = 1;
    public:
        void getAttendance()
        {
            srand(time(0));
            int empCheck = rand() % 2;
            if (empCheck == present)
                cout << "Employee is Present" << endl;
            else
                cout << "Employee is Absent" << endl;
        }
};

int main()
{
    EmployeeWage* empWage = new EmployeeWage;
    empWage->getAttendance();  
}
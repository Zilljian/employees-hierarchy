#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Supervisor.h"

int main() {
    Employee newEmp = Employee::Builder("Ivan", "Petrov", "Pidor", 228).createNewEmployee();
    newEmp.printInstance();
}
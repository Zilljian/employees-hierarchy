#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Supervisor.h"

int main() {
    Employee newEmp = Employee("Ivan", "Petrov", "Developer", 228);
    Employee newEmp1 = Employee("Борис", "Крылов", "Developer", 457457);
    Employee newEmp2 = Employee("Василий", "Семенов", "Developer", 456456);

    Manager newMan = Manager("Аркадий", "Паровозов", "Manager", 213646);
    newMan.addSubordinate(newEmp);
    newMan.addSubordinate(newEmp2);
    newMan.printInstance();
}
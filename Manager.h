#ifndef EMPLOYEES_HIERARCHY_MANAGER_H
#define EMPLOYEES_HIERARCHY_MANAGER_H

#include "Employee.h"
#include <vector>
#include <set>
#include <string>

struct currentWork {
    Employee* subordinate;
    std::string task;
    Date deadline;
};

class Manager : public Employee{
public:
    Manager(std::string,std::string,std::string,long);
    Manager(std::string,std::string,std::string,long,Date);


    void addTask(Employee&,Date,std::string);
    bool isSubordinate(Employee);
    void addSubordinate(Employee&);
    void addSubordinate(std::set<Employee>);
    void removeSubordinate(Employee);
    void setEmployeeSalary(Employee &, long);

    bool isSuccessful() override;
    void printInstance() override;

private:
    std::vector<currentWork*> taskList;
    std::set<Employee*> subordinateList;
};

#endif //EMPLOYEES_HIERARCHY_MANAGER_H

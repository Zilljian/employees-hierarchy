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

    bool operator < (currentWork& right) {
        return deadline < right.deadline;
    }
};

class Manager : public Employee{
public:
    void addTask(Employee&,Date,std::string);
    bool isSubordinate(Employee);
    void addSubordinate(Employee);
    void removeSubordinate(Employee);
    void setEmployeeSalary(Employee &, long);
    bool isSuccessful() override;
    void printInstance();

private:
    std::vector<currentWork> taskList;
    std::set<Employee> subordinateList;
};

#endif //EMPLOYEES_HIERARCHY_MANAGER_H

#ifndef EMPLOYEES_HIERARCHY_MANAGER_H
#define EMPLOYEES_HIERARCHY_MANAGER_H

#include "Employee.h"
#include <vector>
#include <set>
#include <string>

struct currentWork {
    bool isDone = false;
    Date done = Date();
    Employee* subordinate;
    std::string task;
    Date deadline;
};

class Manager : public Employee{
public:
    Manager(std::string,std::string,std::string,long);
    Manager(std::string,std::string,std::string,long,Date);


    virtual void addTask(Employee&,Date,std::string);
    virtual bool isSubordinate(Employee&);
    virtual void addSubordinate(Employee&);
    virtual void addSubordinate(std::set<Employee>);
    virtual void removeSubordinate(Employee&);
    virtual void setEmployeeSalary(Employee&,long);
    virtual std::set<Employee*>* getSubordinateList();
    bool isSuccessful(Employee&) override;
    void printInstance() override;

private:
    std::vector<currentWork*> taskList;

protected:
    std::set<Employee*> subordinateList;
};

#endif //EMPLOYEES_HIERARCHY_MANAGER_H

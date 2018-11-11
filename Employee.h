#ifndef EMPLOYEES_HIERARCHY_EMPLOYEE_H
#define EMPLOYEES_HIERARCHY_EMPLOYEE_H

#include "date.h"
#include <string>

class Employee {

public:

class Builder {
public:
    Builder(std::string,std::string,std::string,long);

    void setHiredDate(Date);
    void setFirstTask(std::string);
    void setFirstDeadline(Date);

    std::string name;
    std::string surname;
    std::string specialization;
    long salary;

    Date hired = Date();
    std::string currentTask = "Have nothing to do";
    Date currentDeadline = Date();
    Employee createNewEmployee();
};

    std::string& getName();
    void setName(std::string);
    std::string& getSurname();
    void setSurname(std::string);
    std::string& getSpecialization();
    long& getSalary();
    virtual void setSalary(long);
    Date& getHiredDate();
    Date& getFiredDate();
    const long getId();
    static long& getEmployeeNumber();
    virtual void printInstance();
    void fireEmployee();
    void setTask(std::string,Date);
    virtual bool isSuccessful();
    void setReady();
    Date getDeadline();
    friend bool operator < (const Employee&,const Employee&);

private:
    std::string name;
    std::string surname;
    std::string specialization;
    long salary;
    Date hired;
    Date fired;
    long const ID;
    static long employeeCount;
    bool isFired = false;
    Date gotReady;
    bool isReady = true;
    std::string currentTask;
    Date currentDeadline;

protected:
    Employee(Builder*);
};


#endif //EMPLOYEES_HIERARCHY_EMPLOYEE_H

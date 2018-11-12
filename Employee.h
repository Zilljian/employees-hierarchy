#ifndef EMPLOYEES_HIERARCHY_EMPLOYEE_H
#define EMPLOYEES_HIERARCHY_EMPLOYEE_H

#include "Date.h"
#include <string>

class Employee {

public:
    Employee();
    Employee(std::string,std::string,std::string,long);
    Employee(std::string,std::string,std::string,long,Date);
    Employee(std::string,std::string,std::string,long,Date,std::string,Date);


    class Builder {
    public:
        Builder(std::string,std::string,std::string,long);

        Builder setHiredDate(Date);
        Builder setFirstTask(std::string);
        Builder setFirstDeadline(Date);

        std::string tempName;
        std::string tempSurname;
        std::string tempSpec;
        long tempSalary;

        Date* firstHired;
        std::string firstTask = "Have nothing to do";
        Date* firstDeadline;
        Employee createNewEmployee();
    };

    std::string& getName();
    void setName(std::string);
    std::string& getSurname();
    void setSurname(std::string);
    std::string& getSpecialization();
    long& getSalary();
    virtual void setSalary(long);
    const Date* getHiredDate();
    const Date* getFiredDate();
    const long getId();
    static long& getEmployeeNumber();
    virtual void printInstance();
    void fireEmployee();
    ~Employee();

private:
    std::string name;
    std::string surname;
    std::string specialization;
    long salary;
    Date* hired;
    Date* fired;
    long const ID;
    static long employeeCount;
    bool isFired = false;

protected:
    Employee(Builder*);
};


#endif //EMPLOYEES_HIERARCHY_EMPLOYEE_H

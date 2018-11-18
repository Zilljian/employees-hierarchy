#ifndef EMPLOYEES_HIERARCHY_SUPERVISOR_H
#define EMPLOYEES_HIERARCHY_SUPERVISOR_H

#include "Manager.h"

class Supervisor : public Manager{
public:
    Supervisor(std::string,std::string,std::string,long);
    Supervisor(std::string,std::string,std::string,long,Date);


    bool isSubordinate(Manager&);
    void removeSubordinate(Manager&);
    void setEmployeeSalary(Manager&,long);
    void addSubordinate(Manager&);
    void addSubordinate(std::set<Manager>);
    bool isSuccessful(Manager&);
    void printInstance() override;
};


#endif //EMPLOYEES_HIERARCHY_SUPERVISOR_H

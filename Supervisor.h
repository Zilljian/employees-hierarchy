#ifndef EMPLOYEES_HIERARCHY_SUPERVISOR_H
#define EMPLOYEES_HIERARCHY_SUPERVISOR_H

#include "Manager.h"

class Supervisor : public Manager{
public:
    void setSalary(Manager&,long);
};


#endif //EMPLOYEES_HIERARCHY_SUPERVISOR_H

#include "Supervisor.h"

void Supervisor::setSalary(Manager &subordinate, long newSalary) {
    if(subordinate.isSuccessful()) subordinate.setSalary(newSalary);
}

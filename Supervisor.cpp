#include "Supervisor.h"

void Supervisor::addSubordinate(std::set<Manager> newSubordinates) {
    for(auto item : newSubordinates) subordinateList.insert(&item);
}

void Supervisor::addSubordinate(Manager& newSubordinate) {
    subordinateList.insert(&newSubordinate);
}

bool Supervisor::isSubordinate(Manager& subordinate) {
    for(auto item : subordinateList) {
        if(item->getId() == subordinate.getId()) {
            return true;
        }
    } return false;
}

void Supervisor::removeSubordinate(Manager& subordinate) {
    subordinateList.erase(&subordinate);
}

void Supervisor::setEmployeeSalary(Manager& subordinate, long newSalary) {
    if(isSubordinate(subordinate) && isSuccessful(subordinate)) subordinate.setSalary(newSalary);
}

bool Supervisor::isSuccessful(Manager& subordinate) {
    for (auto employee : *subordinate.getSubordinateList()) {
        if (!subordinate.isSuccessful(*employee)) return false;
    }
}

void Supervisor::printInstance() {
    Manager::printInstance();
}

Supervisor::Supervisor(std::string initName, std::string initSurname, std::string spec, long initSalary)
        : Manager(std::move(initName), std::move(initSurname), std::move(spec), initSalary){}

Supervisor::Supervisor(std::string initName, std::string initSurname, std::string spec, long initSalary, Date hired)
        : Manager(std::move(initName), std::move(initSurname), std::move(spec), initSalary, hired){}

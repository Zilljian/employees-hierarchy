#include "Manager.h"

Manager::Manager(std::string initName, std::string initSurname, std::string spec, long initSalary)
        : Employee(initName, initSurname, spec, initSalary), taskList(), subordinateList() {}

Manager::Manager(std::string initName, std::string initSurname, std::string spec, long initSalary, Date hired)
        : Employee(initName, initSurname, spec, initSalary, hired), taskList(), subordinateList() {}


void Manager::addTask(Employee &subordinate, Date deadline, std::string task) {
    currentWork temp;
    temp.deadline = deadline;
    temp.task = std::move(task);
    temp.subordinate = &subordinate;

    for(auto item : subordinateList) {
        if(item->getId() == subordinate.getId()) {
            taskList.push_back(&temp);
            break;
        }
    }
}

void Manager::addSubordinate(std::set<Employee> newSubordinates) {
    for(auto item : newSubordinates) subordinateList.insert(&item);
}

bool Manager::isSubordinate(Employee& subordinate) {
    for(auto item : subordinateList) {
        if(item->getId() == subordinate.getId()) {
            return true;
        }
    } return false;
}

void Manager::addSubordinate(Employee& newSubordinate) {
    subordinateList.insert(&newSubordinate);
}

void Manager::removeSubordinate(Employee& subordinate) {
    subordinateList.erase(&subordinate);
}

void Manager::setEmployeeSalary(Employee& subordinate, long newSalary) {
    if(isSubordinate(subordinate) && isSuccessful(subordinate)) subordinate.setSalary(newSalary);
}

bool Manager::isSuccessful(Employee& subordinate) {
    if (isSubordinate(subordinate)) {
        for (auto item : taskList) {
            if (item->subordinate->getId() == subordinate.getId()) {
                if (!item->isDone || item->deadline < item->done) return false;
            }
        }
        return true;
    }
}

void Manager::printInstance() {
    Employee::printInstance();
    std::cout << "Subordinate List: \n";
    for(auto item : subordinateList) std::cout << item->getSurname() << " " << item->getName() << "\n";
    std::cout.flush();
}

std::set<Employee*> *Manager::getSubordinateList() {
    return &subordinateList;
}

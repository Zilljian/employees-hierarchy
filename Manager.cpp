#include "Manager.h"

void Manager::addTask(Employee &subordinate, Date deadline, std::string task) {
    currentWork temp;
    temp.deadline = deadline;
    temp.task = task;
    temp.subordinate = &subordinate;

    for(auto item : subordinateList) {
        if(item.getId() == subordinate.getId()) {
            taskList.push_back(temp);
            break;
        }
    }
}

bool Manager::isSubordinate(Employee subordinate) {
    for(auto item : subordinateList) {
        if(item.getId() == subordinate.getId()) {
            return true;
        }
    } return false;
}

void Manager::addSubordinate(Employee newSubordinate) {
    subordinateList.insert(newSubordinate);
}

void Manager::removeSubordinate(Employee subordinate) {
    subordinateList.erase(subordinate);
}

void Manager::setEmployeeSalary(Employee &subordinate, long newSalary) {
    if(isSubordinate(subordinate)) subordinate.setSalary(newSalary);
}

bool Manager::isSuccessful() {
    for(auto item : taskList) {
        if(!item.subordinate->isSuccessful()) return false;
    } return true;
}

void Manager::printInstance() {
    Employee::printInstance();
    for(auto item : subordinateList) std::cout << item.getSurname() << " " << item.getName() << "\n";
}

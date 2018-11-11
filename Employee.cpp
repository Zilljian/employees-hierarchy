#include "Employee.h"

long Employee::employeeCount = 0;

Employee::Employee(Builder* builder) : ID(++employeeCount){
    name = builder->name;
    surname = builder->surname;
    specialization = builder->specialization;
    salary = builder->salary;
    currentTask = builder->currentTask;
    currentDeadline = builder->currentDeadline;
}

std::string& Employee::getName() {
    return name;
}

void Employee::setName(std::string newName) {
    name = newName;
}

std::string& Employee::getSurname(){
    return surname;
}

void Employee::setSurname(std::string newSurname){
    surname = newSurname;
}

std::string& Employee::getSpecialization(){
    return specialization;
}

long& Employee::getSalary(){
    return salary;
}

Date& Employee::getHiredDate(){
    return hired;
}

Date& Employee::getFiredDate(){
    if (isFired) return fired;
}

const long Employee::getId(){
    return ID;
}

long& Employee::getEmployeeNumber(){
    return employeeCount;
}

void Employee::fireEmployee() {
    if(isReady) {
        isFired = true;
        fired.setCurrentTime();
    }
}

void Employee::printInstance() {
    std::cout << name << "\n"
    << surname << "\n"
    << specialization << "\n"
    << salary << "\n"
    << hired << "\n";
    if (isFired) std::cout << fired << "\n";
    std::cout << ID << "\n"
    << currentTask;
}

void Employee::setTask(std::string task, Date deadline) {
    currentTask = task;
    currentDeadline = deadline;
    isReady = false;
}

void Employee::setSalary(long newSalary) {
    salary = newSalary;
}

bool Employee::isSuccessful() {
    return isReady && gotReady < currentDeadline;
}

void Employee::setReady() {
    currentTask = "The last task was " + currentTask;
    gotReady = Date();
    isReady = true;
}

Date Employee::getDeadline() {
    return currentDeadline;
}

bool operator < (const Employee& left,const Employee& right) {
    return left.ID < right.ID;
}




Employee::Builder::Builder(
        std::string name,
        std::string surname,
        std::string spec,
        long salary
        ): name(name), surname(surname), specialization(spec), salary(salary){}

void Employee::Builder::setHiredDate(Date newDate) {
    hired = newDate;
}

void Employee::Builder::setFirstTask(std::string firstTask) {
    currentTask = firstTask;
}

void Employee::Builder::setFirstDeadline(Date newDeadline) {
    currentDeadline = newDeadline;
}

Employee Employee::Builder::createNewEmployee() {
    return Employee(this);
}

#include "Employee.h"

long Employee::employeeCount = 0;

Employee::Employee(Builder* builder) : ID(++employeeCount){
    name = builder->tempName;
    surname = builder->tempSurname;
    specialization = builder->tempSpec;
    salary = builder->tempSalary;
    currentTask = builder->firstTask;
    currentDeadline = *(builder->firstDeadline);
    hired = *(builder->firstHired);
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
    std::cout << "Name: " << name << "\n"
    << "Surname: " << surname << "\n"
    << "Specialization: " << specialization << "\n"
    << "Salary: " << salary << "\n"
    << "Hired: " << hired << "\n";
    if (isFired) std::cout << "Fired: "<< fired << "\n";
    std::cout << "ID: " << ID << "\n"
    << "Last Task: " << currentTask;
    std::cout.flush();
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
        ): tempName(name), tempSurname(surname), tempSpec(spec), tempSalary(salary){
    firstHired = new Date;
    firstDeadline = new Date;
}

void Employee::Builder::setHiredDate(Date newDate) {
    firstHired->setDate(newDate.getDateMs());
}

void Employee::Builder::setFirstTask(std::string firstTask) {
    this->firstTask = firstTask;
}

void Employee::Builder::setFirstDeadline(Date newDeadline) {
    firstDeadline->setDate(newDeadline.getDateMs());
}

Employee Employee::Builder::createNewEmployee() {
    return Employee(this);
}

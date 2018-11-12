#include "Employee.h"

long Employee::employeeCount = 0;

Employee::Employee(Builder* builder) : ID(++employeeCount){
    name = builder->tempName;
    surname = builder->tempSurname;
    specialization = builder->tempSpec;
    salary = builder->tempSalary;
    currentTask = builder->firstTask;
    currentDeadline = builder->firstDeadline;
    hired = builder->firstHired;
}

Employee::Employee(): ID(++employeeCount) {}


std::string& Employee::getName() {
    return name;
}

void Employee::setName(std::string newName) {
    name = std::move(newName);
}

std::string& Employee::getSurname(){
    return surname;
}

void Employee::setSurname(std::string newSurname){
    surname = std::move(newSurname);
}

std::string& Employee::getSpecialization(){
    return specialization;
}

long& Employee::getSalary(){
    return salary;
}

const Date* Employee::getHiredDate(){
    return hired;
}

const Date* Employee::getFiredDate(){
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
        fired = new Date();
    }
}

void Employee::printInstance() {
    std::cout << "Name: " << name << "\n"
    << "Surname: " << surname << "\n"
    << "Specialization: " << specialization << "\n"
    << "Salary: " << salary << "\n"
    << "Hired: " << *hired << "\n";
    if (isFired) std::cout << "Fired: "<< fired << "\n";
    std::cout << "ID: " << ID << "\n";
    if(!currentTask.empty()) std::cout << "Last Task: " << currentTask << "\n";
    std::cout.flush();
}

void Employee::setTask(std::string task, Date deadline) {
    currentTask = std::move(task);
    currentDeadline->setDate(deadline.getDateMs());
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
    gotReady->setCurrentTime();
    isReady = true;
}

const Date* Employee::getDeadline() {
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
        ): tempName(std::move(name)), tempSurname(std::move(surname)), tempSpec(std::move(spec)), tempSalary(salary){
    firstHired = new Date;
    firstDeadline = new Date;
}

Employee::Builder Employee::Builder::setHiredDate(Date newDate) {
    firstHired->setDate(newDate.getDateMs());
    return *(this);
}

Employee::Builder Employee::Builder::setFirstTask(std::string firstTask) {
    this->firstTask = std::move(firstTask);
    return *(this);
}

Employee::Builder Employee::Builder::setFirstDeadline(Date newDeadline) {
    firstDeadline->setDate(newDeadline.getDateMs());
    return *(this);
}

Employee Employee::Builder::createNewEmployee() {
    return Employee(this);
}


Employee::Employee(std::string initName, std::string initSurname, std::string spec, long initSalary)
: ID(++employeeCount) {
    name = std::move(initName);
    surname = std::move(initSurname);
    specialization = std::move(spec);
    salary = initSalary;
    hired = new Date;
    currentDeadline = new Date;
    gotReady = new Date;
    fired = nullptr;
}

Employee::Employee(std::string initName, std::string initSurname, std::string spec, long initSalary, Date newHired)
: Employee(std::move(initName), std::move(initSurname), std::move(spec), initSalary){
    hired->setDate(newHired.getDateMs());
}

Employee::Employee(std::string initName, std::string initSurname, std::string spec, long initSalary, Date hired, std::string firstTask, Date initDeadline)
: Employee(std::move(initName), std::move(initSurname), std::move(spec), initSalary, hired) {
    currentDeadline->setDate(initDeadline.getDateMs());
    currentTask = std::move(firstTask);
    isReady = false;
}

Employee::~Employee() {
    delete hired;
    if(isFired) delete fired;
}

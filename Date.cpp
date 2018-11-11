#include "Date.h"
#include <iostream>

Date::Date() : ms(0) {
    dateTime = new (tm);
    setCurrentTime();
}

Date::Date (long ms) {
    dateTime = new (tm);
    this->ms = ms;
    toYmd();
}

Date::Date (int year, int month, int day) : ms(0) {
    dateTime = new (tm);
    dateTime->tm_year = year;
    dateTime->tm_mon = month -1;
    dateTime->tm_mday = day;
    toMs();
}


bool Date::operator < (Date &rightExpr) {
    return ms < rightExpr.getDateMs();
}

bool Date::operator > (Date &rightExpr) {
    return ms > rightExpr.getDateMs();
}

bool Date::operator == (Date &rightExpr) {
    return ms == rightExpr.getDateMs();
}

bool Date::operator != (Date &rightExpr) {
    return ms != rightExpr.getDateMs();
}

Date Date::operator - (const Date& rightExpr) {
    return Date(ms - rightExpr.ms);
}

Date operator - (const Date& leftExpr, const long& rightExpr) {
    return Date(leftExpr.ms - rightExpr);
}

Date operator + (const Date& leftExpr, const long& rightExpr) {
    return Date(leftExpr.ms + rightExpr);
}

Date operator + (const long& leftExpr,const Date& rightExpr) {
    return Date(leftExpr + rightExpr.ms);
}

std::ostream& operator << (std::ostream& out, const Date& date) {
    out << std::to_string(date.dateTime->tm_mday) << '/' <<
        std::to_string(date.dateTime->tm_mon + 1) << '/' <<
        std::to_string(date.dateTime->tm_year);
    out.flush();
    return out;
}

std::istream& operator >> (std::istream& in, Date& date) {
    in >> date.dateTime->tm_mday;
    in >> date.dateTime->tm_mon;
    in >> date.dateTime->tm_year;
    date.dateTime->tm_mon--;
    date.toMs();
    return in;

}


std::string Date::getDate() {
    return std::to_string(dateTime->tm_mday) + '/' +
           std::to_string(dateTime->tm_mon + 1) + '/' +
           std::to_string(dateTime->tm_year);
}

long Date::getDateMs() {
    return ms;
}

void Date::setCurrentTime() {
    ms = time(nullptr);
    dateTime = localtime(&ms);
    dateTime->tm_year += 1900;
    ms = mktime(dateTime) * 1000;
}

void Date::setDate(long ms) {
    this->ms = ms;
    toYmd();
}

void Date::setDate(int year, int month, int day) {
    dateTime->tm_year = year;
    dateTime->tm_mon = month;
    dateTime->tm_mday = day;
}

int Date::compare(Date& rightExpr) {
    if (rightExpr.getDateMs() > this->getDateMs()) return -1;
    else if (rightExpr.getDateMs() == this->getDateMs()) return 0;
    return 1;
}


void Date::toYmd() {
    long temp = ms / 1000;
    localtime_r(&temp, dateTime);
}

void Date::toMs() {
    ms = mktime(dateTime) * 1000;
}

Date::~Date() {
    delete dateTime;
}
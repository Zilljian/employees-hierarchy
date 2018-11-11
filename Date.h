#ifndef EMPLOYEES_HIERARCHY_DATE_H
#define EMPLOYEES_HIERARCHY_DATE_H
#include <string>
#include <iostream>
#include <time.h>


class Date {
public:
    Date();
    Date(long);
    Date (int, int, int);


    bool operator < (Date&);
    bool operator > (Date&);
    bool operator == (Date&);
    bool operator != (Date&);
    Date operator - (const Date&);
    friend Date operator - (const Date&,const long&);
    friend Date operator + (const Date&,const long&);
    friend Date operator + (const long&,const Date&);
    friend std::ostream& operator << (std::ostream&,const Date&);
    friend std::istream& operator >> (std::istream&,Date&);


    std::string getDate();
    long getDateMs();
    void setDate(long);
    void setDate(int,int,int);
    void setCurrentTime();
    int compare(Date&);
    ~Date();

private:
    tm* dateTime;
    time_t ms;
    void toYmd();
    void toMs();
};


#endif //DATA_DATA_H
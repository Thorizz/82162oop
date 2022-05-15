#pragma once
#include <iostream>
#include "MyString.h"
class Date {
private:
    MyString date;
    int day;
    int month;
    int year;
public:
    Date();
    Date(const MyString& newDate);
    Date(const Date& other);
    Date& operator=(const Date& other);
    const int GetDay() const;
    const int GetMonth() const;
    const int GetYear() const;
    const bool IsItNull() const;
    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    const MyString GetFullDate () const;
    const bool IsDateEmpty()const;
    void makeDateEmpty();
    friend std::istream& operator>> (std::istream& is, Date& dt);
    friend std::ostream& operator<< (std::ostream& os, const Date& dt);
};

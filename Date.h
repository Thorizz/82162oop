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
    void makeDateEmpty();
};

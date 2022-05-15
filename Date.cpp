#include "Date.h"

Date::Date(): day(0), month(0), year(0) {}

Date::Date(const MyString &newDate) {
    date = newDate;
    if (date.size() != 10) {
        assert(date.size() != 10 && "invalid date"); // yyyy-mm-dd
    }
    if (date[0] >= '0' && date[0] <= '9' &&
        date[1] >= '0' && date[1] <= '9' &&
        date[2] >= '0' && date[2] <= '9' &&
        date[3] >= '0' && date[3] <= '9'){
        year = (date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
    }else {
        assert("invalid date");
    }
    if (date[5] >= '0' && date[5] <= '9' &&
        date[6] >= '0' && date[6] <= '9'){
        month = (date[5]-'0')*10+(date[6]-'0');
        if(month > 12){
            month = 0;
            year = 0;
            assert("invalid date");
        }
    }else {
        year = 0;
        assert("invalid date");
    }

    if (date[8] >= '0' && date[8] <= '9' &&
        date[9] >= '0' && date[9] <= '9'){
        day = (date[8]-'0')*10+(date[9]-'0');
        int maxDate = 28;
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: maxDate += 3; break;
            case 4: case 6: case 9: case 11: maxDate += 2; break;
            default:break;
        }
        if ((month == 2 && year % 400 == 0) || (month == 2 && year % 4 == 0 && year % 100 != 0)){
            maxDate++;
        }
        if (day > maxDate){
            day = 0;
            year = 0;
            month = 0;
            assert("invalid date");
        }
    }else {
        year = 0;
        month = 0;
        assert("invalid date");
    }

}
Date::Date(const Date &other) {
    date = other.date;
    day = other.day;
    month = other.month;
    year = other.year;
}
Date &Date::operator=(const Date &other) {
    if (this != &other) {
        date = other.date;
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}



bool Date::operator<(const Date &rhs) const {
    if (year < rhs.year) {
        return true;
    } else if (year > rhs.year){
        return false;
    } else {
        if (month < rhs.month){
            return true;
        } else if (month < rhs.month){
            return false;
        } else {
            if (day < rhs.day){
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Date::operator>(const Date &rhs) const {
    if (year > rhs.year) {
        return true;
    } else if (year < rhs.year){
        return false;
    } else {
        if (month > rhs.month){
            return true;
        } else if (month < rhs.month){
            return false;
        } else {
            if (day > rhs.day){
                return true;
            } else {
                return false;
            }
        }
    }
}

const int Date::GetDay() const {
    if (date.empty()) {
        assert(date.empty() && "there is no such date");
    }
    return day;
}
const int Date::GetMonth() const {
    if (date.empty()) {
        assert(date.empty() && "there is no such date");
    }
    return month;
}

const int Date::GetYear() const {
    if (date.empty()) {
        assert(date.empty() && "there is no such date");
    }
    return year;
}

const bool Date::IsItNull() const {
    if(year == 0 && month == 0 && day == 0){
        return true;
    }
    return false;
}

bool Date::operator==(const Date &rhs) const {
    if(year == rhs.year && month == rhs.month && day == rhs.day){
        return true;
    }
    return false;
}

const MyString Date::GetFullDate() const {

    return date;
}


void Date::makeDateEmpty() {
    date.makeStringEmpty();
    day = 0;
    month = 0;
    year = 0;
}

const bool Date::IsDateEmpty() const{
    if (date.empty()){
        return true;
    }
    return false;
}

std::istream &operator>>(std::istream &is, Date &dt) {
    is >> dt.date;
    return is;
}

std::ostream &operator<<(std::ostream &os,const Date &dt) {
    os << dt.date;
    return os;
}

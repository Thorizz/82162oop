#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
class MyString {
private:
    char* words;
    int length;
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();
    MyString& operator=(const MyString& other);
    bool empty() const;
    std::size_t size() const;
    bool operator==(const MyString& rhs) const;
    void addChar(char c);
    char& operator[](std::size_t pos);
    const char* c_str() const;
    const void Print () const;
    void makeStringEmpty();
    friend std::istream& operator>> (std::istream& is, MyString& dt);
    friend std::ostream& operator<< (std::ostream& os, const MyString& dt);
};

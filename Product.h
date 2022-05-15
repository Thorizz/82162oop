#pragma once
#include <iostream>
#include "MyString.h"
#include "Date.h"
class Product {
private:
    MyString name;
    Date expireDate;
    Date entranceDate;
    MyString productionName;
    MyString comment;
public:
    Product();
    Product(const MyString& newName, const Date& newExpireDate,const Date& newEntranceDate, const MyString& newProductionName, const MyString& newComment);
    Product(const Product& other);
    Product& operator=(const Product& other);
    const MyString GetName() const;
    const Date GetExpireDate() const;
    const Date GetEntranceDate() const;
    const MyString GetProductionName() const;
    const MyString GetComment() const;
    bool operator<(const Product& rhs) const;
    void removeProduct();
};
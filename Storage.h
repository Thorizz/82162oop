#pragma once
#include <vector>
#include "Product.h"
#include <fstream>
#include <algorithm>
class Storage {
private:
    std::vector<std::pair<Product, int>> quantityOfEveryProduct;
    Product store[100][100][100];
    std::vector<Product> storeLog;
public:
    Storage();
    Storage(const std::vector<std::pair<Product, int>>& newQuantityOfEveryProduct, Product newStore[100][100][100], const std::vector<Product>& newStoreLog);
    Storage(const Storage& other);
    Storage& operator=(const Storage& other);
    void AddProduct (const Product& newProduct);
    void RemoveProduct(const MyString& name, int quantity);
    const void PrintAll() const;
    void clearing(const Date& currentDate);
    void checkPeriod(const Date& beg, const Date& end);
};

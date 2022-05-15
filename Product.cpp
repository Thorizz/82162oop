#include "Product.h"

Product::Product() {}

Product::Product(const MyString &newName, const Date &newExpireDate, const Date& newEntranceDate,
                 const MyString& newProductionName, const MyString& newComment):
name(newName), expireDate(newExpireDate), entranceDate(newEntranceDate),
productionName(newProductionName), comment(newComment) {
}

Product::Product(const Product &other) {
    name = other.name;
    expireDate = other.expireDate;
    entranceDate = other.entranceDate;
    productionName = other.productionName;
    comment = other.comment;


}

Product &Product::operator=(const Product &other) {
    if (this != &other) {
        name = other.name;
        expireDate = other.expireDate;
        entranceDate = other.entranceDate;
        productionName = other.productionName;
        comment = other.comment;
    }
    return *this;
}

const MyString& Product::GetName() const {
    return name;
}

const Date& Product::GetExpireDate() const {
    return expireDate;
}

const Date& Product::GetEntranceDate() const {
    return entranceDate;
}

const MyString& Product::GetProductionName() const {
    return productionName;
}

const MyString& Product::GetComment() const {
    return comment;
}

bool Product::operator<(const Product &rhs) const {
    if (expireDate<rhs.expireDate){
        return true;
    }
    return false;
}

void Product::removeProduct() {
    name.makeStringEmpty();
    expireDate.makeDateEmpty();
    entranceDate.makeDateEmpty();
    productionName.makeStringEmpty();
    comment.makeStringEmpty();
}

void Product::print() {
    name.Print();
    std::cout << std::endl;
    productionName.Print();
    std::cout << std::endl;
    comment.Print();
    std::cout << std::endl;

}

const bool Product::IsItEmpty() const {
    if (name.empty()){
        return true;
    }
    return false;
}

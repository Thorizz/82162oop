#include <iostream>
#include <fstream>
#include "Storage.h"

int main() {
    Storage *newStorage = new Storage();
    std::string line;

    std::ifstream file("Store.txt");
    while (getline(file, line)) {
        MyString name;
        Date expireDate;
        Date entranceDate;
        MyString productionName;
        MyString comment;

        MyString current;
        int currentCount = 0;
        int saveI =0;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ' '){
                if (name.empty()){
                    name = current;
                    current.makeStringEmpty();
                } else if (expireDate.IsDateEmpty()){
                    expireDate = Date(current);

                    current.makeStringEmpty();

                }else if (entranceDate.IsDateEmpty()){
                    entranceDate = Date(current);

                    current.makeStringEmpty();

                } else if (productionName.empty()){
                    productionName = current;
                    current.makeStringEmpty();
                    saveI = i+1;
                    currentCount = 0;
                    break;
                }
            } else {

                current.addChar(line[i]);
                currentCount++;
            }
        }

        for (int i = saveI; i < line.size(); ++i) {
            current.addChar(line[i]);
            currentCount++;
        }
        comment = current;
        Product newProduct(name, expireDate, entranceDate, productionName,comment);
        newStorage->AddProduct(newProduct);

    }
    file.close();
    Product newProduct(MyString("aaaa"), Date("1234/12/12"), Date("1234/12/12"), MyString("nqma"),MyString("comment"));
    newStorage->AddProduct(newProduct);
    std::cout << "Hello customer, there are following options in this store: \n";
    std::cout << "Press x to exit \n";
    std::cout << "Press p to print all products \n";
    std::cout << "Press a to add new product \n";
    std::cout << "Press r to remove products \n";
    std::cout << "Press c to check all actions in given period \n";
    std::cout << "Press l to clear all expired products \n";

    char str;
    do{
        std::cin >> str;
        if (str == 'p'){
            newStorage->PrintAll();
        } else if (str == 'a'){
            MyString newProdName;
            Date newProdExpireDate;
            Date newProdEntranceDate;
            MyString newProdProductionName;
            MyString newProdComment;
            std::cout << "Please enter the product name ";
            std::cin >> newProdName;
            std::cout << newProdName;
            std::cout << "Please enter the product expire date ";
            std::cin >> newProdExpireDate;
            std::cout << newProdExpireDate;
            std::cout << "Please enter the product entrance date ";
            std::cin >> newProdEntranceDate;
            std::cout << newProdEntranceDate;
            std::cout << "Please enter the product production name ";
            std::cin >> newProdProductionName;
            std::cout << newProdProductionName;
            std::cout << "Please enter more text";
            std::cin >> newProdComment;
            std::cout << newProdComment;
            Product newProd(newProdName,newProdExpireDate,newProdEntranceDate,newProdProductionName,newProdProductionName);
            newStorage->AddProduct(newProd);
        } else if (str == 'r') {
            MyString prodName;
            std::cout << "Please enter the product name ";
            std::cin >> prodName;
            int quantity;
            std::cin >> quantity;
            newStorage->RemoveProduct(prodName,quantity);
        } else if (str == 'c') {
            std::cout << "Please enter the first date ";
            Date firstDate;
            std::cin >> firstDate;
            std::cout << "Please enter the first date ";
            Date secondDate;
            std::cin >> secondDate;
            newStorage->checkPeriod(firstDate, secondDate);
        } else if (str == 'l') {
            std::cout << "Please enter the date ";
            Date firstDate;
            std::cin >> firstDate;
            newStorage->clearing(firstDate);
        }

    } while (str != 'x');

    std::cout << "saving in Store.txt";

    newStorage->SaveChanges();
    return 0;
}

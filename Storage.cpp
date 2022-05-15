#include "Storage.h"

Storage::Storage() {}

Storage::Storage(const std::vector<std::pair<Product, int>>& newQuantityOfEveryProduct, Product (*newStore)[100][100],
                 const std::vector<Product>& newStoreLog) {
    for (int i = 0; i < newQuantityOfEveryProduct.size(); ++i) {
        quantityOfEveryProduct.push_back(newQuantityOfEveryProduct[i]);
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                store[i][j][j] = newStore[i][j][j];
            }
        }
    }

    for (int i = 0; i < newStoreLog.size(); ++i) {
        storeLog.push_back(newStoreLog[i]);
    }
}

Storage::Storage(const Storage &other) {
    for (int i = 0; i < other.quantityOfEveryProduct.size(); ++i) {
        quantityOfEveryProduct.push_back(other.quantityOfEveryProduct[i]);
    }
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                store[i][j][j] = other.store[i][j][j];
            }
        }
    }

    for (int i = 0; i < other.storeLog.size(); ++i) {
        storeLog.push_back(other.storeLog[i]);
    }
}

Storage &Storage::operator=(const Storage &other) {
    if (this != &other) {
        for (int i = 0; i < other.quantityOfEveryProduct.size(); ++i) {
            quantityOfEveryProduct[i] = other.quantityOfEveryProduct[i];
        }
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                for (int k = 0; k < 100; ++k) {
                    store[i][j][j] = other.store[i][j][j];
                }
            }
        }

        for (int i = 0; i < other.storeLog.size(); ++i) {
            storeLog[i] = other.storeLog[i];
        }
    }
    return *this;
}

void Storage::AddProduct(const Product &newProduct) {
    bool IsItIn = false;
    int found = 0;

    for (int p = 0; p < quantityOfEveryProduct.size(); ++p) {
        if (quantityOfEveryProduct[p].first.GetName() == newProduct.GetName()){
            quantityOfEveryProduct[p].second++;
            IsItIn = true;

            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    for (int k = 0; k < 100; ++k) {
                        if (found == 0) {
                            if (store[i][j][k].GetName() == newProduct.GetName()) {
                                if (store[i][j][k].GetExpireDate() == newProduct.GetExpireDate()) {
                                    found = 1;
                                } else {
                                    found = 2;
                                }
                            }
                        } else {
                            if (store[i][j][k].IsItEmpty()) {
                                if (found == 1) {
                                    store[i][j][k] = newProduct;
                                    found = 3;
                                    break;
                                } else {
                                    found = 1;
                                }
                            }
                        }
                    }
                    if(found == 3){
                        break;
                    }
                }
                if(found == 3){
                    break;
                }
            }
            break;
        }
    }

    if (!IsItIn || found != 3){
        bool empty = false;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                for (int k = 0; k < 100; ++k) {
                    if (store[i][j][k].IsItEmpty()){

                        store[i][j][k] = newProduct;
                        empty = true;
                        break;
                    }
                }
                if (empty == true){
                    break;
                }
            }
            if (empty == true){
                break;
            }
        }
        if (empty == false){
            std::cerr << "our shop is full";
        }
    }
    if (!IsItIn){
        std::pair<Product, int> temp;
        temp.first = newProduct;
        temp.second = 1;
        quantityOfEveryProduct.push_back(temp);
    }


}

void Storage::RemoveProduct(const MyString& name, int quantity) {
    for (int i = 0; i < quantityOfEveryProduct.size(); ++i) {
        if (name == quantityOfEveryProduct[i].first.GetName()){
            if (quantityOfEveryProduct[i].second < quantity){
                std::cout << "There are " << quantityOfEveryProduct[i].second << " products left with expire date: \n";
                for (int t = 0; t < 100; ++t) {
                    for (int j = 0; j < 100; ++j) {
                        for (int k = 0; k < 100; ++k) {
                            if (!store[t][j][k].GetName().empty() && store[t][j][k].GetName() == name){
                                std::cout << " expire date:" << store[t][j][k].GetExpireDate().GetFullDate().c_str() << std::endl;
                            }
                        }
                    }
                }

                std::cout << "press 1 if you want to get all " << quantityOfEveryProduct[i].second << " products left";
                char GetAllProducts;
                std::cin >> GetAllProducts;
                if (GetAllProducts == '1'){
                    for (int t = 0; t < 100; ++t) {
                        for (int j = 0; j < 100; ++j) {
                            for (int k = 0; k < 100; ++k) {
                                if (!store[t][j][k].GetName().empty() && store[t][j][k].GetName() == name){
                                    storeLog.push_back(store[t][j][k]);
                                    store[t][j][k].removeProduct();

                                }
                            }
                        }
                    }
                    quantityOfEveryProduct.erase(quantityOfEveryProduct.begin()+i);
                }
                return;
            } else {
                Product *listOfAllProducts = new Product [quantityOfEveryProduct[i].second];
                int counter = 0;
                for (int t = 0; t < 100; ++t) {
                    for (int j = 0; j < 100; ++j) {
                        for (int k = 0; k < 100; ++k) {
                            if (!store[t][j][k].GetName().empty() && store[t][j][k].GetName() == name){
                                listOfAllProducts[counter] = store[t][j][k];
                                counter++;
                            }
                        }
                    }
                }
                for (int l = 0; l < quantityOfEveryProduct.size(); ++l) {
                    if (quantityOfEveryProduct[i].first.GetName() == name){
                        if (quantityOfEveryProduct[i].second > 1){
                            quantityOfEveryProduct[i].second-=quantity;
                        }
                    }
                }
                std::sort(listOfAllProducts, listOfAllProducts+counter);
                for (int t = 0; t < 100; ++t) {
                    for (int j = 0; j < 100; ++j) {
                        for (int k = 0; k < 100; ++k) {
                            if (!store[t][j][k].GetName().empty() && store[t][j][k].GetName() == name){
                                for (int l = 0; l < quantity; ++l) {
                                    if (listOfAllProducts[l].GetExpireDate() == store[t][j][k].GetExpireDate()){
                                        storeLog.push_back(store[t][j][k]);
                                        store[t][j][k].removeProduct();
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cerr << "There is no such product";
}

const void Storage::PrintAll() const {
    if (quantityOfEveryProduct.empty()){
        std::cout << "There are no products";
    }
    for (int i = 0; i < quantityOfEveryProduct.size(); ++i) {
        std::cout << "The name of the product " << i << " is: ";
        quantityOfEveryProduct[i].first.GetName().Print();
        std::cout << " The production name is: ";
        quantityOfEveryProduct[i].first.GetProductionName().Print();
        std::cout << " The comment is ";
        quantityOfEveryProduct[i].first.GetComment().Print();
        std::cout << " And the quantity is: " << quantityOfEveryProduct[i].second << std::endl;
    }
}

void Storage::clearing(const Date &currentDate) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                if (!store[i][j][k].GetName().empty()){
                    if (store[i][j][k].GetExpireDate() < currentDate){
                        std::ofstream newFile;
                        char fileName[20];
                        int day = currentDate.GetDay();
                        int month = currentDate.GetMonth();
                        int year = currentDate.GetYear();
                        fileName[14] = '\0';
                        fileName[13] = 't';
                        fileName[12] = 'x';
                        fileName[11] = 't';
                        fileName[10] = '.';

                        fileName[9] = day % 10 + '0';
                        day /= 10;
                        fileName[8] = day % 10 + '0';

                        fileName[7] = '-';

                        fileName[6] = month % 10 + '0';
                        month /= 10;
                        fileName[5] = month % 10 + '0';

                        fileName[4] = '-';

                        fileName[3] = year % 10 + '0';
                        year /= 10;
                        fileName[2] = year % 10 + '0';
                        year /= 10;
                        fileName[1] = year % 10 + '0';
                        year /= 10;
                        fileName[0] = year % 10 + '0';

                        newFile.open (fileName);
                        newFile << "File name: " << store[i][j][k].GetName().c_str()
                        << " expire date:" << store[i][j][k].GetExpireDate().GetFullDate().c_str()
                        << "entrance date: " << store[i][j][k].GetEntranceDate().GetFullDate().c_str()
                        << "production name: " << store[i][j][k].GetProductionName().c_str()
                        << "and the comment is: "<< store[i][j][k].GetComment().c_str();
                        newFile.close();
                        for (int l = 0; l < quantityOfEveryProduct.size(); ++l) {
                            if (quantityOfEveryProduct[i].first.GetName() == store[i][j][k].GetName()){
                                if (quantityOfEveryProduct[i].second > 1){
                                    quantityOfEveryProduct[i].second--;
                                } else {
                                    quantityOfEveryProduct.erase(quantityOfEveryProduct.begin()+i);
                                }
                            }
                        }
                        store[i][j][k].removeProduct();
                    }
                }
            }
        }
    }
}

void Storage::checkPeriod(const Date &beg, const Date &end) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                if ((store[i][j][j].GetEntranceDate() > beg && store[i][j][j].GetEntranceDate() < end) ||
                store[i][j][j].GetEntranceDate() == beg || store[i][j][j].GetEntranceDate() == beg){  //too lazy to implement >= and <= I am sorry
                    std::cout << "Product with entrance date " << store[i][j][k].GetEntranceDate().GetFullDate().c_str()
                            << " file name: " << store[i][j][k].GetName().c_str()
                            << " expire date:" << store[i][j][k].GetExpireDate().GetFullDate().c_str()
                            << " production name: " << store[i][j][k].GetProductionName().c_str()
                            << " comment : "<< store[i][j][k].GetComment().c_str() << " got in the store";
                }
            }
        }
    }
    for (int i = 0; i < storeLog.size(); ++i) {
        if ((storeLog[i].GetEntranceDate() > beg && storeLog[i].GetEntranceDate() < end) ||
                storeLog[i].GetEntranceDate() == beg || storeLog[i].GetEntranceDate() == beg){  //too lazy to implement >= and <= I am sorry
            std::cout << " Product with entrance date " << storeLog[i].GetEntranceDate().GetFullDate().c_str()
                      << " file name: " << storeLog[i].GetName().c_str()
                      << " expire date:" << storeLog[i].GetExpireDate().GetFullDate().c_str()
                      << " production name: " << storeLog[i].GetProductionName().c_str()
                      << " comment : "<< storeLog[i].GetComment().c_str() << " was taken from the store";
        }

    }
}

void Storage::SaveChanges() {
    std::ofstream newFile;
    newFile.open ("Store.txt");
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                if(!store[i][j][k].IsItEmpty()){
                    newFile << store[i][j][k].GetName() << " " << store[i][j][k].GetExpireDate() << " " <<
                            store[i][j][k].GetProductionName() << " " << store[i][j][k].GetComment() << std::endl;
                }
            }
        }
    }
}

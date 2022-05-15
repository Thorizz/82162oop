#include <iostream>
#include <fstream>
# include "Storage.h"
int main(int argc, char *argv[]) {
    Storage newStorage();
    std::string line;
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
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
                        } else if (expireDate.GetFullDate().empty()){
                            expireDate = Date(current);
                            current = MyString();
                        }else if (entranceDate.GetFullDate().empty()){
                            entranceDate = Date(current);
                            current = MyString();
                        } else if (productionName.empty()){
                            productionName = current;
                            current = MyString();
                            saveI = i+2;
                            currentCount = 0;
                            break;
                        }
                    } else {
                        current[currentCount] += line[i];
                        currentCount++;
                    }
                }
                for (int i = saveI; i < line.size(); ++i) {
                    current[currentCount] += line[i];
                    currentCount++;
                }
                comment = current;
                Product newProduct(name, expireDate, entranceDate, productionName,comment);
            }
            file.close();
        } else {
            std::cout << "Cannot open the file";
        }
    }

    return 0;
}

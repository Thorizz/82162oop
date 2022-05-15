#include "MyString.h"

MyString::MyString(const char* str){
    length = strlen(str);
    words = new char[length + 1];
    strcpy(words,  str);
    words[length] = '\0';
}

MyString::MyString(const MyString &other) {
    length = other.length;
    words = new char[length + 1];
    strcpy(words, other.words);
    words[length] = '\0';
}

MyString::MyString() : words(nullptr), length(0){}

MyString::~MyString() {
    delete[] words;
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        delete[] words;
        length = other.length;
        words = new char[length + 1];
        strcpy(words,  other.words);
    }
    return *this;
}

bool MyString::empty() const {

    if (length == 0) {

        return true;
    }
    return false;
}

std::size_t MyString::size() const {
    return length;
}

bool MyString::operator==(const MyString &rhs) const {
    if (length != rhs.length) {
        return false;
    } else {
        for (size_t i = 0; i < length; i++) {
            if (words[i] != rhs.words[i]) {
                return false;
            }

        }
        return true;
    }
}

char &MyString::operator[](std::size_t pos) {
    if (length > pos || pos < 0) {
        assert(length > pos && "there is no such position");
       // assert(pos < 0 && "there is no such position");
    }

    return words[pos];
}

const char *MyString::c_str() const {
    return this->words;
}

const void MyString::Print() const {
    for (int i = 0; i < size(); ++i) {
        std::cout << words[i];
    }
}

void MyString::makeStringEmpty() {
    delete[] words;
    words = nullptr;
    length = 0;
}

void MyString::addChar(char c) {
    if (length != 0){
        char* copy = new char[length + 2];
        strcpy(copy ,words);

        delete[] words;

        copy[length] = c;
        copy[length+1] = '\0';
        ++length;
        words = copy;
    } else {
        words = new char [2];
        ++length;
        words[0] = c;
        words[1] = '\0';
    }

}

std::istream &operator>>(std::istream &is, MyString &dt) {
    dt.words = new char [100];
    is>>dt.words;
    return is;
}

std::ostream &operator<<(std::ostream &os,const MyString &dt) {
    os << dt.words;
    return os;
}


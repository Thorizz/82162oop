#include "MyString.h"

MyString::MyString(const char* str){
    length = strlen(str);
    words = new char[length + 1];
    strcpy(words,  str);

}

MyString::MyString(const MyString &other) {
    length = other.length;
    words = new char[length + 1];
    strcpy(words,  other.words);
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
    assert(length > pos && "there is no such position");
    assert(length < 0 && "there is no such position");
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

MyString &MyString::operator+=(char c) {
    char* copy = new char[length + 1];
    strcpy(copy, words);
    delete[] words;
    ++length;
    copy[length - 1] = c;
    copy[length] = '\0';
    words = copy;
    return *this;
}

void MyString::makeStringEmpty() {
    delete[] words;
    words = nullptr;
    length = 0;
}

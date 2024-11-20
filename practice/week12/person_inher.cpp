#include <iostream>
using namespace std;

class Person {
protected:
    string name;        // private에서 protected로 접근지정자 변경
    string address;
};

class Student: Person {
public:
    void SetAddress(string add) {
        address = add;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string name) { this ->name = name; }
};

int main() {
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;

    return 0;
}
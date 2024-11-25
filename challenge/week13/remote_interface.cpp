#include <iostream>
using namespace std;

// 리모컨 인터페이스 정의
class RemoteControl {
public:
    // 순수 가상 함수 정의
    virtual void TurnOn() = 0;  // 가전 제품을 켠다.
    virtual void TurnOff() = 0;  // 가전 제품을 끈다. 
};

// TV 클래스 정의
class Television: public RemoteControl {
    void TurnOn() {
        cout << "TV를 켭니다." << endl;       
    }
    void TurnOff() {
        cout << "TV를 끕니다." << endl;       
    }
};


// 냉장고 클래스 정의
class Refrigerator: public RemoteControl {
    void TurnOn() {
        cout << "냉장고를 켭니다." << endl;       
    }
    void TurnOff() {
        cout << "냉장고를 끕니다." << endl;       
    }
};

int main() {
    // TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteTv = new Television();
    remoteTv->TurnOn(); // TV를 켬
    remoteTv->TurnOff(); // TV를 끔

    // 냉장고를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnOn(); // 냉장고를 켬
   remoteRefrigerator->TurnOff(); // 냉장고를 끔

    delete remoteTv, remoteRefrigerator;
    return 0;
}
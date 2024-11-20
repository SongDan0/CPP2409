#include <iostream>
using namespace std;

class User {
private:    
    int hp;         // 체력
    int item_cnt;   // 아이템 획득 횟수
public:             
    int user_x;     // 유저의 위치의 x값
	int user_y;     // 유저의 위치의 y값
    User();                             // 생성자(변수 초기화)
    void DecreaseHP(int dec_hp);        // hp 감소
    void IncreaseHP(int inc_hp);        // hp 증가
    int GetHP();                        // hp 변수 반환               
    void DoAttack();                    // 공격 문구 출력
    friend ostream& operator<<(ostream& os, const User& user);  // user 객체 출력 시 << 재정의
    friend void IncreaseItemCnt(User& user);    // 아이템 획득 횟수 1증가
};

//직업
class Magician: public User{
public:
    Magician(): User(){};   // 생성자(User클래스의 생성자 호출)
    void DoAttack();        // DoAttack 오버라이딩(공격 문구 출력)
};

class Warrior: public User{
public:
    Warrior(): User(){};    // 생성자(User클래스의 생성자 호출)
    void DoAttack();        // DoAttack 오버라이딩(공격 문구 출력)
};
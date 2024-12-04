#include <iostream>
using namespace std;

class User {
protected:    
    int hp;         // 체력
    int item_cnt;   // 아이템 획득 횟수
public:             
    int user_x;     // 유저의 위치의 x값
	int user_y;     // 유저의 위치의 y값
    User();                                         // 생성자(변수 초기화)
    virtual void DecreaseHP(int dec_hp) = 0;        // hp 감소
    virtual void IncreaseHP(int inc_hp) = 0;        // hp 증가
    virtual int GetHP() = 0;                        // hp 변수 반환
    virtual void IncreaseItemCnt() = 0;             // 아이템 획득 횟수 1증가               
    virtual void DoAttack() = 0;                    // 공격 문구 출력
    friend ostream& operator<<(ostream& os, const User& user);  // user 객체 출력 시 << 재정의
};

//직업
class Magician: public User{
public:
    Magician(): User(){};               // 생성자(User클래스의 생성자 호출)
    void DecreaseHP(int dec_hp);        // hp 감소
    void IncreaseHP(int inc_hp);        // hp 증가
    int GetHP();                        // hp 변수 반환
    void IncreaseItemCnt();             // 아이템 획득 횟수 1증가               
    void DoAttack();                    // 공격 문구 출력
};

class Warrior: public User{
public:
    Warrior(): User(){};                // 생성자(User클래스의 생성자 호출)
    void DecreaseHP(int dec_hp);        // hp 감소
    void IncreaseHP(int inc_hp);        // hp 증가
    int GetHP();                        // hp 변수 반환
    void IncreaseItemCnt();             // 아이템 획득 횟수 1증가               
    void DoAttack();                    // 공격 문구 출력
};
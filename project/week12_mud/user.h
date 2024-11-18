#include <iostream>
using namespace std;

class User {
private:    
    int hp;
    int itemCnt;
public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
    friend ostream& operator<<(ostream& os, const User& user);
    friend void increaseItemCnt(User& user);
};
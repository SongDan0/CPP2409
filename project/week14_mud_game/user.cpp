#include "user.h"
#include <iostream>
#include <string>
using namespace std;

User::User() {    
    hp = 20;
    item_cnt = 0;
    user_x = 0;
	user_y = 0;
}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Magician::GetHP() {
    return hp;
}

void Magician::IncreaseItemCnt() {
    item_cnt++;
}

void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}


ostream& operator<<(ostream& os, const User& user){
    os << "현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.item_cnt << "개 입니다.";
    return os;
}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

int Warrior::GetHP() {
    return hp;
}

void Warrior::IncreaseItemCnt() {
    item_cnt++;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}
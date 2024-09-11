#include <iostream>
using namespace std;

int main(){
    int money = 0;
    int candy_money = 0;
    cout << "현재 가지고 있는 돈: ";
    cin >> money;
    cout << "캔디의 가격: ";
    cin >> candy_money;
    cout << "최대로 살 수 있는 캔디 = " << money / candy_money << endl;
    cout << "캔디 구입 후 남은 돈 = " <<  money % candy_money;
}
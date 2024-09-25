#include <iostream>
using namespace std;

int main(){
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 일력하면 종료): ";
    for(int i = 0; ; ){
        cin >> userInput;
        if (userInput == 0)
            break;

        cout << "입력값: " << userInput << " 횟수: " << ++i << endl;

        if(i == 10)
            break;
    }

    cout << "종료되었습니다.";
    return 0;
}
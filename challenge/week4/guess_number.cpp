#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL)); //random 함수 관련 설정

    int answer = rand() % 100; // 정답
    int tries = 0; //시도 횟수 저장하는 변수

    int guess; // 사용자 입력 저장하기 위한 변수

    while(true){
        //입력 받기
        cout << "정답을 추측하여 보시오: ";
        cin >> guess;

        
        if(guess == answer){
            cout << "축하합니다. 시도 횟수 = " << tries;
            break;
        }
        else if(guess > answer)
            cout << "제시한 정수가 높습니다." << endl;
        else 
            cout << "제시한 정수가 낮습니다." << endl;
    tries++;    //시도 횟수 증가
    }

    return 0;
}
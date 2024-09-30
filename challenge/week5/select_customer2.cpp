#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
   
   //명의 회원의 정보 입력 받기
    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;
    for(int i = 0; i < maxPeople; i++){
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }

    //max
    int max_index = 0;
    int max = ages[0];
    for(int i = 1; i < maxPeople; i++){
        if(max < ages[i]){
            max = ages[i];
            max_index = i;
        }
    }

    //min
    int min_index = 0;
     int min = ages[0];
    for(int i = 1; i < maxPeople; i++){
        if(min > ages[i]){
            min = ages[i];
            min_index = i;
        }
    }

    //메뉴
    int choice = 0;
    while(true){
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은 사람 출력" << endl;
        cout << "3. 종료" << endl;
        cout << "메뉴를 선택해주세요: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "나이가 가장 많은 사람: " << names[max_index] << "(" << ages[max_index] << "세)" << endl;
                break;
            case 2:
                cout << "나이가 가장 적은 사람: " << names[min_index] << "(" << ages[min_index] << "세)" << endl;
                break;
            case 3:
                cout << "종료하겠습니다. " << endl;
                break;
            defalut:
                cout << "잘못된 메뉴를 선택하셨습니다. " << names[min_index] << endl;
        }
        if(choice == 3)
            break;
    } 

    return 0;
}
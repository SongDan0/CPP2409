#include <iostream>
using namespace std;

int main(){
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch;// 사용자 입력 저장하기 위한 변수

    //자음, 모음 카운터
    while(cin >> ch){
        //소문자일 경우
        if(ch >= 'a' || ch <= 'z'){
            //자음, 모음 구분하여 vowel, consonant값 증가
            switch(ch){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                vowel++;
                break;
                default:
                consonant++;
            }
        }
        else    //소문자가 아닐 경우
        cout << "잘못 입력하셨습니다. " << endl;
    }
    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;

    return 0;
}
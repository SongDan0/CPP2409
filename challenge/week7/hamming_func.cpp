#include <iostream>
using namespace std;

string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);

int main() {
    string s1, s2;
    int count = 0;

//길이가 같은 문자열을 입력할 때까지 입력요청 반복
while(true){
    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;    
    //문자열의 길이가 같을 경우 반복문 탈출
    if(s1.length() == s2.length()) 
        break;
    //문자열의 길이가 다를 경우 다시 입력 받기
    else
        cout << "문자열의 길이가 다릅니다." << endl;
}

    //해밍거리 계산
    count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;
    return 0;
}

//문자열의 알파벳을 소문자로 바꾸는 함수
string toLowerStr(string str) {
    string Lower_str = str;             //문자열 복사
    for(char& ch: Lower_str) {          //문자열 순회
        if(ch >= 'A' && ch <= 'Z')      //문자가 대문자일 경우
            ch += ('a' - 'A');          //소문자로 변환
    }
    return Lower_str;                   //변환한 문ㅏ열 반환
}

//문자열의 알파벳을 대문자로 바꾸는 함수
string toUpperStr(string str) {     
    string Upper_str = str;             //문자열 복사
    for(char& ch: Upper_str) {          //문자열 순회
        if(ch >= 'a' && ch <= 'z')      //문자가 소문자일 경우
            ch -= ('a' - 'A');          //소문자로 변환
    }
    return Upper_str;                   //변환한 문자열 반환
}

//해밍거리 계산 및 반환
int calcHammingDist(string s1, string s2){
    int count = 0;
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    //해밍거리 계산
    for(int i = 0; i < s1.length(); i++) {  //문자열 순회
            if(s1[i] != s2[i])              //문자열이 다르면
                count += 1;                 //count 1증가
        }
    return count;                           //해밍거리 반환
}

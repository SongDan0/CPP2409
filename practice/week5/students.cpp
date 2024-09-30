#include <iostream>
using namespace std;

int main(){
    const int STUDENTS = 5;
    int scores [STUDENTS];
    int sum = 0;
    int i , average;

    //학생 성적 입력받아 배열값으로 입력
    for(i = 0; i < STUDENTS; i++){
        cout << "학생들의 성적을 입력하시오: ";
        cin >> scores[i];
    }
    
    //성적의 합 구하기
    for(i = 0; i < STUDENTS; i++)
        sum += scores[i];
   
    //성적 평균 구하기
    average = sum / STUDENTS;
    cout << "성적 평균= " << average << endl;
    return 0;
}
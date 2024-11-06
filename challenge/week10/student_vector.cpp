#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<float> student_score;    //성적을 저장할 동적 배열
    float score = 0;                //성적을 입력 받을 변수
    float sum = 0;                  //성적의 합
    int count = 0;                  //학생 수

    //성적 입력 받기
    while(true) {
        //입력 받기
        cout << "학생들의 성적을 입력하세요 (종료하려면 -1 입력): ";
        cin >> score;

        //종료 조건
        if(score == -1)
            break;

        //성적 유효성 체크
        if(score >= 0 && score <= 100)
            student_score.push_back(score);
        else {
            cout << "점수가 유효하지 않습니다. 다시 입력해주세요." << endl;
            continue;
        }
    }
    
    //sum, count 계산
    for(float i: student_score){
        sum += i;
        count++;
    }

    //성적 평균 출력
    cout << "성적 평균 = " << sum/count << endl;\
    
    return 0;
}
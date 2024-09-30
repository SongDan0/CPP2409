#include <iostream>
using namespace std;

int main(){
    int list[10];
    int max;

    //난수를 이용한 배열 생성
    for(int i = 0; i < 10; i++){
        int elem = rand() % 100 + 1;
        list[i] = elem;
        cout << elem << " ";
    }
    cout << endl;

    //최댓값 구하기
    max = list[0];
    for(auto elem : list){
        if(elem > max)
            max = elem;
    }
    cout << "최대값 = " << max << endl;
   
    return 0;
}
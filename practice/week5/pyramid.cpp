#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5 ~ 100): ";
    cin >> floor;

//층을 위에서부터 내림차순으로 순서를 매김(i는 각 층 의미)
    for(int i = floor; i > 0; i--){
        for(int j = 0; j < i-1; j++ ){                  // i층에서는 S가 i-1개 존재
            cout << "S";
        }  
        for(int k = 0; k < 2 * (floor-i) + 1; k++){     // i층에서는 *이 2 * (floor-i)+1개 존재
            cout << "*";
        }
        cout << endl;                                   //층 변경
    }
}
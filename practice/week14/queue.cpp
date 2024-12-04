#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> qu;
    
    // 추가
    qu.push(100);
    qu.push(200);
    qu.push(300);
    
    // 출력
    while (!qu.empty()) {
        cout << qu.front() << endl;
        qu.pop();
    }

    return 0;
}

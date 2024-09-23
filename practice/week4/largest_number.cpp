#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    // a, b, c 중 같은 수가 있으면 c를 출력하는 문제 존재
    // >=를 이용하여 같은 수가 있을 경우 우선순위를 지정(우선순위: a > b > c)
    if(a >= b && a >= c)         
        largest = a;
    else if(b > a && b >= c)     
        largest = b;
    else 
        largest = c;

    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    float f_temperature = 0;
    float c_temperature = 0;
    
    cout << "화씨온도: ";
    cin >> f_temperature;
    c_temperature = (5.0 / 9.0) * (f_temperature - 32);
    cout << "섭씨온도: " << c_temperature;
}
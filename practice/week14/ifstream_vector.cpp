#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TempData {
private: 
    int hour;
    double temperature;
public:
    TempData(int hour, double temp) {
        this->hour = hour;
        this->temperature = temp;
    }
    void Print() {
          cout << hour << "시: 온도 " << temperature << endl; 
    }
};

int main() {
    ifstream is{"temp.txt"};
    if(!is) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }

    vector<TempData> temps; 
    int hour;
    double temperature;
    while(is >> hour >> temperature) {
      temps.push_back(TempData{hour, temperature});
    }
    for(TempData t: temps)
        t.Print();
    return 0;
}
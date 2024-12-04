#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T Add(T x, T y) {
    return x + y;
}

vector<int> Add(vector<int>& vec1, vector<int>& vec2) {
    vector<int> result;
    // 결과 벡터의 크기를 미리 예약
    result.reserve(vec1.size() + vec2.size());

    // 첫 번째 벡터의 모든 아이템을 결과 벡터에 추가
    for(const int& item: vec1) {
        result.push_back(item);
    }  

    // 두 번째 벡터의 모든 아이템을 결과 벡터에 추가
    for(const int& item: vec2) {
        result.push_back(item);
    }

    return result;
}

int main() {
    int x = 100, y = 200;
    cout << Add(x, y) << endl;

    vector<int> s1 = { 1, 2, 3 };
    vector<int> s2 = { 4, 5, 6 };
    vector<int> s3 = Add(s1, s2);
    for (auto& item: s3) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Box2 {
    T1 first_data;
    T2 second_data;

public:
    Box2() {}
    T1 GetFirst();
    T2 GetSecond();
    void SetFirst(T1 value) {
        first_data = value;
    }
    void SetSecond(T2 value) {
        second_data = value;
    }
};

template <typename T1, typename T2>
T1 Box2<T1, T2>::GetFirst() {
    return first_data;
}

template <typename T1, typename T2>
T2 Box2<T1, T2>::GetSecond() {
    return second_data;
}

int main() {
    Box2<int, double> b;
    b.SetFirst(10);
    b.SetSecond(3.14);
    
    cout << "(" << b.GetFirst() << ", " << b.GetSecond() << ")" << endl;

    return 0;
}

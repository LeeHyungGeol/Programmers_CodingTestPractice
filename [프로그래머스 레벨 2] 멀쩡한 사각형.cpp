// 최대공약수를 활용한 문제
// 역시 수학을 잘해면 아주 많이 유리하다.
// 자료형(type) casting에 유의하자!!

#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b > a) {
        swap(a, b);
    }
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

ll solution(int w, int h) {
    return ((ll)w * h) - ((ll)w + h - gcd(w, h));
}
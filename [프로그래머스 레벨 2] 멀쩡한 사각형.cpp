// �ִ������� Ȱ���� ����
// ���� ������ ���ظ� ���� ���� �����ϴ�.
// �ڷ���(type) casting�� ��������!!

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
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    int num = 0, x2 = x;
    while (x) {
        num += (x % 10);
        x /= 10;
    }

    return x2 % num ? false : true;
}
int main() {
    cout << solution(11) << '\n';
    return 0;
}
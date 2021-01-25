#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int solution(int num) {
    int answer = 0;
    ll n = num;
    while (n != 1 && answer < 500) {
        if (n % 2) {
            n *= 3;
            n++;
        }
        else {
            n /= 2;
        }
        answer++;
    }
    return answer == 500 ? -1 : answer;
}
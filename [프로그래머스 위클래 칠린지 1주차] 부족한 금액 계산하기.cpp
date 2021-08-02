using namespace std;

typedef long long ll;

ll solution(int price, int money, int count) {
    ll answer = -money;

    while (count) {
        answer += price * count--;
    }

    return (answer < 0) ? 0 : answer;
}
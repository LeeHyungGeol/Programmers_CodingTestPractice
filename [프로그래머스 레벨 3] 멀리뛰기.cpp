// (���α׷��ӽ� ���� 3) nx2 Ÿ�ϸ� ������ �Ȱ���.
// dp ����

#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

typedef long long ll;

ll solution(int n) {
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < money.size(); ++i) {
        for (int j = money[i]; j <= n; ++j) {
            dp[j] += dp[j - money[i]] % MOD;
        }
    }

    return dp[n];
}
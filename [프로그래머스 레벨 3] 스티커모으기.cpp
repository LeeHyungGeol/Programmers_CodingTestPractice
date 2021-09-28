#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker) {
    int answer = 0, size = sticker.size();
    vector<int> dp(size, 0);

    if (size == 1) {
        return sticker[0];
    }

    dp[0] = sticker[0];
    dp[1] = dp[0];
    for (int i = 2; i < size - 1; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }
    dp[size - 1] = dp[size - 2];
    int Max = *max_element(dp.begin(), dp.end());

    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < size; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    answer = max(Max, *max_element(dp.begin(), dp.end()));

    return answer;
}
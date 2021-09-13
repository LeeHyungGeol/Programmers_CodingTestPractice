// dp, dfs 로 풀이 가능

// dp풀이 : https://mind-devlog.tistory.com/2  , https://seoftware.tistory.com/93

#include <string>
#include <vector>

#define MAX 1e9

using namespace std;

int answer = MAX;

void dfs(int N, int number, int count, int total);

int solution(int N, int number) {
    dfs(N, number, 0, 0);

    if (answer >= 9) {
        answer = -1;
    }

    return answer;
}

void dfs(int N, int number, int count, int total) {
    if (count >= 9) {
        return;
    }
    if (number == total) {
        answer = min(answer, count);
        return;
    }

    int temp = 0;

    for (int i = 0; i + count < 9; ++i) {
        temp = temp * 10 + N;
        dfs(N, number, i + count + 1, total + temp);
        dfs(N, number, i + count + 1, total - temp);
        dfs(N, number, i + count + 1, total * temp);
        dfs(N, number, i + count + 1, total / temp);
    }
}

//----------------------dp풀이-----------------------//

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> Dp(8);

int getNN(int N, int k);

int solution(int N, int number) {
    if (N == number) {
        return 1;
    }

    Dp[0].insert(N);

    for (int k = 1; k < 8; ++k) {
        for (int a = 0; a < k; ++a) {
            for (int b = 0; b < k; ++b) {
                if (a + b + 1 == k) {
                    for (int x : Dp[a]) {
                        for (int y : Dp[b]) {
                            Dp[k].insert(x + y);
                            Dp[k].insert(x - y);
                            Dp[k].insert(x * y);
                            if (y > 0) {
                                Dp[k].insert(x / y);
                            }
                        }
                    }
                }
            }
        }
        Dp[k].insert(getNN(N, k));

        if (Dp[k].find(number) != Dp[k].end()) {
            return k + 1;
        }
    }

    return -1;
}

int getNN(int N, int k) {
    int result = N;
    for (int i = 0; i < k; ++i) {
        result = result * 10 + N;
    }
    return result;
}
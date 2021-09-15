// dp(다이나믹 프로그래밍)
// (백준 실버 1) 정수 삼각형(1932번) 과 똑같은 문제

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int check[501][501];
// 탑다운 방식(top-down)
int go(vector<vector<int>>& triangle, int i, int j) {
    int& ret = check[i][j];
    if (ret != -1) {
        return ret;
    }
    if (i == triangle.size() - 1) {
        return triangle[i][j];
    }
    return ret = max(go(triangle, i + 1, j + 1) + triangle[i][j], go(triangle, i + 1, j) + triangle[i][j]);
}

int solution1(vector<vector<int>> triangle) {
    memset(check, -1, sizeof(check));
    return go(triangle, 0, 0);
}

// 바텀업 방식(bottom-up)
int solution2(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            int left, right;

            if (j - 1 < 0) {
                left = 0;
            }
            else {
                left = triangle[i - 1][j - 1];
            }
            if (j == triangle[i].size() - 1) {
                right = 0;
            }
            else {
                right = triangle[i - 1][j];
            }

            triangle[i][j] = triangle[i][j] + max(left, right);
        }
    }

    for (int i = 0; i < triangle.size(); ++i) {
        answer = max(answer, triangle[triangle.size() - 1][i]);
    }

    return answer;
}
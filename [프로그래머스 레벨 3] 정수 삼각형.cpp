// dp(���̳��� ���α׷���)
// (���� �ǹ� 1) ���� �ﰢ��(1932��) �� �Ȱ��� ����

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int check[501][501];
// ž�ٿ� ���(top-down)
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

// ���Ҿ� ���(bottom-up)
int solution2(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    int n = triangle.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            int left;
            int right;

            if (j - 1 < 0) {
                left = 0;
            }
            else {
                left = triangle[i - 1][j - 1];
            }
            if (i - 1 < j) {
                right = 0;
            }
            else {
                right = triangle[i - 1][j];
            }

            triangle[i][j] = triangle[i][j] + max(left, right);
        }
    }

    for (int i = 0; i < n; ++i) {
        answer = max(answer, triangle[n - 1][i]);
    }

    return answer;
}
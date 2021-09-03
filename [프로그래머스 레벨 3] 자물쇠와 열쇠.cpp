// 2차원 배열의 크기 3배 확대, 2차원 배열 90도 회전 구현

// https://dev-mystory.tistory.com/227
// https://velog.io/@domybest/2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4-%ED%9A%8C%EC%A0%84%EC%8B%9C%ED%82%A4%EA%B8%B0

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> arr);
bool check(vector<vector<int>> lock);

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> newLock(n * 3, vector<int>(n * 3, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newLock[n + i][n + j] = lock[i][j];
        }
    }

    for (int r = 0; r < 4; ++r) {
        key = rotate(key);

        for (int i = 0; i < n * 2; ++i) {
            for (int j = 0; j < n * 2; ++j) {
                for (int x = 0; x < m; ++x) {
                    for (int y = 0; y < m; ++y) {
                        newLock[i + x][j + y] += key[x][y];
                    }
                }

                if (check(newLock)) {
                    return true;
                }

                for (int x = 0; x < m; ++x) {
                    for (int y = 0; y < m; ++y) {
                        newLock[i + x][j + y] -= key[x][y];
                    }
                }
            }
        }
    }

    return false;
}

vector<vector<int>> rotate(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> temp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp[j][n - i - 1] = arr[i][j];
        }
    }

    return temp;
}

bool check(vector<vector<int>> lock) {
    int n = lock.size() / 3;

    for (int i = n; i < n * 2; ++i) {
        for (int j = n; j < n * 2; ++j) {
            if (lock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
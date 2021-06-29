// https://dev-mystory.tistory.com/227
// https://velog.io/@domybest/2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4-%ED%9A%8C%EC%A0%84%EC%8B%9C%ED%82%A4%EA%B8%B0

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 시계방향 회전
vector<vector<int>> rotate90degree(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[j][n - i - 1] = arr[i][j];
        }
    }

    return result;
}

bool check(vector<vector<int>> bigLock) {
    int realLockSize = bigLock.size() / 3;

    for (int i = realLockSize; i < realLockSize * 2; ++i) {
        for (int j = realLockSize; j < realLockSize * 2; ++j) {
            if (bigLock[i][j] != 1) {
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size();
    int M = key.size();

    vector<vector<int>> bigLock(N * 3, vector<int>(N * 3));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bigLock[i + N][j + N] = lock[i][j];
        }
    }

    for (int rotation = 0; rotation < 4; ++rotation) {
        key = rotate90degree(key);
        for (int i = 0; i < N * 2; ++i) {
            for (int j = 0; j < N * 2; ++j) {

                for (int x = 0; x < M; ++x) {
                    for (int y = 0; y < M; ++y) {
                        bigLock[i + x][j + y] += key[x][y];
                    }
                }

                if (check(bigLock)) {
                    return true;
                }

                for (int x = 0; x < M; ++x) {
                    for (int y = 0; y < M; ++y) {
                        bigLock[i + x][j + y] -= key[x][y];
                    }
                }
            }
        }
    }
    return false;
}
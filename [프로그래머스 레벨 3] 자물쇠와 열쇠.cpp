#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 2차원 리스트 90도 회전하기
vector<vector<int> > rotateMatrixBy90Degree(vector<vector<int> > a) {
    int n = a.size(); 
    int m = a[0].size(); 
    vector<vector<int> > result(n, vector<int>(m)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];
        }
    }
    return result;
}

bool check(vector<vector<int>> newLock) {
    int lockLength = newLock.size() / 3;
    for (int i = lockLength; i < lockLength * 2; i++) {
        for (int j = lockLength; j < lockLength * 2; j++) {
            if (newLock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size();
    int m = key.size();
    vector<vector<int>> newLock(n * 3, vector<int>(n * 3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newLock[i + n][j + n] = lock[i][j];
        }
    }

    for (int rotation = 0; rotation < 4; rotation++) {
        key = rotateMatrixBy90Degree(key); // 열쇠 회전
        for (int x = 0; x < n * 2; x++) {
            for (int y = 0; y < n * 2; y++) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        newLock[x + i][y + j] += key[i][j];
                    }
                }
                if (check(newLock)) return true;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        newLock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1001][1001] = { 0 };

vector<int> solution(int n) {
    vector<int> answer;
    arr[0][0] = 1;
    int cnt = n, cntLength = n, Case = 1, i = -1, j = 0, num = 1;
    while (true) {
        if (cntLength == 0) break;
        if (Case == 1) {
            if (cnt == 0) { Case = 2; cnt = --cntLength; continue; }
            arr[++i][j] = num++;
            --cnt;
        }
        else if (Case == 2) {
            if (cnt == 0) { Case = 3; cnt = --cntLength; continue; }
            arr[i][++j] = num++;
            --cnt;
        }
        else if (Case == 3) {
            if (cnt == 0) { Case = 1, cnt = --cntLength; continue; }
            arr[--i][--j] = num++;
            --cnt;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << arr[i][j] << ' ';
            answer.push_back(arr[i][j]);
        }
        cout << '\n';
    }
    return answer;
}

int main() {
    int n = 5;
    solution(n);
    return 0;
}
// dp문제
// (백준 실버 1) 정수 삼각형(1932번) 과 매우 유사한 문제
// (백준 골드 5) 가장 큰 정사각형(1915번) 과 똑같은 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = board[0][0];

    for (int i = 1; i < board.size(); ++i) {
        for (int j = 1; j < board[0].size(); ++j) {
            if (board[i][j]) {
                board[i][j] = min(board[i - 1][j - 1], min(board[i][j - 1], board[i - 1][j])) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}
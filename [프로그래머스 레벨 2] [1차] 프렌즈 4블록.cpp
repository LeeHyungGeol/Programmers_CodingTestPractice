// ����, ����Ž��, down()

// ��ĭ�鿡 ���ؼ� ��ϵ��� ������ �Լ��� down() �Լ� ���� ����� �� ����س���!
// (���� ��� 3) �̳׶� 2(18500��) ������ moveMineral()�Լ��� �����ؼ� �������.

#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> SameBlocks;

bool check(int m, int n, vector<string>& board);
int deleteBlocks(int m, int n, vector<string>& board);
void down(int m, int n, vector<string>& board);

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (check(m, n, board)) {
        int deletedBlockNums = deleteBlocks(m, n, board);
        answer += deletedBlockNums;
        down(m, n, board);
    }

    return answer;
}

bool check(int m, int n, vector<string>& board) {
    SameBlocks.assign(m, vector<bool>(n, false));
    bool flag = false;

    for (int i = 0; i <= m - 2; ++i) {
        for (int j = 0; j <= n - 2; ++j) {
            if (board[i][j] != ' ') {
                char c = board[i][j];
                if (c == board[i + 1][j] && c == board[i][j + 1] && c == board[i + 1][j + 1]) {
                    SameBlocks[i][j] = true;
                    SameBlocks[i + 1][j] = true;
                    SameBlocks[i][j + 1] = true;
                    SameBlocks[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
    }

    return flag;
}

int deleteBlocks(int m, int n, vector<string>& board) {
    int cnt = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (SameBlocks[i][j]) {
                board[i][j] = ' ';
                ++cnt;
            }
        }
    }

    return cnt;
}

void down(int m, int n, vector<string>& board) {
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == ' ') {
                for (int k = i; k > 0; --k) {
                    if (board[k - 1][j] != ' ') {
                        board[k][j] = board[k - 1][j];
                        board[k - 1][j] = ' ';
                    }
                }
            }
        }
    }
    return;
}
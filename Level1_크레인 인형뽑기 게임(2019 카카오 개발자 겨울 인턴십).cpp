#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>> board = { {0, 0, 0, 0, 0} ,{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    s.push(0);
    for (int i = 0; i < moves.size(); ++i) {
        int cur = moves[i] - 1;
        for (int j = 0; j < board[0].size(); ++j) {
            int doll = board[j][cur];
            if (doll != 0) {
                if (s.top() == doll) {
                    s.pop();
                    answer++;
                }
                else {
                    s.push(doll);
                }
                board[j][cur] = 0;
                break;
            }
        }
    }
    return answer * 2;
}
int main() {
   /* for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout <<"answer: "<< solution(board, moves) << '\n';
    return 0;
}
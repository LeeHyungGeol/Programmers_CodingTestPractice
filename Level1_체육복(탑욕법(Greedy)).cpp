#include <string>
#include <vector>

using namespace std;

vector<int> Arr;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    Arr.resize(n + 2);

    for (int l : lost) --Arr[l];
    for (int r : reserve) ++Arr[r];

    for (int i = 1; i <= n; ++i) {
        if (Arr[i] < 0) {
            if (Arr[i - 1] > 0) {
                --Arr[i - 1];
                ++Arr[i];
            }
            else if (Arr[i + 1] > 0) {
                --Arr[i + 1];
                ++Arr[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (Arr[i] >= 0) ++answer;
    }

    return answer;
}
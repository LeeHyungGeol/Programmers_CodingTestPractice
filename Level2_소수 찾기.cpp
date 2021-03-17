#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, K;
vector<int> choice;
vector<int> arr;
vector<int> totalCase;

bool isPrimeNumber(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
void comb(int n, int idx) {
    if (idx > K) {
        string s;
        for (int i = 1; i <= K; ++i) {
            s += to_string(choice[i]);
            cout << "s : " << s << ", choice[i] : " << choice[i] << ' ';
        }
        cout << '\n' << s << '\n';
        totalCase.push_back(stoi(s));
        return;
    }
    if (n > N) return;
    choice[idx] = arr[n];
    comb(n + 1, idx + 1);
    comb(n + 1, idx);
}
int solution(string numbers) {
    int answer = 0;
    N = numbers.size();
    arr.resize(N + 1, 0);
    choice.resize(N + 1);
    cout << N << '\n';
    for (int i = 1; i <= numbers.size(); ++i) {
        arr[i] = numbers[i - 1];
        cout << " i : " << i << ", arr[i] : " << arr[i] << ", numbers[i-1] : " << numbers[i - 1] << ' ';
    }
    cout << '\n';
    for (int k = 1; k <= numbers.size(); ++k) {
        K = k;
        comb(1, 1);
        cout << K << '\n';
        choice.clear();
        choice.resize(N + 1);
    }
    for (int i = 0; i < totalCase.size(); ++i) {
        if (isPrimeNumber(totalCase[i])) ++answer;
    }

    return answer;
}
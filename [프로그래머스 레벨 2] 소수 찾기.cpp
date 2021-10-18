#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<bool> Select;
set<int> Nums, Total;

void perm(string str, string num, int cnt);
void dfs(string str, string num, int cnt);
bool isPrime(int n);

int solution(string numbers) {
    int answer = 0;
    Select.assign(numbers.length(), false);

    perm("", numbers, 0);

    for (auto num : Nums) {
        string s = to_string(num);
        Select.assign(s.length(), false);
        dfs("", s, 0);
    }

    for (auto num : Total) {
        if (isPrime(num)) {
            ++answer;
        }
    }

    return answer;
}

void perm(string str, string num, int cnt) {
    if (cnt == num.length()) {
        Nums.insert(stoi(str));
        return;
    }

    for (int i = 0; i < num.length(); ++i) {
        if (Select[i]) continue;
        Select[i] = true;
        str.push_back(num[i]);
        perm(str, num, cnt + 1);
        str.pop_back();
        Select[i] = false;
    }
}

void dfs(string s, string n, int cnt) {
    if (cnt == n.length()) {
        return;
    }

    for (int i = 0; i < n.length(); ++i) {
        if (Select[i]) continue;
        Select[i] = true;
        s.push_back(n[i]);
        Total.insert(stoi(s));
        dfs(s, n, cnt + 1);
        s.pop_back();
        Select[i] = false;
    }
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// 순열(permutation), 완전탐색

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Answer;
vector<char> Operators;
vector<ll> Numbers;
vector<char> Arr = { '*', '+', '-' };
vector<bool> Select;
vector<char> Priorities;

void dfs(int cnt);
ll calc(ll a, char op, ll b);

ll solution(string expression) {

    string num = "";

    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            num += expression[i];
        }
        else {
            Numbers.push_back(stoll(num));
            Operators.push_back(expression[i]);

            num.clear();
        }
    }

    Numbers.push_back(stoll(num));

    Select.resize(3, false);

    dfs(0);

    return Answer;
}

void dfs(int cnt) {
    if (cnt == 3) {
        vector<ll> nums = Numbers;
        vector<char> ops = Operators;

        for (int i = 0; i < Priorities.size(); ++i) {
            for (int j = 0; j < ops.size(); ++j) {
                if (ops[j] == Priorities[i]) {
                    ll result = calc(nums[j], ops[j], nums[j + 1]);

                    nums.erase(nums.begin() + j);
                    nums.erase(nums.begin() + j);
                    nums.insert(nums.begin() + j, result);
                    ops.erase(ops.begin() + j);
                    --j;
                }
            }
        }

        Answer = max(Answer, abs(nums.front()));
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (Select[i]) {
            continue;
        }
        Select[i] = true;
        Priorities.push_back(Arr[i]);
        dfs(cnt + 1);
        Priorities.pop_back();
        Select[i] = false;
    }
}

ll calc(ll a, char op, ll b) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
}
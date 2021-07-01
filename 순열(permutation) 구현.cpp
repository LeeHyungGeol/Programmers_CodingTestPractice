#include <iostream>
#include <vector>

#define MAX 5
using namespace std;

int arr[MAX];
bool Select[MAX];
vector<int> cases;
vector<int> cases2;

void print();
void dfs(int cnt);

int main(void)
{
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    cases.resize(3);

    dfs(0);
}

// 순열 방식 1 (cnt를 활용한 방식)
void dfs(int cnt) {
    if (cnt == 3) {
        print();
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (Select[i]) {
            continue;
        }
        Select[i] = true;
        cases[cnt] = arr[i];
        dfs(cnt + 1);
        Select[i] = false;
    }
}

// 순열 방식 2 (vector 의 함수를 이용한 방식)
void dfs2(int cnt) {
    if (cnt == 3) {
        print();

        return;
    }

    for (int i = 0; i < MAX; ++i) {
        if(Select[i]) {
            continue;
        }
        Select[i] = true;
        cases.push_back(arr[i]);
        dfs(cnt + 1);
        cases.pop_back();
        Select[i] = false;
    }
}

void print() {
    for (int i = 0; i < cases.size(); ++i) {
        cout << cases[i] << ' ';
    }
    cout << '\n';
}



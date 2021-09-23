#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Parent;

bool compare(const vector<int>& a, const vector<int>& b);
int findParent(int x);
void unionParent(int a, int b);

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    Parent.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        Parent[i] = i;
    }

    sort(costs.begin(), costs.end(), compare);

    for (vector<int> node : costs) {
        if (findParent(node[0]) != findParent(node[1])) {
            unionParent(node[0], node[1]);
            answer += node[2];
        }
    }

    return answer;
}

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

int findParent(int x) {
    if (x != Parent[x]) {
        return Parent[x] = findParent(Parent[x]);
    }
    return Parent[x];
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        Parent[b] = a;
    }
    else {
        Parent[a] = b;
    }
}
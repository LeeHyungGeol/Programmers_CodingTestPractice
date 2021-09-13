#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Vowels = "AEIOU";
vector<string> Dict;

void dfs(string w, int cnt);

int solution(string word) {
    int answer = 0;

    dfs("", 0);

    answer = lower_bound(Dict.begin(), Dict.end(), word) - Dict.begin() + 1;

    return answer;
}

void dfs(string w, int cnt) {
    if (cnt == 5) {
        return;
    }

    for (int i = 0; i < 5; ++i) {
        w.push_back(Vowels[i]);
        Dict.push_back(w);
        dfs(w, cnt + 1);
        w.pop_back();
    }
}
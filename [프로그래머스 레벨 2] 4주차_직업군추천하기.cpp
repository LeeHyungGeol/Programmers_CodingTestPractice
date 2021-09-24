#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

typedef pair<string, int> psi;

vector<psi> TotalScore;

psi getScore(string list, string lan);
bool compare(const psi& a, const psi& b);

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";

    for (string t : table) {
        string job = "";
        int score = 0;

        for (int i = 0; i < languages.size(); ++i) {
            psi result = getScore(t, languages[i]);
            job = result.first;
            score += result.second * preference[i];
        }

        TotalScore.push_back({ job, score });
    }

    sort(TotalScore.begin(), TotalScore.end(), compare);

    answer = TotalScore.front().first;
    return answer;
}

psi getScore(string list, string lan) {
    stringstream ss;
    ss.str(list);
    string job, language;
    psi result = { "",0 };
    int point = 5;
    ss >> job;

    while (ss >> language) {
        if (lan == language) {
            result.second = point;
        }
        --point;
    }
    result.first = job;

    return result;
}

bool compare(const psi& a, const psi& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}
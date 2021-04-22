#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<string, int> psi;

bool compare(pii& a, pii& b) {
    return a.first > b.first;
}

bool comp(psi& a, psi& b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pii>> countGenresPlaysUniqueNumbers;
    map<string, int> countPlays;
    vector<psi> vectorCountPlays;

    for (int i = 0; i < genres.size(); ++i) {
        countGenresPlaysUniqueNumbers[genres[i]].push_back({ plays[i], i });
        countPlays[genres[i]] += plays[i];
    }

    for (auto iter = countGenresPlaysUniqueNumbers.begin(); iter != countGenresPlaysUniqueNumbers.end(); ++iter) {
        sort(iter->second.begin(), iter->second.end(), compare);
    }

    vectorCountPlays.assign(countPlays.begin(), countPlays.end());
    sort(vectorCountPlays.begin(), vectorCountPlays.end(), comp);

    for (int i = 0; i < vectorCountPlays.size(); ++i) {
        string genreName = vectorCountPlays[i].first;
        for (int j = 0; j < countGenresPlaysUniqueNumbers[genreName].size() && j < 2; ++j) {
            answer.push_back(countGenresPlaysUniqueNumbers[genreName][j].second);
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Info {
    int playCount, index;
}Info;
map<string, vector<Info>> GenreCount;
map<string, int> totalPlayCount;
map<int, string> MaxCount;
vector<int> Temp;

bool compare(const Info& a, const Info& b);

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < genres.size(); ++i) {
        totalPlayCount[genres[i]] += plays[i];
        GenreCount[genres[i]].push_back({ plays[i], i });
    }

    for (auto it = totalPlayCount.begin(); it != totalPlayCount.end(); ++it) {
        MaxCount[it->second] = it->first;
        Temp.push_back(it->second);
    }

    sort(Temp.rbegin(), Temp.rend());

    for (int playCount : Temp) {
        string genreName = MaxCount[playCount];
        sort(GenreCount[genreName].begin(), GenreCount[genreName].end(), compare);
        if (GenreCount[genreName].size() >= 2) {
            answer.push_back(GenreCount[genreName][0].index);
            answer.push_back(GenreCount[genreName][1].index);
        }
        else {
            answer.push_back(GenreCount[genreName][0].index);
        }
    }

    return answer;
}

bool compare(const Info& a, const Info& b) {
    return a.playCount > b.playCount;
}
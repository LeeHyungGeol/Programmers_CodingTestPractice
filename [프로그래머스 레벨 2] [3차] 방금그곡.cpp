#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, string> pis;
typedef pair<int, pis> piis;

void changeSharp(string& str);
bool compare(const piis& a, const piis& b);

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int index = 0;
    vector<piis> candidates;

    for (string info : musicinfos) {
        string start = info.substr(0, 5);
        string end = info.substr(6, 5);
        string titleAndMusic = info.substr(12);

        int startHour = stoi(start.substr(0, 2));
        int startMinute = stoi(start.substr(3, 2));
        int startTime = 60 * startHour + startMinute;

        int endHour = stoi(end.substr(0, 2));
        int endMinute = stoi(end.substr(3, 2));
        int endTime = 60 * endHour + endMinute;

        int comma = titleAndMusic.find(',');
        string title = titleAndMusic.substr(0, comma);
        string music = titleAndMusic.substr(comma + 1);

        int totalTime = endTime - startTime;

        changeSharp(m);
        changeSharp(music);

        int times = totalTime / music.length();
        int remain = totalTime % music.length();

        string realMusic = "";

        while (times--) {
            realMusic += music;
        }

        if (remain) {
            for (int i = 0; i < remain; ++i) {
                realMusic += music[i];
            }
        }

        if (realMusic.find(m) != string::npos) {
            candidates.push_back({ totalTime, {index, title} });
        }

        ++index;
    }

    if (candidates.empty()) {
        return "(None)";
    }

    sort(candidates.begin(), candidates.end(), compare);

    answer = candidates[0].second.second;

    return answer;
}

void changeSharp(string& str) {
    int pos = 0;
    pos = str.find('#');
    while (pos != string::npos) {
        str[pos - 1] += '@';
        str.erase(str.begin() + pos);
        pos = str.find('#');
    }
}

bool compare(const piis& a, const piis& b) {
    if (a.first == b.first) {
        return a.second.first < b.second.first;
    }
    return a.first > b.first;
}
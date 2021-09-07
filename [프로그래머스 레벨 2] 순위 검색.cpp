#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<int>> Map;
stringstream SS;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (string str : info) {
        SS.str(str);
        string lang, job, career, food;
        int score;

        SS >> lang >> job >> career >> food >> score;

        vector<vector<string>> temp(4, vector<string>(2, "-"));

        temp[0][0] = lang;
        temp[1][0] = job;
        temp[2][0] = career;
        temp[3][0] = food;

        for (int i = 0; i < 2; ++i) {
            string t1, t2, t3, t4;
            t1 = temp[0][i];
            for (int j = 0; j < 2; ++j) {
                t2 = temp[1][j];
                for (int k = 0; k < 2; ++k) {
                    t3 = temp[2][k];
                    for (int u = 0; u < 2; ++u) {
                        t4 = temp[3][u];
                        Map[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }

        SS.clear();
    }

    // 조회가 아닐 때는 &기호 붙여주자.
    for (auto& m : Map) {
        sort(m.second.begin(), m.second.end());
    }

    for (string str : query) {
        SS.str(str);
        string lang, job, career, food, temp;
        int score;

        SS >> lang >> temp >> job >> temp >> career >> temp >> food >> score;

        string s = lang + job + career + food;

        int index = lower_bound(Map[s].begin(), Map[s].end(), score) - Map[s].begin();

        answer.push_back(Map[s].size() - index);

        SS.clear();
    }

    return answer;
}

//-----------------------2번째 풀이----------------------//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

stringstream SS;
map<string, int> MAP;
vector<int> Combinations[4][3][3][3];

void makeMap();

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    makeMap();

    for (string str : info) {
        SS.str(str);
        string lang, job, career, food;
        int score;

        SS >> lang >> job >> career >> food >> score;

        int arr[4] = { MAP[lang], MAP[job], MAP[career], MAP[food] };

        for (int i = 0; i < (1 << 4); ++i) {
            int index[4] = { 0, };
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j)) {
                    index[j] = arr[j];
                }
            }
            Combinations[index[0]][index[1]][index[2]][index[3]].push_back(score);
        }

        SS.clear();
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int u = 0; u < 3; ++u) {
                    sort(Combinations[i][j][k][u].begin(), Combinations[i][j][k][u].end());
                }
            }
        }
    }

    for (string str : query) {
        SS.str(str);
        string lang, job, career, food, And;
        int score;

        SS >> lang >> And >> job >> And >> career >> And >> food >> score;

        auto& temp = Combinations[MAP[lang]][MAP[job]][MAP[career]][MAP[food]];

        int index = lower_bound(temp.begin(), temp.end(), score) - temp.begin();

        answer.push_back(temp.size() - index);

        SS.clear();
    }

    return answer;
}

void makeMAP() {
    MAP["-"] = 0;
    MAP["cpp"] = 1;
    MAP["java"] = 2;
    MAP["python"] = 3;
    MAP["backend"] = 1;
    MAP["frontend"] = 2;
    MAP["junior"] = 1;
    MAP["senior"] = 2;
    MAP["chicken"] = 1;
    MAP["pizza"] = 2;
}
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<int>> Map;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (string str : info) {
        vector<vector<string>> temp(4, vector<string>(2, "-"));
        stringstream ss(str);
        string a, b, c, d;
        int score;

        ss >> a >> b >> c >> d >> score;

        temp[0][0] = a;
        temp[1][0] = b;
        temp[2][0] = c;
        temp[3][0] = d;

        for (int i = 0; i < 2; ++i) {
            string t1, t2, t3, t4;
            t1 = temp[0][i];
            for (int j = 0; j < 2; ++j) {
                t2 = temp[1][j];
                for (int k = 0; k < 2; ++k) {
                    t3 = temp[2][k];
                    for (int l = 0; l < 2; ++l) {
                        t4 = temp[3][l];
                        Map[t1 + t2 + t3 + t4].push_back(score);
                    }
                }
            }
        }
    }

    /*for (auto itr = Map.begin(); itr != Map.end(); ++itr) {
        sort(itr->second.begin(), itr->second.end());
    }*/

    for (auto& m : Map) {
        sort(m.second.begin(), m.second.end());
    }

    for (string q : query) {
        string a, b, c, d, temp;
        int score;
        stringstream ss(q);

        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;

        string tmp = a + b + c + d;

        // auto low = lower_bound(Map[tmp].begin(), Map[tmp].end(), score);
        vector<int>::iterator low = lower_bound(Map[tmp].begin(), Map[tmp].end(), score);

        answer.push_back(Map[tmp].end() - low);
    }

    return answer;
}
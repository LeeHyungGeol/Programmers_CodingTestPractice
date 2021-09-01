#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

set<string> Set;
map<string, int> Map1, Map2;

int solution(string str1, string str2) {
    int answer = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.length() - 1; ++i) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            Set.insert(str1.substr(i, 2));
            ++Map1[str1.substr(i, 2)];
        }
    }

    for (int i = 0; i < str2.length() - 1; ++i) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            Set.insert(str2.substr(i, 2));
            ++Map2[str2.substr(i, 2)];
        }
    }

    int intersection = 0;
    int unionSize = 0;

    for (auto s : Set) {
        intersection += min(Map1[s], Map2[s]);
        unionSize += max(Map1[s], Map2[s]);
    }

    if (Map1.empty() && Map2.empty()) {
        return 65536;
    }

    answer = (((double)intersection / unionSize) * 65536);

    return answer;
}

//-------------------예전 풀이-----------------------//

int solution2(string str1, string str2) {
    int answer = 0;
    vector<string> v1, v2;
    map<string, int> m1, m2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i + 1])) {
            m1[str1.substr(i, 2)]++;
            v1.push_back(str1.substr(i, 2));
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i + 1])) {
            m2[str2.substr(i, 2)]++;
            v2.push_back(str2.substr(i, 2));
        }
    }

    map<string, int>::iterator iter;
    int cnt = 0;
    for (iter = m1.begin(); iter != m1.end(); ++iter) {
        if (m2.count(iter->first) >= 1) {
            (iter->second >= m2[iter->first]) ? cnt += m2[iter->first] : cnt += iter->second;
        }
    }

    double tmp = (double)cnt / ((v1.size() + v2.size()) - cnt);
    if (v1.size() == 0 && v2.size() == 0) tmp = 1;
    tmp *= 65536;
    tmp = trunc(tmp);

    answer = (int)tmp;
    return answer;
}
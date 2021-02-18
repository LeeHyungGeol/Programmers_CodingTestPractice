#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1, v2;
    map<string, int> m1, m2;
    for (int i = 0; i < str1.size(); ++i)
        str1[i] = tolower(str1[i]);
    for (int i = 0; i < str2.size(); ++i)
        str2[i] = tolower(str2[i]);
    for (int i = 0; i < str1.size() - 1; ++i) {
        if (97 <= str1[i] && str1[i] <= 122 && 97 <= str1[i + 1] && str1[i + 1] <= 122) {
            string s = "";
            s += str1[i];
            s += str1[i + 1];
            v1.push_back(s);
            if (m1.count(s) >= 1) m1[s] += 1;
            else m1.insert({ s, 1 });
        }
    }

    for (int i = 0; i < str2.size() - 1; ++i) {
        if (97 <= str2[i] && str2[i] <= 122 && 97 <= str2[i + 1] && str2[i + 1] <= 122) {
            string s = "";
            s += str2[i];
            s += str2[i + 1];
            v2.push_back(s);
            if (m2.count(s) >= 1) m2[s] += 1;
            else m2.insert({ s, 1 });
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
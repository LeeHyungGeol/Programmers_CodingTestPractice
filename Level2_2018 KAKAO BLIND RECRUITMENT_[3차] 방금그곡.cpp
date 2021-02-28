//KMP �˰��� ���
//Ư�� ���ڸ� �������� ���ڿ� �ڸ��� ���(split�Լ�)
//���ڿ��� #��ȣ�� �ϳ��� ���ڷ� ��ȯ(charChange�Լ�)
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, string> pis;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int matched = 0, begin = 1;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

bool kmpSearch(const string& H, const string& N) {
    int m = N.size(), n = H.size();
    vector<int> pi = getPartialMatch(N);
    int matched = 0, begin = 0;
    while (begin <= n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m)
                return true;
        }
        else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return false;
}
vector<string> split(string inputStr, char Separator) {
    string str = inputStr;
    istringstream ss(str);
    string stringBuffer;
    vector<string> v;
    v.clear();
    // Separator�� �������� ���ڿ� �ڸ���
    while (getline(ss, stringBuffer, Separator)) {
        v.push_back(stringBuffer);
    }
    return v;
}
string charChange(string s) {
    vector<string> v = { "C#","D#","F#","G#","A#" };
    vector<string> v2 = { "$","%","^","&","*" };
    int index;
    string str = s;

    for (int i = 0; i < v.size(); i++) {
        while (true) {
            index = str.find(v[i]);
            if (index == string::npos) break;
            str.replace(index, v[i].length(), v2[i]);
        }
    }
    return str;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    pis ans = { 0, "" };
    for (int i = 0; i < musicinfos.size(); ++i) {
        //Ư�� ���ڸ� �������� ���ڿ� �ڸ���
        vector<string> v = split(musicinfos[i], ',');
        vector<string> firstTime = split(v[0], ':');
        vector<string> lastTime = split(v[1], ':');

        //���ڿ��� #��ȣ�� �ϳ��� ���ڷ� ��ȯ
        string changedM = charChange(m);
        string changedMusicInfo = charChange(v[3]);

        //�������� ����� �ð�
        int hour = stoi(lastTime[0]) - stoi(firstTime[0]);
        int min = stoi(lastTime[1]) - stoi(firstTime[1]);
        int totalTime = (60 * hour) + min;

        string realPlayMusic = "";
        if (totalTime > changedMusicInfo.size()) {
            //������ �ݺ��� Ƚ��
            int cnt = totalTime / changedMusicInfo.size();
            for (int i = 0; i < cnt; ++i) realPlayMusic += changedMusicInfo;
            cnt = totalTime % changedMusicInfo.size();
            if (cnt) realPlayMusic += changedMusicInfo.substr(0, cnt);
            if (kmpSearch(realPlayMusic, changedM) && totalTime > ans.first) ans = { totalTime, v[2] };
        }
        else {
            realPlayMusic = changedMusicInfo.substr(0, totalTime);
            if (kmpSearch(realPlayMusic, changedM) && totalTime > ans.first) ans = { totalTime, v[2] };
        }
    }
    answer = ans.second;
    if (ans.second == "") answer = "(None)";
    return answer;
}
int main() {
	string m = "ABCDEFG";
	vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
	cout << solution(m, musicinfos) << '\n';
	return 0;
}
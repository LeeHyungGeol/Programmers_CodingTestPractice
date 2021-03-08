#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
vector<string> split(const string& inputStr, const char& separator) {
    istringstream ss(inputStr);
    string strBuffer;
    vector<string> ret;
    ret.clear();
    while (getline(ss, strBuffer, separator)) {
        ret.push_back(strBuffer);
        //cout<<strBuffer<<'\n';
    }
    return ret;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> dict;
    //vector<vector<string>> v;
    for (int i = 0; i < record.size(); ++i) {
        vector<string> v = split(record[i], ' ');
        if (v[0] == "Leave") continue;
        else dict[v[1]] = v[2];
    }
    for (int i = 0; i < record.size(); ++i) {
        vector<string> v = split(record[i], ' ');
        string s = "";
        s += dict[v[1]];
        if (v[0] == "Enter") s += "님이 들어왔습니다.";
        else if (v[0] == "Leave") s += "님이 나갔습니다.";
        else continue;
        answer.push_back(s);
    }
    return answer;
}
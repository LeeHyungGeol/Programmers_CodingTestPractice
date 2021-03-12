#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

// for string delimiter
vector<string> splitByString(const string& inputStr) {
    string delimiter = " and";
    int pos_start = 0, pos_end, delim_len = delimiter.length();
    string token, tmp = "";
    vector<string> ret;

    while ((pos_end = inputStr.find(delimiter, pos_start)) != string::npos) {
        token = inputStr.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        tmp += token;
    }
    tmp += (inputStr.substr(pos_start));

    delimiter = " ";
    delim_len = delimiter.length(), pos_start = 0;
    while ((pos_end = tmp.find(delimiter, pos_start)) != string::npos) {
        token = tmp.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        ret.push_back(token);
    }
    ret.push_back(tmp.substr(pos_start));
    
    /*for(auto a : ret) cout<<a<<' ';
    cout<<'\n';*/
    
    return ret;
}

vector<string> splitByChar(const string& inputStr) {
    string delimiter = " ";
    int pos_start = 0, pos_end, delim_length = delimiter.length();
    string token;
    vector<string> ret;

    while ((pos_end = inputStr.find(delimiter, pos_start)) != string::npos) {
        token = inputStr.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_length;
        ret.push_back(token);
    }
    ret.push_back(inputStr.substr(pos_start));

    /*for (auto a : ret) cout << a << ' ';
    cout << '\n';*/

    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < query.size(); ++i) {
        vector<string> queryStr = splitByString(query[i]);
        int cntQualified = 0;
        for (int j = 0; j < info.size(); ++j) {
            int cntCondition = 0;
            vector<string> infoStr = splitByChar(info[j]);
            for (int k = 0; k < infoStr.size(); ++k) {
                cout << "queryStr[k] : " << queryStr[k] << ", infoStr[k] : " << infoStr[k] << '\n';
                if (queryStr[k] == "-" || queryStr[k] == infoStr[k]) cntCondition++;
                else if (k==4 && (int)stoi(queryStr[k]) <= (int)stoi(infoStr[k])) cntCondition++;
            }
            if (cntCondition == 5) cntQualified++;
        }
        answer.push_back(cntQualified);
    }

    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> answer = solution(info, query);

    for (auto a : answer) cout << a << '\n';

    return 0;
}
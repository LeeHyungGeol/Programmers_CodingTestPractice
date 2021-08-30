// 문자열, Map(해쉬), stringstream문제

// stringstream ss; 
// ss.str(targetString); 
// 공백 또는 자료형이 섞인 문자열에서 유용하게 쓰일 수 있다.

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

map<string, string> Map;
stringstream SS;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (string info : record) {
        SS.str(info);
        string cmd, uid, nickname;

        SS >> cmd;

        if (cmd == "Enter" || cmd == "Change") {
            SS >> uid >> nickname;
            Map[uid] = nickname;
        }

        SS.clear();
    }

    for (string info : record) {
        SS.str(info);
        string cmd, uid, nickname;

        SS >> cmd;

        if (cmd == "Enter") {
            SS >> uid;
            answer.push_back(Map[uid] + "님이 들어왔습니다.");
        }
        else if (cmd == "Leave") {
            SS >> uid;
            answer.push_back(Map[uid] + "님이 나갔습니다.");
        }

        SS.clear();
    }

    return answer;
}
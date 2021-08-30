// ���ڿ�, Map(�ؽ�), stringstream����

// stringstream ss; 
// ss.str(targetString); 
// ���� �Ǵ� �ڷ����� ���� ���ڿ����� �����ϰ� ���� �� �ִ�.

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
            answer.push_back(Map[uid] + "���� ���Խ��ϴ�.");
        }
        else if (cmd == "Leave") {
            SS >> uid;
            answer.push_back(Map[uid] + "���� �������ϴ�.");
        }

        SS.clear();
    }

    return answer;
}
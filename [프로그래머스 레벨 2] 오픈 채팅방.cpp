// 해쉬(map) + stringstream 문제
// stringstream 을 활용하는 문제이다.
// 공백 또는 자료형이 섞인 문자열에서 유용하게 쓰일 수 있다.
// stringstream ss; 
// ss.str(targetString); 

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> map;
    vector<string> uids;
    stringstream ss;

    for (auto r : record) {
        ss.str(r);
        string cases, uid, name;
        ss >> cases;

        if (cases == "Enter") {
            ss >> uid;
            ss >> name;
            map[uid] = name;
            uids.push_back(uid);
            answer.push_back("님이 들어왔습니다.");
        }
        else if (cases == "Change") {
            ss >> uid;
            ss >> name;
            map[uid] = name;
        }
        else if (cases == "Leave") {
            ss >> uid;
            uids.push_back(uid);
            answer.push_back("님이 나갔습니다.");
        }
        ss.clear();
    }

    for (int i = 0; i < answer.size(); ++i) {
        answer[i] = map[uids[i]] + answer[i];
    }

    return answer;
}
// �ؽ�(map) + stringstream ����
// stringstream �� Ȱ���ϴ� �����̴�.
// ���� �Ǵ� �ڷ����� ���� ���ڿ����� �����ϰ� ���� �� �ִ�.
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
            answer.push_back("���� ���Խ��ϴ�.");
        }
        else if (cases == "Change") {
            ss >> uid;
            ss >> name;
            map[uid] = name;
        }
        else if (cases == "Leave") {
            ss >> uid;
            uids.push_back(uid);
            answer.push_back("���� �������ϴ�.");
        }
        ss.clear();
    }

    for (int i = 0; i < answer.size(); ++i) {
        answer[i] = map[uids[i]] + answer[i];
    }

    return answer;
}
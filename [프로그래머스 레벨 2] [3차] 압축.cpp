#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> Map;

void makeMap();

vector<int> solution(string msg) {
    vector<int> answer;

    makeMap();

    string key = "";
    int index = 0, value = 27;

    while (!msg.empty()) {
        key += msg[index];

        if (Map.find(key) == Map.end()) {
            Map[key] = value++;
            key.pop_back();
            answer.push_back(Map[key]);
            msg = msg.erase(0, key.length());
            index = 0;
            key.clear();
        }
        else {
            ++index;
        }
    }

    return answer;
}

void makeMap() {
    for (int i = 0; i < 26; ++i) {
        string alpha = "";
        alpha += 'A' + i;
        Map[alpha] = i + 1;
    }
}
int main() {
    string msg = "KAKAO";
    solution(msg);
    return 0;
}
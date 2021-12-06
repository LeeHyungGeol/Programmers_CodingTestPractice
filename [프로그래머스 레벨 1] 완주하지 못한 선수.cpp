#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> Map;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for (string name : completion) {
        ++Map[name];
    }

    for (string name : participant) {
        auto found = Map.find(name);
        if (found->second < 1) answer = name;
        if (found != Map.end()) --Map[name];
        else answer = name;
    }

    return answer;
}
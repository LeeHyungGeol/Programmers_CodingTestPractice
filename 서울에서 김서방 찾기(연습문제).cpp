#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
vector<string> seoul = { "Jane", "Kim" };
string solution(vector<string> seoul) {
    string answer = "";
    int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer = "�輭���� " + to_string(pos) + "�� �ִ�";
    return answer;
}
string solution2(vector<string> seoul) {
    string answer = "";
    for (int i = 0; i < seoul.size(); ++i) {
        if (seoul[i] == "Kim") {
            answer = "�輭���� " + to_string(i) + "�� �ִ�";
            break;
        }
    }
    return answer;
}
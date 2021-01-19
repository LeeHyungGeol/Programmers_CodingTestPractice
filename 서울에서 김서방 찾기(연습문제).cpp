#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
vector<string> seoul = { "Jane", "Kim" };
string solution(vector<string> seoul) {
    string answer = "";
    int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer = "김서방은 " + to_string(pos) + "에 있다";
    return answer;
}
string solution2(vector<string> seoul) {
    string answer = "";
    for (int i = 0; i < seoul.size(); ++i) {
        if (seoul[i] == "Kim") {
            answer = "김서방은 " + to_string(i) + "에 있다";
            break;
        }
    }
    return answer;
}
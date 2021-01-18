#include <string>
#include <vector>
#include <string>
//https://modoocode.com/224
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
vector<string> completion = { "stanko", "ana", "mislav" };
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mapP;
    map<string, int>::iterator it;

    for (int i = 0; i < participant.size(); ++i) {
        if (mapP.count(participant[i]) >= 1) {
            mapP[participant[i]] += 1;
        }
        else {
            mapP.insert({ participant[i], 1 });
        }
    }
   /* for (it = mapP.begin(); it != mapP.end(); ++it) {
        cout << it->first << " " << it->second << '\n';
    }
    cout << '\n';*/
    for (int i = 0; i < completion.size(); ++i) {
        if (mapP.count(completion[i]) >= 1)
            mapP[completion[i]] -= 1;
    }
    for (it = mapP.begin(); it != mapP.end(); ++it) {

        //cout << it->first << " " << it->second << '\n';

        if (it->second == 1) {
            answer = it->first;
            //cout << answer << '\n';
        }

    }
    return answer;
}
string solution2(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
    //return answer;
}
int main() {
    cout << solution2(participant, completion)<<'\n';
    return 0;
}
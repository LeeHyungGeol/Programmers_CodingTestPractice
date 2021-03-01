//find() - map이든 unordered_map이든 값이 없을 때는 map_name.end()값을 반환!!
//count() - map이든 unordered_map이든 key가 존재하면 1 아니면 0을 반환하게됨.
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution2(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    //길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
     //for (int i = 0; i < 26; ++i) { char c = 'A' + i; string s =""; s += c; dict[s] = i + 1; }
    for (int i = 0; i < 26; ++i) { string s; s = 'A' + i; dict[s] = i + 1; }

    //26이후의 색인번호
    int index = 27;

    for (int i = 0; i < msg.size(); ++i) {
        string s = "";
        s += msg[i];
        int j = i;
        int cnt = 0;
        //find() - map이든 unordered_map이든 값이 없을 때는 map_name.end()값을 반환!!
        //count() - map이든 unordered_map이든 key가 존재하면 1 아니면 0을 반환하게됨.
        while (dict.find(s) != dict.end()) {
            cnt++;
            j++;
            s += msg[j];
        }
        i += cnt - 1;
        dict[s] = index++;
        s.pop_back();
        answer.push_back(dict[s]);
    }

    //for(auto it=dict.begin(); it!=dict.end();++it)
    //    cout<<it->first<<" "<<it->second<<'\n';
    return answer;
}
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    //길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (int i = 0; i < 26; ++i) { char c = 'A' + i; string s = ""; s += c; dict[s] = i + 1; }

    //26이후의 색인번호
    int index = 27;
    for (int i = 0; i < msg.size(); ++i) {
        string s = "";
        int j = i;
        while (1) {
            s += msg[j];
            if (dict.count(s) >= 1) {             
                ++j;     
            }
            else {
                string noMatched = s;
                string matched = msg.substr(i, s.size() - 1);
                dict[noMatched] = index;
                if (matched.size() >= 2) i += s.size() - 2;
                index++;
                answer.push_back(dict.find(matched)->second);
                break;
            }
        }
    }

    for (auto a : answer) cout << a << '\n';


    //for(auto it=dict.begin(); it!=dict.end();++it)
    //    cout<<it->first<<" "<<it->second<<'\n';
    return answer;
}
int main() {
    string msg = "KAKAO";
    solution(msg);
    return 0;
}
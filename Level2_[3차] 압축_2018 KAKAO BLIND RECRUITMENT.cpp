#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    //길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (int i = 0; i < 26; ++i) { char c = 'A' + i; string s = ""; s += c; dict[s] = i + 1; }

    //26이후의 색인번호
    int cnt = 27;
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
                dict[noMatched] = cnt;
                cout << "j : " << j << '\n';
                cout << "cnt : " << cnt << '\n';
                cout << "matched : " << matched << '\n';
                cout << "noMatched  : " << noMatched << '\n';
                cout << "dict.find(matched)->second  : " << dict.find(matched)->second << '\n';
                cnt++;
                answer.push_back(dict.find(matched)->second);
                break;
            }
        }
    }




    //for(auto it=dict.begin(); it!=dict.end();++it)
    //    cout<<it->first<<" "<<it->second<<'\n';
    return answer;
}
int main() {
    string msg = "KAKAO";
    solution(msg);
    return 0;
}
// map 또는 set을 활용하는 문제, 탐색면에서 완전탐색 문제라고도 볼 수도 있을 것 같다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef pair<int, vector<int>> piv;

vector<piv> subsets;

// 첫번째 풀이
// 문자열 s 에 '{', '}', ',' 가 혼합되어 있어서 풀기가 처음에는 매우 화가 났다.
// map 또는 set을 부분집합을 뽑아내는데 활용하려 했으나 처음에는 생각이 잘 나지 않아서 포기하고,
// 사실 무조건 부분집합들을 "{{1,2,3},{2,1},{1,2,4,3},{2}}" 이 모양의 vector<vector<int>> 형태로 뽑아내려고 하려다 보니 생각이 안났다.

// while문을 통해 각각의 부분집합들을 vector<int> 형태로 구하였고, vector<int>의 크기에 따라서 정렬하기 위해,
// vector<pair<int, vector<int>>> 의 형태로 저장하였다.
// 이후 while문을 벗어난 후, sort()를 해서 vector의 크기 순으로 정렬해주고
// 부분집합들의 원소가 중복 될 수 있기 때문에, 
// set을 활용하여 현재의 원소가 set에 없으면 set과 answer에 넣어주고, 있다면 넘어가는 방식으로 구현하였다.

vector<int> solution(string s) {
    vector<int> answer;

    s.erase(s.begin());
    s.erase(s.begin() + s.length() - 1);

    int i = 0;

    while (true) {
        if (i == s.length()) {
            break;
        }
        if (s[i] == '{') {
            ++i;
            string str = "";
            vector<int> temp;

            while (true) {
                if (s[i] == '}') {
                    temp.push_back(stoi(str));
                    str.clear();
                    break;
                }
                if (isdigit(s[i])) {
                    str.push_back(s[i]);
                }
                else {
                    temp.push_back(stoi(str));
                    str.clear();
                }
                ++i;
            }

            subsets.push_back({ (int)temp.size(), temp });
            temp.clear();
        }

        ++i;
    }

    sort(subsets.begin(), subsets.end());

    set<int> set;

    for (auto subset : subsets) {
        for (auto x : subset.second) {
            if (set.find(x) == set.end()) {
                set.insert(x);
                answer.push_back(x);
            }
        }
    }

    return answer;
}

// 두번째 풀이
// map을 활용한 풀이
// 첫번째 풀이가 너무 복잡하고 별로라고 생각하여 다른 사람의 풀이를 참고하였다.

// map<int, int> map 의 방식으로 map을 정의하여
// key는 부분집합의 원소, value는 부분집합의 총 등장횟수 의 형태로 저장하였다. // 사실 이 부분을 첫번째 풀이 때 생각하지 못하여 코드가 길어졌다.

// for문을 돌며, 숫자가 아니면 map[stoi(str)]++; 의 형태로 해당 key값의 등장 횟수를 더해주었다.
// for문을 다 돌고나면, 등장횟수가 가장 많은 것이 answer의 맨 첫번째 원소가 되어야 하므로 reverse()를 해준다.

vector<int> solution2(string s) {
    vector<int> answer;
    map<int, int> map;

    s.erase(s.begin());
    s.erase(s.begin() + s.length() - 1);

    string temp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            temp.push_back(s[i]);
        }
        else if (!temp.empty()) {
            map[stoi(temp)]++;
            temp.clear();
        }
    }

    answer.resize(map.size());

    for (auto m : map) {
        answer[m.second - 1] = m.first;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}
// map �Ǵ� set�� Ȱ���ϴ� ����, Ž���鿡�� ����Ž�� ������� �� ���� ���� �� ����.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef pair<int, vector<int>> piv;

vector<piv> subsets;

// ù��° Ǯ��
// ���ڿ� s �� '{', '}', ',' �� ȥ�յǾ� �־ Ǯ�Ⱑ ó������ �ſ� ȭ�� ����.
// map �Ǵ� set�� �κ������� �̾Ƴ��µ� Ȱ���Ϸ� ������ ó������ ������ �� ���� �ʾƼ� �����ϰ�,
// ��� ������ �κ����յ��� "{{1,2,3},{2,1},{1,2,4,3},{2}}" �� ����� vector<vector<int>> ���·� �̾Ƴ����� �Ϸ��� ���� ������ �ȳ���.

// while���� ���� ������ �κ����յ��� vector<int> ���·� ���Ͽ���, vector<int>�� ũ�⿡ ���� �����ϱ� ����,
// vector<pair<int, vector<int>>> �� ���·� �����Ͽ���.
// ���� while���� ��� ��, sort()�� �ؼ� vector�� ũ�� ������ �������ְ�
// �κ����յ��� ���Ұ� �ߺ� �� �� �ֱ� ������, 
// set�� Ȱ���Ͽ� ������ ���Ұ� set�� ������ set�� answer�� �־��ְ�, �ִٸ� �Ѿ�� ������� �����Ͽ���.

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

// �ι�° Ǯ��
// map�� Ȱ���� Ǯ��
// ù��° Ǯ�̰� �ʹ� �����ϰ� ���ζ�� �����Ͽ� �ٸ� ����� Ǯ�̸� �����Ͽ���.

// map<int, int> map �� ������� map�� �����Ͽ�
// key�� �κ������� ����, value�� �κ������� �� ����Ƚ�� �� ���·� �����Ͽ���. // ��� �� �κ��� ù��° Ǯ�� �� �������� ���Ͽ� �ڵ尡 �������.

// for���� ����, ���ڰ� �ƴϸ� map[stoi(str)]++; �� ���·� �ش� key���� ���� Ƚ���� �����־���.
// for���� �� ������, ����Ƚ���� ���� ���� ���� answer�� �� ù��° ���Ұ� �Ǿ�� �ϹǷ� reverse()�� ���ش�.

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
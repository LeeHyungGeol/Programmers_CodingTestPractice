#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> map;

    for (auto phone : phone_book) {
        map[phone] = 1;
    }

    for (int i = 0; i < phone_book.size(); ++i) {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); ++j) {
            temp += phone_book[i][j];
            if (map[temp] && temp != phone_book[i]) {
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i) {
        // ���ξ ���ϹǷ� find�� ��ȯ������ 0��� ������ �߰��ؾ� �Ѵ�.
        if (phone_book[i + 1].find(phone_book[i]) != string::npos && phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            break;
        }
    }

    return answer;
}
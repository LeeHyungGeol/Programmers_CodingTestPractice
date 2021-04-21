#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

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

// �ٸ� ����� Ǯ�� 1 : substr()�� �̿�
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for (int i = 0; i < phoneBook.size() - 1; i++)
    {
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> hash_map;
    for (int i = 0; i < phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if (hash_map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}
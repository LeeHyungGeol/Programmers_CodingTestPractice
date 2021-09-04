// 연결리스트 구현, Set, Iterator를 이용한 풀이 가능

// Set은 Map과 마찬가지로 key를 기준으로 오름차순 자동 정렬된다.
// Set 자료구조는 내부적으로 이진 트리 구조, 삽입 / 삭제의 시간 복잡도가 O(logN) 
// next(), prev() 를 통해 현재 가리키는 Iterator의 양 옆을 탐색

#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct Node {
    bool removed;
    Node* prev;
    Node* next;
}Node;

Node List[1000000];
stack<Node*> Stack;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    for (int i = 1; i < n; ++i) {
        List[i - 1].next = &List[i];
        List[i].prev = &List[i - 1];
    }

    Node* cur = &List[k];

    for (string str : cmd) {
        if (str[0] == 'U') {
            int num = stoi(str.substr(2));
            while (num--) {
                cur = cur->prev;
            }
        }
        else if (str[0] == 'D') {
            int num = stoi(str.substr(2));
            while (num--) {
                cur = cur->next;
            }
        }
        else if (str[0] == 'C') {
            Stack.push(cur);
            cur->removed = true;

            Node* up = cur->prev;
            Node* down = cur->next;

            if (up) {
                up->next = down;
            }

            if (down) {
                down->prev = up;
                cur = down;
            }
            else {
                cur = up;
            }
        }
        else if (str[0] == 'Z') {
            Node* node = Stack.top();
            Stack.pop();

            node->removed = false;
            Node* up = node->prev;
            Node* down = node->next;

            if (up) {
                up->next = node;
            }
            if (down) {
                down->prev = node;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (List[i].removed == true) {
            answer += "X";
        }
        else {
            answer += "O";
        }
    }

    return answer;
}

//-------------------Set, iterator를 이용한 풀이----------------------//

#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

set<int> Set;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    stack<int> Stack;

    for (int i = 0; i < n; ++i) {
        Set.insert(i);
    }

    auto cur = Set.find(k);

    for (string str : cmd) {
        if (str[0] == 'U') {
            int num = stoi(str.substr(2));
            while (num--) {
                // cur = prev(cur);
                --cur;
            }
        }
        else if (str[0] == 'D') {
            int num = stoi(str.substr(2));
            while (num--) {
                // cur = next(cur);
                ++cur;
            }
        }
        else if (str[0] == 'C') {
            Stack.push(*cur);
            cur = Set.erase(cur); // 1, 2, 3 이 있을 때, 2를 삭제한다면, 2 다음 숫자인 3을 가리키는 iterator가 반환된다.

            if (cur == Set.end()) {
                // cur = prev(cur);
                --cur;
            }
        }
        else if (str[0] == 'Z') {
            Set.insert(Stack.top());
            Stack.pop();
        }
    }

    for (int num : Set) {
        answer[num] = 'O';
    }

    return answer;
}
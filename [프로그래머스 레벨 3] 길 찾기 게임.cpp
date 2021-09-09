// 이진 탐색 트리 구현, addNode(root, &Nodes[i]);

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef struct Node {
    int num, x, y;
    Node* left;
    Node* right;
}Node;

vector<Node> Nodes;
vector<int> PreOrder;
vector<int> PostOrder;

bool compare(Node& a, Node& b);
void addNode(Node* parent, Node* child);
void preorder(Node* root);
void postorder(Node* root);

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); ++i) {
        vector<int> node = nodeinfo[i];
        Nodes.push_back({ i + 1, node[0], node[1] });
    }

    sort(Nodes.begin(), Nodes.end(), compare);

    Node* root = &Nodes[0];

    for (int i = 1; i < nodeinfo.size(); ++i) {
        addNode(root, &Nodes[i]);
    }

    preorder(root);
    postorder(root);

    answer.push_back(PreOrder);
    answer.push_back(PostOrder);

    return answer;
}

bool compare(Node& a, Node& b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

void addNode(Node* parent, Node* child) {
    if (parent->x > child->x) {
        if (parent->left == NULL) {
            parent->left = child;
        }
        else {
            addNode(parent->left, child);
        }
    }
    else if (parent->x < child->x) {
        if (parent->right == NULL) {
            parent->right = child;
        }
        else {
            addNode(parent->right, child);
        }
    }
}

void preorder(Node* cur) {
    if (cur == NULL) {
        return;
    }
    PreOrder.push_back(cur->num);
    preorder(cur->left);
    preorder(cur->right);
}

void postorder(Node* cur) {
    if (cur == NULL) {
        return;
    }
    postorder(cur->left);
    postorder(cur->right);
    PostOrder.push_back(cur->num);
}
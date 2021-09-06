//stable_sort() ���
//stable_sort() : ���� ���ؿ� ���� ���̰� ���ٸ� ���� �Է¿��� �־��� ������ �����ϴ� ����
//���� ���� O : ���� ���� Merge Sort , ���� ���� Bubble Sort, ���� ���� Insertion Sort
//���� ���� X : �� ���� Quick Sort

// stable_sort() : ���� ���ؿ� ���� ���̰� ���ٸ� ���� �Է¿��� �־��� ������ �����ϴ� ����
// stoi() : stoi("000321abc000987") == 321

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareAlpha(string a, string b);
bool compareNum(string a, string b);
int getNumIndex(string str);

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compareNum);
    stable_sort(files.begin(), files.end(), compareAlpha);

    return files;
}

bool compareAlpha(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    return a.substr(0, getNumIndex(a)) < b.substr(0, getNumIndex(b));
}

bool compareNum(string a, string b) {
    return stoi(a.substr(getNumIndex(a))) < stoi(b.substr(getNumIndex(b)));
}

int getNumIndex(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            return i;
        }
    }
}

//--------------------���� Ǯ��----------------------//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;

bool cmp(const piss& a, const piss& b) {
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<piss> tmp;
    for (int i = 0; i < files.size(); ++i) {
        string str = files[i];
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        string s = "", num = "";
        bool flag = false;
        for (int j = 0; j < str.size(); ++j) {
            while (isdigit(str[j])) {
                num += str[j]; ++j;  flag = true;
            }
            if (flag) break;
            s += str[j];
        }
        cout << "num : " << num << ", s : " << s << '\n';
        int n = stoi(num);
        tmp.push_back({ {n,s},files[i] });
    }
    stable_sort(tmp.begin(), tmp.end(), cmp);
    for (int i = 0; i < tmp.size(); ++i) {
        answer.push_back(tmp[i].second);
    }
    return answer;
}
int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    solution(files);
    return 0;
}
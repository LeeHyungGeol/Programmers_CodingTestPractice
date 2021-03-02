//stable_sort() ���
//stable_sort() : ���� ���ؿ� ���� ���̰� ���ٸ� ���� �Է¿��� �־��� ������ �����ϴ� ����
//���� ���� O : ���� ���� Merge Sort , ���� ���� Bubble Sort, ���� ���� Insertion Sort
//���� ���� X : �� ���� Quick Sort
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
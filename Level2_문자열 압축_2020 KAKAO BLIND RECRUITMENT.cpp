//kmp�˰���, �����Լ�(getPartialMatch())�� ����غ��� ������, �� ������ �װ� ���°� �ƴϾ���.
//�׳� �ܼ��� �տ��� ���� ���ڿ��� 1��, 2��, 3���� �߶󰡸鼭 ���س����� �׷� ��������.
//�� ���� ���� �ؼ� �ð��� �������� ���� �ɷȴ�.
//������ �� ����� �ٽ� Ǯ���.
#include <string>
#include <vector>
#include <algorithm>    // std::min
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    //i�� �ڸ��� ������ ����
    for (int i = 1; i <= s.size() / 2; ++i) {
        string newString = "";
        string tmp = s.substr(0, i);
        int cnt = 1;
        //j�� ���ڿ��� ������
        for (int j = i; j < s.size(); j += i) {
            if (tmp == s.substr(j, i)) {
                cnt++;
            }
            else {
                if (cnt > 1) newString += to_string(cnt);
                newString += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt > 1) newString += to_string(cnt);
        newString += tmp;
        //cout<<newString<<'\n';
        //int newStringSize=newString.size();
        //min�Լ� �ȿ� (int)�ȳ־��ָ� Ʋ��
        answer = min(answer, (int)newString.size());
    }
    return answer;
}
void print(string s, int answer) {
    int t = solution(s);
    if (answer == t)
        cout << "����" << endl;
    else
        cout << "Ʋ��" << endl;
}

int main() {
    print("a", 1);
    print("aaaaa", 2);
    print("aaaaaaaaaa", 3);
    print("aabbaccc", 7);
    print("ababcdcdababcdcd", 9);
    print("abcabcdede", 8);
    print("abcabcabcabcdededededede", 14);
    print("xababcdcdababcdcd", 17);
    return 0;
}
//�� ��ȭ Ű�е忡�� �޼հ� �������� �����հ������� �̿��ؼ� ���ڸ��� �Է��Ϸ��� �մϴ�.
//�� ó�� �޼� �����հ�����* Ű�е忡 ������ �����հ����� # Ű�е� ��ġ���� �����ϸ�, �����հ����� ����ϴ� ��Ģ�� ������ �����ϴ�.

//1.�����հ����� �����¿� 4���� �������θ� �̵��� �� ������ Ű�е� �̵� �� ĭ�� �Ÿ��� 1�� �ش��մϴ�.
//2.���� ���� 3���� ���� 1, 4, 7�� �Է��� ���� �޼� �����հ����� ����մϴ�.
//3.������ ���� 3���� ���� 3, 6, 9�� �Է��� ���� ������ �����հ����� ����մϴ�.
//4.��� ���� 4���� ���� 2, 5, 8, 0�� �Է��� ���� �� �����հ����� ���� Ű�е��� ��ġ���� �� ����� �����հ����� ����մϴ�.
//4 - 1. ���� �� �����հ����� �Ÿ��� ���ٸ�, ���������̴� ������ �����հ���, �޼����̴� �޼� �����հ����� ����մϴ�.

//������� ���� ��ȣ�� ��� �迭 numbers, �޼��������� ������������ ���� ��Ÿ���� ���ڿ� hand�� �Ű������� �־��� ��, 
//�� ��ȣ�� ���� �����հ����� �޼��� �� �������� ���� ��Ÿ���� ���ӵ� ���ڿ� ���·� return �ϵ��� solution �Լ��� �ϼ����ּ���.
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
vector<string> X = { {"147*"},{"2580"},{"369#"} };//0,1,2
vector<string> Y = { {"123"},{"456"},{"789"}, {"*0#"} };//0,1,2,3

int findY(int num) {
    string n = to_string(num);
    for (int i = 0; i < Y.size(); ++i) {
        //string���� find�Լ��� ������ ã�� ��� int���� �ƴ� string���¿��� �Ѵ�.
        if (Y[i].find(n) != string::npos)
            return i;
    }
}
int findX(int num) {
    string n = to_string(num);
    for (int i = 0; i < X.size(); ++i) {
        //string���� find�Լ��� ������ ã�� ��� int���� �ƴ� string���¿��� �Ѵ�.
        if (X[i].find(n) != string::npos)
            return i;
    }
}
int dist(const pii& left, const pii& right) {
    return abs(left.first - right.first) + abs(left.second - right.second);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pii L = { 0,3 }, R = { 2,3 };
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            L = { findX(numbers[i]), findY(numbers[i]) };
            //cout<<"L : " << L.first << " " << L.second << '\n';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            R = { findX(numbers[i]), findY(numbers[i]) };
            //cout << "R : " << R.first << " " << R.second << '\n';

        }
        else {
            pii location = { findX(numbers[i]), findY(numbers[i]) };
            //cout << "location : " << location.first << " " << location.second << '\n';
            //cout << "dist L: " << dist(location, L) << '\n';
            //cout << "dist R: " << dist(location, R) << '\n';
            if (dist(location, L) > dist(location, R)) {
                answer += "R";
                R = location;
            }
            else if (dist(location, L) < dist(location, R)) {
                answer += "L";
                L = location;
            }
            else {
                if (hand == "right") {
                    answer += "R";
                    R = location;
                }
                else {
                    answer += "L";
                    L = location;
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string s = "right";
    cout << solution(numbers, s) << '\n';
}
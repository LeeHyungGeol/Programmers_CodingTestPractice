//이 전화 키패드에서 왼손과 오른손의 엄지손가락만을 이용해서 숫자만을 입력하려고 합니다.
//맨 처음 왼손 엄지손가락은* 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.

//1.엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
//2.왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
//3.오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
//4.가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.
//4 - 1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용합니다.

//순서대로 누를 번호가 담긴 배열 numbers, 왼손잡이인지 오른손잡이인 지를 나타내는 문자열 hand가 매개변수로 주어질 때, 
//각 번호를 누른 엄지손가락이 왼손인 지 오른손인 지를 나타내는 연속된 문자열 형태로 return 하도록 solution 함수를 완성해주세요.
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
        //string에서 find함수를 쓰려면 찾는 대상도 int형이 아닌 string형태여야 한다.
        if (Y[i].find(n) != string::npos)
            return i;
    }
}
int findX(int num) {
    string n = to_string(num);
    for (int i = 0; i < X.size(); ++i) {
        //string에서 find함수를 쓰려면 찾는 대상도 int형이 아닌 string형태여야 한다.
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
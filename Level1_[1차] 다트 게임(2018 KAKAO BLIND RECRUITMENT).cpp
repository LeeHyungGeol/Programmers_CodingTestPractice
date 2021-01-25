#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
//���� Ǯ��
int solution(string dartResult) {
    int answer = 0;
    vector<int> num;
    for (int i = 0; i < dartResult.size(); ++i) {
        if (48 <= dartResult[i] && dartResult[i] <= 57) {
            if (dartResult[i + 1] == '0') {
                num.push_back(10);
                i++;
                continue;
            }
            num.push_back(dartResult[i] - '0');
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            if (dartResult[i] == 'D') num[num.size() - 1] = pow(num[num.size() - 1], 2);
            if (dartResult[i] == 'T') num[num.size() - 1] = pow(num[num.size() - 1], 3);
        }
        else if (dartResult[i] == '*' || dartResult[i] == '#') {
            if (dartResult[i] == '*') {
                if (num.size() == 1) num[num.size() - 1] *= 2;
                else {
                    num[num.size() - 1] *= 2;
                    num[num.size() - 2] *= 2;
                }
            }
            else if (dartResult[i] == '#') num[num.size() - 1] *= -1;
        }
    }
    for (int i = 0; i < num.size(); ++i)
        answer += num[i];

    return answer;
}
//�ٸ� ����� Ǯ��: sstream���̺귯���� Ȱ���Ͽ� ������ �ε����� ������� �ʰ� ss.get()�Լ��� ����ϰ� Ǯ���Ͽ���.
int solution2(string dartResult) {
    //stringstream ���̺귯�� Ȱ�� 
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
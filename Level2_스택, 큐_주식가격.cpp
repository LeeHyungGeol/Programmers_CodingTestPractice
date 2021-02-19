//����� ��
//      prices	           return
// {1, 2, 3, 2, 3}  |  {4, 3, 1, 1, 0}
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size());
    for (int i = 0; i < prices.size(); ++i) {
        bool flag = true;
        for (int j = i; j < prices.size(); ++j) {
            if (prices[i] > prices[j]) { answer[i] = j - i; flag = false; break; }
        }
        if (flag) answer[i] = prices.size() - 1 - i;
    }


    return answer;
}
//�ٸ� ����� Ǯ��: ������ �̿��� Ǯ��
vector<int> solution2(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();

    for (int i = 0; i < size; i++)
    {
        // ������ �������鼭 ������ �������� �����ϸ�
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        // ������ �ö󰥶����� ���ؿ� ����
        s.push(i);
    }

    // ���ؿ� �����͵��� �������
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}
int main() {
    vector<int> prices = { 1, 2, 3, 2, 3 };
    vector<int> answer;
    answer = solution2(prices);
    for (auto p : answer) {
        cout << p << ' ';
    }
    return 0;
}
// Tree, Parent[next] = cur : next의 부모는 cur이다, dfs

#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> Parent;
map<string, int> Profit;

void updateProfit(string name, int money);

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); ++i) {
        Parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); ++i) {
        updateProfit(seller[i], amount[i] * 100);
    }

    for (string name : enroll) {
        answer.push_back(Profit[name]);
    }

    return answer;
}

void updateProfit(string name, int money) {
    if (name == "-" || money < 1) {
        return;
    }

    int giveMoney = money * 0.1;
    Profit[name] += (money - giveMoney);

    updateProfit(Parent[name], giveMoney);
}
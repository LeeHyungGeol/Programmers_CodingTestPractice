#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;

    for (int i = 0; i < numbers.size(); ++i) {
        temp.push_back(to_string(numbers[i]));
    }

    sort(temp.begin(), temp.end(), compare);

    if (temp[0] == "0") {
        return answer = "0";
    }
    else {
        for (int i = 0; i < temp.size(); ++i) {
            answer += temp[i];
        }
        return answer;
    }
}
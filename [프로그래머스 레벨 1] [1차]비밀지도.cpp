#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n, int size);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        answer.push_back(toBinary(arr1[i] | arr2[i], n));
    }

    return answer;
}

string toBinary(int n, int size) {
    string result = "";
    while (n) {
        result += (n % 2) ? '#' : ' ';
        n /= 2;
    }

    while (result.length() < size) {
        result += ' ';
    }

    reverse(result.begin(), result.end());

    return result;
}
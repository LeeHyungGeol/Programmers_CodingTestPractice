#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr[10001];
vector<string> reverseArr[10001];

string replaceAll(string str, string from, string to);
int countByRange(vector<string>& v, string leftValue, string rightValue);

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); ++i) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reverseArr[word.size()].push_back(word);
    }

    for (int i = 0; i < 10001; ++i) {
        sort(arr[i].begin(), arr[i].end());
        sort(reverseArr[i].begin(), reverseArr[i].end());
    }

    for (int i = 0; i < queries.size(); ++i) {
        string query = queries[i];
        int result = 0;

        if (query[0] == '?') {
            reverse(query.begin(), query.end());
            result = countByRange(reverseArr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        else {
            result = countByRange(arr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        answer.push_back(result);
    }

    return answer;
}

string replaceAll(string str, string from, string to) {
    //string 처음부터 검사
    int pos = 0;
    //from을 찾을 수 없을 때까지
    while ((pos = str.find(from, pos)) != string::npos)
    {
        str.replace(pos, from.length(), to);
        // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
        pos += to.length();
    }
    return str;
}

int countByRange(vector<string>& v, string leftValue, string rightValue) {
    int leftIndex = lower_bound(v.begin(), v.end(), leftValue) - v.begin();
    int rightIndex = upper_bound(v.begin(), v.end(), rightValue) - v.begin();

    return rightIndex - leftIndex;
}
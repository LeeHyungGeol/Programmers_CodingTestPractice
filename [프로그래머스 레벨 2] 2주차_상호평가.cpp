// #include <algorithm> 의 count()
// #include <numeric> 의 accumulate() 
// 2개의 메서드를 잘 기억하자!!

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

char getGrade(double num);

string solution(vector<vector<int>> scores) {
    string answer = "";
    int size = scores.size();
    vector<vector<int>> temp(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[i][j] = scores[j][i];
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        int Max = *max_element(temp[i].begin(), temp[i].end());
        int maxCount = count(temp[i].begin(), temp[i].end(), Max);
        int Min = *min_element(temp[i].begin(), temp[i].end());
        int minCount = count(temp[i].begin(), temp[i].end(), Min);
        int sum = accumulate(temp[i].begin(), temp[i].end(), 0);
        int newSize = size;

        if ((temp[i][i] == Max && maxCount == 1) || (temp[i][i] == Min && minCount == 1)) {
            --newSize;
            sum -= temp[i][i];
        }

        sum = (double)sum / newSize;

        answer += getGrade(sum);
    }

    return answer;
}

char getGrade(double num) {
    if (num >= 90) {
        return 'A';
    }
    else if (num >= 80) {
        return 'B';
    }
    else if (num >= 70) {
        return 'C';
    }
    else if (num >= 50) {
        return 'D';
    }
    else {
        return 'F';
    }
}
// 문자열, 완전탐색, 시간 계산(전체시간을 초 단위로 바꾸기)

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

stringstream SS;
vector<pdd> Times;

int solution(vector<string> lines) {
    int answer = 0;

    for (string line : lines) {
        string date, time, processingTime;
        SS.str(line);

        SS >> date >> time >> processingTime;

        double hour = stod(time.substr(0, 2));
        double minute = stod(time.substr(3, 2));
        double second = stod(time.substr(6));

        processingTime.pop_back();
        double process = stod(processingTime);

        double endTime = 3600 * hour + 60 * minute + (double)second;
        double startTime = endTime - process + 0.001;

        Times.push_back({ startTime, endTime });

        SS.clear();
    }


    for (int i = 0; i < Times.size(); ++i) {
        double endTime = Times[i].second;
        int cnt = 0;

        for (int j = i; j < Times.size(); ++j) {
            double startTime = Times[j].first;

            if (startTime < endTime + 1) {
                ++cnt;
            }
        }

        answer = max(answer, cnt);
    }

    return answer;
}


//-----------2번째 실패한 풀이--------------//

// 이분 탐색인 lower_bound() 이용

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

stringstream SS;
vector<pdd> Times;

int countByRange(vector<double>& arr, double leftValue, double rightValue);

int solution(vector<string> lines) {
    int answer = 0;
    vector<double> startTimes, endTimes;

    for (string line : lines) {
        string date, time, processingTime;
        SS.str(line);

        SS >> date >> time >> processingTime;

        double hour = stod(time.substr(0, 2));
        double minute = stod(time.substr(3, 2));
        double second = stod(time.substr(6));

        processingTime.pop_back();
        double process = stod(processingTime);

        double endTime = 3600 * hour + 60 * minute + (double)second;
        double startTime = endTime - process + 0.001;

        endTimes.push_back(endTime);
        startTimes.push_back(startTime);

        SS.clear();
    }


    for (int i = 0; i < startTimes.size(); ++i) {
        int value = countByRange(endTimes, startTimes[i], endTimes[i] + 1);
        answer = max(answer, value);
    }

    return answer;
}

int countByRange(vector<double>& arr, double leftValue, double rightValue) {
    int leftIndex = lower_bound(arr.begin(), arr.end(), leftValue) - arr.begin();
    int rightIndex = lower_bound(arr.begin(), arr.end(), rightValue) - arr.begin();
    return rightIndex - leftIndex;
}
//  구현, 시간계산(분으로 바꾸기)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Times;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    for (string time : timetable) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3));

        Times.push_back(60 * hour + minute);
    }

    sort(Times.begin(), Times.end());

    int bus = 540;
    int index = 0;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int total = m;

        for (int j = index; j < Times.size(); ++j) {
            if (Times[j] <= bus) {
                ++index;
                --total;
                if (total <= 0) {
                    break;
                }
            }
        }

        if (i + 1 == n) {
            if (total == 0) {
                result = Times[index - 1] - 1;
            }
            else {
                result = bus;
            }
        }

        bus += t;
        if (bus >= 1440) {
            break;
        }
    }

    string hour = "";
    int h = result / 60;

    if (h < 10) {
        hour += "0" + to_string(h);
    }
    else {
        hour += to_string(h);
    }

    answer += hour + ":";

    string minute = "";
    int minu = result % 60;

    if (minu < 10) {
        minute += "0" + to_string(minu);
    }
    else {
        minute += to_string(minu);
    }

    answer += minute;

    return answer;
}
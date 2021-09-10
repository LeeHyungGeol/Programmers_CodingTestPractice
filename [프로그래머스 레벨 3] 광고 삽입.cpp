// sliding window, sprintf(buf, "%02d:%02d:%02d", t/3600, t/60%60, t%60);

#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;

int Times[360000];
stringstream SS;

int timeToSecond(string str);

int ttoi(string x) {
    int h, m, s;
    sscanf(x.c_str(), "%02d:%02d:%02d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}
string itot(int x) {
    char xx[19];
    sprintf(xx, "%02d:%02d:%02d", x / 3600, (x / 60) % 60, x % 60);
    return xx;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer;

    for (string log : logs) {
        int start = timeToSecond(log.substr(0, 8));
        int end = timeToSecond(log.substr(9, 8));

        for (int i = start; i < end; ++i) {
            ++Times[i];
        }
    }

    int playTime = timeToSecond(play_time);
    int advTime = timeToSecond(adv_time);
    ll sum = 0;

    for (int i = 0; i < advTime; ++i) {
        sum += Times[i];
    }

    ll maxSum = sum, maxIndex = 0;

    for (int i = advTime; i < playTime; ++i) {
        sum = sum + Times[i] - Times[i - advTime];

        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i - advTime + 1;
        }
    }

    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", maxIndex / 3600, maxIndex / 60 % 60, maxIndex % 60);
    answer = buf;

    return answer;
}

int timeToSecond(string time) {
    SS.str(time);
    int hour, minute, second;
    char temp;

    SS >> hour >> temp >> minute >> temp >> second;
    SS.clear();

    return 3600 * hour + 60 * minute + second;
}
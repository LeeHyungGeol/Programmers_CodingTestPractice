#include <string>
#include <vector>

using namespace std;

string days[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
int month[] = { 31,29,31,30,31,30,31,31,30,31,30 };
string solution(int a, int b) {
    int sum = 4;
    for (int i = 0; i < a - 1; ++i)
    {
        sum += month[i];
    }
    return days[(sum + b) % 7];

}
string solution2(int a, int b) {
    string answer = "";
    int day[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    for (int i = 0; i < a - 1; ++i) {
        sum += day[i];
    }
    sum += b;
    switch (sum % 7) {
    case 0:
        return "THU";
    case 1:
        return "FRI";
    case 2:
        return "SAT";
    case 3:
        return "SUN";
    case 4:
        return "MON";
    case 5:
        return "TUE";
    case 6:
        return "WED";
    }
    //return answer;
}
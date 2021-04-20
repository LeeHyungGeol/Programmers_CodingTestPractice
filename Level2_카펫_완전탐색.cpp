#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int carpet = brown + yellow;

    for (int i = carpet; i > 0; --i) {
        if (carpet % i == 0) {
            int w = i;
            int h = carpet / i;
            if ((w - 2) * (h - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;
// a와 b의 내적은 a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] 
vector<int> a = {1,2,3,4}, b = {-3,-1,0,2};
//answer==3
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); ++i) {
        answer += (a[i] * b[i]);
    }
    return answer;
}
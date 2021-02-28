//페이지 교체 알고리즘은 페이징 기법으로 메모리를 관리하는 운영체제에서, 
//페이지 부재가 발생 하여 새로운 페이지를 할당하기 위해 현재 할당된 페이지 중 어느 것과 교체할지를 결정하는 방법입니다.

//LFU : 가장 적은 횟수를 참조하는 페이지를 교체
//단점: 참조될 가능성이 많음에도 불구하고 횟수에 의한 방법이므로 최근에 사용된 프로그램을 교체시킬 가능성이 있고, 해당 횟수를 증가시키므로 오버헤드 발생

//LRU: 가장 오랫동안 참조되지 않은 페이지를 교체
//단점 : 프로세스가 주기억장치에 접근할 때마다 참조된 페이지에 대한 시간을 기록해야함.큰 오버헤드가 발생

//여기서는 LRU알고리즘을 사용해야 함.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;

    for (int i = 0; i < cities.size(); ++i) {
        //문자열의 알파벳을 모두 소문자로 바꾸는 함수
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        bool flag = true;
        //erase함수를 사용하기 위해 iterator를 사용
        for (auto it = v.begin(); it != v.end(); ++it) {
            //메모리에 해당 문자열이 있는 경우 : hit
            if (*it == cities[i]) {
                flag = false;
                answer++;
                v.erase(it);
                v.push_back(cities[i]);
                break;
            }
        }
        //메모리에 해당 문자열이 없는 경우 : page fault
        if (flag) {
            answer += 5;
            if (v.size() < cacheSize) v.push_back(cities[i]);
            else if (cacheSize != 0 && v.size() >= cacheSize) {
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
        }
    }

    return answer;
}
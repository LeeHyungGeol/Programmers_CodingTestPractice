// LRU 알고리즘을 기억하자.
// deque, queue, vector를 이용하여 문제를 풀 수 있다.

// deque도 operator[] 를 이용하여 array처럼 값을 접근할 수 있다는 것을 처음 배웠다.
// iterator사용에도 익숙해지자.

#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;

    if (cacheSize == 0) {
        answer += 5 * cities.size();
        return answer;
    }

    for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (cache.size() < cacheSize) {
            bool flag = false;

            for (int i = 0; i < cache.size(); ++i) {
                if (cache[i] == city) {
                    cache.erase(cache.begin() + i);
                    cache.push_back(city);
                    flag = true;
                    break;
                }
            }

            if (flag) {
                answer += 1;
                continue;
            }
            else {
                cache.push_back(city);
                answer += 5;
            }
        }
        else {
            bool flag = false;
            for (int i = 0; i < cache.size(); ++i) {
                if (cache[i] == city) {
                    cache.erase(cache.begin() + i);
                    cache.push_back(city);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                answer += 1;
            }
            else {
                cache.pop_front();
                cache.push_back(city);
                answer += 5;
            }
        }
    }

    return answer;
}

//-------------vector를 이용한 풀이------------//

#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if (cacheSize == 0) {
        answer += 5 * cities.size();
        return answer;
    }

    for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        if (cache.size() < cacheSize) {
            bool flag = false;

            for (auto it = cache.begin(); it != cache.end(); ++it) {
                if (*it == city) {
                    cache.erase(it);
                    cache.push_back(city);
                    flag = true;
                    break;
                }
            }

            if (flag) {
                answer += 1;
                continue;
            }
            else {
                cache.push_back(city);
                answer += 5;
            }
        }
        else {
            bool flag = false;

            for (auto it = cache.begin(); it != cache.end(); ++it) {
                if (*it == city) {
                    cache.erase(it);
                    cache.push_back(city);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                answer += 1;
            }
            else {
                cache.erase(cache.begin());
                cache.push_back(city);
                answer += 5;
            }
        }
    }

    return answer;
}
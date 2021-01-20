//에라토스테네스의 체 알고리즘
//""다수의 자연수에 대하여 소수 여부를 판별""할 때 사용하는 알고리즘
//에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾을 때 사용 가능하다.

//동작과정
//1. 2부터 N까지의 모든 자연수를 나열한다.
//2. 남은 수 중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다.
//3. 남은 수 중에서 i의 배수를 모두 제거한다.(i는 제거하지 않는다.)
//4. 더 이상 반복할 수 없을 때까지 2와 3의 과정을 반복한다.

//에라토스테네스의 체 알고리즘 시간 복잡도: O(NloglogN) 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool isPrimeNumber(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrimeNumber(i)) answer++;
    }
    return answer;
}
int SieveOfEratosthenes(int n) {
    int answer = 0;
    vector<bool> tmp(n + 1, true);

    for (int i = 2; i < n + 1; i++) {
        if (tmp[i] == true) {
            for (int j = 2; i * j < n + 1; j++) tmp[i * j] = false;
            answer++;
        }
    }

    return answer;
}
int n = 1000000;//2부터 1000000까지의 모든 수에 대하여 소수 판별
vector<bool> arr(n + 1, true);//처음엔 모든 수가 소수(true)인 것으로 초기화(0과 1은 제외)
//에라토스테네스의 체 알고리즘 수행
int SieveOfEratosthenes2(int n) {
    int answer = 0;
    //2부터 n의 제곱근까지의 모든 수를 확인
    for (int i = 2; i <= sqrt(n); ++i) {
        //i가 소수인 경우(남은 수인 경우)
        if (arr[i] == true) {
            int j = 2;
            //i를 제외한 n까지의 i의 모든 배수를 지우기
            while (i * j <= n) {
                arr[i * j] = false;
                j++;
            }
        }
    }
    for (int i = 2; i <= n; ++i)//모든 소수 체크
        if (arr[i]) answer++;
    return answer;
}
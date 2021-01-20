//�����佺�׳׽��� ü �˰���
//""�ټ��� �ڿ����� ���Ͽ� �Ҽ� ���θ� �Ǻ�""�� �� ����ϴ� �˰���
//�����佺�׳׽��� ü�� N���� �۰ų� ���� ��� �Ҽ��� ã�� �� ��� �����ϴ�.

//���۰���
//1. 2���� N������ ��� �ڿ����� �����Ѵ�.
//2. ���� �� �߿��� ���� ó������ ���� ���� ���� �� i�� ã�´�.
//3. ���� �� �߿��� i�� ����� ��� �����Ѵ�.(i�� �������� �ʴ´�.)
//4. �� �̻� �ݺ��� �� ���� ������ 2�� 3�� ������ �ݺ��Ѵ�.

//�����佺�׳׽��� ü �˰��� �ð� ���⵵: O(NloglogN) 
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
int n = 1000000;//2���� 1000000������ ��� ���� ���Ͽ� �Ҽ� �Ǻ�
vector<bool> arr(n + 1, true);//ó���� ��� ���� �Ҽ�(true)�� ������ �ʱ�ȭ(0�� 1�� ����)
//�����佺�׳׽��� ü �˰��� ����
int SieveOfEratosthenes2(int n) {
    int answer = 0;
    //2���� n�� �����ٱ����� ��� ���� Ȯ��
    for (int i = 2; i <= sqrt(n); ++i) {
        //i�� �Ҽ��� ���(���� ���� ���)
        if (arr[i] == true) {
            int j = 2;
            //i�� ������ n������ i�� ��� ����� �����
            while (i * j <= n) {
                arr[i * j] = false;
                j++;
            }
        }
    }
    for (int i = 2; i <= n; ++i)//��� �Ҽ� üũ
        if (arr[i]) answer++;
    return answer;
}
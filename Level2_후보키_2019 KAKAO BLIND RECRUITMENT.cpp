//��Ʈ����ũ Ȥ�� dfs�� Ǯ �� �ִ� ����
//map�� ����Ͽ� ������ ���������� �Ͽ� Ǯ��� ������ �ڵ尡 �ʹ� �������� �� ���Ƽ� ����
//�˻��غ��Ҵ��� set�� ��Ʈ����ũ�� �̿��� Ǯ�̰� ���� ����ϰ� �ǿ����̶�� �Ǵ�
//�ٽ� �ѹ� ��Ʈ����ũ�� �����ϰ� �����غ��Ҵ�.
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
//�ĺ�Ű�� �ּҼ��� �˻��ϴ� �Լ�
bool key_min(vector<int>& ans, int now) {
    for (int i = 0; i < ans.size(); ++i) {
        //���� ��� ans[i]=0110�̰�, now=0111�� ������ �� �̰��� & ������ ���� �� 0110�̵ȴ�.
        //���� �̹� �ִ� �������� �Ǿ���� ��� false�� ��ȯ
        if ((ans[i] & now) == ans[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int row = relation.size();//������ ����
    int col = relation[0].size();//������ ����//�Ӽ��� ����
     // ���� ����� ��
    /*
     1(0001) - �й�
     2(0010) - �̸�
     3(0011) - �̸�, �й�
     4(0100) - ����
     5(0101) - �й�, ����
     6(0110) - �̸�, ����
     7(0111) - �й�, �̸�, ����
     8(1000) - �г�
     9(1001) - �й�, �г�
     10(1010) - �̸�, �г�
     11(1011) - �й�, �̸�, �г�
     12(1100) - �̸�, �й�
     13(1101) - �й�, ����, �г�
     14(1110) - �̸�, ����, �г�
     15(1111) - �й�, �̸�, ����, �г�
     */
    for (int i = 1; i < (1 << col); ++i) {
        set<string> set;
        for (int j = 0; j < row; ++j) {
            string s = "";
            for (int k = 0; k < col; ++k) {
                if (i & (1 << k)) s += relation[j][k] + ' ';
            }
            //cout<<s<<'\n';
            //������ ������ ����� ���� string���� set�� insert
            //���ϼ��� ������� ���� ������ ��쵵 �ϴ� ����.
            set.insert(s);
        }
        //���ϼ� + �ּҼ� �˻�
        //set�� size�� row�� ����(����, Ʃ���� ����)�� ���ƾ� i�� �ش��ϴ� ������ ���ϼ��� ����� Ű�� �����̶�� �� �� �ִ�.
        //key_min() : �ּҼ��� �˻��ϴ� �Լ�, answer�� ����ִ� ���հ� ���� ������� ������ &�����Ͽ� �� ����� �̹� answer�� ���ԵǾ� ������ false�� ��ȯ, ���� �����̶�� true�� ��ȯ
        //�� 2���� ��츦 ��� ������ answer.push_back() ����
        if (set.size() == row && key_min(answer, i)) answer.push_back(i);
    }
    //answer.size()�� �ĺ�Ű�� �� ����
    return (int)answer.size();
}
int main() {
    vector<vector<string>> relation = { {"100","ryan","music","2"} ,{"200","apeach","math","2"},{"300","tube","computer","3"}
    ,{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };

    cout << solution(relation) << '\n';

    return 0;
}
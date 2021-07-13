#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	vector<string>input(3, "");	// given input
	input[0] = "1 Kim 89";
	input[1] = "2 Moon 100";
	input[2] = "3 Chan 78";

	for (int i = 0; i < input.size(); i++)
	{
		int num, score;
		string name;

		stringstream ss;	
		ss.str(input[i]);

		ss >> num;
		ss >> name;
		ss >> score;

		cout << num << " " << name << " " << score << endl;
		// ���� �ʿ��� �ڷ� ������ �����Ͽ� Ȱ���Ѵ�.

		ss.clear();
	}

	int n;
	stringstream ss2;
	ss2.str("12 345 6789 0 -12");
	while (ss2 >> n) {
		cout << n << '\n';
	}
	ss2.clear();
	/*
	��� istream�� �� �̻� �Է¹��� ���� ���µ� �Է��� ������ �ϸ� 0�� ��ȯ�մϴ�. 
	n�� 0�� ���� ���� �ƴմϴ�!!
	�׷��� �̷� ���� �����մϴ�. 
	�ٸ�, Ű����� �Է¹޴� �� ������ cin������ �̷� ������ ȿ���� ���Ⱑ ���������δ� ��ư�,
	���� �Է¿����� �� ����� ���մϴ�.

	[����] https://m.blog.naver.com/kks227/220245263973
	*/

	return 0;
}
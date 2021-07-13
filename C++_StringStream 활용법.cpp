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
		// 이후 필요한 자료 구조에 저장하여 활용한다.

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
	사실 istream은 더 이상 입력받을 값이 없는데 입력을 받으려 하면 0을 반환합니다. 
	n에 0이 들어가는 것이 아닙니다!!
	그래서 이런 것이 가능합니다. 
	다만, 키보드로 입력받는 게 보통인 cin에서는 이런 것으로 효과를 보기가 정상적으로는 어렵고,
	파일 입력에서는 이 방법이 통합니다.

	[참고] https://m.blog.naver.com/kks227/220245263973
	*/

	return 0;
}
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
	}

	return 0;
}
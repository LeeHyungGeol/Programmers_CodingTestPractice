//https://jhnyang.tistory.com/116

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string numbers = "0123456789";
    string full = numbers.substr();
    string sub = numbers.substr(3, 5);
    string a = numbers.substr(0);

    cout << "Full String: " << full << endl;
    cout << "Sub String: " << sub << endl;
    cout << a << '\n';
}
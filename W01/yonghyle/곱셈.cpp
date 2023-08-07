#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long num1, num2, mul1, mul2, mul3, result;
	cin >> num1 >> num2;

	mul1 = num1 * (num2 % 10);
	mul2 = num1 * (num2 / 10 % 10);
	mul3 = num1 * (num2 / 100);
	result = mul1 + mul2 * 10 + mul3 * 100;

	cout << mul1 << "\n" << mul2 << "\n" << mul3 << "\n" << result;
}
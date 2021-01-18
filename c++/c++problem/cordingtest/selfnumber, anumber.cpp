#include<iostream>
#include <list>
#include <string>

using namespace std;
//---------------------------------------------------------------------------
// self�ѹ� ���ϱ�
//int main() {
//	constexpr int maxNum = 5000;
//	bool arr[maxNum] = { false };
//	for (int i = 1; i < maxNum; ++i) {
//		int num = i;
//		int numSum = 0;
//		while (true) {
//			numSum += num % 10;
//			num /= 10;
//			if (0 == num) break;
//		}
//		numSum += i;
//		if (numSum < maxNum) {
//			arr[numSum] = true;
//		}
//	}
//
//	for (int i = 1; i < maxNum; ++i) {
//		if (false == arr[i]) {
//			cout << i << ", ";
//		}
//	}
//
//}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// A Number ���ϱ�
// f(x) = K �ڸ��� x�� ������ ���� ������ K�ڸ��� ���� ���� x�� ������ 1
// f(x) = 1 �̸� A Number�̴�
#include<cmath>
#include<set>
constexpr int maxPow = 10;
long long fivePow[maxPow];
long long tenPow[maxPow];
set<long long> candidateNum;
set<long long> aNum;
int getLen(long long num) {
	string n = to_string(num);
	return n.length();
}

bool isANum(long long num) {
	long long mul = (num) * (num - 1);
	int len = getLen(num);

	if (mul % tenPow[len] == 0)
	{
		return true;
	}
	return false;
}

int main() {
	
	
	int n1 = 1;
	int n2 = 1;
	

	for (int i = 0; i < maxPow; ++i) {
		fivePow[i] = pow(5, i);
		tenPow[i] = pow(10, i);
		/*fivePow[i] = n1;
		n1 *= 5;
		tenPow[i] = n2;
		n2 *= 10;*/
	}
	for (int i = 0; i < maxPow; ++i) {
		candidateNum.insert(fivePow[i]);

		long long mul = 2;
		while (mul * fivePow[i] < tenPow[i]) {
			candidateNum.insert(mul * fivePow[i]);
			++mul;
		}
	}

	for (auto num : candidateNum) {
		if (isANum(num)) {
			aNum.insert(num);
		}
		if (isANum(num + 1)) {
			aNum.insert(num + 1);
		}
	}

	for (auto n : aNum) {
		cout << n << endl;
	}

	int input = 10;
	int result = -1;
	for (auto n : aNum) {
		if (input <= n) break;
		result = n;
	}
	cout << result << endl;
}
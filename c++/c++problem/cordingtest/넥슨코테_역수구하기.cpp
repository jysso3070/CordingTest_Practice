
// 역수 구하기
// 정수가 주어졌을때 역수를 출력하는 프로그램 작성
// 역수는 무한히 반복되는 숫자로 끝나게 될 것이므로 반복되는 부분을 두번 출력하고
// 그 사이에 공백문자를 하나 출력 한다
// 예를들어 N = 8 이면 1/8 = 0.12500000... 이니까 '0.1250 0'을 출력
//			N = 9 이면 1/9 = 0.111111 이고 '0.1 1'을 출력
// 제약조건 2 <= N <= 10^5
// 예제 입력 10 이면 출력은 '0.10 0'

#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

void reciprocal(int input) {

	int DividedNum = 10;
	int remain = -1;
	for (int i = 0; i < 100; ++i) {
		cout << "loop_" << i<<": \t";
		if (DividedNum >= input) {
			cout << DividedNum / input;
			DividedNum = DividedNum % input;
			if (DividedNum < input) {
				DividedNum *= 10;
			}
		}
		else if (DividedNum < input) {
			cout << 0;
			DividedNum *= 10;
		}
		cout << endl;
	}
}
void reciprocal1(int input) {

	//list<int> quotientList;
	int DividedNum = 10;	// 피제수 (나눠지는수)
	int remain = -1;		// 나머지
	int quotientNum = -1;	// 몫
	int beforeQuotientNum = -1;	// 이전 몫

	cout << "0.";
	for (int i = 0; i < 100; ++i) {
		// 피제수가 제수보다 클때 나눗셈 실행 나누고나서 나머지가 제수보다 작아지면 x10
		if (DividedNum >= input) {
			quotientNum = DividedNum / input;
			DividedNum = DividedNum % input;
			if (DividedNum < input) {
				DividedNum *= 10;
			}
		}
		// 피제수가 제수보다 작으면 x10
		else if (DividedNum < input) {
			quotientNum = 0;
			DividedNum *= 10;
		}
		// 반복인지 검사해봄
		if (quotientNum == beforeQuotientNum) {
			cout << " " << quotientNum << endl;
			break;
		}
		else {
			beforeQuotientNum = quotientNum;
			cout << quotientNum;
		}
	}
}

int main() {
	float inputNum;
	cout << "정수 입력: ";
	fscanf_s(stdin, "%f", &inputNum);
	float result = 1 / inputNum;
	cout << result << endl;

	reciprocal1((int)inputNum);


	

}


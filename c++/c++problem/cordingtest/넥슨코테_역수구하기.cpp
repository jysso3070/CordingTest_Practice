
// ���� ���ϱ�
// ������ �־������� ������ ����ϴ� ���α׷� �ۼ�
// ������ ������ �ݺ��Ǵ� ���ڷ� ������ �� ���̹Ƿ� �ݺ��Ǵ� �κ��� �ι� ����ϰ�
// �� ���̿� ���鹮�ڸ� �ϳ� ��� �Ѵ�
// ������� N = 8 �̸� 1/8 = 0.12500000... �̴ϱ� '0.1250 0'�� ���
//			N = 9 �̸� 1/9 = 0.111111 �̰� '0.1 1'�� ���
// �������� 2 <= N <= 10^5
// ���� �Է� 10 �̸� ����� '0.10 0'

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
	int DividedNum = 10;	// ������ (�������¼�)
	int remain = -1;		// ������
	int quotientNum = -1;	// ��
	int beforeQuotientNum = -1;	// ���� ��

	cout << "0.";
	for (int i = 0; i < 100; ++i) {
		// �������� �������� Ŭ�� ������ ���� �������� �������� �������� �۾����� x10
		if (DividedNum >= input) {
			quotientNum = DividedNum / input;
			DividedNum = DividedNum % input;
			if (DividedNum < input) {
				DividedNum *= 10;
			}
		}
		// �������� �������� ������ x10
		else if (DividedNum < input) {
			quotientNum = 0;
			DividedNum *= 10;
		}
		// �ݺ����� �˻��غ�
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
	cout << "���� �Է�: ";
	fscanf_s(stdin, "%f", &inputNum);
	float result = 1 / inputNum;
	cout << result << endl;

	reciprocal1((int)inputNum);


	

}


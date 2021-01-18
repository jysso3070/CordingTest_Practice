#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// case1	��밪:50908
// A 315402
// B 403521
// case2	����:71515
// A 123450
// B 123450
// case3	����:101818
// A 251034
// B 253041

// 1. A�� B�� ���ÿ� ī�带 ���� �� ���� ī�带 �� ����� ���� �Ϻ��� ���� ī�� ����
//    ���ڰ� �����ϸ� ���� �������� ���� ��� ���ÿ� ī�带 �����Ѵ�
// 2. �մܰ迡�� ���� ���ڸ� ������ ����� ī�带 ���� �����Ѵ�
//    �̹��ϱ��� ���� �� ī������� ���� ������ �� ī������� ���պ��� ������� �ٷ� �й�
//    0ī�带 �� ��� ������ �����Ͽ� ������ ī����ڷ� ����Ѵ�
// 3. �ºΰ� �����ɶ� ���� ���� �����ư��� �� �ܰ踦 ����
// 4. ���̻� ������ ī�尡 ���� ��� �й�
// (a) = �ºΰ� ������ �� ��
// (b) = A�� ������ ī����� ����
// (c) = B�� ������ ī����� ����
// (a)x10000 + (b)x100 + (c) �� ���� ����ϴ� �Լ� ����


vector<int> case1_A;
vector<int> case1_B;

vector<int> case2_A;
vector<int> case2_B;

vector<int> case3_A;
vector<int> case3_B;

vector<int> case4_A;
vector<int> case4_B;

int cardGame(vector<int> & a, vector<int>& b){
	queue<int> aQueue;
	queue<int> bQueue;
	int answer = 0;
	int turnNum = 0; // ���°������
	int aSum = 0; // a�� �� ī�� ��
	int bSum = 0; // b�� �� ī�� ��
	int lastA = 0; // ���������� �� Aī��
	int lastB = 0; // ���������� �� Bī��
	bool turn = false; // true : A ��
	int smallCardsSize = 0; // ī��� ������
	if (a.size() >= b.size())
		smallCardsSize = b.size();
	else {
		smallCardsSize = a.size();
	}

	// ť�� ī�� �ֱ�
	for (int i = 0; i < a.size(); ++i) {
		aQueue.push(a[i]);
	}
	for (int i = 0; i < b.size(); ++i) {
		bQueue.push(b[i]);
	}

	for (int i = 0; i < smallCardsSize; ++i) {
		aSum += aQueue.front();
		lastA = aQueue.front();
		aQueue.pop();
		bSum += bQueue.front();
		lastB = bQueue.front();
		bQueue.pop();
		if (a[i] == b[i]) {
			continue;
		}
		if (a[i] < b[i]) {
			turn = true;
		}
		turnNum = ++i;
		break;
	}
	if (0 == turnNum) {
		answer = (10000 * (a.size()+1)) + (aSum*100) + bSum;
		return answer;
	}
	cout << turnNum << endl;
	cout << aQueue.front() << endl;
	cout << bQueue.front() << endl;
	cout << lastA << endl;
	cout << lastB << endl;

	while (true){
		++turnNum;
		cout <<"turn: " <<turnNum << endl;
		if (true == turn) { // a turn
			if(aQueue.empty()){
				answer = (10000 * turnNum) + (aSum * 100) + bSum;
				return answer;
			}
			int aCard = aQueue.front();
			if (0 == aCard) { aCard = lastB; }
			aSum += aCard;
			lastA = aCard;
			aQueue.pop();
			if (aSum < bSum) {
				answer = (10000 * turnNum) + (aSum * 100) + bSum;
				return answer;
			}
			turn = false;
		}
		else { // b turn
			if (bQueue.empty()) {
				answer = (10000 * turnNum) + (aSum * 100) + bSum;
				return answer;
			}
			int bCard = bQueue.front();
			if (0 == bCard) { bCard = lastA; }
			bSum += bCard;
			lastB = bCard;
			bQueue.pop();
			if (bSum < aSum) {
				answer = (10000 * turnNum) + (aSum * 100) + bSum;
				return answer;
			}
			turn = true;
		}
	}


	//return answer;
}

void makeVector(){
	case1_A.emplace_back(3);
	case1_A.emplace_back(1);
	case1_A.emplace_back(5);
	case1_A.emplace_back(4);
	case1_A.emplace_back(0);
	case1_A.emplace_back(2);

	case1_B.emplace_back(4);
	case1_B.emplace_back(0);
	case1_B.emplace_back(3);
	case1_B.emplace_back(5);
	case1_B.emplace_back(2);
	case1_B.emplace_back(1);

	case2_A.emplace_back(1);
	case2_A.emplace_back(2);
	case2_A.emplace_back(3);
	case2_A.emplace_back(4);
	case2_A.emplace_back(5);
	case2_A.emplace_back(0);
		
	case2_B.emplace_back(1);
	case2_B.emplace_back(2);
	case2_B.emplace_back(3);
	case2_B.emplace_back(4);
	case2_B.emplace_back(5);
	case2_B.emplace_back(0);

	case3_A.emplace_back(2);
	case3_A.emplace_back(5);
	case3_A.emplace_back(1);
	case3_A.emplace_back(0);
	case3_A.emplace_back(3);
	case3_A.emplace_back(4);
		
	case3_B.emplace_back(2);
	case3_B.emplace_back(5);
	case3_B.emplace_back(3);
	case3_B.emplace_back(0);
	case3_B.emplace_back(4);
	case3_B.emplace_back(1);

	case4_A.emplace_back(2);
	case4_A.emplace_back(5);
		
	case4_B.emplace_back(2);
	case4_B.emplace_back(5);
	case4_B.emplace_back(3);
	case4_B.emplace_back(0);
	case4_B.emplace_back(4);
	case4_B.emplace_back(1);
}

int main() {
	makeVector();

	int ret1 = cardGame(case1_A, case1_B);
	int ret2 = cardGame(case2_A, case2_B);
	int ret3 = cardGame(case3_A, case3_B);
	int ret4 = cardGame(case4_A, case4_B);

	cout << "answer = " << ret1 << endl;
	cout << "answer = " << ret2 << endl;
	cout << "answer = " << ret3 << endl;
	cout << "answer = " << ret4 << endl;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// case1	기대값:50908
// A 315402
// B 403521
// case2	예상값:71515
// A 123450
// B 123450
// case3	예상값:101818
// A 251034
// B 253041

// 1. A와 B가 동시에 카드를 내고 더 낮은 카드를 낸 사람이 다음 턴부터 먼저 카드 제시
//    숫자가 동일하면 선이 정해질때 까지 계속 동시에 카드를 제시한다
// 2. 앞단계에서 작은 숫자를 제시한 사람이 카드를 먼저 제시한다
//    이번턴까지 내가 낸 카드숫자의 합이 상대방이 낸 카드숫자의 총합보다 작은경우 바로 패배
//    0카드를 낸 경우 상대방이 이전턴에 제시한 카드숫자로 취급한다
// 3. 승부가 결정될때 까지 턴을 번갈아가며 위 단계를 진행
// 4. 더이상 제시할 카드가 없는 경우 패배
// (a) = 승부가 결정된 턴 수
// (b) = A가 제시한 카드숫자 총합
// (c) = B가 제시한 카드숫자 총합
// (a)x10000 + (b)x100 + (c) 의 값을 출력하는 함수 구현


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
	int turnNum = 0; // 몇번째턴인지
	int aSum = 0; // a가 낸 카드 합
	int bSum = 0; // b가 낸 카드 합
	int lastA = 0; // 마지막으로 낸 A카드
	int lastB = 0; // 마지막으로 낸 B카드
	bool turn = false; // true : A 턴
	int smallCardsSize = 0; // 카드수 적은쪽
	if (a.size() >= b.size())
		smallCardsSize = b.size();
	else {
		smallCardsSize = a.size();
	}

	// 큐에 카드 넣기
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
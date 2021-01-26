#include <iostream>
#include <vector>

using namespace std;

vector<string> closestStraightCity(vector<string> c, vector<int> x, vector<int> y, vector<string> q) {
	vector<string> result;
	result.reserve(q.size());

	for (int i = 0; i < q.size(); ++i) {
		int minDis = 1000000000;
		string minDisCity = "";
		int qIndex = find(c.begin(), c.end(), q[i]) - c.begin();
		int qX = x[qIndex];
		int qY = y[qIndex];

		for (int j = 0; j < c.size(); ++j) {
			if (qIndex == j) { continue; }

			if (qX == x[j]) {
				int tempDis = abs(qY - y[j]);
				if (minDis > tempDis) {
					minDis = tempDis;
					minDisCity = c[j];
				}
				else if (minDis == tempDis) {
					if (minDisCity.compare(c[j]) == 1) {
						minDisCity = c[j];
					}
				}
			}
			else if (qY == y[j]) {
				int tempDis = abs(qX - x[j]);
				if (minDis > tempDis) {
					minDis = tempDis;
					minDisCity = c[j];
				}
				else if (minDis == tempDis) {
					if (minDisCity.compare(c[j]) == 1) {
						minDisCity = c[j];
					}
				}
			}
		}
		if (minDisCity.compare("") == 0) {
			result.emplace_back("NONE");
		}
		else {
			result.emplace_back(minDisCity);
		}
	}
	return result;
}

int main() {
	string a = "abc";
	string b = "abd";
	cout << a.compare(b) << endl; // a가 b보다 아스키코드값 크면 1
}
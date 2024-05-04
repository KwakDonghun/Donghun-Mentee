#include <iostream>
#include <vector>

using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& right) {
		return lhs > right; //우측값이 작을 때 true
	}
};

class sortedPQ {
private:
	vector<int> pq;
	compare C;
	int level;
public:
	sortedPQ() {
		pq.clear();
		level = 0;
	}
	void insert(vector<int>& v, int n) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			int idx;
			for (idx = 0; idx < pq.size(); idx++)
				if (C(pq[idx], v[0])) break;
			pq.insert(pq.begin() + idx, v[0]);
			v.erase(v.begin());
			level++;
			if (level == n) {
				cout << "S : ";
				for (int j = 0; j < v.size(); j++)
					cout << v[j] << ' ';
				cout << "\nPQ : ";
				for (int j = 0; j < pq.size(); j++)
					cout << pq[j] << ' ';
				cout << '\n';
				return;
			}
		}
		v.clear();
		for (int i = 0; i < size; i++) {
			v.push_back(pq.back());
			pq.pop_back();
			level++;
			if (level == n) {
				cout << "S : ";
				for (int j = 0; j < v.size(); j++)
					cout << v[j] << ' ';
				cout << "\nPQ : ";
				for (int j = 0; j < pq.size(); j++)
					cout << pq[j] << ' ';
				cout << '\n';
				return;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, input, level;
	cin >> T;
	while (T--) {
		vector <int> S;
		sortedPQ pq;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			S.push_back(input);
		}
		cin >> level;
		pq.insert(S,level);
	}
}
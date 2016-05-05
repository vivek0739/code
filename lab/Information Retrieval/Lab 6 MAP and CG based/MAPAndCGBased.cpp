#include <bits/stdc++.h>
using namespace std;
map<int, double> dcg;
map<int, double> ap;
map<int, int> relevant;
map<int, int> ind;
int main() {
	ifstream fin("Run1.res", ios::in);
	string lineInput;
	while(getline(fin, lineInput)) {
		istringstream iss(lineInput);
		string query, doc;
		int id, ind, grade;
		double someValue;
		iss >> id >> query >> doc >> ind >> someValue >> grade;
		if(grade == 1) {
			relevant[id]++;
			ap[id] += ((double)relevant[id] / ind);
		}
	}
	map<int, double>::iterator it;
	double sumAp = 0;
	for(it = ap.begin(); it != ap.end(); it++) {
		it -> second /= relevant[it -> first];
		cout << it -> second << endl;
		sumAp += it -> second;
	}
	double MAP = sumAp / ap.size();
	cout << "MAP for Run1.res is " << MAP << endl;
	fin.close();
	fin.open("truth_std_fire13.rel", ios::in);
	while(getline(fin, lineInput)) {
		istringstream iss(lineInput);
		string query, doc;
		int id, grade;
		iss >> id >> query >> doc >> grade;
		ind[id]++;
		if(ind[id] != 1) {
			dcg[id] += (0.301 * grade) / log10(ind[id]);
		} else {
			dcg[id] = grade;
		}		
	}
	for(it = dcg.begin(); it != dcg.end(); it++) {
		cout << "For id: " << it -> first << " " << it -> second << endl;
	}
	return 0;
}

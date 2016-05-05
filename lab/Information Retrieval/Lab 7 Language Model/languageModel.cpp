#include <bits/stdc++.h>
using namespace std;
map<string, int> termFrequency[100];
map<int, int> totalDocTerms;
map<int, double> docQueryProbability;
int main() {
	int n;
	cout << "Enter the number of docs: ";
	cin >> n;
	int i;
	string temp;
	string word;
	char ch;
	scanf("%c", &ch);
	for(i = 0; i < n; i++) {
		cout << "Enter the doc(in a single line): ";
		getline(cin, temp);
		istringstream iss(temp);
		
		while(iss >> word) {
			termFrequency[i][word] ++;
			totalDocTerms[i]++;
		}
	}
	cout << "Enter the query: ";
	getline(cin, temp);
	istringstream iss(temp);
	for(i = 0; i < n; i++) {
		docQueryProbability[i] = 1.0;
	}
	while(iss >> word) {
		for(i = 0; i < n; i++) {
			double wordProb = (double) termFrequency[i][word] / totalDocTerms[i];
			docQueryProbability[i] *= wordProb;
		}
	}
			
	map<int, double>::iterator it;
	vector<pair<double, int> > revDocQueryProb;
	for(it = docQueryProbability.begin(); it != docQueryProbability.end(); it++) {
		revDocQueryProb.push_back(make_pair(it -> second, it -> first));
	}
	sort(revDocQueryProb.begin(), revDocQueryProb.end());
	reverse(revDocQueryProb.begin(), revDocQueryProb.end());
	for(i = 0; i < revDocQueryProb.size(); i++) {
		cout << "Doc " << revDocQueryProb[i].second + 1 << " " << revDocQueryProb[i].first << endl;
	}
	return 0;
}

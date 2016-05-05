#include <bits/stdc++.h>
using namespace std;
map<string, int> termFrequency[100];
map<string, vector<int> > classDocs;
map<string, double> classProb;
map<int, int> totalDocTerms;
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
		cout << "Enter the class: ";
		string cls;
		cin >> cls;
		scanf("%c", &ch);
		classDocs[cls].push_back(i);
	}
	cout << "Enter the query: ";
	getline(cin, temp);
	istringstream iss(temp);
	map<string, vector<int> >::iterator it;
	for(it = classDocs.begin(); it != classDocs.end(); it++) {
		classProb[it -> first] = 1.0;
	}
	while(iss >> word) {
		for(it = classDocs.begin(); it != classDocs.end(); it++) {
			vector<int> temp = it -> second;
			int sumTF = 0;
			int sumDT = 0;
			for(i = 0; i < temp.size(); i++) {
				sumTF += termFrequency[temp[i]][word];
				sumDT += totalDocTerms[temp[i]];
			}
			cout << sumTF << " " << sumDT << endl;
			classProb[it -> first] *= (double) sumTF / sumDT;
			cout << classProb[it -> first] << endl;
		} 
	}
	string answer;
	double maxval = -1;
	for(it = classDocs.begin(); it != classDocs.end(); it++) {
		if(maxval < classProb[it -> first]) {
			maxval = classProb[it -> first];
			answer = it -> first;
		}
	}
	cout << answer << " " << maxval << endl;
	return 0;
}

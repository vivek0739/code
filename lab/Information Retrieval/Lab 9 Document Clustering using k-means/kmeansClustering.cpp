#include <bits/stdc++.h>
using namespace std;
map<string, int> termFrequency[100];
map<string, double> clusterMeans[100];
vector<int> clusters[100];
map<string, bool> uniqueWords;
map<int, int> totalDocTerms;
double calcDistance(int i, int j) {
	double distance = 0;
	map<string, bool>::iterator it;
	double sum1 = 0, sum2 = 0, dotProd = 0;
	for(it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
		sum1 = termFrequency[i][it -> first] * termFrequency[i][it -> first];
		sum2 = clusterMeans[j][it -> first] * clusterMeans[j][it -> first];
	}
	sum1 = sqrt(sum1+sum2);
	return sum1;
}
int main() {
	int n, k;
	cout << "Enter the number of clusters: ";
	cin >> k;
	cout << "Enter the number of docs: ";
	cin >> n;
	int i;
	int j;
	string temp;
	string word;
	char ch;
	scanf("%c", &ch);
	for(i = 0; i < n; i++) {
		cout << "Enter the doc-name: ";
		cin >> temp;
		ifstream fin(temp.c_str(), ios::in);
		while(getline(fin, temp)) {
			istringstream iss(temp);
			while(iss >> word) {
				uniqueWords[word] = 1;
				termFrequency[i][word] ++;
			}			
		}
	}
	int sizeCluster = n / k;
	j = 0;
	for(i = 0; i < k; i++) {
		int limit;
		if(i == k - 1) {
			limit = n;
			
		} else {
			limit = j + sizeCluster;
		}
		for(; j < limit; j++) {
			clusters[i].push_back(j);
		}
	}
	int iter = 0;
	int same = 0;
	while(!same && iter < 100) {
		iter++;
		vector<int> newClusters[100];
		for(i = 0; i < k; i++) {
			map<string, bool>::iterator it;
			for(it = uniqueWords.begin(); it != uniqueWords.end(); it++) {
				clusterMeans[i][it -> first] = 0.0;
				for(j = 0; j < clusters[i].size(); j++) {
					clusterMeans[i][it -> first] += termFrequency[clusters[i][j]][it -> first];
				}
				clusterMeans[i][it -> first] /= clusters[i].size();
			}
		}
		
		for(i = 0; i < n; i++) {
			int minInd = -1;
			double minDist = 10000000;
			for(j = 0; j < k; j++) {
				double dist = calcDistance(i, j);
				if(dist < minDist) {
					minDist = dist;
					minInd = j;
				}
			}
			//cout << minDist << endl;
			//cout << minInd << endl;
			newClusters[minInd].push_back(i);
		}
		for(i = 0; i < k; i++) {
			if(clusters[i] != newClusters[i]) {
				break;
			}
		}
		for(i = 0;i < k; i++) {
			clusters[i] = newClusters[i];
		}
		if(i == k) {
			same = 1;
		}
	}
	for(i = 0; i < k; i++) {
		for(j = 0; j < clusters[i].size(); j++) {
			cout << clusters[i][j] << " ";
		}
		cout << endl;
		map<string, double>::iterator it;
		for(it = clusterMeans[i].begin(); it != clusterMeans[i].end(); it++) {
			cout << it -> first << " " << clusterMeans[i][it -> first] << " ";
		}
		cout << endl;
	}
	return 0;
}

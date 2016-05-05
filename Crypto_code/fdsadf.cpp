#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;
int lps[500] = {0};
void createLps(char pattern[]) {
	lps[0] = lps[1] = 0;
	if(pattern[1] == '\0') {
		return;
	}
	for(int i = 2; pattern[i - 1] != '\0'; i++) {
		int j = lps[i - 1];
		while(1) {
			if(pattern[j] == pattern[i - 1]) {
				lps[i] = j + 1;
			}
			if(j == 0) {
				lps[i] = 0;
				break;
			} else 
				j = lps[j];

		}
	}
}
void KMP(char text[], char pattern[], int patLen)
{
        
	string output;
	int prevInd = 0;
	createLps(pattern); 
	int i = 0;
	int j = 0;
	int flag = 0;
	while(1) {
		if(text[j] == '\0') break; 
		if(text[j] == pattern[i]) {
			i++;
			j++;
			if(i == patLen) {
				flag = 1;	
				for(int k = prevInd; k <= j - patLen - 1; k++) {
					output.push_back(text[k]);
				}
				output.push_back('\"');
				for(int k = j - patLen; k <= j - 1; k++) {
					output.push_back(text[k]);
				}
				output.push_back('\"');
				i = 0;
				prevInd = j;

			}
		}
		else if(i > 0) i = lps[i];
		else j++;
	}
	if(flag) {
		cout << output;
		for(int k = prevInd; text[k] != '\0'; k++) {
			cout << text[k];
		}
		cout << endl;
	}
}	
std::vector<std::string> open(std::string path = ".") {

    DIR*    dir;
    dirent* pdir;
    std::vector<std::string> files;

    dir = opendir(path.c_str());

    while (pdir = readdir(dir)) {
        files.push_back(pdir->d_name);
    }
    
    return files;
}
int main(int argc, char *argv[]) {
	char *searchString, *fileName, *directoryName;
	searchString = argv[1];
	std::vector<std::string> f;
	f = open("/home/vivek/"); // or pass which dir to open
	int n=f.size();
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"************************************"<<f[i]<<"************"<<endl;
		ifstream fin(f[i].c_str(), ios::in);
		char inputString[500];
		while(fin.getline(inputString, 500)) {
			KMP(inputString, searchString, strlen(searchString));
		}
	}
	
	
	return 0;
}
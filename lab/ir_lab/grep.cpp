#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;
void SubString(char text[], char pattern[], int patLen)
{
    int n = strlen(text);
	string output;
	int prevInd = 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	for(j=0;j<n-patLen;j++) {
		for(i = 0 ;i<patLen;i++)
		{
			if(text[i+j]!=pattern[i]) break;
		}
		
			
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
    	string news = path.c_str();
    	news+=pdir->d_name;
        files.push_back(news);
    }
    
    return files;
}
int main(int argc, char *argv[]) {
	char *searchString, *fileName, *directoryName;
	searchString = argv[1];
	std::vector<std::string> f;
	f = open("/home/vivek/lab/"); // or pass which dir to open
	int n=f.size();
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"************************************"<<f[i]<<"************"<<endl;
		ifstream fin(f[i].c_str(), ios::in);
		char inputString[500];
		while(fin.getline(inputString, 500)) {
			SubString(inputString, searchString, strlen(searchString));
		}
	}
	
	
	return 0;
}

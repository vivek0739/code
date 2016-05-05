
#include <iostream>
#include <limits.h>
using namespace std;
int main() {
        string str ="XLILSYWIMWRSAJSVWEPIJSVJSYVQMPPMSRHSPPEVWMXMWASVXLQSVILYVVCFIJSVIXLIWIPPIVVIGIMZIWQSVISJJIVW";
        cin>>str;
        int hash[26] = {0};
        string strOutput;
        int i;
        for(i = 0; i < str.size(); i++) {
                hash[str[i] - 'A']++;
        }
        int maxIndex = INT_MIN, maxValue = INT_MIN;
        for(i = 0; i < 26; i++) {
                if(maxValue < hash[i]) {
                        maxValue = hash[i];
                        maxIndex = i;
                }
        }
        //int mostCommon[] = {4, 0, 14, 19};
        int b = maxIndex - 4;
        if(b < 0) {
                b += 26;
        }
        for(i = 0; i < str.size(); i++) {
                char ch = (str[i] - 'A' - b) % 26 + 'A';
                if(ch < 'A') {
                        ch += 26;
                }
                strOutput.push_back(ch);
        }
        cout << "The output string is " << strOutput<<endl;
        return 0;
}

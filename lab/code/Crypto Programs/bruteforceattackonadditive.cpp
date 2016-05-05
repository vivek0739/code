#include <iostream>
using namespace std;
#define MOD 26
int main() {
        string str;
        string strOutput;
        cin >> str;
        int b = 1;
        while(b < 26) {
                strOutput = "";
                int i;
                for(i = 0; i < str.size(); i++) {
                        char ch = (str[i] - 'A' - b)%MOD;
                        ch += 'A';
                        if(ch < 'A') {
                                ch += MOD;
                        }
                        strOutput.push_back(ch);
                }
                cout << "String after taking b = " << b << " is " << strOutput << endl;
                b++;
        }
        return 0;
}

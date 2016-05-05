#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack <int> s;
int cffs, cffb;
void calcInverse(int a, int b) {
        int newa = b;
        int newb = a % b;
        if(newa % newb == 0) {
                cffs = (a / b) * (-1);
                cffb = 1;
                //cout << cffb << " " << cffs << endl;
                return;
        }
        calcInverse(b, a % b);
        int store = cffs;
        cffs = cffb - (a / b) * (cffs);
        cffb = store;
        //cout << cffb << " " << cffs << endl;

}
int main() {
        string str;
        string strOutput;
        cout << "Enter the string: ";
        cin >> str;
        int b = 1;
        for(; b < 26; b += 2) {
                strOutput = "";
                if(b != 13) {
                        calcInverse(b, 26);
                        if(cffb < 0) {
                                cffb += 26;
                        }
                        for(int i = 0; i < str.size(); i++) {
                                char ch = (str[i] - 'A')* cffb % 26 + 'A';
                                strOutput.push_back(ch);
                        }
                        cout << "Using key b = " << b << "whose inverse is " << cffb << " The string is " << strOutput << endl;
                }
        }
        return 0;
}

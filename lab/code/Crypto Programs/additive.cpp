#include <iostream>
using namespace std;
#define MOD 26
int main() {
        string str;
        cout << "Enter the string: ";
        cin >> str;
        cout << "Enter the value to shift to right: ";
        int b;
        cin >> b;
        if(b < 0) {
                b += MOD;
        }
        for(int i = 0; i < str.size(); i++) {
                str[i] = (str[i] - 'A' + b) % MOD + 'A';
        }
        cout << "After encryption the string is: " << str;
        return 0;
}

#include <iostream>
using namespace std;
int main() {
        string str;
        cout << "Enter the string to be encrypted: ";
        cin >> str;
        cout << "Enter the key: ";
        int b;
        cin >> b;
        if(b % 13 == 0 || b % 2 == 0) {
                cout << "Not a valid Key";
        } else {
                for(int i = 0; i < str.size(); i++) {
                        str[i] = ((str[i] - 'A') * b) % 26 + 'A';
                }
                cout << "String after encryption: " << str<<endl;
        }
        return 0;
}

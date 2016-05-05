#include <iostream>
using namespace std;
int matrix[3][3] = {{-25, -50, 0}, {-100, -225, -175}, {-50, -50, -25}};
int decr[3][3] = {{-5, 10, -10}, {-2, 1, 2}, {14, -7, 1}};
string encrypt(string temp) {
        int i, j, k;
        string ret = "";
        for(i = 0; i < 3; i++) {
                for(j = 0; j < 1; j++) {
                        int ch = 0;
                        for(k = 0; k < 3; k++) {
                                ch = (ch + matrix[i][k] * (temp[k] - 'A')) % 26;
                                //      cout << ch << endl;
                        }
                        if(ch < 26) {
                                ch += 26;
                        }
                        char x = ch + 'A';
                        //cout << x << endl;


                        ret.push_back(x);
                }
        }
        return ret;
}

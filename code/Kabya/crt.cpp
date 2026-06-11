#include <iostream>
#include <vector>
using namespace std;
// Chinese Remainder Theorem
int chineseRemainder(const vector<int>& num, const vector<int>& rem) {
    int prod = 1;
    for (int n : num) prod *= n;
    int result = 0;
    for (int i = 0; i < num.size(); i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;}
    return result % prod;}
int main() {
    vector<int> num = {3, 4, 5};  // moduli
    vector<int> rem = {2, 3, 1};  // remainders
    cout << "x = " << chineseRemainder(num, rem) << endl;
    return 0;}

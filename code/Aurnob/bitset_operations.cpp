#include <iostream>
#include <bitset>
using namespace std;
int main() {
    bitset<8> b1(string("10101100"));  // binary: 10101100
    bitset<8> b2(string("00111100"));  // binary: 00111100
    cout << "b1 = " << b1 << endl;  // Output: 10101100
    cout << "b2 = " << b2 << endl;  // Output: 00111100
    cout << "\nb1 & b2 = " << (b1 & b2) << endl;  // Output: 00101100
    cout << "b1 | b2 = " << (b1 | b2) << endl;    // Output: 10111100
    cout << "b1 ^ b2 = " << (b1 ^ b2) << endl;    // Output: 10010000
    cout << "~b1 = " << (~b1) << endl;            // Output: 01010011
    bitset<8> b3 = b1;
    b3.set(); // Set all bits
    cout << "\nb3.set() = " << b3 << endl;        // Output: 11111111
    b3.reset();// Reset all bits
    cout << "b3.reset() = " << b3 << endl;        // Output: 00000000
    b3 = b1;
    b3.flip();// Flip all bits
    cout << "b3.flip() = " << b3 << endl;         // Output: 01010011
    b3.set(2);// Set a specific bit (index 2)
    cout << "b3.set(2) = " << b3 << endl;         // Output: 01010111
    b3.reset(2);// Reset a specific bit (index 2)
    cout << "b3.reset(2) = " << b3 << endl;       // Output: 01010011
    b3.flip(0);// Flip a specific bit (index 0)
    cout << "b3.flip(0) = " << b3 << endl;        // Output: 01010010
    // Count number of set bits
    cout << "\nb1.count() = " << b1.count() << endl;  // Output: 4
    // Get value of a specific bit (index 3)
    cout << "\nb1[3] = " << b1[3] << endl;            // Output: 1
    // Convert bitset to unsigned long
    cout << "b1.to_ulong() = " << b1.to_ulong() << endl;  // Output: 172
    // Convert bitset to unsigned long long
    cout << "b1.to_ullong() = " << b1.to_ullong() << endl; // Output: 172
    // Convert bitset to string
    cout << "b1.to_string() = " << b1.to_string() << endl; // Output: 10101100
    return 0;
}

#include <iostream>
using namespace std;

void flipIthBit(int &num, int i) {
    /*
        45 = 00101101
        01 = 00000001

        to set 2nd bit -> i=2

        45 =               0 0 1 0 1 1 0 1
        1 << i -> 1 << 2 = 0 0 0 0 0 1 0 0
                           ---------------
                     xor   0 0 1 0 1 0 0 1
    */
    num = num ^ (1 << i);
}

int main() {
    int num = 41;
    int i = 2;
    flipIthBit(num, i);
    cout << num << endl;
    return 0;
}
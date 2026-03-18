#include <iostream>
using namespace std;

int main() {
    int n;
    int man, chun, baek, sip, il;

    cin >> n;

    man = n / 10000;
    chun = (n % 10000) / 1000;
    baek = (n % 1000) / 100;
    sip = (n % 100) / 10;
    il = n % 10;

    if (man != 0) cout << man << "만 ";
    if (chun != 0) cout << chun << "천 ";
    if (baek != 0) cout << baek << "백 ";
    if (sip != 0) cout << sip << "십 ";
    if (il != 0) cout << il;

    cout << endl;

    return 0;
}
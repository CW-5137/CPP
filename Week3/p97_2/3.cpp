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

    if (man != 0) {
        if (man == 1) cout << "만 ";
        else cout << man << "만 ";
    }

    if (chun != 0) {
        if (chun == 1) cout << "천 ";
        else cout << chun << "천 ";
    }

    if (baek != 0) {
        if (baek == 1) cout << "백 ";
        else cout << baek << "백 ";
    }

    if (sip != 0) {
        if (sip == 1) cout << "십 ";
        else cout << sip << "십 ";
    }

    if (il != 0) {
        cout << il;
    }

    cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    int man, chun, baek, sip, il;

    cout << "정수를 입력하세요: ";
    cin >> n;

    man = n / 10000;
    chun = (n % 10000) / 1000;
    baek = (n % 1000) / 100;
    sip = (n % 100) / 10;
    il = n % 10;

    cout << man << "만 "
         << chun << "천 "
         << baek << "백 "
         << sip << "십 "
         << il << endl;

    return 0;
}
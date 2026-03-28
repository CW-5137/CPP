//메인파일

#include <iostream>
#include "3.hpp."
//using namespace std; 이거쓰면 cin >> ? cout << ? 시용가능
int main()
{
    std::string s;

    std::cout << "숫자를 입력하세요:";
    std::cin >> s;

    std::cout << "역순:";
    std::cout << reverse(s) << std::endl;

    return 0;
}
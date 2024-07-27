#include <iostream>
int main(){
    int h, w;
    std::cin >> h >> w;
    std::cout << 50 * (h < w ? h : w) << '\n';
    return 0;
}
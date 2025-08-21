#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, int> window;
    window['A'] = 1;
    window['B'] = 2;

    // 判断 'C' 是否存在
    if (window.find('C') == window.end()) {
        cout << "'C' 不在 window 中" << endl;
    } else {
        cout << "'C' 存在，值是：" << window['C'] << endl;
    }

    return 0;
}

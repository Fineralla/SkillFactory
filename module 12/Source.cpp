#include <iostream>
#include <string>


bool IsKPeriodic(const std::string & str, int k) {
    // ѕровер€ем, что k > 0 и что длина строки кратна k.
    if (k <= 0 || str.length() % k != 0) {
        return false;
    }


    // ѕровер€ем, что каждый блок длины k в строке равен первому блоку.
    const int block_length = k;
    const int num_blocks = str.length() / block_length;
    const std::string first_block = str.substr(0, block_length);
    for (int i = 1; i < num_blocks; ++i) {
        const std::string block = str.substr(i * block_length, block_length);
        if (block != first_block) {
            return false;
        }
    }


    return true;
}


int main() {
    std::string str = "abcabcabcabc";
    int k = 3;
    if (IsKPeriodic(str, k)) {
        std::cout << str << " is " << k << "-periodic" << std::endl;
    }
    else {
        std::cout << str << " is not " << k << "-periodic" << std::endl;
    }
    return 0;
}
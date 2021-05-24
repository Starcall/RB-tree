#include "redblacktree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int main()
{

    for (size_t sz = 10; sz < 200000; sz++) {
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::vector<int32_t> data;
        RedBlackTree A = RedBlackTree();
        for (size_t i = 0; i < sz; i++) {
            data.push_back(i + 1);
        }
        std::random_shuffle(data.begin(), data.end());
        for (auto x : data) {
            A.insert(x);
        }
        std::vector<bool> ans;
        for (size_t i = 1; i <= sz; i++) {
            ans.push_back(A.find(i));
        }

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << sz << " " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\n";
    }
    return 0;
}

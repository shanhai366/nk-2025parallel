#include <iostream>
#include <immintrin.h>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int n = 5000;
vector<vector<float>> matrix(n, vector<float>(n, 1.0)); // 二维向量
vector<float> given_vector(n, 1.0); // 一维向量
vector<float> res(n, 0.0); // 一维向量

void optimized_method() {
    for (int i = 0; i < n; i++) { // 通过按行遍历矩阵来优化缓存访问模式
        for (int j = 0; j < n; j++) {
            res[j] += matrix[i][j] * given_vector[i]; // 执行内积计算
        }
    }
}

int main() {
    // 测试矩阵与向量内积的算法
    auto start = high_resolution_clock::now();  // 记录开始时间
    optimized_method(); // 调用优化算法计算内积
    auto end = high_resolution_clock::now();  // 记录结束时间


    



    cout << "cache优化算法: " << duration_cast<milliseconds>(end - start).count() << " ms\n"; // 输出时间

    return 0;
}


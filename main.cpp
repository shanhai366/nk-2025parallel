
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

void basic_method() {
    for (int j = 0; j < n; j++) // j列
    {
        float sum = 0.0;
        for (int i = 0; i < n; i++) // i行
        {
            sum += matrix[i][j] * given_vector[i]; // 第i个值
        }
        res[j] = sum; // 赋值给res的每一个值
    }
}

int main() {
    // 测试矩阵与向量内积的算法
    auto start = high_resolution_clock::now();  // 记录开始时间
    basic_method(); // 调用平凡算法计算内积
    auto end = high_resolution_clock::now();  // 记录结束时间
    cout << "平凡算法: " << duration_cast<milliseconds>(end - start).count() << " ms\n"; // 输出时间


    return 0;
}


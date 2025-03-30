#include <iostream>
#include <immintrin.h>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

const int n = 5000;
vector<vector<float>> matrix(n, vector<float>(n, 1.0)); // ��ά����
vector<float> given_vector(n, 1.0); // һά����
vector<float> res(n, 0.0); // һά����

void optimized_method() {
    for (int i = 0; i < n; i++) { // ͨ�����б����������Ż��������ģʽ
        for (int j = 0; j < n; j++) {
            res[j] += matrix[i][j] * given_vector[i]; // ִ���ڻ�����
        }
    }
}

int main() {
    // ���Ծ����������ڻ����㷨
    auto start = high_resolution_clock::now();  // ��¼��ʼʱ��
    optimized_method(); // �����Ż��㷨�����ڻ�
    auto end = high_resolution_clock::now();  // ��¼����ʱ��


    // Reset result vector
    fill(res.begin(), res.end(), 0.0);




    cout << "cache�Ż��㷨: " << duration_cast<milliseconds>(end - start).count() << " ms\n"; // ���ʱ��

    return 0;
}


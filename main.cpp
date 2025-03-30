
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

void basic_method() {
    for (int j = 0; j < n; j++) // j��
    {
        float sum = 0.0;
        for (int i = 0; i < n; i++) // i��
        {
            sum += matrix[i][j] * given_vector[i]; // ��i��ֵ
        }
        res[j] = sum; // ��ֵ��res��ÿһ��ֵ
    }
}

int main() {
    // ���Ծ����������ڻ����㷨
    auto start = high_resolution_clock::now();  // ��¼��ʼʱ��
    basic_method(); // ����ƽ���㷨�����ڻ�
    auto end = high_resolution_clock::now();  // ��¼����ʱ��
    cout << "ƽ���㷨: " << duration_cast<milliseconds>(end - start).count() << " ms\n"; // ���ʱ��


    return 0;
}


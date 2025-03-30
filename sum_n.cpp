#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

// �����ۼ�
float basic_sum(const vector<float>& array1) {
    float sum = 0.0;
    for(float i : array1) {
        sum += i;
    }
    return sum;
}

// ��·�ۼ�
float two_way_basic(const vector<float>& array1) {
    float sum1 = 0, sum2 = 0;
    size_t n = array1.size();

    for (size_t i = 0; i < n; i += 2) {
        sum1 += array1[i];
        if (i + 1 < n) sum2 += array1[i + 1];  // ����Խ��
    }

    return sum1 + sum2;
}

// �ݹ��Լ
void recursive_sum(vector<float>& array1, size_t n) {
    if (n == 1) return;

    for (size_t i = 0; i < n / 2; i++) {
        array1[i] += array1[n - i - 1];
    }

    recursive_sum(array1, n / 2);
}

// ������Լ
float iterative_sum(vector<float> array1) {
    size_t n = array1.size();

    while (n > 1) {
        size_t m = (n + 1) / 2;  // ������������
        for (size_t i = 0; i < m; i++) {
            if (2 * i + 1 < n) {
                array1[i] = array1[2 * i] + array1[2 * i + 1];
            } else {
                array1[i] = array1[2 * i];  // �������һ��������Ԫ��
            }
        }
        n = m;
    }

    return array1[0];
}

int main() {
    const size_t n = 1 << 20;  // 2^20 = 1,048,576
    vector<float> arr(n, 1.0);  // ����Ԫ�س�ʼ��Ϊ1.0

    // ���Ի����ۼ�
    auto start = high_resolution_clock::now();
    float sum_basic = basic_sum(arr);
    auto end = high_resolution_clock::now();
    cout << "�����ۼ� " << sum_basic << " ʱ��: "
         << duration<float, milli>(end - start).count() << " ms" << endl;

    // ������·�ۼ�
    start = high_resolution_clock::now();
    float sum_two_way = two_way_basic(arr);
    end = high_resolution_clock::now();
    cout << "��·�ۼ� " << sum_two_way << " ʱ��: "
         << duration<float, milli>(end - start).count() << " ms" << endl;

    // ���Եݹ��Լ
    vector<float> arr_recursive = arr;
    start = high_resolution_clock::now();
    recursive_sum(arr_recursive, n);
    end = high_resolution_clock::now();
    cout << "�ݹ��Լ " << arr_recursive[0] << " ʱ��: "
         << duration<float, milli>(end - start).count() << " ms" << endl;

    // ���Ե�����Լ
    vector<float> arr_iterative = arr;
    start = high_resolution_clock::now();
    float sum_iterative = iterative_sum(arr_iterative);
    end = high_resolution_clock::now();
    cout << "������Լ " << sum_iterative << " ʱ��: "
         << duration<float, milli>(end - start).count() << " ms" << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#define maxh = 501

using namespace std;

void Swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int strlen_m(const char* str) {
    int len = 0;
    /*while (true) {
        if (NULL != str[len]) {
            ++len;
        }
        else {
            return len;
        }
    }*/
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

char* removeConti(char* str) {
    int idx = 1;
    int len = strlen_m(str);
    char* result = new char[len];
    result[0] = str[0];
    for (int i = 1; str[i] != '\0'; ++i) {
        if (result[idx - 1] != str[i]) {
            result[idx++] = str[i];
        }
    }
    result[idx] = '\0';

    return result;
}

char* reverseStr(char* str) {
    int len = strlen_m(str);
    char temp;
    for (int i = 0; i < len / 2; ++i) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}

int strCompare(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            if (str1[i] < str2[i])
                return -1;
            else if (str1[i] > str2[i])
                return 1;
        }
        ++i;
    }
    if (str1[i] < str2[i])
        return -1;
    else if (str1[i] > str2[i])
        return 1;
    else
        return 0;
}

// 소수 판별
bool checkPrime(int num) {
    for (int i = 2; i < sqrt(num); ++i) {
        if (0 == (num % i)) {
            cout << "소수가 아님" << endl;
            return true;
        }
    }
    cout << "소수" << endl;
    return false;
}

// 범위안의 소수 구하기
void findPrimeNumber(int range) {
    int* numArr = new int[range];
    for (int i = 0; i < range; ++i) {
        numArr[i] = i;
    }
    for (int i = 2; i < sqrt(range); ++i) {
        if (0 == numArr[i]) continue;
        for (int j = i + i; j < range ; j += i) {
            numArr[j] = 0;
        }
    }

    for (int i = 2; i < range; ++i) {
        if (0 != numArr[i]) {
            cout << numArr[i] << " ";
        }
    }
}


int main() {
    findPrimeNumber(50000);
    //checkPrime(49993);
}


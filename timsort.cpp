#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Минимальный размер блока для сортировки вставками
const int MIN_BLOCK_SIZE = 256;

// Сортировка подмассива с помощью сортировки вставками
void insertion_sort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Объединение двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Тимсорт - универсальный алгоритм сортировки, комбинирующий сортировку вставками и сортировку слиянием
void tim_sort(vector<int>& arr) {
    int n = arr.size();

    // Сортировка подмассивов с помощью сортировки вставками
    for (int i = 0; i < n; i += MIN_BLOCK_SIZE)
        insertion_sort(arr, i, min((i + MIN_BLOCK_SIZE - 1), n - 1));

    // Сортировка подмассивов с помощью сортировки слиянием
    for (int size = MIN_BLOCK_SIZE; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    vector<int> arr{ 831, 310, 838, 772, 346, 968, 372, 397, 673, 575, 6, 72, 847, 591, 514, 96, 813, 953, 437, 252, 79, 834, 682, 305, 516, 197, 717, 28, 805, 797, 503, 662, 35, 982, 753, 95, 716, 527, 630, 637, 571, 205, 90, 922, 29, 575, 512, 844, 51, 363, 105, 677, 370, 995, 492, 317, 220, 126, 780, 394, 924, 962, 128, 150, 12, 434, 128, 524, 138, 269, 518, 57, 871, 823, 945, 507, 451, 522, 628, 964, 24, 854, 714, 386, 454, 133, 512, 405, 584, 90, 325, 47, 77, 363, 785, 329, 385, 292, 891, 490, 741, 353, 133, 896, 387, 849, 150, 967, 538, 235, 4, 59, 986, 355, 41, 996, 543, 797, 771, 897, 946, 405, 345, 423, 553, 307, 299, 187, 528, 383, 753, 597, 252, 771, 660, 441, 929, 546, 808, 716, 843, 604, 496, 577, 343, 687, 638, 287, 668, 884, 770, 670, 125, 12, 244, 987, 36, 863, 976, 330, 953, 137, 672, 76, 224, 450, 214, 924, 869, 446, 961, 145, 231, 742, 677, 184, 70 };
    tim_sort(arr);

    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
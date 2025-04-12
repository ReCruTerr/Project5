#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

double safeInputDouble();
double sumNegativeElements(const double arr[], int size);
double multiplyBetweenMinMax(const double arr[], int size);
void sortArray(double arr[], int size);
void printArray(const double arr[], int size);

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n;
    const int MAX_SIZE = 1000;
    double arr[MAX_SIZE];

    // ���� ������� �������
    cout << "������� ������ ������� (�� ����� " << MAX_SIZE << " ���������): ";
    cin >> n;

    while (cin.fail() || n <= 0 || n > MAX_SIZE) {
        cout << "������� ���������� ������ ��� �������!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> n;
    }

    // ���� ��������� �������
    cout << "������� " << n << " ������������ ��������� �������:\n";
    for (int i = 0; i < n; ++i) {
        arr[i] = safeInputDouble();
    }

    // ����� ��������� �������
    cout << "\n�������� ������:\n";
    printArray(arr, n);

    // ���������� � ����� ����� ������������� ���������
    double sumNegative = sumNegativeElements(arr, n);
    cout << "1) ����� ������������� ��������� = " << sumNegative << "\n";

    // ���������� � ����� ������������ ����� min � max
    double product = multiplyBetweenMinMax(arr, n);
    cout << "2) ������������ ����� min � max ���������� = " << product << "\n";

    // ���������� �������
    sortArray(arr, n);
    cout << "������ ������������ �� �����������:\n";
    printArray(arr, n);

    return 0;
}

// ���������� �������

double safeInputDouble() {
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������ �����! ������� �����: ";
        }
        else {
            return value;
        }
    }
}

double sumNegativeElements(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void sortArray(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

double multiplyBetweenMinMax(const double arr[], int size) {
    if (size < 3) {
        // ���� ������ ������� ������ 3, �� ����� min � max �� ����� ���� ���������
        cout << "������: ������������ ��������� ��� ������������ ����� min � max.\n";
        return 1.0; 
    }

    int minIndex = 0;
    int maxIndex = 0;
    double minValue = arr[0];
    double maxValue = arr[0];

    for (int i = 0; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    // ��������, ��� minIndex < maxIndex
    if (minIndex > maxIndex) {
        swap(minIndex, maxIndex);
    }

    // ���� ����������� � ������������ �������� ����� �����
    if (minIndex + 1 == maxIndex) {
        cout << "������: ����������� � ������������ �������� ����� �����. ������������ ����������.\n";
        return 1.0;
    }

    double product = 1.0;
    for (int i = minIndex + 1; i < maxIndex; ++i) {
        product *= arr[i];
    }

    return product;
}

void printArray(const double arr[], int size) { 
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
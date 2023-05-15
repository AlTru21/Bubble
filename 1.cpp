#include <iostream>
#include <string>
#include <chrono>
void insert(int* a, int n) {  // функция вставки 
    int i, j, t; 
    for (i = 1; i < n; i++) { // изменение в условии цикла 
        t = a[i]; 
        for (j = i - 1; j >= 0 && t < a[j]; j--) { 
            a[j + 1] = a[j]; 
        } 
    a[j + 1] = t; 
    } 
}
void bubble(int* a, int n) { // функция пузырька 
    int i, j, t; 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { // изменение в условии цикла 
            if (a[j] > a[j + 1]) { 
                t = a[j]; 
                a[j] = a[j + 1]; 
                a[j + 1] = t; 
            } 
        } 
    } 
}
int main() { 
    int n, choice; 
    std::cout << "Enter the size of the array: "; 
    std::cin >> n;
    int* a = new int[n]; // выделение памяти под массив
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }
    std::cout << "Select sorting method:\n";
    std::cout << "1. Insertion sort\n";
    std::cout << "2. Bubble sort\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    auto start = std::chrono::high_resolution_clock::now(); // начало измерения времени
    if (choice == 1) {
        insert(a, n); // вызов функции вставки
    }
    else if (choice == 2) {
        bubble(a, n); // вызов функции пузырька
    }
    else {
        std::cout << "Incorrect choice!\n";
        return 0;
    }
    auto stop = std::chrono::high_resolution_clock::now(); // конец измерения времени
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // вычисление затраченного времени в микросекундах
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken by the sorting function: " << duration.count() << " microseconds\n"; // вывод затраченного времени
    delete[] a; // освобождение памяти
    return 0;
}

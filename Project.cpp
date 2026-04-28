#include <iostream>
#include <cstring>
#include <clocale>// Підключаємо бібліотеки
using namespace std;
class ArrayFloatMult {// клас
private:
    int size;
    string* A;
public:
    ArrayFloatMult(int _size, string* _A) : size(_size) { // Конструктор з параметрами
        A = new string[size];
        for (int i = 0; i < size; ++i) {
            A[i] = _A[i];
        }
    }
    void SetSize(int _size) {
        if (_size > 0) {
            string* newArray = new string[_size];
            for (int i = 0; i < std::min(size, _size); ++i) {
           }     
            delete[] A;
            A = newArray; 
                size = _size;
        }
    }
    string* GetA(){
        string* result = new string[size];
        for (int i = 0; i < size; ++i) {
            result[i] = A[i];
        }
     return result;
    }
    int GetB() {
        int result = A[0].size();
        for (int i = 1; i < size; ++i) {
            if (A[i].size() > result) {
                result = A[i].size();
            }
        }
        return result;
    }
    

    void SetA(string* _A) {
        for (int i = 0; i < size; ++i) {
            A[i] = _A[i];
        }
    }
};
int main() {
    setlocale(LC_ALL, "ukr");  int n = 20; int s = 1 ; int r = 1;
    string* values = new string[n];
     cout << "Введiть елементи масиву: ";
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
         cin >> values[i];
    }
    ArrayFloatMult array(n, values);
    int resultArray = array.GetB();
    for (int i = 1; i < n ; ++i) {
        if (array.GetA()[i].size() < array.GetA()[s].size()) {
            s = i;
        }
        if (array.GetA()[i].size() > array.GetA()[r].size()) {
            r = i;
        }
     }   
    swap(array.GetA()[s], array.GetA()[r]);
    for (int i = 0; i < n; ++i) {
        cout <<array.GetA()[i] << " ";
    }
}
// Transfer_constructor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
class DynArray {
    int* arr;
    int size;
public:
    DynArray() : DynArray(5) {}
    DynArray(int size) : arr{ new int[size]}, size{size}
    {
        cout << "DynArray конструктор размера " << size
            << " Адресс: " << this << endl;
    }
    DynArray(const DynArray& object){
        size = object.size;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = object.arr[i];
        }
        cout << "DynArray конструктор копирования " << size <<
            " Адрес: " << this << endl;
    }
    DynArray& operator=(const DynArray& object) {
        
        if (!(this == &object)) {
            if (size != object.size) {
                delete[] arr;
                arr = new int[object.size];
            }
            size = object.size;
            for (size_t i = 0; i < size; i++)
            {
                arr[i] = object.arr[i];
            }
        }
        cout << "DynArray оператор присваивания " << size <<
            " Адрес: " << this << endl;
        return *this;
    }
    int getElem(int id) const {
        
    }
    void setElem(int index, int value) {
        arr[index] = value;
    }
    void print() const {
        for (size_t i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    void randomize() {
        
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 10;
        }
    }
};


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    DynArray arr1(10);
    arr1.randomize();
    cout << "Arr1: " << endl;
    arr1.print();
    arr1.randomize();
    cout << "Arr1: " << endl;
    arr1.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

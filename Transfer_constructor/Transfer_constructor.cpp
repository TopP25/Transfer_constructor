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
    DynArray(DynArray&& object) : arr{ object.arr }, size{ object.size } {
        object.arr = nullptr;
        object.size = 0;
        cout << "DynArray rval конструктор " << size
            << " Адресс: " << this << endl;
    }
    ~DynArray() {
        cout << "DEST" << this << " Адрес arr: " << arr << endl;
        delete[] arr;
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
        return arr[id];
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


void funA(int& val) {
    cout << "funA int& \n";
}
void funA(const int& val) {
    cout << "funA cons int& \n";
}
void funA(int&& val) {
    cout << "funA int&& \n";
}

void funB(int& val) {
    cout << " int \n";
}
void funB(const int& val) {
    cout << "funb const int& \n";
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    DynArray arr1(10);
    arr1.randomize();
    cout << "Arr1: " << endl;
    arr1.print();
    DynArray arr2;
    arr2.randomize();
    cout << "Arr2: " << endl;
    arr2.print();
    DynArray arr3(arr1);
    cout << "Arr3: " << endl;
    arr3.print();

    /*arr3 = arr2;
    cout << "Arr3 = Arr2, Arr3 = " << endl;
    arr3.print();*/

    DynArray arr4(move(arr2));
    cout << "arr4(move(arr2)) " << endl;
    arr4.print();
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
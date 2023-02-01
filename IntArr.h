#pragma once


template <typename T>class Arr
{
private:
    int m_length{};
    T* m_data{};
public:
    Arr();
    Arr(int length);
    Arr(const Arr& a);

    ~Arr();

    void erase();
    T& operator[](int index);
    void reallocate(int newLength); // уничтожит все существующие элементы в массиве при изменении его размера
    
    void resize(int newLength);// сохранит все существующие элементы в массиве
    T& operator=(T& a);//перегрузка оператор
    
   

    void insertBefore(T value, int index);   //заменяет элемент
    void remove(int index);   //удаляет элемент

    void insertAtBeginning(T value);
    
    void insertAtEnd(T value);
   
    T getLength() const;
 };





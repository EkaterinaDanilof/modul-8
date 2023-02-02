#pragma once
#include "exception.h"

template <typename T>class Arr
{
private:
    int m_length;
    T* m_data;
public:
    Arr();
    Arr(int length);
    Arr(const Arr& a);
    ~Arr();
    
    void erase();
   
    T& operator[](int index);
    
    void reallocate(int newLength);      // уничтожит все существующие элементы в массиве при изменении его размера
    
    void resize(int newLength);   // сохранит все существующие элементы в массиве
    
    T& operator=(T& a);   //перегрузка оператор
    
    void insertBefore(T value, int index);   //заменяет элемент
    
    void remove(int index);   //удаляет элемент
    
    void insertAtBeginning(T value);
    
    void insertAtEnd(T value);
    T getLength() const;
 };
template <typename T>Arr<T>::Arr() = default;

template <typename T>Arr<T>::Arr(int length)
{
    m_length = length;
    {
        if (length <= 0)
            throw Bad_Length();
        else
            m_data = new T[length] {};
    }
}

template <typename T>Arr<T>::Arr(const Arr & a)
{

    reallocate(a.getLength());


    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
}

template <typename T>Arr<T>::~Arr()
{
    delete[] m_data;
}

template <typename T>void Arr<T>::erase()
{
    delete[] m_data;

    m_data = nullptr;
    m_length = 0;
}

template <typename T>T& Arr<T>::operator[](int index)
{
    // TODO: вставьте здесь оператор return
    if (index < 0 || index > m_length)
        throw Bad_Range();
    else  return m_data[index];
}

template <typename T> void Arr<T>::reallocate(int newLength)
{
    erase();   //обнуляем и задаем новую длину 


    if (newLength <= 0)
        throw Bad_Length();
    else
    {
        m_data = new T[newLength];
        m_length = newLength;
    }
}

template <typename T> void Arr<T>::resize(int newLength)
{
    if (newLength == m_length)
        return;


    if (newLength <= 0)
    {
        erase();
        return;
    }


    T* data{ new T[newLength] };


    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };


        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }


    delete[] m_data;


    m_data = data;
    m_length = newLength;
}

template <typename T>T& Arr<T>::operator=(T & a)  //template <typename T>T& Arr<T>::operator[](int index)
{
    // TODO: вставьте здесь оператор return

    if (&a == this)
        return *this;


    reallocate(a.getLength());


    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}


template<typename T>
void Arr<T>::insertBefore(T value, int index)
{
    if (index < 0 || index > m_length)
        throw Bad_insertBefore();
    else {

        T* data{ new T[m_length + 1] };


        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];


        data[index] = value;


        for (int after{ index }; after < m_length; ++after)
            data[after + 1] = m_data[after];


        delete[] m_data;
        m_data = data;
        ++m_length;
    }
}

template <typename T> void Arr<T>::remove(int index)
{
    if (index < 0 || index > m_length)
        throw Bad_Range();


    if (m_length == 1)
    {
        erase();
        return;
    }


    T* data{ new T[m_length - 1] };


    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];


    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];


    delete[] m_data;
    m_data = data;
    --m_length;
}

template<typename T>
void Arr<T>::insertAtBeginning(T value)
{
    insertBefore(value, 0);
}

template<typename T>
void Arr<T>::insertAtEnd(T value)
{
    insertBefore(value, m_length);
}


template <typename T> T Arr<T>::getLength() const
{
    return m_length;
}






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
    void reallocate(int newLength); // ��������� ��� ������������ �������� � ������� ��� ��������� ��� �������
    
    void resize(int newLength);// �������� ��� ������������ �������� � �������
    T& operator=(T& a);//���������� ��������
    
   

    void insertBefore(T value, int index);   //�������� �������
    void remove(int index);   //������� �������

    void insertAtBeginning(T value);
    
    void insertAtEnd(T value);
   
    T getLength() const;
 };





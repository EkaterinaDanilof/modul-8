#pragma once

class exception
{
};
class Bad_Range : public exception
{
public:
    virtual const char* what() const noexcept
    {
        return "ОШИБКА: Вне диапазона контейнера.";
    }
    
};
class Bad_Length : public exception
{
public:
    virtual const char* what() const noexcept
    {
        return "ОШИБКА: Неправильная длина массива.";
    }
    
};
class Bad_insertBefore :public exception
{
public:
    virtual const char* what() const noexcept
    {
        return "ОШИБКА: Неправильная подстановка.";
    }
};


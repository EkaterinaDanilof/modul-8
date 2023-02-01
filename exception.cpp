#include "exception.h"

const char* Bad_Range::what() const noexcept
{
	return "ОШИБКА: Вне диапазона контейнера.";
    
}

const char* Bad_Length::what() const noexcept
{
	return "ОШИБКА: Неправильная длина массива.";
}

const char* Bad_insertBefore::what() const noexcept
{
	return "ОШИБКА: Неправильная подстановка.";
}

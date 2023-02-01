#pragma once

class exception
{
};
class Bad_Range : public exception
{
public:
    virtual const char* what() const noexcept; //override
    
};
class Bad_Length : public exception
{
public:
    virtual const char* what() const noexcept; //override
    
};
class Bad_insertBefore :public exception
{
public:
    virtual const char* what() const noexcept; //override
    
};


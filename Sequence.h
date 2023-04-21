#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

class Sequence abstract
{
public:
    virtual double getValueOfElement(int& number_element) abstract;                         //получения значения произвольного элемента
    virtual void setValueOfElement(int& number_element, double& value_element) abstract;    //установки значения произвольного элемента
    virtual void addValueOfElement(double& value_element) abstract;                         //добавления элемента в конец последовательности
};
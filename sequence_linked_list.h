#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

#include "Sequence.h"
#include "NodeStack.h"

class sequence_linked_list : public Sequence
{
private:
    NodeStack* pTop;                                             //указатель на вершину стека

public:
    sequence_linked_list();                                      //конструктор по умолчанию

    sequence_linked_list(const sequence_linked_list& l);         //конструктор копировання

    ~sequence_linked_list();                                     //деструктор

    void push(double item);                                      //поместить элемент в стек, элемент помещается на начало списка

    double pop();                                                //метод, вытягивающий элемент со стека

    int count();                                                 //количество элементов в стеке

    void empty();                                                //очищает стек - удаляет все элементы из стека
 
    sequence_linked_list& operator=(const sequence_linked_list& l);      //оператор копирования

    void print(const char* l);                                   //вывод списка

    double getValueOfElement(int& number_element) override;

    void setValueOfElement(int& number_element, double& value_element) override;

    void addValueOfElement(double& new_element) override;
};
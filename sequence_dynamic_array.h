#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

#include "Sequence.h"

class sequence_dynamic_array : public Sequence
{
private:
    int m_size;                                 //размер последовательности (количество элементов в последовательности, доступных пользователю)
    int m_capacity;                             //"вместимость" последовательности, то есть размер выделенной памяти для хранения элементов
    double* m_data;                             //указатель на область памяти, где хранятся сами элементы последовательности

public:
    sequence_dynamic_array();                                    //конструктор по умолчанию создает пустую последовательность, не содержащий элементов

    sequence_dynamic_array(sequence_dynamic_array& a);           //копи-конструктор создает копию существующего последовательности

    sequence_dynamic_array(int size);                            //конструктор, который создает последовательность заданного размера

    ~sequence_dynamic_array();                                   //деструктор 

    void resize(int size);                                       //метод resize изменяет размер последовательности, новый размер передается параметром size

    void push_back(double val);                                  //метод push_back добавляет один новый элемент в конец последовательности

    int size() const;                                            //метод size возвращает размер последовательности

    double& operator[] (int i);                                  //доступ к элементам последовательности, перегрузим оператор [].
                                                                 //это позволит обращаться к элементам последовательности sequence_dynamic_array так же, как к элементам обычного массива: a[i]
    double getValueOfElement(int& number_element) override;

    void setValueOfElement(int& number_element, double& value_element) override;

    void addValueOfElement(double& new_element) override;
};
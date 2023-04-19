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
    NodeStack* pTop;                                             //��������� �� ������� �����

public:
    sequence_linked_list();                                      //����������� �� ���������

    sequence_linked_list(const sequence_linked_list& l);         //����������� �����������

    ~sequence_linked_list();                                     //����������

    void push(double item);                                      //��������� ������� � ����, ������� ���������� �� ������ ������

    double pop();                                                //�����, ������������ ������� �� �����

    int count();                                                 //���������� ��������� � �����

    void empty();                                                //������� ���� - ������� ��� �������� �� �����
 
    sequence_linked_list& operator=(const sequence_linked_list& l);      //�������� �����������

    void print(const char* l);                                   //����� ������

    double getValueOfElement(int& number_element) override;

    void setValueOfElement(int& number_element, double& value_element) override;

    void addValueOfElement(double& new_element) override;
};
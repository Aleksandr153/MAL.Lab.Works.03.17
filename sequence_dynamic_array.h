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
    int m_size;                                 //������ ������������������ (���������� ��������� � ������������������, ��������� ������������)
    int m_capacity;                             //"�����������" ������������������, �� ���� ������ ���������� ������ ��� �������� ���������
    double* m_data;                             //��������� �� ������� ������, ��� �������� ���� �������� ������������������

public:
    sequence_dynamic_array();                                    //����������� �� ��������� ������� ������ ������������������, �� ���������� ���������

    sequence_dynamic_array(sequence_dynamic_array& a);           //����-����������� ������� ����� ������������� ������������������

    sequence_dynamic_array(int size);                            //�����������, ������� ������� ������������������ ��������� �������

    ~sequence_dynamic_array();                                   //���������� 

    void resize(int size);                                       //����� resize �������� ������ ������������������, ����� ������ ���������� ���������� size

    void push_back(double val);                                  //����� push_back ��������� ���� ����� ������� � ����� ������������������

    int size() const;                                            //����� size ���������� ������ ������������������

    double& operator[] (int i);                                  //������ � ��������� ������������������, ���������� �������� [].
                                                                 //��� �������� ���������� � ��������� ������������������ sequence_dynamic_array ��� ��, ��� � ��������� �������� �������: a[i]
    double getValueOfElement(int& number_element) override;

    void setValueOfElement(int& number_element, double& value_element) override;

    void addValueOfElement(double& new_element) override;
};
#include "sequence_dynamic_array.h"

sequence_dynamic_array::sequence_dynamic_array()                                    //����������� �� ��������� ������� ������ ������������������, �� ���������� ���������
{
    m_size = 0;
    m_capacity = 0;
    m_data = NULL;
}

sequence_dynamic_array::sequence_dynamic_array(sequence_dynamic_array& a)           //����-����������� ������� ����� ������������� ������������������
{
    m_size = a.m_size;
    m_capacity = m_size;
    m_data = NULL;
    if (m_size != 0)
        m_data = new double[m_size];
    else
        m_data = 0;
    for (int i = 0; i < m_size; ++i)
        m_data[i] = a.m_data[i];
}

sequence_dynamic_array::sequence_dynamic_array(int size)                            //�����������, ������� ������� ������������������ ��������� �������
{
    m_size = size;
    m_capacity = size;
    if (size != 0)
        m_data = new double[size];
    else
        m_data = 0;
}

sequence_dynamic_array::~sequence_dynamic_array()                                   //���������� 
{
    if (m_data)
        delete[] m_data;
}

void sequence_dynamic_array::resize(int size)                                       //����� resize �������� ������ ������������������, ����� ������ ���������� ���������� size
{
    if (size > m_capacity)
    {
        int new_capacity = max(size, m_size * 2);
        double* new_data = new double[new_capacity];
        for (int i = 0; i < m_size; ++i)
            new_data[i] = m_data[i];
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
    m_size = size;
}

void sequence_dynamic_array::push_back(double val)                                  //����� push_back ��������� ���� ����� ������� � ����� ������������������
{
    resize(m_size + 1);
    m_data[m_size - 1] = val;
}

int sequence_dynamic_array::size() const                                            //����� size ���������� ������ ������������������
{
    return m_size;
}

double& sequence_dynamic_array::operator[] (int i)                                  //������ � ��������� ������������������, ���������� �������� [].
{                                                                                   //��� �������� ���������� � ��������� ������������������ sequence_dynamic_array ��� ��, ��� � ��������� �������� �������: a[i]
    return m_data[i];
}

double sequence_dynamic_array::getValueOfElement(int& number_element) 
{
    return m_data[number_element];
}

void sequence_dynamic_array::setValueOfElement(int& number_element, double& value_element) 
{
    cout << "�������� ������� ��� �������: " << number_element << " ������: " << m_data[number_element] << endl;
    m_data[number_element] = value_element;
    cout << "�������� ��: " << value_element << endl;
    return;
}

void sequence_dynamic_array::addValueOfElement(double& new_element) 
{
    this->push_back(new_element);
    cout << "����� ��������: " << new_element << " ��������� � ������������������" << endl;
    return;
}
#include "sequence_linked_list.h"

sequence_linked_list::sequence_linked_list()                                      //����������� �� ���������
{
    pTop = nullptr;
}

sequence_linked_list::sequence_linked_list(const sequence_linked_list& l)         //����������� �����������
{
    NodeStack* p1;                                          //�������������� ���������
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;
    p3 = nullptr;
    
    p1 = l.pTop;                                            //��������� p1 �������� �� ������ l.pTop->...
    while (p1 != nullptr)
    {
        try                                                 //1. ������������ ���� p2
        {
                p2 = new NodeStack;                         //������� ��������� ������
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                       //���� ������ �� ��������, �� �����
            return;
        }
        
        p2->item = p1->item;
        p2->next = nullptr;
        
        if (pTop == nullptr)                                //2. pTop = pTop + p2
        {
            pTop = p2;                                      //������� �������
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                      //3. ������� �� ��������� �������
    }
}

sequence_linked_list::~sequence_linked_list()                                     //����������
{
    empty();
}

void sequence_linked_list::push(double item)                                      //��������� ������� � ����, ������� ���������� �� ������ ������
{
    NodeStack* p1;
    
    try                                                     //1. ������������ �������
    {
        p1 = new NodeStack;                                 //������� �������� ������
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;                           //���� ������ �� ����������, �� �����
        return;
    }

    p1->item = item;
    p1->next = pTop;                                        //p1 ��������� �� 1-� �������
    
    pTop = p1;                                               //2. ������������� pTop �� p1
}


double sequence_linked_list::pop()                                                //�����, ������������ ������� �� �����
{
    if (pTop == nullptr)                                    //��������, ���� �� ����?
        return 0;

    NodeStack* p2;                                          //�������������� ���������
    double item;
    item = pTop->item;
    
    p2 = pTop;                                              //������������� ��������� pTop, p2
    pTop = pTop->next;
    
    delete p2;                                              //���������� ������, ���������� ��� 1-� �������
    
    return item;                                            //������� item
}

int sequence_linked_list::count()                                                 //���������� ��������� � �����
{
    if (pTop == nullptr)
        return 0;
    else
    {
        NodeStack* p1 = pTop;
        int c = 0;
        
        while (p1 != nullptr)
        {
            c++;
            p1 = p1->next;
        }
        return c;
    }
}

void sequence_linked_list::empty()                                                //������� ���� - ������� ��� �������� �� �����
{
    NodeStack* p1;                                          //�������������� ���������
    NodeStack* p2;

    p1 = pTop;
    
    while (p1 != nullptr)
    {
        p2 = p1;                                            //������� ����� �� p1
        p1 = p1->next;                                      //������� �� ��������� ������� �����
        delete p2;                                          //������� ������, ���������� ��� ����������� ��������
    }
    pTop = nullptr;                                         //��������� ������� �����
}

sequence_linked_list& sequence_linked_list::operator=(const sequence_linked_list& l)      //�������� �����������
{
    
    if (pTop != nullptr)                                    //���� �� �������� � �����?
        empty();
    
    NodeStack* p1;                                          //�������������� ���������
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;                                         //����������������� pTop
    p3 = nullptr;
    
    p1 = l.pTop;                                            //��������� p1 ��������� �� ������ l.pTop->...
    while (p1 != nullptr)
    {
        try                                                 //1. ������������ ���� p2
        {
            p2 = new NodeStack;                             //������� �������� ������   
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                       //���� ������ �� ��������, �� �����
            return *this;
        }

        p2->item = p1->item;
        p2->next = nullptr;

        if (pTop == nullptr)                                //2. pTop = pTop + p2
        {
            pTop = p2;                                      //������� ����
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                      //3. ������� �� ��������� �������
    }
    return *this;
}

void sequence_linked_list::print(const char* l)                                   //����� ������
{
    cout << "������������������: " << l << endl;
    if (pTop == nullptr)
        cout << "������������������ �����." << endl;
    else
    {
        NodeStack* p1;                                      //�������������� ���������
        p1 = pTop;
        while (p1 != nullptr)
        {
            cout << p1->item << " ";
            p1 = p1->next;
        }
        cout << endl;
    }
}

double sequence_linked_list::getValueOfElement(int& number_element) 
{
    sequence_linked_list lstTemp = *this;
    int number_element_from_top;
    number_element_from_top = this->count() - number_element;
    for (int i = 0; i < number_element_from_top - 1; i++)
        lstTemp.pop();
    return lstTemp.pop();
}

void sequence_linked_list::setValueOfElement(int& number_element, double& value_element) 
{
    sequence_linked_list lstTemp;
    int number_element_from_top;
    number_element_from_top = this->count() - number_element;
    for (int i = 0; i < number_element_from_top - 1; i++)
        lstTemp.push(this->pop());
    this->pop();
    this->push(value_element);
    for (int i = 0; i < number_element_from_top - 1; i++)
        this->push(lstTemp.pop());
    return;
}

void sequence_linked_list::addValueOfElement(double& new_element) 
{
    this->push(new_element);
    cout << "����� ��������: " << new_element << " ��������� � ������������������" << endl;
    return;
}
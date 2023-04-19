#include "sequence_linked_list.h"

sequence_linked_list::sequence_linked_list()                                      //конструктор по умолчанию
{
    pTop = nullptr;
}

sequence_linked_list::sequence_linked_list(const sequence_linked_list& l)         //конструктор копировання
{
    NodeStack* p1;                                          //дополнительные указатели
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;
    p3 = nullptr;
    
    p1 = l.pTop;                                            //указатель p1 движется по списку l.pTop->...
    while (p1 != nullptr)
    {
        try                                                 //1. Сформировать узел p2
        {
                p2 = new NodeStack;                         //попытка выделения памяти
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                       //если память не выделена, то выход
            return;
        }
        
        p2->item = p1->item;
        p2->next = nullptr;
        
        if (pTop == nullptr)                                //2. pTop = pTop + p2
        {
            pTop = p2;                                      //создать очередь
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                      //3. Перейти на следующий элемент
    }
}

sequence_linked_list::~sequence_linked_list()                                     //деструктор
{
    empty();
}

void sequence_linked_list::push(double item)                                      //поместить элемент в стек, элемент помещается на начало списка
{
    NodeStack* p1;
    
    try                                                     //1. Сформировать элемент
    {
        p1 = new NodeStack;                                 //попытка выделить память
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;                           //если память не выделилась, то выход
        return;
    }

    p1->item = item;
    p1->next = pTop;                                        //p1 указывает на 1-й элемент
    
    pTop = p1;                                               //2. Перенаправить pTop на p1
}


double sequence_linked_list::pop()                                                //метод, вытягивающий элемент со стека
{
    if (pTop == nullptr)                                    //проверка, пуст ли стек?
        return 0;

    NodeStack* p2;                                          //дополнительный указатель
    double item;
    item = pTop->item;
    
    p2 = pTop;                                              //перенаправить указатели pTop, p2
    pTop = pTop->next;
    
    delete p2;                                              //освободить память, выделенную под 1-й элемент
    
    return item;                                            //вернуть item
}

int sequence_linked_list::count()                                                 //количество элементов в стеке
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

void sequence_linked_list::empty()                                                //очищает стек - удаляет все элементы из стека
{
    NodeStack* p1;                                          //дополнительный указатель
    NodeStack* p2;

    p1 = pTop;
    
    while (p1 != nullptr)
    {
        p2 = p1;                                            //сделать копию из p1
        p1 = p1->next;                                      //перейти на следующий элемент стека
        delete p2;                                          //удалить память, выделенную для предыдущего элемента
    }
    pTop = nullptr;                                         //поправить вершину стека
}

sequence_linked_list& sequence_linked_list::operator=(const sequence_linked_list& l)      //оператор копирования
{
    
    if (pTop != nullptr)                                    //есть ли элементы в стеке?
        empty();
    
    NodeStack* p1;                                          //дополнительный указатель
    NodeStack* p2;
    NodeStack* p3;
    
    pTop = nullptr;                                         //иИнициализировать pTop
    p3 = nullptr;
    
    p1 = l.pTop;                                            //указатель p1 двигается по списку l.pTop->...
    while (p1 != nullptr)
    {
        try                                                 //1. Сформировать узел p2
        {
            p2 = new NodeStack;                             //попытка выделить память   
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;                       //если память не выделена, то выход
            return *this;
        }

        p2->item = p1->item;
        p2->next = nullptr;

        if (pTop == nullptr)                                //2. pTop = pTop + p2
        {
            pTop = p2;                                      //создать стек
            p3 = p2;
        }
        else
        {
            p3->next = p2;
            p3 = p3->next;
        }
        
        p1 = p1->next;                                      //3. Перейти на следующий элемент
    }
    return *this;
}

void sequence_linked_list::print(const char* l)                                   //вывод списка
{
    cout << "Последовательность: " << l << endl;
    if (pTop == nullptr)
        cout << "Последовательность пуста." << endl;
    else
    {
        NodeStack* p1;                                      //дополнительный указатель
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
    cout << "Новое значение: " << new_element << " добавлено в последовательность" << endl;
    return;
}
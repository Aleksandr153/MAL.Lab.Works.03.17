#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

struct Leaks
{
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

/*

17.

Создать абстрактный класс «последовательность» с абстрактными функциями
получения значения произвольного элемента,
установки значения произвольного элемента,
добавления элемента в конец последовательности.

Создать реализации класса «последовательность»
на основе динамического массива sequence_dynamic_array
и
на основе односвязного списка sequence_linked_list .

последовательность - sequence

*/

#include "Sequence.h"
#include "sequence_dynamic_array.h"
#include "NodeStack.h"
#include "sequence_linked_list.h"
#include "ostream_operator_cout.h"

/*

class Sequence abstract
{
public:
    virtual double getValueOfElement(int& number_element) abstract;
    virtual void setValueOfElement(int& number_element, double& value_element) abstract;
    virtual void addValueOfElement(double& value_element) abstract;
};

class sequence_dynamic_array : public Sequence
{
private:
    int m_size;                                 //размер последовательности (количество элементов в последовательности, доступных пользователю)
    int m_capacity;                             //"вместимость" последовательности, то есть размер выделенной памяти для хранения элементов
    double* m_data;                             //указатель на область памяти, где хранятся сами элементы последовательности

public:
    sequence_dynamic_array()                                    //конструктор по умолчанию создает пустую последовательность, не содержащий элементов
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
    }

    sequence_dynamic_array(sequence_dynamic_array& a)           //копи-конструктор создает копию существующего последовательности
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

    sequence_dynamic_array(int size)                            //конструктор, который создает последовательность заданного размера
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new double[size];
        else
            m_data = 0;
    }

    ~sequence_dynamic_array()                                   //деструктор 
    {
        if (m_data)
            delete[] m_data;
    }

    void resize(int size)                                       //метод resize изменяет размер последовательности, новый размер передается параметром size
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

    void push_back(double val)                                  //метод push_back добавляет один новый элемент в конец последовательности
    {
        resize(m_size + 1);
        m_data[m_size - 1] = val;
    }

    int size() const                                            //метод size возвращает размер последовательности
    {
        return m_size;
    }

    double& operator[] (int i)                                  //доступ к элементам последовательности, перегрузим оператор [].
    {                                                           //это позволит обращаться к элементам последовательности sequence_dynamic_array так же, как к элементам обычного массива: a[i]
        return m_data[i];
    }

    double getValueOfElement(int& number_element) override
    {
        return m_data[number_element];
    }

    void setValueOfElement(int& number_element, double& value_element) override
    {
        cout << "Значение элемент под номером: " << number_element << " равное: " << m_data[number_element] << endl;
        m_data[number_element] = value_element;
        cout << "Заменено на: " << value_element << endl;
        return;
    }

    void addValueOfElement(double& new_element) override
    {
        this->push_back(new_element);
        cout << "Новое значение: " << new_element << " добавлено в последовательность"<< endl;
        return;
    }
};

struct NodeStack                                                //структура описывающая узел
{
    double item;
    NodeStack* next;
};

class sequence_linked_list : public Sequence                    
{
private:
    NodeStack* pTop;                                            //указатель на вершину стека

public:
    sequence_linked_list()                                      //конструктор по умолчанию
    {
        pTop = nullptr;
    }                     

    sequence_linked_list(const sequence_linked_list& l)         //конструктор копировання
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
                p2 = new NodeStack;                             //попытка выделения памяти
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

    ~sequence_linked_list()                                     //деструктор
    {
        empty();
    }

    void push(double item)                                      //поместить элемент в стек, элемент помещается на начало списка
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

    double pop()                                                //метод, вытягивающий элемент со стека
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
    
    int count()                                                 //количество элементов в стеке
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
    
    void empty()                                                //очищает стек - удаляет все элементы из стека
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

    sequence_linked_list& operator=(const sequence_linked_list& l)      //оператор копирования
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

    void print(const char* l)                                   //вывод списка
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

    double getValueOfElement(int& number_element) override
    {
        sequence_linked_list lstTemp = *this;
        int number_element_from_top;
        number_element_from_top = this->count() - number_element;
        for (int i = 0; i < number_element_from_top - 1; i++)
            lstTemp.pop();
        return lstTemp.pop();
    }


    void setValueOfElement(int& number_element, double& value_element) override
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

    void addValueOfElement(double& new_element) override
    {
        this->push(new_element);
        cout << "Новое значение: " << new_element << " добавлено в последовательность" << endl;
        return;
    }
};

ostream& operator << (ostream& out, sequence_dynamic_array a)   //функция потокового вывода последовательности для консоли ( операция << );
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}

*/

int main()
{
    setlocale(LC_ALL, "Russian");

    int valueNew = NULL;
    bool number_element_Bool;

    //последовательность - динамический массив

    sequence_dynamic_array arr;
    int sizeSDA;

    cout << "Введите размер последовательности, на основе динамического массива: ";
    cin >> sizeSDA;                                             // получение от пользователя размера последовательности

    arr.resize(sizeSDA);

    for (int i = 0; i < arr.size(); i++)
    {
        valueNew = NULL;
        printf("Введите значение №%d: ", i);
        cin >> valueNew;
        arr[i] = valueNew;
    }

    cout << endl;
    printf("Значения последовательности\n");
    cout << arr << endl;
    
    int number_element_GVOE;
    double value_element_GVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите номер элемента последовательности, значение которого вы хотите получить: ";
        cin >> number_element_GVOE;                             // получение от пользователя номера искомого элемента последовательности

        if (number_element_GVOE < arr.size())
        {
            value_element_GVOE = arr.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "Значение элемента последовательности: ";
            cout << value_element_GVOE << endl;
            number_element_Bool = false;
        }
        else
        {
            cout << "Номер элемента последовательности больше размера последовательности" << endl;
            number_element_Bool = true;
        }
    }

    int number_element_SVOE;
    double value_element_SVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите номер элемента последовательности, значение которого вы хотите изменить: ";
        cin >> number_element_SVOE;                             // получение от пользователя номера заменяемого элемента последовательности

        if (number_element_SVOE < arr.size())
        {
            cout << endl;
            cout << "Введите новое значение элемента последовательности: ";
            cin >> value_element_SVOE;                          // получение от пользователя значения заменяемого элемента последовательности 
 
            arr.setValueOfElement(number_element_SVOE, value_element_SVOE);
            
            cout << endl;
            printf("Значения последовательности\n");
            cout << arr << endl;
            number_element_Bool = false;
        }
        else
        {
            cout << "Номер элемента последовательности больше размера последовательности" << endl;
            number_element_Bool = true;
        }
    }

    double value_element_AVOE;

    cout << endl;
    cout << "Введите значение элемента последовательности которое вы хотите добавить в последовательность: ";
    cin >> value_element_AVOE;                                  // получение от пользователя добавляемого значения в  последовательность

    arr.addValueOfElement(value_element_AVOE);

    cout << endl;
    printf("Значения последовательности\n");
    cout << arr << endl << endl;

    //последовательность - связанный список

    sequence_linked_list lst;
    int sizeSLL;

    cout << "Введите размер последовательности на основе связанного списка: ";
    cin >> sizeSLL;                                             // получение от пользователя размера последовательности

    valueNew = NULL;
    for (int i = 0; i < sizeSLL; i++)
    {
        printf("Введите значение №%d: ", i);
        cin >> valueNew;
        lst.push(valueNew);
    }
    cout << endl;
    lst.print("lst");

    //int number_element_GVOE;
    //double value_element_GVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите номер элемента последовательности, значение которого вы хотите получить: ";
        cin >> number_element_GVOE;                             // получение от пользователя номера искомого элемента последовательности

        if (number_element_GVOE < lst.count())
        {
            value_element_GVOE = lst.getValueOfElement(number_element_GVOE);
            cout << endl;
            cout << "Значение элемента последовательности: ";
            cout << value_element_GVOE << endl;
            number_element_Bool = false;
        }
        else
        {
            cout << "Номер элемента последовательности больше размера последовательности " << lst.count() << endl;
            number_element_Bool = true;
        }
    }

    //int number_element_SVOE;
    //double value_element_SVOE;

    number_element_Bool = true;
    while (number_element_Bool)
    {
        cout << endl;
        cout << "Введите номер элемента последовательности, значение которого вы хотите изменить: ";
        cin >> number_element_SVOE;                             // получение от пользователя номера заменяемого элемента последовательности

        if (number_element_SVOE < lst.count())
        {
            cout << endl;
            cout << "Введите новое значение элемента последовательности: ";
            cin >> value_element_SVOE;                          // получение от пользователя значения заменяемого элемента последовательности 

            lst.setValueOfElement(number_element_SVOE, value_element_SVOE);

            cout << endl;
            lst.print("lst");
            number_element_Bool = false;
        }
        else
        {
            cout << "Номер элемента последовательности больше размера последовательности" << endl;
            number_element_Bool = true;
        }
    }

    //double value_element_AVOE;

    cout << endl;
    cout << "Введите значение элемента последовательности которое вы хотите добавить в последовательность: ";
    cin >> value_element_AVOE;                            // получение от пользователя добавляемого значения в  последовательность

    lst.addValueOfElement(value_element_AVOE);

    cout << endl;
    lst.print("lst");

    return 0;
}
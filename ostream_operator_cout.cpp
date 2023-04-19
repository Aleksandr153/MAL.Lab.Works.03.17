#include "ostream_operator_cout.h"

ostream& operator << (ostream& out, sequence_dynamic_array a)   //функция потокового вывода последовательности для консоли ( операция << );
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}
#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

#include "Sequence.h"
#include "sequence_dynamic_array.h"

ostream& operator << (ostream& out, sequence_dynamic_array a);   //функция потокового вывода последовательности для консоли ( операция << );
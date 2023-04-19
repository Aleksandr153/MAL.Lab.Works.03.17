#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

struct NodeStack                                                //структура описывающая узел
{
    double item;
    NodeStack* next;
};
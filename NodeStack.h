#pragma once

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include<iostream>

using namespace std;

struct NodeStack                                                //��������� ����������� ����
{
    double item;
    NodeStack* next;
};
#include "accumulator.h"

Accumulator& Accumulator::add(int i) 
{
    accum += i;
    return *this;
}

int Accumulator::result() 
{
    return accum;
}
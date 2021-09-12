/*
    averageStack.h - Library for easily averaging n samples for PI(D) control
    Created by the Amber Lab at Caltech for an ankle-exoskeleton
*/

#include "Arduino.h"
#include "averageStack.h"

averageStack::averageStack(int size, double fillvalue)
{
    _size = size;
    _members = new double[_size];
    for (int i = 0; i < _size; i++) {
        _members[i] = fillvalue;
    }
    _avg = fillvalue;
    _position = 0;
}

void averageStack::enqueue(double member) {
    double old = _members[_position];
    _avg = _avg + (member - old) / _size;
    _members[_position] = member;
    _position++;
    if (_position >= _size) {
        _position = 0;
    }
}

void averageStack::flush(double fillvalue) {
    for (int i = 0; i < _size; i++) {
        _members[i] = fillvalue;
    }
}

double averageStack::get_average() {
    return _avg;
}
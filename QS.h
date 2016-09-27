//
//  QS.h
//  Lab08
//
//  Created by Zac Clark on 3/1/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#pragma once
#include "QSInterface.h"
#include <iostream>
#include <sstream>

using namespace std;

class QS : public QSInterface
{
public:
    QS();
    ~QS();
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray();
    int getSize();
    void addToArray(int value);
    bool createArray(int capacity);
    void clear();
    int lowestOfTwo(int first, int second);
    void sort(int left, int right);
    
private:
    int *Array = NULL;
    int arrayCapacity;
    int position;
};
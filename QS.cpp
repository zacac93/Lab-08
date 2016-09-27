//
//  QS.cpp
//  Lab08
//
//  Created by Zac Clark on 3/1/16.
//  Copyright © 2016 Zac Clark. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include <math.h>
#include "QS.h"

using namespace std;

QS::QS()
{
    arrayCapacity = 0;
    position = 0;
}

QS::~QS()
{
    clear();
}

void QS::sortAll()
{
    cout << "ran sortAll()" << endl;
    cout << "current array: " << endl;
    for (int i = 0; i < arrayCapacity; i++)
    {
        cout << Array[i] << ",";
    }
    cout << endl;
    if (arrayCapacity != 0)
    {
        int left = 0;
        int right = arrayCapacity-1;
    
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        
        sort(left, right);
    }
}

int QS::medianOfThree(int left, int right)
{
    cout << "ran medianOfThree()" << endl;
    cout << "current array: " << endl;
    for (int i = 0; i < arrayCapacity; i++)
    {
        cout << Array[i] << ",";
    }
    cout << endl;
    
    //check to make sure left is lower than right and not an empty array
    if (left >= right || arrayCapacity == 0)
        return -1;
    //check to make sure indices are not out of bounds
    if (left < 0 || right > (arrayCapacity-1))
        return -1;

    //calculate middle index
    int middle = (left + right) / 2;
    //find values
    int tempLeft = Array[left];
    int tempMiddle = Array[middle];
    int tempRight = Array[right];
    
    cout << "left: " << left << endl;
    cout << "middle: " << middle << endl;
    cout << "right: " << right << endl;
    
    int tempVar;
    if (tempMiddle < tempLeft)
    {
        cout << "middle was less than left (first)" << endl;
        tempVar = tempLeft;
        tempLeft = tempMiddle;
        tempMiddle = tempVar;
    }
    if (tempRight < tempMiddle)
    {
        cout << "right was less than middle" << endl;
        tempVar = tempMiddle;
        tempMiddle = tempRight;
        tempRight = tempVar;
    }
    if (tempMiddle < tempLeft)
    {
        cout << "middle was less than left (second)" << endl;
        tempVar = tempLeft;
        tempLeft = tempMiddle;
        tempMiddle = tempVar;
    }
    
    //reset array values
    Array[left] = tempLeft;
    Array[middle] = tempMiddle;
    Array[right] = tempRight;
    
    return middle;
    
}

int QS::partition(int left, int right, int pivotIndex)
{
    cout << "ran partition()" << endl;
    cout << "left: " << left << endl;
    cout << "pivot: " << pivotIndex << endl;
    cout << "right: " << right << endl;
    
    //catch invalid input
    if (Array == NULL || left >= right || arrayCapacity == 0)
        return -1;
    if (left > pivotIndex || right < pivotIndex)
        return -1;
    if (left < 0 || right > (arrayCapacity-1))
        return -1;
    //switch pivot with left index
    cout << "current array: " << endl;
    for (int i = 0; i < arrayCapacity; i++)
    {
        cout << Array[i] << ",";
    }
    cout << endl;
    
    //through pivot to left position
    int tempPivot = Array[pivotIndex];
    Array[pivotIndex] = Array[right];
    Array[right] = tempPivot;
    
    
    int i = left;
    int j = right-1;
    int tempVar;
    //while i is still less than or equal to j
    while (i < j)
    {
        //run while i value is less than pivot
        while (i <= (right-1) && Array[i] <= Array[right])
        {
            i++;
            cout << "index [i]: " << i << ", value: " << Array[i] << endl;
        }
        //run while j value is greater than pivot
        while (j >= left && Array[j] > Array[right])
        {
            j--;
            cout << "index [j]: " << j << ", value: " << Array[j] << endl;
        }
        //if i is still on left of j
        if (i < j)
        {
            cout << "switched!" << endl;
            tempVar = Array[i];
            Array[i] = Array[j];
            Array[j] = tempVar;
            cout << "current array: " << endl;
            for (int i = 0; i < arrayCapacity; i++)
            {
                cout << Array[i] << ",";
            }
            //cout << endl;
            //cout << "index [i]: " << i << ", value: " << Array[i] << endl;
            //cout << "index [j]: " << j << ", value: " << Array[j] << endl;
        }
    }
    
    //return pivot to original position if i passed j
    cout << "switched back" << endl;
    tempPivot = Array[right];
    Array[right] = Array[i];
    Array[i] = tempPivot;
    
    return i;
}

string QS::getArray()
{
    //cout << "ran getArray()" << endl;
    
    if (arrayCapacity == 0)
        return "";
    
    string output;
    for (int i = 0; i < position; i++)
    {
        stringstream ss;
        ss << Array[i];
        if (i != (position-1))
        {
            output = output + ss.str() + ",";
        }
        else
            output += ss.str();
    }
    
    return output;
}

int QS::getSize()
{
    //cout << "ran getSize()" << endl;

    return arrayCapacity;
}

void QS::addToArray(int value)
{
    //cout << "ran addToArray()" << endl;
    
    if (arrayCapacity != position && Array != NULL)
    {
        Array[position] = value;
        position++;
    }
}

bool QS::createArray(int capacity)
{
    //cout << "ran createArray()" << endl;
    
    if (capacity <= 0)
        return false;
    
    Array = new int[capacity];
    arrayCapacity = capacity;
    
    return true;
}

void QS::clear()
{
    //cout << "ran clear()" << endl;
    
    delete [] Array;
    Array = NULL;
    position = 0;
    arrayCapacity = 0;
}
int QS::lowestOfTwo(int first, int second)
{
    if (first < second)
        return first;
    else
        return second;
}
void QS::sort(int left, int right)
{
    cout << "called sort()" << endl;
    if (left == right)
        return;
    else if (right - left < 3)
        medianOfThree(left, right);
    else if (right-left >= 3)
    {
        int p = medianOfThree(left, right);
        cout << "pivot index: " << p << endl;
        p = partition(left, right, p);
        sort(left, p-1);
        sort(p+1, right);
    }
}


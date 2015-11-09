/* 
 * File:   Vect.h
 * Author: Himkw_000
 *
 * Created on September 16, 2015, 4:36 PM
 */

// Vect class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;


class Vect
{
private:
   int *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int allocateSize;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   Vect();
      
   // Constructor declaration
   Vect(int);
   
   // Copy constructor declaration
   Vect(const Vect &);
   
   // Destructor declaration
   ~Vect();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   //push
   void append(int);
   //pull
   void pop_back();
   
   // Accessor to return a specific element
   int getElementAt(int position);

   // Overloaded [] operator declaration
   int &operator[](const int &);
};

//***********************************************************
// Constructor for Vect class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

Vect::Vect(){
//  cout<<"default constructor";
  aptr = 0; arraySize = 0;allocateSize=0;
}


Vect::Vect(int s)
{
//  cout<<"int Constructor\n";
   arraySize = s;
   allocateSize = s;
   // Allocate memory for the array.
   try{
      aptr = new int [s];
   }
   catch (bad_alloc){
      memError();
   }
   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for Vect class. *
//*******************************************


Vect::Vect(const Vect &obj)
{
//  cout<<"Vector constructor\n";
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new int [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for Vect class.  *
//**************************************


Vect::~Vect()
{
   if (allocateSize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************


void Vect::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************


void Vect::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

void Vect::append(int a){
  arraySize+=1;
  //double the size and copy all the value
  if(arraySize>allocateSize){
    if(allocateSize==0)allocateSize=1;
    allocateSize*=2;
    int *temp = new int[allocateSize];
    for(int i=0;i<arraySize-1;i++){
      temp[i]=aptr[i];
    }
    temp[arraySize-1]=a;
    arraySize-1==0?delete aptr:delete[] aptr;
    aptr=temp;
  }
  else{
    aptr[arraySize-1]=a;
  }
//  cout<<"arraySize = "<<arraySize<<endl;
//  cout<<"allocate size = "<<allocateSize<<endl;
}

void Vect::pop_back(){
  if(arraySize>0)
    arraySize-=1;
  else
    cout<<"arraySize = 0\n";
}
//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************


int Vect::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************


int &Vect::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
//      subError();
     cout<<"error\n";
   return aptr[sub];
}
#endif
/**
 *
 * @brief  Test harness for single linked list_back operations
 * @file   test_back.cpp
 * @author onyettr
 *
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include "list.h"

using namespace std;

/*
******************************************************************************
Private Constants
******************************************************************************
*/

/*
******************************************************************************
Private Types
******************************************************************************
*/

/*
******************************************************************************
Private variables (static)
******************************************************************************
*/

/*
******************************************************************************
Private Macros
******************************************************************************
*/

/*
******************************************************************************
Global variables
******************************************************************************
*/

/*
******************************************************************************
Exported Global variables
******************************************************************************
*/

/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

int test_back (void)
{
  // Sign on
  cout << "Linked List Class Test - back" << endl; 

  /*
   * create a new list
   */ 
  linked_list addTest;
  
  /*
   * Add an element
   */
  cout << "Test01 - return Tail, no list elements" << endl;
  cout << "Return (  0) = " << addTest.list_back() << endl;

  cout << "Test02 - return Tail, list has one elenment" << endl;  
  addTest.list_add_element(201);
  cout << "Return (201) = " << addTest.list_back() << endl;  

  cout << "Test03 - return back, list has two elements" << endl;  
  addTest.list_add_element(301);
  cout << "Return (301) = " << addTest.list_front() << endl;  

#if 0
  cout << "Test04 - return front, list has new front element" << endl;  
  addTest.list_add_at_back(111);
  cout << "Return (111) = " << addTest.list_front() << endl;  
#endif

  addTest.list_dump(addTest.GetListHead());
  
  return 0;
}

//
// Fin
//
  

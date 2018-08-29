/**
 *
 * @brief  Test harness for single linked list add operations
 * @file   test_front.cpp
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

int test_front (void)
{
  // Sign on
  cout << "Linked List Class Test - front" << endl; 

  /*
   * create a new list
   */ 
  linked_list addTest;
  
  /*
   * Add an element
   */
  cout << "Test01 - return front, no list elements" << endl;
  cout << "Return (  0) = " << addTest.list_front() << endl;

  cout << "Test02 - return front, list has one elenment" << endl;  
  addTest.list_add_element(200);
  cout << "Return (200) = " << addTest.list_front() << endl;  

  cout << "Test03 - return front, list has two elements" << endl;  
  addTest.list_add_at_front(111);
  cout << "Return (200) = " << addTest.list_front() << endl;  

  cout << "Test04 - return front, list has new front element" << endl;  
  addTest.list_add_at_front(111);
  cout << "Return (111) = " << addTest.list_front() << endl;  
  
  return 0;
}

//
// Fin
//
  
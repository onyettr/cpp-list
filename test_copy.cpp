/**
 * @brief Test harness for single linked list copy operations
 * @file test_copy.cpp
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

int test_copy( void )
{
  // Sign on
  cout << "**** Linked List Class Test - copy" << endl; 

  /*
   * create a new list
   */ 
  linked_list srcCopyTest;
  linked_list dstCopyTest;
  
  srcCopyTest.list_add_element(100);
  srcCopyTest.list_add_element(101);
  srcCopyTest.list_add_element(102);
  srcCopyTest.list_add_element(103);
  srcCopyTest.list_add_element(104);      

  cout << "\tTest01 - src list copy, size  " << srcCopyTest.list_size()  << endl;
  srcCopyTest.list_dump();
  //  linked_list dstCopyTest = srcCopyTest;
  dstCopyTest = srcCopyTest;  
  cout << "\tTest02 - dst list copy, size  " << dstCopyTest.list_size()  << endl;
  dstCopyTest.list_dump();    
  cout << "**** Linked List Class Test - copy Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

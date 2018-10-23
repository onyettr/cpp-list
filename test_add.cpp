/**
 * @brief  Test harness for single linked list add operations
 * @file   test_add.cpp
 * @author onyettr
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

int test_add ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - add" << endl; 

  /*
   * create a new list
   */ 
  linked_list addTest;
  linked_list emplaceTest;
    
  /*
   * Add an element
   */
  cout << "\tTest01a - add single element" << endl;
  addTest.list_add_element(10);
  addTest.list_dump();  

  cout << "\tTest01b - add more   elements" << endl;  
  addTest.list_add_element(20);
  addTest.list_add_element(30);
  addTest.list_add_element(40);
  addTest.list_add_element(50);
  addTest.list_add_element(60);  
  addTest.list_dump();
  cout << "\tTest01b - size of list " << addTest.list_size() << endl;  

  cout << "\tTest02a - add to front" << endl;  
  addTest.list_add_at_front(111);
  addTest.list_dump();
  cout << "\tTest02a - size of list " << addTest.list_size() << endl;

  cout << "\tTest03a - add to back" << endl;  
  addTest.list_add_at_back(222);
  addTest.list_dump();
  cout << "\tTest03a - size of list " << addTest.list_size() << endl;

  cout << "\tTest04a - emplace" << endl;  
  emplaceTest.list_add_element(1);
  emplaceTest.list_add_element(2);
  emplaceTest.list_add_element(3);
  emplaceTest.list_add_element(4);  
  emplaceTest.list_dump();
  cout << "\tTest04a - size of list 4 = " << emplaceTest.list_size() << endl;

  cout << "\tTest05a - emplace at position 2" << endl;    
  emplaceTest.list_add_position(2, 5);
  emplaceTest.list_dump();  
  cout << "\tTest05a - size of list " << emplaceTest.list_size() << endl;

  cout << "\tTest05b get at position 2 (5) " << emplaceTest.list_get_position(2) << endl;
  
  cout << "**** Linked List Class Test - add Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

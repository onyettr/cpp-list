/**
 *
 * @brief  Test harness for single linked list add operations
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

int test_add ( void )
{
  // Sign on
  cout << "Linked List Class Test - add" << endl; 

  /*
   * create a new list
   */ 
  linked_list addTest;
  linked_list emplaceTest;
    
  /*
   * Add an element
   */
  cout << "Test01 - add single element" << endl;
  addTest.list_add_element(10);
  addTest.list_dump(addTest.GetListHead());  

  cout << "Test01 - add more   elements" << endl;  
  addTest.list_add_element(20);
  addTest.list_add_element(30);
  addTest.list_add_element(40);
  addTest.list_add_element(50);
  addTest.list_add_element(60);  
  addTest.list_dump(addTest.GetListHead());
  cout << "Test01a - size of list " << addTest.list_size() << endl;  

  cout << "Test02 - add to front" << endl;  
  addTest.list_add_at_front(111);
  addTest.list_dump(addTest.GetListHead());
  cout << "Test02a - size of list " << addTest.list_size() << endl;

  cout << "Test03 - add to back" << endl;  
  addTest.list_add_at_back(222);
  addTest.list_dump(addTest.GetListHead());
  cout << "Test03a - size of list " << addTest.list_size() << endl;

  cout << "Test04 - emplace" << endl;  
  emplaceTest.list_add_element(1);
  emplaceTest.list_add_element(2);
  emplaceTest.list_add_element(3);
  emplaceTest.list_add_element(4);  
  emplaceTest.list_dump(emplaceTest.GetListHead());
  cout << "Test04a - size of list " << emplaceTest.list_size() << endl;

  emplaceTest.list_emplace(2, 5);
  emplaceTest.list_dump(emplaceTest.GetListHead());  
  cout << "Test04a - size of list " << emplaceTest.list_size() << endl;
  
  return 0;
}

//
// Fin
//
  

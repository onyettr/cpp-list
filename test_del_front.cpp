/**
 * @brief Test harness for single linked list delete front operation
 * @file test_del_front.cpp
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

int test_del_front ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - deletion front" << endl; 

  /*
   * create a new list
   */ 
  linked_list delTest;
  
  /*
   * Add an element
   */
  delTest.list_add_element(202);
  delTest.list_add_element(203);
  delTest.list_add_element(204);
  delTest.list_add_element(205);    
  cout << "\tNumber in list before deletion = " << delTest.list_size() << endl;  
  delTest.list_dump();

  cout << "\tTest01 - delete front element" << endl;
  delTest.list_delete_front();
  cout << "\tNumber in list after deletion at 1  = " << delTest.list_size() << endl;    
  delTest.list_dump();

  cout << "\tTest02 - delete front element, exception to be thrown - empty list" << endl;
  linked_list delTest02;
  try {
    delTest02.list_delete_front();    
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  cout << "**** Linked List Class Test - deletion front Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

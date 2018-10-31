/**
 * @brief Test harness for single linked list delete back operation
 * @file test_del_back.cpp
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

int test_del_back ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - deletion back" << endl; 

  /*
   * create a new list
   */ 
  linked_list delTest;
  
  /*
   * Add an element
   */
  delTest.list_add_element(101);
  delTest.list_add_element(102);
  delTest.list_add_element(103);

  cout << "\tTest01 - delete back element" << endl;
  cout << "\tNumber in list before deletion = " << delTest.list_size() << endl;  
  delTest.list_dump();
  
  delTest.list_delete_back();
  cout << "\tNumber in list after back deletion = " << delTest.list_size() << endl;    
  delTest.list_dump();
  cout << "\tLast number (102) = " << delTest.list_get_back() << endl;
    
  cout << "\tTest01c - del back element, one element" << endl;
  linked_list delTest2;
  delTest2.list_add_element(200);

  delTest2.list_dump();
  delTest2.list_delete_back();
  cout << "\tNumber in list after back deletion = " << delTest2.list_size() << endl;      
  //  cout << "\tReturn (0) = " << delTest2.list_get_back() << endl;
  delTest2.list_dump();
  
  cout << "\tTest03 - delete back element, exception to be thrown - empty list" << endl;
  linked_list delTest3;
  try {
    delTest3.list_delete_back();    
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  cout << "**** Linked List Class Test - deletion back Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

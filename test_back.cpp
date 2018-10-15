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
  cout << "**** Linked List Class Test - back" << endl; 

  /*
   * create a new list
   */ 
  linked_list addTest;
  
  /*
   * Add an element
   */
  cout << "\tTest01 - return Tail, no list elements" << endl;
  try {
  cout << "\tReturn (  0) = " << addTest.list_get_back() << endl;
  } catch(std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  cout << "\tTest02 - return Tail, list has one elenment" << endl;  
  addTest.list_add_element(201);
  cout << "\tReturn (201) = " << addTest.list_get_back() << endl;  

  cout << "\tTest03 - return back, list has two elements" << endl;  
  addTest.list_add_element(301);
  cout << "\tReturn (301) = " << addTest.list_get_back() << endl;  

  cout << "\tTest04 - return back, list has new back element" << endl;  
  addTest.list_add_at_back(111);
  cout << "\tReturn (111) = " << addTest.list_get_back() << endl;  

  addTest.list_dump();

  cout << "**** Linked List Class Test - back Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

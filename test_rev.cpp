/**
 * @brief Test harness for single linked list reverse
 * @file test_rev.cpp
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

int test_rev ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - list reverse" << endl; 

  linked_list revTest1;
  linked_list revTest2;
  linked_list revTest3;  

  /*
   * Test01 - single element
   */
  cout << "\tTest01 - rev single element" << endl;
  revTest1.list_add_element(1);
  revTest1.list_reverse();  
  revTest1.list_dump();

  /*
   * Test02 - mulitple elements
   */
  cout << "\tTest02 - rev multiple element" << endl;  
  revTest2.list_add_element(1);
  revTest2.list_add_element(2);
  revTest2.list_add_element(3);
  revTest2.list_add_element(4);
  revTest2.list_add_element(5);      
  cout << "\tNumber in list before reverse = " << revTest2.list_size() << endl;  
  revTest2.list_dump();
  revTest2.list_reverse();  
  revTest2.list_dump();

  /*
   * Test03 - no elements
   */
  cout << "\tTest03 - rev zero element, exception to be thrown" << endl;    
  try {
    revTest3.list_reverse();
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  cout << "**** Linked List Class Test - reverse Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

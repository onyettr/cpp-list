/**
 * @brief Test harness for single linked list search
 * @file test_search.cpp
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

int test_search ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - list search" << endl; 

  linked_list searchTest1;
  linked_list serTest2;
  linked_list serTest3;
  
  /*
   * Test01a - single element, positive find
   */
  cout << "\tTest01a - Search single element positive " << endl;
  searchTest1.list_add_element(101);
  cout << "\tFound match at Position 0 = " << searchTest1.list_search(101) << endl;

  /*
   * Test01b - single element, negative find
   */
  cout << "\tTest01b - Search single element" << endl;
  cout << "\tNo Found match at Position -1 = " << searchTest1.list_search(102) << endl;

  /*
   * Test02 - mulitple elements, positive find
   */
  cout << "\tTest02a - Search multiple element positive " << endl;
  serTest2.list_add_element(1);
  serTest2.list_add_element(2);
  serTest2.list_add_element(3);
  serTest2.list_add_element(4);
  serTest2.list_add_element(5);      
  cout << "\tFound match at Position 3 = " << serTest2.list_search(4) << endl;

  /*
   * Test02 - mulitple elements, negative find
   */
  cout << "\tTest02b - Search multiple element negative " << endl;
  cout << "\tNo Found match at Position -1 = " << serTest2.list_search(404) << endl;  
  
  /*
   * Test03 - no elements
   */
  cout << "\tTest03 - search zero element, exception to be thrown" << endl;    
  try {
    serTest3.list_search(101);
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
  

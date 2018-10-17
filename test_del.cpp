/**
 *
 * @brief Test harness for single linked list delete operation
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

int test_del ( void )
{
  // Sign on
  cout << "**** Linked List Class Test - deletion" << endl; 

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

  cout << "\tTest01 - del single element" << endl;
  delTest.list_delete_element(1);
  cout << "\tNumber in list after deletion at 1  = " << delTest.list_size() << endl;    
  delTest.list_dump();

  cout << "\tTest02 - del first element" << endl;  
  delTest.list_delete_element(0);
  cout << "\tNumber in list after deletion at 0 = " << delTest.list_size() << endl;    
  delTest.list_dump();

  cout << "\tTest03 - del illegal element, exception to be thrown" << endl;    
  try {
    delTest.list_delete_element(delTest.list_size()+1);    
  } catch (std::runtime_error& e) {
    cout << "Exception: " << e.what() << endl;
  } catch(...) {
    cout << "Exception: ouch something bad went on = " << endl;
  }

  cout << "**** Linked List Class Test - deletion Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

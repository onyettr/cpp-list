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
  cout << "\tTest01 - del single element" << endl;
  delTest.list_add_element(202);
  cout << "\tNumber in list before deletion = " << delTest.list_size() << endl;  
  delTest.list_dump();  
  delTest.list_delete_element(delTest.GetListHead()->pNext);
  cout << "\tNumber in list after deletion  = " << delTest.list_size() << endl;    
  delTest.list_dump();

  cout << "**** Linked List Class Test - deletion Ends" << endl;
  
  return 0;
}

//
// Fin
//
  

/**
 * @brief  main entry - invokes the test harness
 * @file   main.cpp
 * @author onyettr 
 * @version
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include "list.h"
#include "test.h"

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
extern void poortool_init(void);

/*
******************************************************************************
Prototypes of all functions contained in this file (in order of occurance)
******************************************************************************
*/

int main ( void )
{
  // Sign on
  cout << "C++ Examples Simple Linked List Class" << endl; 

  // Test Cases
#if 0  
  test_add();
  test_front();
  test_back();  
  test_del();
  test_size();
  test_empty();
#endif
  test_del_front();
  test_del_back();
  test_rev();
  test_copy();
  //  poortool_init();
}

//
// Fin
//
  

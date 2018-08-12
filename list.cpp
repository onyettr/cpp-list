/*
 *****************************************************************************
 * MODULE: C++ Programming Examples
 *
 * $Header: $
 * $Archive:$
 * 
 * $Workfile: $
 *
 * $Author: Onyettr $
 *
 * NAME: Richard Onyett 
 * EMAIL: 
 *
 * PURPOSE: Simple Stack Class implementation
 *
 * 
 * $Revision:$
 * $History: $
 ***************************************************************************** 
 */

/*
******************************************************************************
Includes
******************************************************************************
*/
#include <iostream>
#include <string.h>
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
// Constructor time
node::node(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  node_prev = NULL;
  node_next = NULL;
  node_count= 0;
}

// Destructor time
node::~node() {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called "  << endl;  
#endif
}

int node::getNodecount (void) {
  return node_count;
}

int node::setNodecount (int count) {
  node_count = count;
}

void node::list_add_element ( list_element_t *lp) {
  int count = 0;
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_element called "  << endl;  
#endif
  count = getNodecount();
  count = count + 1;
  setNodecount(count);
}

void node::list_dump        ( node *pHead ) {
  if ( pHead != NULL ) {
    cout << "Number of nodes = " << getNodecount() << endl;
    for (int i=0; i < 10; i++) {
      cout << "Node: " << i << " Data " << endl;
    }
  }
  else {
    cout << "Error: No node head found" << endl;
  }
}


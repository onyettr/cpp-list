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

/**
 * @function  node::node
 *
 * @brief     node ctor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      ctor
 */
node::node(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  node_prev = NULL;
  node_next = NULL;
  node_count= 0;
}

/**
 * @function  node::~node
 *
 * @brief     node dtor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      dtor
 */
node::~node() {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called "  << endl;  
#endif
}

/**
 * @function  node::getNodeCount
 *
 * @brief     get the number of nodes created
 *
 * @param[in] none
 *
 * @return    int     number of created nodes
 *
 * @note
 */
int node::getNodecount (void) {
  return node_count;
}

/**
 * @function  node::setNodeCount
 *
 * @brief     Set the number of nodes to create
 *
 * @param[in] None
 *
 * @return    int
 *
 * @note
 */
void node::setNodecount (int count) {
  node_count = count;
}

/**
 * @function  void node::list_add_element(list_element_t *lp)
 *
 * @brief     Add a new list element
 *
 * @param[in] list_element_t *lp    Pointer to new list element
 *
 * @return    none
 *
 * @note
 */
void node::list_add_element (list_element_t *lp) {
  int count = 0;
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_element called "  << endl;  
#endif
  count = getNodecount();
  count = count + 1;
  setNodecount(count);
}

/**
 * @function  void node::list_dump(node *pHead)
 *
 * @brief     Dump a given list
 *
 * @param[in] node *pHead    Pointer to head of the given list
 *
 * @return    none
 *
 * @note
 */
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


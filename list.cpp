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
 * PURPOSE: Simple C++ linked list implementation
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

/**
 * @function  linked_list::linked_list(void) {
 *
 * @brief     linked_list constructor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      ctor
 */
linked_list::linked_list(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  pHead = NULL;
  pTail = NULL;
  list_count= 0;
}

/**
 * @function  linked_list::~linked_list() {
 *
 * @brief     linked_list destructor
 *
 * @param[in] none
 *
 * @return    None
 *
 * @note      dtor
 */
linked_list::~linked_list() {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Destructor called "  << endl;  
#endif
  list_element_t *pNext;

  pNext = GetListHead();
  while (pNext) {
    list_element_t *pNodeToDelete;

    pNodeToDelete = pNext;
    pNext = pNext->pNext;
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: deleting "  << pNodeToDelete << endl;  
#endif
    
    delete pNodeToDelete;
    list_count--;
  }
}

/**
 * @function  void node::list_add_element(int value)
 *
 * @brief     Add a new list element
 *
 * @param[in] int   element to add
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_add_element (int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_element called "  << endl;  
#endif
  list_element_t *Temp;

  /*
   * Create a new element for the list
   */
  Temp = new list_element_t;
  Temp->element = value;
  Temp->pNext = NULL;

  cout << "<" << this << ">TRACE: list_add_element Created new " << Temp << endl;
  
  if (pHead == NULL) {
    /*
     * We are the first
     */
    pHead = Temp;
    pTail = Temp;
  } else {
    pTail->pNext = Temp;
    pTail = pTail->pNext;
  }
  list_count++;
  
  cout << "<" << this << ">TRACE: list_add_element Head " << pHead << endl;  
  cout << "<" << this << ">TRACE: list_add_element Tail " << pTail << endl;
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
void linked_list::list_add_at_front (int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_to_front called "  << endl;  
#endif
  list_element_t *Temp;

  /*
   * Create a new element for the list
   */
  Temp = new list_element_t;
  Temp->element = value;
  Temp->pNext = pHead;            /* This element now points to the head */
  pHead = Temp;                   /* This moves the head to point to the new element, making it at the front */
  
  cout << "<" << this << ">TRACE: list_add_to_front Created new " << Temp << endl;

  list_count++;
  
  cout << "<" << this << ">TRACE: list_add_to_front Head " << pHead << endl;  
  cout << "<" << this << ">TRACE: list_add_to_front Tail " << pTail << endl;
}

/**
 * @function  void node::list_delete_element(list_element_t *lp)
 *
 * @brief     Remove a list element
 *
 * @param[in] list_element_t *lp    Pointer to list element to delete
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_delete_element (list_element_t *pElement) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_delete_element called "  << endl;  
#endif

  list_count--;
  
  cout << "<" << this << ">TRACE: list_delete_element Head " << pHead << endl;  
  cout << "<" << this << ">TRACE: list_delete_element Tail " << pTail << endl;
}

/**
 * @function  void node::list_sort(list_element_t *lp)
 *
 * @brief     Sort the list
 *
 * @param[in] list_element_t *lp    Pointer to new list element
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_sort (list_element_t *pHead) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_sort called "  << endl;  
#endif
  
}

/**
 * @function  int list::list_size(void)
 *
 * @brief     return the size of the list
 *
 * @param[in] none
 *
 * @return    Size of the list
 *
 * @note
 */
int linked_list::list_size (void) {
#if defined ( DEBUG_TRACE_1 )
  cout << "<" << this << ">TRACE: list_size called "  << endl;  
#endif

  return list_count;
}

/**
 * @function  bool list::list_empty(void)
 *
 * @brief     Is the list empty?
 *
 * @param[in] none
 *
 * @return    bool TRUE = Empty, FALSE = Not empty
 *
 * @note
 */
bool linked_list::list_empty (void) {
#if defined ( DEBUG_TRACE_1 )
  cout << "<" << this << ">TRACE: list_empty called "  << endl;  
#endif

  if (list_count == 0) {
    return true;
  }
  return false;
}

/**
 * @function  void linked_list::list_dump        (void) {
 *
 * @brief     Print out the linked list
 *
 * @param[in] none
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_dump (list_element_t *listHead) {
  list_element_t *pCurrent;
  
  if ( listHead != NULL ) {
    cout << "Number of nodes = " << list_count << endl;

    pCurrent = listHead;
    while (pCurrent != NULL) {
      cout << "[" << pCurrent << "] ";
      cout << pCurrent->element << endl;

      pCurrent = pCurrent->pNext;
    }
  }
  else {
    cout << "Error: No elements in linked list" << endl;
  }
}

#if 0
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

#endif

/**
 * MODULE: C++ Programming Examples
 *
 * @brief  Simple C++ linked list implementation
 * @author onyettr 
 * @file   list.cpp
 * @version
 *
 *  List_element_t           list_element_t       list_element_t
 *    pHead    ------------>   element             element
 *    pTail    ------------|   pNext ------------> pNext ---> NULL
 *                         |                         ^
 *    list_count=2         |                         |
 *                         ---------------------------
 *
 * List Methods
 * list_add_element (int value);       Add an element to the list, increases list size by 1
 * list_add_at_front(int value);       Add an element to the front of the list, increases list size by 1
 * list_add_at_back (int value);       Add an element to the back  of the list, increases list size by 1
 * list_add_position(int position, int value); Add an element at position,increases list size by 1
 * list_get_position(int position);    return value at "position"
 * list_get_front   (void);            return value of first list element
 * list_get_back    (void);            return value of tail list element
 * list_delete_element(int position);  Delete element  at position, decreases list size by 1
 * list_delete_front(void);            Delete first element of list, decreases list size by 1  
 * list_sort        (void);            Sort the list
 * list_dump        (void);            Show the contents of the linked list
 * list_size        (void);            Number of elements in the list
 * list_empty       (void);            is the list empty?
 * GetListHead(void)                   Obtain Head iterator pointing to first element
 * GetListTail(void)                   Obtain Tail iterator pointing to last element
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
 * @fn        linked_list::linked_list(void)
 *
 * @brief     linked_list constructor
 *
 * @param     
 *
 * @return    none
 *
 * @note      constructor
 */
linked_list::linked_list(void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Constructor called"  << endl;  
#endif

  pHead = nullptr;
  pTail = nullptr;
  list_count= 0;
}

/**
 * @fn        linked_list::linked_list(const linked_list& srcCopyList) {
 *
 * @brief     Copy constructor
 *
 * @param     srcCopyList - List to copy
 *
 * @return    none
 *
 * @note      copy constructor
 */
linked_list::linked_list(const linked_list& srcCopyList) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: Basic Copy Constructor called"  << endl;  
#endif
  int ListItems;
  list_element_t *pSrcList = srcCopyList.pHead;
  
  this->pHead = nullptr;
  this->pTail = nullptr;

  ListItems = srcCopyList.list_count;
  for (auto i=0; i  < ListItems; i++) {
#if defined (DEBUG_TRACE)    
     cout << "<" << this << ">TRACE: Basic Copy Constructor add "  << pSrcList->element << endl;
#endif
     list_add_element(pSrcList->element);
     pSrcList = pSrcList->pNext;
  }
  
  this->list_count = srcCopyList.list_count;
}

/**
 * @fn        linked_list::~linked_list()
 *
 * @brief     linked_list destructor
 *
 * @param[in] 
 *
 * @return    None
 *
 * @note      dtor
 */
linked_list::~linked_list(void) {
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
 * @fn        void linked_list::list_add_element(int value)
 *
 * @brief     Add a new list element
 *
 * @param[in] value  -  element to add
 *
 * @return    none
 *
 * @throw     none
 *
 * @note      This creates a new linked_list element and adds to the TAIL of the list
 */
void linked_list::list_add_element (int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_add_element called "  << endl;  
#endif
  list_element_t *Temp;

  /*
   * Create a new element for the list
   */
  try {
    Temp = new list_element_t;
  }
  catch (std::bad_alloc& exp) {
    std::cerr << "Dynamic memory allocation failed!" << exp.what();

    return;
  }
    
  Temp->element = value;
  Temp->pNext = nullptr;

#if defined (DEBUG_TRACE)
  cout << "<" << this << ">TRACE: list_add_element Created new " << Temp << endl;
#endif
  
  if (pHead == nullptr) {
    /*
     * We are the first
     */
    pHead = Temp;
    pTail = Temp;
  } else {
    pTail->pNext = Temp;
    pTail = pTail->pNext;
  }
  list_count++;        /* Increment the number of items in the list */
#if defined (DEBUG_TRACE)  
  cout << "<" << this << ">TRACE: list_add_element Head " << pHead << endl;  
  cout << "<" << this << ">TRACE: list_add_element Tail " << pTail << endl;
#endif
}

/**
 * @fn        void linked_list::list_add_position(int position, int value)
 *
 * @brief     Add a new list element at Position in the list
 *
 * @param[in] position   Place to insert the new element
 * @param[in] value      element 
 *
 * @return    none
 *
 * @note      This will insert at Position. 
 */
void linked_list::list_add_position(int position, int value) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_emplace called "  << endl;  
#endif
  list_element_t *Temp;
  list_element_t *pCurrent;
  list_element_t *pPrevious;
  
  /*
   * Create a new element for the list
   */
  Temp = new list_element_t;
  Temp->element = value;
  Temp->pNext = nullptr;
#if defined (DEBUG_TRACE)
  cout << "<" << this << ">TRACE: list_emplace Created new " << Temp << endl;
#endif
  
  pCurrent = pHead;  /* Start of the list */
  /*
   * Traverse the list until we get to position
   */
  for (int i=1; i < position; i++) {
     pPrevious = pCurrent;
     pCurrent = pCurrent->pNext;
  }

  /* Now we are at Position, lets insert the new node */
  pPrevious->pNext = Temp;
  Temp->pNext      = pCurrent;
  
  list_count++;
}

/**
 * @fn        void linked_list::list_add_at_front(int value)
 *
 * @brief     Add a new list value to the front of the list
 *
 * @param[in] value - Element to add at the front
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_add_at_front(int value) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_front called "  << endl;  
#endif
    list_element_t *Temp;

    /*
     * Create a new element for the list
     */
    try {
        Temp = new list_element_t;
    }
    catch (std::bad_alloc& exp) {
       std::cerr << "Dynamic memory allocation failed!" << exp.what();

       return;
    }

    Temp->element = value;
    Temp->pNext = pHead;            /* This element now points to the head */
    pHead = Temp;                   /* This moves the head to point to the new element, making it at the front */

    list_count++;                   /* increment the number in the list    */
  
#if defined (DEBUG_TRACE)
    cout << "<" << this << ">TRACE: list_add_to_front Created new " << Temp << endl;
    cout << "<" << this << ">TRACE: list_add_to_front Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Tail " << pTail << endl;
#endif
}

/**
 * @fn        void linked_list::list_add_at_back(int value)
 *
 * @brief     Add a new list value to the back of the list
 *
 * @param[in] value  - Element to add at the back
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_add_at_back(int value) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_back called "  << endl;  
#endif
    list_element_t *Temp;

    /*
     * Create a new element for the list
     */
    try {
       Temp = new list_element_t;
    }
    catch (std::bad_alloc& exp)
    {
       std::cerr << "Dynamic memory allocation failed!" << exp.what();

       return;
    }

    Temp->element = value;
    Temp->pNext = nullptr;          /* This element points at nothing as its now at the back                  */
    pTail->pNext = Temp;            /* Make the current last element point to the new Tail                    */
    pTail = Temp;                   /* This moves the Tail to point to the new element, making it at the back */
  
    list_count++;
    
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_add_to_back Created new " << Temp << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_add_to_front Tail " << pTail << endl;
#endif    
}

/**
 * @fn        void linked_list::list_delete_element(int position)
 *
 * @brief     Remove a list element
 *
 * @param[in] position - Element Position to remove
 *
 * @return    none
 * @details   Special case test is done for first (or zero) element as this is pointed
 *            to by pHead, which we must update
 * @throws    std::runtime_error
 * @note
 */
void linked_list::list_delete_element (int position) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_delete_element " << position << " called "  << endl;  
#endif
    list_element_t *pCurrent;
    list_element_t *pPrevious;

    /*
     * Test if the position element is legal
     */
    if (position > list_size()) {
      throw std::runtime_error("linked_list::list_delete_element - position beyond list_size");

      return;
    }
      
    /*
     * Test for first element (requires the HEAD to be updated) otherwise
     * scan the list for the "position" to delete
     */
    pCurrent = GetListHead();

    if (position == 0) {                     /* First in the list */
       pHead = pCurrent->pNext;              /* Update the Head pointer as position zero is deleted */
       pCurrent->pNext = nullptr;
    } else {
      for (auto i=0; i < position; i++) {
         pPrevious = pCurrent;
         pCurrent = pCurrent->pNext;
      }
      pPrevious->pNext = pCurrent->pNext;    /* Previous entry is now pointing to one beyond the deleted entry */      
    }
#if defined (DEBUG_TRACE)
    cout << "deleting    " << pCurrent;
#endif    
    delete [] pCurrent;                      /* Delete the entry at position */

    list_count--;

#if defined ( DEBUG_TRACE )  
    cout << "<" << this << ">TRACE: list_delete_element Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_delete_element Tail " << pTail << endl;
#endif  
}

/**
 * @fn        void linked_list::list_delete_front(void)
 *
 * @brief     Remove a list element from the fromt of the list
 *
 * @param[in] 
 *
 * @return    none
 * @details   

 * @throws    std::runtime_error - list empty
 * @note
 */
void linked_list::list_delete_front (void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_delete_front called "  << endl;  
#endif
    list_element_t *pCurrent;

    /*
     * List is empty?
     */
    if (list_size() == 0) {
      throw std::runtime_error("linked_list::list_delete_front - list is empty");

      return;
    }
      
    pCurrent = GetListHead();

    pHead = pCurrent->pNext;              /* Update the Head pointer as position zero is deleted */
    pCurrent->pNext = nullptr;
#if defined (DEBUG_TRACE)
    cout << "deleting    " << pCurrent;
#endif    
    delete [] pCurrent;                      /* Delete the entry at position */

    list_count--;

#if defined ( DEBUG_TRACE )  
    cout << "<" << this << ">TRACE: list_delete_front Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_delete_front Tail " << pTail << endl;
#endif  
}

/**
 * @fn        void linked_list::list_delete_back(void)
 *
 * @brief     Remove a list element from the back (tail) of the list
 *
 * @param[in] 
 *
 * @return    none
 * @details   

 * @throws    std::runtime_error - list empty
 * @note
 */
void linked_list::list_delete_back (void) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_delete_back called "  << endl;  
#endif
    list_element_t *pCurrent;

    /*
     * List is empty?
     */
    if (list_size() == 0) {
      throw std::runtime_error("linked_list::list_delete_back - list is empty");

      return;
    }

    pCurrent = GetListHead();
    
    /*
     * test if we have only one element
     */
    if (list_size() == 1) {
      delete(pCurrent);
      pHead = nullptr;
      pTail = nullptr;
      list_count = 0;

      return;
    }

    /*
     * Scan from the Head of the list until we find the end
     * NOTE: we are looking beyond the next for the end
     */
    while( pCurrent->pNext->pNext != NULL ) {
      pCurrent = pCurrent->pNext;
    }

    /* pCurrent is now at the last (but one) element node */
    delete [] pCurrent->pNext;     /* Delete the last element */

    pCurrent->pNext = NULL;    /* Current is now the last */
    pTail = pCurrent;       /* Update the Tail to last */
    list_count--;            /* Decrement the nodeCount */
  
#if defined ( DEBUG_TRACE )
    cout << "deleting    " << pCurrent->pNext;    
    cout << "<" << this << ">TRACE: list_delete_back Head " << pHead << endl;  
    cout << "<" << this << ">TRACE: list_delete_back Tail " << pTail << endl;
#endif  
}

/**
 * @fn        void linked_list::list_sort(void)
 *
 * @brief     Sort the list
 *
 * @param     none
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_sort (void) {
#if defined ( DEBUG_TRACE )
   cout << "<" << this << ">TRACE: list_sort called "  << endl;  
#endif
}

/**
 * @fn        int linked_list::list_size(void)
 *
 * @brief     return the size of the list
 *
 * @param
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
 * @fn        bool linked_list::list_empty(void)
 *
 * @brief     Is the list empty?
 *
 * @param
 *
 * @return    bool TRUE = Empty, FALSE = Not empty
 *
 * @note
 */
bool linked_list::list_empty(void) {
#if defined ( DEBUG_TRACE_1 )
   cout << "<" << this << ">TRACE: list_empty called "  << endl;  
#endif

  if (list_count == 0) {
     return true;
  }

  return false;
}

/**
 * @fn        int linked_list::list_get_front(void)
 *
 * @brief     return front list value
 *
 * @param[in] void
 *
 * @return    Front list value
 *
 * @note
 */
int linked_list::list_get_front(void) {
   int value = 0;  
#if defined ( DEBUG_TRACE )
   cout << "<" << this << ">TRACE: list_get_front called "  << endl;  
#endif

   if (list_empty()) {
      throw std::runtime_error("linked_list::list_get_front - list is empty");
   }
   else {
      value = pHead->element;
   }

   return value;
}

/**
 * @fn        int linked_llist::list_get_back(void)
 *
 * @brief     return the back/tail list value
 *
 * @param[in] none
 *
 * @return    <T> (int)   back list value
 *
 * @note
 */
int linked_list::list_get_back(void) {
   int value = 0;  
#if defined ( DEBUG_TRACE )
   cout << "<" << this << ">TRACE: list_get_back called "  << endl;  
#endif

   if (list_count == 0) {
      throw std::runtime_error("linked_list::list_get_back - list is empty");    
   }
   else {
      value = pTail->element;
   }

   return value;
}

/**
 * @fn        void linked_list::list_get_position(int position)
 *
 * @brief     return value at Position
 *
 * @param[in] position -  Position of Element to return
 *
 * @return    int value
 *
 * @note      This will return value at Position. 
 */
int linked_list::list_get_position(int position) {
#if defined ( DEBUG_TRACE )
  cout << "<" << this << ">TRACE: list_get_position called "  << endl;  
#endif
  list_element_t *pCurrent;
  int value = 0;

  if (list_empty()) {
     throw std::runtime_error("linked_list::list_get_front - list is empty");
     return value;
  }

  /*
   * Traverse the list until we get to position
   */
  pCurrent = pHead;  /* Start of the list */
  for (int i=1; i < position; i++) {
     pCurrent = pCurrent->pNext;
  }

  /* Now we are at Position, lets insert the new node */
  value = pCurrent->element;

  return value;
}

/**
 * @fn        void linked_list::list_reverse(void) 
 *
 * @brief     reverse the single linked list
 *
 * @param     none
 *
 * @return    none
 * @throws    std::runtime_error - list empty
 * @note
 */
void linked_list::list_reverse (void) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_reverse called "  << endl;  
#endif
    list_element_t *pCurrent = nullptr;
    list_element_t *pNext    = nullptr;
    list_element_t *pPrevious= nullptr;

    /*
     * List is empty?
     */
    if (list_size() == 0) {
      throw std::runtime_error("linked_list::list_reverse - list is empty");

      return;
    }

    pCurrent = GetListHead();            /* Point at the start of the list */
    pTail = pHead;                       /* Swap the tail to point to head */
 cout << "pHead " << pHead << " pTail " << pTail << endl;
    while (pCurrent != NULL) {
      pNext = pCurrent->pNext;           /* Next element in the list       */
      pCurrent->pNext = pPrevious;       /* Current's 'next' is reversed   */
      pPrevious = pCurrent;
      pCurrent = pNext;                  /* Advance down the list          */
    }
    pHead = pPrevious;                   /* New head of the list           */
 cout << "pHead " << pHead << " pTail " << pTail << endl;    
}

/**
 * @fn        void linked_list::list_search(int value) 
 *
 * @brief     Search the single linked list
 *
 * @param     value - What to search for
 *
 * @return    int Position - place in the list
 * @throws    std::runtime_error - list empty
 * @note
 */
int linked_list::list_search (int value) {
#if defined ( DEBUG_TRACE )
    cout << "<" << this << ">TRACE: list_search called "  << endl;  
#endif
    list_element_t *pCurrent = nullptr;
    int Position = 0;
    
    /*
     * List is empty?
     */
    if (list_size() == 0) {
      throw std::runtime_error("linked_list::list_reverse - list is empty");

      return -1;
    }

    pCurrent = GetListHead();            /* Point at the start of the list */
    while (pCurrent != NULL) {
      if (pCurrent->element == value) {  /* We have a match                */
	return Position;
      }
      pCurrent = pCurrent->pNext;         /* Advance down the list         */
      ++Position;
    }

    return -1;                            /* We have no match              */
}

/**
 * @fn        void linked_list::list_dump(void) 
 *
 * @brief     Print out the single linked list
 *
 * @param     none
 *
 * @return    none
 *
 * @note
 */
void linked_list::list_dump (void) {
   list_element_t *pCurrent;
  
   if ( !list_empty() ) {
      int count = 0;

      pCurrent = GetListHead();

      cout << "      Address   \tValue\t   pNext\t# Nodes [" << list_count << "]" << endl;
      while (pCurrent != nullptr) {
 	 cout << count << "  [" << pCurrent << "]\t";
         cout << pCurrent->element << "\t[" << pCurrent->pNext << "]";
         if (pCurrent == GetListHead()) {
	   cout << "    <--- HEAD";
	 }
	 if (pCurrent == GetListTail()) {
	   cout << "\t         <--- TAIL";
	 }
         cout << endl;
	 
         pCurrent = pCurrent->pNext;
	 count++;
    }
  }
  else {
     cout << "Error: No elements in linked list" << endl;
  }
}

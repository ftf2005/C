//write a c progeam for linked list for insrting at the beginning , end and middle  of the list and deletion at the beginning , end and between of the list and searching element and display
#include <stdio.h>

#include <stdlib.h>

struct sllnode {

  int value;

  struct sllnode *next;

};

struct sllnode *sllstart = NULL;

struct sllnode *sllcreate() {

  struct sllnode *temp;

  temp = (struct sllnode *)malloc(sizeof(struct sllnode));

  temp->next=NULL;

  return temp;

}

void slldisplay_list() {

  struct sllnode *temp;

  if (sllstart == NULL) {

    printf("List is empty\n");

  }

  

  temp = sllstart;

  while (temp != NULL) {

    printf("%d -> ", temp->value);

    temp = temp->next;

  }

}

void sllinsert_start(int value) {

  struct sllnode *newNode;

  newNode = sllcreate();

  newNode->value = value;

  newNode->next = sllstart;

  sllstart = newNode;

  slldisplay_list();

}

void sllinsert_end(int value) {

  struct sllnode *newNode, *temp;

  newNode = sllcreate();

  newNode->value = value;

  newNode->next = NULL;

  if (sllstart == NULL) {

    sllstart = newNode;

  }

  temp = sllstart;

  while (temp->next != NULL) {

    temp = temp->next;

  }

  temp->next = newNode;

  slldisplay_list();

}

int slldelete_start() {

  struct sllnode*temp;

  if (sllstart == NULL) {

    printf("List is empty\n");

    return -1;

  }

  temp=sllstart;

  int value = sllstart->value;

  sllstart = sllstart->next;

  temp->next=NULL;

  free(temp);

  return value;

}

int slldelete_end() {

  struct sllnode *prev, *temp;

  temp = sllstart;

  if (sllstart == NULL) {

    printf("List is empty\n");

    return -1;

  }

  while (temp->next != NULL) {

    prev = temp;

    temp = temp->next;

  }

  int value = temp->value;

  prev->next = NULL;

  free(temp);

  return value;

}

void sllinsert_position(int value, int pos) {

  struct sllnode *newNode, *temp;

  int i;

  

  newNode = sllcreate();

  newNode->value = value;

  if (pos == 1) {

    sllinsert_start(value);

  }

  temp = sllstart;

  for (i=1; i<pos-1 && temp != NULL; i++) {

    temp = temp->next;

  }

  if (temp == NULL) {

    printf("Invalid position\n");

    return;

  }

  newNode->next = temp->next;

  temp->next = newNode;

  slldisplay_list();

}

// New functions

void sllinsert_before(int value, int newValue){

  struct sllnode *newNode, *temp;

  newNode = sllcreate();

  newNode->value = newValue;

  

  if(sllstart == NULL){

    printf("List is empty\n");

  }

  

  if(sllstart->value == value){

    newNode->next = sllstart;

    sllstart = newNode;

  }

  

  temp = sllstart;

  while(temp->next != NULL && temp->next->value != value){

    temp = temp->next;

  }

  

  if(temp->next == NULL){

    printf("%d not found in list\n", value);

    return;

  }

  

  newNode->next = temp->next;

  temp->next = newNode;

  slldisplay_list();

}

void sllinsert_after(int value, int newValue){

  struct sllnode *newNode, *temp;

  newNode = sllcreate();

  newNode->value = newValue;

  if(sllstart == NULL){

    printf("List is empty\n");

  }

  temp = sllstart;

  while(temp != NULL && temp->value != value){

    temp = temp->next;

  }

  if(temp == NULL){

    printf("%d not found in list\n", value);

    return;

  }

  newNode->next = temp->next;

  temp->next = newNode;

  

  slldisplay_list();

}

int slldelete_position(int pos){

  struct sllnode *temp, *prev;

  int deletedValue;

  if(sllstart == NULL){

    printf("List is empty\n");

    return -1;

  }

  if(pos == 1){

    deletedValue = sllstart->value;

    sllstart = sllstart->next;

    return deletedValue;

  }

  temp=sllstart;

  for(int i=1; i<pos && temp!=NULL; i++){

    prev = temp;

    temp = temp->next;

  }

  if(temp == NULL){

    printf("Position %d does not exist\n", pos);

    return -1;

  }

  deletedValue = temp->value;

  prev->next = temp->next;

  temp->next=NULL;

  free(temp);

  return deletedValue;

}

int slldelete_before(int value){

  struct sllnode *temp, *prev;

  int deletedValue;

  if(sllstart == NULL){

    printf("List is empty\n");

    return -999;

  }

  if(sllstart->value == value){

    printf("%d is first element. Cannot delete before it\n", value);

    return -999;

  }

  temp = sllstart;

  while(temp != NULL && temp->value != value){

    prev = temp;

    temp = temp->next;

  }

  if(temp == NULL){

    printf("%d not found in list\n", value);

    return -1;

  }

  deletedValue = prev->value;

  prev = sllstart;

  while(prev->next != temp){

    prev = prev->next;

  }

  prev->next = temp;

  return deletedValue;

}

int slldelete_after(int value){

  struct sllnode *temp, *prev;

  int deletedValue;

  if(sllstart == NULL){

    printf("List is empty\n");

    return -1; 

  }

  prev = sllstart;

  temp = sllstart->next;

  while(temp != NULL && prev->value != value){

    prev = temp;

    temp = temp->next;

  }

  if(temp == NULL){

    printf("%d not found in list\n", value);

    return -999;

  }

  deletedValue = temp->value;

  prev->next = temp->next;

  return deletedValue;

}

int sllsearch(int value){

  struct sllnode *temp = sllstart;

  int pos = 1;

  while(temp != NULL){

    if(temp->value == value){

      return pos;

    }

    pos++;

    temp = temp->next;

  }

  return -1; 

}

// ************************

struct dllnode {

  int data;

  struct dllnode *pre;

  struct dllnode *next;  

};

struct dllnode *dllstart = NULL;

struct dllnode *dllend = NULL;

struct dllnode *dllcreate() {

  struct dllnode *temp;

  temp = (struct dllnode *)malloc(sizeof(struct dllnode));

  if (temp == NULL) {

    printf("Memory allocation failed\n");

    exit(EXIT_FAILURE);

  }

  temp->pre = NULL;

  temp->next = NULL;

  return temp;

}

void dlldisplay() {

  struct dllnode *s = dllstart;

  if (s == NULL) {

    printf("List is empty\n");

    return;

  }

  while (s != NULL) {

    printf("%d -> ", s->data);

    s = s->next;

  }

  printf("\n");  

}

void dllinsert_start(int x) {

  struct dllnode *new_node, *s;

  new_node = dllcreate();

  new_node->data = x;

  if (dllstart == NULL) {

    dllstart = dllend = new_node;

  } else {

    new_node->next = dllstart;

    dllstart->pre = new_node;

    dllstart = new_node;

  }

  dlldisplay();

}

void dllinsert_mid(int x, int pos) {

  struct dllnode *new_node, *s;

  int c = 1;

  new_node = dllcreate();

  new_node->data = x;

  if (dllstart == NULL) {

    dllstart = dllend = new_node;

  } else {

    s = dllstart;

    while (c < pos - 1 && s != NULL) {

      s = s->next;

      c++;

    }

    if (s == NULL) {

      printf("Invalid position\n");

      return;

    }

    new_node->pre = s;

    new_node->next = s->next;

    if (s->next != NULL) {

      s->next->pre = new_node;

    }

    s->next = new_node;

  }

  dlldisplay();

}

void dllinsert_mid_before(int x, int value) {

  struct dllnode *new_node, *s;

  new_node = dllcreate();

  new_node->data = x;

  s = dllstart;

  while (s != NULL && s->data != value) {

    s = s->next;

  }

  if (s == NULL) {

    printf("%d not found in list\n", value);

    return;

  }

  new_node->next = s;

  new_node->pre = s->pre;

  if (s->pre) {

    s->pre->next = new_node;

  } else {

    dllstart = new_node; 

  }

  s->pre = new_node;

  dlldisplay();

}

void dllinsert_mid_after(int x, int value) {

  struct dllnode *new_node, *s;

  new_node = dllcreate();

  new_node->data = x;

  s = dllstart;

  while (s != NULL && s->data != value) {

    s = s->next;

  }

  if (s == NULL) {

    printf("%d not found in list\n", value);

    return;

  }

  new_node->pre = s;

  new_node->next = s->next;

  if (s->next) {

    s->next->pre = new_node;

  } else {

    dllend = new_node;

  }

  s->next = new_node;

  dlldisplay();

}

void dllinsert_end(int x) {

  struct dllnode *new_node, *s;

  new_node = dllcreate();

  new_node->data = x;

  if (dllstart == NULL && dllend == NULL) {

    dllstart = dllend = new_node;

  } else {

    dllend->next = new_node;

    new_node->pre = dllend;

    dllend = new_node;

  }

  dlldisplay();

}

void dlldelete_start() {

  struct dllnode *temp;

  if (dllstart == NULL) {

    printf("List is empty\n");

    return;

  }

  temp = dllstart;

  dllstart = dllstart->next;

  dllstart->pre = NULL;

  free(temp);

  dlldisplay();

}

void dlldelete_mid(int pos) {

  struct dllnode *temp, *s = dllstart;

  int i = 1;

  if (dllstart == NULL) {

    printf("List is empty\n");

    return;

  }

  while (i < pos && s != NULL) {

    s = s->next;

    i++;

  }

  if (s == NULL) {

    printf("Invalid position\n");

    return;

  }

  temp = s;

  if (s->pre) {

    s->pre->next = s->next;

  } else {

    dllstart = s->next;

  }

  if (s->next) {

    s->next->pre = s->pre;

  } else {

    dllend = s->pre;

  }

  free(temp);

  dlldisplay();

}

void dlldelete_mid_before(int value) {

  struct dllnode *temp, *s = dllstart;

  if (dllstart == NULL) {

    printf("List is empty\n");

    return;

  }

  while (s != NULL && s->data != value) {

    s = s->next;

  }

  if (s == NULL || s == dllstart) {

    printf("%d not found in list\n", value);

    return;

  }

  temp = s->pre;

  temp->pre->next = s;

  s->pre = temp->pre;

  free(temp);

  dlldisplay();

}

void dlldelete_mid_after(int value) {

  struct dllnode *temp, *s = dllstart;

  if (dllstart == NULL) {

    printf("List is empty\n");

    return;

  }

  while (s != NULL && s->data != value) {

    s = s->next;

  }

  if (s == NULL || s == dllend) {

    printf("%d not found in list\n", value);

    return;

  }

  temp = s->next;

  s->next = temp->next;

  if (temp->next) {

    temp->next->pre = s;

  } else {

    dllend = s;

  }

  free(temp);

  dlldisplay();

}

void dlldelete_end() {

  struct dllnode *temp;

  if (dllend == NULL) {

    printf("List is empty\n");

    return;

  }

  temp = dllend;

  dllend = dllend->pre;

  dllend->next = NULL;

  free(temp);

  dlldisplay();

}

void dllr_display() {

  struct dllnode *s = dllend;

  if (s == NULL) {

    printf("List is empty\n");

    return;

  }

  while (s != NULL) {

    printf("%d -> ", s->data);

    s = s->pre;

  }

  printf("\n");

}

void dllsearch(int value) {

  struct dllnode *s = dllstart; 

  int pos = 1;

  while (s != NULL) {

    if (s->data == value) {

      printf("%d found at position %d\n", value, pos);

      return;

    }

    s = s->next;

    pos++;

  }

  printf("%d not found in list\n", value);

}

// **************************************************************

struct cllnode {

    int value;

    struct cllnode *next;

};

struct cllnode *cllstart = NULL;

struct cllnode *createNode(int value) {

    struct cllnode *newNode = (struct cllnode *)malloc(sizeof(struct cllnode));

    newNode->value = value;

    newNode->next = newNode; // Circular link to itself

    return newNode;

}

void clldisplay_list() {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *current = cllstart;

    do {

        printf("%d -> ", current->value);

        current = current->next;

    } while (current != cllstart);

    printf("\n");

}

void cllinsertBeginning(int value) {

    struct cllnode *newNode = createNode(value);

    if (cllstart == NULL) {

        cllstart = newNode;

    } else {

        newNode->next = cllstart;

        struct cllnode *current = cllstart;

        while (current->next != cllstart) {

            current = current->next;

        }

        current->next = newNode;

        cllstart = newNode;

    }

    clldisplay_list();

}

void cllinsertEnd(int value) {

    struct cllnode *newNode = createNode(value);

    if (cllstart == NULL) {

        cllstart = newNode;

    } else {

        struct cllnode *current = cllstart;

        while (current->next != cllstart) {

            current = current->next;

        }

        current->next = newNode;

        newNode->next = cllstart;

    }

    clldisplay_list();

}

int clldelete_start() {

  struct cllnode*temp;

  if (cllstart == NULL) {

    printf("List is empty\n");

    return -1;

  }

  temp=cllstart;

  int value = cllstart->value;

  cllstart = cllstart->next;

  temp->next=NULL;

  free(temp);

  return value;

}

// Function to delete a cllnode from the beginning of the circular singly linked list

void clldeleteBeginning() {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *toDelete = cllstart;

    if (cllstart->next == cllstart) { // Only one cllnode in the list

        cllstart = NULL;

    } else {

        struct cllnode *current = cllstart;

        while (current->next != cllstart) {

            current = current->next;

        }

        current->next = cllstart->next;

        cllstart = cllstart->next;

    }

    free(toDelete);

    clldisplay_list();

}

// Function to delete a cllnode from the end of the circular singly linked list

void clldeleteEnd() {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *toDelete = cllstart;

    if (cllstart->next == cllstart) { // Only one cllnode in the list

        cllstart = NULL;

    } else {

        struct cllnode *current = cllstart;

        struct cllnode *prev = NULL;

        while (current->next != cllstart) {

            prev = current;

            current = current->next;

        }

        prev->next = cllstart;

    }

    free(toDelete);

    clldisplay_list();

}

void cllinsertMiddle(int value, int position) {

    if (cllstart == NULL || position <= 1) {

        cllinsertBeginning(value);

        return;

    }

    struct cllnode *newNode = createNode(value);

    struct cllnode *current = cllstart;

    int count = 1;

    while (count < position - 1 && current->next != cllstart) {

        current = current->next;

        count++;

    }

    

    newNode->next = current->next;

    current->next = newNode;

    clldisplay_list();

}

// Delete the cllnode at the middle of the circular singly linked list

void clldeleteMiddle(int position) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    if (position <= 1) {

        printf("Invalid position for middle deletion\n");

        return;

    }

    struct cllnode *current = cllstart;

    struct cllnode *prev = NULL;

    int count = 1;

    while (count < position && current->next != cllstart) {

        prev = current;

        current = current->next;

        count++;

    }

    if (count != position) {

        printf("Position out of bounds\n");

        return;

    }

    prev->next = current->next;

    free(current);

    clldisplay_list();

}

// Insert a new cllnode before a given value in the circular singly linked list

void cllinsertBeforeValue(int newValue, int targetValue) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *newNode = createNode(newValue);

    struct cllnode *current = cllstart;

    struct cllnode *prev = NULL;

    do {

        if (current->value == targetValue) {

            if (prev == NULL) { // Insert at the beginning

                newNode->next = current;

                struct cllnode *last = cllstart;

                while (last->next != cllstart) {

                    last = last->next;

                }

                last->next = newNode;

                cllstart = newNode;

            } else {

                prev->next = newNode;

                newNode->next = current;

            }

            clldisplay_list();

            return;

        }

        prev = current;

        current = current->next;

    } while (current != cllstart);

    printf("Target value not found\n");

    free(newNode);

    

}

// Insert a new cllnode after a given value in the circular singly linked list

void cllinsertAfterValue(int newValue, int targetValue) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *newNode = createNode(newValue);

    struct cllnode *current = cllstart;

    do {

        if (current->value == targetValue) {

            newNode->next = current->next;

            current->next = newNode;

            clldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cllstart);

    printf("Target value not found\n");

    free(newNode);

}

// Delete the cllnode before a given value in the circular singly linked list

void clldeleteBeforeValue(int targetValue) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    if (cllstart->value == targetValue) {

        printf("No cllnode to delete before the first element\n");

        return;

    }

    struct cllnode *current = cllstart;

    struct cllnode *prev = NULL;

    struct cllnode *prevPrev = NULL;

    do {

        if (current->value == targetValue) {

            if (prevPrev == NULL) {

                printf("No cllnode to delete before the target value\n");

                return;

            }

            prevPrev->next = prev->next;

            free(prev);

            clldisplay_list();

            return;

        }

        prevPrev = prev;

        prev = current;

        current = current->next;

    } while (current != cllstart);

    printf("Target value not found\n");

}

// Delete the cllnode after a given value in the circular singly linked list

void clldeleteAfterValue(int targetValue) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cllnode *current = cllstart;

    do {

        if (current->value == targetValue) {

            struct cllnode *nodeToDelete = current->next;

            if (nodeToDelete == cllstart) {

                printf("No cllnode to delete after the last element\n");

                return;

            }

            current->next = nodeToDelete->next;

            free(nodeToDelete);

            clldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cllstart);

    printf("Target value not found\n");

}

// Search for an element in the circular singly linked list

int cllsearch(int value) {

    if (cllstart == NULL) {

        printf("List is empty\n");

        return -1;

    }

    struct cllnode *current = cllstart;

    int pos = 1;

    do {

        if (current->value == value) {

            return pos;

        }

        pos++;

        current = current->next;

    } while (current != cllstart);

    return -1;

}

// **************************************************

struct cdllnode {

    int value;

    struct cdllnode *prev;

    struct cdllnode *next;

};

struct cdllnode *cdllstart = NULL;

struct cdllnode *cdllcreateNode(int value) {

    struct cdllnode *newNode = (struct cdllnode *)malloc(sizeof(struct cdllnode));

    newNode->value = value;

    newNode->prev = NULL;

    newNode->next = NULL;

    return newNode;

}

void cdlldisplay_list() {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *current = cdllstart;

    do {

        printf("%d <-> ", current->value);

        current = current->next;

    } while (current != cdllstart);

    printf("\n");

}

void cdllinsertBeginning(int value) {

    struct cdllnode *newNode = cdllcreateNode(value);

    if (cdllstart == NULL) {

        cdllstart = newNode;

        cdllstart->prev = newNode;

        cdllstart->next = newNode;

    } else {

        newNode->next = cdllstart;

        newNode->prev = cdllstart->prev;

        cdllstart->prev->next = newNode;

        cdllstart->prev = newNode;

        cdllstart = newNode;

    }

    cdlldisplay_list();

}

void cdllinsertEnd(int value) {

    struct cdllnode *newNode = cdllcreateNode(value);

    if (cdllstart == NULL) {

        cdllstart = newNode;

        cdllstart->prev = newNode;

        cdllstart->next = newNode;

    } else {

        newNode->prev = cdllstart->prev;

        newNode->next = cdllstart;

        cdllstart->prev->next = newNode;

        cdllstart->prev = newNode;

    }

    cdlldisplay_list();

}

void cdlldeleteBeginning() {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *toDelete = cdllstart;

    if (cdllstart->next == cdllstart) { // Only one cdllnode in the list

        cdllstart = NULL;

    } else {

        cdllstart->prev->next = cdllstart->next;

        cdllstart->next->prev = cdllstart->prev;

        cdllstart = cdllstart->next;

    }

    free(toDelete);

    cdlldisplay_list();

}

void cdlldeleteEnd() {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *toDelete = cdllstart->prev;

    if (cdllstart->next == cdllstart) { // Only one cdllnode in the list

        cdllstart = NULL;

    } else {

        cdllstart->prev = toDelete->prev;

        toDelete->prev->next = cdllstart;

    }

    free(toDelete);

    cdlldisplay_list();

}

void cdllinsertMiddle(int value, int position) {

    if (cdllstart == NULL || position <= 1) {

        cdllinsertBeginning(value);

        return;

    }

    struct cdllnode *newNode = cdllcreateNode(value);

    struct cdllnode *current = cdllstart;

    int count = 1;

    while (count < position - 1 && current->next != cdllstart) {

        current = current->next;

        count++;

    }

    newNode->next = current->next;

    newNode->prev = current;

    current->next->prev = newNode;

    current->next = newNode;

    cdlldisplay_list();

}

void cdlldeleteMiddle(int position) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    if (position <= 1) {

        printf("Invalid position for middle deletion\n");

        return;

    }

    struct cdllnode *current = cdllstart;

    int count = 1;

    while (count < position && current->next != cdllstart) {

        current = current->next;

        count++;

    }

    if (count != position) {

        printf("Position out of bounds\n");

        return;

    }

    current->prev->next = current->next;

    current->next->prev = current->prev;

    free(current);

    cdlldisplay_list();

}

void cdllinsertBeforeValue(int newValue, int targetValue) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *newNode = cdllcreateNode(newValue);

    struct cdllnode *current = cdllstart;

    do {

        if (current->value == targetValue) {

            newNode->next = current;

            newNode->prev = current->prev;

            current->prev->next = newNode;

            current->prev = newNode;

            cdlldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cdllstart);

    printf("Target value not found\n");

    free(newNode);

}

void cdllinsertAfterValue(int newValue, int targetValue) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *newNode = cdllcreateNode(newValue);

    struct cdllnode *current = cdllstart;

    do {

        if (current->value == targetValue) {

            newNode->prev = current;

            newNode->next = current->next;

            current->next->prev = newNode;

            current->next = newNode;

            cdlldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cdllstart);

    printf("Target value not found\n");

    free(newNode);

}

void cdlldeleteBeforeValue(int targetValue) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *current = cdllstart;

    do {

        if (current->value == targetValue) {

            struct cdllnode *nodeToDelete = current->prev;

            if (nodeToDelete == cdllstart) {

                printf("No cdllnode to delete before the first element\n");

                return;

            }

            nodeToDelete->prev->next = current;

            current->prev = nodeToDelete->prev;

            free(nodeToDelete);

            cdlldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cdllstart);

    printf("Target value not found\n");

}

void cdlldeleteAfterValue(int targetValue) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return;

    }

    struct cdllnode *current = cdllstart;

    do {

        if (current->value == targetValue) {

            struct cdllnode *nodeToDelete = current->next;

            if (nodeToDelete == cdllstart) {

                printf("No cdllnode to delete after the last element\n");

                return;

            }

            current->next = nodeToDelete->next;

            nodeToDelete->next->prev = current;

            free(nodeToDelete);

            cdlldisplay_list();

            return;

        }

        current = current->next;

    } while (current != cdllstart);

    printf("Target value not found\n");

}

// Search for an element in the circular doubly linked list

int cdllsearch(int value) {

    if (cdllstart == NULL) {

        printf("List is empty\n");

        return -1;

    }

    struct cdllnode *current = cdllstart;

    int pos = 1;

    do {

        if (current->value == value) {

            return pos;

        }

        pos++;

        current = current->next;

    } while (current != cdllstart);

    return -1;

}

int main() {

  int choice, value, pos;

  while(1) {

    

    printf("\nLinked List Operations\n");

    printf("1. Singly linked list\n");

    printf("2. Doubly linked list\n");

    printf("3. Circular linked list\n"); 

    printf("4. Circular doubly linked list\n");

    printf("5. Exit\n");

    

    scanf("%d", &choice);

    outer_switch:

    switch(choice) {

      

      case 1:

        // Singly linked list operations

        while(1) {

          printf("\nSingle Linked List Menu\n");

          printf("\n1. Insert at start\n");

    printf("2. Insert at end\n");

    printf("3. Delete from start\n");

    printf("4. Delete from end\n");

    printf("5. Insert at position\n");

    printf("6. Insert before value\n"); 

    printf("7. Insert after value\n");

    printf("8. Delete at position\n");

    printf("9. Delete before value\n");

    printf("10. Delete after value\n");

    printf("11. Search element\n");

    printf("12. Display list\n");

    printf("13. Exit\n");

  while (1) {

    printf("\n Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {

      case 1:

        printf("Enter the element to insert: ");

        scanf("%d", &value);

        sllinsert_start(value);

        break;

      case 2:

        printf("Enter the element to insert: ");

        scanf("%d", &value);

        sllinsert_end(value);

        break;

      case 3:

        printf("Deleted element: %d\n", slldelete_start());

        break;

      case 4:

        printf("Deleted element: %d\n", slldelete_end());  

        break;

      case 5:

        printf("Enter position: ");

        scanf("%d", &pos);

        printf("Enter element: ");

        scanf("%d", &value);

        sllinsert_position(value, pos);

        break;

      case 6:

        printf("Enter existing value: ");

        scanf("%d", &value);

        printf("Enter new value: ");

        scanf("%d", &pos);

        sllinsert_before(value, pos);

        break;

      case 7:

        printf("Enter existing value: ");

        scanf("%d", &value);

        printf("Enter new value: ");

        scanf("%d", &pos);

        sllinsert_after(value, pos);

        break;

      case 8:

        printf("Enter position: ");

        scanf("%d", &pos);

        printf("Deleted element: %d\n", slldelete_position(pos));

        break;

      case 9:

        printf("Enter value: ");

        scanf("%d", &value);

        printf("Deleted element: %d\n", slldelete_before(value));

        break;

      case 10:

        printf("Enter value: ");

        scanf("%d", &value);

        printf("Deleted element: %d\n", slldelete_after(value));

        break;

      case 11:

        printf("Enter element to dllsearch: ");

        scanf("%d", &value);

        pos = sllsearch(value);

        if(pos == -1){

          printf("Element not found\n");

        } else {

          printf("Element found at position %d\n", pos);

          

        }

        break;

      case 12:

        slldisplay_list();

        break;

      case 13:

        goto outer_switch;

      default:

        printf("Invalid choice\n");

    }

  }

        }

        break;

        

      case 2:

        // Doubly linked list operations 

        while(1) {

          printf("\nDouble Linked List Menu\n");

          int choice, x, pos, value;

  while (1) {

    

    printf("\nMenu:");

    printf("\n1. Insert at beginning"); 

    printf("\n2. Insert at middle");

    printf("\n3. Insert before value");

    printf("\n4. Insert after value");

    printf("\n5. Insert at end");

    printf("\n6. Delete from beginning");

    printf("\n7. Delete from middle");

    printf("\n8. Delete before value");

    printf("\n9. Delete after value");  

    printf("\n10. Delete from end");

    printf("\n11. Display");

    printf("\n12. Display reverse");

    printf("\n13. Search");

    printf("\n14. Exit");

    

    printf("\nEnter your choice: ");

    scanf("%d", &choice);

    

    switch(choice) {

      case 1: 

        printf("Enter value: ");

        scanf("%d", &x);

        dllinsert_start(x);

        break;

        

      case 2:

        printf("Enter position: ");

        scanf("%d", &pos);  

        printf("Enter value: ");

        scanf("%d", &x);

        dllinsert_mid(x, pos);

        break;

        

      case 3:

        printf("Enter value: ");

        scanf("%d", &x);

        printf("Enter value before which to insert: ");

        scanf("%d", &value);

        dllinsert_mid_before(x, value);

        break;

        

      case 4:  

        printf("Enter value: ");

        scanf("%d", &x);

        printf("Enter value after which to insert: ");

        scanf("%d", &value);

        dllinsert_mid_after(x, value);

        break;

        

      case 5:

        printf("Enter value: ");

        scanf("%d", &x);

        dllinsert_end(x);

        break;

        

      case 6:

        dlldelete_start();

        break;

        

      case 7:

        printf("Enter position: ");

        scanf("%d", &pos);

        dlldelete_mid(pos);

        break;

        

      case 8:

        printf("Enter value: ");

        scanf("%d", &value);

        dlldelete_mid_before(value);

        break;

        

      case 9:

        printf("Enter value: ");

        scanf("%d", &value);

        dlldelete_mid_after(value);

        break;

        

      case 10:

        dlldelete_end();

        break;

        

      case 11:

        dlldisplay();

        break;

        

      case 12:

        dllr_display();

        break;

        

      case 13:

        printf("Enter value to dllsearch: ");

        scanf("%d", &x);

        dllsearch(x);

        break;

        

      case 14:

        goto outer_switch;

        

      default:

        printf("Invalid choice!\n");

    }

  }

           

        }

        break;

        

      case 3:

        // Circular linked list operations

        while(1) {

          printf("\nCircular Linked List Menu\n");

          int choice, value, position, targetValue;

    printf("Circular Singly Linked List Operations:\n");

    printf("1. Insert at beginning\n");

    printf("2. Insert at end\n");

    printf("3. Delete from beginning\n");

    printf("4. Delete from end\n");

    printf("5. Insert at middle\n");

    printf("6. Delete from middle\n");

    printf("7. Insert before a value\n");

    printf("8. Insert after a value\n");

    printf("9. Delete before a value\n");

    printf("10. Delete after a value\n");

    printf("11. Display list\n");

    printf("12. Search element\n");

    printf("13. Exit\n");

    while (1) {

        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                cllinsertBeginning(value);

                break;

            case 2:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                cllinsertEnd(value);

                break;

            case 3:

                clldeleteBeginning();

                break;

            case 4:

                clldeleteEnd();

                break;

            case 5:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                printf("Enter the position: ");

                scanf("%d", &position);

                cllinsertMiddle(value, position);

                break;

            case 6:

                printf("Enter the position: ");

                scanf("%d", &position);

                clldeleteMiddle(position);

                break;

            case 7:

                printf("Enter the new element: ");

                scanf("%d", &value);

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cllinsertBeforeValue(value, targetValue);

                break;

            case 8:

                printf("Enter the new element: ");

                scanf("%d", &value);

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cllinsertAfterValue(value, targetValue);

                break;

            case 9:

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                clldeleteBeforeValue(targetValue);

                break;

            case 10:

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                clldeleteAfterValue(targetValue);

                break;

            case 11:

                clldisplay_list();

                break;

            case 12:

                printf("Enter element to cllsearch: ");

                scanf("%d", &value);

                int pos = cllsearch(value);

                if (pos == -1) {

                    printf("Element not found\n");

                } else {

                    printf("Element found at position %d\n", pos);

                }

                break;

            case 13:

                goto outer_switch;

            default:

                printf("Invalid choice\n");

        }

    }

        }

        break;

        

      case 4:  

        // Circular doubly linked list operations

        while(1) {

          printf("\nCircular Double Linked List Menu\n");

          

          int choice, value, position, targetValue;

    printf("Circular Doubly Linked List Operations:\n");

    printf("1. Insert at beginning\n");

    printf("2. Insert at end\n");

    printf("3. Delete from beginning\n");

    printf("4. Delete from end\n");

    printf("5. Insert at middle\n");

    printf("6. Delete from middle\n");

    printf("7. Insert before a value\n");

    printf("8. Insert after a value\n");

    printf("9. Delete before a value\n");

    printf("10. Delete after a value\n");

    printf("11. Display list\n");

    printf("12. Search element\n");

    printf("13. Exit\n");

    while (1) {

        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                cdllinsertBeginning(value);

                break;

            case 2:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                cdllinsertEnd(value);

                break;

            case 3:

                cdlldeleteBeginning();

                break;

            case 4:

                cdlldeleteEnd();

                break;

            case 5:

                printf("Enter the element to insert: ");

                scanf("%d", &value);

                printf("Enter the position: ");

                scanf("%d", &position);

                cdllinsertMiddle(value, position);

                break;

            case 6:

                printf("Enter the position: ");

                scanf("%d", &position);

                cdlldeleteMiddle(position);

                break;

            case 7:

                printf("Enter the new element: ");

                scanf("%d", &value);

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cdllinsertBeforeValue(value, targetValue);

                break;

            case 8:

                printf("Enter the new element: ");

                scanf("%d", &value);

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cdllinsertAfterValue(value, targetValue);

                break;

            case 9:

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cdlldeleteBeforeValue(targetValue);

                break;

            case 10:

                printf("Enter the target value: ");

                scanf("%d", &targetValue);

                cdlldeleteAfterValue(targetValue);

                break;

            case 11:

                cdlldisplay_list();

                break;

            case 12:

                printf("Enter element to cdllsearch: ");

                scanf("%d", &value);

                int pos = cdllsearch(value);

                if (pos == -1) {

                    printf("Element not found\n");

                } else {

                    printf("Element found at position %d\n", pos);

                }

                break;

            case 13:

                goto outer_switch;

            default:

                printf("Invalid choice\n");

        }

    }

        }

        break;

        

      case 5:

        exit(0);

        

      default:

        printf("Invalid choice\n");

    }

  }

  return 0;

}
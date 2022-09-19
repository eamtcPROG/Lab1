#include <iostream>
#include <cstdlib>

using namespace std;

struct NodeDoubly
{
    int data;
    struct NodeDoubly *next;
    struct NodeDoubly *prev;
};

void reverseDoubly(struct NodeDoubly **headRef)
{
    struct NodeDoubly *tempD = NULL;
    struct NodeDoubly *currentD = *headRef;

    while (currentD != NULL)
    {
        tempD = currentD->prev;
        currentD->prev = currentD->next;
        currentD->next = tempD;
        currentD = currentD->prev;
    }

    if (tempD != NULL)
        *headRef = tempD->prev;
}

void pushDoubly(struct NodeDoubly **headRef, int newData)
{
    struct NodeDoubly *newNodeD = (struct NodeDoubly *)malloc(sizeof(struct NodeDoubly));

    newNodeD->data = newData;
    newNodeD->prev = NULL;
    newNodeD->next = (*headRef);

    if ((*headRef) != NULL)
        (*headRef)->prev = newNodeD;

    (*headRef) = newNodeD;
}

struct Node
{
    int data;
    struct Node *next;
};

void append(struct Node **headRef, int newData)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void prepend(struct Node **headRef, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

static void reverse(struct Node **headRef)
{
    struct Node *prev = NULL;
    struct Node *current = *headRef;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void deleteElement(struct Node **headRef, int pos)
{

    struct Node *temp = *headRef;

    int i;
    if (pos == 0)
    {
        struct Node *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct Node *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
        free(del);
    }
}

Node *getNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void printListDoubly(struct NodeDoubly *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

void menuText()
{
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------- Menu -----------------------" << endl;
    cout << "\n 1. - Linked List menu" << endl;
    cout << " 2. - Add data from file" << endl;
    cout << " 3. - Exit" << endl;
    cout << "\n----------------------------------------------------" << endl;
}

void linkedListMenuText()
{
    cout << "----------------------------------------------------" << endl;
    cout << "----------------- Linked List Menu -----------------" << endl;
    cout << "\n 1. - Append" << endl;
    cout << " 2. - Prepend" << endl;
    cout << " 3. - Reverse" << endl;
    cout << " 4. - Add a value to the specific index" << endl;
    cout << " 5. - Remove a value the from index" << endl;
    cout << " 6. - Show list" << endl;
    cout << " 7. - Search element" << endl;
    cout << " 8. - Sort elements" << endl;
    cout << " 9. - Exit" << endl;
    cout << "\n----------------------------------------------------" << endl;
}

void linkedListSelectText()
{
    cout << "----------------------------------------------------" << endl;
    cout << "---------------- Linked List Select ----------------" << endl;
    cout << "\n 1. - Linked List" << endl;
    cout << " 2. - Linked List Doubly" << endl;
    cout << " 3. - Exit" << endl;
    cout << "\n----------------------------------------------------" << endl;
}

void linkedListDoublyText()
{
    cout << "----------------------------------------------------" << endl;
    cout << "---------------- Linked List Doubly ----------------" << endl;
    cout << "\n 1. - Push" << endl;
    cout << " 2. - Backwards traversal" << endl;
    cout << " 3. - Show list" << endl;
    cout << " 4. - Exit" << endl;
    cout << "\n----------------------------------------------------" << endl;
}

void menuSelectText()
{
    cout << "----------------------------------------------------" << endl;
    cout << "----------------- Menu Select List -----------------" << endl;
    cout << "\n 1. - First Linked List" << endl;
    cout << " 2. - Second Linked List" << endl;
    cout << " 3. - Join Lists" << endl;
    cout << " 4. - Exit" << endl;
    cout << "\n----------------------------------------------------" << endl;
}

void infoText(char input)
{
    switch (input)
    {
    case '1':
    {
        cout << "\nPress a key: ";
    }
    break;
    case '2':
    {
        cout << "\nIf you want to continue press y, else press n to exit: ";
    }
    break;
    case '3':
    {
        cout << "\nSorry,you can press only n or y !!!";
    }
    break;
    case '4':
    {
        cout << "\nIf you want to exit press y to confirm, else press n to continue: ";
    }
    break;
    case '5':
    {
        cout << "\nType a number: ";
    }
    break;
    case '6':
    {
        cout << "\n\nIf you want to to stay in this Menu press y, else press n to go to previous Menu: ";
    }
    break;
    case '7':
    {
        cout << "\nMy List: ";
    }
    break;
    case '8':
    {
        cout << "\nIf you want to add: ";
    }
    break;
    case '9':
    {
        cout << "\nPress y to confirm else press n to decline: ";
    }
    break;
    case '0':
    {
        cout << "\nAre you sure you want to reverse your list if yes press y to confirm else press n to decline: ";
    }
    break;
    case 'a':
    {
        cout << "\nType position: ";
    }
    break;
    case 'b':
    {
        cout << "\nIf you want to delete this position: ";
    }
    break;
    case 'c':
    {
        cout << "Invalid position!" << endl;
    }
    break;
    case 'd':
    {
        cout << "\nIf you want to insert element in this position: ";
    }
    break;
    case 'e':
    {
        cout << "\nIf you want to search: ";
    }
    break;
    case 'f':
    {
        cout << "\nThe element has been found, its position is: ";
    }
    break;
    case 'h':
    {
        cout << "\nThe element doesn't exist";
    }
    break;
    case 'g':
    {
        cout << "\nList sorted!";
    }
    break;
    case 'j':
    {
        cout << "\nIf you want to backwards traversal: ";
    }
    break;
    case 'l':
    {
        cout << "\nList is empty";
    }
    break;
    default:
    {
        cout << "\nSorry,you can press only 1,2,3,4 !!!" << endl;
    }
    }
}

void insertPos(Node **headRef, int pos, int data)
{

    if (pos < 1)
        infoText('c');
    else
    {
        while (pos--)
        {

            if (pos == 0)
            {
                Node *temp = getNode(data);
                temp->next = *headRef;
                *headRef = temp;
            }
            else
            {
                headRef = &(*headRef)->next;
            }
        }
    }
}

int search(struct Node **headRef, int el)
{
    struct Node *current = *headRef;
    int pos = 0;
    while (current != NULL)
    {
        if (current->data == el)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

void clearTerminal()
{
    system("clear");
}

int conformationMenu(char type)
{
    char input;
    infoText(type);
    cin >> input;
    int r;
    switch (input)
    {
    case 'y':
    {
        clearTerminal();
        r = 0;
    }
    break;
    case 'n':
    {
        r = 1;
    }
    break;
    default:
    {
        infoText('3');
        conformationMenu(type);
    }
    }
    return r;
}

void sortedInsert(struct Node **headRef, struct Node *newNode)
{
    struct Node *d;
    struct Node *current = d;
    d->next = *headRef;

    while (current->next != NULL && current->next->data < newNode->data)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    *headRef = d->next;
}

void sort(struct Node **headRef)
{
    struct Node *result = NULL;
    struct Node *current = *headRef;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        sortedInsert(&result, current);
        current = next;
    }
    *headRef = result;
}

void moveNode(struct Node **destRef, struct Node **sourceRef)
{
    struct Node *newNode = *sourceRef;
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

struct Node *merge(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;
    struct Node **lastPtrRef = &result;

    while (1)
    {
        if (a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if (b == NULL)
        {
            *lastPtrRef = a;
            break;
        }
        if (a->data <= b->data)
        {

            moveNode(lastPtrRef, &a);
        }
        else
        {

            moveNode(lastPtrRef, &b);
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }
    return (result);
}

void linkedListMenu(struct Node **list)
{
    int stopProgram = 0;
    char inputValUser;
    struct Node *mylist = *list;
    do
    {
        clearTerminal();
        linkedListMenuText();
        infoText('1');
        cin >> inputValUser;
        switch (inputValUser)
        {
        case '1':
        {
            int input;
            infoText('5');
            cin >> input;
            infoText('8');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                append(&mylist, input);
            }
        }
        break;
        case '2':
        {
            int input;
            infoText('5');
            cin >> input;
            infoText('8');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                prepend(&mylist, input);
            }
        }
        break;
        case '3':
        {
            int confirm = conformationMenu('0');
            if (confirm == 0)
            {
                reverse(&mylist);
            }
        }
        break;
        case '4':
        {
            int input, inputVal;
            infoText('a');
            cin >> input;
            infoText('d');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                linkedListMenuText();
                infoText('5');
                cin >> inputVal;
                infoText('8');
                cout << inputVal;
                confirm = conformationMenu('9');
                if (confirm == 0)
                {
                    insertPos(&mylist, input, inputVal);
                }
            }
        }
        break;
        case '5':
        {
            int input;
            infoText('a');
            cin >> input;
            infoText('b');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                deleteElement(&mylist, input);
            }
        }
        break;
        case '6':
        {
            infoText('7');
            printList(mylist);
            stopProgram = conformationMenu('6');
        }
        break;
        case '7':
        {
            int input, pos;
            infoText('5');
            cin >> input;
            infoText('e');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                pos = search(&mylist, input);
            }
            linkedListMenuText();
            if (pos != -1)
            {
                infoText('f');
                cout << pos;
            }
            else
            {
                infoText('h');
            }
            stopProgram = conformationMenu('6');
        }
        break;
        case '8':
        {
            if(mylist != NULL){
                sort(&mylist);
                infoText('g');
            }
            else{
                infoText('l');
            }
            stopProgram = conformationMenu('6');
        }
        
        break;
        case '9':
        {
            int confirm = conformationMenu('4');
            if (confirm == 0)
            {
                stopProgram = 1;
            }
        }
        break;

        default:
        {
            infoText('w');
            stopProgram = conformationMenu('2');
        }
        }
    } while (stopProgram != 1);
    (*list) = mylist;
}

void menuSelect()
{
    int stopProgram = 0;
    char inputValUser;
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *mergeList = NULL;

    do
    {
        clearTerminal();
        menuSelectText();
        infoText('1');
        cin >> inputValUser;
        switch (inputValUser)
        {
        case '1':
        {
            linkedListMenu(&list1);
        }
        break;
        case '2':
        {
            linkedListMenu(&list2);
        }
        break;
        case '3':
        {
            mergeList = merge(list1, list2);
            infoText('7');
            printList(mergeList);
            stopProgram = conformationMenu('6');
        }
        break;

        case '4':
        {
            int confirm = conformationMenu('4');
            if (confirm == 0)
            {
                stopProgram = 1;
            }
        }
        break;

        default:
        {
            infoText('w');
            stopProgram = conformationMenu('2');
        }
        }
    } while (stopProgram != 1);
}

void linkedListDoubly()
{
    int stopProgram = 0;
    char inputValUser;
    struct NodeDoubly *mylist = NULL;
    do
    {
        clearTerminal();
        linkedListDoublyText();
        infoText('1');
        cin >> inputValUser;
        switch (inputValUser)
        {
        case '1':
        {
            int input;
            infoText('5');
            cin >> input;
            infoText('8');
            cout << input;
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                pushDoubly(&mylist, input);
            }
        }
        break;
        case '2':
        {
            infoText('j');
            int confirm = conformationMenu('9');
            if (confirm == 0)
            {
                reverseDoubly(&mylist);
            }
        }
        break;

        case '3':
        {
            infoText('7');
            printListDoubly(mylist);
            stopProgram = conformationMenu('6');
        }
        break;

        case '4':
        {
            int confirm = conformationMenu('4');
            if (confirm == 0)
            {
                stopProgram = 1;
            }
        }
        break;

        default:
        {
            infoText('w');
            stopProgram = conformationMenu('2');
        }
        }
    } while (stopProgram != 1);
}

void linkedListSelect()
{
    int stopProgram = 0;
    char inputValUser;
    do
    {
        clearTerminal();
        linkedListSelectText();
        infoText('1');
        cin >> inputValUser;
        switch (inputValUser)
        {
        case '1':
        {
            menuSelect();
        }
        break;
        case '2':
        {
            linkedListDoubly();
        }
        break;

        case '3':
        {
            int confirm = conformationMenu('4');
            if (confirm == 0)
            {
                stopProgram = 1;
            }
        }
        break;

        default:
        {
            infoText('w');
            stopProgram = conformationMenu('2');
        }
        }
    } while (stopProgram != 1);
}
int main()
{
    int stopProgram = 0;
    char inputValUser;
    clearTerminal();
    
    do
    {
        clearTerminal();
        menuText();
        infoText('1');
        cin >> inputValUser;
        switch (inputValUser)
        {
        case '1':
        {
            linkedListSelect();
        }
        break;
        case '2':
        {
        }
        break;
        case '3':
        {
            int confirm = conformationMenu('4');
            if (confirm == 0)
            {
                stopProgram = 1;
            }
        }
        break;

        default:
        {
            infoText('d');
            stopProgram = conformationMenu('2');
        }
        }
    } while (stopProgram != 1);

    return 0;
}
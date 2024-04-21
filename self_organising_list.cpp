//Program to implement Self Organising List ADT using Move-To-Front method using Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

class List
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *tail;

    public:
        List()
        {
        head = nullptr;
        tail = nullptr;
        } 

        bool insertion(int);
        bool deletion(int);
        bool access(int);
        void movetofront(struct node *);
        void display();

};

int main()
{
    List l1;
    while (true)
    {
        printf("Menu:\n1. Insert\n2. Delete\n3. Access\n4. Display\n5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            int num, res;
            case 1:
                printf("\nEnter number to insert: ");
                scanf("%d", &num);

                if (l1.insertion(num)) 
                {
                    printf("Element %d inserted successfully.\n\n", num);
                } 
                else 
                {
                    printf("Insertion failed.\n\n");
                }
                break;

            case 2:
                printf("\nEnter number to delete: ");
                scanf("%d", &num);

                if (l1.deletion(num)) 
                {
                    printf("Element %d deleted successfully.\n\n", num);
                } 
                else 
                {
                    printf("Deletion failed.\n\n");
                }
                break;

            case 3:
                printf("\nEnter number to access: ");
                scanf("%d", &num);

                if (l1.access(num)) 
                {
                    printf("Element %d accessed.\n\n", num);
                }
                else 
                {
                    printf("Element %d not found.\n\n", num);
                }
                break;

            case 4:
                l1.display();
                break;

            case 5:
                printf("Program exited\n");
                exit(0);

            default:
                printf("\nInvalid choice entered. Enter valid choice.\n\n");
                break;
        }
    }
}

//Method to insert an element into the SOL
bool List::insertion(int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory allocation failed.\n\n");
        return false;
    }

    newnode->data = num;
    newnode->next = nullptr;

    if (head == nullptr)
    {
        newnode->prev = nullptr;
        head = newnode;
        tail = newnode;
        return true;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    return true;
}

//Method to delete an element from the SOL
bool List::deletion(int num)
{
  struct node *temp = head;

  while (temp != nullptr) 
  {
    if (temp->data == num) 
    {
        if (temp == head) 
        {
            head = head->next;
            if (head != nullptr) 
            {
            head->prev = nullptr;
            } 
            else 
            {
            tail = nullptr;
            }
        } 
        else if (temp == tail) 
        {
            tail = tail->prev;
            if (tail != nullptr) 
            {
            tail->next = nullptr;
            } 
            else 
            {
            head = nullptr;
            }
        } 
        else 
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        free(temp);
        return true;
    }
    temp = temp->next;
  }

  return false; // Deletion failed (element not found or empty list)
}



//Method to move an element to the front
void List::movetofront(struct node *temp)
{
    if (temp == head)
    {
        return;
    }
    if (temp == tail)
    {
        tail = temp->prev;
        tail->next = nullptr;
    }
    else
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    temp->prev = nullptr;
    head->prev = temp;
    temp->next = head;
    head = temp;
}

//Method to access an element in the SOL
bool List::access(int num)
{
    struct node *target = head;

    while (target != nullptr)
    {
        if (target->data == num)
        {
            movetofront(target);
            return true;
        }
        target = target->next;
    }

    return false;
}

//Method to display the elements of the SOL
void List::display()
{
    struct node *temp = head;

    if (head == nullptr)
    {
        printf("\nThe list is empty.\n\n");
    }

    else
    {
        printf("\nContents of the self organising list:\n");
        while (temp != nullptr)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n\n");
    }
}

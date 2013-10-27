#include <iostream>
#include <string.h>

using namespace std;


class production_list
{
    char data[100];
    production_list * next;
    public: 
    production_list()
    {
        strcpy(data, " ");
        next = NULL;
    }
    void add_item(char * new_prod, production_list * head, production_list * tail)
    {
        production_list * new_item = new production_list;
        if (head == NULL)
        {
            tail = new_item;
        }
        strcpy(new_item->data, new_prod); 
        head->next = new_item;
        new_item->next = NULL;
        head = head->next;
        cout << "Added item " << new_prod << '\n';
    }
    void display(production_list * tail)
    {
        production_list * scan;
        scan = tail;
        while (scan->next != NULL)
        {
            cout << scan->data << '\n';
            scan = scan->next;
        }
    }
};




int main()
{
    production_list a;
    production_list * list_head;
    production_list * list_tail;
    char str[100];
    strcpy(str, "hello");
    a.add_item(str, list_head, list_tail);
    a.add_item(str, list_head, list_tail);
    a.display(list_tail);
    return 0;
}


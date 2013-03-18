#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int char_after_dot(char*);
void insert_dot(char*, char*);
bool is_nonterminal(char); 

class group
{
    char name[10];
    char productions[100][100];
    int group_prod_count;
    char added[100];
    public:
    group()
    {
        group_prod_count = 0;
        for (int i=0; i<100; i++)
            added[i] = '0';
    }
    void set_name(char new_name[])
    {
        strcpy(name, new_name);
    }
    void add_prod(char prod[100])
    {
        strcpy(productions[group_prod_count], prod);
        group_prod_count++;
    }
    void closure(char* given_prods, int given_prods_count)
    {
        bool already_there;
        for (int i=0; i<group_prod_count; i++)
        {
            int next_char_loc;
            next_char_loc = char_after_dot(productions[i]);
            already_there = false;
            if (is_nonterminal(productions[i][next_char_loc]))
            {
                for (int k=0; added[k] != '0'; k++)
                {
                    if (added[k] == productions[i][next_char_loc])
                        already_there = true;
                }
                if (already_there) break;
                for (int k=0; k<given_prods_count; k++)
                {
                    printf("Considering %s", given_prods[k]);
                    if (productions[i][next_char_loc] == given_prods[k][0])
                    {
                        add_prod(given_prods[k]);
                        printf("\nadded : %s", given_prods[k]);
                    }
                }
                int l;
                for (l=0; added[l] != '0'; l++);
                added[l] = productions[i][next_char_loc];
                printf("\n%c is new!\n", productions[i][next_char_loc]);
            }
         }
     } 
                     
    void display_prods()
    {
        printf ("Productions in %s are : \n", name);
        for (int i=0; i<group_prod_count; i++)
            printf("%s", productions[i]);
    }
};

int char_after_dot(char* production)
{
    for (int i=0; i<strlen(production); i++)
    {
        if (production[i] == '.')
            return i+1;
    }
    return -1;
}

//Takes old_prod, adds a '.' to the 3rd location, and puts it into new_prod
void insert_dot(char* old_prod, char* new_prod)     
{
    strcpy(new_prod, old_prod);
    for (int j=100; j>3; j--)
        new_prod[j] = new_prod[j-1];
    new_prod[3] = '.';
    return;
}

bool is_nonterminal(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    else //if (character >= 'A' && character <= 'Z')
        return false;
}



int main()
{
    FILE* fd = NULL;
    char buff[100];
    char productions[100][100];
    group a[100];
    int prod_count = 0;
    
    memset(buff, 0, sizeof(buff));
    
    fd = fopen("input.txt", "r");
    
    if (fd == NULL)
    {
        printf("\nOops! There was an error opening the file\n");
        return 1;
    }
    printf("Input.txt opened!\n");
    printf("The list of production are : \n");
    while(fgets(buff, 80, fd) != NULL)
    {
        //printf ("%s", fgets(buff, 80, fd));
        for (int i=0; i<strlen(buff); i++)
        {
            if (buff[i] == 'i' && buff[i+1] == 'd')
            {
                for (int j=i+1; j<strlen(buff); j++)
                    buff[j] = buff[j+1];
                buff[i] = '@';
            }
        }
	    printf("%s", buff);
	    strcpy(productions[prod_count], buff);
	    prod_count++;
    }
    
    for (int i=0; i<prod_count; i++)
        insert_dot(productions[i], productions[i]);
     
    //---- Compute Closure(I0) ----
    a[0].set_name("I0");
    a[0].add_prod(productions[0]); 
         
    a[0].closure(productions, prod_count);
    
    a[0].display_prods();
           
    fclose(fd);
    return 0;
}

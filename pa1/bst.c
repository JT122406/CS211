#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node* right;
    struct node* left;
};

typedef struct node node_data;

node_data *create_new_node(int value){
    node_data *result = malloc(sizeof(node_data));
    result->value = value;
    result->right = NULL;
    result->left = NULL;
    return result;
}

void insert_node(int val, node_data *header){
node_data *ptr = header;

while ((ptr->left != NULL) || (ptr->right != NULL))
{

    if (ptr->value == val)
    {
        printf("not inserted");
        printf("\n");
        return;
    }
    else if ((header->left == NULL) && (header->right != NULL) && (val < header->value))
    {
        break;
    }
    else if ((header->right == NULL) && (header->left != NULL) && (val > header->value))
    {
        break;
    }
    else if ((header->right == NULL) && (header->left == NULL))
    {
        break;
    }
    
    
    
    if ((ptr->value > val) && (ptr->left != NULL))
    {
        ptr = ptr->left;
        if ((ptr->value > val) && (ptr->left == NULL))
        {
            node_data *newn = create_new_node(val);
            ptr->left = newn;
            printf("inserted");
            printf("\n");
            return;
        } 
        else if ((ptr->value < val) && (ptr->right == NULL))
        {
            node_data *newn = create_new_node(val);
            ptr->right = newn;
            printf("inserted");
            printf("\n");
            return;
        }
        
    }
    else if ((ptr->value < val) && (ptr->right != NULL))
    {
        ptr = ptr->right;
        if ((ptr->value < val) && (ptr->right == NULL))
        {
            node_data *newn = create_new_node(val);
            ptr->right = newn;
            printf("inserted");
            printf("\n");
            return;
        }
        else if ((ptr->value > val) && (ptr->left == NULL))
        {
            node_data *newn = create_new_node(val);
            ptr->left = newn;
            printf("inserted");
            printf("\n");
            return;
        }
        
    }
}

//create new node
node_data *newn = create_new_node(val);
//position should be kept in pointer now just have to do a check and insert
    if ((ptr->value > val)) //place on left
    {
        ptr->left = newn;
        printf("inserted");
        printf("\n");
        return;
    }
    else if ((ptr->value < val)) //place on right
    {
        ptr->right = newn;
        printf("inserted");
        printf("\n");
        return;
    }
    
}

void search(int val, node_data *header){
    if (header == NULL)
    {
        printf("absent");
        printf("\n");
        return;
    }
    node_data *ptr = header;
    while (ptr->value != val)
    {
    if ((ptr->value > val) && (ptr->left != NULL))
    {
        ptr = ptr->left;
    }
    else if ((ptr->value < val) && (ptr->right != NULL))
    {
        ptr = ptr->right;
    }
    

    if (((ptr->left == NULL) && (ptr->value > val)) || ((ptr->right == NULL) && (ptr->value < val)))
    {
        printf("absent");
        printf("\n");
        return;
    }
    }
    printf("present");
    printf("\n");
}

node_data* delete(node_data *header, int val){

    if (header == NULL)
    {
        return header;
    }
    else if (val < header->value)
    {
        header->left = delete(header->left, val);
    }
    else if (val > header->value)
    {
        header->right = delete(header->right, val);
    }
    else
    {
        if (header->right == NULL)
        {
            node_data *hold = header->left;
            free(header);
            return hold;
        }
        else if (header->left == NULL)
        {
            node_data *hold = header->right;
            free(header);
            return hold;
        }
        node_data *low = header->right;
        while (low && low->left != NULL)
        {
            low = low->left;
        }
        header->value = low->value;
        header->right = delete(header->right, low->value);
        
    }
    return header;
}

void print(node_data *header){

if (header == NULL)
{
    return;
}
if (header != NULL)
{
    printf("(");
    if (header->left != NULL)
    {
        print(header->left);
    }
    printf("%d", header->value);
    if (header->right != NULL)
    {
        print(header->right);
    }
    printf(")");
}
}

void clean(node_data *ptr){
    if (ptr == NULL)
    {
        return;
    }
    if (ptr->right != NULL)
    {
        clean(ptr->right);
    }
    if (ptr->left != NULL)
    {
        clean(ptr->left);
    }
    free(ptr); 
}

int count(node_data *ptr, int num){
    if (ptr == NULL)
    {
        num++;
        return(num);
    }
    if (ptr->right != NULL)
    {
        num++;
        num = count(ptr->right,num);
    }
    if (ptr->left != NULL)
    {
        num++;
        num = count(ptr->left,num);
    }
    return(num); 
}

int main() {
char x;
int var;
node_data *head = NULL;
print(head);
int check = scanf(" %c ", &x);
while(((x == 'd')||(x == 'i')||(x == 's') || (x == 'p')) && (check != -1)){
if (x == 'd')
{
    scanf(" %d", &var);
    if (((head->left == NULL) && (head->right == NULL)) && (head->value == var))
    {
        head = NULL;
        printf("deleted\n");
    }
    else
    {
    int count1 = count(head, 0);
    delete(head, var);
    int count2 = count(head, 0);
    //printf("%d", count1);
    //printf("%d", count2);
    if (count1 <= count2)
    {
        printf("not deleted\n");
    }
    else if (count1 > count2)
    {
        printf("deleted\n");
    }
    }
}
else if (x == 'i')
{
    
    scanf(" %d", &var);
    if (head == NULL)
    {
        //head->value = var;
        head = create_new_node(var);
        printf("inserted");
        printf("\n");
    }else if (head->value == var)
    {
        printf("not inserted\n");

    }
    
    else
    {
    insert_node(var, head);
    }
}
else if (x == 's')
{
    scanf(" %d", &var);
    search(var, head);
}
else if (x == 'p')
{
    if (head == NULL)
    {
    printf("\n");
    }
    print(head);
    printf("\n");
}
check = scanf(" %c", &x);
}
clean(head);
}
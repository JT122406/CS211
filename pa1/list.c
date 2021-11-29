#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_data;

node_data *create_new_node(int value){
    node_data *result = malloc(sizeof(node_data));
    result->value = value;
    result->next = NULL;
    return result;
}

void delete_node(int val, node_data *header){
node_data *ptr = header;
node_data *ptr2 = header;
while (ptr->next != NULL)
{
 
    ptr = ptr->next; 
    if (ptr->value == val)
    {
	ptr2->next = ptr->next;
	break;
    }
	ptr2 = ptr2->next;   
}
}

void insert(node_data *newnode, node_data *previousnode){
newnode->next = previousnode->next;
previousnode->next = newnode;
}

void printlist(node_data *ptr){

       
    while (ptr->next != NULL)
    {

        printf(" ");
        printf("%d", ptr->next->value);

        
 
        ptr = ptr->next;
    }
}


void insert_node(int val, node_data *newn, node_data *header){

if(header->next == NULL){
//inserts into a blank list
header->next = newn;
return;
}
else if(header->next->value > newn->value)
{
//inserts if it belongs next to the header
newn->next = header->next;
header->next = newn;
return;
}

node_data *hold = header;
header = header->next;
while(header->next != NULL){

if((header->value > val) && (hold->value < val)){
insert(newn, hold);

return;
}
else if(header->value == val)
{
return;
}
header = header->next;
hold = hold->next;
}

if(header->value < val){
header->next = newn;

return;
}

}

int main(){
node_data *head = malloc(sizeof(node_data));
char x;
int var;
int check = scanf(" %c %d", &x, &var);
//printf("\n");

while(((x == 'd')||(x == 'i')) && (check != -1)){
if(x == 'i')
{
insert_node(var ,create_new_node(var), head);
}else{
delete_node(var, head);
}
//Print and count
node_data *ptr = head;
int count = 0;

while(ptr->next != NULL)
{    
    ptr = ptr->next;
    count++;
}

printf("%i",count);
printf(" :");
printlist(head);
printf("\n");
scanf("\n");
check = scanf(" %c %d", &x, &var);

}
free(head);



}
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This represents a node in the list 
 * Allocate a new node as follows
 * node * new_node = malloc(sizeof(node));
 */
typedef struct node_t
{
	char data[3];
	struct node_t *next;
} node;

/* Linked List holding references to head and tail of the list*/
typedef struct linked_list_t
{
	node *head,* tail;
} linked_list;


node * compare_LL(linked_list * dna ,linked_list * gene , node * current)
{
    node * ptr1, *ptr2;
    ptr1=current;
    ptr2=gene->head;
    while(ptr2!= NULL)
    {
        if(strcmp(ptr1->data,ptr2->data))
        {
            return NULL;
        }
        else
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return ptr1;
}

node * traverse_prev(linked_list * list,int i)
{
    int count=0;
    node * present = list->head;
    while(present!=NULL)
    {
        if(i==count)
        {
            return present;
        }
        present = present->next;
        count++;
    }
    return NULL;
}


void fix_dna_sequence(linked_list * dna_sequence, linked_list *gene_sequence)
{
  //Add your code here.
  //Search for defective gene sequence in the dna_sequence
  //and remove the gene_sequence from the dna_sequence
    node * prev, *current, *last;
    int count=0;
    current=dna_sequence->head;
    while(current!=NULL)
    {
        if(!strcmp(current->data,gene_sequence->head->data))
        {
            last=compare_LL(dna_sequence,gene_sequence,current); 
            if(last!=NULL)
            {
                if(current==dna_sequence->head)
                {
                    dna_sequence->head=last;
                    
                }
                else
                {
                    prev=traverse_prev(dna_sequence, count-1);
                    prev->next=last;
                }
                current=last;
            }
            else
            {
                current=current->next;
                count++;
            }
        }
        else
        {
            current=current->next;
            count++;
        }      
    }
  
}



void list_init(linked_list **list)
{
	*list = malloc(sizeof(linked_list));
	(*list)->head = NULL;
	(*list)->tail = NULL;
}

int add(linked_list *list, char *item)
{
	node *new_node= (node*)malloc(sizeof(node));	
	strcpy(new_node->data,item);
	new_node->next = NULL;

	if(list->head == NULL)
	{
		list->head=new_node;
		list->tail=new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}

	return 0;
}


void list_display(linked_list *list)
{
	node *current=list->head;
	printf("List : ");
	while(current!=NULL)
	{
		printf("%s,",current->data);
		current = current->next;
	}
	printf("\n");
}




char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    
    char* data = malloc(alloc_length);
    
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        
        if (!line) {
            break;
        }
        
        data_length += strlen(cursor);
        
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }
        
        alloc_length <<= 1;
        
        data = realloc(data, alloc_length);
        
        if (!data) {
            data = '\0';
            
            break;
        }
    }
    
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        
        data = realloc(data, data_length);
        
        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);
        
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }
    
    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }
    
    if (!*str) {
        return str;
    }
    
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    
    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
    
    if (!*str) {
        return str;
    }
    
    char* end = str + strlen(str) - 1;
    
    while (end >= str && isspace(*end)) {
        end--;
    }
    
    *(end + 1) = '\0';
    
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    
    return value;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);
    
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
   }
   return value;
}

int main(int argc, char * argv[])
{
    linked_list *dna_sequence;
    linked_list *gene_sequence;
    list_init(&dna_sequence);
    list_init(&gene_sequence);
  
    int l_dna_sequence= parse_int(ltrim(rtrim(readline())));
    for (int i = 0; i < l_dna_sequence; i++) {
        char * l_item = ltrim(rtrim(readline()));
        
        add(dna_sequence, l_item);
    }
    int l_gene_sequence= parse_int(ltrim(rtrim(readline())));
    for (int i = 0; i < l_gene_sequence; i++) {
        char * l_gene = ltrim(rtrim(readline()));
        
        add(gene_sequence, l_gene);
    }
    
    //printf("Input DNA Sequence ");list_display(dna_sequence);
    //printf("Input Gene Sequence ");list_display(gene_sequence);
    fix_dna_sequence(dna_sequence,gene_sequence);
    printf("Corrected DNA Sequence ");list_display(dna_sequence);
    
    return 0;
}

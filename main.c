#include <stdio.h>
#include <stdlib.h>

FILE *fl;

typedef struct stack
{
 int elem;
 struct stack* next;
};

typedef struct stack Stack;
Stack* top = NULL; 
Stack* base = NULL;

Stack* CreateNode()
{
   Stack* pt = (Stack*)malloc(sizeof(Stack));
   if(pt != NULL)
       return pt;
   return NULL;
}

int EmptyStack()
{
  if (top == NULL)
   return 1;
  else
   return 0;
}



void InsertElement()
{
int elem;
Stack* x;
 if (EmptyStack())
 {
   x = CreateNode();
   printf("Type the value to be inserted\n");
   scanf("%d",&elem);
   x->elem = elem;
   x->next = NULL;
   top = x;
   base = x;
 }
 else
 {
   x = CreateNode();
   printf("\nType the value to be inserted\n");
   scanf("%d",&elem);
   x->elem = elem;
   x->next = top;
   top = x;
 }
}

void RemoveElement()
{
  int elem;
  Stack* x;
  Stack* y;
  if (EmptyStack())
   {
   	printf("\nEmpty stack.\n");
   	return;
   } 

   x=top;
   
   if (x->next == NULL)
   {
   	 printf("Element %d removed\n",x->elem);
	 top = NULL;
	 free(x);
   } 
   else
   {
   	y = x->next;
	printf("Element %d removed\n",x->elem);
	top = y;
	free(x);
   } 
  return;
}



void CheckElement()
{
  Stack* x = top;
  int num, count = 0;
  
  printf("What element are you looking for?\nElement: ");
  scanf("%d",&num);
  
  if(x != NULL){
  	
  	while(x != NULL){
  		if(x->elem == num){
  			printf("\nElement foud!\n");
  			count++;
		  }

		  x = x->next;
		  
	  }
	  if(count == 0){
	  	printf("\nElement NOT found!\n\n");
	  }
	  
  	
  }else{
  	printf("\nthe stack is empty!\n");
  }
  
}

int Quantity()
{
  Stack* x = top;
  int qtd = 0;
  
  while(x != NULL){
  	qtd++;
  	x = x->next;
  }

  printf("\nQuantity of element in the stack: %d\n\n",qtd);
}


void SummingElements()
{
  Stack* x = top;
  int sum;
  
  if(x != NULL){
  	while(x != NULL){
  	sum += x->elem;
  	
  	x = x->next;
  }
  
  printf("\nSum of the elemenst in the stack: %d \n\n",sum);
  }else{
  	printf("\nThe stack is empty!\n");
  }
  
}
void BiggestElement()
{
  Stack* x = top;
  int biggest_value;
  
  if(x != NULL){
  	
  	biggest_value = x->elem;
  	
  	while(x != NULL){
  		if((x->elem) > biggest_value ){
  			biggest_value = x->elem;
		  }
		  
		  x = x->next;
		  
	  }
	  
	  printf("\nBiggest element in the stack: %d\n\n",biggest_value);
  	
  }else{
  	printf("\nThe stack is empty!\n");
  	
  }
  
}

void PrintStack()
{
  int i;
  Stack* x;
  x = top;
  if (EmptyStack())
    printf("The stack is empty!\n");
  else
  {
   while(x!= NULL)
   {
  	 printf("%d -",x->elem);
  	 x = x->next;
   }	
  printf("\n\n");
}
}

int main() {
int opt;
Stack* no;
top = NULL;
while (1)
{
  printf("\n1- To insert an element in the stack\n");
  printf("2- To get the size of the stack\n");
  printf("3- To remove an element from the stack\n");
  printf("4- Check an element in the stack\n");
  printf("5- Sum the elements in the stack\n");
  printf("6- To get the biggest value in the stack\n");
  printf("7- To print the stack\n");
  printf("8- To finish the program\n");
  printf("Choice: ");
  scanf("%d", &opt);
  switch (opt)
  {
  	case 1: InsertElement();
  	         break;
  	case 2: Quantity();
  	         break;
  	case 3: RemoveElement();
  	         break;  
	case 4: CheckElement();
  	         break; 
  	case 5: SummingElements();
  	         break;
  	case 6: BiggestElement();
  	         break;
	case 7: PrintStack();
	        break;
	case 8: exit(0);
  }
}	
	return 0;
}

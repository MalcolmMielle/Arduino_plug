#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getID(char order[], int size);
char* getOrder(char order[], int size);
void doWorktest(int id, char* order[]);
int getAllInfo(char order[], int size, int* id, char* order_out[]);


/* get the id and order as an int and a char**) */
int getAllInfo(char order[], int size, int* id, char* order_out[]){
	*id = getID(order,size);
	printf("working on order : %s, with id %d ", order, *id); 
	*order_out=getOrder(order, size);
	printf("and in the end order %s\n",*order_out);

	return 1;
}

/*get the id in the order. Return -1 if failed*/
int getID(char order[], int size){
	int i=0;
	for(i=0;i<size-1;i++){
		char tmp=order[i];
		if(strchr(";",tmp)){
			char end[]="";
			return atoi(strncat(end,order,i+1));
		}
	}
	return -1;
}


//TODO conditionnal jump here ! Only whn returning from the function
char* getOrder(char order[], int size){
	int i=0;
	char copy[size];
	strcpy(copy, order);

	char* res;

	printf("\nstr: %s\n", copy);
	res=strtok(copy,";");
	if (res == NULL){ /* always check the return value from strtok */
        return NULL;
    }
	printf("tok : %s\n", res);
	res=strtok(NULL, ";");
	if (res == NULL){ /* always check the return value from strtok */
        return NULL;
    }
	printf("tok : %s\n", res);	
	return order + (res - copy); //move by offset
}

void doWorktest(int id, char* order[]){
	if(!strcmp(*order, "on")){
		printf("Lights on mhterfucker !");
	}
	else if(!strcmp(*order, "off")){
		printf("Lights off. Greener planet today");
	}
	else{
		printf("Did not find a good looking order for ya.");
	}
}


#include "libplug.h"


int main (int argc, char *argv[]){

	/*Test get ID
	char name[] = "12;ononon";
	printf("yo \n");
	printf("final : %d\n", getID(name, sizeof(name)));
	printf("New round\n");
	if(getID(name, sizeof(name))==12){
		printf("Good\n");
	}
	else{
		printf("Nope\n");
	}
	
	char* res= NULL;
	getOrder(name, sizeof(name), &res);
	printf("At the end : %s\n",res);
	printf("%d\n",strcmp(res,"ononon"));*/
	
	
	printf("****************************************************************\n\n");
	
	char name2[] = "2;on";
	char* buffer = NULL;
	char* ord=NULL;
	int num = 0;

	//printf("the order V1 is %s\n", getOrder(name2, strlen(name2), &ord));
	
	getAllInfo(name2, sizeof(name2), &num, &buffer);
	
	printf("the id : %d = 2 and the order %s = off\n", num, buffer);
	
	printf("ouais %d\n",strcmp(buffer, "on"));
	doWorktest(num, &buffer);
	/*
	char na[] = "2;on";
	char* bu="on";
	
	//TODO Do conditionnal jump
	bu=getOrder(na, 5);
	
	//TODO Doesn't conditionnal jump
	//char copy[strlen(na)];
	//strcpy(copy, na);
	
	//bu=strtok(na,";");
	
	//bu[2]='\0';
	
	printf("ending : %s\n",bu);
	printf("the order at the end %s", na);*/
	
	
	
}

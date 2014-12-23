#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"
#include "libplug.h"

RF24 radio(9,10);

byte addresses[][6] = {"addr1", "mysel"};
char* ack="OK";
//Equivalences between the number of the plug and the arduino pin associated
int pin_table[6]={1, 2, 3, 4, 5, 6};

/********************µµActual function*********************/
int doWork(int id, char* order[]){
        //Converting the id number into the pin numbers
        int pin=pin_table[id];
  
	if(!strcmp(*order, "on")){
		printf("Lights on mhterfucker !");
                digitalWrite(pin, HIGH);
	}
	else if(!strcmp(*order, "off")){
		printf("Lights off. Greener planet today");
                digitalWrite(pin, LOW);
	}
	else{
		printf("Did not find a good looking order for ya.");
	}
}


void setup(){
	Serial.begin(57600);
	printf("Arduino plug started");
	
	//Setup the nrf
	radio.begin();
	radio.setAutoAck(1);
	//Set acknoledgement
	radio.enableAckPayload();
	radio.setRetries(15, 15);
	radio.openWritingPipe(addresses[1]);
	radio.openReadingPipe(1,addresses[0]);
	radio.startListening();
	radio.powerUp();
	radio.printDetails();
}

void loop(){

	//Init receiving variable
	char* order;
	if(!radio.available()){
	
	}
	else{
                byte pipeNo;
		while(radio.available(&pipeNo)){
			radio.read(order, radio.getPayloadSize());
			radio.writeAckPayload(pipeNo, ack, strlen(ack));
			printf("Got a response ");
			printf(order);
                        
                        //Got an order, now doing something
                        int num=0;
                        char* buffer=NULL;
                        getAllInfo(order, strlen(order), &num, &buffer);
                        
                        //Using the actual order
                        doWork(num, &buffer);
		}
	}
}




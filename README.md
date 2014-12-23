Arduino_plug
============

Based on the NRF24 library.

Order must be like follow : "[plug_number];[order]".

The actual function to do the job is 
```C
doWork(number_of_the_plug : int, order : char**)
```

To retrieve the information from the order as received from the NRF just use the function `getAllInfo`

List of all orders understood
=============================

pin number are in the pin_table table and must be completed accordingly. Element 1 is plug number 1 and is associated to the digital pin that is in the table.

 - on : if a pin number is associated, the corresponding relay is turned on. If no number of pin is associated (meaning the number is either less than 0 or above the size of pin_table) all relays are turned on.
 - off : if a pin number is associated, the corresponding relay is turned off. If no number of pin is associated (meaning the number is either less than 0 or above the size of pin_table) all relays are turned off.
 
 If the order is not understood nothing happen and a error message is printed.


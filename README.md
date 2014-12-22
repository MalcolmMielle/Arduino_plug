Arduino_plug
============

Based on the NRF24 library.

Order must be like follow : "[plug_number];[order]".

The actual function to do the job is 
```C
doWork(number_of_the_plug : int, order : char**)
```

To retrieve the information from the order as received from the NRF just use the function `getAllInfo`



/** I N C L U D E S **************************************************/
#include <p18f45k20.h>


void main (void)
{
   // unsigned char brightness = 64; // = 0x7D
     unsigned char   dc ;
     unsigned int i;
     unsigned int percentage;        
     unsigned int light = 128*(percentage/100);
     void initpwm();
  
    while(1)
    {

        
        
       for(dc = 0 ; dc < 128 ; dc++)
                        {
                       for(i=0;i<1000;i++){
                                CCPR1L = dc ;
                           }
                         if(dc<1){
                          
                           for(i=0;i<30000;i++){
                                CCPR1L = dc ;
                           }
                       } 

                     
                        
                       if(dc<45){
                          
                           for(i=0;i<1000;i++){
                                CCPR1L = dc ;
                           }
                       } 
       
                     
                        }
       
       
                for(dc = 127 ; dc > 0 ; dc--)
                        {
                           for(i=0;i<1000;i++){
                                CCPR1L = dc ;
                           }
                    if(dc>114){
                          
                           for(i=0;i<10000;i++){
                                CCPR1L = dc ;
                           }
                       } 
                         if(dc>115){
                        for(i=0;i<1000;i++){
                                CCPR1L = dc ;
                       } 
                
                      
             
                        } 
                }
 
        
        
        
        
        

    };    	
}


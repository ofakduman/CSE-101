;factoriyel calculate: 
	
	load R1,5;
	load R2,1;
	load R3,2;
	load R4,3;
	load R5,4;
	load R6,5;
	load R7,48; This load is for show on display(result of (1!,2! and 3!)), I calculated in decimal so I will use them in end adress. 
	load RA,24; To check result of 4! (24=RE) in adress equal4, and to find 120 in fac5(24x5)
	load RB,120;To check result of 5! (120=RE) in adress equal5

	move R0,R1; Thanks to this command I able to use R0.
	
	jmpEQ R2=R0, fac1; 
	jmp facA


fac1: addi RE,RE,R1;
	jmpEQ R2=R0,end; R2=1,R0=1 so go to end
	jmp Error


facA: jmpEQ R3=R0, fac2; 
	jmp facB

fac2:	
	addi RE,RE,R1   ;
	jmpEQ R2=R0, end
	jmp Error


facB:	jmpEQ R4=R0, fac3
	jmp facC


fac3:	addi RE,RE,R3; Now we calcula 2X3 so i will calculate like : +2, +2, +2
	addi R8,R2,R8;  This is for calculate loops time, 
	jmpEQ R8=R0, end; If we have 3 times 2 its ok and the result is 6, we found result in decimal
	jmp fac3 ;its looping

facC:	addi R9,R9,R4
	addi R9,R9,R4     ;I want to calculate 4!=3X6 so I need to find 6 in adress fac4
      jmpEQ R5=R0, fac4
	jmp facD
fac4: 
      addi RE,RE,R9; Now we can calcula 6X4 
	addi R8,R8,R2; This is for calculate loops time,
	jmpEQ R8=R0, equal4; At the end we will find the result=24 but if I want to show on display I should some operation in adress end2.
	jmp fac4
equal4: move R0,RE      ; 
       jmpEQ RA=R0, end2 ;to check 24=R0
	 jmp Error
facD:   jmpEQ R6=R0, fac5
	jmp Error

fac5:	addi RE,RA,RE; in decimal 5! is 24X5
	addi R8,R8,R2;
	jmpEQ R8=R0,equal5;to check 120=R0 
      jmp fac5; this provide 24x5
equal5:move R0,RE;by the calculation ( in fac5) RE must be 120 , to check i moved RE to R0
	jmpEQ RB=R0, end3;we have to check our result if its 120 calculation is right
	jmp Error

Error:load    R1,Text2     ;			   
         load    R2,1        ;
         load    R0,0        
loops:   load    RF,[R1]     
         addi    R1,R1,R2
         jmpEQ   RF=R0,finish1 
         jmp     loops   
finish1:   halt
Text2:    db      10
         db      "Error",10




	
end:	addi RE,R7,RE;Before the show result, if we want to show the result on display we have to add 48
	move RF,RE
	halt

end2:    load    R1,texxx     ;we found result in decimal (24) 			   
         load    R2,1        ;to show in display we can create text and use it.
         load    R0,0        
results:   load    RF,[R1]     
         addi    R1,R1,R2
         jmpEQ   RF=R0,finish2
         jmp     results   
finish2:   halt
texxx:    db      10
         db      "24",10



end3:    load    R1,Text33    ;we found result in decimal (120) [in fac5]			   
         load    R2,1        ;to show in display we can create text and use it.
         load    R0,0        
loop2:   load    RF,[R1]     
         addi    R1,R1,R2
         jmpEQ   RF=R0,Ready1
         jmp     loop2    
Ready1:  halt


Text33:    db      10
         db      "120",10
      

                  

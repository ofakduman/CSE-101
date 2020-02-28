




load     R1,Text             ;Firstly, we write text in main memory
         load    R2,1        ;we will use it for increase step. 
         load    R0,0        ;this command actually not neccessary but i want to show it.
	 load    R3,[R1]     ;this command loaded first character value of text, in R3 to use it then.    
         addi    R1,R1,R2    ;this command is increases step.For change the character of text.
         jmpEQ   R3=R0,Ready ;if there is no character in text , its finished already so halted.
         load    R4,[R1]     ;this command for the second character of text.
	 addi    R1,R1,R2    ;this command is increas step.
	 jmpEQ   R4=R0,Ready ;if there is no second character, the program will go to second operation"Ready"
	 load    R5,[R1]     ;these commands are repeated until another operation,"Ready"
         addi    R1,R1,R2    
         jmpEQ   R5=R0,Ready
	 load    R6,[R1]     
         addi    R1,R1,R2    
         jmpEQ   R6=R0,Ready
	 load    R7,[R1]     
         addi    R1,R1,R2    
         jmpEQ   R7=R0,Ready
	 load    R8,[R1]     
         addi    R1,R1,R2    
         jmpEQ   R8=R0,Ready
         load    R9,[R1]     
         addi    R1,R1,R2    
         jmpEQ   R9=R0,Ready
         load    RA,[R1]     
         addi    R1,R1,R2    
         jmpEQ   RA=R0,Ready
         load    RB,[R1]     
         addi    R1,R1,R2    
         jmpEQ   RB=R0,Ready
         load    RC,[R1]     
         addi    R1,R1,R2    
         jmpEQ   RC=R0,Ready
         load    RD,[R1]     
         addi    R1,R1,R2    
         jmpEQ   RD=R0,Ready 
                              ;First part is OK,"I loaded in register the all of character's value", Now 2nd part stars
         

Ready:   move    RF,RD     ;if we move to any values of character, RF, display is showed us this values of character. And if We replace reversed in RF display will show us to reserve string.
	 move    RF,RC     ; I used the move command instead of the load command because it didnt work. I dont know, maybe i did some mistakes.          
	 move    RF,RB
         move    RF,RA
         move    RF,R9
         move    RF,R8
         move    RF,R7
         move    RF,R6
         move    RF,R5
         move    RF,R4
         move    RF,R3
         

Text:    db      10
         db      "test",10


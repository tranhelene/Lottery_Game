/*	   	 		  	   	 			 	  	 		 	*
 * ADD YOUR STANDARD SUBMISSION INFORMATION HERE	  	*
 * NAME: Helene Tran 				   		 	 	 	*   	  	   	
 * EMAIL: htran31@student.ubc.ca	 	   	  		   	*  		  			 	*
 * DATE: December 18, 2023	  		 		 	  	   	* 	  	   	 	
 *	   	   	   	 	 			   	  		   	 	 	*/


//symbolic constants for INPUT/OUTPUT pins
int const A = 11;
int const B = 10;
int const C = 7;
int const D = 8;
int const E = 9;
int const F = 12;
int const G = 13;
int const H = 6;
int const start = 5;
int const clear = 4;

// define any function(s), constants required to implement your program
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void off();

// initialization

void setup(void){
  
  //digital I/O pins mode setup
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(start, INPUT);
  pinMode(clear, INPUT);
  
  randomSeed(analogRead(0));
}


void loop(void){
  int count;
  int num;
  unsigned long startTime = millis();
  unsigned long endTime = millis();
  
  if(digitalRead(start) == HIGH) {        //check if start button was pressed
    startTime = millis();
    
    if(digitalRead(start) == LOW) { 
      endTime = millis();
      
      if(millis() > 200) {            //check if  start button was pressed for more than 200 ms
		for(count = 1; count <= 10; count++) { //10 random numbers
          num = random(0,10);
        
          if(num == 0) {
            zero();
    	  }
          else if(num == 1) {
            one();
          }
          else if(num == 2) {
            two();
          }
          else if(num == 3) {
            three();
          }
          else if(num == 4) {
            four();
          }
          else if(num == 5) {
            five();
          }
          else if(num == 6) {
            six();
          }
          else if(num == 7) {
            seven();
          }
          else if(num == 8) {
            eight();
          }
          else {
            nine();
          }
      
          if(count < 10) {        //if not the 10th number, delay for shorter time
            delay(300);
            off();
            delay(400);
          }
        }
      }
    }
  }
  if(digitalRead(clear) == HIGH) {     //check if clear button was pressed
    startTime = millis();
    
    if(digitalRead(clear) == LOW) {
      endTime = millis();
      
      if(millis() > 100) {        //check if clear button was pressed for more than 100 ms
        off();
      }
    }
  }
}

void zero(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);
}

void one(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

void two(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void three(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void four(){
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void five(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void six(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void seven(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);  
}

void eight(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void nine(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(H, LOW);  
}

void off() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(H, LOW);
}

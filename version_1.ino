#define SEED A0
#define BUTTON 2

#define A  5
#define B  6
#define C  8
#define D  9
#define E  10
#define F  4
#define G  3
#define DP 7

#define ON  1
#define OFF 0


int HMN=0;
int array[9];
int Rnumber=0;
bool ItIsNotThere = false;
bool v_last=LOW;


void setup()
{
  pinMode(SEED, INPUT);
  pinMode(BUTTON, INPUT);
  
  randomSeed(analogRead(SEED));
  
  Serial.begin(9600);
  
  for(int i = 0; i < 9; i++){
    array[i] = 0;
  }      
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
 }

void SetLEDs(int a, int b, int c, int d,int e, int f,int g, int dp){
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
  digitalWrite(E, e);
  digitalWrite(F, f);
  digitalWrite(G, g);
  digitalWrite(DP, dp);
}

void ONE()
{SetLEDs(OFF,ON,ON,OFF,OFF,OFF,OFF,OFF);}
 
void TWO()
{SetLEDs(ON,ON,OFF,ON,ON,OFF,ON,OFF);}
 
void THREE()
{SetLEDs(ON,ON,ON,ON,OFF,OFF,ON,OFF);}
 
void FOUR()
{SetLEDs(OFF,ON,ON,OFF,OFF,ON,ON,OFF);}
 
void FIVE() 
{SetLEDs(ON,OFF,ON,ON,OFF,ON,ON,OFF);}
 
void SIX()
{SetLEDs(ON,OFF,ON,ON,ON,ON,ON,OFF);}
 
void SEVEN()
{SetLEDs(ON,ON,ON,OFF,OFF,OFF,OFF,OFF);}
 
void EIGHT()
{SetLEDs(ON,ON,ON,ON,ON,ON,ON,OFF);}
 
void NINE()
{SetLEDs(ON,ON,ON,ON,OFF,ON,ON,OFF);}

void ALLOFF()
{SetLEDs(OFF,OFF,OFF,OFF,OFF,OFF,OFF,OFF);}

int GetNewRNumber(){
  	int Number = 0;
    ItIsNotThere = false;
    while(ItIsNotThere == false){
    	
        Number=random(1,10);
        if(array[Number-1] == 0){
          	array[Number-1] = Number;
            ItIsNotThere = true;
        }
    }  	
  return Number;

}

void ResetGame()
{
  for(int i = 0; i < 9; i++){
    array[i] = 0;
  }
  Rnumber = 0;
  HMN = 0;
  ALLOFF();
  Serial.println("New Game Started");  
}


void loop()
{

  if(HMN < 5){
	
  	if(DebouncedPushButton(BUTTON) == HIGH){
    	HMN++;
  		Rnumber=GetNewRNumber();
		Serial.println(Rnumber);
		WriteNumberToDisplay(Rnumber);
    }
  }
  else{

    Serial.println("Winner Numbers:");
    for(int i = 0; i < 9; i++){
      if(array[i] != 0){
        Serial.println(array[i]);
      }
    }
     delay(2000);//To keep the last number displayed for 2 sec
     ResetGame();
  }

}

bool DebouncedPushButton(int pin){ 
  if(v_last == LOW && digitalRead(pin) == HIGH){
  	unsigned long StartMillis = millis();
    while((digitalRead(pin) == HIGH)){
      if(millis()-StartMillis > 50){
      	v_last = HIGH;
        return HIGH;}
    }
  }
  if( digitalRead(pin) == LOW){
      	v_last=LOW;}
  
return LOW;
}

void WriteNumberToDisplay(int number){
      	switch (number) {
 		case 1:
    		ONE();
    	break;
          
  		case 2:
    	 	TWO();
   		break;
          
        case 3:
    	 	THREE();
   		break;

        case 4:
    	 	FOUR();
   		break;
        
        case 5:
    	 	FIVE();
   		break;
        
        case 6:
    	 	SIX();
   		break;
        
        case 7:
    	 	SEVEN();
   		break;
        
        case 8:
    	 	EIGHT();
   		break;
        
        case 9:
    	 	NINE();
   		break;
  		
        default:
    	break;
		}
}
  

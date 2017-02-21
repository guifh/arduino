/*************************************************************
/Code for DIY photo stack with a 1-Channel DC Motor
/*************************************************************/

int motordirection = 12;
int motorbrake = 9;
int motorspeed = 3;
int camera = 13;
int button = 2;

void setup() {
 
  //Setup Channel A
  pinMode(motordirection, OUTPUT);  //Initiates Motor Channel A pin
  pinMode(motorbrake, OUTPUT);      //Initiates Brake Channel A pin
  pinMode(camera, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}


void loop(){

  boolean buttonState = digitalRead(button);
  Serial.print("Button State ");
  Serial.println(buttonState);
  delay(100);

  if(buttonState==HIGH){

  int myCount = 0;
  
  while(myCount < 5){                      //how many photos

  Serial.print("Photo Stack ");
  Serial.println(myCount);
  
  //forward @ full speed
  digitalWrite(motordirection, HIGH);   //Establishes forward direction of Channel A
  digitalWrite(motorbrake, LOW);        //Disengage the Brake for Channel A
  analogWrite(motorspeed, 255);         //Spins the motor on Channel A at full speed
  
  delay(100);                            //distance
  
  digitalWrite(motorbrake, HIGH);       //Engage the Brake for Channel A
  delay(100);
  digitalWrite(camera, HIGH);
  delay(200);
  digitalWrite(camera, LOW);
  delay(200);                           //stop after move 

  myCount = myCount + 1;
  }

  //backward @ half speed
  digitalWrite(motordirection, LOW);    //Establishes backward direction of Channel A
  digitalWrite(motorbrake, LOW);        //Disengage the Brake for Channel A
  analogWrite(motorspeed, 255);         //Spins the motor on Channel A at half speed
  
  delay(100*myCount);                            //distance backwards
  
  digitalWrite(motorbrake, HIGH);  
  delay(100);
  
  myCount = 0;
 
  }
}


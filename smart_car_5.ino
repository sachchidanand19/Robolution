 char t;
int d1=2;
int d2=4;
int en1=5;
int en2=6;

 
void setup() {
  Serial.begin(9600);
  
  pinMode(d1,INPUT);
  pinMode(d2,INPUT); 
   pinMode(en1,OUTPUT);
   pinMode(en2,OUTPUT);
pinMode(9,OUTPUT);   
pinMode(10,OUTPUT);   
pinMode(11,OUTPUT);  
pinMode(12,OUTPUT); 
pinMode(13,OUTPUT);
 
 

 
}
 
void loop() {
  digitalWrite(13,LOW);
  
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == '1'){       
 forward();
}
 
else if(t == '2'){      
 back();
 
}
 
else if(t == '3'){      
right();
}
 
else if(t == '4'){     

 left();
}
 
else if(t == '5'){     
  Wait();
}

else if(t == '6'){   
     Serial.print("f");     
ir();
digitalWrite(13,HIGH);
}



delay(90);
}



void ir() {

 if((digitalRead(d1)==HIGH) && (digitalRead(d2)==HIGH)){
    forward();
      Serial.print("forward");     

    delay(10);
  }
  else if((digitalRead(d1)==LOW) && (digitalRead(d2)==HIGH)){
    left();
      Serial.print("left");     

    delay(10);
  }
  else if((digitalRead(d1)==HIGH) && (digitalRead(d2)==LOW))
  { 
    right();
    delay(10);
      Serial.print("right");     

    }
    else 
Wait();


   
}



void forward(){
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  analogWrite(en1,150);
    
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
 analogWrite(en2,150);
}

void back(){
 digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  analogWrite(en1,120);
  
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
   analogWrite(en2,120 );
 
  }
  
void left(){
 digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
   analogWrite(en1,80);
   
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  analogWrite(en2,100);
}
void right(){
   digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
   analogWrite(en1,100);
   
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
 analogWrite(en2,80);
}
void Wait(){
   digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
   analogWrite(en1,0);
    analogWrite(en2,0);
    digitalWrite(13,LOW);
} 

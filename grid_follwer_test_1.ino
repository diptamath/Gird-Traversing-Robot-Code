int c=0;
int x1=; 
 
int x2= ;
int y1= ;
int y2= ;
int h=12;
float d=1;

int r;
#define leftCenterSensor 3
#define leftNearSensor 4
#define leftFarSensor 5
#define rightCenterSensor 2
#define rightNearSensor 
#define rightFarSensor 
int rightFarSensor=
int leftFarSensor=
int ping=
int ping1=
int ping2=
int pingpin=
int pingpin1=
int pingpin2=

#define pick1 6
#define pick2 7




void setup() {
 Serial.begin(9600);
 pinMode(leftMotor1, OUTPUT);
pinMode(leftMotor2, OUTPUT);
pinMode(rightMotor1, OUTPUT);
pinMode(rightMotor2, OUTPUT);
 pinMode(pick1, OUTPUT);
  pinMode(pick2, OUTPUT);



}

void loop() {
  if(c==0)
  {
    if(x2>=x1)
    {
      lr1();
      d=1;
      while(e!=1)
      {
        str();
        avoid();
        x1=upd(x1,y1,d);
        e=check(x2,0,x1,y1);
      }

       hault();
       ll1();
       
    }

          else if(x1>x2)
          {
            ll1();
            d=2;
            while(e!=1)
      {
        str();
        avoid();
        x1=upd(x1,y1,d);
        e=check(x2,0,x1,y1);
      }

       hault();
       lr1();
            
          }

      d=3;                      
     while(e!=1)
      {
        str();
        avoid();
        x1=upd(x1,y1,d);
        e=check(x2,y2,x1,y1);
      }

      hault();
      delay(100);
      c=1;
      
    
  }

  else if(c==1)
  {
    if(objtr(1,1)==1 && s!=0)
{
  d=getdis();
  if(d<15)
  {
    str();
    delay(20);
    hault();
    pick();
    rev();
    delay(20);
    relis();
    dealy(1000);
      }
}

else if(objtr(2,(10-x2))==1)
{
  ll1();
  k=1;
  scan(10,x1,x2,y2,k);
  x1=10;
  backreach(x1,y1,x2,y2,k);
  lr1();
  k=4;
  
}
 else if (objtr(3,x2)==1)
{
  lr1();
  k=2;
  scan(0,x1,x2,y2,k);
  x1=0;
   backreach(x1,y1,x2,y2,k);
  ll1();
  k=4;
  
}
else if(s!=0)
{
  k=4;
  reach(x1,y1,x2,(y2-1),k);
  s++;
  y1--;
  
w=1;
    
  }
  else if(w==1){
  while(y1!=Y2)
  {
    backreach(x1,y1,x2,y2,k);
    c=3;
  }
}




    
  }


  if(c==3)
{
  lr1();
  k=2;
  reach(0,y1,x2,y2,k);
  while(x1!=10)
  {
    if(objtr(r)==1)
    {
      hault();
      lr1();
      k=4;
    scan1(x1,y1,x1,0,k);
    }
    backreach(x1,y1,(x1+1),y1,k);
    x1++;
  }
  reach(x1,y1,x2,y2,k);
}


}

 void avoid()
 {
  int d;
  d=getdis();
      if(d<=h)
      {
        hault();
        pick();
        lr2();
        rev();
        relis();
      }

 }


 

void getdis()
 {
 long duration, cm;

 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);


 pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm=duration/29/2;
  if(cm=<15)
  {
  return cm;
  }
  else 
  {
    return 100;
  }
  
 }




 void objtr(int c,int r)
 {
 long duration, cm;

 if(c==1)
 {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);


 pinMode(ping, INPUT);
  duration = pulseIn(ping, HIGH);
  cm=duration/29/2;
  if(cm=<(15*r)
  {
  return 1;
  }
  else 
  {
    return 0;
  }
 }

 if(c==2)
 {
    pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);


 pinMode(ping1, INPUT);
  duration = pulseIn(ping1, HIGH);
  cm=duration/29/2;
  if(cm=<15*r)
  {
  return 1;
  }
  else 
  {
    return 0;
  }
  
 }

 if(c==2)
 {
    pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);


 pinMode(ping2, INPUT);
  duration = pulseIn(ping2, HIGH);
  cm=duration/29/2;
  if(cm=<15*r)
  {
  return 1;
  }
  else 
  {
    return 0;
  }
  
 }
 
 
 }


void scan(int x1,int y1,int x2,int y2,int k)
{
  int  d,p,t=10;
  while(x1!=x2)
  {
    d=getdis();
    if(d=<t)
    {
      pick();
      backreach(x1,y1,x2,y1,k);
      p=y1;
      if(y1!=y2)
      {
        k=4;
        if(k==1)
        {
          lr1();
        }
        else
        {
          ll1();
        }
        backreach(x1,y1,x2,y2,k);
        relis();
        delay(100);
        reach(x1,y1,x2,p,k);
        if(x2==0)
        {
          k=2;
          lr1();
        }
        else{
          k=1;
          ll1();
          
                       
        }
      }
    
    }
}










void scan1(int x1,int y1,int x2,int y2,int k)
{
  int  d,p,t=10;
  while(y1!=n)
  {
    d=getdis();
    if(d=< t)
    {
      pick();
      backreach(x1,y1,x1,y2,k);
      p=y1;
     
      ll1();
     if(x1<x2)
     {
        backreach(x1,y1,x2,y2,k);
        relis();
        delay(1000);
        reach(x1,y1,x1,y2,k);
        lr1();
     }
     else if(x1>x2)
     {
        reach(x1,y1,x2,y2,k);
        relis();
        delay(1000);
        reach(x1,y1,x2,p,k);
        lr1();
     }
     else if(x1==x2)
     {
      relis();
      delay(1000);
     lr1();
     }
                   
           
    }
}



void pick()
{
 digitalWrite(pick1, HIGH);
digitalWrite(pick2, LOW);
}

void relis()
{
 digitalWrite(pick1, LOW);
digitalWrite(pick2, HIGH);
}





void reach(x1,y1,x2,y2,k)
{
  while(x!=m || y!=n)
  {
    str();
    delay(100);
    clear1();
    upt(x1,y1,k);
    
    
  }
    
  hault();
  
}




void backreach(x1,y1,x2,y2,k)
{
  while(x1!=x2 || y1!=y2)
  {
    rev();
    delay(100);
    clear1();
    upt(x,y,k);
    
  }
  hault();
}

void str()
{
  int i,j;
i=analogRead(rightCenterSensor);
j=analogRead(leftCenterSensor);
if( i=0 && j=0)
{
digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(2);
}
if(i>0 && j=0)
{

digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(2);
}
if(i=0 && j>0)
{
  digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
delay(2);
}





void lr1(){
  int t=0;
  while(analogRead(rightbackSensor)!=0 && analogRead(leftbackSensor)!=0)
  {
    str();
    
   }
 while(analogRead(rightbackSensor)>0 && analogRead(leftbackSensor)>0)
  {
    str();
   }
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, LOW);

while(analogRead(rightCenterSensor)==0 && analogRead(leftCenterSensor)==0){
digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
t++;
delay(2);
}
while(analogRead(rightCenterSensor)>0 || analogRead(leftCenterSensor)>0){
digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
delay(2);

}
if(analogRead(rightCenterSensor)==0 && analogRead(leftCenterSensor)==0 && t>0)
{
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, LOW);
}
}














void ll1(){
  int t=0;
  while(analogRead(rightbackSensor)!=0 && analogRead(leftbackSensor)!=0)
  {
    str();
   }
 while(analogRead(rightbackSensor)>0 && analogRead(leftbackSensor)>0)
  {
    str();
   }
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, LOW);
while(analogRead(rightCenterSensor)=0 && analogRead(leftCenterSensor)=0){
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(2);
t++;
}
while(analogRead(rightCenterSensor)>0 || analogRead(leftCenterSensor)>0){
  digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(2);

}
if(analogRead(rightCenterSensor)=0 && analogRead(leftCenterSensor)=0 && t>0)
{
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, LOW);
}
}






void lr2()
{
  lr1();
  lr1();
}





void ll2()
{
  ll1();
  ll1();

}



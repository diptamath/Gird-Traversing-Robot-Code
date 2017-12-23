int c=0;
int w=0,s;
static int x1=1; 
 
static int x2=2;
static int y1=3;
static int y2=4;
float d;
int k;

int r;
#define leftCenterSensor 53
#define leftFarSensor 50
#define rightCenterSensor 52
#define rightFarSensor 54
#define rightbackSensor 55
#define leftbackSensor 56
#define ping 57
#define ping1 58
#define ping2 59

#define pingpin 60
#define pingpin1 61
#define pingpin2 62

#define pick1 64
#define pick2 65
#define leftMotor1 66
#define leftMotor2 67
#define rightMotor1 68
#define rightMotor2 69


/*void str();
void lr1();
void ll1();
void rev();
void ll2();
void lr2();
void upd(int x,int y,int k);
void avoid();
void getdis();
void objtr(int c,int r);
void scan(int x1,int y1,int x2,int y2,int k);
void scan1(int x1,int y1,int x2,int y2,int k);
void pick();
void relis();
void reach(x1,y1,x2,y2,k);
void backreach(x1,y1,x2,y2,k);
*/

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
      k=1;
      while(x1!=x2)
      {
        str();
        avoid();
        upd(x1,y1,k);
        
      }

       hault();
       ll1();
       
    }

          else if(x1>x2)
          {
            ll1();
            k=2;
            while(x1!=x2)
      {
        str();
        avoid();
        upd(x1,y1,k);
        e=check(x2,0,x1,y1);
      }

       hault();
       lr1();
            
          }

      k=3;                      
     while(y1!=y2)
      {
        str();
        avoid();
        upd(x1,y1,k);
        
      }

      hault();
      delay(100);
      c=1;
      
    
  }

  else if(c==1)
  {
    if(objtr(1,1)==1 && s!=10)
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
else if(s!=10)
{
  k=4;
  reach(x1,y1,x2,(y2-1),k);
  s++;
  
  
   
  }
else {
  while(y1!=y2)
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
    
  }
  reach(x1,y1,x2,y2,k);
}


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
delay(500);
}
if(i>0 && j=0)
{

digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(500);
}
if(i=0 && j>0)
{
  digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
delay(500);
}

void rev()
{
  int i,j;
i=analogRead(rightCenterSensor);
j=analogRead(leftCenterSensor);
if( i=0 && j=0)
{
digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
delay(500);
}
if(i>0 && j=0)
{

digitalWrite(leftMotor1, HIGH);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, HIGH);
delay(500);
}
if(i=0 && j>0)
{
  digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, HIGH);
digitalWrite(rightMotor1, HIGH);
digitalWrite(rightMotor2, LOW);
delay(500);
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

void hault()
{
  digitalWrite(leftMotor1, LOW);
digitalWrite(leftMotor2, LOW);
digitalWrite(rightMotor1, LOW);
digitalWrite(rightMotor2, LOW);
}
void upd(int x,int y,int k)
{
  int c;

  if (analogRead(rightfarSensor)=0 && analogRead(leftfarSensor)=0)
  {
    if(c==1)
    {
      if(k==1)
    {
      x=x+1;
      
    }
    else if(k==2)
    {
      x=x-1;
      
    }

    else if(k==3)
    {
      y=y+1;
      
    }
    else if(k==4)
    {
      y=y-1;
      
    }
    )
    else 
    {
      c=0;
    }
  
  }
}
 void avoid()
 {
  int d;
  d=getdis();
      if(d<=10)
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


 pinMode(ping, INPUT);
  duration = pulseIn(ping, HIGH);
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
  while(y1!=y2)
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
delay(2000);
}

void relis()
{
 digitalWrite(pick1, LOW);
digitalWrite(pick2, HIGH);
delay(2000);
}





void reach(x1,y1,x2,y2,k)
{
  while(x1!=x2 || y1!=y2)
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
    upt(x1,y1,k);
    
  }
  hault();
}



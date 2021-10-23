volatile int count=0;
volatile int millis1;
volatile int millis2;
volatile float diff;
int interval = 1000;
float rpm;

int count_=0;
int check=0;
int temp;

void setup() {
  Serial.begin(115200);
  attachInterrupt(0, magnet_detect, CHANGE);
  pinMode(12, OUTPUT);
}

void loop() {
  if(count%2==0 && count_%2==0){
    digitalWrite(12, LOW);
  }
  if(count%2==1 && count_%2==1){
    digitalWrite(12, HIGH);
  }
  if(millis() > interval){
    rpm = 60/(diff/1000);
    Serial.print("rpm1: ");
    Serial.print(rpm);
    
    Serial.print(" ");

    temp = check;
    Serial.print("rpm2: ");
    Serial.println(temp*60);
    check = check - temp;
    
    interval += 1000;
  }
}

void magnet_detect(){
  count++;
  count_++;
  if(count_%2 == 0){
    check++;
  }
  if(count%2==0 && count%4!=0){
    millis1=millis();
  }
  if(count%4==0){
    millis2=millis();
    diff=millis2-millis1;
    millis1=0;
    millis2=0;
  }
}

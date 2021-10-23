volatile int count=0;
volatile int check=0;
float temp;
int interval = 1000;
float rpm2;

void setup() {
  Serial.begin(115200);
  attachInterrupt(0, magnet_detect, CHANGE);
  pinMode(12, OUTPUT);
}

void loop() {
  if(count%2==0){
    digitalWrite(12, LOW);
  }
  if(count%2==1){
    digitalWrite(12, HIGH);
  }
  if(millis() > interval){
    temp = check;
    Serial.print("rpm2: ");
    rpm2 = temp*(60/(1000/1000));
    Serial.println(rpm2);
    check = check - temp;
    interval = interval + 1000;
  }
}

//check the number of serial monitor

void magnet_detect(){
  count++;
  if(count%2 == 0.0){
    check++;
  }
}

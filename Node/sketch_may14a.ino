#define trigPin 9
#define echoPin 8

#define trigPin2 7
#define echoPin2 6
#define ag_ismi "CMPE_IOT"
#define ag_sifresi "cmpeiot123"
#define IP "desolate-garden-11771.herokuapp.com"
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  
  pinMode(echoPin, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  Serial.begin(115200);
  Serial.println("AT");
  delay(3000);
  //analogReference(INTERNAL);
  if (Serial.find("OK")) {
    Serial.println("AT+CWMODE=1");
    delay(2000);
    String baglantiKomutu = String("AT+CWJAP=\"") + ag_ismi + "\",\"" + ag_sifresi + "\"";
    Serial.println(baglantiKomutu);
    delay(5000);
  }
}

void loop() {
  long duration, distance;
  long duration2, distance2;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 25){
    distance = 25;
  }
  if (distance < 0){
    distance = 0;
  }

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  if (distance2 > 25){
    distance2 = 25;
  }
  if (distance2 < 0){
    distance2 = 0;
  }

  
  Serial.print(distance);
  send_distance(distance, distance2);
  Serial.println(" cm");
  delay(1000);
}



void send_distance(long distance, long distance2) {
  Serial.println(String("AT+CIPSTART=\"TCP\",\"") + IP +"\",80");
  delay(100);
  if (Serial.find("Error")) {
    Serial.println("AT+CIPSTART Error");
    return;
  }

  String requestLink = "GET /measurement?distance=";
  requestLink += (int(distance));
  requestLink += "&distance2=";
  requestLink += (int(distance2));
  requestLink += " HTTP/1.1";
  requestLink += "\r\n";
  requestLink += "Host: desolate-garden-11771.herokuapp.com";
  requestLink += "\r\n";
  requestLink += "Accept: */*"; 
  requestLink +="\r\n\r\n";   
  delay(300);

  Serial.print("AT+CIPSEND=");
  Serial.println(requestLink.length() + 2);

  delay(100);

  if (Serial.find(">")) {

  Serial.print(requestLink);
  Serial.print("\r\n\r\n");
  } else {
    Serial.println("AT+CIPCLOSE");
  }
}

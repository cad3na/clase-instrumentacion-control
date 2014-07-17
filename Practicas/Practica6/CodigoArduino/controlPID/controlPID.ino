float errores[100];
float err, ent, sal;
int i = 0;

void setup() {
  Serial.begin(9600);
  for (i = 0; i < 100; i = i + 1) {
    errores[i] = 0.0;
  }
}

void loop() {
  float kp, ki, kd, ref, integral;
  kp = analogRead(A0) / 1023.0;
  delay(2);
  ki = analogRead(A1) / 1023.0;
  delay(2);
  kd = analogRead(A2) / 1023.0;
  delay(2);
  //ref = analogRead(A3) / 1023.0 * 5; 
  //delay(2);
  //ent = analogRead(A4) / 1023.0 * 5;
  //delay(2);
  
  ref = 3;
  ent = 1;
  
  err = ent - ref;
  int j = 0;
  integral = 0;
  for (j = 0; j < 100; j = j + 1) {
    integral = errores[j];
  }
  
  sal = kp*err + kd*(err - errores[i]) + ki*integral;
  
  Serial.println(sal);
  errores[i] = err;
  i = (i+1) % 100;
}


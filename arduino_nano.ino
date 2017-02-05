// Input Pins
int g1mu_i = 2;
int g1md_i = 3;
int g2mu_i = 4;
int g2md_i = 5;

// OUTPUT Pins
int g1mu_p = 7;
int g1md_p = 8;
int g2mu_p = 9;
int g2md_p = 10;

// Buffers for digital read
int g1mu_b = 0;
int g1md_b = 0;
int g2mu_b = 0;
int g2md_b = 0;

void setup() {
  
  //Serial.begin(9600);

  pinMode(g1mu_i, INPUT);  // g1mu
  digitalWrite(g1mu_i, HIGH); // Enable internal pull-up resistor
  pinMode(g1md_i, INPUT);  // g1md
  digitalWrite(g1md_i, HIGH);
  pinMode(g2mu_i, INPUT);  // g2mu
  digitalWrite(g2mu_i, HIGH);
  pinMode(g2md_i, INPUT);  // g2md
  digitalWrite(g2md_i, HIGH);

  pinMode(g1mu_p, OUTPUT); // g1mu
  pinMode(g1md_p, OUTPUT); // g1md
  pinMode(g2mu_p, OUTPUT); // g2mu
  pinMode(g2md_p, OUTPUT);// g2md

  // Start Clean
  digitalWrite(g1mu_p, LOW);
  digitalWrite(g1md_p, LOW);
  digitalWrite(g2mu_p, LOW);
  digitalWrite(g2md_p, LOW);

   //delay(60*1000); // Delay start by 30secs
}

void loop() {
  g1mu_b = digitalRead(g1mu_i);
  g1md_b = digitalRead(g1md_i);

  if(!(g1mu_b == 1 && g1md_b == 1))
  {
    digitalWrite(g1mu_p, g1mu_b);
    digitalWrite(g1md_p, g1md_b);
  } 
  
  g2mu_b = digitalRead(g2mu_i);
  g2md_b = digitalRead(g2md_i);

  if(!(g2mu_b == 1 && g2md_b == 1))
  {
    digitalWrite(g2mu_p, g2mu_b);
    digitalWrite(g2md_p, g2md_b);
  }
}

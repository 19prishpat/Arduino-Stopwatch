const int Input_Pin = 2; // Button connected to digital pin 2
long int StartTime;
long int EndTime;
float DurationSeconds;

// Timer0 mode and prescaler bit masks
byte WGM00_Mask = 0b00000001;
byte WGM01_Mask = 0b00000010;
byte WGM02_Mask = 0b00001000;
byte CS00_Mask = 0b00000001;
byte CS01_Mask = 0b00000010;
byte CS02_Mask = 0b00000100;

void waitForPressAndRelease(const char* message) {
  Serial.println(message);
  
  // Wait for button press (active LOW)
  while (digitalRead(Input_Pin) == HIGH);
  Serial.println("Button pressed...");
  
  // Wait for button release
  while (digitalRead(Input_Pin) == LOW);
  Serial.println("Button released.");
}

void setup() {
  pinMode(Input_Pin, INPUT);
  Serial.begin(9600);

  // Configure Timer0 for normal mode with a prescaler of 64
  TCCR0A &= ~WGM00_Mask;
  TCCR0A &= ~WGM01_Mask;
  TCCR0B &= ~WGM02_Mask;
  TCCR0B |= CS00_Mask;
  TCCR0B |= CS01_Mask;
  TCCR0B &= ~CS02_Mask;

  Serial.println("=== Stopwatch Initialized ===");
}

void loop() {
  // Start timing
  waitForPressAndRelease("Press and release the button to START the stopwatch...");
  StartTime = millis();
  Serial.println("Stopwatch started...");

  // Stop timing
  waitForPressAndRelease("Press and release the button again to STOP the stopwatch...");
  EndTime = millis();
  Serial.println("Stopwatch stopped.");

  // Display duration
  DurationSeconds = (float)(EndTime - StartTime) / 1000.0;
  Serial.print("Elapsed time: ");
  Serial.print(DurationSeconds);
  Serial.println(" seconds");
  Serial.println("===============================");
  Serial.println();
}
m

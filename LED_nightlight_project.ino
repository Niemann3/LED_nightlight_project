/*
Mark A. Niemann III
2/8/2023
ENGR 33320

LED Nightlight
*/

// RGB cathodes and matching pins
const int b_led = 9; // Blue LED cathode on pin 9
const int g_led = 10; // Green LED cathode on pin 10
const int r_led = 11; // Red LED cathode on pin 11
const int button = 2; // Button on pin 2

// Changing variables
int mode = 0; // Current mode for LED: 1 = solid, 2 = random, 0 = off
int button_state = LOW; // Default state is LOW which is unchanged
int prev_button_state = LOW; // Last state of button, used for debounce
int number_1 = random(255);
int number_2 = random(255);
int number_3 = random(255);

void setup() {
  // put your setup code here, to run once:
  pinMode(b_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(r_led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  randomSeed(analogRead(A0));
}

int randomNum() {
  return random(255);
}

// Debounce 
boolean debounce(boolean previous) {
  boolean current = digitalRead(button);
  if (previous != current) {
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void led_mode(int mode) {
  if (mode == 1) { // Red
    digitalWrite(b_led, LOW);
    digitalWrite(g_led, LOW);
    digitalWrite(r_led, HIGH);
  }

  else if (mode == 2) { // Green
    digitalWrite(b_led, LOW);
    digitalWrite(g_led, HIGH);
    digitalWrite(r_led, LOW);
  }

  else if (mode == 3) { // Blue
    digitalWrite(b_led, HIGH);
    digitalWrite(g_led, LOW);
    digitalWrite(r_led, LOW);
  }

  else if (mode == 4) { // Purple (Blue + Red)
    analogWrite(b_led, 255);
    analogWrite(g_led, 0);
    analogWrite(r_led, 255);
  }

  else if (mode == 5) { // Teal (Green + Blue)
    analogWrite(b_led, 255);
    analogWrite(g_led, 255);
    analogWrite(r_led, 0);
  }

  else if (mode == 6) { // Orange (Green + Red)
    analogWrite(b_led, 0);
    analogWrite(g_led, 30);
    analogWrite(r_led, 255);
  }

  else if (mode == 7) { // White (RGB)
    analogWrite(b_led, 255);
    analogWrite(g_led, 255);
    analogWrite(r_led, 255);
  }

  else if (mode == 8) { // Random
    analogWrite(b_led, number_1);
    analogWrite(g_led, number_2);
    analogWrite(r_led, number_3);
    }

  else if (mode == 0) { // Off
    analogWrite(b_led, 0);
    analogWrite(g_led, 0);
    analogWrite(r_led, 0);
  }
}



void loop() {

  button_state = debounce(prev_button_state);
  if (button_state == HIGH && prev_button_state == LOW) {
    mode++;
  }
  prev_button_state = button_state; // Changes button state

  if (mode == 9) {
    number_1 = random(255);
    number_2 = random(255);
    number_3 = random(255);
    mode = 0; // Reset mode to 0
  }
  led_mode(mode);
  }


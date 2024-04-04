// Variables for the delays 
const int dotDelay = 500; // Delay for a dot
const int charGapDelay = 250; // Delay for a gap between character

const int ledPin = 13; // Built-in LED pin

// Morse code characters
const String morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
"..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to blink a single Morse code character
void blinkMorse(char character) {
  int index = character - 'A'; // Convert character to index (A-Z)
  
  if (index >= 0 && index <= 25) { // Ensure it's a valid letter
    String code = morseCode[index];
    Serial.print(code);
    
    for (int i = 0; i < code.length(); i++) {
      
      if (code[i] == '.') {
        digitalWrite(ledPin, HIGH); // LED ON
        delay(dotDelay);             // Dot duration
      } else if (code[i] == '-') {
        digitalWrite(ledPin, HIGH); // LED ON
        delay(dotDelay * 3);         // Dash duration
      }
      digitalWrite(ledPin, LOW); // LED OFF
      delay(dotDelay);            // Inter-element gap (Gap between two elements in a single morse code character)
    }
    
    delay(charGapDelay); // Gap between letters
  }Serial.println();
}

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Set the Serial Monitor to check the morse code characters
}

void loop() {
  String name = "SOS"; // Name to display as a morse code
  
  // Blink the name in Morse code
  for (int i = 0; i < name.length(); i++) {
    blinkMorse(toupper(name[i])); // Convert to uppercase and blink
    delay(dotDelay * 2); // Gap between characters
  }
  
  delay(dotDelay * 4); // Gap between words
}

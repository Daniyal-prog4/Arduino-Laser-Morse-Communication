// --- Morse Code Laser Transmitter ---
// Laser connected to pin 3

int laserPin = 3;

// Morse timing (must match receiver)
int dotTime = 200;     // Dot duration
int dashTime = 600;    // Dash duration
int symbolGap = 200;   // Gap between dot/dash
int letterGap = 600;   // Gap between letters
int wordGap = 1400;    // Gap between words

// Morse dictionary
String getMorse(char c) {
  switch (c) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";

    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";

    default: return "";
  }
}

void sendSymbol(char symbol) {
  if (symbol == '.') {
    digitalWrite(laserPin, HIGH);
    delay(dotTime);
    digitalWrite(laserPin, LOW);
    delay(symbolGap);
  }

  else if (symbol == '-') {
    digitalWrite(laserPin, HIGH);
    delay(dashTime);
    digitalWrite(laserPin, LOW);
    delay(symbolGap);
  }
}

void sendText(String text) {
  text.toUpperCase();

  for (int i = 0; i < text.length(); i++) {
    char c = text[i];

    if (c == ' ') {
      delay(wordGap);
      continue;
    }

    String morse = getMorse(c);

    for (int j = 0; j < morse.length(); j++) {
      sendSymbol(morse[j]);
    }

    delay(letterGap);
  }
}

void setup() {
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);

  Serial.begin(9600);
  Serial.println("Laser Morse Transmitter Ready");

  delay(2000);
}

void loop() {
  sendText("HELLO WORLD");
  delay(4000);
}

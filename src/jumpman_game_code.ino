#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 12; 

bool isJumping = false;
int obstaclePos = 15; 
const int playerRow = 1; 
int score = 0; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, playerRow);
  lcd.print("O"); 

  lcd.setCursor(8, 0);
  lcd.print("Score: 0");
}

void loop() {
  static unsigned long lastMoveTime = 0;
  unsigned long currentTime = millis();

  if (digitalRead(buttonPin) == LOW) {
    isJumping = true;
    lcd.setCursor(0, playerRow);
    lcd.print(" "); 
    lcd.setCursor(0, playerRow - 1);
    lcd.print("O"); 
  } else {
    isJumping = false;
    lcd.setCursor(0, playerRow - 1);
    lcd.print(" "); 
    lcd.setCursor(0, playerRow);
    lcd.print("O"); 
  }

  if (currentTime - lastMoveTime >= 200) {
    lastMoveTime = currentTime;

    lcd.setCursor(obstaclePos, playerRow);
    lcd.print(" ");

    obstaclePos--;
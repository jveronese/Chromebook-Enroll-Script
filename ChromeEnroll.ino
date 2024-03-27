#include <Keyboard.h> // keyboard library

//Variables
#define wifi_name "---" // Define SSID for your wireless connection.
#define wifi_pass "---" // Define the password for your wireless connection.
#define wifi_security 2 //[0,1,2] Set to 0 for open, 1 for WEP, 2 for WPA
#define username "---" // Define the user name for enrolling the device.√
#define password "---" // The password for the enrollment GAFE account.

#define slowMode 1 // [0,1] Set to 1 if Centipede appears to be moving too quickly at any screen. This will slow down the entire process
#define update_wait_time 10 // Set to seconds to wait for mandatory updates to be downloaded

// Special characters definition
#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_ENTER       0xB0
#define KEY_ESC         0xB1
#define KEY_CAPS_LOCK   0xC1

int buttonPin = 2;  // Set a button to any pin
int RXLED = 17;
static uint8_t __clock_prescaler = (CLKPR & (_BV(CLKPS0) | _BV(CLKPS1) | _BV(CLKPS2) | _BV(CLKPS3)));

void setup() {
  Keyboard.begin();// put your setup code here, to run once:
  wait(5);

}

void loop() {
  setWifi();
  postWifi();
  enterEnrollment();
}

void repeatKey(byte key, int num) {
  for (int i = 0; i < num; i++) {
    Keyboard.write(key);
    wait(1);
  }
}

void blink() {
  digitalWrite(RXLED, LOW);
  //  TXLED1;
  delay(250);
  digitalWrite(RXLED, HIGH);
  //  TXLED0;
  delay(250);
}

void wait(int cycles) {
  for (int i = 0; i < cycles; i++) {
    blink();
    if (slowMode) {
      delay(250);
    }
  }
}

void setWifi () {
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(2);
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(1);
  Keyboard.write(KEY_ENTER);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(1);
  Keyboard.write(KEY_ENTER);
  wait(1);
  Keyboard.print(wifi_name);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  repeatKey(KEY_DOWN_ARROW, 2);
  wait(2);
  Keyboard.write(KEY_TAB);
  wait(2);
  Keyboard.print(wifi_pass);
  wait(2);
  repeatKey(KEY_TAB, 3);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(30);
}

void postWifi() {
  repeatKey(KEY_TAB, 3);
  wait(1);
  Keyboard.write(KEY_ENTER);
  wait(2);
  Keyboard.write(KEY_ENTER);
  wait(15);
}

void enterEnrollment() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('e');
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.release(KEY_LEFT_CTRL);
  wait(5);
  Keyboard.print(username);
  repeatKey(KEY_TAB, 2);
  Keyboard.write(KEY_ENTER);
  wait(5);
  Keyboard.print(password);
  repeatKey(KEY_TAB, 4);
  Keyboard.write(KEY_ENTER);
  wait(60);
}

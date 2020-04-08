#include <Keypad.h>
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = 
{
{'0','4','8', 'C'}, 
{'1','5','9', 'D'},
{'2', '6', 'A', 'E'}, 
{'3', '7', 'B', 'F'}
};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {2, 3, 4, 5};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {6, 7, 8, 9};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );
void setup()
{
byte numDigits = 1;
byte digitPins[] = {17};
byte segmentPins[] = {10,11,12,13,14,15,16};
sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);

Serial.begin(9600);
}
void loop()
{
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY)
{
Serial.println(key);
}
if(key>='A'&&key<='F')
sevseg.refreshDisplay();
}

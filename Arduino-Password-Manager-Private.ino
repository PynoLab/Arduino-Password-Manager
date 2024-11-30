#include <SD.h>
#include <Wire.h>
#include <DoublyLinkedList.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <Keypad.h>
#include <Keyboard.h>

#define HD44780_LCDOBJECT
#define PIN_SPI_CS 10

DoublyLinkedList<String> files(true);
hd44780_I2Cexp lcd(0x27, 16, 2);
uint16_t currentFile = 0;
const int COLUMN_NUM = 5;
const int ROW_NUM = 1;
char keys[ROW_NUM][COLUMN_NUM] = {
    {'1', '2', '3', '4', '5'},
};
byte pin_rows[ROW_NUM] = {4};
byte pin_column[COLUMN_NUM] = {5, 6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void updateDisplay()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(files[currentFile]);
}

void checkSD()
{
    if (!SD.begin(PIN_SPI_CS))
    {
        lcd.clear();
        lcd.print("SD not found");
        lcd.setCursor(0, 1);
        lcd.print("Insert & reboot");
        while (1);
    }
}

void setup()
{

    Serial.begin(115200);
    lcd.begin(16, 2);
    lcd.backlight();
    Keyboard.begin();
    checkSD();
    File root = SD.open("/");
    File entry = root.openNextFile();

    while (entry)
    {
        if (!entry.isDirectory())
            files.add(entry.name());
        entry.close();
        entry = root.openNextFile();
    }

    root.close();
    lcd.print(files[currentFile]);
}

void loop()
{
    checkSD();
    char key = keypad.getKey();

    if (key == '4' && currentFile > 0)
    {
        currentFile--;
        updateDisplay();
    }

    if (key == '5' && currentFile < files.size() - 1)
    {
        currentFile++;
        updateDisplay();
    }

    if (key == '1')
    {
        File pwdFile = SD.open(files[currentFile]);
        String pwd = pwdFile.readString();
        pwd.replace("\n", "");
        Keyboard.print(pwd);
    }
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Declare Objects
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setp()
{
    Serial.begin(9600);

    // SSD1306_SWITCHAPVCC = generate display voltage from 3.3V internally
    if (!dispaly.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }

    // show the display buffer on the screen. You MUST call display() after drawing commands to make them visible on the display
    display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();

    display.setTextSize(1);              // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE); // Draw white text
    display.setCursor(0, 0);             // Start at top-left corner
    display.println(F("Welcome to Medibox !"));

    display.display();
    delay(2000); // Pause for 2 seconds
}

void loop()
{
}

void print_time_now(void)
{
    display.clearDisplay();
    print_line(String(days), 0, 0, 2);
}
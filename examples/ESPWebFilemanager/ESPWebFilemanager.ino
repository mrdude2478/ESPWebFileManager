/*
 * Project Name: Example code for ESPWebFileManager Library
 * Project Brief: Example code for ESPWebFileManager Library
 * Author: Jobit Joseph @ https://github.com/jobitjoseph
 * IDE: Arduino IDE 2.x.x
 * Arduino Core: ESP32 Arduino Core V 3.0.7
 * Dependencies : ESPWebFileManager Library V 1.4.2 @ https://github.com/jobitjoseph/ESPWebFileManager
                  Async TCP Library for ESP32 V 3.2.14 @ https://github.com/mathieucarbou/AsyncTCP
 *                ESPAsyncWebServer Library V 2.2.6 @ https://github.com/mathieucarbou/ESPAsyncWebServer
 * Copyright © Jobit Joseph
 * 
 * This code is licensed under the following conditions:
 *
 * 1. Non-Commercial Use:
 * This program is free software: you can redistribute it and/or modify it
 * for personal or educational purposes under the condition that credit is given 
 * to the original author. Attribution is required, and the original author 
 * must be credited in any derivative works or distributions.
 *
 * 2. Commercial Use:
 * For any commercial use of this software, you must obtain a separate license
 * from the original author. Contact the author for permissions or licensing
 * options before using this software for commercial purposes.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL 
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING 
 * FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 *
 * Author: Jobit Joseph
 * Date: 01 December 2024
 *
 * For commercial use or licensing requests, please contact [jobitjoseph1@gmail.com].
 */
#include <ESPWebFileManager.h>
#include <ESPAsyncWebServer.h>

#define DEBUG_SERIAL Serial
const char *ssid = "WiFi SSID";
const char *password = "WiFi Password";
AsyncWebServer server(80);
ESPWebFileManager fileManager;

void setup() {
    DEBUG_SERIAL.begin(115200);
    DEBUG_SERIAL.println("Initializing system...");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        DEBUG_SERIAL.print(".");
    }
    DEBUG_SERIAL.println("\nWi-Fi connected");
    DEBUG_SERIAL.print("IP Address: ");
    DEBUG_SERIAL.println(WiFi.localIP());

    // Initialize SPIFFS (Change to other types as needed, Valid types: FS_SD_CARD, FS_SPIFFS, FS_LITTLEFS, FS_FATFS )
    if (!fileManager.initFileSystem(ESPWebFileManager::FS_SPIFFS, true)) {
        DEBUG_SERIAL.println("Failed to initialize file system");
    }

    fileManager.setServer(&server);
    server.begin();
    DEBUG_SERIAL.println("Web server started");
}

void loop() {
    delay(5);
}

/*
 * ESPWebFileManager Library
 * Copyright (C) 2024 Jobit Joseph
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)
 * You may not use this work for commercial purposes. Modifications must credit the original author.
 * See the LICENSE file for more details.
 * Project Name: ESPWebFileManager Library
 * Project Brief: ESPWebFileManager Library
 * Author: Jobit Joseph @ https://github.com/jobitjoseph
 * IDE: Arduino IDE 2.x.x
 * Arduino Core: ESP32 Arduino Core V 3.0.7
 * GitHub: https://github.com/jobitjoseph/ESPWebFileManager
 * Dependencies : 
 *                Async TCP Library for ESP32 V 3.2.14 @ https://github.com/mathieucarbou/AsyncTCP
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
#ifndef ESP_WEB_FILE_MANAGER_H
#define ESP_WEB_FILE_MANAGER_H

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
// Define file system types
#define FS_SPIFFS 1
#define FS_SD 2
#define FS_LITTLEFS 3
#define FS_FATFS 4

#define EN_DEBUG
#define DEBUG_SERIAL Serial

#ifdef EN_DEBUG
#define DEBUG_PRINTLN(x) { DEBUG_SERIAL.println(x); }
#define DEBUG_PRINT(x) { DEBUG_SERIAL.print(x); }
#define DEBUG_PRINT2(x, y)   DEBUG_SERIAL.print(F(x)); DEBUG_SERIAL.println(y)
#define DEBUG_PRINTX(...)     DEBUG_SERIAL.printf(__VA_ARGS__)
#else
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT(x)
#endif

class ESPWebFileManager {
public:
    // Constructor for SPIFFS, FATFS, or LittleFS (only one variable needed)
    ESPWebFileManager(int fsType, bool formatOnFailFlag);

    // Constructor for SD card with SPI pin remapping and arguments
    ESPWebFileManager(int fsType, bool formatOnFailFlag, bool SPIreconfig, int csPin = -1, int mosi = -1, int miso = -1, int sck = -1);

    // Public function to initialize the file system
    bool begin();

    String sanitizePath(const String& path);

    void setServer(AsyncWebServer *server);

    void listDir(const char *dirname, uint8_t levels);
    
    int getFsType();
private:
    FS *current_fs = nullptr;
    bool memory_ready = false;
    String str_data = "";
    AsyncWebServer *_server = nullptr;
    //FileSystemType fs_type = FS_UNKNOWN;
    int _fsType;          // File system type
    bool _formatOnFailFlag;       // Common flag
    bool _SPIreconfig;      // Extra flag to remap SPI pins for SD Card
    int _args[4];         // CS pin, MOSI, MISO, and SCK for SD card

    int _csPin;           // Temporary CS pin variable

    bool initFileSystem(fs::FS &fs, const char *fsName, std::function<bool()> beginFn, std::function<bool()> formatFn);

    bool initSD();
};

#endif

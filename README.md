# ESPWebFileManager

**EspWebFileManager** is a library that manages various file systems and provides file management over a web interface for ESP32. With the **EspWebFileManager** library, you will get a  responsive interface that allows you to upload, download, and delete files stored on the ESP32's filesystem. Now Supports folders too. You can create or delete folders on LittleFS, FAT FS or SD card. Folders are not supported on SPIFFS. The **EspWebFileManager** library supports multiple file systems like SD Card, SPIFFS, LittleFS, and FATfs on ESP32.
<img src="https://github.com/jobitjoseph/ESPWebFileManager/blob/main/Images/Desktop.jpg" width="" alt="alt_text" title="image_tooltip">
<img src="https://github.com/jobitjoseph/ESPWebFileManager/blob/main/Images/Phone.jpg" width="" alt="alt_text" title="image_tooltip">

## Features
- **File Management:** web interface for file management tasks such as upload, download, and delete.
- - **Folder Management:** You can create or delete folders on LittleFS, FAT FS or SD card. Folders are not supported on SPIFFS.

## Installation

### Arduino IDE
1. Through Arduino Library Manager: In the Arduino library manager search for ESPWebFileManager and install.
1. Manual Installation: Download the zip file and install it using `Sketch -> Include Library -> Add .ZIP Library` or Extract the zip file to the Arduino libraries folder.
### PlatformIO
1. Add the library to your `platformio.ini`:
   ```ini
   lib_deps =
       https://github.com/jobitjoseph/ESPWebFileManager.git

## Usage 
    
Check the Example file provided. Libraray usage is now much easier. All you have to do is create the proper constructor at the start of the sketch and call the begin function in the setup. :
   ```cpp
   /*File System eg. FS_SPIFFS, Format the file system if mounting failed  true/false, (for FS_SD only)Reconfig SPI pins true/false, SPI pin CS, MOSI, MISO, SCK*/
   //ESPWebFileManager fileManager(FS_SPIFFS, true);// FS_SPIFFS, true / false
   ESPWebFileManager fileManager(FS_LITTLEFS, true);// FS_LITTLEFS, true / false
   //ESPWebFileManager fileManager(FS_FATFS, true);// FS_FATFS, true / false
   //ESPWebFileManager fileManager(FS_SD, true, false, 25);// FS_SD, true / false, CS // if you don't want to change the cs pin use -1 instead
   //ESPWebFileManager fileManager(FS_SD, true, true, 25, 23, 19, 18); // FS_SD, true / false, CS , MOSI, MISO, SCK
```

    
Call the begin function in the setup. :
   ```cpp
   fileManager.begin()
```


After uploading the code you can access the file manager through the URL `http:ipadrees/file`. for eg `192.168.0.124/file`
## Issues and Warnings
    Don't use files with way too long file names.

## To Do
    SD MMC support
    File search Add a search bar to filter files and folders by name dynamically.
    Sorting
    Rename files
    Multi-file selection and management
    Drag and drop upload
    Notifications
    File Metadata
    Edit file within the web UI
    Real-Time Updates
    ̌File preview Preview text files (e.g., .txt, .log) without downloading., Display image files (e.g., .jpg, .png) directly in the browser.
    File system stats
    


## License

 *EspWebFileManager Library
 * Copyright (C) 2024 Jobit Joseph
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)
 * You may not use this work for commercial purposes. Modifications must credit the original author.
 * See the LICENSE file for more details.

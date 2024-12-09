# ESPWebFileManager

**EspWebFileManager** is a library that manages various file systems and provides file management over a web interface for ESP32. With the **EspWebFileManager** library, you will get a  responsive interface that allows you to upload, download, and delete files stored on the ESP32's filesystem. The **EspWebFileManager** library supports multiple file systems like SD Card, SPIFFS, LittleFS, and FATfs on ESP32.
<img src="https://github.com/jobitjoseph/ESPWebFileManager/blob/main/Images/Desktop.png" width="" alt="alt_text" title="image_tooltip">
<img src="https://github.com/jobitjoseph/ESPWebFileManager/blob/main/Images/Phone.jpg" width="" alt="alt_text" title="image_tooltip">

## Features
- **File Management:** web interface for file management tasks such as upload, download, and delete.

## Installation

### Arduino IDE
1. Download the zip file and install it using `Sketch -> Include Library -> Add .ZIP Library` or Extract the zip file to the Arduino libraries folder.

### PlatformIO
1. Add the library to your `platformio.ini`:
   ```ini
   lib_deps =
       https://github.com/jobitjoseph/ESPWebFileManager.git

## Usage 
    
Check the Example file provided. To use change the filesystem type on the function call`fileManager.initFileSystem(ESPWebFileManager::FS_SPIFFS, true)`. Valid file system types are `FS_SD_CARD, FS_SPIFFS, FS_LITTLEFS, FS_FATFS`. For the SD Card CS pin needs to be changed within the library. :
   ```cpp
   fileManager.initFileSystem(ESPWebFileManager::FS_SPIFFS, true)
```

After uploading the code you can access the file manager through the URL `http:ipadrees/file`. for eg `192.168.0.124/file`
## Issues and Warnings
    Don't use files with longer file names.

## To Do
    File search Add a search bar to filter files and folders by name dynamically.
    Sorting
    Rename files
    Multi-file selection and management
    Drag and drop upload
    Notifications
    File Metadata
    Edit file within the web UI
    Real-Time Updates
    Folder Management: Add the ability to create, rename, and delete folders.
    ̌File preview Preview text files (e.g., .txt, .log) without downloading., Display image files (e.g., .jpg, .png) directly in the browser.
    File system stats
    


## License

 *EspWebFileManager Library
 * Copyright (C) 2024 Jobit Joseph
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)
 * You may not use this work for commercial purposes. Modifications must credit the original author.
 * See the LICENSE file for more details.

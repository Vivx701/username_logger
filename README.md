# username_logger
Code to log the name of the user while logged  in 


## files included
* client.c     - c code send username
* server_sd.c  - systemd server to write to file
* build        - Bash script to build and install code.
* username_server.service - "systemd service file"
* username_server.socket - " systemd socket file"

## How to use build script
command help

1. Build main.c

   Build the main.c file to create username command

    ```
    ./build --build
    ``` 
2. Install username command

    Installs the services and files to system
    ```
    sudo ./build --install
    ``` 
3. Uninstall the command
    
    Removes the services and files from system. Restore the /etc/bashrc and /etc/profile manullay from .bak files
    ```
    sudo ./build --remove
    ``` 
4. Clean build
    
    Cleans the existing build
    ```
    ./build --clean
    ``` 

5. Print help message

    ```
    ./build --help
    ``` 


## Working
When user tried to login or switch user via GUI/greeter or terminal. Name of the user will be stored in /tmp/username.log

Tested with: fedora 30 KDE, Kernel: 5.0.9-301.fc30.x86_64
   

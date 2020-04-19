# username_logger
Code to log the name of the user while logged  in 


## files included

* main.c - c code to print username.
* build  - Bash script to build and install code.


##How to use build script
command help

1. Build main.c

   Build the main.c file to create username command

    ```
    ./build --build
    ``` 
2. Install username command

    Installs the username command to /usr/bin and creates a user.sh file in "/etc/profile.d"
    ```
    sudo ./build --install
    ``` 
3. Uninstall the command
    
    Removes the username command from /usr/bin and  user.sh file from "/etc/profile.d"
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


##Working
When user tried to login or switch user via GUI/greeter or terminal. Name of the user will be stored in /tmp/username.log
   
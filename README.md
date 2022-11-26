# canvas-cpp

canvas-cpp is a command line application that downloads all course files into the user's computer from a particular Canvas LMS
server. It is written in C++. Currently only supported on Linux.


## Config File
- The config file must be placed in the `$HOME` directory with the name `canvas-config.txt`.
- It must also follow the format as shown below.
- The token is generated from the settings in your institution's Canvas portal.

```
[Canvas Url]
https://canvas.yourinstitution.com

[Token]
012345678abcdefgh

[Download Folder]
/home/user/Downloads
```


## Installing Dependencies (Tested with Debian/Ubuntu)
If using other distributions, it might be libssl-devel

```shell
sudo apt install gcc g++ make cmake libssl-dev 
```

## Building from source and running the program
```
git clone https://github.com/theresurgence/canvas-cpp
cd canvas-cpp
mkdir build && cd build

cmake ..
make
sudo make install
./canvas-cpp
```










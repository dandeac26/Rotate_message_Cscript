# Rotate message script

This is a short script that can encode or decode messages.

## Installation:
```bash
git clone https://github.com/dandeac26/Rotate_message_Cscript.git
cd Rotate_message_Cscript
gcc rotate.c -o rotate
```
## Use:
Inspired by the Rotate13 encryption, this script allows you to choose the rotation offset. In case of Rotate13 the offset is 13. 
In case of offset 1, for the message "gun", it would be "hvo". ( h is 1 letter ahead of g in case of forward offset by 1)

You can choose the direction by using the following flags: -f or -b for forward/ backwrard

Example : 
```bash
./[executable-name] [direction:forward/backwrad] [offset:int] [message:string]
./rotate -f 1 gun

./rotate -b 13 "this is 4 times harder to understand"
```

# STM32SignalLogger
Custom project on STM32F446R3 meant to be a demo of a custom bootloader and a FreeRTOS app

Step 1 install GNU arm toolchain:
https://www.youtube.com/watch?v=UbTTvdbxmPc

Step 2 install make:
https://leangaurav.medium.com/how-to-setup-install-gnu-make-on-windows-324480f1da69

Step 3 install stlink toosl and add to path (version 1.7 works for me):
https://github.com/stlink-org/stlink?tab=readme-ov-file

Note: libopencm3 calls python3, but the makefile in the normal project calls python

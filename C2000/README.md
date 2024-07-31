To build the project, you will need to install TI C2000ware which includes drivers and the TI cl2000 compiler tools.

The make file assumes usage of gmake, in this case since the CCS install was present in this computer, gmake from the CCS install was used. Any gmake installation should be good.

Example call to gmake to build the project (go inside app folder):

C:\ti\ccs1271\ccs\utils\bin\gmake -k -j 12

The code can be flashed using uniflash, using the generated app.out executable.

Once a bootloader is added this process will use custom software.

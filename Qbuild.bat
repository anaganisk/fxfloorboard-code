@echo off
:CHECK
cls
echo ********************************************************************
echo *                    ___________________________________           *
echo ***                   Build MENU for GT-10FxFloorBoard          ***
echo *                    -----------------------------------           *
echo *                      Press [1] to "Compile"                      *
echo *                               or                                 *
echo *                      Press [2] to "Compile and Run"              *
echo *                               or                                 *
echo *                      Press [3] for "Run only"                    *
echo *                               or                                 *
echo *                      Press [4] for "EXIT"                        *
echo ********************************************************************
echo .
choice /c:1234  Choose an option
if errorlevel 4 goto D-OPTION
if errorlevel 3 goto C-OPTION
if errorlevel 2 goto B-OPTION
if errorlevel 1 goto A-OPTION

:A-OPTION
c:\qt\4.4.2\bin\qmake
c:\MinGW\bin\mingw32-make 
pause
goto CHECK

:B-OPTION
c:\qt\4.4.2\bin\qmake
c:\MinGW\bin\mingw32-make 
cd packager
GT-10FxFloorBoard.exe
cd ..
goto CHECK

:C-OPTION
cd packager
GT-10FxFloorBoard.exe
cd ..
goto CHECK

:D-OPTION
goto END

:END
echo .
echo the end......................Colin`s Menu ..........................
exit


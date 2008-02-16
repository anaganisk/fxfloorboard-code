:start
cls
@echo "press any key to compile"
pause
c:\qt\qt-win-src-4.4.0\bin\qmake
mingw32-make
@echo "press any key to run"
pause
packager\GT-3FxFloorBoard.exe
goto start

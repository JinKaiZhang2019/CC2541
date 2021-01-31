@echo off
:for /r . %%i in (*.cout) do del %%i
:for /r . %%i in (*.r51) do del %%i
:for /r . %%i in (*.pbi*) do del %%i
:for /r . %%i in (*.pbd*) do del %%i
:for /r . %%i in (*.map) do del %%i
:for /r . %%i in (*.d51) do del %%i
:for /r . %%i in (*.s51) do del %%i
:for /r . %%i in (*.sim) do del %%i

del /s /q *.cout
del /s /q *.r51
del /s /q *.pbi*
del /s /q *.pbd*
del /s /q *.map
del /s /q *.d51
del /s /q *.s51
del /s /q *.sim

pause
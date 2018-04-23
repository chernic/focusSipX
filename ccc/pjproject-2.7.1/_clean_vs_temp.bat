@echo off
@echo 接下来将删除以下文件

REM @echo Debug Release output ipch *.pdb *.sdf

REM set ConfigurationName=%cd%\Deploy\i386-Win32-vc8-Debug
REM echo %ConfigurationName%
REM if exist %ConfigurationName% (
  REM del %ConfigurationName%\*.exp /f /s /q
  REM del %ConfigurationName%\*.ilk /f /s /q
  
  REM REM del %ConfigurationName%\*.lib /f /s /q
  REM REM del %ConfigurationName%\*.ocx /f /s /q
REM )

@echo off
setlocal enabledelayedexpansion  

for /r . %%a in (Debug) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

REM if exist %ConfigurationName% (
  REM del %ConfigurationName%\*.htm /f /s /q
  REM del %ConfigurationName%\*.obj /f /s /q
  REM del %ConfigurationName%\*.sbr /f /s /q
  REM del %ConfigurationName%\*.idb /f /s /q
  REM del %ConfigurationName%\*.pdb /f /s /q
  
  REM del %ConfigurationName%\*.bsc /f /s /q
  REM del %ConfigurationName%\*.ilk /f /s /q
REM )

for /r . %%a in (Release) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (output) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (ipch) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

for /r . %%a in (*.sdf) do (  
  if exist %%a (
  echo "delete" %%a
  del "%%a" 
 )
)

@pause
@pause

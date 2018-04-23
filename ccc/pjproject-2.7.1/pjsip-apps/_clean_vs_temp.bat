@REM *.pyc
@echo 接下来将删除以下文件

@echo Debug Release output ipch *.pdb *.sdf

@del /S *.pdb

@echo off
setlocal enabledelayedexpansion  


for /r . %%a in (Debug) do (  
  if exist %%a (
  echo "delete" %%a
  rd /s /q "%%a" 
 )
)

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

pause
    :: Chernic 20180307
    @echo off  

    @echo ====current environment :
    @echo %PATH%

    :: Chernic 用户工具的 Windows 系统变量
    @setx PathBandizip          "C:\Program Files\Bandizip\7z"
    @setx PathMacType           "C:\Program Files\MacType"
    @setx PathCMake             "C:\Program Files\CMake\bin"
    @setx Pathdoxygen           "C:\Program Files\doxygen\bin"
    @setx PathTortoiseSVN       "C:\Program Files\TortoiseSVN\bin"
    @setx PathTortoiseGit       "D:\Program Files\TortoiseGit\bin"

    REM @setx PERL_HOME         "D:\Perl\site\bin;D:\Perl\bin"
    REM @setx PYTHON_HOME       "C:\Python27\;C:\Python27\Scripts"
    REM @setx JAVA_HOME         "C:\ProgramData\Oracle\Java\javapath"
    REM @setx QT_VS2008_HOM     "C:\Qt\4.8.7_vs2008\bin"
    REM @setx QT_IFW_HOME       "D:\Qt\QtIFW2.0.5\bin"
    REM @setx MinGW_HOME        "C:\msys\MinGW\bin"
    REM @setx MSYS_HOME         "C:\msys\1.0\local\yasm\bin;C:\msys\1.0\local\SDL\bin;C:\msys\1.0\local\x264\bin"

    :: Chernic 工作空间的 Windows 系统变量
    @setx MYWORK_HOMES %%PERL_HOME%%;%%PYTHON_HOME%%;%%JAVA_HOME%%;%%QT_VS2008_HOME%%;%%QT_IFW_HOME%%;%%MinGW_HOME%%;%%MSYS_HOME%%;

    :: 本地新加 系统变量
    @setx PathLocal         "%cd%\DLLExport"

    :: CChernic 用户的所有 系统变量
    @setx path 1111;%%CHERNIC_TOOL_HOMES%%;%%MYWORK_HOMES%%;%%PathLocal%%;1111;

    @echo ====new environment :
    @echo %PATH%
    
    :: 使用WMIC，重启生效（永久的）系统变量
    @set SYSTEMPATH=C:\;C:\Windows\System32;C:\Windows;C:\Windows\system32\wbem
    @set SYSTEMPATH=%SYSTEMPATH%;%%VS90COMNTOOLS%%
    @set SYSTEMPATH=%SYSTEMPATH%;%%VS100COMNTOOLS%%
    @set SYSTEMPATH=%SYSTEMPATH%;%%VS110COMNTOOLS%%
    @set SYSTEMPATH=%SYSTEMPATH%;%%VS120COMNTOOLS%%
    
    @wmic ENVIRONMENT where "name='path' and username='<SYSTEM>'" set VariableValue='%SYSTEMPATH%'
    @pause

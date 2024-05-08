@echo off

rem
rem This is a script that will package everything for release and place
rem it into the Releases folder.
rem
rem It will do the following:
rem - Compile all the libraries required (x86/x64 Debug/Release)
rem - Package them into the correct name
rem - Zip them up with the correct name
rem
rem It will not:
rem - Touch or delete any of your project files. At all. 
rem 

set package_dir=%~dp0\_temp
set release_dir=%~dp0\Releases
set package_name=CProcessingSG.zip

where /q cl
IF %ERRORLEVEL% == 0 (GOTO build)
SET VC_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community
IF NOT DEFINED LIB (IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64))

:build

pushd Processing_Sample

rem --- Compilation Phase ---  
powershell write-host -fore Red === BUILDING DEVELOPMENT FILES  ===
rem We assume that users have already installed the required VS2019, to the point where they can build from there
rem This initializes the development environment for VS2019 in x64 mode

devenv Processing_Sample.sln /rebuild "Debug|x64"
devenv Processing_Sample.sln /rebuild "Release|x64"
devenv Processing_Sample.sln /rebuild "Debug|x86"
devenv Processing_Sample.sln /rebuild "Release|x86"

rem --- Packaging Phase ---
rmdir %package_dir% /s /q
mkdir %package_dir%
mkdir %package_dir%\CProcessing
mkdir %package_dir%\CProcessing\inc
mkdir %package_dir%\CProcessing\lib
mkdir %package_dir%\CProcessing\lib\x64
mkdir %package_dir%\CProcessing\lib\x86

rem -- Packaging CProcessing -- 
rem x64
powershell write-host -fore Red === PACKAGING DEVELOPMENT FILES  ===
xcopy CProcessing\lib\x64\CProcessing.lib %package_dir%\CProcessing\lib\x64 /s /r /y /q >nul
xcopy CProcessing\lib\x64\CProcessing.dll %package_dir%\CProcessing\lib\x64 /s /r /y /q >nul
xcopy CProcessing\lib\x64\CProcessingd.lib %package_dir%\CProcessing\lib\x64 /s /r /y /q >nul
xcopy CProcessing\lib\x64\CProcessingd.dll %package_dir%\CProcessing\lib\x64 /s /r /y /q  >nul
xcopy CProcessing\lib\x64\fmod.dll %package_dir%\CProcessing\lib\x64 /s /r /y /q >nul
xcopy CProcessing\lib\x64\fmodL.dll %package_dir%\CProcessing\lib\x64 /s /r /y /q >nul

rem x86
xcopy CProcessing\lib\x86\CProcessing.lib %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul
xcopy CProcessing\lib\x86\CProcessing.dll %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul
xcopy CProcessing\lib\x86\CProcessingd.lib %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul
xcopy CProcessing\lib\x86\CProcessingd.dll %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul
xcopy CProcessing\lib\x86\fmod.dll %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul
xcopy CProcessing\lib\x86\fmodL.dll %package_dir%\CProcessing\lib\x86 /s /r /y /q >nul

rem inc
xcopy CProcessing\inc\cprocessing.h %package_dir%\CProcessing\inc /s /r /y /q >nul
xcopy CProcessing\inc\cprocessing_common.h %package_dir%\CProcessing\inc /s /r /y /q >nul

popd


rem -- Wiki building --
powershell write-host -fore Red === BUILDING WIKI FILES ===
pushd Wiki
mkdocs build -d %package_dir%\Wiki
popd


rem rem --- Zipping phase --- 
powershell write-host -fore Red === ZIPPING EVERYTHING ===
powershell Compress-Archive -Force -Path %package_dir%\* -DestinationPath %release_dir%\%package_name%


rem rem -- Cleanup -- 
powershell write-host -fore Red === CLEAN UP ===
rmdir %package_dir% /s /q


powershell write-host -fore Red === DONE ===

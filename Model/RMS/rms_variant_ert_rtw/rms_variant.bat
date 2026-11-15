
cd .

chcp 1252

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2025a\bin\win64\gmake"  -f rms_variant.mk all) else ("C:\PROGRA~1\MATLAB\R2025a\bin\win64\gmake"  -f rms_variant.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1
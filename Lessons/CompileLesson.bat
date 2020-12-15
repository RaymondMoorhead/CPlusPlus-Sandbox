@echo off
mkdir CompiledLessons
set /P num="Enter The Two-Digit Lesson Number: "
set ppo="_NDEBUG"
set deb="n"
set exf=""

rem Lesson 4 uses files from Lesson 5
if %num%==04 set exf="Source/05_*.cpp"

rem Lesson 5 uses files from Lesson 4
if %num%==05 set exf="Source/04_1*.cpp"

rem Lesson 6 uses files from Lesson 5
if %num%==06 set exf="Source/05_*.cpp"

rem Lesson 09 demonstrates differences between
rem debug and release builds, and thus needs this
if %num%==09 set /P deb="Run In Debug Mode(y/n): "
if %deb%==y set ppo="_DEBUG"

if %exf%==""  g++ -D %ppo% -o "CompiledLessons/Lesson_%num%.exe" "Source/%num%_*.cpp"
if not %exf%=="" g++ -D %ppo% -o "CompiledLessons/Lesson_%num%.exe" "Source/%num%_*.cpp" "%exf%"

if not %errorlevel%==0 goto error-end

echo Your program has successfully compiled, here is the output:
"CompiledLessons/Lesson_%num%.exe"

pause
exit

:error-end
echo Your program failed to compile
pause
exit
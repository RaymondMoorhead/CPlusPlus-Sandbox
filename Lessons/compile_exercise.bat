@echo off
set /P num="Enter The Two-Digit Exercise Number: "
set ppo="SOLUTION"
set sol="s"

if not exist CompiledExercises mkdir CompiledExercises

set /P sol="Run your Exercise code Or the Solution(e/s): "
if %sol%==e set ppo="EXERCISE"

:start

if %sol%==e goto run-exercise
if %sol%==s goto run-solution

echo Invalid Option
pause
exit

:run-exercise

if not exist  Exercises/%num%_*.cpp g++ -D %ppo% -o "CompiledExercises/Exercise_%num%.exe" "Exercises/Drivers/%num%_*.cpp"
if exist      Exercises/%num%_*.cpp g++ -D %ppo% -o "CompiledExercises/Exercise_%num%.exe" "Exercises/Drivers/%num%_*.cpp" "Exercises/%num%_*.cpp"

if not %errorlevel%==0 goto error-end

echo Your program has successfully compiled, here is the output:
"CompiledExercises/Exercise_%num%.exe"

pause
exit

:run-solution

if not exist  Exercises/Solutions/%num%_*.cpp g++ -D %ppo% -o "CompiledExercises/Exercise_%num%_Solution.exe" "Exercises/Drivers/%num%_*.cpp"
if exist      Exercises/Solutions/%num%_*.cpp g++ -D %ppo% -o "CompiledExercises/Exercise_%num%_Solution.exe" "Exercises/Drivers/%num%_*.cpp" "Exercises/Solutions/%num%_*.cpp"

if not %errorlevel%==0 goto error

echo Here is the solution's output:
"CompiledExercises/Exercise_%num%_Solution.exe"

goto end

:error
echo The program failed to compile

:end

set /P retry="Recompile? (y/n)"

if %retry%==y goto start

exit
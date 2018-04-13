@echo off

for /f %%j in ("java.exe") do (
	if "%%~dp$PATH:j"=="" (
		echo java 1.7 onwards required! 
		exit /b
	)
)

java -jar panako-1.6.jar query %1

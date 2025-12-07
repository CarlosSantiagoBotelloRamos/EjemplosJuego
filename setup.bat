@echo off
REM Script de instalación para Traffic Racer en Windows (MSYS2/MinGW64)
REM Este script verifica dependencias y copia una fuente por defecto

echo.
echo ============================================
echo   Traffic Racer - Setup de Instalacion
echo ============================================
echo.

REM Crear carpetas necesarias
echo [1/4] Creando estructura de carpetas...
if not exist "assets\fonts" mkdir assets\fonts
if not exist "bin" mkdir bin
if not exist "obj" mkdir obj
echo OK: Carpetas creadas

REM Intentar copiar fuente del sistema
echo.
echo [2/4] Buscando fuente TTF del sistema...
if exist "C:\Windows\Fonts\arial.ttf" (
    echo Encontrado: C:\Windows\Fonts\arial.ttf
    copy "C:\Windows\Fonts\arial.ttf" "assets\fonts\arial.ttf"
    echo OK: Fuente copiada a assets\fonts\
) else if exist "C:\Windows\Fonts\segoeui.ttf" (
    echo Encontrado: C:\Windows\Fonts\segoeui.ttf
    copy "C:\Windows\Fonts\segoeui.ttf" "assets\fonts\arial.ttf"
    echo OK: Fuente copiada a assets\fonts\
) else (
    echo ADVERTENCIA: No se encontró fuente TTF en el sistema
    echo Descarga una fuente desde https://fonts.google.com/
    echo y copia el archivo .ttf a: assets\fonts\arial.ttf
)

REM Verificar Make
echo.
echo [3/4] Verificando herramientas de compilacion...
where make >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: 'make' no encontrado
    echo Debes instalar MSYS2 y ejecutar:
    echo   pacman -S make
    echo   pacman -S mingw-w64-x86_64-toolchain
    pause
    exit /b 1
) else (
    echo OK: make disponible
)

REM Verificar G++
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: 'g++' no encontrado
    echo Debes instalar MinGW64 en MSYS2:
    echo   pacman -S mingw-w64-x86_64-toolchain
    pause
    exit /b 1
) else (
    echo OK: g++ disponible
)

REM Compilar
echo.
echo [4/4] Compilando proyecto...
call make rebuild
if %errorlevel% neq 0 (
    echo ERROR: Fallo en la compilacion
    pause
    exit /b 1
) else (
    echo OK: Compilacion exitosa!
)

echo.
echo ============================================
echo   Setup completado exitosamente!
echo ============================================
echo.
echo Para ejecutar el juego:
echo   make run
echo.
echo O ejecuta directamente:
echo   bin\TrafficRacer.exe
echo.
pause

# Script de instalación para Traffic Racer en Windows (MSYS2/MinGW64)
# Uso: .\setup.ps1

Write-Host "`n============================================" -ForegroundColor Green
Write-Host "   Traffic Racer - Setup de Instalacion" -ForegroundColor Green
Write-Host "============================================`n" -ForegroundColor Green

# 1. Crear carpetas necesarias
Write-Host "[1/4] Creando estructura de carpetas..." -ForegroundColor Yellow
$folders = @("assets/fonts", "bin", "obj", "gameplay")

foreach ($folder in $folders) {
    if (-Not (Test-Path $folder)) {
        New-Item -ItemType Directory -Path $folder -Force | Out-Null
        Write-Host "  ✓ Carpeta creada: $folder"
    }
}
Write-Host "OK: Carpetas verificadas`n" -ForegroundColor Green

# 2. Copiar fuente del sistema
Write-Host "[2/4] Buscando fuente TTF del sistema..." -ForegroundColor Yellow

$fontSource = $null
$possibleFonts = @(
    "C:\Windows\Fonts\arial.ttf",
    "C:\Windows\Fonts\segoeui.ttf",
    "C:\Windows\Fonts\calibri.ttf"
)

foreach ($font in $possibleFonts) {
    if (Test-Path $font) {
        $fontSource = $font
        Write-Host "  ✓ Encontrado: $font"
        break
    }
}

if ($fontSource) {
    Copy-Item $fontSource -Destination "assets/fonts/arial.ttf" -Force
    Write-Host "  ✓ Fuente copiada a assets/fonts/`n" -ForegroundColor Green
} else {
    Write-Host "  ⚠ ADVERTENCIA: No se encontró fuente TTF en el sistema" -ForegroundColor Yellow
    Write-Host "    Descarga una fuente desde https://fonts.google.com/" -ForegroundColor Yellow
    Write-Host "    y copia el archivo .ttf a: assets/fonts/arial.ttf`n" -ForegroundColor Yellow
}

# 3. Verificar herramientas
Write-Host "[3/4] Verificando herramientas de compilacion..." -ForegroundColor Yellow

$tools = @("make", "g++")
$toolsOk = $true

foreach ($tool in $tools) {
    try {
        $null = & $tool --version 2>$null
        Write-Host "  ✓ $tool disponible" -ForegroundColor Green
    } catch {
        Write-Host "  ✗ $tool NO encontrado" -ForegroundColor Red
        $toolsOk = $false
    }
}

if (-Not $toolsOk) {
    Write-Host "`n  ERROR: Herramientas faltantes" -ForegroundColor Red
    Write-Host "  Instala MSYS2 y ejecuta:" -ForegroundColor Red
    Write-Host "    pacman -S make" -ForegroundColor Red
    Write-Host "    pacman -S mingw-w64-x86_64-toolchain" -ForegroundColor Red
    exit 1
}
Write-Host "OK: Todas las herramientas disponibles`n" -ForegroundColor Green

# 4. Compilar
Write-Host "[4/4] Compilando proyecto..." -ForegroundColor Yellow
& make rebuild

if ($LASTEXITCODE -ne 0) {
    Write-Host "ERROR: Fallo en la compilacion" -ForegroundColor Red
    exit 1
}

Write-Host "`n============================================" -ForegroundColor Green
Write-Host "   Setup completado exitosamente!" -ForegroundColor Green
Write-Host "============================================`n" -ForegroundColor Green

Write-Host "Para ejecutar el juego:" -ForegroundColor Cyan
Write-Host "  make run" -ForegroundColor White
Write-Host "`nO ejecuta directamente:" -ForegroundColor Cyan
Write-Host "  .\bin\TrafficRacer.exe" -ForegroundColor White
Write-Host ""

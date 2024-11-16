#!/bin/sh

if [ ! -d "build" ] || [ "CMakeLists.txt" -nt "build/Makefile" ]; then
  echo "Configuración inicial o cambios en CMakeLists.txt detectados. Ejecutando 'cmake -B build'..."
  cmake -B build
fi

echo "Compilando el proyecto..."
cmake --build build

EXECUTABLE="build/bin/sfml-game"
if [ -f "$EXECUTABLE" ]; then
  echo "Ejecutando el juego..."
  "$EXECUTABLE"
else
  echo "El ejecutable '$EXECUTABLE' no se encontró."
fi

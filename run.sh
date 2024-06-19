#!/bin/bash

# Erstellen eines Build-Verzeichnisses, wenn es nicht existiert
mkdir -p build
cd build

# Konfigurieren des Projekts mit CMake (Debug-Modus aktivieren)
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Bauen des Projekts (mit Debug-Flags)
make

# Ausführen des Programms mit 2 Prozessen
mpirun -np 2 ./bin/DataAnalysisSystem

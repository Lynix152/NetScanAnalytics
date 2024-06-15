#!/bin/bash

# Erstellen eines Build-Verzeichnisses, wenn es nicht existiert
mkdir -p build
cd build

# Konfigurieren des Projekts mit CMake
cmake ..

# Bauen des Projekts
make

# Ausführen des Programms mit 4 Prozessen
mpirun -np 2 ./netscan

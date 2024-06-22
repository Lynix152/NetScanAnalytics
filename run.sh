#!/bin/bash

# Erstellen eines Build-Verzeichnisses, wenn es nicht existiert
mkdir -p build
cd build

# Konfigurieren des Projekts mit CMake (Debug-Modus aktivieren)
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Bauen des Projekts (mit Debug-Flags)
make

# Core-Dumps aktivieren (für den Fall, dass sie benötigt werden)
ulimit -c unlimited

# Überprüfen, ob das Programm erfolgreich beendet wurde
if ! mpirun -np 2 ./bin/DataAnalysisSystem; then
    echo "Das Programm ist nicht erfolgreich beendet worden."
    echo "Starten des Debuggers..."

    # Starten von gdb für detailliertes Debugging
    gdb -ex run --args mpirun -np 2 ./bin/DataAnalysisSystem
else
    echo "Das Programm wurde erfolgreich beendet."
fi

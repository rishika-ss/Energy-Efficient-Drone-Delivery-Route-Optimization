@echo off
if not exist "bin" mkdir bin
gcc -O3 src/backend/graph.c src/backend/energy_model.c src/backend/tsp_exact.c src/backend/tsp_greedy.c src/backend/tsp_approx.c src/backend/main.c -o bin/optimizer.exe
echo Compilation complete.

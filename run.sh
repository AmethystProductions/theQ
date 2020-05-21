if gcc main.c Simulator/sim.c Simulator/norm.c Simulator/binaries.c -lm -o sim; then
./sim
else
echo "GCC Comilation Error."
fi
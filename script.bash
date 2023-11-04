#!/bin/bash

# # Run 'make run' first
make run
if [ $? -ne 0 ]; then
    echo "Make run failed."
    exit
fi

# Check if gnuplot is installed
if ! command -v gnuplot &> /dev/null
then
    echo "gnuplot was not found."
    exit
fi

# Check if data.txt exists in the current directory
if [ ! -f "data.txt" ]; then
    echo "data.txt does not exist in the current directory."
    exit
fi

# Create a gnuplot script with the provided commands
gnuplot_script=$(cat <<'END_SCRIPT'
set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'temps_execution.png'

set title "Comparaison des temps d'exécution des algorithmes de tree"
set xlabel "Nombre de données"
set ylabel "Temps d'exécution (s)"

set xrange [5000:100000]  # Définit la portée de l'axe x de 100 à 100000
set key outside
set grid

plot "data.txt" index 0 using 2:3 with linespoints title 'Bubble Sort', \
    "data.txt" index 1 using 2:3 with linespoints title 'Selection Sort'
END_SCRIPT
)

# Run the gnuplot script
echo "$gnuplot_script" | gnuplot

# Check if the PNG file was created
if [ -f "temps_execution.png" ]; then
    echo "Graph generated as temps_execution.png."
else
    echo "Failed to generate graph."
fi
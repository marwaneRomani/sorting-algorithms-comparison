#!/bin/bash

# Run 'make run' first
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
set xrange [1000:100000]  # Définit la portée de l'axe x de 1000 à 100000
set ytics 0, 0.01        # Set the y-axis tics starting at -1 and incrementing by 0.1
set key outside
set key outside

set grid

plot "data.txt" index 0 using 2:3 with linespoints title 'Bubble sort' lc rgb 'blue' pt 1, \
    "data.txt" index 1 using 2:3 with linespoints title 'heap sort' lc rgb 'red' pt 1 , \
    "data.txt" index 2 using 2:3 with linespoints title 'Selection sort' lc rgb 'yellow' pt 1, \
    "data.txt" index 3 using 2:3 with linespoints title 'qwik sort' lc rgb 'purple' pt 1, \
    "data.txt" index 4 using 2:3 with linespoints title 'inserion sort' lc rgb 'steelblue' pt 1 

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
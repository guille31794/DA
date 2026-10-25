# Título de cada eje.

set xlabel 'n'
set ylabel 't(n) (tiempo en segundos)'

# Rejilla.

set grid linestyle -1

# Posición de la leyenda.

set key left top

# Estilo de presentación (puntos interpolados linealmente).

set style data linespoints
set linetype 1 pointtype 5 pointsize 0.5 linecolor rgb 'blue' 
set linetype 2 pointtype 7 pointsize 0.5 linecolor rgb 'red' 

# Codificación y terminal.

set encoding locale
set terminal pdf size 16cm,10cm linewidth 2

# Creación de los ficheros PDF.

set output 'prueba-1.pdf'
plot 'prueba-1.tmp' title 'Fibonacci recursivo trivial'

set output 'prueba-2.pdf'
plot 'prueba-2.tmp' title 'Fibonacci dinámico' linetype 2

set output 'pruebas-1-y-2.pdf'
plot 'prueba-1.tmp' title 'Fibonacci recursivo trivial', \
     'prueba-2.tmp' title 'Fibonacci dinámico'

set term png
set out "thermistor.png"
set grid
set key box
set title "Variacion de la resistencia de un termistor NTC"
set xlabel "Tempatura (K)"
set ylabel "Resistencia (KOhms)"
f(x) = 9.91 * exp(a*(1/x-1/296.15))
fit f(x) 'data.txt'\
using 2:3 via a
plot 'data.txt'using 2:3 title 'datos experimentales', f(x) title 'funcion de ajuste' 

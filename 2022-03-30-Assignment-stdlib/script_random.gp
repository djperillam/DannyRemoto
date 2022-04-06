set term pdf
set out "random_pdf.pdf"
set grid
set key box
set title "Histograma siguiendo una distribución normal"
set xlabel "dominio de valores"
set ylabel "frecuencia"
plot 'data_seed1.txt'using 2:3 title 'seed = 1' w l, 'data_seed2.txt'using 2:3 title 'seed = 2' w l,'data_seed5.txt'using 2:3 title 'seed = 5' w l 
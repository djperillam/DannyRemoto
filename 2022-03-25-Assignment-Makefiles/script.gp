set term pdf
set out "thermistor.pdf"
# set xlabel "Nterms"
# set ylabel "Percentual difference"
f(x) = 9.91 * exp(a*(1/x-1/296.15))
fit f(x) 'data.txt'\
using 2:3 via a
plot 'data.txt'using 2:3, f(x)

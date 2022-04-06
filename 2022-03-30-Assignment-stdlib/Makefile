all: random_pdf.pdf
	xdg-open random_pdf.pdf

random_pdf.pdf: data_seed1.txt data_seed2.txt data_seed5.txt script_random.gp
	gnuplot script_random.gp

data_seed1.txt: random_pdf.x
	./random_pdf.x 1 5000 3.5 0.4 2.7 4.6 50 > data_seed1.txt

data_seed2.txt: random_pdf.x
	./random_pdf.x 2 5000 3.5 0.4 2.7 4.6 50 > data_seed2.txt

data_seed5.txt: random_pdf.x
	./random_pdf.x 5 5000 3.5 0.4 2.7 4.6 50 > data_seed5.txt

random_pdf.x:  random_pdf.cpp
	g++ random_pdf.cpp -o random_pdf.x

clean:
	rm -f *.x *.txt *.pdf

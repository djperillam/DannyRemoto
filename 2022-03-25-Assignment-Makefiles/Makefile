all: article.pdf
	xdg-open article.pdf

article.pdf: thermistor.png
	pdflatex article.tex

thermistor.png: data.txt script.gp
	gnuplot script.gp

clean:
	rm -f *.png *.log *.aux *.tex~ *.pdf 

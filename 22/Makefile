all: build run report

build: sources/main.cpp
	g++ sources/main.cpp -o result/main 

run: result/main
	./result/main > ./result/output.txt

report: sources/report.tex
	convert -density 1200 -resize 1000x800 sources/scheme.svg result/scheme.png
	pdflatex --shell-escape sources/report.tex
	rm -f report.aux report.log texput.log
	mv report.pdf result/


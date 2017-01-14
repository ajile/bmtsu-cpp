all: build run print

build: sources/main.cpp
	g++ sources/main.cpp -o result/main

run: result/main
	result/main sources/F sources/G > result/output.txt

print: result/output.txt
	cat result/output.txt

#!/bin/bash

NAME=report
TEX=pdflatex
latexmk -$TEX -synctex=1 -interaction=nonstopmode -shell-escape -pv -quiet $NAME.tex && latexmk -c -silent $NAME.tex 2> /dev/null

#!/bin/bash
git clone --quiet "https://github.com/LoganSDN/template_class.git" template
g++ template/sed.cpp -o template/sed
mkdir -p class
mkdir -p class_def
for (( i=1; i<=$#; i++)); 
do
	./template/sed template/template.cpp "€" ${!i}
	./template/sed template/template.hpp "€" ${!i}
	mv template/template.cpp.replace class_def/${!i}.cpp
	mv template/template.hpp.replace class/${!i}.hpp
done
rm -rf template
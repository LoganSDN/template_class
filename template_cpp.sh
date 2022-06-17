#!/bin/zsh
git clone --quiet "https://github.com/LoganSDN/template_class.git" template
g++ template/sed.cpp -o template/sed
./template/sed template/template.cpp "€" $1
./template/sed template/template.hpp "€" $1
mkdir -p class
mkdir -p class_def
mv template/template.cpp.replace class_def/$1.cpp
mv template/template.hpp.replace class/$1.hpp
rm -rf template
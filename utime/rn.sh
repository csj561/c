#!/bin/sh
name=`pwd|sed 's/^.*\///g'`;
soure=`ls *.cpp`;
#mv $(soure) $(name)'.cpp'
make clean;
echo mv ${soure} ${name}'.cpp';
mv ${soure} ${name}'.cpp';

#!/bin/bash

#Run Front end with transaction sessions && Save each result in seperate files
for file in /test.*             
do 
    ${file} < ./Main.java | cd output | > ${file%_*}_output.txt;
done

#Concats all seperate files into 1 merged transaction file -> save to Master.txt
cat /output.* > Master.txt
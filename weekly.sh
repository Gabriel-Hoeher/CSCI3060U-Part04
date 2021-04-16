#!/bin/bash

#Weekly Script

for i in {1..5}
	do
		#Run Front end 
		CurrentBank.txt < ./Main.cpp | cd output | > ${file%_*}_output.txt;
		
		#Run Back end     

		#Updates the Master Bank Accounts file with the day before's output
		
		${file%_*}_output.txt > Master.txt;
		Master.txt < ./Main.java > CurrentBank.txt

	done
done
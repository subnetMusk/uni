#!/bin/bash

numero=-1
while [ $numero -lt 0 ] || [ $numero -gt 10 ]
do
	echo "Inserire un numero compreso tra 0 e 10 (estremi inclusi):"
	read numero
done
echo "Numero inserito --> $numero"

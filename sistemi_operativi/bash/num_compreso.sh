#!/bin/bash

echo "Inserire un numero compreso tra 0 e 10 (estremi inclusi): ";
read numero
if [ $numero -le 10 ] && [ $numero -ge 0 ] ; then
	echo "Il numero ($numero) è compreso tra 0 e 10"
else
	echo "Il numero ($numero) NON è compreso tra 0 e 10"
fi

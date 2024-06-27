#!/bin/bash
somma=0

for arg in $@ ; do
	((somma=$somma+$arg*$arg));
done
echo $somma;


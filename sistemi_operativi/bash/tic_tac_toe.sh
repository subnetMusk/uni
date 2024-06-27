#!/bin/bash 
# GNU bash, version 4.4.20
# leonardo soligo
continua=1
while [ $continua -eq 1 ]; do
	echo "______________________________________"
	echo "______________________________________"
	echo ""
	
	echo "Scegli la modalità di gioco:"
	echo "1) 1 vs 1"
	echo "2) vs CPU"
	echo "3) esci"
	read scelta
	if [ $scelta -eq 1 ]; then
		echo "Inserisci il nome del primo giocatore:"
		read nome1
		echo "Inserisci il nome del secondo giocatore:"
		read nome2
	elif [ $scelta -eq 2 ]; then
		echo "Inserisci il tuo nome:"
		read nome1
		nome2="CPU"
	else
		continua=0
		break
	fi
	echo ""
	if [ $scelta != 3 ]; then
		partita=1
		giocatore=1
		array=(0 0 0 0 0 0 0 0 0)
		index=0
		echo -n " "
		while [ $index -lt ${#array[@]} ]; do
			echo -n $index
			if [ $(($((index+1))%3)) -gt 0 ]&&[ $index -le 7 ]; then
				echo -n " | "
			fi 
			if [ $index -lt 6 ] && [ $(($((index+1))%3)) -eq 0 ]; then
				echo ""
				echo " ----------"
				echo -n " "
			fi
			index=$((index+1))
		done
		echo ""
		while [ $partita -eq 1 ]; do
			mossa=-1
			vittoria=0
			while [ $mossa -lt 0 ]; do
				echo ""
				if [ $giocatore -eq 1 ]; then
					echo -n $nome1
				else
					echo -n $nome2
				fi
				echo -n " fai la tua mossa (inserire il numero della casella da riempire): "
				if [ $scelta -eq 1 ] || [[ $scelta -eq 2  &&  $giocatore -eq 1 ]]; then
					read mossa
				else
					if [ $giocatore -eq 2 ]; then
						index=$(($RANDOM%(8-0+1)+0))
						while [ $mossa -eq -1 ]; do
							if [ ${array[$index]} -eq 0 ]; then
								mossa=$index
							fi
							index=$(($((index+1))%8))
						done
					fi
					echo -n $mossa
				fi
				
				if [ $mossa -ge 0 ] && [ $mossa -le 8 ]; then
					if [ ${array[$mossa]} -eq 0 ]; then
						array[$mossa]=$giocatore

						#giocatore ha vinto
						if [ $(($mossa%3)) -eq 0 ]; then #prima colonna
							if [ ${array[$mossa]} -eq ${array[$(($mossa+1))]} ] && [ ${array[$mossa]} -eq ${array[$(($mossa+2))]} ]; then #orizzontale
								vittoria=1
							fi

							if [ $mossa -eq 0 ]; then #prima riga
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[8]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[3]} ] && [ ${array[$mossa]} -eq ${array[6]} ]; then
									vittoria=1
								fi
							fi

							if [ $mossa -eq 3 ]; then #seconda riga
								if [ ${array[$mossa]} -eq ${array[0]} ] && [ ${array[$mossa]} -eq ${array[6]} ]; then
									vittoria=1
								fi
							fi

							if [ $mossa -eq 6 ]; then #terza riga
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[2]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[3]} ] && [ ${array[$mossa]} -eq ${array[0]} ]; then
									vittoria=1
								fi
							fi
						fi
						
						if [ $(($(($mossa+2))%3)) -eq 0 ]; then #seconda colonna
							if [ ${array[$mossa]} -eq ${array[$(($mossa-1))]} ] && [ ${array[$mossa]} -eq ${array[$(($mossa+1))]} ]; then #orizzontale
								vittoria=1
							fi

							if [ $mossa -eq 1 ]; then #prima riga
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[7]} ]; then
									vittoria=1
								fi
							fi

							if [ $mossa -eq 4 ]; then #seconda riga
								if [ ${array[$mossa]} -eq ${array[0]} ] && [ ${array[$mossa]} -eq ${array[8]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[2]} ] && [ ${array[$mossa]} -eq ${array[6]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[1]} ] && [ ${array[$mossa]} -eq ${array[7]} ]; then
									vittoria=1
								fi
							fi
							if [ $mossa -eq 7 ]; then #terza riga
								if [ ${array[$mossa]} -eq ${array[6]} ] && [ ${array[$mossa]} -eq ${array[8]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[1]} ]; then
									vittoria=1
								fi
							fi
						fi

						if [ $(($(($mossa+1))%3)) -eq 0 ]; then #terza colonna
							if [ ${array[$mossa]} -eq ${array[$(($mossa-1))]} ] && [ ${array[$mossa]} -eq ${array[$(($mossa-2))]} ]; then #orizzontale
								vittoria=1
							fi

							if [ $mossa -eq 2 ]; then #prima riga
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[6]} ]; then 
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[5]} ] && [ ${array[$mossa]} -eq ${array[8]} ]; then 
									vittoria=1
								fi
							fi

							if [ $mossa -eq 5 ]; then #seconda
								if [ ${array[$mossa]} -eq ${array[2]} ] && [ ${array[$mossa]} -eq ${array[8]} ]; then
									vittoria=1
								fi
							fi
							if [ $mossa -eq 8 ]; then #terza riga
								if [ ${array[$mossa]} -eq ${array[5]} ] && [ ${array[$mossa]} -eq ${array[0]} ]; then
									vittoria=1
								fi
								if [ ${array[$mossa]} -eq ${array[4]} ] && [ ${array[$mossa]} -eq ${array[0]} ]; then
									vittoria=1
								fi
							fi
						fi
					else
						echo "mossa non valida!"
						mossa=-1
					fi
				else
					echo "mossa non valida!"
					mossa=-1
				fi
			done
			echo ""
			echo -n " "
			index=0
			while [ $index -lt ${#array[@]} ]; do
				if [ ${array[$index]} -eq 0 ]; then
					echo -n " "
				fi
				if [ ${array[$index]} -eq 1 ]; then
					echo -n "x"
				fi
				if [ ${array[$index]} -eq 2 ]; then
					echo -n "o"
				fi
				if [ $(($((index+1))%3)) -gt 0 ]&&[ $index -le 7 ]; then
					echo -n " | "
				fi 
				if [ $index -lt 6 ] && [ $(($((index+1))%3)) -eq 0 ]; then
					echo ""
					echo " ----------"
					echo -n " "
				fi
				index=$((index+1))
			done
			echo ""
			echo "------------------------------------"
			
			if [ $vittoria -eq 1 ]; then
				if [ $giocatore -eq 1 ]; then
					echo -n $nome1
				else
					echo -n $nome2
				fi
				echo -n " HA VINTO!"
				echo ""
				partita=0
			fi

			if [ $giocatore -eq 1 ]; then
				giocatore=2
			else
				giocatore=1
			fi

			#controllo se non ci sono più caselle libere
			if [ $partita -eq 1 ]; then
				index=0
				vuoto=1
				while [ $index -lt ${#array[@]} ]; do
					if [ ${array[$index]} -eq 0 ]; then
						vuoto=0
					fi
					index=$((index+1));
				done

				if [ $vuoto -eq 1 ]; then
					echo " "
					echo "PAREGGIO"
					partita=0
				fi
			fi
		done

		echo "Vuoi fare un'altra partita? (y/n)"
		read scelta1
		if [ $scelta1 != 'y' ]; then
			continua=0
		fi
	fi
done

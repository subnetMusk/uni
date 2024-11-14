import base64
import string
import math

''' ------ FUNZIONI DI BASE -------------------------------------------- '''

# Funzione che legga interamente il contenuto di un file di testo
# es. filename = "documento.txt"
def read_content(filename):
  with open(filename, "r") as file:
    content = file.read()
  return content

# Funzione che converta una stringa in base64 ad ascii
def base64_to_string(base64_string):
    base64_bytes = base64_string.encode('ascii')
    ascii_bytes = base64.b64decode(base64_bytes)
    ascii_string = ascii_bytes.decode('ascii')
    return ascii_string

# Funzione che converta da ascii a base64
def string_to_base64(ascii_string):
    ascii_bytes = ascii_string.encode('ascii')
    base64_bytes = base64.b64encode(ascii_bytes)
    base64_string = base64_bytes.decode('ascii')
    return base64_string

# Funzione che converta da ascii a binario
def string_to_binary(ascii_string):
    binary_string = ' '.join(format(ord(char), '08b') for char in ascii_string)
    return binary_string

# Funzione che converta da binario ad ascii
def binary_to_string(binary_string):
    ascii_string = ''.join(chr(int(byte, 2)) for byte in binary_string.split())
    return ascii_string

''' -------------------------------------------------------------------- '''


''' ------ CIFRARI ----------------------------------------------------- '''

# Funzione che risolva il cifrario di cesare
# pos = numero intero che rappresenta lo 'shift' di ogni lettera 
# es. C (cipher_text) --> G (plain_text): pos=4
def caesar_cipher(cipher_text, pos):
  plain_text = ''.join([chr(ord(c) + pos) for c in cipher_text])
  return plain_text

# Funzione che risolva il cifrario di cesare ma con i soli caratteri alfabetici
def find_index(string, char):
  index = 0
  for c in string:
    if c == char:
      return index
    index += 1
  return -1
    
def caesar_cipher_alpha(cipher_text, pos):
  alphabet = string.ascii_lowercase
  leng = len(alphabet)

  plain_text = ""
  for c in cipher_text:
    f = False
    if c.isupper():
      f = True
      c = c.lower()
    index_c = find_index(alphabet, c)
    if index_c != -1:
      char = alphabet[(index_c + pos) % leng]
      if f:
        char = char.upper()
      plain_text += char
    else:
      plain_text += c
  return plain_text

# Funzione che risolva il cifrario di vigenere
def vigenere(enc_text, key):
	alphabet_ext = string.ascii_lowercase + string.ascii_uppercase
	alphabet = string.ascii_uppercase
	
	len_text = len(enc_text)
	repetitions = math.ceil(len_text/len(key))
	key_repeated = key * repetitions
	key_repeated = key_repeated[:len_text]
	
	plain_text = ""
	k_index = 0
	for c in enc_text:
		current_k = key_repeated[k_index % len(key_repeated)]
		if find_index(alphabet_ext, c) != -1:
			f = False
			if c.islower():
				f = True
				c = c.upper()
			
			index = find_index(alphabet, c) - find_index(alphabet, current_k)
			char = alphabet[index % len(alphabet)]
			if f:
				char = char.lower()
			plain_text += char
			k_index += 1
		else:
			plain_text += c
	return plain_text
      
''' -------------------------------------------------------------------- '''

''' ------ SOSTITUZIONI CARATTERI--------------------------------------- '''
# Funzione che ritorna un dizionario del tipo "carattere" : "numero di volte che esso si ripete nel testo"
# ordinato in maniera decrescente (dal carattere più frequente a quello meno frequente)
def frequency(text):
  freq = {}
  for c in text:
    if c.upper() in freq.keys():
      freq[c.upper()] += 1
    else:
      freq[c.upper()] = 1

  freq = dict(sorted(freq.items(), key=lambda item: item[1], reverse=True))
  return freq

# Funzione che riceve in ingresso un testo e lo ritorna dopo aver sostituito le lettere come definito dal dizionario
# sostituzioni ("lettera originale" : "lettera finale", esempio txt = "abc", sost ={"b" : "d", "c" : "e"} -> txt = "ade")
# ATTENZIONE: è preferibile che chiavi e valori del dizionario siano maiuscoli
def substitute(testo, sostituzioni):
    plain = ""
    for c in testo:
        if c.upper() in sostituzioni.keys():
            f = False
            if c.islower():
              f = True
              c = c.upper()
            char = sostituzioni[c]
            if f:
              char = char.lower()
            plain += char
        else:
            plain += c
    return plain
    
''' -------------------------------------------------------------------- '''

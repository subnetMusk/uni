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
      
''' -------------------------------------------------------------------- '''





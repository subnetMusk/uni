import base64
import string
import math
import binascii

''' ------ ENCODING ---------------------------------------------------- '''

# Funzione che legge interamente il contenuto di un file di testo
# es. filename = "documento.txt"
def read_content(filename):
  with open(filename, "r") as file:
    content = file.read()
  return content

''' BASE 64'''
# Funzione che converte una stringa in base64 ad ascii
def base64_to_string(base64_string):
    base64_bytes = base64_string.encode('ascii')
    ascii_bytes = base64.b64decode(base64_bytes)
    ascii_string = ascii_bytes.decode('ascii')
    return ascii_string

# Funzione che converte da ascii a base64
def string_to_base64(ascii_string):
    ascii_bytes = ascii_string.encode('ascii')
    base64_bytes = base64.b64encode(ascii_bytes)
    base64_string = base64_bytes.decode('ascii')
    return base64_string
''''''

''' BASE 32 '''
def base32_to_string(b32_enc):
    decoded_bytes = base64.b32decode(b32_enc)
    decoded_str = decoded_bytes.decode('utf-8')
    return decoded_str

def string_to_base32(ascii_string):
    ascii_bytes = ascii_string.encode('ascii')
    base32_bytes = base64.b32encode(ascii_bytes)
    base32_string = base32_bytes.decode('ascii')
    return base32_string
''''''

''' BINARIO'''
# Funzione che converte da ascii a binario
def string_to_binary(ascii_string):
    binary_string = ' '.join(format(ord(char), '08b') for char in ascii_string)
    return binary_string

# Funzione che converte da binario ad ascii
def binary_to_string(binary_string):
    ascii_string = ''.join(chr(int(byte, 2)) for byte in binary_string.split())
    return ascii_string
''''''

''' HEX '''
def ascii_to_hex(ascii_string):
    ascii_bytes = ascii_string.encode('ascii')
    encoded = binascii.hexlify(ascii_bytes).decode()
    return encoded

def hex_to_ascii(hex_str):
    decoded = binascii.unhexlify(hex_str).decode()
    return decoded
''''''

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

def vigenere_s(enc_text, key):
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
			
			index = find_index(alphabet, c) + find_index(alphabet, current_k)
			char = alphabet[index % len(alphabet)]
			if f:
				char = char.lower()
			plain_text += char
			k_index += 1
		else:
			plain_text += c
	return plain_text

# è esattamente come caesar -> ROT13 rimpiazza la lettera con la lettera 13 posizioni avanti
def ROTencode(message, pos):
    alphabet = string.printable
    leng = len(alphabet)
    rot13_enc = ''
    for c in message:
        i = alphabet.index(c)
        rot13_enc += alphabet[(i+pos)%leng]
    return rot13_enc

def ROTdecode(rot_enc, pos):
    alphabet = string.printable
    leng = len(alphabet)
    text = ""
    for c in rot_enc:
      i = alphabet.index(c)
      text += alphabet[(i - pos) % leng]
    return text

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

''' ------ WEB EXPLOITATION -------------------------------------------- '''

''' MODIFICARE I COOKIES DI UNA PAGINA '''
import requests

# Creare una sessione per persistenza dei cookie
session = requests.Session()

# Effettua una richiesta per ottenere i cookie
response = session.get('http://target.com')
print(response.cookies)  # Leggere i cookie

# Modificare e inviare i cookie in una successiva richiesta
session.cookies.set('session', 'new_value')  # Impostare un valore di cookie
response = session.get('http://target.com/another_page')
print(response.text)
''''''

''' INVIARE UNA RICHIESTA POST '''
import requests

url = "http://target.com/login"
data = {"username": "admin", "password": "password"}
response = requests.post(url, data=data)

print(response.text)
''''''

''' INVIARE UNA RICHIESTA GET '''
headers = {
    "User-Agent": "Mozilla/5.0",
    "Authorization": "Bearer token123"
}
response = requests.get("http://target.com/secure", headers=headers)
print(response.text)
''''''

''' INTERCETTARE RICHIESTE HTTP '''
from http.server import HTTPServer, BaseHTTPRequestHandler

class SimpleHTTPRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        print("Richiesta GET ricevuta con percorso:", self.path)
        self.send_response(200)
        self.end_headers()
        self.wfile.write(b'Hello, world!')

httpd = HTTPServer(('localhost', 8000), SimpleHTTPRequestHandler)
httpd.serve_forever()
''''''

''' BRUTEFORCE ATTACK CON PAYLOAD PERSONALIZZATI '''
import requests

url = "http://target.com/login"
possible_passwords = ["1234", "password", "admin"]

for password in possible_passwords:
    response = requests.post(url, data={"username": "admin", "password": password})
    if "Login successful" in response.text:
        print(f"Password trovata: {password}")
        break
''''''

''' INTERCETTARE IL TRAFFICO HTTP '''
from scapy.all import sniff

# Filtra solo le richieste HTTP
def packet_callback(packet):
    if packet.haslayer('Raw'):  # Individua i dati raw nei pacchetti HTTP
        print(packet['Raw'].load)

sniff(filter="tcp port 80", prn=packet_callback, count=10)
''''''

''' -------------------------------------------------------------------- '''

''' ------ COMANDI TERMINALE ------------------------------------------- 

>>  git show <file> 
    The git show command is used to view the changes of a specific commit

    Esempio: picoCTF/commitment_issues
      Il file presenta una sola riga con la scritta 'TOP SECRET':
        >> git show message.txt           
        commit 42942c9c605b30100f5d859ef6e172027447c0db (HEAD -> master)
        Author: picoCTF <ops@picoctf.com>
        Date:   Tue Mar 12 00:06:23 2024 +0000

            remove sensitive info

        diff --git a/message.txt b/message.txt
        index 0e0fefc..d552d1e 100644
        --- a/message.txt
        +++ b/message.txt
        @@ -1 +1 @@
        -picoCTF{s@n1t1z3_c785c319}
        +TOP SECRET

>>  steghide info <file>
    Steghide is steganography program which hides bits of a data file in some of 
    the least significant bits of another file in such a way that the existence 
    of the data file is not visible and cannot be proven.

    Steghide is designed to be portable and configurable and features hiding data in bmp, 
    jpeg, wav and au files, blowfish encryption, MD5 hashing of passphrases to blowfish 
    keys, and pseudo-random distribution of hidden bits in the container data.

    Esempio: picoCTF/hide2see
      Viene fornito un solo file di tipo .jpg
        >> steghide info atbash.jpg
        "atbash.jpg":
          format: jpeg
          capacity: 2.4 KB
        Try to get information about embedded data ? (y/n) y
        Enter passphrase: 
          embedded file "encrypted.txt":
            size: 31.0 Byte
            encrypted: rijndael-128, cbc
            compressed: yes

>>  steghide extract -sf <file>
    Estraiamo il file embedded: (la passphrase può essere vuota, come in questo caso)
      >> steghide extract -sf atbash.jpg
      Enter passphrase: 
      wrote extracted data to "encrypted.txt".

>>  xxd <file>
    xxd is a command-line tool that is primarily used for creating and analyzing 
    hexadecimal dumps from files. It can also be used to reverse the process and 
    convert a hexadecimal dump back into binary form.

    Esempio:
      >> xxd atbash.jpg     
      00000000: ffd8 ffe0 0010 4a46 4946 0001 0100 0001  ......JFIF......
      00000010: 0001 0000 ffdb 0043 0006 0405 0605 0406  .......C........
      00000020: 0605 0607 0706 080a 100a 0a09 090a 140e  ................
      00000030: 0f0c 1017 1418 1817 1416 161a 1d25 1f1a  .............%..
      00000040: 1b23 1c16 1620 2c20 2326 2729 2a29 191f  .#... , #&')*)..
      00000050: 2d30 2d28 3025 2829 28ff db00 4301 0707  -0-(0%()(...C...
      00000060: 070a 080a 130a 0a13 281a 161a 2828 2828  ........(...((((
      00000070: 2828 2828 2828 2828 2828 2828 2828 2828  ((((((((((((((((
      00000080: 2828 2828 2828 2828 2828 2828 2828 2828  ((((((((((((((((
      00000090: 2828 2828 2828 2828 2828 2828 2828 ffc0  ((((((((((((((..
      000000a0: 0011 0801 c701 d103 0122 0002 1101 0311  ........."......
      000000b0: 01ff c400 1f00 0001 0501 0101 0101 0100  ................
      000000c0: 0000 0000 0000 0001 0203 0405 0607 0809  ................
      ...

>>  curl <opt> <address>
    `curl` is a command-line tool and library for transferring data with URLs. 
    It supports a wide range of protocols, making it an invaluable tool for fetching,
    uploading, and managing data over the Internet.

    Esempio: (l'opzione -I permette di visualizzare solo l'header della risposta)
      >> curl -I http://mercury.picoctf.net:45028
      HTTP/1.1 200 OK
      flag: picoCTF{r3j3ct_th3_du4l1ty_775f2530}
      Content-type: text/html; charset=UTF-8

'''

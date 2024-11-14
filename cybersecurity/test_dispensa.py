from dispensa import *

''' ENCODING '''
stringa = "ciao, come va? ABCD1234 abcd1234"
b64_string = string_to_base64(stringa)
print(b64_string, "\n", base64_to_string(b64_string))

b32_string = string_to_base32(stringa)
print("\n", b32_string, "\n", base32_to_string(b32_string))

bin_string = string_to_binary(stringa)
print("\n", bin_string, "\n", binary_to_string(bin_string))

hex_string = ascii_to_hex(stringa)
print("\n", hex_string, "\n", hex_to_ascii(hex_string))

''' CIFRARI '''
message = "io a N4poli non ci s0no mai stato ... tantomeno 1n moto"
caesar = caesar_cipher(message, 12)
print("\n", caesar, "\n", caesar_cipher(caesar, -12))

caesar_cipher_a = caesar_cipher_alpha(message, -18)
print("\n", caesar_cipher_a, "\n", caesar_cipher_alpha(caesar_cipher_a, 18))

key = "sHrEk"
vigenere_c = vigenere(message, key)
print("\n", vigenere_c, "\n", vigenere_s(vigenere_c, key))

rot13 = ROTencode(message, 13)
print("\n", rot13, "\n", ROTdecode(rot13, 13))


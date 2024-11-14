# Funzione che legga interamente il contenuto di un file di testo
# es. filename = "documento.txt"
def read_content(filename):
  with open(filename, "r") as file:
    content = file.read()
  return content
    

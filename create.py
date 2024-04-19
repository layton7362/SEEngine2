import os
import sys

def create_file(folder_name, filename, extension):
    # Erstelle den vollständigen Dateipfad
    file_path = os.path.join(folder_name, filename + extension)
    # Überprüfe, ob die Datei bereits existiert
    if os.path.exists(file_path):
        print(f"Die Datei '{file_path}' existiert bereits.")
        return
    # Erstelle die Datei
    with open(file_path, 'w') as file:
        file.write("// Hier könnte Ihr Code stehen\n")
    print(f"Die Datei '{file_path}' wurde erfolgreich erstellt.")

def create_folder(folder_name):
    # Erstelle den Ordner, falls er noch nicht existiert
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
        print(f"Der Ordner '{folder_name}' wurde erfolgreich erstellt.")
    else:
        print(f"Der Ordner '{folder_name}' existiert bereits.")

def main():
    # Überprüfe die Anzahl der Argumente
    if len(sys.argv) != 3:
        print("Verwendung: python script.py FOLDER_NAME FILENAME")
        return

    # Extrahiere die Argumente
    folder_name = sys.argv[1]
    filename = sys.argv[2]

    # Erstelle den Ordner 'src'
    create_folder("src")
    # Erstelle die Datei im 'src'-Ordner
    create_file(os.path.join("src", folder_name), filename, ".cpp")

    # Erstelle den Ordner 'include'
    create_folder("include")
    # Erstelle die Datei im 'include'-Ordner
    create_file(os.path.join("include", folder_name), filename, ".hpp")

if __name__ == "__main__":
    main()

import os
import sys

src_code = '''
#include <{folder_name}/{file_name}.hpp>

{file_name}::{file_name}()
{{
        
}}

{file_name}::~{file_name}()
{{
        
}}
'''

header_code = '''
class {file_name}{{
    
public:
    {file_name}();
    virtual ~{file_name}();
}};
'''

def create_file_header(path,folder_name,file_name):
    file_path = os.path.join(path, file_name + ".hpp")
    if os.path.exists(file_path):
        print(f"Header '{file_path}' existiert bereits.")
        return
    with open(file_path, 'w') as file:
        file.write(header_code.format(file_name = file_name, folder_name=folder_name))
    print(f"Header '{file_path}' wurde erfolgreich erstellt.")

def create_file_source(path, folder_name, file_name):
    file_path = os.path.join(path, file_name + ".cpp")
    if os.path.exists(file_path):
        print(f"Source '{file_path}' existiert bereits.")
        return
    with open(file_path, 'w') as file:
        file.write(src_code.format(file_name = file_name, folder_name=folder_name))
    print(f"Source '{file_path}' wurde erfolgreich erstellt.")

def create_folder(folder_name):
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
        print(f"Der Ordner '{folder_name}' wurde erfolgreich erstellt.")
    else:
        print(f"Der Ordner '{folder_name}' existiert bereits.")

def main():
    if len(sys.argv) != 3:
        print("Verwendung: python script.py FOLDER_NAME FILENAME")
        return

    folder_name = sys.argv[1]
    filename = sys.argv[2]

    create_folder(f"src/{folder_name}")
    create_file_source(os.path.join("src", folder_name),folder_name , filename)

    create_folder(f"include/{folder_name}")
    create_file_header(os.path.join("include", folder_name), folder_name, filename)

if __name__ == "__main__":
    main()

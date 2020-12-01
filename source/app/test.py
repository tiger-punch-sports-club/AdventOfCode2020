def load_file(file_path):
    file = open(file_path, 'r') 
    lines = file.readlines()
    return lines
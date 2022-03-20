##
## EPITECH PROJECT, 2022
## B-MUL-200-NCE-2-1-mydefender-antoine.frankel
## File description:
## rename_file
##

from fileinput import filelineno
import os
from unicodedata import name

filelist = os.listdir()

for i in filelist :
    if i[len(i) - 3:] == "ini" or i[len(i) - 3:] == ".py" or i[len(i) - 3:] == "xml" :
        continue
    name_cut = i[:len(i) - 4]
    print(name_cut)
    old_file_name = i
    new_file_name = f"{name_cut}png"
    os.rename(old_file_name, new_file_name)

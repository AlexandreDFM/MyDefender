##
## EPITECH PROJECT, 2022
## scrapper
## File description:
## generate_spritesheet
##

from turtle import width
from PIL import Image
import os.path
import xml.etree.ElementTree as ET

os.chmod('script.py', 0o777)
filelist = os.listdir()

name_biggest = ""
biggest_width = 0
biggest_height = 0

for i in filelist :
    if i[len(i) - 3:] == "png" :
        img = Image.open(i)
        width, height = img.size
        if biggest_width <= width and biggest_height <= height :
            name_biggest = i
            biggest_width = width
            biggest_height = height
        elif biggest_width <= width or biggest_height <= height :
            print(i)
            print(width)
            print(height)
    else :
        continue

print("The biggest is :")
print(name_biggest)
print(biggest_width)
print(biggest_height)

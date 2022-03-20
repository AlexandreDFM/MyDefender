##
## EPITECH PROJECT, 2022
## scrapper
## File description:
## generate_spritesheet
##

from tkinter import N
from turtle import width
from PIL import Image
import os.path
import xml.etree.ElementTree as ET

os.chmod('script.py', 0o777)
im = Image.open("upgrade_icons.png")

tree = ET.parse('upgrade_icons.xml')
root = tree.getroot()

for child in root:
    print(child.tag, child.attrib)


name_bigger = ""
bigger_width = 0
bigger_height = 0

for cell in root.iter('Cell'):
    name = cell.attrib.get('name')
    x = cell.attrib.get('x')
    y = cell.attrib.get('y')
    width = cell.attrib.get('w')
    height = cell.attrib.get('h')
    new_width = int(width)
    new_height = int(height)
    if bigger_width <= new_width and bigger_height <= new_height :
        name_bigger = name
        bigger_width = int(width)
        bigger_height = int(height)
    elif bigger_width <= new_width or bigger_height <= new_height :
        print(name)
        print(width)
        print(height)

print("The biggest is : ")
print(name_bigger, bigger_width, bigger_height)

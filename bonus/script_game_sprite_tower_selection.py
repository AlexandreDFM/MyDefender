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
im = Image.open("InGame.png")

tree = ET.parse('InGame.xml')
root = tree.getroot()

for child in root:
    print(child.tag, child.attrib)

list = ["dart_monkey", "glue_gunner", "supermonkey", "ninja", "pineapple", "ice", "b"]

for cell in root.iter('Cell'):
    name = cell.attrib.get('name')
    name_cut = name
    for i in list :
        name_cut = name_cut[:len(i)]
        if str(name_cut) == str(i) :
            x = cell.attrib.get('x')
            y = cell.attrib.get('y')
            width = cell.attrib.get('w')
            height = cell.attrib.get('h')
            if (os.path.isfile(str(name))):
                img = Image.open(str(name))
            else:
                img = Image.new('RGBA', (int(width), int(height)), color = (0, 0, 0, 0))
            region = im.crop((int(x), int(y), int(x) + int(width), int(y) + int(height)))
            img.paste(region, (0, 0, int(width), int(height)))
            img.save(f"{str(name)}.png")
            print(name, x, y, width, height)

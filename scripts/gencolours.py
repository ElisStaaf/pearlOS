#!/usr/bin/python3

from sys import argv

colors = {
    "BLACK"        : "0",
    "BLUE"         : "1",
    "GREEN"        : "2",
    "CYAN"         : "3",
    "RED"          : "4",
    "PURPLE"       : "5",
    "BROWN"        : "6",
    "GRAY"         : "7",
    "DARK_GRAY"    : "8",
    "LIGHT_BLUE"   : "9",
    "LIGHT_GREEN"  : "a",
    "LIGHT_CYAN"   : "b",
    "LIGHT_RED"    : "c",
    "LIGHT_PURPLE" : "d",
    "YELLOW"       : "e",
    "WHITE"        : "f"
}

def generate():
    result = "#define INCLUDED_COLOR\n"
    for color in colors:
        result += "#define " + color + " 0x" + colors[color] + "\n"
    for background_color in colors:
        for text_color in colors:
            if background_color != text_color:
                background_code = colors[background_color]
                text_code = colors[text_color]
                result += "#define " + text_color + "_ON_" + background_color + " 0x" + background_code + text_code + "\n"
    return result

def fwrite(filename, data):
    with open(filename, "w") as f:
        return f.write(str(data))   # str() to make sure

def main():
    if len(argv) > 1:
        fwrite(argv[1], generate())
    else:
        print(generate())

if __name__ == "__main__":
    main()

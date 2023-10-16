Import("env")

# access to global build environment
print(env)


html = open("src/web/index.html", "r")


file = open("src/web/index.h", "w") 
file.write("const char MAIN_page[] PROGMEM = R\"=====(\n" + html.read() + "\n)=====\";") 
file.close() 
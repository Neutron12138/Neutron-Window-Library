set filename=main
g++ -finput-charset=UTF-8 -fexec-charset=gbk ^
    "%filename%.cpp" -o "%filename%.exe" ^
    -lglfw3 -lgdi32 -lopengl32 -lglew32 ^
    -I ../../includes/
"%filename%.exe"
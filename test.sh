CC="gcc"
CFLAGS="-Wall -Wextra -Wno-unused-parameter -Wbad-function-cast\
    -Wstrict-prototypes -Wmissing-declarations -Wmissing-prototypes"

# Carpetas en donde están los .o de las partes 1 y 2 del proyecto
# Al ejecutar este script, los .o ya deberían estar creados
CODIGO_PARTE_1="../ProyectoMDII2022/Código parte 1"
CODIGO_PARTE_2="../ProyectoMDII2022/Código parte 2"

EJECUTABLE="a.out"

# Compilar el código que testea
$CC $CFLAGS -O3 -IInterfaces *.c "$CODIGO_PARTE_1"/*.o "$CODIGO_PARTE_2"/*.o -o "$EJECUTABLE"

# Asumiendo que los grafos a testear están en la carpeta Grafos/
for file in Grafos/*
do
    echo "Testeando con '$file'"
    "./$EJECUTABLE" < "$file" || exit 1 # exit 1 para que si falla un test termine todo automáticamente
done



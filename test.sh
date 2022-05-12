CC="gcc"
CFLAGS="-Wall -Wextra -Wno-unused-parameter -Wbad-function-cast\
    -Wstrict-prototypes -Wmissing-declarations -Wmissing-prototypes"

FILES="Chequeos.c"

# Carpetas en donde están los .o de las partes 1 y 2 del proyecto
# Al ejecutar este script, los .o ya deberían estar creados
CODIGO_PARTE_1="../ProyectoMDII2022/Código parte 1"
CODIGO_PARTE_2="../ProyectoMDII2022/Código parte 2"

TEST_GRAFOS="TestGrafos"
TEST_BIPARTITOS="TestBipartitos"
TEST_NO_BIPARTITOS="TestNoBipartitos"

# Compilar los códigos que testea
$CC $CFLAGS -O3 -IInterfaces "$FILES" "$TEST_GRAFOS.c" "$CODIGO_PARTE_1"/*.o "$CODIGO_PARTE_2"/*.o -o "$TEST_GRAFOS" || exit 1
$CC $CFLAGS -O3 -IInterfaces "$FILES" "$TEST_BIPARTITOS.c" "$CODIGO_PARTE_1"/*.o "$CODIGO_PARTE_2"/*.o -o "$TEST_BIPARTITOS" || exit 1
$CC $CFLAGS -O3 -IInterfaces "$FILES" "$TEST_NO_BIPARTITOS.c" "$CODIGO_PARTE_1"/*.o "$CODIGO_PARTE_2"/*.o -o "$TEST_NO_BIPARTITOS" || exit 1

# Asumiendo que los grafos a testear están en la carpeta Grafos/
for file in Grafos/* Bipartitos/* NoBipartitos/*
do
    echo "Testeando con '$file'"
    "./$TEST_GRAFOS" < "$file" || exit 1 # exit 1 para que si falla un test termine todo automáticamente
done


# Asumiendo que los grafos bipartitos a testear están en la carpeta Bipartitos/
for file in Bipartitos/*
do
    echo "Testeando con '$file' (Bipartito)"
    "./$TEST_BIPARTITOS" < "$file" || exit 1 # exit 1 para que si falla un test termine todo automáticamente
done

for file in NoBipartitos/*
do
    echo "Testeando con '$file' (No Bipartito)"
    ./$TEST_NO_BIPARTITOS < "$file" || exit 1 # exit 1 para que si falla un test termine todo automáticamente
done

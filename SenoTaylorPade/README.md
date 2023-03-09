# Instruções

Compile o arquivo C como uma biblioteca compartilhada

```bash
gcc -fPIC -shared -o sen.so sen.c
```

Execute o arquivo plot.py para mostrar o gráfico:
```bash
python plot.py
```

# Dependências
- matplotlib
- numpy
- ctypes
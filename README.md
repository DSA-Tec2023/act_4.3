# Actividad 4.3
## Programación de Estructura de Datos y Algoritmos 

## Información del Proyecto

### Equipo
- Andrés Martínez, A00227463
- Fernanda Granados, A01252895
- Santiago Poblete, A01254609
- Martín Tánori, A01252900

### Makefile 
Este proyecto cuenta con un archivo `makefile`, para ejecutar el proyecto puede utilizar el siguiente comando:
`make run`

Además, para borrar la caché que provenga con el compilar este proyecto puede utilizar el siguiente comando:
`make clean`

## Ejemplo de Entrada y Salida 

### Entrada
```
16
Alexandria Algeciras
Algeciras Ambarli
Ambarli Antwerp
Alexandria Balboa
Balboa Bandar
Bandar Barcelona
Antwerp Bremen
Bremen Busan
Algeciras Cai_Mep
Cai_Mep Callao
Ambarli Cartagena
Barcelona Callao
Cai_Mep Cartagena
Callao Charleston
Cartagena Charleston
Charleston Busan
2
Cai_Mep 2
Cai_Mep 3
```

### Salida 
```
Case 1: 5 ports not reachable from port Cai_Mep with MNP = 2. 
Case 2: 1 ports not reachable from port Cai_Mep with MNP = 3. 
```
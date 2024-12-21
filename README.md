# DCA_2024_25_p9
Practica de control de versiones


## Funcionamiento del programa
Se ha hecho un diario personal donde puedes introducir 
al día una entrada, y leer dias anteriores registrados 
y guardados.

## Bisect 
Habia un error en el commit con el comentario "guardar entrada"
donde se le habia borrado el + 1900 para calcular la fecha. Para ello,
se ha hecho un 

```
git bisect start
```

se ha puesto como `git bisect good 0532d780a5c024e0fcae67f6e0aefa5a414786fb` 
el commit con el comentario "función creada".  

Se ha ido haciendo `git bisect bad` hasta llegar al commit de comentario "obtener fecha de hoy para guardar", que estaba bien. Se le ha puesto `git bisect good` para indicar que estaba bien. 

Se hizo `git bisect reset` y se ha corregido el error.


## Hooks

Se ha creado un pre-commit para que cuando hagas commit pruebe a compilarse y si falla pone un mensaje.

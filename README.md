This project has been created as part of the 42 curriculum by lebeyssa

## 📄 get_next_line

get_next_line est un projet de l’école 42 
dont l’objectif est d’implémenter une fonction capable de lire un fichier 
ligne par ligne, sans en perdre le moindre caractère, 
et en gérant efficacement un buffer de taille variabl.


## Implémenter la fonction :
```
char *get_next_line(int fd);

```
## Cette fonction doit :

retourner la prochaine ligne lue depuis le descripteur de fichier fd,
fonctionner sur plusieurs appels successifs,
gérer proprement le retour de fin de fichier (EOF),
s’adapter à n’importe quelle valeur de BUFFER_SIZE.

## 📁 Structure du projet

```
.
├── get_next_line.h        # Prototypes + includes
├── get_next_line_utils.c  # Fonctions utilitaires
└── get_next_line.c        # focntion principale
```
## 🔧 Compilation

Pour compiler ton projet avec un buffer personnalisé :
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c -o gnl

```
Tu peux varier la taille du buffer :

```
-D BUFFER_SIZE=1
-D BUFFER_SIZE=1000

```
## 📝 Exemple d’utilisation

```
int     fd = open("test.txt", O_RDONLY);
char    *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 🧪 Tester le programme

Créer un fichier de test :
```
echo -e "Hello\nWorld\n42!" > test.txt
```
Compiler et lancer :
```
./gnl test.txt
```
Tester avec Valgrind :
```
valgrind --leak-check=full ./gnl test.txt
```





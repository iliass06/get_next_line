#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

// Cette fonction sera appelée plusieurs fois
void lire_5_octets(int fd)
{
    // 1. VARIABLE STATIQUE : Elle ne meurt pas à la fin de la fonction
    // Elle est initialisée à 0 une seule fois au démarrage du programme.
    static int compteur_appels = 0; 
    
    char *buff;
    int octets_lus;

    // On incrémente le compteur à chaque appel (0 -> 1 -> 2...)
    compteur_appels++; 

    buff = malloc(6); // 5 + 1 pour le \0
    if (!buff)
        return;

    // 2. LECTURE : On continue là où le curseur s'est arrêté la dernière fois
    octets_lus = read(fd, buff, 5);

    // Sécurisation de la chaîne
    if (octets_lus > 0)
        buff[octets_lus] = '\0';
    else
        buff[0] = '\0'; // Si on a fini de lire ou erreur

    // Affichage
    printf("--- Appel numéro %d ---\n", compteur_appels);
    printf("J'ai lu %d octets : [%s]\n\n", octets_lus, buff);

    free(buff);
}

int main()
{
    int fd;

    // 1. Préparation du fichier (on écrit assez de texte pour tester)
    // "Hello World, this is a test for 42" (environ 30 caractères)
    fd = open("tuto_gnl.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
    write(fd, "Hello World, this is a test for 42", 34);
    close(fd);

    // 2. Ouverture réelle en lecture seule
    fd = open("tuto_gnl.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // 3. Appels successifs
    // Le fd reste ouvert entre les appels, donc le curseur avance !
    lire_5_octets(fd);
    lire_5_octets(fd);
    lire_5_octets(fd);
    lire_5_octets(fd);

    // 4. Nettoyage final
    close(fd);
    return (0);
}
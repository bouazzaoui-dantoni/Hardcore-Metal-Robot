# Cahier de suivi de Léna D'ANTONI #
 
### compte-rendu du 18 décembre 2017 : ###
 
première idée de projet --> Hardcore Metal Robot
Deux modes :
- le mode télécommandé. Le robot a comme visage un écran LCD dont les pixel forment un smiley souriant. À l’aide de Bluetooth Electronics on définit 4 boutons qui permettront d’avancer et de reculer, de tourner à droite et à gauche.
Eventuellement lui faire éviter les obstacles si on avance vite.
- le mode musique. Il réagit à la musique : il s’arrête, bouge ses bras (des tiges) dans des sens opposés, et l’écran se modifie pour afficher un autre smiley.
Reste à déterminer du mode d’acquisition du son et d’éventuelles autres réactions du robot (son expression change suivant le style de musique qu’il détecte, par exemple).
 
### compte-rendu du 8 janvier 2018 : ###
 
évolution du projet --> Musical-e Robot

après questionnements et reflexions on décide de mettre en place un robot à plusieurs options. En effet, on se rend compte que c'est trop compliqué de faire réagir le robot à un certain type de son (des musiques).
Il aura les options suivantes :
- robot télécommandé sur des chenilles qui évite les murs grâce un capteur ultra son. Ses déplacements sont gérés par une application bluetooth.
- robot dansant qui diffuse sur une enceinte la musique programmée et danse dessus en tournant sur lui-même et agitant ses bras motorisés
- robot chantant une musique en style 8-bit qu'il aura apprise auparavant.
- robot changeant de tête selon le bouton sur lequel on appuit. Son expression sera diffusée sur un écran LCD.
Les options seront disponibles sur l'application android, l'utilisateur n'aura qu'à choisir la fonctionnalité qu'il veut.
Ces options ne seront peut-être pas toutes réalisées. 
 
matériel : 
- kit chenilles + moteurs + socle 
- deux moteurs continus sur lesquels on collera des tiges pour les bras
- un capteur ultra-son
- un écran LCD 3,5 pouces noir et blanc
- un speaker relié à l'Arduino pour diffuser une musique
- un Piezo Speaker pour la musique en style 8-bit

### compte-rendu du 15 janvier 2018 : ###

Pour des questions de puissance, on décide d'abandonner l'idée des chenilles qui auraient ralenti l'avancée du robot pour des roues omnidirectionnelles plus adaptées, notamment pour son option danse. On essaye pendant 1h30 de comprendre le Motor Control Shield de Arduino, qui était déjà fixé sur les moteurs continus du châssis, mais on n'a pas réussi à trouver de tuto convenable et des codes assez compréhensibles pour être adaptés. 
Finalement on se tourne vers une carte L298N et après quelques recherches et test on finit par réussir à faire tourner les moteurs, donc les roues.

nouveau matériel : 
- roues omnidirectionnelles + châssis
- carte L298N (H-Bridge)

### compte-rendu du 22 janvier 2018 : ###

Nous présentons notre projet devant la classe.

nouveau matériel :
- module bluetooth
- 2 servo-moteurs

Grâce au module, je peux modifier notre code de base (qui permet seulement le déplacement du robot). J'y ajoute tout d'abord 3 nouvelles fonctions :
- forward() qui permet d'aller tout droit en bougeant seulement deux roues
- rigth() qui permet de tourner à droite en faisant tourner toutes les roues dans le sens horaire
- left() qui permet de tourner à gauche en faisant tourner toutes les roues dans le sens antihoraire

Dans le fonction loop() j'inclus des boucles while : tant que l'utilisateur appuie sur 'x', 'y' ou 'z' le code exécutera la fonction forward(), right() ou left().
En revanche le montage avec le module bluetooth ne marche pas, il faudra voir ça dans la semaine.

### compte-rendu du 7 février 2018 : ###

Le cablage pour le bluetooth a enfin été réussi. Premier test d'un code mais la boucle ne marche pas car le robot roule indéfiniment sans changer de direction.

nouveau matériel :
- écran LCD

### compte-rendu du 21 février 2018 : ###

Nouveau code bluetooth avec introduction d'une nouvelle fonction stop() qui arrête le robot. Cette fonction se déclenche losqu'on arrête d'appuyer sur le bouton bluetooth. En changeant également les boucles, le code marche désormais. Seulement une des 3 roues semble avoir un faux contact.
 
 ### compte-rendu du 21 mars 2018 : ###
 
Les roues posent toujours problème même avec une batterie rechargeable de 12V. J'ai essayé chaque roue dans les deux directions pour savoir s'il y en avait une avec un problème particulier mais globalement elles ont du mal à tourner (sauf quand le robot est porté, elles roulent plus facilement mais parfois avec des accroches)

J'ai commencé à mettre en place le code des servo-moteurs (qui servirons de bras au robot). Comme avec la roue, la liaison avec le bluetooth pose problème à cause d'une boucle infini.

nouveau matériel :
- batterie rechargeable 12V
- module SD Arduino

### compte-rendu du 28 mars 2018 : ###

Le code des servo-moteurs tourne toujours à l'infini, il faut vraiment régler ça. Il y a plusieurs possibilités à cela : la boucle est mal choisie, ou bien il y a une mauvaise liaison avec l'application bluetooth.
Avec l'aide d'un des professeurs, nous arrivons à la conclusion que le problème ne vient pas des roues mais apparemment du code. En effet les roues fonctionnent en y appliquant une tension donc la possibilité est que le code soit mal écrit.

Avec toutes les options qui commencent à prendre forme, nous nous demandons comment tous les câblages pourront tenir dans une seule carte Arduino. Il serait donc préférable d'en avoir une méga.

### compte-rendu du 5 avril 2018 : ###

Nous faison la présentaiton de mi-parcours de notre projet.

Nous prenons commande pour une carte Arduino méga.

La roue du motor A est celle qui ne fonctionne pas. Toute seule elle tourne dans un sens et dans l'autre correctement (grâce à un code qui teste les roues). Mais dans le programme principal elle ne fonctionne plus et je ne comprends pas pourquoi. Je décide pour le moment de ne plus l'utiliser.

### compte-rendu du 4 mai 2018 : ###

Nous recevons le carte Arduino Mega. Je rebranche les moteurs, tout re-fonctionne parfaitement. Je rebranche ensuite le bluetooth et rien à y faire ça ne veut pas marcher. C'est une fois chez moi que je me suis rendue compte que j'avais branché le TX et le RX sur des ports non adaptés.

### compte-rendu du 14 mai 2018 : ###

La tête est fixée au corps du robot. Les roues ont de nouveau des problèmes même après recâblage. J'ai re-tenté de brancher le servo-moteur mais il semble prendre beaucoup d'énergie car l'écran clignotte et se brouille.

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

Pour des questions de puissance, on décide d'abandonner l'idée des chenilles qui auraient ralenti l'avancée du robot pour des roues omnidirectionnelles plus adaptées, notamment pour son option danse.

nouveau matériel : 
- roues omnidirectionnelles + châssis
- carte L298N-H-Bridge

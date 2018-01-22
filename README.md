![Polytech](http://www.polytechnice.fr/jahia/jsp/jahia/templates/inc/img/polytech_nice-sophia.png)

Ce projet est réalisé dans le cadre de la formation de prépa intégrée de Polytech'Nice Sophia

# Musical-e Robot #

Le Musical-e Robot est un robot ayant plusieurs fonctionnalités : 
- il peut être télécommandé
- il diffuse de la musique et danse dessus
- il chante des musiques qu'il a apprises dans un style 8-bit
- il peut changer l'expression de son visage

Ces commandes sont choisies grâce à une application bluetooth.

-----------------

#### Matériel ####

- corps
  - un châssis avec des roues omnidirectionnelles qui permettent le déplacement télécommandé du robot
  - deux servo-moteurs qui servent à articuler les bras
  - un écran LCD qui représente la tête du robot, il affiche une expression différente selon le mode choisi
- modules
  - un capteur ultra-son pour faire éviter les obstacles au robot
  - une carte L298N (H-Bridge) qui contrôle les moteurs des roues
  - un module bluetooth HC-06 qui permet la liaison bluetooth entre le téléphone et le robot
  - un buzzer qui permet le diffusion de son dans un style 8-bit

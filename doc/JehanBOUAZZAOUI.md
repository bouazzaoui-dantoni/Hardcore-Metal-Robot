# Cahier de suivi de Jehan BOUAZZAOUI #

Séance du 8 janvier 2018:
Nous avons finalement décidé de créer un robot qui aurait plusieurs options:
-il serait télécommandé,
-il pourrait "chanter" une petite mélodie en style 8-bit
-il diffuserait de la musique et danserait dessus
-il pourrait changer l'expression de son visage
Pour le controler on utilisera une application android et une connexion bluetooth.
Il y aura probablement 4 flèches pour diriger le robot et des boutons pour lui faire éxécuter les différentes actions.
Son visage sera représenté sur un écran. 
La musique sortirait d'une enceinte sur le robot mais nous ne sommes pas encore sûrs de la manière dont nous allons nous y prendre.
Il danserait en bougeant ses bras (deux tiges au bout de deux moteurs) et en tournant sur lui même(chenilles comme Wall-E pour se déplacer).

Séance du 15 janvier 2018:
Finalement nous avons récupéré le châssis que les étudiants de l'année dernière avaient utilisé pour les NERF télécommandés. Il possède des roues omnidirectionnelles liées à trois moteurs, qui permettront au robot de se déplacer dans toutes les directions et de danser.
Un motor shield était installé sur le châssis. Nous avons essayé pendant un moment de comprendre son fonctionnement puis nous avons opté pour le remplacer par un double L298n pour gérer les trois moteurs. Nous avons commencé à découvrir les commandes disponibles et à contrôler un moteur.

Séance du 22 janvier 2018:
On présente d'abord le projet et on écoute les présentation des autres.
On récupère un écran 1.8 SPI TFT 128\*60 pour représenter le visage du robot. Je commence à rechercher des infos sur l'écran (librairies, branchements ...).
On essaye de connecter le module bluetooth mais ça ne fonctionne pas.

Séance du 7 février 2018:
J'arrive à allumer l'écran mais j'ai encore du mal à le controler. Le module bluetooth fonctionne enfin.

Séance du 21 février 2018
J'arrive à controler l'écran. Les premiers visages du robot sont crées et affichés sur l'écran.

Séance du 21 mars 2018
Ma carte arduino est détruite. Pendant la séance j'ai cherché comment faire en sorte que le robot émette de la musique à partir d'une enceinte. J'ai trouvé quelque chose mais je ne peux du coup pas le tester.

Séance du 28 mars 2018
J'ai récupéré une nouvelle carte.J'ai presque fini de coder les visages.

Dernière séance:
Nous passons sur une arduino Mega pour pouvoir mettre en commun nos travaux avec Léna car nous avons besoin de beaucoup d'entrées /sorties. 
J'utilise une librarie qui permet de lire un fichier audio (.wav) à partir d'une carte SD pour émettre de la musique à travers une enceinte reliée à l'arduino. Il y a une musique par émotion correspondant au visage du robot.



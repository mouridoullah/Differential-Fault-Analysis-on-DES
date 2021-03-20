# Differential Fault Analysis on DES Middle Rounds

## Abstract 
```
L'analyse différentielle des pannes (DFA) est une technique cryptographique puissante qui perturbe les calculs 
cryptographiques et exploite des résultats erronés pour déduire des clés secrètes. Au cours de la dernière 
décennie, de nombreux travaux ont décrit et amélioré les techniques DFA contre les chiffrements par blocs, 
montrant ainsi un besoin inhérent de protéger leurs implémentations. Une solution simple et largement
utilisée consiste à effectuer le calcul deux fois et à vérifier que le même résultat est obtenu. Étant 
donné que DFA contre les chiffrements par blocs cible généralement les derniers tours, il n'est pas 
nécessaire de protéger l'ensemble du chiffrement, ce qui permet de gagner du temps de calcul. 
Cependant, le nombre de cartouches à protéger doit être choisi très soigneusement afin d'éviter les failles 
de sécurité. Pour déterminer ce nombre, il faut étudier le ciblage DFA au milieu des rondes du chiffrement. 
Dans cet article, nous abordons ce problème pour l'algorithme Data Encryption Standard (DES). 
Nous décrivons une attaque qui brise DES en introduisant quelques fautes à la fin des rounds 9, 10, 11 ou 12,
 plus ou moins efficacement selon le modèle de faute et le numéro de round.
```
## Introduction
```
```
## Data Encryption Standard
```
```
## Fault Models
```
```
## Attack Description
```
```
### General Principle
```
```
### Wrong-key Distinguishers
```
```
### Chosen Error Position Strategies
```
```
## Attack Simulations
```
```
## How Many Rounds To Protect ?
```
```
## Conclusion
```
```

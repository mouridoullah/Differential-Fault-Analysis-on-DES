# Differential Fault Analysis on DES Middle Rounds

## Abstract 
```
L'analyse différentielle des pannes (DFA) est une technique cryptographique puissante qui perturbe les 
calculs cryptographiques et exploite des résultats erronés pour déduire des clés secrètes. Au cours de 
la dernière décennie, de nombreux travaux ont décrit et amélioré les techniques DFA contre les 
chiffrements par blocs, montrant ainsi un besoin inhérent de protéger leurs implémentations. Une solution
simple et largementutilisée consiste à effectuer le calcul deux fois et à vérifier que le même résultat
est obtenu. Étant donné que DFA contre les chiffrements par blocs cible généralement les derniers tours,
il n'est pas nécessaire de protéger l'ensemble du chiffrement, ce qui permet de gagner du temps de calcul. 
Cependant, le nombre de cartouches à protéger doit être choisi très soigneusement afin d'éviter les failles 
de sécurité. Pour déterminer ce nombre, il faut étudier le ciblage DFA au milieu des rondes du chiffrement. 
Dans cet article, nous abordons ce problème pour l'algorithme Data Encryption Standard (DES). 
Nous décrivons une attaque qui brise DES en introduisant quelques fautes à la fin des rounds 9, 10, 11 ou 
12, plus ou moins efficacement selon le modèle de faute et le numéro de round.
```
## Introduction
```
L'analyse des pannes est une classe d'attaques d'implémentation qui consiste à perturber les calculs cryptographiques pour récupérer des clés secrètes. Parmi ces attaques, on identifie simplement deux familles qui diffèrent par les informations exploitées pour récupérer la clé. L'analyse différentielle des défauts (DFA) [3] exploite la différence entre les résultats corrects et erronés tandis que d'autres attaques se concentrent sur le comportement du calcul corrompu, à savoir si la faute induite provoque effectivement un résultat erroné ou non. Parmi eux, on répertorie les attaques par erreur de sécurité [26] sur les algorithmes d'exponentiation ainsi que Ineffective Fault Analysis (IFA) [9, 23] et Collision Fault Analysis (CFA) [16] contre les implémentations de chiffrements par blocs. IFA et CFA considèrent un adversaire capable de fixer une variable intermédiaire de son choix à une valeur connue (généralement à 0). Si le résultat est erroné ou si un défaut est détecté, l'attaquant sait que la variable intermédiaire était différente de la valeur induite. L'obtention de ces informations pour plusieurs cryptages permet la récupération de clé. Un moyen simple de contrecarrer ce type d'attaque est d'utiliser le masquage des données [2,15] qui est souvent appliqué pour protéger l'implémentation embarquée contre l'analyse de puissance [18]. En effet, le masquage garantit qu'aucune variable intermédiaire unique ne fournit d'informations sur la clé secrète. Cependant, le masquage ne garantit pas l'intégrité du résultat et est donc inefficace contre DFA [5]. Le DFA sur les chiffrements par blocs a été introduit pour la première fois par Biham et Shamir contre DES [3]. Depuis, plusieurs DFA ont été proposés sur AES [4,7,11,13,17,22,25] ainsi que sur d'autres blocs de chiffrement tels que IDEA [10] et CLEFIA [8, 24]. Ces différents travaux démontrent la vulnérabilité des chiffrements par blocs vis-à-vis de DFA et le besoin ultérieur d'inclure des contre-mesures aux implémentations embarquées. Un moyen simple de protéger un algorithme contre DFA consiste à le calculer deux fois et à vérifier si les résultats obtenus sont égaux ou non. Une autre solution similaire consiste à vérifier l'intégrité d'un cryptage par un décryptage et vice versa. Il est également possible d'inclure la redondance et la vérification de cohérence au niveau de l'exploitation; le rapport complexité-sécurité de tels schémas est généralement le même
ordre que celui du calcul doublant [19]. Un avantage du doublement de calcul est l'évolutivité du nombre de tours à protéger. En fait, la plupart des techniques DFA ciblent les derniers cycles du chiffrement par blocs. Pour contrecarrer ces attaques, il suffit de doubler le calcul de ces derniers tours, économisant ainsi du temps de calcul. Cependant, une question demeure: combien de rounds faut-il protéger pour obtenir un bon niveau de sécurité vis-à-vis de DFA? Pour répondre à cette question, nous devons enquêter sur DFA au milieu du chiffrement. Ce problème a été résolu dans [21] par Phan et Yen pour le chiffrement par bloc AES. Ils appliquent des techniques d'analyse de chiffrement par blocs pour améliorer DFA sur
AES et présentent quelques attaques contre les rounds 7, 6 et 5. Concernant DES, l'ouvrage original de Biham et Shamir [3] décrit une attaque qui exploite une faille corrompant soit les rounds 16, 15 ou 14 (et de manière équivalente la fin du round 15, 14 ou 13). Dans sa thèse de doctorat [1], Akkar étudie l'application de techniques de cryptanalyse différentielle pour attaquer des cycles antérieurs de DES. En premier lieu, l'attaquant considéré est supposé être capable d'induire un différentiel de son choix dans la valeur interne DES à la fin d'un tour. La dernière clé ronde est récupérée en devinant toutes les parties de 6 bits indépendamment et en sélectionnant, pour chaque sous-clé, le candidat qui produit le différentiel attendu à la sortie S-box le plus fréquemment. Les attaques obtenues sont assez efficaces mais, comme mentionné par l'auteur, le modèle de faute n'est pas réaliste. Akkar applique ensuite cette attaque sous deux modèles de défauts plus réalistes: un commutateur à un seul bit à une position fixe (dans la partie gauche de l'état interne DES) et un commutateur à un bit à une position aléatoire (dans la partie droite de l'état interne DES ). Pour le modèle d'erreur de bit de position fixe, l'attaque a besoin de quelques centaines d'injections de fautes à la fin du tour 11, et elle échoue au tour 9 (l'attaque du tour 10 n'est pas prise en compte). Pour le modèle d'erreur de bit de position aléatoire, l'attaque a besoin de quelques dizaines d'injections de fautes à la fin du round 12, et elle échoue au round 11. Dans cet article, nous généralisons et améliorons l'attaque décrite par Akkar dans [1]. Nous considérons divers modèles de défaut réalistes pour une erreur induite dans la partie gauche de l'état interne DES, y compris le modèle d'erreur sur les bits et le modèle d'erreur d'octet avec la position d'erreur choisie ou la position d'erreur aléatoire. Comme nous l'expliquerons, déranger la partie gauche conduit à de meilleures attaques que déranger la partie droite. De plus, nous utilisons des distinctions plus précises que celle proposée dans [1]. Dans le modèle habituel d'erreur d'octet (position choisie), notre attaque récupère toute la dernière touche ronde avec un taux de réussite de 99% en utilisant 9 fautes au tour 12, 210 fautes au tour 11 et 13400 fautes au tour 10. Dans la (position choisie) modèle d'erreur de bit, ces chiffres
sont réduits à 7, 11 et 290, respectivement.
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
Based on (2), an adversary that knows  can mount a key recovery attack.
The principle is to make a guess on the value of the round key k16. Then, given
a pair of ciphertexts (C, e C), the attacker checks whether (2) is consistent for
this guess. If not, the guess is discarded. In this way, k16 is uniquely determined
using few pairs of ciphertexts. Due to the structure of f (see (1)), the attacker
does not need to guess the whole round key k16 but he can guess and check each
subkey k16,i independently. When an error is induced in the final rounds, the
differential  (or at least a part of it) can be predicted according to the pair
(C, e C) which enables the attack [3]. This is no more the case for an error induced
in a middle round; in that case the attack must be extended.
Comme noté dans [1], si une erreur epsilon est induite dans la partie gauche à la fin du treizième tour alors delta est égal à epsilon. Par conséquent, un attaquant capable d'induire une erreur choisie (ou du moins connue) dans L13 peut appliquer l'attaque précédente. Pour une faute induite dans la partie gauche lors d'un tour précédent, l'égalité delta = epsilon ne tient plus. Cependant, la distribution statistique du delta peut être significativement biaisée (en fonction du modèle de faute et du nombre d'arrondi). En effet, comme illustré sur la figure 2, une injection de défaut dans la partie gauche saute d'un tour avant de se propager à travers la fonction f. De plus, le chemin de propagation d'erreur de Lr à L15 ne passe par la fonction f qu'une seule fois pour r = 12, deux fois pour r = 11, etc. C'est assez faible compte tenu de la diffusion lente de la fonction f. En conséquence, un défaut induit dans Lr peut produire un delta différentiel avec une distribution significativement biaisée. Comme décrit ci-après, ce biais permet une attaque de récupération de clé basée sur un distingueur statistique.
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


```
Etudiant(e) : 21901591 - NDIAYE Mamadou

Message clair :
 DF 15 49 D0 0B A1 E0 C4 

Message chiffré juste :
 63 3C C7 98 73 8D 9E DA 

Messages chiffrés faux :
 61 39 C7 D8 73 8C 9E DA 
 63 2E C7 98 73 8C 9E DA 
 63 3C C5 9C 73 8C 9E DA 
 63 6C C7 DA 63 8D 9E DA 
 62 7C C7 9C 61 8C 9E DA 
 62 7C C7 98 73 8F 9E DA 
 62 3C C7 98 63 8D 9C DA 
 63 3C C3 99 63 99 9E D8 
 6A 7C C7 99 23 8D 9E DA 
 63 34 C7 98 33 9D 9E DA 
 63 3C CF 99 73 9D 9E DA 
 23 3C C7 90 73 D9 9E DA 
 23 3C C7 99 3B D9 9E DA 
 63 3C D7 98 73 85 9E DB 
 23 3C D7 98 73 8D 96 DA 
 23 3C D7 98 77 CD 8E D2 
 43 3C C7 98 73 CD 8F 9B 
 63 1C C7 98 73 8D 8E 9A 
 63 3C E7 98 77 8D 9F 9A 
 77 3C C7 B8 77 8D 9E 9A 
 67 3C 86 98 57 8D 9F 9A 
 77 3C C7 98 73 AD 9E DA 
 73 3C 86 98 73 8D BE DA 
 73 3C 87 98 72 8D DE FA 
 F7 3C C7 88 73 8D DE DA 
 63 BC C7 88 72 8D 9E DA 
 63 3C 47 88 73 8D DA DA 
 63 38 C7 18 72 8D DA CA 
 63 3C C7 98 F3 8D DA CE 
 63 39 C7 98 73 0D 9E DA 
 63 38 C7 98 73 8D 1E DE 
 63 39 C7 D8 73 8C 9E 4A 
```
# C++ Project IMT Atlantique Course

### Ecosystem simulation

Eustache Le Bihan, Antoine Guillou, Maxence Cisse, François Goujon  
[Slides](https://docs.google.com/presentation/d/1rCD23_DhoyQQBm1EI2nZ__1x8R_TTviz40ElkV2aOEo/edit?usp=sharing)

# Project description 

## Class diagram

For ease of understanding, the elements of the base code do not appear on this diagram.

<p align="center">
  <img width="500" height="" src=./figures/UML_class.png>
</p>

## Description

Graphically, the different behaviors can be recognized by the colors of the beasts:
- ![#3070B3](https://via.placeholder.com/15/3070B3/3070B3.png) Gregaire
- ![#D95117](https://via.placeholder.com/15/D95117/D95117.png) Kamikaze
- ![#CBAB01](https://via.placeholder.com/15/CBAB01/CBAB01.png) Peureuse
- ![#7D922A](https://via.placeholder.com/15/7D922A/7D922A.png) Prevoyante
- ![#475058](https://via.placeholder.com/15/475058/475058.png) PersoMultiple

# Setting up the simulation

All the parameters of the simulation and their  description can be found and set at **./src/constantes.h**.

# Running the simulation 

1. Clone this git repo. In a terminal, type:
> git clone https://github.com/eustlb/ecosystem_simu.git

2. In a terminal, move to the folder location and then to /src folder. Then, type:
> make

3. Type:
> ./main

A window should appear, enjoy !

# Implemented features

All the required features were implemented, excepted the "prevoyante" behavior, beasts cloning and "capteurs"/ "accessoires" visualisation.


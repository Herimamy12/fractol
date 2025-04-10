# 🌌 Fractol

Projet graphique développé dans le cadre du cursus 42.
Il permet de visualiser différentes fractales en temps réel avec une interaction clavier/souris.

---

## 📸 Aperçu

![Fractol Demo](https://www.youtube.com/watch?v=b005iHf8Z3g)  
<sub>*Exemple d’un zoom dans un ensemble de Mandelbrot*</sub>

---

## 🧠 Objectif du projet

Ce projet a pour but de manipuler la librairie **MiniLibX** (fournie par 42) pour afficher des fractales et interagir avec elles en temps réel via le clavier et la souris.  
Il met en avant la gestion des événements, des images et la performance du rendu graphique.

---

## 🧩 Fractales disponibles

- **Mandelbrot**
- **Julia**
- **Tricorn**
- *(D'autres peuvent être ajoutées facilement)*

---

## ⚙️ Installation

### Prérequis

- Système UNIX (Linux / macOS)
- `make`

### Compilation

```bash
make
```

```bash
make bonus
```

Utiliser `make bonus` pour avoir la version bonus avec plus des fonctionnalites et pour lancer `Tricorn`

### Exécution

```bash
./fractol mandelbrot
./fractol julia
./fractol Tricorn
```

### Exemple avec paramètres Julia

```bash
./fractol julia -0.8 0.156
```

---

## 🎮 Contrôles

| Action                        | Touche / Interaction                      |
|-------------------------------|-------------------------------------------|
| 🔍 Zoom avant / arrière       | Molette souris                            |
| 🧭 Déplacement de la vue      | Flèches directionnelles / Souris maintenir|
| 👾​ Incrementation iteration   | `Shift` `+` / `Shift` `-`                 |
| 🎨 Changer les couleurs       | `Shift` `C`                               |
| ♻️  Recentrer la fractale     | `Shift` `R`                               |
| 🔄 Changer le type de fractale| `1` (Mandelbrot), `3` (Tricorn)           |
| ❌ Quitter le programme       | `ESC`                                     |

---

## 🚀 À venir / Idées futures

- 🎞️ **Animation de zoom automatique**  
  Créer un effet de plongée continue dans la fractale avec variation de couleurs.

- 🎛️ **Système de sauvegarde**  
  Enregistrer des vues personnalisées de fractales pour y revenir plus tard.

- 🌈 **Nouvelles palettes de couleurs dynamiques**  
  Générer des couleurs en fonction du temps, du zoom ou de la position.

- 🔄 **Support multi-fractales en parallèle**  
  Afficher plusieurs fractales côte à côte ou passer de l'une à l'autre rapidement.

---

> *"Les mathématiques ne sont pas une chose à comprendre, mais une chose à ressentir."*  
> — **Benoît Mandelbrot**

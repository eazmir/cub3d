# Cub3D Texture Collection

This directory contains a minimal set of 8 high-quality 64x64 XPM textures for all maps in the `maps/good` folder.

## Texture List

1. **stone_wall.xpm** - Gray stone brick wall texture
2. **brick_wall.xpm** - Red brick wall texture  
3. **wood_planks.xpm** - Wooden plank texture
4. **mossy_stone.xpm** - Green mossy stone texture
5. **metal.xpm** - Metallic gray paneling texture
6. **blue_tile.xpm** - Blue tiled wall texture
7. **dark_stone.xpm** - Dark gray/black stone texture
8. **purple_stone.xpm** - Purple stone wall texture

## Symbolic Links

The following symbolic links exist for test maps:
- **north.xpm** → stone_wall.xpm
- **south.xpm** → brick_wall.xpm
- **west.xpm** → wood_planks.xpm
- **east.xpm** → blue_tile.xpm

## Usage

All maps in `maps/good/` now reference these textures using the path format:
```
NO maps/good/textures/stone_wall.xpm
SO maps/good/textures/brick_wall.xpm
WE maps/good/textures/wood_planks.xpm
EA maps/good/textures/blue_tile.xpm
```

## Features

- **Minimal Set**: Only 8 textures (plus 4 symlinks) for all 18 maps
- **Consistent Style**: All textures use a 64x64 resolution with 4-color palettes
- **Self-Contained**: All textures are located within the maps/good directory
- **Variety**: Different themes including stone, brick, wood, metal, and decorative tiles

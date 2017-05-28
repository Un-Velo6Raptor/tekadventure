/*
** velleda.c for tekadventure in /home/heychsea/MUL/tekadventure
** 
** Made by Hugo Cousin
** Login   <hugo.cousin@epitech.eu>
** 
** Started on  Sun May 28 17:05:02 2017 Hugo Cousin
** Last update Sun May 28 19:28:05 2017 Hugo Cousin
*/

#include	"display.h"

int		init_velleda(t_needs *needs)
{
  sfTexture	*texture;
  sfSprite	*sprite;
  sfText	*text;
  sfFont	*font;

  font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
  texture = sfTexture_createFromFile("ressources/velleda/velleda.png", NULL);
  text = sfText_create();
  sprite = sfSprite_create();
  if (!texture || !font || !text || !sprite)
    return (84);
  sfText_setFont(text, font);
  sfText_setString(text, "0");
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfText_setPosition(text, vector_2f(750, 0));
  sfText_setColor(text, sfRed);
  sfSprite_setScale(sprite, vector_2f(0.2, 0.2));
  sfSprite_setPosition(sprite, vector_2f(800, 0));
  sfText_setCharacterSize(text, 50);
  needs->nb_veleda = text;
  needs->veleda_sprite = sprite;
  return (0);
}

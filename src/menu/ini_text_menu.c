/*
** ini_text_menu.c for  in /home/januar_m/delivery/graphical/tekadventure
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri May 19 20:32:24 2017 Martin Januario
** Last update Sat May 20 22:07:29 2017 Martin Januario
*/

#include	"menu.h"

static int	create_text_difficult(t_text_menu *menu_text)
{
  menu_text->title_diff = sfText_create();
  menu_text->diff[0] = sfText_create();
  menu_text->diff[1] = sfText_create();
  menu_text->diff[2] = sfText_create();
  if (menu_text->diff[0] == NULL || menu_text->diff[1] == NULL ||
      menu_text->diff[2] == NULL || menu_text->title_diff == NULL)
    return (84);
  sfText_setString(menu_text->title_diff, "Difficulty:");
  sfText_setString(menu_text->diff[0], "Easy");
  sfText_setString(menu_text->diff[1], "Normal");
  sfText_setString(menu_text->diff[2], "Hard");
  sfText_setFont(menu_text->title_diff, menu_text->font);
  sfText_setFont(menu_text->diff[0], menu_text->font);
  sfText_setFont(menu_text->diff[1], menu_text->font);
  sfText_setFont(menu_text->diff[2], menu_text->font);
  sfText_setCharacterSize(menu_text->title_diff, 60);
  sfText_setCharacterSize(menu_text->diff[0], 50);
  sfText_setCharacterSize(menu_text->diff[1], 50);
  sfText_setCharacterSize(menu_text->diff[2], 50);
  sfText_setPosition(menu_text->title_diff, vector_2f(30.0f, 210.0f));
  sfText_setPosition(menu_text->diff[0], vector_2f(80.0f, 280.0f));
  sfText_setPosition(menu_text->diff[1], vector_2f(280.0f, 280.0f));
  sfText_setPosition(menu_text->diff[2], vector_2f(550.0f, 280.0f));
  menu_text->diff[3] = NULL;
  return (0);
}

static int	create_text_lang(t_text_menu *menu_text)
{
  menu_text->title_lang = sfText_create();
  menu_text->lang[0] = sfText_create();
  menu_text->lang[1] = sfText_create();
  if (menu_text->title_lang == NULL || menu_text->lang[0] == NULL ||
      menu_text->lang[1] == NULL)
    return (84);
  sfText_setString(menu_text->title_lang, "Language in game:");
  sfText_setString(menu_text->lang[0], "French");
  sfText_setString(menu_text->lang[1], "English");
  sfText_setFont(menu_text->title_lang, menu_text->font);
  sfText_setFont(menu_text->lang[0], menu_text->font);
  sfText_setFont(menu_text->lang[1], menu_text->font);
  sfText_setCharacterSize(menu_text->title_lang, 60);
  sfText_setCharacterSize(menu_text->lang[0], 50);
  sfText_setCharacterSize(menu_text->lang[1], 50);
  sfText_setPosition(menu_text->title_lang, vector_2f(30.0f, 350.0f));
  sfText_setPosition(menu_text->lang[0], vector_2f(80.0f, 420.0f));
  sfText_setPosition(menu_text->lang[1], vector_2f(280.0f, 420.0f));
  menu_text->lang[2] = NULL;
  return (0);
}

static int	create_text_keyboard(t_text_menu *menu_text)
{
  menu_text->title_key = sfText_create();
  menu_text->keyboard[0] = sfText_create();
  menu_text->keyboard[1] = sfText_create();
  if (menu_text->title_key == NULL || menu_text->keyboard[0] == NULL ||
      menu_text->keyboard[1] == NULL)
    return (84);
  sfText_setString(menu_text->title_key, "Keyboard:");
  sfText_setString(menu_text->keyboard[0], "French");
  sfText_setString(menu_text->keyboard[1], "English");
  sfText_setFont(menu_text->title_key, menu_text->font);
  sfText_setFont(menu_text->keyboard[0], menu_text->font);
  sfText_setFont(menu_text->keyboard[1], menu_text->font);
  sfText_setCharacterSize(menu_text->title_key, 60);
  sfText_setCharacterSize(menu_text->keyboard[0], 50);
  sfText_setCharacterSize(menu_text->keyboard[1], 50);
  sfText_setPosition(menu_text->title_key, vector_2f(30.0f, 490.0f));
  sfText_setPosition(menu_text->keyboard[0], vector_2f(80.0f, 560.0f));
  sfText_setPosition(menu_text->keyboard[1], vector_2f(280.0f, 560.0f));
  menu_text->keyboard[2] = NULL;
  return (0);
}

static int	create_text_sound(t_text_menu *menu_text)
{
  menu_text->title_sound = sfText_create();
  menu_text->sound[0] = sfText_create();
  menu_text->sound[1] = sfText_create();
  if (menu_text->title_sound == NULL || menu_text->sound[0] == NULL ||
      menu_text->sound[1] == NULL)
    return (84);
  sfText_setString(menu_text->title_sound, "Sound:");
  sfText_setString(menu_text->sound[0], "Yes");
  sfText_setString(menu_text->sound[1], "No");
  sfText_setFont(menu_text->title_sound, menu_text->font);
  sfText_setFont(menu_text->sound[0], menu_text->font);
  sfText_setFont(menu_text->sound[1], menu_text->font);
  sfText_setCharacterSize(menu_text->title_sound, 60);
  sfText_setCharacterSize(menu_text->sound[0], 50);
  sfText_setCharacterSize(menu_text->sound[1], 50);
  sfText_setPosition(menu_text->title_sound, vector_2f(30.0f, 630.0f));
  sfText_setPosition(menu_text->sound[0], vector_2f(80.0f, 700.0f));
  sfText_setPosition(menu_text->sound[1], vector_2f(280.0f, 700.0f));
  menu_text->sound[2] = NULL;
  return (0);
}

int		ini_text_menu(t_text_menu *menu_text,
			      t_core __attribute__ ((unused)) *needs)
{
  menu_text->font = sfFont_createFromFile("ressources/font/FFF_Tusj.ttf");
  if (menu_text->font == NULL)
    return (84);
  if (create_text_difficult(menu_text) == 84 ||
      create_text_lang(menu_text) == 84 ||
      create_text_keyboard(menu_text) == 84 ||
      create_text_sound(menu_text) == 84)
    return (84);
  sfText_setColor(menu_text->diff[1], color(0, 255, 0));
  sfText_setColor(menu_text->lang[0], color(0, 255, 0));
  sfText_setColor(menu_text->keyboard[0], color(0, 255, 0));
  sfText_setColor(menu_text->sound[0], color(0, 255, 0));
  sfText_setColor(menu_text->title_diff, sfBlack);
  sfText_setColor(menu_text->title_lang, sfBlack);
  sfText_setColor(menu_text->title_key, sfBlack);
  sfText_setColor(menu_text->title_sound, sfBlack);
  return (0);
}

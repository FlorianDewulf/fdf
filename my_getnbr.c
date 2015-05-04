/*
** my_getnbr.c for my_getnbr in /home/dewulf_f//afs/Brouillon
** 
** Made by florian dewulf
** Login   <dewulf_f@epitech.net>
** 
** Started on  Tue Oct 11 18:23:56 2011 florian dewulf
** Last update Sun Dec 11 21:26:52 2011 florian dewulf
*/

int	my_getnbr(char *str)
{
  int	c;
  int	signe;
  int	resultat;

  signe = (c = 0) ? 1 : 1;
  resultat = 0;
  while ((str[c] != 0 && (str[c] >= 48 && str[c] <= 57)) || str[c] == 43 ||
	 str[c] == 45)
    {
      while (str[c] == 45)
	{
	  signe = signe * -1;
	  c++;
	  if (str[c] == 0 || (str[c] <= 48 && str[c] >= 57 &&
			      str[c] != 45 && str[c] != 43))
	    return (0);
	}
      if (str[c] >= 48 && str[c] <= 57)
	{
	  str[c] = str[c] - 48;
	  resultat = (resultat * 10) + str[c];
	}
      c++;
    }
  return (resultat * signe);
}

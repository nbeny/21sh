# 21sh
termcaps ref:

- http://loiclefloch.fr/877-les-termcaps/

- https://www.gnu.org/software/termutils/manual/termcap-1.3/html_chapter/termcap_5.html

- http://www.commentcamarche.net/forum/affich-17395192-c-unix-sequences-touches-directionnelles

- https://openclassrooms.com/forum/sujet/termcaps-comment-se-mouvoir-dans-le-terminal

redirection ref:

- https://www.tutorialspoint.com/unix/unix-io-redirections.html

- http://www.gnu.org/software/bash/manual/bashref.html#Redirections

shell ref:

- http://www.gnu.org/software/bash/manual/bashref.html



gestion couper copier coller:

```
else if (buff[0] == -62 && buff[1] == -96 && buff[2] == '\0')

    ft_printf(2, "select\n");//option + space
    
 else if (buff[0] == -30 && buff[1] == -119 && buff[2] == -120 && buff[3] == '\0')

    ft_printf(2, "couper\n");//option + x

 else if (buff[0] == -61 && buff[1] == -89 && buff[2] == '\0')

    ft_printf(2, "copier\n");//option + c

 else if (buff[0] == -30 && buff[1] == -120 && buff[2] == -102 && buff[3] == '\0')

    ft_printf(2, "coller\n");//option + v
```
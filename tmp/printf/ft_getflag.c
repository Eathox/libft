#include "ft/char.h"

#include "printf.h"
#include "priv.h"

static void handleconflicts(t_info *info) {
    PF_FLAG_SPACE = (PF_FLAG_PLUS == false && PF_FLAG_SPACE);
    PF_FLAG_ZERO = (PF_FLAG_MIN == false && PF_FLAG_ZERO);
}

size_t ft_getflag(t_info *info, const char *str) {
    size_t i;
    bool spacer;

    i = 0;
    spacer = 0;
    while (i == 0 || ft_chrin(PF_A_FLAG, str[i]) ||
           (ft_chrin(PF_A_SPACER, str[i]) && spacer == false)) {
        if (str[i] == '#')
            PF_FLAG_HASH = true;
        else if (str[i] == '0')
            PF_FLAG_ZERO = true;
        else if (str[i] == '-')
            PF_FLAG_MIN = true;
        else if (str[i] == '+')
            PF_FLAG_PLUS = true;
        else if (str[i] == ' ')
            PF_FLAG_SPACE = true;
        else if (str[i] == '\'')
            PF_FLAG_APOST = true;
        spacer = (str[i] != 0);
        i++;
    }
    handleconflicts(info);
    return i;
}

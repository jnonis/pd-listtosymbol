//
//  listtosymbol.c
//
//  Created by javiernonis on 6/17/18.
//  Copyright © 2018 jnonis. All rights reserved.
//

#include <string.h>
#include "m_pd.h"

static t_class *listtosymbol_class;

typedef struct _listtosymbol {
    t_object  x_obj;
    t_outlet  *out;
} t_listtosymbol;

void listtosymbol_list(t_listtosymbol *x, t_symbol *s, t_int argc, t_atom *argv) {
    char result[1000];
    char buf[100];
    for (int i = 0; i < argc; i++) {
        atom_string((argv + i), buf, 100);
        if(i > 0) {
            strcat(result, " ");
            strcat(result, buf);
        } else {
            strcpy(result, buf);
        }
    }
    outlet_symbol(x->out, gensym(result));
}

void *listtosymbol_new(void) {
    t_listtosymbol *x = (t_listtosymbol *) pd_new(listtosymbol_class);
    
    x->out = outlet_new(&x->x_obj, &s_symbol);
    
    return (void *)x;
}

void listtosymbol_free(t_listtosymbol *x) {
    outlet_free(x->out);
}

void listtosymbol_setup(void) {
    listtosymbol_class = class_new(gensym("listtosymbol"),
                                 (t_newmethod)listtosymbol_new,
                                 (t_method)listtosymbol_free,
                                 sizeof(t_listtosymbol),
                                 CLASS_DEFAULT,
                                 A_GIMME,
                                 0);

    class_addlist(listtosymbol_class, listtosymbol_list);
}

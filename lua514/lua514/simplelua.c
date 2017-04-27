//
//  simplelua.c
//  lua514
//
//  Created by Shiling Yang on 27/04/2017.
//  Copyright © 2017 Peter Young. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include <stdarg.h>
#include <stdlib.h>

int main()
{
  char buff[256];

  int error = 0;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  while(fgets(buff, sizeof(buff), stdin) != NULL)
    {
      error = luaL_loadbuffer(L, buff, strlen(buff), "line")
        || lua_pcall(L, 0, 0, 0);
    }

  if(error)
    {
      fprintf(stderr, "%s", lua_tostring(L, -1));
      lua_pop(L, 1);
    }

  lua_close(L);

    return 0;
}

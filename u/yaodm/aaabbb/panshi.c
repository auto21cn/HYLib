// daodan.hehe
 
#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_send", "send");
       add_action("do_send", "fire");
}


void create()
{
        set_name("导弹", ({"daodan"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
                         "这是侠客行目前最为先进的武器。\n");
               set("value", 0);
             set("unit", "架");
               set("no_get", 0);
               set("no_drop", 0);
               set("treasure", 1);
       }
}

int do_send(string target)
{
       object me, dest;

       me = this_object();

     if (target == "aaabbb")
             target = this_player()->query("id");
     if (target == "lubinh")
             target = this_player()->query("id");

       if(!(dest = find_player(target)))
             if(!(dest = find_living(target)))
             {
                   write("没有这个人或生物。\n");
                   return 1;
             }
    if (!environment(dest)) return notify_fail("这个人不知道在哪里。\n");




       dest->set_temp("last_damage_from", "被" + me->name() + "炸");

       dest->delete("env/immortal");
       dest->die();
       return 1;
}


